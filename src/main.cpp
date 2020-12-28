#include "common.h"
#include <fstream>

extern TreeNode *root;
extern FILE *yyin;
extern int yyparse();
using namespace std;
Type* TYPE_INT = new Type(VALUE_INT);
Type* TYPE_CHAR = new Type(VALUE_CHAR);
Type* TYPE_BOOL = new Type(VALUE_BOOL);
Type* TYPE_STRING = new Type(VALUE_STRING);
Type* TYPE_SIGNED = new Type(VALUE_SIGNED);
Type* TYPE_UNSIGNED = new Type(VALUE_UNSIGNED);
Type* TYPE_CONST = new Type(VALUE_CONST);
Type* TYPE_POINTER = new Type(VALUE_POINTER);
Type* TYPE_ARRAY = new Type(VALUE_ARRAY);
TreeNode* null_node = new TreeNode(-1, NODE_NULL);
_domain *d_root;
int main(int argc, char *argv[])
{
    d_root = new _domain();
    if (argc == 2)
    {
        FILE *fin = fopen(argv[1], "r");
        if (fin != nullptr)
        {
            yyin = fin;
        }
        else
        {
            cerr << "failed to open file: " << argv[1] << endl;
        }
    }
    cout << "entering yyparse" << endl;
    yyparse();
    cout << "parsed" << endl;
    if(root != NULL) {
        //root->genNodeId();
        root->printAST();
    }
    cout << "setting up type system\n";
    root->domain = d_root;
    //if (root->domain->type == global) cout << "ok\n";
    root->domain_dump();
    SetupTypeSystem();
    root->typeDump();
    root->funcTypeDump();
    root->redefCheck();
    root->tyCheckUndef();
    return 0;
}