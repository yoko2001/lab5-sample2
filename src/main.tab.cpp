/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "src/main.y" /* yacc.c:339  */

    #include "common.h"
    #include "tree.h"
    #define YYSTYPE TreeNode *  
    TreeNode* root;
    extern int lineno;
    int yylex();
    int yyerror( char const * );
    

#line 77 "src/main.tab.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "main.tab.h".  */
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

/* Copy the second part of user declarations.  */

#line 197 "src/main.tab.cpp" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  18
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   516

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  69
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  53
/* YYNRULES -- Number of rules.  */
#define YYNRULES  146
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  240

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   323

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    36,    36,    40,    46,    51,    59,    73,    74,    75,
      76,    77,    78,    79,    83,    87,    91,    95,   103,   109,
     115,   122,   134,   141,   152,   153,   158,   163,   170,   173,
     180,   183,   189,   196,   205,   208,   212,   215,   223,   226,
     233,   240,   251,   258,   266,   269,   278,   283,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   303,   306,   317,
     320,   331,   334,   344,   347,   357,   360,   370,   373,   383,
     386,   396,   399,   406,   416,   419,   426,   433,   440,   450,
     453,   460,   470,   473,   480,   490,   493,   500,   507,   517,
     520,   530,   531,   532,   533,   534,   535,   539,   542,   548,
     554,   565,   568,   575,   582,   589,   595,   601,   612,   618,
     626,   630,   633,   639,   657,   658,   659,   660,   661,   662,
     666,   669,   672,   677,   677,   680,   683,   689,   694,   695,
     696,   697,   701,   702,   706,   707,   711,   712,   716,   719,
     727,   737,   742,   749,   759,   760,   769
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_CHAR", "T_INT", "T_STRING", "T_BOOL",
  "LO_EQ", "LO_N_EQ", "RO_AS_ADDEQ", "RO_AS_SUBEQ", "RO_AS_MULEQ",
  "RO_AS_DIVEQ", "RO_AS_SFTL_EQ", "RO_AS_SFTR_EQ", "RO_AS_ANDEQ",
  "RO_AS_OREQ", "LO_AS_SELFINC", "LO_AS_SELFDEC", "RO_TRI_QUES",
  "RO_TRI_COLON", "LO_MUL", "LO_DIV", "LO_ADD", "LO_SUB", "LO_BIT_NOT",
  "LO_MOD", "LO_SFT_L", "LO_LGC_OR", "LO_LGC_AND", "LO_SFT_R",
  "LO_LGC_NOT", "LO_BIT_XOR", "LO_BIT_AND", "LO_BIT_OR", "RO_ASSIGN",
  "LO_COMMA", "KW_CONTINUE", "KW_BREAK", "KW_IF", "KW_FOR", "KW_RET",
  "KW_STRUCT", "KW_WHILE", "KW_DO", "KW_ELSE", "T_SIGNED", "T_UNSIGNED",
  "Q_CONST", "SEMICOLON", "COLON", "LO_REL_L", "LO_REL_G", "LO_REL_LE",
  "LO_REL_GE", "KW_UNION", "IDENTIFIER", "INTEGER", "CHAR", "BOOL",
  "STRING", "LO_MEMBER", "LO_PT_MEMBER", "L_BRACKET", "R_BRACKET",
  "L_SQ_BRACKET", "R_SQ_BRACKET", "L_BRACE", "R_BRACE", "$accept",
  "translation-unit", "external-declaration", "function-definition",
  "statement", "jump-statement", "iteration-statement",
  "selection-statement", "expression-statement", "compound-statement",
  "block-item-list", "block-item", "declaration", "declaration-specifiers",
  "init-declarator-list", "init-declarator", "initializer",
  "initializer-list", "expression", "assignment-operator",
  "assignment-expression", "conditional-expression",
  "logical-OR-expression", "logical-AND-expression",
  "inclusive-OR-expression", "exclusive-OR-expression", "AND-expression",
  "equality-expression", "relational-expression", "shift-expression",
  "additive-expression", "multiplicative-expression", "cast-expression",
  "unary-operator", "unary-expression", "postfix-expression",
  "argument-expression-list", "primary-expression", "constant",
  "type-specifier", "struct-or-union-specifier", "struct-or-union",
  "struct-declaration-list", "struct-declaration",
  "specifier-qualifier-list", "struct-declarator-list",
  "struct-declarator", "declarator", "direct-declarator",
  "parameter-type-list", "parameter-declaration", "pointer",
  "type-qualifier", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323
};
# endif

#define YYPACT_NINF -80

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-80)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     344,   -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,   333,
     -80,   -80,   -80,    -8,   344,   -80,    63,   344,   -80,   -80,
      18,   -80,    -3,   -80,   -15,    77,   -12,   -80,    25,   344,
     -80,   -80,    -8,   -80,   377,   156,   -80,   344,   442,    77,
     344,   344,    61,   -80,    -8,   344,   -80,   -25,   453,   453,
     -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,   307,   377,
     -80,   -80,   -80,    13,    71,    20,    86,    91,   149,    96,
     107,   140,   100,   -80,   442,   478,    -2,   -80,   -80,    87,
      92,    81,    95,   394,    98,   260,   -80,   -80,   -80,   -80,
     -80,   -80,   -80,   -80,   204,   -80,   -80,    -8,     7,   -80,
      -8,   -19,   -80,   110,   227,   -80,   -80,   -80,    68,   -80,
     134,   -80,   442,   -80,   -80,   -13,   122,   -80,   -10,   442,
     442,   442,   442,   442,   442,   442,   442,   442,   442,   442,
     442,   442,   442,   442,   442,   442,   442,   442,   -80,   -80,
     -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,   442,
     -80,   -80,   132,   135,   442,   442,   -80,   -80,   442,   405,
     -80,   141,   442,   158,   -80,   -80,   -80,   442,   -80,   -80,
     344,   -80,   -80,   -80,    -8,   -80,   152,   -80,   442,   377,
     -80,    30,    71,    20,    86,    91,   149,    96,    96,   107,
     107,   107,   107,   140,   140,   100,   100,   -80,   -80,   -80,
     -80,   -80,   -80,   -80,    32,    -9,    33,   143,    76,   -80,
      59,   151,   -80,   -80,   -80,   -80,   -80,   -80,   442,   442,
     -80,   -80,   260,   142,   442,   260,   442,   -80,   -80,   170,
     -80,    78,   -80,    74,   260,   442,   -80,   -80,    75,   -80
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   115,   114,   116,   123,   117,   118,   146,   124,     0,
       2,     4,     5,    33,    34,   119,     0,    36,     1,     3,
     144,   138,     0,    38,    40,   137,     0,    35,   122,     0,
      37,   145,     0,    32,     0,     0,     6,     0,     0,   136,
       0,   128,     0,   125,     0,   130,    39,    40,     0,     0,
      92,    93,    94,    95,    96,    91,   110,   113,     0,     0,
      41,    42,    57,    59,    61,    63,    65,    67,    69,    71,
      74,    79,    82,    85,     0,    89,    97,   101,   111,     0,
       0,     0,     0,     0,     0,     0,     7,    27,    31,    13,
      12,    11,    10,     9,     0,    28,     8,    33,     0,    46,
       0,     0,   141,     0,     0,   129,   121,   126,     0,   132,
     134,   131,     0,    98,    99,     0,     0,    44,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   100,    89,
      49,    56,    52,    51,    54,    55,    50,    53,    48,     0,
     105,   106,     0,     0,     0,     0,    15,    14,     0,     0,
      16,     0,     0,     0,     8,    26,    29,     0,    25,   143,
       0,   140,   139,   120,     0,   127,     0,   112,     0,     0,
      43,     0,    62,    64,    66,    68,    70,    72,    73,    75,
      76,    77,    78,    80,    81,    83,    84,    86,    87,    88,
      58,   103,   104,   108,     0,     0,     0,     0,     0,    17,
       0,     0,    47,   142,   133,   135,    90,    45,     0,     0,
     107,   102,     0,     0,     0,     0,     0,    60,   109,    22,
      20,     0,    18,     0,     0,     0,    19,    23,     0,    21
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -80,   -80,   207,   -80,   -79,   -80,   -80,   -80,   -80,   193,
     -80,   124,    12,     5,   -80,   188,   -51,   -80,   -57,   -80,
     -34,     8,   -80,   112,   113,   114,   115,   116,    40,    24,
      39,    49,   -65,   -80,   -46,   -80,   -80,   -80,   -80,    -5,
     -80,   -80,   199,   -31,    90,   -80,    80,    -6,   223,   -80,
      85,   236,   -11
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     9,    10,    11,    88,    89,    90,    91,    92,    93,
      94,    95,   164,    97,    22,    23,    60,   118,    98,   149,
      99,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,   204,    77,    78,    14,
      15,    16,    42,    43,    44,   108,   109,    47,    25,   101,
     102,    26,    17
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      61,   115,   113,   114,   103,    13,   163,    24,   117,   138,
      34,   107,    12,    20,    13,   150,   151,   170,    45,    27,
      34,    12,    30,   167,    41,    61,   179,   167,   139,    45,
      45,    45,   119,    32,    45,    41,    41,    41,   110,    20,
      41,   120,   100,   167,    21,   171,    33,    96,    21,   161,
     218,   177,    35,   116,   122,   115,   168,   221,   180,   152,
     153,   154,   181,   155,     1,     2,   167,     3,   219,   167,
     197,   198,   199,   107,   139,   139,   139,   139,   139,   139,
     139,   139,   139,   139,   139,   139,   139,   139,   139,   139,
     139,   139,    40,    45,   169,   167,   220,   222,   205,    41,
     121,   206,   208,     4,   174,   210,    96,     5,     6,     7,
     167,   167,   167,   216,   167,   200,     8,   175,   123,    28,
     203,   135,   136,   225,   124,   224,   137,   235,   217,   106,
      29,   105,   139,   212,   131,   111,   156,   132,   236,   239,
      37,   157,    38,   229,   158,    61,   232,   127,   128,   129,
     130,   189,   190,   191,   192,   237,   125,   126,   159,     1,
       2,   162,     3,   133,   134,   187,   188,   231,   110,   233,
     193,   194,   139,    48,    49,   100,   172,    50,   238,    51,
      52,    53,   195,   196,   176,   228,   178,    54,   201,    55,
     209,   202,   223,    79,    80,    81,    82,    83,     4,    84,
      85,   211,     5,     6,     7,    86,   230,     1,     2,   215,
       3,     8,    56,    57,   226,   234,    19,    36,   166,    58,
      46,    48,    49,    35,    87,    50,   227,    51,    52,    53,
       1,     2,   182,     3,   183,    54,   184,    55,   185,   104,
     186,    79,    80,    81,    82,    83,     4,    84,    85,    39,
       5,     6,     7,    86,   214,   213,    31,     0,     0,     8,
      56,    57,     0,     1,     2,     0,     3,    58,     0,     4,
       0,    35,   165,     5,     6,     7,     0,    48,    49,     0,
       0,    50,     8,    51,    52,    53,     0,     0,     0,     0,
       0,    54,     0,    55,     0,   173,     0,    79,    80,    81,
      82,    83,     4,    84,    85,     0,     5,     6,     7,    86,
       1,     2,     0,     3,     0,     8,    56,    57,     0,     0,
       0,     0,     0,    58,    48,    49,     0,    35,    50,     0,
      51,    52,    53,    18,     0,     0,     1,     2,    54,     3,
      55,     0,     0,     0,     0,     0,     0,     1,     2,     4,
       3,     0,     0,     5,     6,     0,     0,     0,     0,     0,
       0,     0,     8,    56,    57,     0,     0,     0,     0,     0,
      58,     0,     0,     0,     0,     4,     0,     0,     0,     5,
       6,     7,     0,     0,     0,     0,     4,     0,     8,     0,
       5,     6,     7,     0,    48,    49,     0,     0,    50,     8,
      51,    52,    53,     0,     0,     0,     0,     0,    54,     0,
      55,    48,    49,     0,     0,    50,     0,    51,    52,    53,
       0,     0,    48,    49,     0,    54,    50,    55,    51,    52,
      53,     0,     0,    56,    57,     0,    54,     0,    55,     0,
      58,     0,     0,   160,    59,     0,     0,     0,     0,     0,
      56,    57,     0,     0,   207,     0,     0,    58,     0,    48,
      49,    56,    57,    50,     0,    51,    52,    53,    58,     0,
      48,    49,     0,    54,    50,    55,    51,    52,    53,     0,
       0,     0,     0,     0,    54,     0,    55,   140,   141,   142,
     143,   144,   145,   146,   147,     0,     0,     0,    56,    57,
       0,     0,     0,     0,     0,    58,     0,     0,     0,    56,
      57,     0,     0,   148,     0,     0,   112
};

static const yytype_int16 yycheck[] =
{
      34,    58,    48,    49,    38,     0,    85,    13,    59,    74,
      35,    42,     0,    21,     9,    17,    18,    36,    29,    14,
      35,     9,    17,    36,    29,    59,    36,    36,    74,    40,
      41,    42,    19,    36,    45,    40,    41,    42,    44,    21,
      45,    28,    37,    36,    56,    64,    49,    35,    56,    83,
      20,    64,    67,    58,    34,   112,    49,    66,    68,    61,
      62,    63,   119,    65,     3,     4,    36,     6,    36,    36,
     135,   136,   137,   104,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,    67,   104,   100,    36,    64,    64,   155,   104,
      29,   158,   159,    42,    36,   162,    94,    46,    47,    48,
      36,    36,    36,   178,    36,   149,    55,    49,    32,    56,
     154,    21,    22,    64,    33,    49,    26,    49,   179,    68,
      67,    41,   178,   167,    27,    45,    49,    30,    64,    64,
      63,    49,    65,   222,    63,   179,   225,    51,    52,    53,
      54,   127,   128,   129,   130,   234,     7,     8,    63,     3,
       4,    63,     6,    23,    24,   125,   126,   224,   174,   226,
     131,   132,   218,    17,    18,   170,    66,    21,   235,    23,
      24,    25,   133,   134,    50,   219,    64,    31,    56,    33,
      49,    56,    49,    37,    38,    39,    40,    41,    42,    43,
      44,    43,    46,    47,    48,    49,    64,     3,     4,    57,
       6,    55,    56,    57,    63,    45,     9,    24,    94,    63,
      32,    17,    18,    67,    68,    21,   218,    23,    24,    25,
       3,     4,   120,     6,   121,    31,   122,    33,   123,    40,
     124,    37,    38,    39,    40,    41,    42,    43,    44,    26,
      46,    47,    48,    49,   174,   170,    20,    -1,    -1,    55,
      56,    57,    -1,     3,     4,    -1,     6,    63,    -1,    42,
      -1,    67,    68,    46,    47,    48,    -1,    17,    18,    -1,
      -1,    21,    55,    23,    24,    25,    -1,    -1,    -1,    -1,
      -1,    31,    -1,    33,    -1,    68,    -1,    37,    38,    39,
      40,    41,    42,    43,    44,    -1,    46,    47,    48,    49,
       3,     4,    -1,     6,    -1,    55,    56,    57,    -1,    -1,
      -1,    -1,    -1,    63,    17,    18,    -1,    67,    21,    -1,
      23,    24,    25,     0,    -1,    -1,     3,     4,    31,     6,
      33,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,    42,
       6,    -1,    -1,    46,    47,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    56,    57,    -1,    -1,    -1,    -1,    -1,
      63,    -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,    46,
      47,    48,    -1,    -1,    -1,    -1,    42,    -1,    55,    -1,
      46,    47,    48,    -1,    17,    18,    -1,    -1,    21,    55,
      23,    24,    25,    -1,    -1,    -1,    -1,    -1,    31,    -1,
      33,    17,    18,    -1,    -1,    21,    -1,    23,    24,    25,
      -1,    -1,    17,    18,    -1,    31,    21,    33,    23,    24,
      25,    -1,    -1,    56,    57,    -1,    31,    -1,    33,    -1,
      63,    -1,    -1,    49,    67,    -1,    -1,    -1,    -1,    -1,
      56,    57,    -1,    -1,    49,    -1,    -1,    63,    -1,    17,
      18,    56,    57,    21,    -1,    23,    24,    25,    63,    -1,
      17,    18,    -1,    31,    21,    33,    23,    24,    25,    -1,
      -1,    -1,    -1,    -1,    31,    -1,    33,     9,    10,    11,
      12,    13,    14,    15,    16,    -1,    -1,    -1,    56,    57,
      -1,    -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,    56,
      57,    -1,    -1,    35,    -1,    -1,    63
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     6,    42,    46,    47,    48,    55,    70,
      71,    72,    81,    82,   108,   109,   110,   121,     0,    71,
      21,    56,    83,    84,   116,   117,   120,    82,    56,    67,
      82,   120,    36,    49,    35,    67,    78,    63,    65,   117,
      67,   108,   111,   112,   113,   121,    84,   116,    17,    18,
      21,    23,    24,    25,    31,    33,    56,    57,    63,    67,
      85,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   106,   107,    37,
      38,    39,    40,    41,    43,    44,    49,    68,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    87,    89,
      82,   118,   119,    89,   111,   113,    68,   112,   114,   115,
     116,   113,    63,   103,   103,    87,   108,    85,    86,    19,
      28,    29,    34,    32,    33,     7,     8,    51,    52,    53,
      54,    27,    30,    23,    24,    21,    22,    26,   101,   103,
       9,    10,    11,    12,    13,    14,    15,    16,    35,    88,
      17,    18,    61,    62,    63,    65,    49,    49,    63,    63,
      49,    89,    63,    73,    81,    68,    80,    36,    49,   116,
      36,    64,    66,    68,    36,    49,    50,    64,    64,    36,
      68,    87,    92,    93,    94,    95,    96,    97,    97,    98,
      98,    98,    98,    99,    99,   100,   100,   101,   101,   101,
      89,    56,    56,    89,   105,    87,    87,    49,    87,    49,
      87,    43,    89,   119,   115,    57,   101,    85,    20,    36,
      64,    66,    64,    49,    49,    64,    63,    90,    89,    73,
      64,    87,    73,    87,    45,    49,    64,    73,    87,    64
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    69,    70,    70,    71,    71,    72,    73,    73,    73,
      73,    73,    73,    73,    74,    74,    74,    74,    75,    75,
      75,    75,    76,    76,    77,    77,    78,    78,    79,    79,
      80,    80,    81,    81,    82,    82,    82,    82,    83,    83,
      84,    84,    85,    85,    86,    86,    87,    87,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    89,    89,    90,
      90,    91,    91,    92,    92,    93,    93,    94,    94,    95,
      95,    96,    96,    96,    97,    97,    97,    97,    97,    98,
      98,    98,    99,    99,    99,   100,   100,   100,   100,   101,
     101,   102,   102,   102,   102,   102,   102,   103,   103,   103,
     103,   104,   104,   104,   104,   104,   104,   104,   105,   105,
     106,   106,   106,   107,   108,   108,   108,   108,   108,   108,
     109,   109,   109,   110,   110,   111,   111,   112,   113,   113,
     113,   113,   114,   114,   115,   115,   116,   116,   117,   117,
     117,   118,   118,   119,   120,   120,   121
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     2,     3,     5,     6,
       5,     8,     5,     7,     1,     2,     3,     2,     1,     2,
       1,     1,     3,     1,     1,     2,     1,     2,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       5,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     3,     1,     3,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     1,     3,     3,     3,     1,
       4,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       2,     1,     4,     3,     3,     2,     2,     4,     1,     3,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       5,     4,     2,     1,     1,     1,     2,     3,     1,     2,
       1,     2,     1,     3,     1,     3,     2,     1,     1,     4,
       4,     1,     3,     2,     1,     2,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 36 "src/main.y" /* yacc.c:1646  */
    {
    root = new TreeNode(0, NODE_PROG);
    root->addChild((yyvsp[0]));
}
#line 1531 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 40 "src/main.y" /* yacc.c:1646  */
    {
    root->addChild((yyvsp[0]));
}
#line 1539 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 46 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode(lineno, NODE_EXTERN_DECL);
    node->addChild((yyvsp[0]));
    (yyval) = node;
}
#line 1549 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 51 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode(lineno, NODE_EXTERN_DECL);
    node->addChild((yyvsp[0]));
    (yyval) = node;
}
#line 1559 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 59 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode(lineno, NODE_EXTERN_FUNC_DECL);
    node->addChild((yyvsp[-2]));
    node->addChild((yyvsp[-1]));
    node->addChild((yyvsp[0]));
    (yyval) = node;
}
#line 1571 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 73 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_STMT); (yyval)->stype = STMT_SKIP;}
#line 1577 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 74 "src/main.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1583 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 75 "src/main.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1589 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 76 "src/main.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1595 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 77 "src/main.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1601 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 78 "src/main.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1607 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 79 "src/main.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1613 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 83 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode(lineno, NODE_BREAK);
    (yyval) = node;
}
#line 1622 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 87 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode(lineno, NODE_CONTINUE);
    (yyval) = node; 
}
#line 1631 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 91 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode(lineno, NODE_RET);
    (yyval) = node;
}
#line 1640 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 95 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode(lineno, NODE_RET);
    (yyval) = node;
    (yyval)->addChild((yyvsp[-1]));
}
#line 1650 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 103 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode(lineno, NODE_WHILE);
    node->addChild((yyvsp[-2]));
    node->addChild((yyvsp[0]));
    (yyval) = node;
}
#line 1661 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 109 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode(lineno, NODE_DO_WHILE);
    node->addChild((yyvsp[-1]));
    node->addChild((yyvsp[-4]));
    (yyval) = node;
}
#line 1672 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 115 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode(lineno, NODE_FOR);
    node->addChild(null_node);
    node->addChild(null_node);
    node->addChild(null_node);
    (yyval) = node;
}
#line 1684 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 122 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode(lineno, NODE_FOR);
    node->addChild((yyvsp[-5]));
    node->addChild((yyvsp[-3]));
    node->addChild((yyvsp[-1]));
    (yyval) = node;
}
#line 1696 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 134 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode(lineno, NODE_STMT);
    node->stype = STMT_SELECT;
    node->addChild((yyvsp[-2]));
    node->addChild((yyvsp[0]));
    (yyval) = node;
}
#line 1708 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 141 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode(lineno, NODE_STMT);
    node->stype = STMT_SELECT;
    node->addChild((yyvsp[-4]));
    node->addChild((yyvsp[-2]));
    node->addChild((yyvsp[0]));
    (yyval) = node;
}
#line 1721 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 152 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_STMT); (yyval)->stype = STMT_SKIP;}
#line 1727 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 153 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[-1]);
}
#line 1735 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 158 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = new TreeNode(lineno, NODE_STMT); 
    (yyval)->stype = STMT_COMPOUND;
    (yyval)->addChild((yyvsp[-1]));
}
#line 1745 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 163 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = new TreeNode(lineno, NODE_STMT); 
    (yyval)->stype = STMT_COMPOUND;
}
#line 1754 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 170 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
}
#line 1762 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 173 "src/main.y" /* yacc.c:1646  */
    {
    (yyvsp[-1])->addSibling((yyvsp[0]));
    (yyval) = (yyvsp[-1]);
}
#line 1771 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 180 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
}
#line 1779 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 183 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
}
#line 1787 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 189 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode(lineno, NODE_STMT);
    node->stype = STMT_DECL;
    node->addChild((yyvsp[-2]));
    node->addChild((yyvsp[-1]));
    (yyval) = node;
}
#line 1799 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 196 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode(lineno, NODE_STMT);
    node->stype = STMT_DECL;
    node->addChild((yyvsp[0]));
    (yyval) = node;
}
#line 1810 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 205 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
}
#line 1818 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 208 "src/main.y" /* yacc.c:1646  */
    {
    (yyvsp[-1]) -> addSibling((yyvsp[0]));
    (yyval) = (yyvsp[-1]);
}
#line 1827 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 212 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
}
#line 1835 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 215 "src/main.y" /* yacc.c:1646  */
    {
    (yyvsp[-1])->addSibling((yyvsp[0]));
    (yyval) = (yyvsp[-1]);
}
#line 1844 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 223 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
}
#line 1852 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 226 "src/main.y" /* yacc.c:1646  */
    {
    (yyvsp[-2])->addSibling((yyvsp[-1]));
    (yyval) = (yyvsp[-2]);
}
#line 1861 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 233 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* fnode = new TreeNode(lineno, NODE_DECL);
    TreeNode* node = new TreeNode(lineno, NODE_DECL_VARS);
    node->addChild((yyvsp[0]));
    fnode->addChild(node);
    (yyval) = fnode;
}
#line 1873 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 240 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* fnode = new TreeNode(lineno, NODE_DECL);
    TreeNode* node = new TreeNode(lineno, NODE_INIT_DECL_VARS);
    node->addChild((yyvsp[-2]));
    node->addChild((yyvsp[0]));
    fnode->addChild(node);
    (yyval) = fnode;
}
#line 1886 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 251 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode(lineno, NODE_DECL_INIT);
    node->addChild((yyvsp[0]));
    //cout << "ckpt1\n";
    (yyval) = node;
    //cout << "ckpt2\n";
}
#line 1898 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 258 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode(lineno, NODE_DECL_INIT);
    node->addChild((yyvsp[-1]));
    (yyval) = node;
}
#line 1908 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 266 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
}
#line 1916 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 269 "src/main.y" /* yacc.c:1646  */
    {
    (yyvsp[-2])->addSibling((yyvsp[0]));
    (yyval) = (yyvsp[-2]);
}
#line 1925 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 278 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode(lineno, NODE_EXPR);
    node->addChild((yyvsp[0]));
    (yyval) = node;
}
#line 1935 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 283 "src/main.y" /* yacc.c:1646  */
    {
    //TreeNode* node = new TreeNode(lineno, NODE_EXPR);
    
    (yyvsp[-2])->addSibling((yyvsp[-1]));
    (yyval) = (yyvsp[-2]);
}
#line 1946 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 291 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_OP); (yyval)->optype = OP_ASSIGN;}
#line 1952 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 292 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_OP); (yyval)->optype = OP_AS_ADDEQ;}
#line 1958 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 293 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_OP); (yyval)->optype = OP_AS_ANDEQ;}
#line 1964 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 294 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_OP); (yyval)->optype = OP_AS_DIVEQ;}
#line 1970 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 295 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_OP); (yyval)->optype = OP_AS_MULEQ;}
#line 1976 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 296 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_OP); (yyval)->optype = OP_AS_OREQ;}
#line 1982 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 297 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_OP); (yyval)->optype = OP_AS_SFTL_EQ;}
#line 1988 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 298 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_OP); (yyval)->optype = OP_AS_SFTR_EQ;}
#line 1994 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 299 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_OP); (yyval)->optype = OP_AS_SUB_EQ;}
#line 2000 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 303 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
}
#line 2008 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 306 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-2])->lineno, NODE_EXPR);
    node-> optype = (yyvsp[-1])->optype;
    node-> addChild((yyvsp[-2]));
    node-> addChild((yyvsp[-1]));
    node-> addChild((yyvsp[0]));
    (yyval) = node;
}
#line 2021 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 317 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
}
#line 2029 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 320 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-4])->lineno, NODE_EXPR);
    node -> optype = OP_CONDITION;
    node -> addChild((yyvsp[-4]));
    node -> addChild((yyvsp[-2]));
    node -> addChild((yyvsp[0]));
    (yyval) = node;
}
#line 2042 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 331 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
}
#line 2050 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 334 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-2])->lineno, NODE_EXPR);
    node -> optype = OP_LGC_OR;
    node -> addChild((yyvsp[-2]));
    node -> addChild((yyvsp[0]));
    (yyval) = node;
}
#line 2062 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 344 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
}
#line 2070 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 347 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-2])->lineno, NODE_EXPR);
    node -> optype = OP_LGC_AND;
    node -> addChild((yyvsp[-2]));
    node -> addChild((yyvsp[0]));
    (yyval) = node;
}
#line 2082 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 357 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
}
#line 2090 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 360 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-2])->lineno, NODE_EXPR);
    node -> optype = OP_BIT_OR;
    node -> addChild((yyvsp[-2]));
    node -> addChild((yyvsp[0]));
    (yyval) = node;
}
#line 2102 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 370 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
}
#line 2110 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 373 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-2])->lineno, NODE_EXPR);
    node -> optype = OP_BIT_XOR;
    node -> addChild((yyvsp[-2]));
    node -> addChild((yyvsp[0]));
    (yyval) = node;
}
#line 2122 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 383 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
}
#line 2130 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 386 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-2])->lineno, NODE_EXPR);
    node -> optype = OP_BIT_AND;
    node -> addChild((yyvsp[-2]));
    node -> addChild((yyvsp[0]));
    (yyval) = node;
}
#line 2142 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 396 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
}
#line 2150 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 399 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-2])->lineno, NODE_EXPR);
    node -> optype = OP_EQ;
    node -> addChild((yyvsp[-2]));
    node -> addChild((yyvsp[0]));
    (yyval) = node;
}
#line 2162 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 406 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-2])->lineno, NODE_EXPR);
    node -> optype = OP_N_EQ;
    node -> addChild((yyvsp[-2]));
    node -> addChild((yyvsp[0]));
    (yyval) = node;
}
#line 2174 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 416 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
}
#line 2182 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 419 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-2])->lineno, NODE_EXPR);
    node -> optype = OP_REL_L;
    node -> addChild((yyvsp[-2]));
    node -> addChild((yyvsp[0]));
    (yyval) = node;
}
#line 2194 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 426 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-2])->lineno, NODE_EXPR);
    node -> optype = OP_REL_G;
    node -> addChild((yyvsp[-2]));
    node -> addChild((yyvsp[0]));
    (yyval) = node;
}
#line 2206 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 433 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-2])->lineno, NODE_EXPR);
    node -> optype = OP_REL_LE;
    node -> addChild((yyvsp[-2]));
    node -> addChild((yyvsp[0]));
    (yyval) = node;
}
#line 2218 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 440 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-2])->lineno, NODE_EXPR);
    node -> optype = OP_REL_GE;
    node -> addChild((yyvsp[-2]));
    node -> addChild((yyvsp[0]));
    (yyval) = node;
}
#line 2230 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 450 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
}
#line 2238 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 453 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-2])->lineno, NODE_EXPR);
    node -> optype = OP_SFT_L;
    node -> addChild((yyvsp[-2]));
    node -> addChild((yyvsp[0]));
    (yyval) = node;
}
#line 2250 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 460 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-2])->lineno, NODE_EXPR);
    node -> optype = OP_SFT_R;
    node -> addChild((yyvsp[-2]));
    node -> addChild((yyvsp[0]));
    (yyval) = node;
}
#line 2262 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 470 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
}
#line 2270 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 473 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-2])->lineno, NODE_EXPR);
    node -> optype = OP_ADD;
    node -> addChild((yyvsp[-2]));
    node -> addChild((yyvsp[0]));
    (yyval) = node;
}
#line 2282 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 480 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-2])->lineno, NODE_EXPR);
    node -> optype = OP_SUB;
    node -> addChild((yyvsp[-2]));
    node -> addChild((yyvsp[0]));
    (yyval) = node;
}
#line 2294 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 490 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
}
#line 2302 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 493 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-2])->lineno, NODE_EXPR);
    node -> optype = OP_MUL;
    node -> addChild((yyvsp[-2]));
    node -> addChild((yyvsp[0]));
    (yyval) = node;
}
#line 2314 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 500 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-2])->lineno, NODE_EXPR);
    node -> optype = OP_DIV;
    node -> addChild((yyvsp[-2]));
    node -> addChild((yyvsp[0]));
    (yyval) = node;
}
#line 2326 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 507 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-2])->lineno, NODE_EXPR);
    node -> optype = OP_MOD;
    node -> addChild((yyvsp[-2]));
    node -> addChild((yyvsp[0]));
    (yyval) = node;
}
#line 2338 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 517 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
}
#line 2346 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 520 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-3])->lineno, NODE_EXPR);
    node -> optype = OP_CAST;
    node -> addChild((yyvsp[-2]));
    node -> addChild((yyvsp[-1]));
    (yyval) = node;
}
#line 2358 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 530 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_OP); (yyval)->optype = OP_UNA_REF;}
#line 2364 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 531 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_OP); (yyval)->optype = OP_UNA_DEREF;}
#line 2370 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 532 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_OP); (yyval)->optype = OP_POSITIVE;}
#line 2376 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 533 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_OP); (yyval)->optype = OP_MINUS;}
#line 2382 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 534 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_OP); (yyval)->optype = OP_BIT_NOT;}
#line 2388 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 535 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_OP); (yyval)->optype = OP_LGC_NOT;}
#line 2394 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 539 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
}
#line 2402 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 542 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-1])->lineno, NODE_EXPR);
    node -> optype = OP_PRESELFINC;
    node -> addChild((yyvsp[0]));
    (yyval) = node;
}
#line 2413 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 548 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-1])->lineno, NODE_EXPR);
    node -> optype = OP_PRESELFDEC;
    node -> addChild((yyvsp[0]));
    (yyval) = node;
}
#line 2424 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 554 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-1])->lineno, NODE_EXPR);
    node -> optype = (yyvsp[-1])->optype;
    node -> addChild((yyvsp[-1]));
    node -> addChild((yyvsp[0]));
    (yyval) = node;
}
#line 2436 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 565 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
}
#line 2444 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 568 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-3])->lineno, NODE_EXPR);
    node -> optype = OP_OFFSET_ACCESS;
    node -> addChild((yyvsp[-3]));
    node -> addChild((yyvsp[-1]));
    (yyval) = node;
}
#line 2456 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 575 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-2])->lineno, NODE_EXPR);
    node -> optype = OP_AC_MEMBER;
    node -> addChild((yyvsp[-2]));
    node -> addChild((yyvsp[0]));
    (yyval) = node;
}
#line 2468 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 582 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-2])->lineno, NODE_EXPR);
    node -> optype = OP_PTAC_MEMBER;
    node -> addChild((yyvsp[-2]));
    node -> addChild((yyvsp[0]));
    (yyval) = node;
}
#line 2480 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 589 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-1])->lineno, NODE_EXPR);
    node -> optype = OP_POSTSELFINC;
    node -> addChild((yyvsp[-1]));
    (yyval) = node;
}
#line 2491 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 595 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-1])->lineno, NODE_EXPR);
    node -> optype = OP_POSTSELFDEC;
    node -> addChild((yyvsp[-1]));
    (yyval) = node;
}
#line 2502 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 601 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode(lineno, NODE_EXPR);
    cout << "postfix func\n";
    node->optype = OP_FUNC_CALL;
    node->addChild((yyvsp[-3]));
    node->addChild((yyvsp[-1]));
    (yyval) = node;
}
#line 2515 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 612 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode(lineno, NODE_ARGUMENT_LIST);
    node->addChild((yyvsp[0]));
    //cout << "ae\n";
    (yyval) = node;
}
#line 2526 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 618 "src/main.y" /* yacc.c:1646  */
    {
    //cout << "aes\n";
    (yyvsp[-2])->addChild((yyvsp[0]));
    (yyval) = (yyvsp[-2]);
}
#line 2536 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 626 "src/main.y" /* yacc.c:1646  */
    {
    //cout << "id\n";
    (yyval) = (yyvsp[0]);
}
#line 2545 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 630 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
}
#line 2553 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 633 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[-1]);
}
#line 2561 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 639 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
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
#line 2581 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 657 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_TYPE); (yyval)->type = TYPE_INT; }
#line 2587 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 658 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_TYPE); (yyval)->type = TYPE_CHAR;}
#line 2593 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 659 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_TYPE); (yyval)->type = TYPE_BOOL;}
#line 2599 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 660 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_TYPE); (yyval)->type = TYPE_SIGNED;}
#line 2605 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 661 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_TYPE); (yyval)->type = TYPE_UNSIGNED;}
#line 2611 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 662 "src/main.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 2617 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 666 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = NULL;
}
#line 2625 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 121:
#line 669 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = NULL;
}
#line 2633 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 122:
#line 672 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = NULL;
}
#line 2641 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 123:
#line 677 "src/main.y" /* yacc.c:1646  */
    {}
#line 2647 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 124:
#line 677 "src/main.y" /* yacc.c:1646  */
    {}
#line 2653 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 125:
#line 680 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = NULL;
}
#line 2661 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 126:
#line 683 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = NULL;
}
#line 2669 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 127:
#line 689 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = NULL;
    }
#line 2677 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 128:
#line 694 "src/main.y" /* yacc.c:1646  */
    {}
#line 2683 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 129:
#line 695 "src/main.y" /* yacc.c:1646  */
    {}
#line 2689 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 130:
#line 696 "src/main.y" /* yacc.c:1646  */
    {}
#line 2695 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 131:
#line 697 "src/main.y" /* yacc.c:1646  */
    {}
#line 2701 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 132:
#line 701 "src/main.y" /* yacc.c:1646  */
    {}
#line 2707 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 133:
#line 702 "src/main.y" /* yacc.c:1646  */
    {}
#line 2713 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 134:
#line 706 "src/main.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 2719 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 135:
#line 707 "src/main.y" /* yacc.c:1646  */
    {}
#line 2725 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 136:
#line 711 "src/main.y" /* yacc.c:1646  */
    {}
#line 2731 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 137:
#line 712 "src/main.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]); }
#line 2737 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 138:
#line 716 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
}
#line 2745 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 139:
#line 719 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode(lineno, NODE_TYPE);
    node->type = TYPE_ARRAY;
    //cout << "ARRAY!!!\n";
    node->addChild((yyvsp[-3]));
    node->addChild((yyvsp[-1]));
    (yyval) = node;
}
#line 2758 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 140:
#line 727 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* fnode = new TreeNode(lineno, NODE_DECL);
    TreeNode* node = new TreeNode(lineno, NODE_DECL_FUNC);
    node->addChild((yyvsp[-3]));
    node->addChild((yyvsp[-1]));
    fnode->addChild(node);
    (yyval) = node;
}
#line 2771 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 141:
#line 737 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode(lineno, NODE_PARA_DECL_LIST);
    node->addChild((yyvsp[0]));
    (yyval) = node;
}
#line 2781 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 142:
#line 742 "src/main.y" /* yacc.c:1646  */
    {
    (yyvsp[-2])->addChild((yyvsp[0]));
    (yyval) = (yyvsp[-2]);
}
#line 2790 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 143:
#line 749 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode(lineno, NODE_PARA_DECL);
    node->addChild((yyvsp[-1])); 
    node->addChild((yyvsp[0]));
    (yyval) = (yyvsp[-1]);
}
#line 2801 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 144:
#line 759 "src/main.y" /* yacc.c:1646  */
    {TreeNode* node = new TreeNode(lineno, NODE_TYPE); node->type = TYPE_POINTER; (yyval) = node;}
#line 2807 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 145:
#line 760 "src/main.y" /* yacc.c:1646  */
    {
        TreeNode* node = new TreeNode(lineno, NODE_TYPE); 
        node->type = TYPE_POINTER;
        node->addSibling((yyvsp[0]));
        (yyval) = node;
    }
#line 2818 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 146:
#line 769 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = new TreeNode(lineno, NODE_TYPE); (yyval)->type = TYPE_CONST;
    }
#line 2826 "src/main.tab.cpp" /* yacc.c:1646  */
    break;


#line 2830 "src/main.tab.cpp" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 772 "src/main.y" /* yacc.c:1906  */






int yyerror(char const* message)
{
  cout << message << " at line " << lineno << endl;
  return -1;
}
