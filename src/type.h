#ifndef TYPESYSTEM_H
#define TYPESYSTEM_H
#include "./pch.h"
using namespace std;

enum ValueType
{
    VALUE_BOOL,
    VALUE_INT,
    VALUE_CHAR,
    VALUE_VOID,
    VALUE_STRING,
    COMPOSE_STRUCT,
    COMPOSE_UNION,
    COMPOSE_FUNCTION,
    VALUE_SIGNED,
    VALUE_UNSIGNED,
    VALUE_CONST,
    VALUE_POINTER,
    VALUE_ARRAY,
};

class Type
{
public:
    ValueType type;
    Type(ValueType valueType);
public:  
    /* 如果你要设计复杂类型系统的话，可以修改这一部分 */
    ValueType* childType; // for union or struct
    ValueType* paramType, retType; // for function
    
    void addChild(Type* t);
    void addParam(Type* t);
    void addRet(Type* t);
public:
    ValueType* sibling; 
public:
    string getTypeInfo();
};

// 设置几个常量Type，可以节省空间开销
#ifndef __INIT__TYPES__
#define __INIT__TYPES__
// static Type* TYPE_CHAR = new Type(VALUE_CHAR);
// static Type* TYPE_BOOL = new Type(VALUE_BOOL);
// static Type* TYPE_STRING = new Type(VALUE_STRING);
// static Type* TYPE_SIGNED = new Type(VALUE_SIGNED);
// static Type* TYPE_UNSIGNED = new Type(VALUE_UNSIGNED);
// static Type* TYPE_CONST = new Type(VALUE_CONST);
// static Type* TYPE_POINTER = new Type(VALUE_POINTER);
// static Type* TYPE_ARRAY = new Type(VALUE_ARRAY);
extern Type* TYPE_INT;
extern Type* TYPE_CHAR;
extern Type* TYPE_BOOL;
extern Type* TYPE_STRING;
extern Type* TYPE_SIGNED;
extern Type* TYPE_UNSIGNED;
extern Type* TYPE_CONST;
extern Type* TYPE_POINTER;
extern Type* TYPE_ARRAY;
extern Type* TYPE_INT;
extern Type* TYPE_VOID;
#endif
int getSize(Type* type);

#endif