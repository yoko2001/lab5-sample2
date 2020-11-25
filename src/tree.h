#ifndef TREE_H
#define TREE_H

#include "pch.h"
#include "type.h"

enum NodeType
{
    NODE_CONST, 
    NODE_VAR,
    NODE_EXPR,
    NODE_TYPE,
    NODE_ASSI,
    NODE_STMT,
    NODE_PROG,
    NODE_OP,
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
};

enum StmtType {
    STMT_SKIP,
    STMT_DECL,
}
;

struct TreeNode {
public:
    int nodeID;  // 用于作业的序号输出
    int lineno;
    NodeType nodeType;

    TreeNode* child = nullptr;
    TreeNode* sibling = nullptr;

    void addChild(TreeNode*);
    void addSibling(TreeNode*);
    
    void printNodeInfo();
    void printChildrenId();

    void printAST(); // 先输出自己 + 孩子们的id；再依次让每个孩子输出AST。
    void printSpecialInfo();

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
public:
    static string nodeType2String (NodeType type);
    static string opType2String (OperatorType type);
    static string sType2String (StmtType type);
private:
    void __printNodeId(TreeNode* tn);
    void __addSibling(TreeNode* tn);
public:
    TreeNode(int lineno, NodeType type);
};

#endif