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
    LO_PT_MEMBER = 262,
    LO_MEMBER = 263,
    L_BRACKET = 264,
    R_BRACKET = 265,
    L_SQ_BRACKET = 266,
    R_SQ_BRACKET = 267,
    L_BRACE = 268,
    R_BRACE = 269,
    LO_EQ = 270,
    LO_N_EQ = 271,
    RO_AS_ADDEQ = 272,
    RO_AS_SUBEQ = 273,
    RO_AS_MULEQ = 274,
    RO_AS_DIVEQ = 275,
    RO_AS_SFTL_EQ = 276,
    RO_AS_SFTR_EQ = 277,
    RO_AS_ANDEQ = 278,
    RO_AS_OREQ = 279,
    LO_AS_SELFINC = 280,
    LO_AS_SELFDEC = 281,
    RO_TRI_QUES = 282,
    RO_TRI_COLON = 283,
    LO_MUL = 284,
    LO_DIV = 285,
    LO_ADD = 286,
    LO_SUB = 287,
    LO_BIT_NOT = 288,
    LO_MOD = 289,
    LO_SFT_L = 290,
    LO_SFT_R = 291,
    LO_LGC_NOT = 292,
    LO_BIT_XOR = 293,
    LO_BIT_AND = 294,
    LO_BIT_OR = 295,
    RO_ASSIGN = 296,
    LO_LGC_OR = 297,
    LO_LGC_AND = 298,
    KW_IF = 299,
    KW_FOR = 300,
    KW_RET = 301,
    KW_STRUCT = 302,
    KW_WHILE = 303,
    KW_DO = 304,
    Q_UNSIGNED = 305,
    Q_CONST = 306,
    SEMICOLON = 307,
    LO_COMMA = 308,
    LO_REL_L = 309,
    LO_REL_G = 310,
    LO_REL_LE = 311,
    LO_REL_GE = 312,
    IDENTIFIER = 313,
    INTEGER = 314,
    CHAR = 315,
    BOOL = 316,
    STRING = 317
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
