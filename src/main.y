%{
    #include "common.h"
    #include "tree.h"
    #include "domain.h"
    #include "inter.h"
    #define YYSTYPE TreeNode *  
    TreeNode* root;
    BBlock currentBB;
    extern int lineno;
    extern domain* d_root;
    int yylex();
    int yyerror( char const * );
    
%}
%token T_CHAR T_INT T_STRING T_BOOL T_VOID SCANF PRINTF

%token LO_EQ LO_N_EQ RO_AS_ADDEQ RO_AS_SUBEQ RO_AS_MULEQ RO_AS_DIVEQ RO_AS_SFTL_EQ

%token RO_AS_SFTR_EQ RO_AS_ANDEQ RO_AS_OREQ LO_AS_SELFINC LO_AS_SELFDEC RO_TRI_QUES

%token RO_TRI_COLON LO_MUL LO_DIV LO_ADD LO_SUB LO_BIT_NOT LO_MOD LO_SFT_L LO_LGC_OR LO_LGC_AND

%token  LO_SFT_R LO_LGC_NOT LO_BIT_XOR LO_BIT_AND LO_BIT_OR RO_ASSIGN LO_COMMA

%token KW_CONTINUE KW_BREAK KW_IF KW_FOR KW_RET KW_STRUCT KW_WHILE KW_DO KW_ELSE T_SIGNED T_UNSIGNED Q_CONST

%token SEMICOLON COLON LO_REL_L LO_REL_G LO_REL_LE LO_REL_GE KW_UNION

%token IDENTIFIER INTEGER CHAR BOOL STRING  LO_MEMBER LO_PT_MEMBER

%token L_BRACKET R_BRACKET L_SQ_BRACKET R_SQ_BRACKET L_BRACE R_BRACE
%left R_BRACKET R_SQ_BRACKET R_BRACE
%right L_BRACKET L_SQ_BRACKET L_BRACE

%left RO_ASSIGN RO_AS_ADDEQ RO_AS_SUBEQ RO_AS_MULEQ RO_AS_DIVEQ RO_AS_SFTL_EQ
%left RO_AS_SFTR_EQ RO_AS_ANDEQ RO_AS_OREQ LO_LGC_OR LO_LGC_AND LO_REL_L LO_REL_G LO_REL_LE LO_REL_GE

%%
translation-unit:
external-declaration{
    root = new TreeNode(0, NODE_PROG);
    root->domain = d_root;
    root->addChild($1);
}
| translation-unit external-declaration{
    root->addChild($2);
}
;

external-declaration:
function-definition{
    TreeNode* node = new TreeNode(lineno, NODE_EXTERN_DECL);
    node->addChild($1);
    $$ = node;
}
|   declaration{
    TreeNode* node = new TreeNode(lineno, NODE_EXTERN_DECL);
    node->addChild($1);
    $$ = node;
}
;

function-definition:
declaration-specifiers  declarator compound-statement{
    TreeNode* node = new TreeNode(lineno, NODE_EXTERN_FUNC_DECL);
    TreeNode* node2 = new TreeNode(lineno, NODE_DECL_SPCF);
    node->addChild(node2);
    node2->addChild($1);
    node->addChild($2);
    node->addChild($3);
    $$ = node;
}

statements:
statement {$$=$1;}
| statements statement {$$=$1; $$->addSibling($2);}
;

statement:
  SEMICOLON  {$$ = new TreeNode(lineno, NODE_STMT); $$->stype = STMT_SKIP;}
| declaration {$$ = $1;}
| compound-statement{$$ = $1;}
| expression-statement{$$ = $1;}
| selection-statement{$$ = $1;}
| iteration-statement{$$ = $1;}
| jump-statement{$$ = $1;}
| io-statement{$$ = $1;}
;

io-statement:
PRINTF L_BRACKET STRING LO_COMMA assignment-expression R_BRACKET SEMICOLON{
    $$ = new TreeNode(lineno, NODE_STMT);
    $$->stype = STMT_PRINTF;
    $$->addChild($3);
    $$->addChild($5);
}
| SCANF L_BRACKET STRING LO_COMMA unary-expression R_BRACKET SEMICOLON{
    $$ = new TreeNode(lineno, NODE_STMT);
    $$->stype = STMT_SCANF;
    $$->addChild($3);
    $$->addChild($5);
}

jump-statement:
    KW_BREAK SEMICOLON{
    TreeNode* node = new TreeNode(lineno, NODE_STMT);
    node->stype = STMT_BREAK;
    $$ = node;
}
|   KW_CONTINUE SEMICOLON{
    TreeNode* node = new TreeNode(lineno, NODE_STMT);
    node->stype = STMT_CONTINUE;
    $$ = node; 
}
|   KW_RET SEMICOLON{
    TreeNode* node = new TreeNode(lineno, NODE_STMT);
    node->stype = STMT_RETURN;
    $$ = node;
}
|   KW_RET  assignment-expression SEMICOLON{
    TreeNode* node = new TreeNode(lineno, NODE_STMT);
    node->stype = STMT_RETURN;
    $$ = node;
    $$->addChild($2);
}
;

iteration-statement
:   KW_WHILE L_BRACKET expression R_BRACKET statement{
    TreeNode* node = new TreeNode(lineno, NODE_STMT);
    node->stype = STMT_WHILE;
    node->addChild($3);
    node->addChild($5);
    $$ = node;
}
|   KW_DO statement KW_WHILE  L_BRACKET expression R_BRACKET{
    TreeNode* node = new TreeNode(lineno, NODE_STMT);
    node->stype = STMT_DO_WHILE;
    node->addChild($5);
    node->addChild($2);
    $$ = node;
}
|   KW_FOR L_BRACKET SEMICOLON SEMICOLON R_BRACKET statement{
    TreeNode* node = new TreeNode(lineno, NODE_STMT);
    node->stype = STMT_FOR_NONE;
    TreeNode* node1 = new TreeNode(-1, NODE_NULL);
    TreeNode* node2 = new TreeNode(-1, NODE_NULL);
    TreeNode* node3 = new TreeNode(-1, NODE_NULL);
    node->addChild(node1);
    node->addChild(node2);
    node->addChild(node3);
    $$ = node;
}
|   KW_FOR L_BRACKET expression SEMICOLON expression SEMICOLON expression R_BRACKET statement{
    TreeNode* node = new TreeNode(lineno, NODE_STMT);
    node->stype = STMT_FOR;
    node->addChild($3);
    node->addChild($5);
    node->addChild($7);
    node->addChild($9);
    $$ = node;
}
;



selection-statement
:   KW_IF L_BRACKET expression R_BRACKET statement{
    TreeNode* node = new TreeNode(lineno, NODE_STMT);
    node->stype = STMT_SELECT;
    node->addChild($3);
    node->addChild($5);
    $$ = node;
}
|   KW_IF L_BRACKET expression R_BRACKET statement  KW_ELSE statement{
    TreeNode* node = new TreeNode(lineno, NODE_STMT);
    node->stype = STMT_SELECT;
    node->addChild($3);
    node->addChild($5);
    node->addChild($7);
    $$ = node;
}
;

expression-statement
:   SEMICOLON{$$ = new TreeNode(lineno, NODE_STMT); $$->stype = STMT_SKIP;}
|   expression SEMICOLON{
    TreeNode* node = new TreeNode(lineno, NODE_STMT);
    node->stype = STMT_EXPRESSION;
    node->addChild($1);
    $$ = node;
}

compound-statement
:   L_BRACE block-item-list R_BRACE{
    $$ = new TreeNode(lineno, NODE_STMT); 
    $$->stype = STMT_COMPOUND;
    $$->addChild($2);
}
|   L_BRACE R_BRACE{
    $$ = new TreeNode(lineno, NODE_STMT); 
    $$->stype = STMT_COMPOUND;
}
;

block-item-list
:   block-item{
    $$ = new TreeNode(lineno, NODE_BLOCK_LIST);
    $$->addChild($1);
}
|   block-item-list block-item{
    $1->addChild($2);
    $$ = $1;
}
;

block-item
:   declaration{
    $$ = $1;
}
|   statement{
    $$ = $1;
}
;

declaration
:   declaration-specifiers  init-declarator-list SEMICOLON{
    TreeNode* node = new TreeNode(lineno, NODE_STMT);
    TreeNode* node2 = new TreeNode(lineno, NODE_DECL_SPCF);
    
    node->stype = STMT_DECL;
    node->addChild(node2);
    node2->addChild($1);
    node->addChild($2);
    $$ = node;
}
|   declaration-specifiers{
    TreeNode* node = new TreeNode(lineno, NODE_STMT);
    TreeNode* node2 = new TreeNode(lineno, NODE_DECL_SPCF);
    
    node->stype = STMT_DECL;
    node->addChild(node2);
    node2->addChild($1);
    $$ = node;
}
;

declaration-specifiers
:   type-specifier{
    $$ = $1;
}
|   type-specifier declaration-specifiers{
    $1 -> addSibling($2);
    $$ = $1;
}
|   type-qualifier{
    $$ = $1;
}
|   type-qualifier declaration-specifiers{
    $1->addSibling($2);
    $$ = $1;
}
;


init-declarator-list:
   init-declarator{
    TreeNode* node = new TreeNode(lineno, NODE_DECL_LIST);
    node->addChild($1);
    $$ = node;
}
|   init-declarator-list LO_COMMA init-declarator{
    $1->addChild($3);
    $$ = $1;
}
;

init-declarator
:   declarator{
    TreeNode* fnode = new TreeNode(lineno, NODE_DECL);
    TreeNode* node = new TreeNode(lineno, NODE_DECL_VARS);
    node->addChild($1);
    fnode->addChild(node);
    $$ = fnode;
}   
|   declarator RO_ASSIGN initializer{
    TreeNode* fnode = new TreeNode(lineno, NODE_DECL);
    TreeNode* node = new TreeNode(lineno, NODE_INIT_DECL_VARS);
    node->addChild($1);
    node->addChild($3);
    fnode->addChild(node);
    $$ = fnode;
}
;

initializer
:   assignment-expression{
    TreeNode* node = new TreeNode(lineno, NODE_DECL_INIT);
    node->addChild($1);
    //cout << "ckpt1\n";
    $$ = node;
    //cout << "ckpt2\n";
}
|   L_BRACE initializer-list R_BRACE{
    TreeNode* node = new TreeNode(lineno, NODE_DECL_INIT);
    node->addChild($2);
    $$ = node;
}
;

initializer-list
:   initializer{
    $$ = $1;
}
|   initializer-list LO_COMMA initializer{
    $1->addSibling($3);
    $$ = $1;
}
;



expression
:   assignment-expression{
    TreeNode* node = new TreeNode(lineno, NODE_EXPR);
    node->addChild($1);
    $$ = node;
}
|   expression LO_COMMA assignment-expression{
    //TreeNode* node = new TreeNode(lineno, NODE_EXPR);
    
    $1->addSibling($2);
    $$ = $1;
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
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
    node-> optype = $2->optype;
    node-> addChild($1);
    node-> addChild($3);
    //node-> addChild($2);
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
|   inclusive-OR-expression LO_BIT_OR exclusive-OR-expression{
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
|   L_BRACKET type-specifier R_BRACKET cast-expression{
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
    node -> optype = OP_CAST;
    node -> addChild($2);
    node -> addChild($3);
    $$ = node;
}
;

unary-operator
:   LO_BIT_AND      {$$ = new TreeNode(lineno, NODE_OP); $$->optype = OP_UNA_REF;}
|   LO_MUL          {$$ = new TreeNode(lineno, NODE_OP); $$->optype = OP_UNA_DEREF;}
|   LO_ADD          {$$ = new TreeNode(lineno, NODE_OP); $$->optype = OP_POSITIVE;}
|   LO_SUB          {$$ = new TreeNode(lineno, NODE_OP); $$->optype = OP_MINUS;}
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
    //node -> addChild($1);
    node -> addChild($2);
    $$ = node;
}
;


postfix-expression:
   primary-expression{
    $$ = $1;
}
|   postfix-expression L_SQ_BRACKET expression R_SQ_BRACKET{
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
    node -> optype = OP_OFFSET_ACCESS;
    node -> addChild($1);
    node -> addChild($3);
    $$ = node;
}
|   postfix-expression LO_MEMBER IDENTIFIER{
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
    node -> optype = OP_AC_MEMBER;
    node -> addChild($1);
    node -> addChild($3);
    $$ = node;
} 
|   postfix-expression LO_PT_MEMBER IDENTIFIER{
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
    node -> optype = OP_PTAC_MEMBER;
    node -> addChild($1);
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
|   postfix-expression L_BRACKET  argument-expression-list R_BRACKET{
    TreeNode* node = new TreeNode(lineno, NODE_EXPR);
    //cout << "postfix func\n";
    node->optype = OP_FUNC_CALL;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
}
|   postfix-expression L_BRACKET R_BRACKET{
    TreeNode* node = new TreeNode(lineno, NODE_EXPR);
    TreeNode* augs = new TreeNode(lineno, NODE_ARGUMENT_LIST);
    node->optype = OP_FUNC_CALL;
    node->addChild($1);
    node->addChild(augs);
    $$ = node;
}
;

argument-expression-list:
assignment-expression{
    TreeNode* node = new TreeNode(lineno, NODE_ARGUMENT_LIST);
    node->addChild($1);
    //cout << "ae\n";
    $$ = node;
}
|   argument-expression-list LO_COMMA assignment-expression{
    //cout << "aes\n";
    $1->addChild($3);
    $$ = $1;
}
;

primary-expression:
   IDENTIFIER{
    //cout << "id\n";
    $$ = $1;
}
|   constant{
    $$ = $1;
}    
|   L_BRACKET expression R_BRACKET{
    $$ = $2;
}
;

constant
:   INTEGER{
    $$ = $1;
    // if ($1->nodeType == NODE_CONST){
    //         cout << "const";
    //     }
    // if($1->type == TYPE_INT){
        
    // }else{
    //     cout << "完蛋\n";
    // }
    // if ($1->type){
    //     cout<< " yacc node->type" << $1->type << endl;
    //     cout << " yacc TYPE_INT" << TYPE_INT << endl;
    // }
}
|   STRING{
    $$ = $1;
}
;

type-specifier
: T_INT {$$ = new TreeNode(lineno, NODE_TYPE); $$->type = TYPE_INT; } 
| T_CHAR {$$ = new TreeNode(lineno, NODE_TYPE); $$->type = TYPE_CHAR;}
| T_BOOL {$$ = new TreeNode(lineno, NODE_TYPE); $$->type = TYPE_BOOL;}
| T_VOID {$$ = new TreeNode(lineno, NODE_TYPE); $$->type = TYPE_VOID;}
| T_SIGNED {$$ = new TreeNode(lineno, NODE_TYPE); $$->type = TYPE_SIGNED;}
| T_UNSIGNED {$$ = new TreeNode(lineno, NODE_TYPE); $$->type = TYPE_UNSIGNED;}
| struct-or-union-specifier {$$ = $1;}
;
    
struct-or-union-specifier
:   struct-or-union IDENTIFIER L_BRACE struct-declaration-list R_BRACE{
    $$ = NULL;
}
|   struct-or-union L_BRACE struct-declaration-list R_BRACE{
    $$ = NULL;
}
|   struct-or-union IDENTIFIER{
    $$ = NULL;
}
;

struct-or-union:    KW_STRUCT {}| KW_UNION {};

struct-declaration-list
:   struct-declaration{
    $$ = NULL;
}
|   struct-declaration-list struct-declaration{
    $$ = NULL;
}
;

struct-declaration:
    specifier-qualifier-list struct-declarator-list SEMICOLON{
        $$ = NULL;
    };

specifier-qualifier-list:
    type-specifier{} 
|   type-specifier specifier-qualifier-list{}
|   type-qualifier{}
|   type-qualifier specifier-qualifier-list{}
;

struct-declarator-list:
    struct-declarator{}
|   struct-declarator-list LO_COMMA struct-declarator{}
;

struct-declarator:
    declarator{$$ = $1;}
|   declarator COLON INTEGER{}
;

declarator:
    pointer declarator{
        TreeNode*node = new TreeNode(lineno, NODE_PT_DECLARATOR);
        node->addChild($2);
        $$ = node;
    }
|   direct-declarator{
        TreeNode*node = new TreeNode(lineno, NODE_DECLARATOR);
        node->addChild($1);
        $$ = node;
    }
;

direct-declarator:
IDENTIFIER{
    $$ = $1;
}
|   direct-declarator L_SQ_BRACKET  assignment-expression R_SQ_BRACKET{
    TreeNode* node = new TreeNode(lineno, NODE_TYPE);
    node->type = TYPE_ARRAY;
    //cout << "ARRAY!!!\n";
    node->addChild($1);
    node->addChild($3);
    $$ = node;
}
|   direct-declarator L_BRACKET parameter-type-list R_BRACKET{
    TreeNode* fnode = new TreeNode(lineno, NODE_DECL);
    TreeNode* node = new TreeNode(lineno, NODE_DECL_FUNC);
    node->addChild($1);
    node->addChild($3);
    fnode->addChild(node);
    $$ = fnode;
}
|   direct-declarator L_BRACKET  R_BRACKET{
    TreeNode* fnode = new TreeNode(lineno, NODE_DECL);
    TreeNode* node = new TreeNode(lineno, NODE_DECL_FUNC);
    node->addChild($1);
    TreeNode* listnode = new TreeNode(lineno, NODE_PARA_DECL_LIST);
    node->addChild(listnode);
    fnode->addChild(node);
    $$ = fnode;
}
;   
parameter-type-list: 
parameter-declaration{
    TreeNode* node = new TreeNode(lineno, NODE_PARA_DECL_LIST);
    //cout << "ck1";
    node->addChild($1);
    $$ = node;
}
|   parameter-type-list LO_COMMA parameter-declaration{
    $1->addChild($3);
    //cout << $1->nodeType;
    $$ = $1;
}
;

parameter-declaration:
declaration-specifiers declarator{
    TreeNode* node = new TreeNode(lineno, NODE_PARA_DECL);
    TreeNode* node2 = new TreeNode(lineno, NODE_DECL_SPCF);
    
    node->addChild(node2); 
    node2->addChild($1);
    node->addChild($2);
    $$ = node;
}
|   declaration-specifiers{
    TreeNode* node = new TreeNode(lineno, NODE_PARA_DECL);
    TreeNode* node2 = new TreeNode(lineno, NODE_DECL_SPCF);
    
    node->addChild(node2); 
    node2->addChild($1);
    $$ = node;
}
;


pointer:
    LO_MUL  {TreeNode* node = new TreeNode(lineno, NODE_TYPE); node->type = TYPE_POINTER; $$ = node;}
// |   LO_MUL pointer{
//         TreeNode* node = new TreeNode(lineno, NODE_TYPE); 
//         node->type = TYPE_POINTER;
//         node->addSibling($2);
//         $$ = node;
//     }
;

type-qualifier:
    Q_CONST{
        $$ = new TreeNode(lineno, NODE_TYPE); $$->type = TYPE_CONST;
    };
%%





int yyerror(char const* message)
{
  cout << message << " at line " << lineno << endl;
  return -1;
}