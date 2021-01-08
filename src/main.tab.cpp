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
    #include "domain.h"
    #include "inter.h"
    #define YYSTYPE TreeNode *  
    TreeNode* root;
    BBlock currentBB;
    extern int lineno;
    extern domain* d_root;
    int yylex();
    int yyerror( char const * );
    

#line 81 "src/main.tab.cpp" /* yacc.c:339  */

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

/* Copy the second part of user declarations.  */

#line 204 "src/main.tab.cpp" /* yacc.c:358  */

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
#define YYFINAL  19
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   636

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  72
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  54
/* YYNRULES -- Number of rules.  */
#define YYNRULES  153
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  260

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   326

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
      65,    66,    67,    68,    69,    70,    71
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    40,    40,    45,    51,    56,    64,    80,    81,    82,
      83,    84,    85,    86,    87,    91,    97,   105,   110,   115,
     120,   129,   136,   143,   154,   168,   175,   186,   187,   195,
     200,   207,   211,   218,   221,   227,   237,   249,   252,   256,
     259,   267,   272,   279,   286,   297,   304,   312,   315,   324,
     329,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     349,   352,   363,   366,   377,   380,   390,   393,   403,   406,
     416,   419,   429,   432,   442,   445,   452,   462,   465,   472,
     479,   486,   496,   499,   506,   516,   519,   526,   536,   539,
     546,   553,   563,   566,   576,   577,   578,   579,   580,   581,
     585,   588,   594,   600,   611,   614,   621,   628,   635,   641,
     647,   655,   666,   672,   680,   684,   687,   693,   708,   714,
     715,   716,   717,   718,   719,   720,   724,   727,   730,   735,
     735,   738,   741,   747,   752,   753,   754,   755,   759,   760,
     764,   765,   769,   774,   782,   785,   793,   801,   812,   818,
     826,   835,   847,   857
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_CHAR", "T_INT", "T_STRING", "T_BOOL",
  "T_VOID", "SCANF", "PRINTF", "LO_EQ", "LO_N_EQ", "RO_AS_ADDEQ",
  "RO_AS_SUBEQ", "RO_AS_MULEQ", "RO_AS_DIVEQ", "RO_AS_SFTL_EQ",
  "RO_AS_SFTR_EQ", "RO_AS_ANDEQ", "RO_AS_OREQ", "LO_AS_SELFINC",
  "LO_AS_SELFDEC", "RO_TRI_QUES", "RO_TRI_COLON", "LO_MUL", "LO_DIV",
  "LO_ADD", "LO_SUB", "LO_BIT_NOT", "LO_MOD", "LO_SFT_L", "LO_LGC_OR",
  "LO_LGC_AND", "LO_SFT_R", "LO_LGC_NOT", "LO_BIT_XOR", "LO_BIT_AND",
  "LO_BIT_OR", "RO_ASSIGN", "LO_COMMA", "KW_CONTINUE", "KW_BREAK", "KW_IF",
  "KW_FOR", "KW_RET", "KW_STRUCT", "KW_WHILE", "KW_DO", "KW_ELSE",
  "T_SIGNED", "T_UNSIGNED", "Q_CONST", "SEMICOLON", "COLON", "LO_REL_L",
  "LO_REL_G", "LO_REL_LE", "LO_REL_GE", "KW_UNION", "IDENTIFIER",
  "INTEGER", "CHAR", "BOOL", "STRING", "LO_MEMBER", "LO_PT_MEMBER",
  "L_BRACKET", "R_BRACKET", "L_SQ_BRACKET", "R_SQ_BRACKET", "L_BRACE",
  "R_BRACE", "$accept", "translation-unit", "external-declaration",
  "function-definition", "statement", "io-statement", "jump-statement",
  "iteration-statement", "selection-statement", "expression-statement",
  "compound-statement", "block-item-list", "block-item", "declaration",
  "declaration-specifiers", "init-declarator-list", "init-declarator",
  "initializer", "initializer-list", "expression", "assignment-operator",
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
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326
};
# endif

#define YYPACT_NINF -84

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-84)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     443,   -84,   -84,   -84,   -84,   -84,   -84,   -84,   -84,   -84,
     429,   -84,   -84,   -84,   -11,   443,   -84,   -42,   443,   -84,
     -84,   -84,   -84,    60,   -84,   -19,   -12,   -11,   -84,   -37,
     443,   -84,   -11,   -84,   449,   181,   -84,   359,   559,   -84,
     443,   443,    97,   -84,   -11,   443,   -84,    19,   570,   570,
     -84,   -84,   -84,   -84,   -84,   -84,   -84,   -84,   -84,   394,
     449,   -84,   -84,   -84,    -4,    46,    96,     3,    99,    62,
     103,     2,    79,   102,   -84,   559,   249,    50,   -84,   -84,
      55,    72,    89,    93,    90,   105,   507,   106,   333,   -84,
     -84,   -84,   -84,   -84,   -84,   -84,   -84,   -84,   250,   -84,
     -84,   -11,    70,   -84,   -84,   -11,   -25,   -84,   104,   300,
     -84,   -84,   -84,    78,   -84,   100,   -84,   559,   -84,   -84,
     -14,    95,   -84,   -16,   559,   559,   559,   559,   559,   559,
     559,   559,   559,   559,   559,   559,   559,   559,   559,   559,
     559,   559,   559,   -84,   -84,   -84,   -84,   -84,   -84,   -84,
     -84,   -84,   -84,   -84,   559,   -84,   -84,   117,   118,   490,
     559,   116,   128,   -84,   -84,   559,   548,   -84,   129,   559,
     146,   -84,   -84,   -84,   559,   -84,   -84,   443,   -84,   -84,
     -84,   -11,   -84,   133,   -84,   559,   449,   -84,    -8,    46,
      96,     3,    99,    62,   103,   103,     2,     2,     2,     2,
      79,    79,   102,   102,   -84,   -84,   -84,   -84,   -84,   -84,
     -84,   -84,    -9,   -28,   157,   158,    -3,   148,    84,   -84,
       0,   132,   -84,   -84,   -84,   -84,   -84,   -84,   559,   559,
     -84,   -84,   570,   559,   333,   136,   559,   333,   559,   -84,
     -84,   137,   139,   162,   333,    85,   -84,     1,   159,   160,
     333,   -84,   559,   -84,   -84,   -84,   -84,    30,   333,   -84
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   120,   119,   121,   122,   129,   123,   124,   153,   130,
       0,     2,     4,     5,    36,    37,   125,     0,    39,     1,
       3,   152,   144,     0,    41,    43,   143,     0,    38,   128,
       0,    40,     0,    35,     0,     0,     6,     0,     0,   142,
       0,   134,     0,   131,     0,   136,    42,    43,     0,     0,
      95,    96,    97,    98,    99,    94,   114,   117,   118,     0,
       0,    44,    45,    60,    62,    64,    66,    68,    70,    72,
      74,    77,    82,    85,    88,     0,    92,   100,   104,   115,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     7,
      30,    34,    14,    13,    12,    11,    10,     9,     0,    31,
       8,    36,     0,    49,   147,   151,     0,   148,     0,     0,
     135,   127,   132,     0,   138,   140,   137,     0,   101,   102,
       0,     0,    47,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   103,    92,    52,    59,    55,    54,    57,
      58,    53,    56,    51,     0,   108,   109,     0,     0,     0,
       0,     0,     0,    18,    17,     0,     0,    19,     0,     0,
       0,     8,    29,    32,     0,    28,   150,     0,   146,   145,
     126,     0,   133,     0,   116,     0,     0,    46,     0,    65,
      67,    69,    71,    73,    75,    76,    78,    79,    80,    81,
      83,    84,    86,    87,    89,    90,    91,    61,   106,   107,
     111,   112,     0,     0,     0,     0,     0,     0,     0,    20,
       0,     0,    50,   149,   139,   141,    93,    48,     0,     0,
     110,   105,     0,     0,     0,     0,     0,     0,     0,    63,
     113,     0,     0,    25,     0,     0,    21,     0,     0,     0,
       0,    23,     0,    22,    16,    15,    26,     0,     0,    24
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -84,   -84,   203,   -84,   -83,   -84,   -84,   -84,   -84,   -84,
     189,   -84,   120,    12,     6,   -84,   184,   -52,   -84,   -58,
     -84,   -34,     7,   -84,    94,   108,   109,    92,   113,    13,
      31,    33,    11,   -66,   -84,   -46,   -84,   -84,   -84,   -84,
       4,   -84,   -84,   197,   -32,    87,   -84,    48,    -7,   -84,
     -84,    61,   -84,    20
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    10,    11,    12,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   171,   101,    23,    24,    61,   123,   102,
     154,   103,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,   212,    78,    79,
      15,    16,    17,    42,    43,    44,   113,   114,    47,    26,
     106,   107,    27,    18
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
      62,   120,   118,   119,   108,   170,    14,    25,   122,   143,
     112,   174,    13,    21,   177,   228,    14,    29,   124,    34,
      39,    28,    13,   186,    31,   174,    62,   125,    30,   144,
     229,   174,   136,    40,    41,   137,   174,   115,   128,   174,
     174,   231,   178,   105,    41,    41,    41,   100,    22,    41,
      45,    35,   168,   184,    37,   187,    38,    34,   230,   120,
      45,    45,    45,   121,   234,    45,   188,   237,   253,   174,
     155,   156,   130,   131,   204,   205,   206,   112,   126,   144,
     144,   144,   144,   144,   144,   144,   144,   144,   144,   144,
     144,   144,   144,   144,   144,   144,   144,   258,   176,    32,
       1,     2,   213,     3,     4,   138,   139,   216,   218,   174,
     100,   220,    33,    41,   157,   158,   159,   181,   160,   226,
     207,   161,   175,   174,   174,   211,   140,   141,   110,    45,
     182,   142,   116,   127,   227,   129,   236,   252,   162,   144,
     222,   163,     5,   194,   195,   164,     6,     7,     8,   202,
     203,   243,    62,   183,   246,     9,   165,   132,   133,   134,
     135,   251,   185,   196,   197,   198,   199,   256,   111,   200,
     201,   166,   169,   179,   115,   259,   208,   209,   245,   214,
     247,   219,   144,   105,     1,     2,   241,     3,     4,    80,
      81,   215,   221,   225,   257,   240,   232,   233,   238,   242,
     235,    48,    49,   244,   248,    50,   249,    51,    52,    53,
     250,   254,   255,    20,    36,    54,    46,    55,   173,   189,
     192,    82,    83,    84,    85,    86,     5,    87,    88,   224,
       6,     7,     8,    89,   190,   239,   191,   109,   223,     9,
      56,    57,   193,     0,    58,     0,     0,    59,     0,     0,
       0,    35,    90,     1,     2,     0,     3,     4,    80,    81,
       0,   145,   146,   147,   148,   149,   150,   151,   152,     0,
      48,    49,     0,     0,    50,     0,    51,    52,    53,     0,
       0,     0,     0,     0,    54,     0,    55,   153,     0,     0,
      82,    83,    84,    85,    86,     5,    87,    88,     0,     6,
       7,     8,    89,     1,     2,     0,     3,     4,     9,    56,
      57,     0,     0,    58,     0,     0,    59,     0,     0,     0,
      35,   172,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     1,     2,     0,     3,
       4,    80,    81,     0,     0,     5,     0,     0,     0,     6,
       7,     8,     0,    48,    49,     0,     0,    50,     9,    51,
      52,    53,     1,     2,     0,     3,     4,    54,     0,    55,
       0,   180,     0,    82,    83,    84,    85,    86,     5,    87,
      88,     0,     6,     7,     8,    89,     0,     0,     0,     0,
       0,     9,    56,    57,     0,     0,    58,     1,     2,    59,
       3,     4,     0,    35,     5,     0,     0,     0,     6,     7,
       8,     0,     0,     0,    48,    49,     0,     9,    50,     0,
      51,    52,    53,     0,     0,     0,   104,     0,    54,    19,
      55,     0,     1,     2,     0,     3,     4,     0,     0,     5,
       0,     0,     0,     6,     7,     0,     1,     2,     0,     3,
       4,     0,     9,    56,    57,     0,     0,    58,     0,     0,
      59,     0,     0,     0,     0,     0,     0,     0,     0,    48,
      49,     0,     0,    50,     5,    51,    52,    53,     6,     7,
       8,     0,     0,    54,     0,    55,     0,     9,     5,     0,
       0,     0,     6,     7,     8,     0,     0,     0,     0,     0,
       0,     9,     0,     0,     0,     0,     0,     0,    56,    57,
      48,    49,    58,     0,    50,    59,    51,    52,    53,    60,
       0,     0,     0,     0,    54,     0,    55,    48,    49,     0,
       0,    50,     0,    51,    52,    53,     0,     0,     0,     0,
       0,    54,     0,    55,     0,     0,     0,     0,     0,    56,
      57,     0,     0,    58,     0,     0,    59,   210,     0,   167,
       0,     0,     0,     0,     0,     0,    56,    57,    48,    49,
      58,     0,    50,    59,    51,    52,    53,     0,     0,    48,
      49,     0,    54,    50,    55,    51,    52,    53,     0,     0,
      48,    49,     0,    54,    50,    55,    51,    52,    53,     0,
     217,     0,     0,     0,    54,     0,    55,    56,    57,     0,
       0,    58,     0,     0,    59,     0,     0,     0,    56,    57,
       0,     0,    58,     0,     0,    59,     0,     0,     0,    56,
      57,     0,     0,    58,     0,     0,   117
};

static const yytype_int16 yycheck[] =
{
      34,    59,    48,    49,    38,    88,     0,    14,    60,    75,
      42,    39,     0,    24,    39,    23,    10,    59,    22,    38,
      27,    15,    10,    39,    18,    39,    60,    31,    70,    75,
      39,    39,    30,    70,    30,    33,    39,    44,    35,    39,
      39,    69,    67,    37,    40,    41,    42,    35,    59,    45,
      30,    70,    86,    67,    66,    71,    68,    38,    67,   117,
      40,    41,    42,    59,    67,    45,   124,    67,    67,    39,
      20,    21,    10,    11,   140,   141,   142,   109,    32,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,    67,   105,    39,
       3,     4,   160,     6,     7,    26,    27,   165,   166,    39,
      98,   169,    52,   109,    64,    65,    66,    39,    68,   185,
     154,    66,    52,    39,    39,   159,    24,    25,    41,   109,
      52,    29,    45,    37,   186,    36,    52,    52,    66,   185,
     174,    52,    45,   130,   131,    52,    49,    50,    51,   138,
     139,   234,   186,    53,   237,    58,    66,    54,    55,    56,
      57,   244,    67,   132,   133,   134,   135,   250,    71,   136,
     137,    66,    66,    69,   181,   258,    59,    59,   236,    63,
     238,    52,   228,   177,     3,     4,   232,     6,     7,     8,
       9,    63,    46,    60,   252,   229,    39,    39,    66,   233,
      52,    20,    21,    67,    67,    24,    67,    26,    27,    28,
      48,    52,    52,    10,    25,    34,    32,    36,    98,   125,
     128,    40,    41,    42,    43,    44,    45,    46,    47,   181,
      49,    50,    51,    52,   126,   228,   127,    40,   177,    58,
      59,    60,   129,    -1,    63,    -1,    -1,    66,    -1,    -1,
      -1,    70,    71,     3,     4,    -1,     6,     7,     8,     9,
      -1,    12,    13,    14,    15,    16,    17,    18,    19,    -1,
      20,    21,    -1,    -1,    24,    -1,    26,    27,    28,    -1,
      -1,    -1,    -1,    -1,    34,    -1,    36,    38,    -1,    -1,
      40,    41,    42,    43,    44,    45,    46,    47,    -1,    49,
      50,    51,    52,     3,     4,    -1,     6,     7,    58,    59,
      60,    -1,    -1,    63,    -1,    -1,    66,    -1,    -1,    -1,
      70,    71,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,    -1,     6,
       7,     8,     9,    -1,    -1,    45,    -1,    -1,    -1,    49,
      50,    51,    -1,    20,    21,    -1,    -1,    24,    58,    26,
      27,    28,     3,     4,    -1,     6,     7,    34,    -1,    36,
      -1,    71,    -1,    40,    41,    42,    43,    44,    45,    46,
      47,    -1,    49,    50,    51,    52,    -1,    -1,    -1,    -1,
      -1,    58,    59,    60,    -1,    -1,    63,     3,     4,    66,
       6,     7,    -1,    70,    45,    -1,    -1,    -1,    49,    50,
      51,    -1,    -1,    -1,    20,    21,    -1,    58,    24,    -1,
      26,    27,    28,    -1,    -1,    -1,    67,    -1,    34,     0,
      36,    -1,     3,     4,    -1,     6,     7,    -1,    -1,    45,
      -1,    -1,    -1,    49,    50,    -1,     3,     4,    -1,     6,
       7,    -1,    58,    59,    60,    -1,    -1,    63,    -1,    -1,
      66,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,
      21,    -1,    -1,    24,    45,    26,    27,    28,    49,    50,
      51,    -1,    -1,    34,    -1,    36,    -1,    58,    45,    -1,
      -1,    -1,    49,    50,    51,    -1,    -1,    -1,    -1,    -1,
      -1,    58,    -1,    -1,    -1,    -1,    -1,    -1,    59,    60,
      20,    21,    63,    -1,    24,    66,    26,    27,    28,    70,
      -1,    -1,    -1,    -1,    34,    -1,    36,    20,    21,    -1,
      -1,    24,    -1,    26,    27,    28,    -1,    -1,    -1,    -1,
      -1,    34,    -1,    36,    -1,    -1,    -1,    -1,    -1,    59,
      60,    -1,    -1,    63,    -1,    -1,    66,    67,    -1,    52,
      -1,    -1,    -1,    -1,    -1,    -1,    59,    60,    20,    21,
      63,    -1,    24,    66,    26,    27,    28,    -1,    -1,    20,
      21,    -1,    34,    24,    36,    26,    27,    28,    -1,    -1,
      20,    21,    -1,    34,    24,    36,    26,    27,    28,    -1,
      52,    -1,    -1,    -1,    34,    -1,    36,    59,    60,    -1,
      -1,    63,    -1,    -1,    66,    -1,    -1,    -1,    59,    60,
      -1,    -1,    63,    -1,    -1,    66,    -1,    -1,    -1,    59,
      60,    -1,    -1,    63,    -1,    -1,    66
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     6,     7,    45,    49,    50,    51,    58,
      73,    74,    75,    85,    86,   112,   113,   114,   125,     0,
      74,    24,    59,    87,    88,   120,   121,   124,    86,    59,
      70,    86,    39,    52,    38,    70,    82,    66,    68,   120,
      70,   112,   115,   116,   117,   125,    88,   120,    20,    21,
      24,    26,    27,    28,    34,    36,    59,    60,    63,    66,
      70,    89,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   110,   111,
       8,     9,    40,    41,    42,    43,    44,    46,    47,    52,
      71,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    91,    93,    67,    86,   122,   123,    93,   115,
     117,    71,   116,   118,   119,   120,   117,    66,   107,   107,
      91,   112,    89,    90,    22,    31,    32,    37,    35,    36,
      10,    11,    54,    55,    56,    57,    30,    33,    26,    27,
      24,    25,    29,   105,   107,    12,    13,    14,    15,    16,
      17,    18,    19,    38,    92,    20,    21,    64,    65,    66,
      68,    66,    66,    52,    52,    66,    66,    52,    93,    66,
      76,    85,    71,    84,    39,    52,   120,    39,    67,    69,
      71,    39,    52,    53,    67,    67,    39,    71,    91,    96,
      97,    98,    99,   100,   101,   101,   102,   102,   102,   102,
     103,   103,   104,   104,   105,   105,   105,    93,    59,    59,
      67,    93,   109,    91,    63,    63,    91,    52,    91,    52,
      91,    46,    93,   123,   119,    60,   105,    89,    23,    39,
      67,    69,    39,    39,    67,    52,    52,    67,    66,    94,
      93,   107,    93,    76,    67,    91,    76,    91,    67,    67,
      48,    76,    52,    67,    52,    52,    76,    91,    67,    76
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    72,    73,    73,    74,    74,    75,    76,    76,    76,
      76,    76,    76,    76,    76,    77,    77,    78,    78,    78,
      78,    79,    79,    79,    79,    80,    80,    81,    81,    82,
      82,    83,    83,    84,    84,    85,    85,    86,    86,    86,
      86,    87,    87,    88,    88,    89,    89,    90,    90,    91,
      91,    92,    92,    92,    92,    92,    92,    92,    92,    92,
      93,    93,    94,    94,    95,    95,    96,    96,    97,    97,
      98,    98,    99,    99,   100,   100,   100,   101,   101,   101,
     101,   101,   102,   102,   102,   103,   103,   103,   104,   104,
     104,   104,   105,   105,   106,   106,   106,   106,   106,   106,
     107,   107,   107,   107,   108,   108,   108,   108,   108,   108,
     108,   108,   109,   109,   110,   110,   110,   111,   111,   112,
     112,   112,   112,   112,   112,   112,   113,   113,   113,   114,
     114,   115,   115,   116,   117,   117,   117,   117,   118,   118,
     119,   119,   120,   120,   121,   121,   121,   121,   122,   122,
     123,   123,   124,   125
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     7,     7,     2,     2,     2,
       3,     5,     6,     6,     9,     5,     7,     1,     2,     3,
       2,     1,     2,     1,     1,     3,     1,     1,     2,     1,
       2,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     5,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     3,     1,     3,     3,
       3,     3,     1,     3,     3,     1,     3,     3,     1,     3,
       3,     3,     1,     4,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     2,     1,     4,     3,     3,     2,     2,
       4,     3,     1,     3,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     5,     4,     2,     1,
       1,     1,     2,     3,     1,     2,     1,     2,     1,     3,
       1,     3,     2,     1,     1,     4,     4,     3,     1,     3,
       2,     1,     1,     1
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
#line 40 "src/main.y" /* yacc.c:1646  */
    {
    root = new TreeNode(0, NODE_PROG);
    root->domain = d_root;
    root->addChild((yyvsp[0]));
}
#line 1573 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 45 "src/main.y" /* yacc.c:1646  */
    {
    root->addChild((yyvsp[0]));
}
#line 1581 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 51 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode(lineno, NODE_EXTERN_DECL);
    node->addChild((yyvsp[0]));
    (yyval) = node;
}
#line 1591 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 56 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode(lineno, NODE_EXTERN_DECL);
    node->addChild((yyvsp[0]));
    (yyval) = node;
}
#line 1601 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 64 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode(lineno, NODE_EXTERN_FUNC_DECL);
    TreeNode* node2 = new TreeNode(lineno, NODE_DECL_SPCF);
    node->addChild(node2);
    node2->addChild((yyvsp[-2]));
    node->addChild((yyvsp[-1]));
    node->addChild((yyvsp[0]));
    (yyval) = node;
}
#line 1615 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 80 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_STMT); (yyval)->stype = STMT_SKIP;}
#line 1621 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 81 "src/main.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1627 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 82 "src/main.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1633 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 83 "src/main.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1639 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 84 "src/main.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1645 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 85 "src/main.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1651 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 86 "src/main.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1657 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 87 "src/main.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1663 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 91 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = new TreeNode(lineno, NODE_STMT);
    (yyval)->stype = STMT_PRINTF;
    (yyval)->addChild((yyvsp[-4]));
    (yyval)->addChild((yyvsp[-2]));
}
#line 1674 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 97 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = new TreeNode(lineno, NODE_STMT);
    (yyval)->stype = STMT_SCANF;
    (yyval)->addChild((yyvsp[-4]));
    (yyval)->addChild((yyvsp[-2]));
}
#line 1685 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 105 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode(lineno, NODE_STMT);
    node->stype = STMT_BREAK;
    (yyval) = node;
}
#line 1695 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 110 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode(lineno, NODE_STMT);
    node->stype = STMT_CONTINUE;
    (yyval) = node; 
}
#line 1705 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 115 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode(lineno, NODE_STMT);
    node->stype = STMT_RETURN;
    (yyval) = node;
}
#line 1715 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 120 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode(lineno, NODE_STMT);
    node->stype = STMT_RETURN;
    (yyval) = node;
    (yyval)->addChild((yyvsp[-1]));
}
#line 1726 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 129 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode(lineno, NODE_STMT);
    node->stype = STMT_WHILE;
    node->addChild((yyvsp[-2]));
    node->addChild((yyvsp[0]));
    (yyval) = node;
}
#line 1738 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 136 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode(lineno, NODE_STMT);
    node->stype = STMT_DO_WHILE;
    node->addChild((yyvsp[-1]));
    node->addChild((yyvsp[-4]));
    (yyval) = node;
}
#line 1750 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 143 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode(lineno, NODE_STMT);
    node->stype = STMT_FOR_NONE;
    TreeNode* node1 = new TreeNode(-1, NODE_NULL);
    TreeNode* node2 = new TreeNode(-1, NODE_NULL);
    TreeNode* node3 = new TreeNode(-1, NODE_NULL);
    node->addChild(node1);
    node->addChild(node2);
    node->addChild(node3);
    (yyval) = node;
}
#line 1766 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 154 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode(lineno, NODE_STMT);
    node->stype = STMT_FOR;
    node->addChild((yyvsp[-6]));
    node->addChild((yyvsp[-4]));
    node->addChild((yyvsp[-2]));
    node->addChild((yyvsp[0]));
    (yyval) = node;
}
#line 1780 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 168 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode(lineno, NODE_STMT);
    node->stype = STMT_SELECT;
    node->addChild((yyvsp[-2]));
    node->addChild((yyvsp[0]));
    (yyval) = node;
}
#line 1792 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 175 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode(lineno, NODE_STMT);
    node->stype = STMT_SELECT;
    node->addChild((yyvsp[-4]));
    node->addChild((yyvsp[-2]));
    node->addChild((yyvsp[0]));
    (yyval) = node;
}
#line 1805 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 186 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_STMT); (yyval)->stype = STMT_SKIP;}
#line 1811 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 187 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode(lineno, NODE_STMT);
    node->stype = STMT_EXPRESSION;
    node->addChild((yyvsp[-1]));
    (yyval) = node;
}
#line 1822 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 195 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = new TreeNode(lineno, NODE_STMT); 
    (yyval)->stype = STMT_COMPOUND;
    (yyval)->addChild((yyvsp[-1]));
}
#line 1832 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 200 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = new TreeNode(lineno, NODE_STMT); 
    (yyval)->stype = STMT_COMPOUND;
}
#line 1841 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 207 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = new TreeNode(lineno, NODE_BLOCK_LIST);
    (yyval)->addChild((yyvsp[0]));
}
#line 1850 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 211 "src/main.y" /* yacc.c:1646  */
    {
    (yyvsp[-1])->addChild((yyvsp[0]));
    (yyval) = (yyvsp[-1]);
}
#line 1859 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 218 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
}
#line 1867 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 221 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
}
#line 1875 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 227 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode(lineno, NODE_STMT);
    TreeNode* node2 = new TreeNode(lineno, NODE_DECL_SPCF);
    
    node->stype = STMT_DECL;
    node->addChild(node2);
    node2->addChild((yyvsp[-2]));
    node->addChild((yyvsp[-1]));
    (yyval) = node;
}
#line 1890 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 237 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode(lineno, NODE_STMT);
    TreeNode* node2 = new TreeNode(lineno, NODE_DECL_SPCF);
    
    node->stype = STMT_DECL;
    node->addChild(node2);
    node2->addChild((yyvsp[0]));
    (yyval) = node;
}
#line 1904 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 249 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
}
#line 1912 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 252 "src/main.y" /* yacc.c:1646  */
    {
    (yyvsp[-1]) -> addSibling((yyvsp[0]));
    (yyval) = (yyvsp[-1]);
}
#line 1921 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 256 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
}
#line 1929 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 259 "src/main.y" /* yacc.c:1646  */
    {
    (yyvsp[-1])->addSibling((yyvsp[0]));
    (yyval) = (yyvsp[-1]);
}
#line 1938 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 267 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode(lineno, NODE_DECL_LIST);
    node->addChild((yyvsp[0]));
    (yyval) = node;
}
#line 1948 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 272 "src/main.y" /* yacc.c:1646  */
    {
    (yyvsp[-2])->addChild((yyvsp[0]));
    (yyval) = (yyvsp[-2]);
}
#line 1957 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 279 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* fnode = new TreeNode(lineno, NODE_DECL);
    TreeNode* node = new TreeNode(lineno, NODE_DECL_VARS);
    node->addChild((yyvsp[0]));
    fnode->addChild(node);
    (yyval) = fnode;
}
#line 1969 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 286 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* fnode = new TreeNode(lineno, NODE_DECL);
    TreeNode* node = new TreeNode(lineno, NODE_INIT_DECL_VARS);
    node->addChild((yyvsp[-2]));
    node->addChild((yyvsp[0]));
    fnode->addChild(node);
    (yyval) = fnode;
}
#line 1982 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 297 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode(lineno, NODE_DECL_INIT);
    node->addChild((yyvsp[0]));
    //cout << "ckpt1\n";
    (yyval) = node;
    //cout << "ckpt2\n";
}
#line 1994 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 304 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode(lineno, NODE_DECL_INIT);
    node->addChild((yyvsp[-1]));
    (yyval) = node;
}
#line 2004 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 312 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
}
#line 2012 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 315 "src/main.y" /* yacc.c:1646  */
    {
    (yyvsp[-2])->addSibling((yyvsp[0]));
    (yyval) = (yyvsp[-2]);
}
#line 2021 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 324 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode(lineno, NODE_EXPR);
    node->addChild((yyvsp[0]));
    (yyval) = node;
}
#line 2031 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 329 "src/main.y" /* yacc.c:1646  */
    {
    //TreeNode* node = new TreeNode(lineno, NODE_EXPR);
    
    (yyvsp[-2])->addSibling((yyvsp[-1]));
    (yyval) = (yyvsp[-2]);
}
#line 2042 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 337 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_OP); (yyval)->optype = OP_ASSIGN;}
#line 2048 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 338 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_OP); (yyval)->optype = OP_AS_ADDEQ;}
#line 2054 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 339 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_OP); (yyval)->optype = OP_AS_ANDEQ;}
#line 2060 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 340 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_OP); (yyval)->optype = OP_AS_DIVEQ;}
#line 2066 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 341 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_OP); (yyval)->optype = OP_AS_MULEQ;}
#line 2072 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 342 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_OP); (yyval)->optype = OP_AS_OREQ;}
#line 2078 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 343 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_OP); (yyval)->optype = OP_AS_SFTL_EQ;}
#line 2084 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 344 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_OP); (yyval)->optype = OP_AS_SFTR_EQ;}
#line 2090 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 345 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_OP); (yyval)->optype = OP_AS_SUB_EQ;}
#line 2096 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 349 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
}
#line 2104 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 352 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-2])->lineno, NODE_EXPR);
    node-> optype = (yyvsp[-1])->optype;
    node-> addChild((yyvsp[-2]));
    node-> addChild((yyvsp[0]));
    //node-> addChild($2);
    (yyval) = node;
}
#line 2117 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 363 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
}
#line 2125 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 366 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-4])->lineno, NODE_EXPR);
    node -> optype = OP_CONDITION;
    node -> addChild((yyvsp[-4]));
    node -> addChild((yyvsp[-2]));
    node -> addChild((yyvsp[0]));
    (yyval) = node;
}
#line 2138 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 377 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
}
#line 2146 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 380 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-2])->lineno, NODE_EXPR);
    node -> optype = OP_LGC_OR;
    node -> addChild((yyvsp[-2]));
    node -> addChild((yyvsp[0]));
    (yyval) = node;
}
#line 2158 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 390 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
}
#line 2166 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 393 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-2])->lineno, NODE_EXPR);
    node -> optype = OP_LGC_AND;
    node -> addChild((yyvsp[-2]));
    node -> addChild((yyvsp[0]));
    (yyval) = node;
}
#line 2178 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 403 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
}
#line 2186 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 406 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-2])->lineno, NODE_EXPR);
    node -> optype = OP_BIT_OR;
    node -> addChild((yyvsp[-2]));
    node -> addChild((yyvsp[0]));
    (yyval) = node;
}
#line 2198 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 416 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
}
#line 2206 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 419 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-2])->lineno, NODE_EXPR);
    node -> optype = OP_BIT_XOR;
    node -> addChild((yyvsp[-2]));
    node -> addChild((yyvsp[0]));
    (yyval) = node;
}
#line 2218 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 429 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
}
#line 2226 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 432 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-2])->lineno, NODE_EXPR);
    node -> optype = OP_BIT_AND;
    node -> addChild((yyvsp[-2]));
    node -> addChild((yyvsp[0]));
    (yyval) = node;
}
#line 2238 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 442 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
}
#line 2246 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 445 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-2])->lineno, NODE_EXPR);
    node -> optype = OP_EQ;
    node -> addChild((yyvsp[-2]));
    node -> addChild((yyvsp[0]));
    (yyval) = node;
}
#line 2258 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 452 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-2])->lineno, NODE_EXPR);
    node -> optype = OP_N_EQ;
    node -> addChild((yyvsp[-2]));
    node -> addChild((yyvsp[0]));
    (yyval) = node;
}
#line 2270 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 462 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
}
#line 2278 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 465 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-2])->lineno, NODE_EXPR);
    node -> optype = OP_REL_L;
    node -> addChild((yyvsp[-2]));
    node -> addChild((yyvsp[0]));
    (yyval) = node;
}
#line 2290 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 472 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-2])->lineno, NODE_EXPR);
    node -> optype = OP_REL_G;
    node -> addChild((yyvsp[-2]));
    node -> addChild((yyvsp[0]));
    (yyval) = node;
}
#line 2302 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 479 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-2])->lineno, NODE_EXPR);
    node -> optype = OP_REL_LE;
    node -> addChild((yyvsp[-2]));
    node -> addChild((yyvsp[0]));
    (yyval) = node;
}
#line 2314 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 486 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-2])->lineno, NODE_EXPR);
    node -> optype = OP_REL_GE;
    node -> addChild((yyvsp[-2]));
    node -> addChild((yyvsp[0]));
    (yyval) = node;
}
#line 2326 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 496 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
}
#line 2334 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 499 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-2])->lineno, NODE_EXPR);
    node -> optype = OP_SFT_L;
    node -> addChild((yyvsp[-2]));
    node -> addChild((yyvsp[0]));
    (yyval) = node;
}
#line 2346 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 506 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-2])->lineno, NODE_EXPR);
    node -> optype = OP_SFT_R;
    node -> addChild((yyvsp[-2]));
    node -> addChild((yyvsp[0]));
    (yyval) = node;
}
#line 2358 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 516 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
}
#line 2366 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 519 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-2])->lineno, NODE_EXPR);
    node -> optype = OP_ADD;
    node -> addChild((yyvsp[-2]));
    node -> addChild((yyvsp[0]));
    (yyval) = node;
}
#line 2378 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 526 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-2])->lineno, NODE_EXPR);
    node -> optype = OP_SUB;
    node -> addChild((yyvsp[-2]));
    node -> addChild((yyvsp[0]));
    (yyval) = node;
}
#line 2390 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 536 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
}
#line 2398 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 539 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-2])->lineno, NODE_EXPR);
    node -> optype = OP_MUL;
    node -> addChild((yyvsp[-2]));
    node -> addChild((yyvsp[0]));
    (yyval) = node;
}
#line 2410 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 546 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-2])->lineno, NODE_EXPR);
    node -> optype = OP_DIV;
    node -> addChild((yyvsp[-2]));
    node -> addChild((yyvsp[0]));
    (yyval) = node;
}
#line 2422 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 553 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-2])->lineno, NODE_EXPR);
    node -> optype = OP_MOD;
    node -> addChild((yyvsp[-2]));
    node -> addChild((yyvsp[0]));
    (yyval) = node;
}
#line 2434 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 563 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
}
#line 2442 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 566 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-3])->lineno, NODE_EXPR);
    node -> optype = OP_CAST;
    node -> addChild((yyvsp[-2]));
    node -> addChild((yyvsp[-1]));
    (yyval) = node;
}
#line 2454 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 576 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_OP); (yyval)->optype = OP_UNA_REF;}
#line 2460 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 577 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_OP); (yyval)->optype = OP_UNA_DEREF;}
#line 2466 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 578 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_OP); (yyval)->optype = OP_POSITIVE;}
#line 2472 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 579 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_OP); (yyval)->optype = OP_MINUS;}
#line 2478 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 580 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_OP); (yyval)->optype = OP_BIT_NOT;}
#line 2484 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 581 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_OP); (yyval)->optype = OP_LGC_NOT;}
#line 2490 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 585 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
}
#line 2498 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 588 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-1])->lineno, NODE_EXPR);
    node -> optype = OP_PRESELFINC;
    node -> addChild((yyvsp[0]));
    (yyval) = node;
}
#line 2509 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 594 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-1])->lineno, NODE_EXPR);
    node -> optype = OP_PRESELFDEC;
    node -> addChild((yyvsp[0]));
    (yyval) = node;
}
#line 2520 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 600 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-1])->lineno, NODE_EXPR);
    node -> optype = (yyvsp[-1])->optype;
    //node -> addChild($1);
    node -> addChild((yyvsp[0]));
    (yyval) = node;
}
#line 2532 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 611 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
}
#line 2540 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 614 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-3])->lineno, NODE_EXPR);
    node -> optype = OP_OFFSET_ACCESS;
    node -> addChild((yyvsp[-3]));
    node -> addChild((yyvsp[-1]));
    (yyval) = node;
}
#line 2552 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 621 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-2])->lineno, NODE_EXPR);
    node -> optype = OP_AC_MEMBER;
    node -> addChild((yyvsp[-2]));
    node -> addChild((yyvsp[0]));
    (yyval) = node;
}
#line 2564 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 628 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-2])->lineno, NODE_EXPR);
    node -> optype = OP_PTAC_MEMBER;
    node -> addChild((yyvsp[-2]));
    node -> addChild((yyvsp[0]));
    (yyval) = node;
}
#line 2576 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 635 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-1])->lineno, NODE_EXPR);
    node -> optype = OP_POSTSELFINC;
    node -> addChild((yyvsp[-1]));
    (yyval) = node;
}
#line 2587 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 641 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-1])->lineno, NODE_EXPR);
    node -> optype = OP_POSTSELFDEC;
    node -> addChild((yyvsp[-1]));
    (yyval) = node;
}
#line 2598 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 647 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode(lineno, NODE_EXPR);
    //cout << "postfix func\n";
    node->optype = OP_FUNC_CALL;
    node->addChild((yyvsp[-3]));
    node->addChild((yyvsp[-1]));
    (yyval) = node;
}
#line 2611 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 655 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode(lineno, NODE_EXPR);
    TreeNode* augs = new TreeNode(lineno, NODE_ARGUMENT_LIST);
    node->optype = OP_FUNC_CALL;
    node->addChild((yyvsp[-2]));
    node->addChild(augs);
    (yyval) = node;
}
#line 2624 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 666 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode(lineno, NODE_ARGUMENT_LIST);
    node->addChild((yyvsp[0]));
    //cout << "ae\n";
    (yyval) = node;
}
#line 2635 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 672 "src/main.y" /* yacc.c:1646  */
    {
    //cout << "aes\n";
    (yyvsp[-2])->addChild((yyvsp[0]));
    (yyval) = (yyvsp[-2]);
}
#line 2645 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 680 "src/main.y" /* yacc.c:1646  */
    {
    //cout << "id\n";
    (yyval) = (yyvsp[0]);
}
#line 2654 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 684 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
}
#line 2662 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 687 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[-1]);
}
#line 2670 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 693 "src/main.y" /* yacc.c:1646  */
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
#line 2690 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 708 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
}
#line 2698 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 714 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_TYPE); (yyval)->type = TYPE_INT; }
#line 2704 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 715 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_TYPE); (yyval)->type = TYPE_CHAR;}
#line 2710 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 121:
#line 716 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_TYPE); (yyval)->type = TYPE_BOOL;}
#line 2716 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 122:
#line 717 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_TYPE); (yyval)->type = TYPE_VOID;}
#line 2722 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 123:
#line 718 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_TYPE); (yyval)->type = TYPE_SIGNED;}
#line 2728 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 124:
#line 719 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_TYPE); (yyval)->type = TYPE_UNSIGNED;}
#line 2734 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 125:
#line 720 "src/main.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 2740 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 126:
#line 724 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = NULL;
}
#line 2748 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 127:
#line 727 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = NULL;
}
#line 2756 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 128:
#line 730 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = NULL;
}
#line 2764 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 129:
#line 735 "src/main.y" /* yacc.c:1646  */
    {}
#line 2770 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 130:
#line 735 "src/main.y" /* yacc.c:1646  */
    {}
#line 2776 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 131:
#line 738 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = NULL;
}
#line 2784 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 132:
#line 741 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = NULL;
}
#line 2792 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 133:
#line 747 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = NULL;
    }
#line 2800 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 134:
#line 752 "src/main.y" /* yacc.c:1646  */
    {}
#line 2806 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 135:
#line 753 "src/main.y" /* yacc.c:1646  */
    {}
#line 2812 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 136:
#line 754 "src/main.y" /* yacc.c:1646  */
    {}
#line 2818 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 137:
#line 755 "src/main.y" /* yacc.c:1646  */
    {}
#line 2824 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 138:
#line 759 "src/main.y" /* yacc.c:1646  */
    {}
#line 2830 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 139:
#line 760 "src/main.y" /* yacc.c:1646  */
    {}
#line 2836 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 140:
#line 764 "src/main.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 2842 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 141:
#line 765 "src/main.y" /* yacc.c:1646  */
    {}
#line 2848 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 142:
#line 769 "src/main.y" /* yacc.c:1646  */
    {
        TreeNode*node = new TreeNode(lineno, NODE_PT_DECLARATOR);
        node->addChild((yyvsp[0]));
        (yyval) = node;
    }
#line 2858 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 143:
#line 774 "src/main.y" /* yacc.c:1646  */
    {
        TreeNode*node = new TreeNode(lineno, NODE_DECLARATOR);
        node->addChild((yyvsp[0]));
        (yyval) = node;
    }
#line 2868 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 144:
#line 782 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
}
#line 2876 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 145:
#line 785 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode(lineno, NODE_TYPE);
    node->type = TYPE_ARRAY;
    //cout << "ARRAY!!!\n";
    node->addChild((yyvsp[-3]));
    node->addChild((yyvsp[-1]));
    (yyval) = node;
}
#line 2889 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 146:
#line 793 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* fnode = new TreeNode(lineno, NODE_DECL);
    TreeNode* node = new TreeNode(lineno, NODE_DECL_FUNC);
    node->addChild((yyvsp[-3]));
    node->addChild((yyvsp[-1]));
    fnode->addChild(node);
    (yyval) = fnode;
}
#line 2902 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 147:
#line 801 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* fnode = new TreeNode(lineno, NODE_DECL);
    TreeNode* node = new TreeNode(lineno, NODE_DECL_FUNC);
    node->addChild((yyvsp[-2]));
    TreeNode* listnode = new TreeNode(lineno, NODE_PARA_DECL_LIST);
    node->addChild(listnode);
    fnode->addChild(node);
    (yyval) = fnode;
}
#line 2916 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 148:
#line 812 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode(lineno, NODE_PARA_DECL_LIST);
    //cout << "ck1";
    node->addChild((yyvsp[0]));
    (yyval) = node;
}
#line 2927 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 149:
#line 818 "src/main.y" /* yacc.c:1646  */
    {
    (yyvsp[-2])->addChild((yyvsp[0]));
    //cout << $1->nodeType;
    (yyval) = (yyvsp[-2]);
}
#line 2937 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 150:
#line 826 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode(lineno, NODE_PARA_DECL);
    TreeNode* node2 = new TreeNode(lineno, NODE_DECL_SPCF);
    
    node->addChild(node2); 
    node2->addChild((yyvsp[-1]));
    node->addChild((yyvsp[0]));
    (yyval) = node;
}
#line 2951 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 151:
#line 835 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode(lineno, NODE_PARA_DECL);
    TreeNode* node2 = new TreeNode(lineno, NODE_DECL_SPCF);
    
    node->addChild(node2); 
    node2->addChild((yyvsp[0]));
    (yyval) = node;
}
#line 2964 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 152:
#line 847 "src/main.y" /* yacc.c:1646  */
    {TreeNode* node = new TreeNode(lineno, NODE_TYPE); node->type = TYPE_POINTER; (yyval) = node;}
#line 2970 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 153:
#line 857 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = new TreeNode(lineno, NODE_TYPE); (yyval)->type = TYPE_CONST;
    }
#line 2978 "src/main.tab.cpp" /* yacc.c:1646  */
    break;


#line 2982 "src/main.tab.cpp" /* yacc.c:1646  */
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
#line 860 "src/main.y" /* yacc.c:1906  */






int yyerror(char const* message)
{
  cout << message << " at line " << lineno << endl;
  return -1;
}
