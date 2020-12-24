#include"error.h"

void error(const char* source, int lineno, const char* msg){
    std::cout << "[ERROR] in " << source << " lno@" << lineno << msg << std::endl;
}
void warning(const char* source, int lineno, const char* msg){
    std::cout << "[WARNING] in " << source << " lno@" << lineno << msg << std::endl;
}