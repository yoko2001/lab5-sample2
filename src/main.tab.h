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
    SCANF = 263,
    PRINTF = 264,
    LO_EQ = 265,
    LO_N_EQ = 266,
    RO_AS_ADDEQ = 267,
    RO_AS_SUBEQ = 268,
    RO_AS_MULEQ = 269,
    RO_AS_DIVEQ = 270,
    RO_AS_SFTL_EQ = 271,
    RO_AS_SFTR_EQ = 272,
    RO_AS_ANDEQ = 273,
    RO_AS_OREQ = 274,
    LO_AS_SELFINC = 275,
    LO_AS_SELFDEC = 276,
    RO_TRI_QUES = 277,
    RO_TRI_COLON = 278,
    LO_MUL = 279,
    LO_DIV = 280,
    LO_ADD = 281,
    LO_SUB = 282,
    LO_BIT_NOT = 283,
    LO_MOD = 284,
    LO_SFT_L = 285,
    LO_LGC_OR = 286,
    LO_LGC_AND = 287,
    LO_SFT_R = 288,
    LO_LGC_NOT = 289,
    LO_BIT_XOR = 290,
    LO_BIT_AND = 291,
    LO_BIT_OR = 292,
    RO_ASSIGN = 293,
    LO_COMMA = 294,
    KW_CONTINUE = 295,
    KW_BREAK = 296,
    KW_IF = 297,
    KW_FOR = 298,
    KW_RET = 299,
    KW_STRUCT = 300,
    KW_WHILE = 301,
    KW_DO = 302,
    KW_ELSE = 303,
    T_SIGNED = 304,
    T_UNSIGNED = 305,
    Q_CONST = 306,
    SEMICOLON = 307,
    COLON = 308,
    LO_REL_L = 309,
    LO_REL_G = 310,
    LO_REL_LE = 311,
    LO_REL_GE = 312,
    KW_UNION = 313,
    IDENTIFIER = 314,
    INTEGER = 315,
    CHAR = 316,
    BOOL = 317,
    STRING = 318,
    LO_MEMBER = 319,
    LO_PT_MEMBER = 320,
    L_BRACKET = 321,
    R_BRACKET = 322,
    L_SQ_BRACKET = 323,
    R_SQ_BRACKET = 324,
    L_BRACE = 325,
    R_BRACE = 326
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
