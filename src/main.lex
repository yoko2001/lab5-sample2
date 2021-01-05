%option nounput
%{
#include "common.h"
#include "main.tab.h"  // yacc header
int lineno=1;
%}
BLOCKCOMMENT \/\*([^\*^\/]*|[\*^\/*]*|[^\**\/]*)*\*\/
LINECOMMENT \/\/[^\n]*
EOL	(\r\n|\r|\n)
WHILTESPACE [[:blank:]]

INTEGER [0-9]+

CHAR \'.?\'
STRING \".+\"

IDENTIFIER [[:alpha:]_][[:alpha:][:digit:]_]*
%%

{BLOCKCOMMENT}  /* do nothing */
{LINECOMMENT}  /* do nothing */

"("     return L_BRACKET;
")"     return R_BRACKET;
"["     return L_SQ_BRACKET;
"]"     return R_SQ_BRACKET;
"{"     return L_BRACE;
"}"     return R_BRACE;
"=="    return LO_EQ;
"!="    return LO_N_EQ;
"+="    return RO_AS_ADDEQ;
"-="    return RO_AS_SUBEQ;
"*="    return RO_AS_MULEQ;
"/="    return RO_AS_DIVEQ;
"<<="   return RO_AS_SFTL_EQ;
">>="   return RO_AS_SFTR_EQ;
"&="    return RO_AS_ANDEQ;
"|="    return RO_AS_OREQ; 
"++"    return LO_AS_SELFINC;
"--"    return LO_AS_SELFDEC;
"?"     return RO_TRI_QUES;
":"     return RO_TRI_COLON;
"*"     return LO_MUL;
"/"     return LO_DIV;
"+"     return LO_ADD;
"-"     return LO_SUB;
"~"     return LO_BIT_NOT;
"%"     return LO_MOD;
"<<"    return LO_SFT_L;
">>"    return LO_SFT_R;
"!"     return LO_LGC_NOT;
"||"    return LO_LGC_OR;
"&&"    return LO_LGC_AND;
"^"     return LO_BIT_XOR;
"&"     return LO_BIT_AND;
"|"     return LO_BIT_OR; 
"="     {return RO_ASSIGN;}
","     {return LO_COMMA;}
"<"     return LO_REL_L;
">"     return LO_REL_G;
"<="    return LO_REL_LE;
">="    return LO_REL_GE;    
"."     return LO_MEMBER;
"->"    return LO_PT_MEMBER;
"int"   return T_INT;
"bool"  return T_BOOL;
"char"  return T_CHAR;
"void"  return T_VOID;

"if"        return KW_IF;
"else"      return KW_ELSE;
"for"       return KW_FOR;
"return"    return KW_RET;
"struct"    return KW_STRUCT;
"union"     return KW_UNION;
"while"     return KW_WHILE;
"do"        return KW_DO;
"continue"  return KW_CONTINUE;
"break"     return KW_BREAK;

"unsigned"  return  T_UNSIGNED;
"signed"    return T_SIGNED;
"const"     return  Q_CONST;


";" return  SEMICOLON;
":" return  COLON;

{INTEGER} {
    //cout<<"init int node"<<endl;
    TreeNode* node = new TreeNode(lineno, NODE_CONST);
    node->type = TYPE_INT;
    //if(node->type == TYPE_INT) cout << "ok";
    //cout << "lex TYPE_INT"<< TYPE_INT << endl;
    //cout << "lex node->type"<< node->type << endl;
    node->int_val = atoi(yytext);
    node->sysType = T(INT);
    node->optype = OP_CONST;
    yylval = node;
    return INTEGER;
}

{CHAR} {
    TreeNode* node = new TreeNode(lineno, NODE_CONST);
    node->type = TYPE_CHAR;
    node->int_val = yytext[1];
    node->sysType = T(CCHAR);
    yylval = node;
    return CHAR;
}

{STRING} {
    TreeNode* node = new TreeNode(lineno, NODE_CONST);
    node->type = TYPE_STRING;
    node->str_val = yytext;
    node->str_val = node->str_val.substr(1);
    int len = node->str_val.size();
    node->str_val = node->str_val.substr(0, len-1);
    node->sysType = ArrayOf(node->str_val.size(), T(CCHAR));
    yylval = node;
    return STRING;
}
{IDENTIFIER} {
    TreeNode* node = new TreeNode(lineno, NODE_VAR);
    node->var_name = string(yytext);
    yylval = node;
    //cout << "id parsed," <<node->var_name << node->nodeType<<endl;
    return IDENTIFIER;
}

{WHILTESPACE} /* do nothing */

{EOL} lineno++;

. {
    cerr << "[line "<< lineno <<" ] unknown character:" << yytext << endl;
}
%%