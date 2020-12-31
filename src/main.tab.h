/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_SRC_MAIN_TAB_H_INCLUDED
# define YY_YY_SRC_MAIN_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    T_CHAR = 258,
    T_INT = 259,
    T_STRING = 260,
    T_BOOL = 261,
    T_VOID = 262,
    LO_EQ = 263,
    LO_N_EQ = 264,
    RO_AS_ADDEQ = 265,
    RO_AS_SUBEQ = 266,
    RO_AS_MULEQ = 267,
    RO_AS_DIVEQ = 268,
    RO_AS_SFTL_EQ = 269,
    RO_AS_SFTR_EQ = 270,
    RO_AS_ANDEQ = 271,
    RO_AS_OREQ = 272,
    LO_AS_SELFINC = 273,
    LO_AS_SELFDEC = 274,
    RO_TRI_QUES = 275,
    RO_TRI_COLON = 276,
    LO_MUL = 277,
    LO_DIV = 278,
    LO_ADD = 279,
    LO_SUB = 280,
    LO_BIT_NOT = 281,
    LO_MOD = 282,
    LO_SFT_L = 283,
    LO_LGC_OR = 284,
    LO_LGC_AND = 285,
    LO_SFT_R = 286,
    LO_LGC_NOT = 287,
    LO_BIT_XOR = 288,
    LO_BIT_AND = 289,
    LO_BIT_OR = 290,
    RO_ASSIGN = 291,
    LO_COMMA = 292,
    KW_CONTINUE = 293,
    KW_BREAK = 294,
    KW_IF = 295,
    KW_FOR = 296,
    KW_RET = 297,
    KW_STRUCT = 298,
    KW_WHILE = 299,
    KW_DO = 300,
    KW_ELSE = 301,
    T_SIGNED = 302,
    T_UNSIGNED = 303,
    Q_CONST = 304,
    SEMICOLON = 305,
    COLON = 306,
    LO_REL_L = 307,
    LO_REL_G = 308,
    LO_REL_LE = 309,
    LO_REL_GE = 310,
    KW_UNION = 311,
    IDENTIFIER = 312,
    INTEGER = 313,
    CHAR = 314,
    BOOL = 315,
    STRING = 316,
    LO_MEMBER = 317,
    LO_PT_MEMBER = 318,
    L_BRACKET = 319,
    R_BRACKET = 320,
    L_SQ_BRACKET = 321,
    R_SQ_BRACKET = 322,
    L_BRACE = 323,
    R_BRACE = 324
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_MAIN_TAB_H_INCLUDED  */
