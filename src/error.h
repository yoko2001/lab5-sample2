#ifndef __ERROR__
#define __ERROR__
    
#include<iostream>
void error(const char* source, int lineno, const char* msg);
void warning(const char* source, int lineno, const char* msg);
#endif 