#ifndef __DJL_TYPE_H__
#define __DJL_TYPE_H__
#include<vector>
#include"stdlib.h"
#include"string.h"
#include<iostream>
/*
 * SysY Language's Type System
 * Widely referenced open source compiler
 * UCC's source code, especially in this
 * part. 
 * url of their project repo:
 * https://github.com/sheisc/ucc162.3.git
 */

//type category
enum{
    CCHAR, UCHAR, INT, UINT, DOUBLE,POINTER ,VOID,
    STRUCT,UNION,  ARRAY, FUNCTION,
};
extern struct type Types[VOID - CCHAR + 1];

#define T(categ) (Types + categ)
#define IsPtrType(ty)      (ty->categ == POINTER)
#define IsRecordType(ty)   (ty->categ == STRUCT || ty->categ == UNION)
#define IsFunctionType(ty) (ty->categ == FUNCTION)
#define IsIncompletePtr(ty) (ty->categ == POINTER && ty->bty->size == 0)
#define IsVoidPtr(ty)       (ty->categ == POINTER && ty->bty->categ == VOID)
#define NotFunctionPtr(ty)  (ty->categ == POINTER && ty->bty->categ != FUNCTION)

const char * GetCategName(int categ);


// type qualifier
enum { CONST = 0x1, VOLATILE = 0x2 };

/*
 * A "TYPE HEADER", which any TYPE should
 * start with (in address space)
 * categ :  an integer to mark the catogory, such as CHAR/POINTER
 * qual  :  an integer to mark the qualifier, such as const/volatile
 * align :  in how many bytes to align with
 * size  :  the space this TYPE is going to take
 * bty   :  pointer to its BASE class; 
 *          for primary type, bty is null
 */
#define TYPE_COMMON \
    unsigned int categ  : 8;    \
    unsigned int qual   : 8;    \
    unsigned int align  :16;    \
    unsigned int size  ;    \
    struct type * bty  ;

typedef struct type
{
    TYPE_COMMON
} *_Type;

typedef struct arrayType{
	TYPE_COMMON
	int len;		// count of array elements
} * _ArrayType;


/*
 * field menber of a struct or union
 * offset   :   offset to the begining of struct/union
 * id       :   name
 * bits     :   bits of a bit filed
 *              should be 0 for non-bit files
 * pos      :   deal with big/little-endian
 * ty       :   type of filed
 */
typedef struct field
{
    int offset;
    char* id;
    int bits;
    int pos;
    _Type ty;
    struct field* next;
}* _Field;

/*
 * struct or union type
 * flds     :   the all fields list of struct/union
 * tail     :   used for construction of field list
 * hasConstFld: contains const field or not
 * hasDenaArray:contains denamic array(array with size 0) or not,
 *              the denemic array must be the last field. 
 */
typedef struct recordType
{
    TYPE_COMMON
    char* id;
    _Field flds;
    _Field* tail;
    int hasConstFld : 16;
    int hasDenaArray : 16;

    //for test whether it is incomplete type.
    int complete;
} *_RecordType;

typedef struct functionType
{
	TYPE_COMMON
	int hasArgu;
    int hasProto;
    std::vector<_Type> param_types; 
} *_FunctionType;


_Type Qualify(int qual, _Type ty);
_Type UnQualify(_Type ty);
_Type PointerTo(_Type ty);
_Type ArrayOf(int len, _Type ty);
_Type FunctionReturn(_Type ty,  int argu, int proto, std::vector<_Type> p);

_Type  StartRecord(char *id, int categ);
_Field AddField(_Type ty, char *id, _Type fty, int bits);
_Field LookupField(_Type ty, char *id);
void EndRecord(_Type ty);
void SetupTypeSystem(void);

#endif