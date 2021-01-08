#ifndef TREE_H
#define TREE_H

#include "pch.h"
#include "type.h"
#include "djl_type.h"
#include "domain.h"
#include "inter.h"

#define BsysTypeArray 0
#define BsysTypeFunc  1
#define BsysTypeRvalue 1<<1;    
#define sysTyClear(mark)   mark = 0
#define sysTySetArr(mark)  mark |= BsysTypeArray
#define sysTySetFunc(mark) mark |= BsysTypeFunc
#define sysTySetRval(mark) mark |= BsysTypeRvalue
#define sysTyIsArr(mark)   mark & BsysTypeArray
#define sysTyIsFunc(mark)  mark & BsysTypeFunc
#define sysTyIsRval(mark)  mark & BsysTypeRvalue

enum NodeType
{
    NODE_CONST, 
    NODE_VAR,
    NODE_EXPR,
    NODE_TYPE,
    NODE_ASSI,
    NODE_STMT,
    NODE_BLOCK_LIST,
    NODE_PROG,
    NODE_OP,
    NODE_DECL_LIST, //list of NODE_DECL
    NODE_DECL,  //作为下面NODE_INIT_DECL_VARS和NODE_DECL_VARS的上层
    NODE_INIT_DECL_VARS, //用来表示一个int a = 1，b； 中的a=1部分
    NODE_DECL_VARS,      //用来表示一个int a = 1，b； 中的b  部分
    NODE_DECL_SPCF,      //int unsigned static extern ...
    NODE_DECL_INIT,
    NODE_DECL_FUNC,     //used for declare of function
    NODE_PT_DECLARATOR, //***a **a *a
    NODE_DECLARATOR,    //a
    NODE_PARA_DECL_LIST,
    NODE_PARA_DECL,
    //NODE_WHILE,       //replaced by STMT_WHILE
    //NODE_DO_WHILE,    
    //NODE_FOR,
    //NODE_CONTINUE,
    //NODE_BREAK,
    //NODE_RET,
    NODE_NULL,          //for null node
    NODE_EXTERN_DECL,   //toppest below translation unit
    NODE_EXTERN_FUNC_DECL,
    NODE_ARGUMENT_LIST,
};


enum OperatorType
{
    OP_EQ = 1,          // ==
    OP_N_EQ,        //  !=
    OP_ASSIGN,      // =
    OP_AS_ADDEQ,    // |=
    OP_AS_ANDEQ,    // &=
    OP_AS_DIVEQ,    // /=
    OP_AS_MULEQ,    // *=
    OP_AS_OREQ,     // |=
    OP_AS_SFTL_EQ,  // <<=
    OP_AS_SFTR_EQ,  // >>=
    OP_AS_SUB_EQ,   // -=
    OP_CONDITION,   // ? :
    OP_LGC_OR,      // ||
    OP_LGC_AND,     // &&
    OP_LGC_NOT,     // !
    OP_BIT_XOR,     // ^
    OP_BIT_OR,      // |
    OP_BIT_AND,     // &
    OP_BIT_NOT,     // ~
    OP_REL_L,       // <
    OP_REL_G,       // >
    OP_REL_LE,      // <=
    OP_REL_GE,      // >=
    OP_SFT_L,       // <<
    OP_SFT_R,       // >>
    OP_ADD,         // +
    OP_SUB,         // -
    OP_MUL,         // *
    OP_DIV,         // /
    OP_MOD,         // %
    OP_CAST,        // (TYPE)
    OP_UNA_REF,     // &
    OP_UNA_DEREF,   // * 
    OP_POSITIVE,    // +
    OP_MINUS,       // -
    OP_PRESELFINC,      // ++ a
    OP_PRESELFDEC,      // -- a
    OP_POSTSELFINC,      // ++ a
    OP_POSTSELFDEC,      // -- a
    OP_OFFSET_ACCESS,   // a[expr]
    OP_AC_MEMBER,       //a.name
    OP_PTAC_MEMBER,     //a->name
    OP_FUNC_CALL,       //f(1, 2);

    OP_CONST,           // 'a' or 123 or 0x88
    OP_ID,              // a  or  jj  or  "q4e"
    OP_NONE,
};
#define Is_Op_As(op) (((op) >= OP_ASSIGN) && ((op) <= OP_AS_SUB_EQ))

enum StmtType {
    STMT_SKIP,
    STMT_DECL,
    STMT_COMPOUND,
    STMT_SELECT,
    STMT_DO_WHILE,
    STMT_WHILE,
    STMT_FOR,
    STMT_FOR_NONE,
    STMT_RETURN,
    STMT_BREAK,
    STMT_CONTINUE,
    STMT_EXPRESSION,
    STMT_PRINTF,
    STMT_SCANF,
}
;
//we run into a new function and gets its Function symbol vec
extern _domain* FSYM;

extern std::ofstream iro;
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
    IMOV,    //"*=",                   IndirectMove)
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
    domain_elem* opds[3];
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

typedef 
struct TreeNode {
public:
    int nodeID;  // 用于作业的序号输出
    int lineno;
    NodeType nodeType;

    TreeNode* child = nullptr;
    TreeNode* sibling = nullptr;
    TreeNode* father = nullptr;

    void addChild(TreeNode*);
    void addSibling(TreeNode*);
    
    void printNodeInfo();
    void printChildrenId();
    void print_expr_info();
    void printAST(); // 先输出自己 + 孩子们的id；再依次让每个孩子输出AST。
    void printSpecialInfo();
    void print_stme_info();
    void genNodeId();
public:
    static int _now_id;
public:
    OperatorType optype;  // 如果是表达式
    Type* type;  // 变量、类型、表达式结点，有类型。
    StmtType stype;
    
    /**
     * should be a union of size 4, also works thisway
     */
    int int_val;
    char ch_val;
    bool b_val;
    void* p_val;
    string str_val;

    bool l_value;


    string var_name;
    struct _domain* domain;
    _Type sysType; 
    uint typeMark;
    vector<domain_elem*>*func_args;
    BBlock loopBB;
    BBlock contBB;      
    BBlock nextBB;
    BBlock testBB;

public:
    static string nodeType2String (NodeType type);
    static string opType2String (OperatorType type);
    static string sType2String (StmtType type);
    void print_type_info();
    void copyto(TreeNode* nn);
    void domain_dump();  //has to call before typeDump;
    void typeDump(); //DUMP ALL BASE TYPES (called by root)
    void funcTypeDump();    //DUMP ALL FUNC TYPES (called by root)
    void typeCheck();
    void IRGenerate();
    void print_all_funcs_ir();
    void redefCheck();
    void idTypeDump();
    bool isConstStr();
    inline void swapchild();
private:
    _Type NODE_STMT_Dump();
    _Type NODE_DECL_LIST_Dump(_Type);
    _Type NODE_DECL_Dump(_Type, char* funcname = NULL);
    _Type NODE_DECL_SPCT_Dump(_Type);
    _FunctionType NODE_PARA_LIST_Dump(_FunctionType);
    void __printNodeId(TreeNode* tn);
    void __addSibling(TreeNode* tn);
public:
    //type check
    void tyCheckUndef();
    void tyCheckFunction();
    void tyCheckGlobalDeclaration();
    void CheckInitializerInternal(TreeNode* initializer, _Type ty);

public:
    TreeNode(int lineno, NodeType type);   

} TreeNode;

extern void TranslateFunction(TreeNode* function);
extern void print_bb_tree(domain* dm);
extern struct TreeNode* null_node;
bool CanAssign(TreeNode* initializer, _Type ty);
#endif