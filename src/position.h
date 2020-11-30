#ifndef __POSITION__H__
#define __POSITION__H__

#include<iostream>
typedef struct _position{
    int row;
    int col;
    _position(int a, int b):row(a), col(b){}
} position;

std::ostream & operator<<(std::ostream& os,  const position & p){
    os << p.row<< ' ' << p.col;
    return os;
}

#endif