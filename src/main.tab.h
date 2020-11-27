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
    LO_EQ = 262,
    LO_N_EQ = 263,
    RO_AS_ADDEQ = 264,
    RO_AS_SUBEQ = 265,
    RO_AS_MULEQ = 266,
    RO_AS_DIVEQ = 267,
    RO_AS_SFTL_EQ = 268,
    RO_AS_SFTR_EQ = 269,
    RO_AS_ANDEQ = 270,
    RO_AS_OREQ = 271,
    LO_AS_SELFINC = 272,
    LO_AS_SELFDEC = 273,
    RO_TRI_QUES = 274,
    RO_TRI_COLON = 275,
    LO_MUL = 276,
    LO_DIV = 277,
    LO_ADD = 278,
    LO_SUB = 279,
    LO_BIT_NOT = 280,
    LO_MOD = 281,
    LO_SFT_L = 282,
    LO_LGC_OR = 283,
    LO_LGC_AND = 284,
    LO_SFT_R = 285,
    LO_LGC_NOT = 286,
    LO_BIT_XOR = 287,
    LO_BIT_AND = 288,
    LO_BIT_OR = 289,
    RO_ASSIGN = 290,
    LO_COMMA = 291,
    KW_CONTINUE = 292,
    KW_BREAK = 293,
    KW_IF = 294,
    KW_FOR = 295,
    KW_RET = 296,
    KW_STRUCT = 297,
    KW_WHILE = 298,
    KW_DO = 299,
    KW_ELSE = 300,
    T_SIGNED = 301,
    T_UNSIGNED = 302,
    Q_CONST = 303,
    SEMICOLON = 304,
    COLON = 305,
    LO_REL_L = 306,
    LO_REL_G = 307,
    LO_REL_LE = 308,
    LO_REL_GE = 309,
    KW_UNION = 310,
    IDENTIFIER = 311,
    INTEGER = 312,
    CHAR = 313,
    BOOL = 314,
    STRING = 315,
    LO_MEMBER = 316,
    LO_PT_MEMBER = 317,
    L_BRACKET = 318,
    R_BRACKET = 319,
    L_SQ_BRACKET = 320,
    R_SQ_BRACKET = 321,
    L_BRACE = 322,
    R_BRACE = 323
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
