%{
    #include "common.h"
    #define YYSTYPE TreeNode *  
    TreeNode* root;
    extern int lineno;
    int yylex();
    int yyerror( char const * );
%}
%token T_CHAR T_INT T_STRING T_BOOL 

%token LO_EQ LO_N_EQ RO_AS_ADDEQ RO_AS_SUBEQ RO_AS_MULEQ RO_AS_DIVEQ RO_AS_SFTL_EQ

%token RO_AS_SFTR_EQ RO_AS_ANDEQ RO_AS_OREQ LO_AS_SELFINC LO_AS_SELFDEC RO_TRI_QUES

%token RO_TRI_COLON LO_MUL LO_DIV LO_ADD LO_SUB LO_BIT_NOT LO_MOD LO_SFT_L LO_LGC_OR LO_LGC_AND

%token  LO_SFT_R LO_LGC_NOT LO_BIT_XOR LO_BIT_AND LO_BIT_OR RO_ASSIGN LO_COMMA

%token KW_IF KW_FOR KW_RET KW_STRUCT KW_WHILE KW_DO Q_UNSIGNED Q_CONST

%token SEMICOLON RO_ASSIGN LO_REL_L LO_REL_G LO_REL_LE LO_REL_GE

%token IDENTIFIER INTEGER CHAR BOOL STRING  LO_MEMBER LO_PT_MEMBER

%token L_BRACKET R_BRACKET L_SQ_BRACKET R_SQ_BRACKET L_BRACE R_BRACE
%left R_BRACKET R_SQ_BRACKET R_BRACE
%right L_BRACKET L_SQ_BRACKET L_BRACE

%left RO_ASSIGN RO_AS_ADDEQ RO_AS_SUBEQ RO_AS_MULEQ RO_AS_DIVEQ RO_AS_SFTL_EQ
%left RO_AS_SFTR_EQ RO_AS_ANDEQ RO_AS_OREQ LO_LGC_OR LO_LGC_AND LO_REL_L LO_REL_G LO_REL_LE LO_REL_GE

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
: T IDENTIFIER LOP_ASSIGN expr{  // declare and init
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

expression
:   assignment-expression{
    $$ = $1;
}
|   expression, assignment-expression{
    $1->addChild($2);
}
;
assignment-operator
:   RO_ASSIGN       {$$ = new TreeNode(lineno, NODE_OP); $$->optype = OP_ASSIGN;}
|   RO_AS_ADDEQ     {$$ = new TreeNode(lineno, NODE_OP); $$->optype = OP_AS_ADDEQ;}
|   RO_AS_ANDEQ     {$$ = new TreeNode(lineno, NODE_OP); $$->optype = OP_AS_ANDEQ;}
|   RO_AS_DIVEQ     {$$ = new TreeNode(lineno, NODE_OP); $$->optype = OP_AS_DIVEQ;}
|   RO_AS_MULEQ     {$$ = new TreeNode(lineno, NODE_OP); $$->optype = OP_AS_MULEQ;}
|   RO_AS_OREQ      {$$ = new TreeNode(lineno, NODE_OP); $$->optype = OP_AS_OREQ;}
|   RO_AS_SFTL_EQ   {$$ = new TreeNode(lineno, NODE_OP); $$->optype = OP_AS_SFTL_EQ;}
|   RO_AS_SFTR_EQ   {$$ = new TreeNode(lineno, NODE_OP); $$->optype = OP_AS_SFTR_EQ;}
|   RO_AS_SUBEQ     {$$ = new TreeNode(lineno, NODE_OP); $$->optype = OP_AS_SUB_EQ;}
;

assignment-expression
:   conditional-expression{
    $$ = $1;
}
|   unary-expression  assignment-operator  assignment-expression{
    TreeNode* node = new TreeNode($1->lineno, NODE_ASSI);
    node-> optype = $2->optype;
    node-> addChild($1);
    node-> addChild($2);
    node-> addChild($3);
    $$ = node;
}
;

conditional-expression
:   logical-OR-expression{
    $$ = $1;
}
|   logical-OR-expression RO_TRI_QUES expression RO_TRI_COLON conditional-expression{
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
    node -> optype = OP_CONDITION;
    node -> addChild($1);
    node -> addChild($3);
    node -> addChild($5);
    $$ = node;
}
;

logical-OR-expression
:   logical-AND-expression{
    $$ = $1;
}   
|   logical-OR-expression LO_LGC_OR logical-AND-expression {
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
    node -> optype = OP_LGC_OR;
    node -> addChild($1);
    node -> addChild($3);
    $$ = node;
}
;

logical-AND-expression
:   inclusive-OR-expression{
    $$ = $1;
}
|   logical-AND-expression LO_LGC_AND inclusive-OR-expression{
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
    node -> optype = OP_LGC_AND;
    node -> addChild($1);
    node -> addChild($3);
    $$ = node;
}
;

inclusive-OR-expression
:   exclusive-OR-expression{
    $$ = $1;
}
}   inclusive-OR-expression LO_BIT_OR exclusive-OR-expression{
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
    node -> optype = OP_BIT_OR;
    node -> addChild($1);
    node -> addChild($3);
    $$ = node;
}
;

exclusive-OR-expression
:   AND-expression {
    $$ = $1;
}  
|   exclusive-OR-expression LO_BIT_XOR AND-expression{
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
    node -> optype = OP_BIT_XOR;
    node -> addChild($1);
    node -> addChild($3);
    $$ = node;
}
;

AND-expression
:   equality-expression{
    $$ = $1;
}
|   AND-expression LO_BIT_AND equality-expression{
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
    node -> optype = OP_BIT_AND;
    node -> addChild($1);
    node -> addChild($3);
    $$ = node;
}
;

equality-expression
:   relational-expression{
    $$ = $1;
}
|   equality-expression LO_EQ relational-expression{
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
    node -> optype = OP_EQ;
    node -> addChild($1);
    node -> addChild($3);
    $$ = node;
}
|   equality-expression LO_N_EQ relational-expression{
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
    node -> optype = OP_N_EQ;
    node -> addChild($1);
    node -> addChild($3);
    $$ = node;
}
;

relational-expression
:   shift-expression{
    $$ = $1;
}
|   relational-expression LO_REL_L  shift-expression{
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
    node -> optype = OP_REL_L;
    node -> addChild($1);
    node -> addChild($3);
    $$ = node;
}
|   relational-expression LO_REL_G  shift-expression{
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
    node -> optype = OP_REL_G;
    node -> addChild($1);
    node -> addChild($3);
    $$ = node;
}
|   relational-expression LO_REL_LE  shift-expression{
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
    node -> optype = OP_REL_LE;
    node -> addChild($1);
    node -> addChild($3);
    $$ = node;
}
|   relational-expression LO_REL_GE  shift-expression{
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
    node -> optype = OP_REL_GE;
    node -> addChild($1);
    node -> addChild($3);
    $$ = node;
}
;

shift-expression
:   additive-expression{
    $$ = $1;
}
|   shift-expression LO_SFT_L additive-expression{
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
    node -> optype = OP_SFT_L;
    node -> addChild($1);
    node -> addChild($3);
    $$ = node;
}
|   shift-expression LO_SFT_R additive-expression{
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
    node -> optype = OP_SFT_R;
    node -> addChild($1);
    node -> addChild($3);
    $$ = node;
}
;

additive-expression
:   multiplicative-expression{
    $$ = $1;
}
|   additive-expression LO_ADD multiplicative-expression{
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
    node -> optype = OP_ADD;
    node -> addChild($1);
    node -> addChild($3);
    $$ = node;
}
|   additive-expression LO_SUB multiplicative-expression{
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
    node -> optype = OP_SUB;
    node -> addChild($1);
    node -> addChild($3);
    $$ = node;
}
;

multiplicative-expression
:   cast-expression{
    $$ = $1;
}
|   multiplicative-expression LO_MUL cast-expression{
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
    node -> optype = OP_MUL;
    node -> addChild($1);
    node -> addChild($3);
    $$ = node;
}
|   multiplicative-expression LO_DIV cast-expression{
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
    node -> optype = OP_DIV;
    node -> addChild($1);
    node -> addChild($3);
    $$ = node;
}
|   multiplicative-expression LO_MOD cast-expression{
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
    node -> optype = OP_MOD;
    node -> addChild($1);
    node -> addChild($3);
    $$ = node;
}
;

cast-expression
:   unary-expression{
    $$ = $1;
}
|   L_BRACKET T R_BRACKET cast-expression{
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
    node -> optype = OP_CAST;
    node -> addChild($2);
    node -> addChild($3);
    $$ = node;
}
;

unary-operator
:   OP_BIT_AND      {$$ = new TreeNode(lineno, NODE_OP); $$->optype = OP_UNA_REF;}
|   OP_MUL          {$$ = new TreeNode(lineno, NODE_OP); $$->optype = OP_UNA_DEREF;}
|   OP_ADD          {$$ = new TreeNode(lineno, NODE_OP); $$->optype = OP_POSITIVE;}
|   OP_DIV          {$$ = new TreeNode(lineno, NODE_OP); $$->optype = OP_MINUS;}
|   LO_BIT_NOT      {$$ = new TreeNode(lineno, NODE_OP); $$->optype = OP_BIT_NOT;}
|   LO_LGC_NOT      {$$ = new TreeNode(lineno, NODE_OP); $$->optype = OP_LGC_NOT;}
;

unary-expression
:   postfix-expression{
    $$ = $1;
}
|   LO_AS_SELFINC unary-expression{
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
    node -> optype = OP_PRESELFINC;
    node -> addChild($2);
    $$ = node;
}
|   LO_AS_SELFDEC unary-expression{
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
    node -> optype = OP_PRESELFDEC;
    node -> addChild($2);
    $$ = node;
}
|   unary-operator cast-expression{
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
    node -> optype = $1->optype;
    nodd -> addChild($1);
    node -> addChild($2);
    $$ = node;
}
;

argument-expression-list
:   assignment-expression{
    $$ = $1;
}
|   argument-expression-list LO_COMMA assignment-expression{
    cout << "argument expression list adding sibling\n";
    $1 -> addSibling($3);
    $$ = $1;
}
;

postfix-expression
:   primary-expression{
    $$ = $1;
}
|   postfix-expression L_SQ_BRACKET expression R_SQ_BRACKET{
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
    node -> optype = OP_OFFSET_ACCESS;
    nodd -> addChild($1);
    node -> addChild($3);
    $$ = node;
}
|   postfix-expression LO_MEMBER IDENTIFIER{
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
    node -> optype = OP_AC_MEMBER;
    nodd -> addChild($1);
    node -> addChild($3);
    $$ = node;
} 
|   postfix-expression LO_PT_MEMBER IDENTIFIER{
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
    node -> optype = OP_PTAC_MEMBER;
    nodd -> addChild($1);
    node -> addChild($3);
    $$ = node;
}
|   postfix-expression LO_AS_SELFINC{
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
    node -> optype = OP_POSTSELFINC;
    node -> addChild($1);
    $$ = node;
}
|   postfix-expression LO_AS_SELFDEC{
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
    node -> optype = OP_POSTSELFDEC;
    node -> addChild($1);
    $$ = node;
}
;

primary-expression
:   IDENTIFIER{
    $$ = $1;
}
|   constant{
    $$ = $1;
}    
|   L_BRACKET expression R_BRACKET{
    $$ = $2;
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