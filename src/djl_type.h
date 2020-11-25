#ifndef __DJL_TYPE_H__
#define __DJL_TYPE_H__

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
    CHAR, UCHAR, INT, UINT, POINTER, DOUBLE, 
    STRUCT, ARRAY, FUNCTION,
};

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
#ifdef __ENDIAN_CONTROL__
    int pos;
#endif
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

#endif