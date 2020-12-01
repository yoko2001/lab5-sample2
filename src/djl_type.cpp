#include"djl_type.h"
#define NEWTYPE(t, ty)\
    ty = (t*)malloc(sizeof(t));\
    memset(ty, 0, sizeof(t));

#define ALIGN(size, align)  ((align == 0) ? size: ((size + align - 1) & (~(align - 1))))
//BASE TYPES
struct type Types[VOID - CCHAR + 1];

static _Type DoTypeClone(_Type ty){
	int categ = ty->categ;
	if(categ == STRUCT || categ == UNION){
		_RecordType rty;
		NEWTYPE(struct recordType, rty);
		*rty = *((_RecordType)ty);
		return (_Type) rty;
	}else if(categ == ARRAY){
		_ArrayType aty;
		NEWTYPE(struct arrayType ,aty);
		*aty = *((_ArrayType)ty);
		return (_Type) aty;
	}else if(categ == FUNCTION){
		_FunctionType fty;
		NEWTYPE(struct functionType, fty);
		*fty = *((_FunctionType)ty);
		return (_Type) fty;	
	}else{
		_Type qty;
		NEWTYPE(struct type, qty);
		*qty = *ty;
		return qty;
	}

}

/**
 * Contruct a qualified type
 */
_Type Qualify(int qual, _Type ty)
{

	_Type qty;
	// @qual is const or volatile
	// if ty has already been qualified by @qual or qual is zero, just return @ty itself.
	if (qual == 0 || qual == ty->qual)
		return ty;
	// we don't want to change the @ty. So we copy @ty first.
	qty = DoTypeClone(ty);
	qty->qual |= qual;
	// if ty has been qualified, get the original type(not qualified one)
	// else ty has not been qualified, ty is the original type.
	if (ty->qual != 0)
	{
		qty->bty = ty->bty;
	}
	else
	{
		qty->bty = ty;
	}
	return qty;	
}

/**
 * Get a type's unqualified version
 */
_Type UnQualify(_Type ty){
    if(ty->qual){
        ty = ty->bty;
    }
    return ty;
}

/**
 * Construct a type pointing to ty.
 */
_Type PointerTo(_Type ty){
    _Type pty;

	NEWTYPE(struct type, pty);

	pty->categ  = POINTER;
	pty->qual = 0;
	pty->align = T(POINTER)->align;
	pty->size = T(POINTER)->size;
	pty->bty = ty;

	return pty;
}

/**
 * Construct an array type, len is the array length.
 */
_Type ArrayOf(int len, _Type ty){
    _ArrayType aty;
	NEWTYPE(struct arrayType, aty);
	aty->categ = ARRAY;
	aty->qual = 0;
	aty->size = len * ty->size;
	aty->align = ty->align;
	aty->bty = ty;
	aty->len = len;
	return (_Type)aty;	
}

/**
 * Construct a function type, the return type is ty. 
 */
_Type FunctionReturn(_Type ty,  int argu, int proto, std::vector<_Type> p){
    _FunctionType fty;

	NEWTYPE(struct functionType, fty);

	fty->categ = FUNCTION;
	fty->qual = 0;
	fty->size = T(POINTER)->size;
	fty->align = T(POINTER)->align;
	fty->hasArgu = argu;
    fty->hasProto = proto;
    fty->param_types = p;
	fty->bty = ty;
	return (_Type)fty;
}

/**
 * Construct a struct/union type whose name is id, id can be NULL.
 */
_Type  StartRecord(char *id, int categ){
    // @categ is STRUCT or UNION;
	_RecordType rty;

	NEWTYPE(struct recordType, rty);
	/*************************************
		When Starting parsing struct /union,
		its size is unclear yet.
		So rty->size is 0 when calling this function.
	 *************************************/
	rty->categ = categ;
	rty->id = id;
	rty->tail= &rty->flds;

	rty->complete = 0;

	return (_Type)rty;
}


/**
 * Add a field to struct/union type ty. fty is the type of the field.
 * id is the name of the field. If the field is a bit-field, bits is its
 * bit width, for non bit-field, bits will be 0.
 */
/*******************************************************
struct Data{
	int a:2;		------------>   Field
	......
}
	@ty		is a object of RecordType, the type of "Data"
	@id		field name,	"a"
	@fty	the type of struct field	, "int"
	@bits	whether this field is bit field, if yes, @bits is the length of bits, "2"
 *******************************************************/
_Field AddField(_Type ty, char *id, _Type fty, int bits){
    _RecordType rty = (_RecordType)ty;
	_Field fld;

	if (fty->size == 0)		// int arr[];
	{
		if(fty->categ == ARRAY){
			rty->hasDenaArray = 1;	
		}
	}
	// If one field member is const ,the total struct object is const.
	if (fty->qual & SHIFT_CONST)
	{
		rty->hasConstFld = 1;
	}

	NEWTYPE(struct field, fld);

	fld->id = id;
	fld->ty = fty;
	fld->bits = bits;
	// offset will be determined in function EndRecord(Type ty)
	fld->pos = fld->offset = 0;
	fld->next = NULL;

	*rty->tail = fld;
	rty->tail  = &(fld->next);

	return fld;
}

/**
 * Lookup if there is a field named id in struct/union type
 */
_Field LookupField(_Type ty, char *id){
    _RecordType rty = (_RecordType)ty;
	_Field fld = rty->flds;

	while (fld != NULL)
	{
		// unnamed struct/union field in a struct/union
		if (fld->id == NULL && IsRecordType(fld->ty))
		{
			/**************************************
				(1)
				typedef struct Data{
					int a;
					struct{
						int b;			// Dada d;  d.b = 5;
					};	
				}Data;
				(2)
				typedef struct Data{
					int a;
					struct{
						int a;	// OK.		Data d;  d.b.a = 3;
					} b;	// this is not an unnamed filed. its name is b. Though the struct is unnamed.	
				}Data;
				(3)
				typedef struct Data{
					int a;
					struct{
						int a;	// redefinition of a
					} ;	
				}Data;				
			 **************************************/
			_Field p;

			p = LookupField(fld->ty, id);
			if (p)
				return p;
		}
		else if (fld->id == id)	// see function  InternName() and AppendSTR()
			return fld;

		fld = fld->next;
	}

	return NULL;
}

/**
 * For unamed struct/union field in a struct/union, the offset of fields in the 
 * unnamed struct/union should be fix up.
 */
void AddOffset(_RecordType rty, int offset)
{
	_Field fld = rty->flds;

	//PRINT_DEBUG_INFO(("fld->id == NULL && IsRecordType(fld->ty)"));
	while (fld)
	{
		fld->offset += offset;
		if (fld->id == NULL && IsRecordType(fld->ty))
		{			
			AddOffset((_RecordType)fld->ty, fld->offset);
		}
		fld = fld->next;
	}

}

/**
 * When a struct/union type's delcaration is finished, layout the struct/union.
 * Calculate each field's offset from the beginning of struct/union and the size
 * and alignment of struct/union.
 */
void EndRecord(_Type ty){
    _RecordType rty = (_RecordType)ty;
	_Field fld = rty->flds;
	int bits = 0;
	int intBits = T(INT)->size * 8;
	if (rty->categ == STRUCT){
		while (fld){
			// align each field
			fld->offset = rty->size = ALIGN(rty->size, fld->ty->align);			
			if (fld->id == NULL && IsRecordType(fld->ty)){
				AddOffset((_RecordType)fld->ty, fld->offset);
			}
			// process bit-field
			if (fld->bits == 0)
			{
				// if current field is not a bit-field, whenever 
                //last field is bit-field or not, 
				// it will occupy a chunk of memory of its size.
				if (bits != 0)
				{
					fld->offset = rty->size = ALIGN(rty->size + T(INT)->size, fld->ty->align);
				}
				bits = 0;
				rty->size = rty->size + fld->ty->size;
			}
			else if (bits + fld->bits <= intBits)
			{
				// current bit-field and previous bit-fields can be placed 
                //together into an int. calculate the position in an 'int' 
                //for the current bit-field.
				fld->pos = bits;//should concern ENDIAN prob here
				bits = bits + fld->bits;
				// the int space for bit-fields are full now.
				if (bits == intBits){
					rty->size += T(INT)->size;
					bits = 0;
				}
			}
			else
			{
				/// current bit-field can't be placed together with previous bit-fields,
				/// must start a new chunk of memory
				rty->size += T(INT)->size;
				fld->offset += T(INT)->size;
				fld->pos = 0;//should concern ENDIAN prob here
				bits = fld->bits;
			}
			if (fld->ty->align > rty->align){
				rty->align = fld->ty->align;
			}
			fld = fld->next;
		}
		// the last field of struct is bit-filed 
		if (bits != 0){
			rty->size += T(INT)->size;
		}
		rty->size = ALIGN(rty->size, rty->align);
	}
	else		//UNION
	{
		/*
		 * (1)The largest align of field member is the align of union.
		 * (2)The largest size of field member is the size of union.
		*/
		while (fld)
		{
			// if the field member of a union has larger align 
			if (fld->ty->align > rty->align)
			{
				rty->align = fld->ty->align;
			}
			// // if the field member of a union has larger size 
			if (fld->ty->size > rty->size)
			{
				rty->size = fld->ty->size;
			}
			fld = fld->next;
		}
		//  for better diagnosis
		if(rty->hasDenaArray){
			std::cout << "flexible array member in union" << std::endl;
		}
	}
	if(rty->categ == STRUCT && rty->size == 0 && rty->hasDenaArray){
		std::cout << "flexible array member in union/struct" << std::endl;
	}
}

/*
 * Setup the type system according to the target configuration.
 */
void SetupTypeSystem(void){
    int i;
	_FunctionType fty;
	// setup type size for each type.

	T(CCHAR)->size = T(UCHAR)->size = 1;
	T(INT)->size = T(UINT)->size = 4;
	T(DOUBLE)->size = 4;
	T(POINTER)->size = 4;
	// without this, TypeToString() would have Segmentation fault??
	T(POINTER)->bty = T(INT);
    T(VOID)->size = 0;
	// type category, type alignment
	for (i = CCHAR; i <= VOID; ++i)
	{
		T(i)->categ = i;
		T(i)->align = T(i)->size;
	}
}