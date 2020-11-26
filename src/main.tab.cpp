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

#line 76 "src/main.tab.cpp" /* yacc.c:339  */

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
    KW_IF = 292,
    KW_FOR = 293,
    KW_RET = 294,
    KW_STRUCT = 295,
    KW_WHILE = 296,
    KW_DO = 297,
    T_SIGNED = 298,
    T_UNSIGNED = 299,
    Q_CONST = 300,
    SEMICOLON = 301,
    COLON = 302,
    LO_REL_L = 303,
    LO_REL_G = 304,
    LO_REL_LE = 305,
    LO_REL_GE = 306,
    KW_UNION = 307,
    IDENTIFIER = 308,
    INTEGER = 309,
    CHAR = 310,
    BOOL = 311,
    STRING = 312,
    LO_MEMBER = 313,
    LO_PT_MEMBER = 314,
    L_BRACKET = 315,
    R_BRACKET = 316,
    L_SQ_BRACKET = 317,
    R_SQ_BRACKET = 318,
    L_BRACE = 319,
    R_BRACE = 320
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

#line 193 "src/main.tab.cpp" /* yacc.c:358  */

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
#define YYFINAL  16
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   206

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  66
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  101
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  152

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   320

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
      65
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    36,    36,    39,    40,    44,    45,    50,    58,    69,
      72,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      89,    92,   103,   106,   117,   120,   130,   133,   143,   146,
     156,   159,   169,   172,   182,   185,   192,   202,   205,   212,
     219,   226,   236,   239,   246,   256,   259,   266,   276,   279,
     286,   293,   303,   306,   316,   317,   318,   319,   320,   321,
     325,   328,   334,   340,   361,   364,   371,   378,   385,   391,
     400,   403,   406,   412,   418,   419,   420,   421,   422,   423,
     427,   430,   433,   438,   438,   441,   444,   450,   455,   456,
     457,   458,   462,   463,   467,   468,   472,   473,   477,   480,
     481,   485
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
  "LO_COMMA", "KW_IF", "KW_FOR", "KW_RET", "KW_STRUCT", "KW_WHILE",
  "KW_DO", "T_SIGNED", "T_UNSIGNED", "Q_CONST", "SEMICOLON", "COLON",
  "LO_REL_L", "LO_REL_G", "LO_REL_LE", "LO_REL_GE", "KW_UNION",
  "IDENTIFIER", "INTEGER", "CHAR", "BOOL", "STRING", "LO_MEMBER",
  "LO_PT_MEMBER", "L_BRACKET", "R_BRACKET", "L_SQ_BRACKET", "R_SQ_BRACKET",
  "L_BRACE", "R_BRACE", "$accept", "program", "statements", "statement",
  "declaration", "expression", "assignment-operator",
  "assignment-expression", "conditional-expression",
  "logical-OR-expression", "logical-AND-expression",
  "inclusive-OR-expression", "exclusive-OR-expression", "AND-expression",
  "equality-expression", "relational-expression", "shift-expression",
  "additive-expression", "multiplicative-expression", "cast-expression",
  "unary-operator", "unary-expression", "postfix-expression",
  "primary-expression", "constant", "type-specifier",
  "struct-or-union-specifier", "struct-or-union",
  "struct-declaration-list", "struct-declaration",
  "specifier-qualifier-list", "struct-declarator-list",
  "struct-declarator", "declarator", "direct-declarator", "pointer",
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
     315,   316,   317,   318,   319,   320
};
# endif

#define YYPACT_NINF -65

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-65)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      95,   -65,   -65,   -65,   -65,   -65,   -65,   -65,   -65,    23,
      95,   -65,   -12,   -28,   -65,   -34,   -65,   -65,   -65,    24,
      10,    78,   119,    78,   -65,    78,     8,   -65,   -15,    78,
     136,   136,   -65,   -65,   -65,   -65,   -65,   -65,   -65,   -65,
      72,    41,   -65,   -65,     1,    56,    53,    62,    55,    32,
      58,     6,    48,    43,   -65,   119,   171,   -13,   -65,   -65,
      18,   -65,   -65,   -65,    79,   -65,   -20,   -65,    57,   -65,
      49,   -65,   119,   -65,   -65,   -26,    50,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   -65,   -65,   -65,
     -65,   -65,   -65,   -65,   -65,   -65,   -65,   -65,   119,   -65,
     -65,    64,    66,   119,   -65,   -65,   -15,   -65,    73,   -65,
     -65,   119,   -65,    -5,    56,    53,    62,    55,    32,    58,
      58,     6,     6,     6,     6,    48,    48,    43,    43,   -65,
     -65,   -65,   -65,   -65,   -65,    -9,   -65,   -65,   -65,   119,
     -65,   -65
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    75,    74,    76,    83,    77,    78,     5,    84,     0,
       2,     3,     0,     0,    79,     0,     1,     4,     6,     8,
      82,     0,     0,     0,   101,    88,     0,    85,     0,    90,
       0,     0,    55,    56,    57,    58,    59,    54,    70,    73,
       0,     7,     9,    20,    22,    24,    26,    28,    30,    32,
      34,    37,    42,    45,    48,     0,    52,    60,    64,    71,
       0,    89,    81,    86,    99,    98,     0,    92,    94,    97,
       0,    91,     0,    61,    62,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    63,    52,    12,
      19,    15,    14,    17,    18,    13,    16,    11,     0,    68,
      69,     0,     0,     0,    80,   100,     0,    87,     0,    96,
      72,     0,    10,     0,    25,    27,    29,    31,    33,    35,
      36,    38,    39,    40,    41,    43,    44,    46,    47,    49,
      50,    51,    21,    66,    67,     0,    93,    95,    53,     0,
      65,    23
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -65,   -65,   -65,   100,   -65,   -21,   -65,   -64,   -29,   -65,
      52,    54,    47,    51,    46,   -18,    76,   -11,    21,   -53,
     -65,   -22,   -65,   -65,   -65,     7,   -65,   -65,   122,   -23,
       3,   -65,    30,   -65,    81,    84,   -65
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     9,    10,    11,    12,    75,   108,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    98,    57,    58,    59,    25,    14,    15,    26,    27,
      28,    66,    67,    68,    69,    70,    29
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      56,    41,    97,    63,   109,   110,    64,    13,    73,    74,
      77,     1,     2,   122,     3,   149,   116,    13,    56,    20,
      78,     1,     2,    16,     3,    19,   117,    77,    61,    79,
      21,    77,    71,    90,    18,   120,    91,    63,    65,    84,
      85,   139,   140,   141,   142,   111,   112,    76,     4,   113,
      56,     5,     6,    24,   150,    56,    56,   123,     4,    22,
       8,     5,     6,    24,    94,    95,   129,   130,   148,    96,
       8,    92,    93,    62,    23,     1,     2,    77,     3,   135,
     136,     1,     2,   114,     3,    80,    56,    81,    83,    30,
      31,    56,   145,    32,    82,    33,    34,    35,     1,     2,
      64,     3,    65,    36,   118,    37,    86,    87,    88,    89,
      17,   121,     4,   137,   138,     5,     6,   143,     4,   144,
     151,     5,     6,    24,     8,    38,    39,   147,   126,   128,
       8,   124,    40,   127,   125,     4,    30,    31,     5,     6,
      32,     7,    33,    34,    35,    60,   146,     8,   115,     0,
      36,   119,    37,    30,    31,     0,     0,    32,     0,    33,
      34,    35,   131,   132,   133,   134,     0,    36,     0,    37,
       0,     0,    38,    39,     0,     0,     0,     0,     0,    40,
      99,   100,   101,   102,   103,   104,   105,   106,     0,    38,
      39,     0,     0,     0,     0,     0,    72,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   107
};

static const yytype_int16 yycheck[] =
{
      22,    22,    55,    26,    17,    18,    21,     0,    30,    31,
      36,     3,     4,    77,     6,    20,    36,    10,    40,    53,
      19,     3,     4,     0,     6,    53,    46,    36,    25,    28,
      64,    36,    29,    27,    46,    61,    30,    60,    53,     7,
       8,    94,    95,    96,   108,    58,    59,    40,    40,    62,
      72,    43,    44,    45,    63,    77,    78,    78,    40,    35,
      52,    43,    44,    45,    21,    22,    84,    85,   121,    26,
      52,    23,    24,    65,    64,     3,     4,    36,     6,    90,
      91,     3,     4,    65,     6,    29,   108,    34,    33,    17,
      18,   113,   113,    21,    32,    23,    24,    25,     3,     4,
      21,     6,    53,    31,    47,    33,    48,    49,    50,    51,
      10,    61,    40,    92,    93,    43,    44,    53,    40,    53,
     149,    43,    44,    45,    52,    53,    54,    54,    81,    83,
      52,    79,    60,    82,    80,    40,    17,    18,    43,    44,
      21,    46,    23,    24,    25,    23,   116,    52,    64,    -1,
      31,    70,    33,    17,    18,    -1,    -1,    21,    -1,    23,
      24,    25,    86,    87,    88,    89,    -1,    31,    -1,    33,
      -1,    -1,    53,    54,    -1,    -1,    -1,    -1,    -1,    60,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,    53,
      54,    -1,    -1,    -1,    -1,    -1,    60,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    35
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     6,    40,    43,    44,    46,    52,    67,
      68,    69,    70,    91,    92,    93,     0,    69,    46,    53,
      53,    64,    35,    64,    45,    91,    94,    95,    96,   102,
      17,    18,    21,    23,    24,    25,    31,    33,    53,    54,
      60,    71,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      94,    96,    65,    95,    21,    53,    97,    98,    99,   100,
     101,    96,    60,    87,    87,    71,    91,    36,    19,    28,
      29,    34,    32,    33,     7,     8,    48,    49,    50,    51,
      27,    30,    23,    24,    21,    22,    26,    85,    87,     9,
      10,    11,    12,    13,    14,    15,    16,    35,    72,    17,
      18,    58,    59,    62,    65,   101,    36,    46,    47,   100,
      61,    61,    73,    71,    76,    77,    78,    79,    80,    81,
      81,    82,    82,    82,    82,    83,    83,    84,    84,    85,
      85,    85,    73,    53,    53,    71,    98,    54,    85,    20,
      63,    74
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    66,    67,    68,    68,    69,    69,    70,    70,    71,
      71,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      73,    73,    74,    74,    75,    75,    76,    76,    77,    77,
      78,    78,    79,    79,    80,    80,    80,    81,    81,    81,
      81,    81,    82,    82,    82,    83,    83,    83,    84,    84,
      84,    84,    85,    85,    86,    86,    86,    86,    86,    86,
      87,    87,    87,    87,    88,    88,    88,    88,    88,    88,
      89,    89,    89,    90,    91,    91,    91,    91,    91,    91,
      92,    92,    92,    93,    93,    94,    94,    95,    96,    96,
      96,    96,    97,    97,    98,    98,    99,    99,   100,   101,
     101,   102
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     2,     4,     2,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     5,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     3,     1,     3,     3,
       3,     3,     1,     3,     3,     1,     3,     3,     1,     3,
       3,     3,     1,     4,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     2,     1,     4,     3,     3,     2,     2,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       5,     4,     2,     1,     1,     1,     2,     3,     1,     2,
       1,     2,     1,     3,     1,     3,     2,     1,     1,     1,
       2,     1
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
    {root = new TreeNode(0, NODE_PROG); root->addChild((yyvsp[0]));}
#line 1416 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 39 "src/main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1422 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 40 "src/main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-1]); (yyval)->addSibling((yyvsp[0]));}
#line 1428 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 44 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_STMT); (yyval)->stype = STMT_SKIP;}
#line 1434 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 45 "src/main.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[-1]);}
#line 1440 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 50 "src/main.y" /* yacc.c:1646  */
    {  // declare and init
    TreeNode* node = new TreeNode((yyvsp[-3])->lineno, NODE_STMT);
    node->stype = STMT_DECL;
    node->addChild((yyvsp[-3]));
    node->addChild((yyvsp[-2]));
    node->addChild((yyvsp[0]));
    (yyval) = node;   
}
#line 1453 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 58 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-1])->lineno, NODE_STMT);
    node->stype = STMT_DECL;
    node->addChild((yyvsp[-1]));
    node->addChild((yyvsp[0]));
    (yyval) = node;   
}
#line 1465 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 69 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
}
#line 1473 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 72 "src/main.y" /* yacc.c:1646  */
    {
    (yyvsp[-2])->addChild((yyvsp[-1]));
}
#line 1481 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 77 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_OP); (yyval)->optype = OP_ASSIGN;}
#line 1487 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 78 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_OP); (yyval)->optype = OP_AS_ADDEQ;}
#line 1493 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 79 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_OP); (yyval)->optype = OP_AS_ANDEQ;}
#line 1499 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 80 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_OP); (yyval)->optype = OP_AS_DIVEQ;}
#line 1505 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 81 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_OP); (yyval)->optype = OP_AS_MULEQ;}
#line 1511 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 82 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_OP); (yyval)->optype = OP_AS_OREQ;}
#line 1517 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 83 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_OP); (yyval)->optype = OP_AS_SFTL_EQ;}
#line 1523 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 84 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_OP); (yyval)->optype = OP_AS_SFTR_EQ;}
#line 1529 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 85 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_OP); (yyval)->optype = OP_AS_SUB_EQ;}
#line 1535 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 89 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
}
#line 1543 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 92 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-2])->lineno, NODE_ASSI);
    node-> optype = (yyvsp[-1])->optype;
    node-> addChild((yyvsp[-2]));
    node-> addChild((yyvsp[-1]));
    node-> addChild((yyvsp[0]));
    (yyval) = node;
}
#line 1556 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 103 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
}
#line 1564 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 106 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-4])->lineno, NODE_EXPR);
    node -> optype = OP_CONDITION;
    node -> addChild((yyvsp[-4]));
    node -> addChild((yyvsp[-2]));
    node -> addChild((yyvsp[0]));
    (yyval) = node;
}
#line 1577 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 117 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
}
#line 1585 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 120 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-2])->lineno, NODE_EXPR);
    node -> optype = OP_LGC_OR;
    node -> addChild((yyvsp[-2]));
    node -> addChild((yyvsp[0]));
    (yyval) = node;
}
#line 1597 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 130 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
}
#line 1605 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 133 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-2])->lineno, NODE_EXPR);
    node -> optype = OP_LGC_AND;
    node -> addChild((yyvsp[-2]));
    node -> addChild((yyvsp[0]));
    (yyval) = node;
}
#line 1617 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 143 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
}
#line 1625 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 146 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-2])->lineno, NODE_EXPR);
    node -> optype = OP_BIT_OR;
    node -> addChild((yyvsp[-2]));
    node -> addChild((yyvsp[0]));
    (yyval) = node;
}
#line 1637 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 156 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
}
#line 1645 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 159 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-2])->lineno, NODE_EXPR);
    node -> optype = OP_BIT_XOR;
    node -> addChild((yyvsp[-2]));
    node -> addChild((yyvsp[0]));
    (yyval) = node;
}
#line 1657 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 169 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
}
#line 1665 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 172 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-2])->lineno, NODE_EXPR);
    node -> optype = OP_BIT_AND;
    node -> addChild((yyvsp[-2]));
    node -> addChild((yyvsp[0]));
    (yyval) = node;
}
#line 1677 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 182 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
}
#line 1685 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 185 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-2])->lineno, NODE_EXPR);
    node -> optype = OP_EQ;
    node -> addChild((yyvsp[-2]));
    node -> addChild((yyvsp[0]));
    (yyval) = node;
}
#line 1697 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 192 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-2])->lineno, NODE_EXPR);
    node -> optype = OP_N_EQ;
    node -> addChild((yyvsp[-2]));
    node -> addChild((yyvsp[0]));
    (yyval) = node;
}
#line 1709 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 202 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
}
#line 1717 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 205 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-2])->lineno, NODE_EXPR);
    node -> optype = OP_REL_L;
    node -> addChild((yyvsp[-2]));
    node -> addChild((yyvsp[0]));
    (yyval) = node;
}
#line 1729 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 212 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-2])->lineno, NODE_EXPR);
    node -> optype = OP_REL_G;
    node -> addChild((yyvsp[-2]));
    node -> addChild((yyvsp[0]));
    (yyval) = node;
}
#line 1741 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 219 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-2])->lineno, NODE_EXPR);
    node -> optype = OP_REL_LE;
    node -> addChild((yyvsp[-2]));
    node -> addChild((yyvsp[0]));
    (yyval) = node;
}
#line 1753 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 226 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-2])->lineno, NODE_EXPR);
    node -> optype = OP_REL_GE;
    node -> addChild((yyvsp[-2]));
    node -> addChild((yyvsp[0]));
    (yyval) = node;
}
#line 1765 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 236 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
}
#line 1773 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 239 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-2])->lineno, NODE_EXPR);
    node -> optype = OP_SFT_L;
    node -> addChild((yyvsp[-2]));
    node -> addChild((yyvsp[0]));
    (yyval) = node;
}
#line 1785 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 246 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-2])->lineno, NODE_EXPR);
    node -> optype = OP_SFT_R;
    node -> addChild((yyvsp[-2]));
    node -> addChild((yyvsp[0]));
    (yyval) = node;
}
#line 1797 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 256 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
}
#line 1805 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 259 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-2])->lineno, NODE_EXPR);
    node -> optype = OP_ADD;
    node -> addChild((yyvsp[-2]));
    node -> addChild((yyvsp[0]));
    (yyval) = node;
}
#line 1817 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 266 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-2])->lineno, NODE_EXPR);
    node -> optype = OP_SUB;
    node -> addChild((yyvsp[-2]));
    node -> addChild((yyvsp[0]));
    (yyval) = node;
}
#line 1829 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 276 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
}
#line 1837 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 279 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-2])->lineno, NODE_EXPR);
    node -> optype = OP_MUL;
    node -> addChild((yyvsp[-2]));
    node -> addChild((yyvsp[0]));
    (yyval) = node;
}
#line 1849 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 286 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-2])->lineno, NODE_EXPR);
    node -> optype = OP_DIV;
    node -> addChild((yyvsp[-2]));
    node -> addChild((yyvsp[0]));
    (yyval) = node;
}
#line 1861 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 293 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-2])->lineno, NODE_EXPR);
    node -> optype = OP_MOD;
    node -> addChild((yyvsp[-2]));
    node -> addChild((yyvsp[0]));
    (yyval) = node;
}
#line 1873 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 303 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
}
#line 1881 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 306 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-3])->lineno, NODE_EXPR);
    node -> optype = OP_CAST;
    node -> addChild((yyvsp[-2]));
    node -> addChild((yyvsp[-1]));
    (yyval) = node;
}
#line 1893 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 316 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_OP); (yyval)->optype = OP_UNA_REF;}
#line 1899 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 317 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_OP); (yyval)->optype = OP_UNA_DEREF;}
#line 1905 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 318 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_OP); (yyval)->optype = OP_POSITIVE;}
#line 1911 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 319 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_OP); (yyval)->optype = OP_MINUS;}
#line 1917 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 320 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_OP); (yyval)->optype = OP_BIT_NOT;}
#line 1923 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 321 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_OP); (yyval)->optype = OP_LGC_NOT;}
#line 1929 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 325 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
}
#line 1937 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 328 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-1])->lineno, NODE_EXPR);
    node -> optype = OP_PRESELFINC;
    node -> addChild((yyvsp[0]));
    (yyval) = node;
}
#line 1948 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 334 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-1])->lineno, NODE_EXPR);
    node -> optype = OP_PRESELFDEC;
    node -> addChild((yyvsp[0]));
    (yyval) = node;
}
#line 1959 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 340 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-1])->lineno, NODE_EXPR);
    node -> optype = (yyvsp[-1])->optype;
    node -> addChild((yyvsp[-1]));
    node -> addChild((yyvsp[0]));
    (yyval) = node;
}
#line 1971 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 361 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
}
#line 1979 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 364 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-3])->lineno, NODE_EXPR);
    node -> optype = OP_OFFSET_ACCESS;
    node -> addChild((yyvsp[-3]));
    node -> addChild((yyvsp[-1]));
    (yyval) = node;
}
#line 1991 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 371 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-2])->lineno, NODE_EXPR);
    node -> optype = OP_AC_MEMBER;
    node -> addChild((yyvsp[-2]));
    node -> addChild((yyvsp[0]));
    (yyval) = node;
}
#line 2003 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 378 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-2])->lineno, NODE_EXPR);
    node -> optype = OP_PTAC_MEMBER;
    node -> addChild((yyvsp[-2]));
    node -> addChild((yyvsp[0]));
    (yyval) = node;
}
#line 2015 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 385 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-1])->lineno, NODE_EXPR);
    node -> optype = OP_POSTSELFINC;
    node -> addChild((yyvsp[-1]));
    (yyval) = node;
}
#line 2026 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 391 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-1])->lineno, NODE_EXPR);
    node -> optype = OP_POSTSELFDEC;
    node -> addChild((yyvsp[-1]));
    (yyval) = node;
}
#line 2037 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 400 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
}
#line 2045 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 403 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
}
#line 2053 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 406 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[-1]);
}
#line 2061 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 412 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
}
#line 2069 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 418 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_TYPE); (yyval)->type = TYPE_INT;}
#line 2075 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 419 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_TYPE); (yyval)->type = TYPE_CHAR;}
#line 2081 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 420 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_TYPE); (yyval)->type = TYPE_BOOL;}
#line 2087 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 421 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_TYPE); (yyval)->type = TYPE_SIGNED;}
#line 2093 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 422 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_TYPE); (yyval)->type = TYPE_UNSIGNED;}
#line 2099 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 423 "src/main.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 2105 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 427 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = NULL;
}
#line 2113 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 430 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = NULL;
}
#line 2121 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 433 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = NULL;
}
#line 2129 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 438 "src/main.y" /* yacc.c:1646  */
    {}
#line 2135 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 438 "src/main.y" /* yacc.c:1646  */
    {}
#line 2141 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 441 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = NULL;
}
#line 2149 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 444 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = NULL;
}
#line 2157 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 450 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = NULL;
    }
#line 2165 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 455 "src/main.y" /* yacc.c:1646  */
    {}
#line 2171 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 456 "src/main.y" /* yacc.c:1646  */
    {}
#line 2177 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 457 "src/main.y" /* yacc.c:1646  */
    {}
#line 2183 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 458 "src/main.y" /* yacc.c:1646  */
    {}
#line 2189 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 462 "src/main.y" /* yacc.c:1646  */
    {}
#line 2195 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 463 "src/main.y" /* yacc.c:1646  */
    {}
#line 2201 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 467 "src/main.y" /* yacc.c:1646  */
    {}
#line 2207 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 468 "src/main.y" /* yacc.c:1646  */
    {}
#line 2213 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 472 "src/main.y" /* yacc.c:1646  */
    {}
#line 2219 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 473 "src/main.y" /* yacc.c:1646  */
    {}
#line 2225 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 477 "src/main.y" /* yacc.c:1646  */
    {}
#line 2231 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 480 "src/main.y" /* yacc.c:1646  */
    {}
#line 2237 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 481 "src/main.y" /* yacc.c:1646  */
    {}
#line 2243 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 485 "src/main.y" /* yacc.c:1646  */
    {}
#line 2249 "src/main.tab.cpp" /* yacc.c:1646  */
    break;


#line 2253 "src/main.tab.cpp" /* yacc.c:1646  */
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
#line 486 "src/main.y" /* yacc.c:1906  */






int yyerror(char const* message)
{
  cout << message << " at line " << lineno << endl;
  return -1;
}
