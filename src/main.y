%{
    #include "common.h"
    #define YYSTYPE TreeNode *  
    TreeNode* root;
    extern int lineno;
    int yylex();
    int yyerror( char const * );
%}
%token T_CHAR T_INT T_STRING T_BOOL  LO_PT_MEMBER LO_MEMBER
%token L_BRACKET R_BRACKET L_SQ_BRACKET R_SQ_BRACKET L_BRACE R_BRACE
%token LO_EQ LO_N_EQ RO_AS_ADDEQ RO_AS_SUBEQ RO_AS_MULEQ RO_AS_DIVEQ RO_AS_SFTL_EQ

%token RO_AS_SFTR_EQ RO_AS_ANDEQ RO_AS_OREQ LO_AS_SELFINC LO_AS_SELFDEC RO_TRI_QUES

%token RO_TRI_COLON LO_MUL LO_DIV LO_ADD LO_SUB LO_BIT_NOT LO_MOD LO_SFT_L

%token  LO_SFT_R LO_LGC_NOT LO_BIT_XOR LO_BIT_AND LO_BIT_OR RO_ASSIGN LO_LGC_OR LO_LGC_AND

%token KW_IF KW_FOR KW_RET KW_STRUCT KW_WHILE KW_DO Q_UNSIGNED Q_CONST

%token SEMICOLON LO_COMMA LO_REL_L LO_REL_G LO_REL_LE LO_REL_GE

%token IDENTIFIER INTEGER CHAR BOOL STRING

%left RO_ASSIGN LO_LGC_OR LO_LGC_AND



%%

program
: statements {root = new TreeNode(0, NODE_PROG); root->addChild($1);};

statements
:  statement {$$=$1;}
|  statements statement {$$=$1; $$->addSibling($2);}
;

statement
: SEMICOLON  {$$ = new TreeNode(lineno, NODE_STMT); $$->stype = STMT_SKIP;}
| declaration SEMICOLON {$$ = $1;}
;

declaration
: T IDENTIFIER RO_ASSIGN expr{  // declare and init
    TreeNode* node = new TreeNode($1->lineno, NODE_STMT);
    node->stype = STMT_DECL;
    node->addChild($1);
    node->addChild($2);
    node->addChild($4);
    $$ = node;   
} 
| T IDENTIFIER {
    TreeNode* node = new TreeNode($1->lineno, NODE_STMT);
    node->stype = STMT_DECL;
    node->addChild($1);
    node->addChild($2);
    $$ = node;   
}
;

expr
: IDENTIFIER {
    $$ = $1;
}
| INTEGER {
    $$ = $1;
}
| CHAR {
    $$ = $1;
}
| STRING {
    $$ = $1;
}
;

T: T_INT {$$ = new TreeNode(lineno, NODE_TYPE); $$->type = TYPE_INT;} 
| T_CHAR {$$ = new TreeNode(lineno, NODE_TYPE); $$->type = TYPE_CHAR;}
| T_BOOL {$$ = new TreeNode(lineno, NODE_TYPE); $$->type = TYPE_BOOL;}
;

%%

int yyerror(char const* message)
{
  cout << message << " at line " << lineno << endl;
  return -1;
}