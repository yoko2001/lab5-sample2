#ifndef __INTER__
#define __INTER__
#include"tree.h"
#include<fstream>

extern ofstream iro;
//diffrent from tree.h's op, these are for assamble language
enum Opcode{
//assign
    BOR, //"|"
    BXOR,//"^"
    BAND,//"&"
    LSH,//
    RSH,//
    ADD,//"+"
    SUB,// "-"
    MUL,//"*"
    DIV,//"/"
    MOD,//"%"
    NEG,//"-"
    BCOM,//"~"
//branch
    JZ,      //"",  
    JNZ,     //"!", 
    JE,      //"=="
    JNE,     //"!="
    JG,      //">"
    JL,      //"<"
    JGE,     //">="
    JLE,     //"<="

//jump
    JMP,     //"jmp"
    IJMP,    //"ijmp" IndirectJump

    INC,     //"++",   Inc
    DEC,     //"--",   Dec

    ADDR,    //"&"  Address
    DEREF,   //"*"  Deref

//Cast
//promote to size 4
    EXTI1,   //"(int)(char)"
    EXTU1,   //"(int)(unsigned char)"
    EXTI2,   //"(int)(short)"
    EXTU2,   //"(int)(unsigned short)"
//shrink to lower size
    TRUI1,   //"(char)(int)"
    TRUI2,   //"(short)(int)"
//real cast
    CVTI4F8, //"(double)(int)"
    CVTU4F8, //"(double)(unsigned)"
    CVTF8I4, //"(int)(double)"
    CVTF8U4,//"(unsigned)(double)"

//Mov
    MOV,     //"=",                    Move)
    //IMOV,    //"*=",                   IndirectMove)
//Func
    CALL,    //"call"
    RET,     //"ret"
//    CLR,     //"",                     Clear)
    
    NOP,     //占位符
};

typedef struct irinst{
    struct irinst *prev;
    struct irinst *next;
    _Type ty;
    int opcode;
    domain_elem opds[3];
}*IRInst;

typedef struct cfgedge
{
	struct bblock* bb;
	struct cfgedge *next;
} *CFGEdge;

typedef struct bblock{
    struct bblock *prev;
	struct bblock *next;

    domain_elem label;  //identifier of bb
    CFGEdge succs;
    CFGEdge preds;

    struct irinst instlist;

    int ninst;

    int nsucc;

    int npred;
    int ref;
}* BBlock;

BBlock CreateBBlock();
void StartBBlock(BBlock bb);

void DrawCFGEdge(BBlock from, BBlock to);

extern BBlock currentBB;
#endif
