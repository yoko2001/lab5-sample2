#ifndef TREE_H
#define TREE_H

#include "pch.h"
#include "type.h"
#include "djl_type.h"
#include "domain.h"

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
    NODE_WHILE,
    NODE_DO_WHILE,
    NODE_FOR,
    NODE_CONTINUE,
    NODE_BREAK,
    NODE_RET,
    NODE_NULL,          //for null node
    NODE_EXTERN_DECL,   //toppest below translation unit
    NODE_EXTERN_FUNC_DECL,
    NODE_ARGUMENT_LIST,
};

enum OperatorType
{
    OP_EQ,          // ==
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
};

enum StmtType {
    STMT_SKIP,
    STMT_DECL,
    STMT_COMPOUND,
    STMT_BLOCK,
    STMT_SELECT,
}
;

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
    int int_val;
    char ch_val;
    bool b_val;
    string str_val;
    string var_name;
    struct _domain* domain;
public:
    static string nodeType2String (NodeType type);
    static string opType2String (OperatorType type);
    static string sType2String (StmtType type);
    void print_type_info();
    _Type NODE_STMT_Dump();
    _Type NODE_DECL_LIST_Dump(_Type);
    _Type NODE_DECL_Dump(_Type, char* funcname = NULL);
    _Type NODE_DECL_SPCT_Dump(_Type);
    _FunctionType NODE_PARA_LIST_Dump(_FunctionType);
    void domain_dump();  //has to call before typeDump;
    void typeDump(); //DUMP ALL BASE TYPES (called by root)
    void funcTypeDump();    //DUMP ALL FUNC TYPES (called by root)
private:
    void __printNodeId(TreeNode* tn);
    void __addSibling(TreeNode* tn);
public:
    TreeNode(int lineno, NodeType type);   

};

extern TreeNode* null_node;

#endif