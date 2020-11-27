#include "type.h"

Type::Type(ValueType valueType) {
    this->type = valueType;
}

string Type::getTypeInfo() {
    switch(this->type) {
        case VALUE_BOOL:
            return "bool";
        case VALUE_INT:
            return "int";
        case VALUE_CHAR:
            return "char";
        case VALUE_STRING:
            return "string";
        case VALUE_ARRAY:
            return "array of";
        case VALUE_POINTER:
            return "pointer of";
        case VALUE_SIGNED:
            return "signed";
        case VALUE_UNSIGNED:
            return "unsigned";
        case VALUE_CONST:
            return "const";
        default:
            cerr << "shouldn't reach here, typeinfo";
            assert(0);
    }
    return "?";
}