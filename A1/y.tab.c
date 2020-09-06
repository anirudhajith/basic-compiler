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
#line 6 "b.y" /* yacc.c:339  */

	#include <stdio.h>
	void yyerror(char *);
	int yylex(void);
	char mytext[100];

#line 73 "y.tab.c" /* yacc.c:339  */

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
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    IF = 258,
    ELSE = 259,
    WHILE = 260,
    DO = 261,
    FOR = 262,
    SWITCH = 263,
    CASE = 264,
    DEFAULT = 265,
    EXTERN = 266,
    STRUCT = 267,
    BREAK = 268,
    CONTINUE = 269,
    RETURN = 270,
    SIZEOF = 271,
    INT = 272,
    LONG = 273,
    SHORT = 274,
    FLOAT = 275,
    DOUBLE = 276,
    VOID = 277,
    CHAR = 278,
    IDENTIFIER = 279,
    RELATIONALOP = 280,
    LOGICALOP = 281,
    CREMENTOP = 282,
    EQ = 283,
    STRUCTFIELDACCESSOP = 284,
    DEREF = 285,
    ADDRESSOF = 286,
    CHARACTER = 287,
    NUMBER = 288,
    REALNUMBER = 289,
    STRING = 290
  };
#endif
/* Tokens.  */
#define IF 258
#define ELSE 259
#define WHILE 260
#define DO 261
#define FOR 262
#define SWITCH 263
#define CASE 264
#define DEFAULT 265
#define EXTERN 266
#define STRUCT 267
#define BREAK 268
#define CONTINUE 269
#define RETURN 270
#define SIZEOF 271
#define INT 272
#define LONG 273
#define SHORT 274
#define FLOAT 275
#define DOUBLE 276
#define VOID 277
#define CHAR 278
#define IDENTIFIER 279
#define RELATIONALOP 280
#define LOGICALOP 281
#define CREMENTOP 282
#define EQ 283
#define STRUCTFIELDACCESSOP 284
#define DEREF 285
#define ADDRESSOF 286
#define CHARACTER 287
#define NUMBER 288
#define REALNUMBER 289
#define STRING 290

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 194 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  94
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1054

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  50
/* YYNRULES -- Number of rules.  */
#define YYNRULES  146
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  254

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   290

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    53,     2,     2,     2,    52,    49,     2,
      42,    43,    47,    45,    38,    46,     2,    48,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    39,    44,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    40,     2,    41,    51,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    36,    50,    37,    54,     2,     2,     2,
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
      35
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    15,    15,    17,    18,    21,    22,    23,    26,    27,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    45,    46,    49,    50,    53,    55,    55,
      56,    57,    60,    61,    63,    64,    65,    67,    68,    71,
      72,    75,    76,    77,    78,    79,    80,    83,    84,    87,
      88,    91,    92,    93,    96,    97,   100,   101,   104,   105,
     108,   109,   111,   112,   113,   114,   115,   116,   117,   118,
     120,   121,   122,   123,   126,   127,   130,   131,   132,   133,
     134,   135,   137,   138,   139,   140,   143,   144,   145,   146,
     149,   150,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   178,   179,   181,   182,   183,   184,   185,
     186,   189,   191,   192,   193,   194,   197,   198,   201,   202,
     203,   204,   205,   208,   209,   210,   211,   212,   213,   214,
     215,   218,   219,   222,   223,   224,   225
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IF", "ELSE", "WHILE", "DO", "FOR",
  "SWITCH", "CASE", "DEFAULT", "EXTERN", "STRUCT", "BREAK", "CONTINUE",
  "RETURN", "SIZEOF", "INT", "LONG", "SHORT", "FLOAT", "DOUBLE", "VOID",
  "CHAR", "IDENTIFIER", "RELATIONALOP", "LOGICALOP", "CREMENTOP", "EQ",
  "STRUCTFIELDACCESSOP", "DEREF", "ADDRESSOF", "CHARACTER", "NUMBER",
  "REALNUMBER", "STRING", "'{'", "'}'", "','", "':'", "'['", "']'", "'('",
  "')'", "';'", "'+'", "'-'", "'*'", "'/'", "'&'", "'|'", "'^'", "'%'",
  "'!'", "'~'", "$accept", "program", "lines", "oneline", "statements",
  "statement", "block", "degenerableblock", "assignment", "declaration",
  "declarationlist", "case", "caselist", "defaultcase", "expressionlist",
  "argument", "argumentlist", "structmemberlist", "structmember",
  "functioncall", "functiondefinition", "functiondeclaration",
  "ifstatement", "forstatement", "whilestatement", "dowhilestatement",
  "switchstatement", "returnstatement", "functioncallstatement",
  "emptystatement", "breakstatement", "continuestatement",
  "variabledeclarationstatement", "structdeclarationstatement",
  "expressionstatment", "structdeclaration", "memberdeclaratation",
  "memberdeclaratationlist", "type", "primarytype", "binaryop", "deref",
  "unaryop", "addressof", "literal", "stringlist", "variable", "value",
  "sizeof", "expression", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   123,   125,    44,    58,
      91,    93,    40,    41,    59,    43,    45,    42,    47,    38,
     124,    94,    37,    33,   126
};
# endif

#define YYPACT_NINF -219

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-219)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     409,   -27,   -11,   357,    29,    65,  1029,    67,    18,    94,
       6,    69,  -219,  1029,  1029,  -219,  -219,  -219,  -219,    25,
     799,  -219,  -219,  -219,  -219,   487,  -219,  -219,  -219,  -219,
    -219,  -219,  -219,   134,   409,  -219,  -219,  -219,   -20,    98,
    -219,  -219,  -219,  -219,  -219,  -219,  -219,  -219,  -219,  -219,
    -219,  -219,  -219,  -219,  -219,    99,   121,   102,   799,  -219,
    -219,   115,  -219,    82,  -219,   190,   823,   823,   253,  -219,
    -219,   149,   131,   511,   823,  -219,   131,   120,  -219,  -219,
    -219,  -219,   122,   487,  -219,  -219,   131,   535,   559,   487,
     135,   118,    88,    71,  -219,  -219,   823,  -219,  -219,  -219,
      32,  -219,    19,   136,  -219,   128,   135,  -219,  -219,   823,
    -219,  -219,  -219,  -219,  -219,  -219,  -219,  -219,  -219,  -219,
     799,   835,   848,  -219,   305,  -219,   137,   583,    38,   863,
      49,  1005,  -219,   133,   876,  -219,  -219,   891,  -219,    35,
     139,   823,   799,  -219,   190,   448,   131,  -219,   823,  -219,
     190,   135,   357,   357,  -219,  -219,   823,   607,    50,   631,
     141,  -219,  -219,  -219,  1017,    -1,  -219,  -219,  -219,  -219,
     190,   135,    20,  -219,    37,   -12,  -219,   190,   174,  -219,
     904,   357,    60,   655,   679,    51,    10,  -219,  -219,   140,
    -219,    64,  -219,  -219,  -219,  1029,    22,   143,   160,   357,
     144,  -219,   357,   357,    62,   357,    87,   703,   823,   146,
    -219,   127,   150,  -219,   727,   165,  -219,  -219,  -219,  -219,
     751,   152,  -219,  -219,  -219,  -219,   357,  -219,   357,   357,
      90,   919,   357,  -219,  -219,  -219,   934,  -219,  -219,   947,
     775,  -219,  -219,  -219,   357,   357,   357,  -219,  -219,  -219,
     964,  -219,   357,  -219
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    93,    94,    95,    96,    97,    92,    98,   130,
       0,   122,   123,   124,   127,     0,    77,   115,   116,   118,
     121,   117,   120,     0,     2,     3,     5,   146,     0,   132,
       7,     6,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,   102,     0,    91,     0,   119,
     133,   125,   134,   143,   140,    40,     0,     0,     0,    26,
      25,     0,     0,     0,     0,   102,     0,   101,    78,    79,
      74,   132,     0,     0,    99,   100,     0,     0,     0,     0,
     137,     0,     0,     0,     1,     4,     0,    83,    76,    82,
     130,    31,     0,    28,   114,    90,   139,   126,   138,     0,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
       0,     0,     0,    24,     0,     9,     0,     0,     0,     0,
       0,     0,    75,     0,     0,   131,   129,     0,    54,     0,
       0,     0,     0,   135,    39,     0,     0,    80,     0,   113,
      27,   144,     0,     0,    23,     8,     0,     0,     0,     0,
       0,    81,    85,    89,     0,     0,   141,   142,   128,    55,
     145,   136,    54,    48,     0,     0,    30,    29,    60,    70,
       0,     0,     0,     0,     0,     0,     0,    84,    88,    51,
      87,     0,    50,    59,    57,     0,     0,    41,     0,     0,
       0,    69,     0,     0,     0,     0,     0,     0,     0,     0,
      73,    35,     0,    36,     0,     0,    86,    47,    58,    56,
       0,    42,    61,    71,    68,    67,     0,    65,     0,     0,
       0,     0,    38,    34,    72,    53,     0,    49,    43,     0,
       0,    66,    64,    63,     0,    33,    37,    52,    44,    45,
       0,    62,    32,    46
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -219,  -219,  -219,   156,  -218,    11,  -147,     5,  -219,    47,
     119,  -219,   -17,  -219,   -44,     2,  -219,  -219,   -15,     0,
    -219,  -219,  -219,  -219,  -219,  -219,  -219,  -219,  -219,  -219,
    -219,  -219,  -219,  -219,  -219,    -4,    34,  -219,     1,    -8,
    -219,  -219,  -219,    26,  -219,  -219,   -40,   -16,  -219,     3
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    33,    34,    35,   124,    69,    70,   125,    37,   101,
     102,   211,   212,   213,    38,   173,   174,   191,   192,    81,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,   163,   164,    72,    57,
     120,   105,    58,    59,    60,    61,    62,    63,    64,    65
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      39,    56,    75,    39,    90,    84,    85,    76,    71,    75,
      75,    36,   197,    82,   246,    66,   103,    92,    96,   208,
     209,    75,    11,   189,    97,   194,    91,   252,    93,   128,
      19,    67,   103,    20,    39,    56,   103,    30,    21,    22,
      23,    24,   106,   190,   139,    36,   135,   210,    25,   219,
      80,    27,    28,    29,    86,    30,    68,   146,    68,    31,
      32,    86,    78,   147,   193,    87,   218,    88,    39,   121,
     122,    73,    87,    96,   145,   195,    96,   129,   169,    75,
     196,   140,   159,   158,   133,    75,   134,   146,    96,    96,
     137,    77,    93,   161,   183,   207,   110,   111,    96,   144,
      96,   139,   215,   202,   151,   226,   103,    74,   216,   108,
     109,    83,   150,   182,   143,   185,   112,   113,   114,   115,
     116,   117,   118,   119,    39,    96,   171,    75,    96,   155,
     228,   142,   165,   244,    94,   104,   208,   209,    79,   204,
     206,    75,    98,    99,   170,   100,   175,   110,   111,   104,
     107,   177,    39,    39,   126,    19,   131,   178,   179,   180,
      75,   141,   108,   230,   148,   165,   132,   112,   113,   114,
     115,   116,   117,   118,   119,   149,   166,   186,   199,   156,
     214,    39,   142,   220,   221,   232,   201,   234,   223,   189,
      95,    75,   240,   176,   233,   130,   175,   217,   188,    39,
     237,   198,    39,    39,   222,    39,     0,   224,   225,     0,
     227,   231,     0,     0,     0,   110,   111,   236,     0,     0,
       0,     0,     0,   239,     0,     0,    39,     0,    39,    39,
       0,   241,    39,   242,   243,   112,   113,   114,   115,   116,
     117,   118,   119,   250,    39,    39,    39,     0,     0,   251,
       0,   155,    39,     0,     0,     0,     1,   155,     2,     3,
       4,     5,     0,     0,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,     0,     0,
      20,     0,     0,     0,     0,    21,    22,    23,    24,    68,
     123,     0,     0,     0,     0,    25,     0,    26,    27,    28,
      29,     0,    30,     0,     0,     0,    31,    32,     1,     0,
       2,     3,     4,     5,     0,     0,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
       0,     0,    20,     0,     0,     0,     0,    21,    22,    23,
      24,    68,   154,     0,     0,     0,     0,    25,     0,    26,
      27,    28,    29,     0,    30,     0,     0,     0,    31,    32,
       1,     0,     2,     3,     4,     5,     0,     0,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,     0,     0,    20,     0,     0,     0,     0,    21,
      22,    23,    24,    68,     0,     0,     0,     0,     0,    25,
       0,    26,    27,    28,    29,     0,    30,     0,     0,     0,
      31,    32,     1,     0,     2,     3,     4,     5,     0,     0,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,     0,     0,    20,     0,     0,     0,
       0,    21,    22,    23,    24,     0,     0,     0,     0,     0,
       0,    25,     0,    26,    27,    28,    29,     0,    30,     0,
       7,     0,    31,    32,    11,    12,    13,    14,    15,    16,
      17,    18,    19,     0,     0,    20,     0,     0,     0,     0,
      21,    22,    23,    24,     0,     0,     0,     0,     0,     0,
      25,   172,     0,    27,    28,    29,     0,    30,     0,     7,
       0,    31,    32,    11,    12,    13,    14,    15,    16,    17,
      18,    19,     0,     0,    20,     0,     0,     0,     0,    21,
      22,    23,    24,     0,     0,     0,     0,    11,     0,    25,
       0,     0,    27,    28,    29,    19,    30,     0,    20,     0,
      31,    32,     0,    21,    22,    23,    24,     0,     0,     0,
       0,    11,     0,    25,     0,   127,    27,    28,    29,    19,
      30,     0,    20,     0,    31,    32,     0,    21,    22,    23,
      24,     0,     0,     0,     0,    11,   136,    25,     0,     0,
      27,    28,    29,    19,    30,     0,    20,     0,    31,    32,
       0,    21,    22,    23,    24,     0,     0,     0,     0,    11,
       0,    25,   138,     0,    27,    28,    29,    19,    30,     0,
      20,     0,    31,    32,     0,    21,    22,    23,    24,     0,
       0,     0,     0,    11,     0,    25,     0,   157,    27,    28,
      29,    19,    30,     0,    20,     0,    31,    32,     0,    21,
      22,    23,    24,     0,     0,     0,     0,    11,     0,    25,
     181,     0,    27,    28,    29,    19,    30,     0,    20,     0,
      31,    32,     0,    21,    22,    23,    24,     0,     0,     0,
       0,    11,     0,    25,     0,   184,    27,    28,    29,    19,
      30,     0,    20,     0,    31,    32,     0,    21,    22,    23,
      24,     0,     0,     0,     0,    11,     0,    25,   203,     0,
      27,    28,    29,    19,    30,     0,    20,     0,    31,    32,
       0,    21,    22,    23,    24,     0,     0,     0,     0,    11,
       0,    25,   205,     0,    27,    28,    29,    19,    30,     0,
      20,     0,    31,    32,     0,    21,    22,    23,    24,     0,
       0,     0,     0,    11,     0,    25,   229,     0,    27,    28,
      29,    19,    30,     0,    20,     0,    31,    32,     0,    21,
      22,    23,    24,     0,     0,     0,     0,    11,   235,    25,
       0,     0,    27,    28,    29,    19,    30,     0,    20,     0,
      31,    32,     0,    21,    22,    23,    24,     0,     0,     0,
       0,    11,   238,    25,     0,     0,    27,    28,    29,    19,
      30,     0,    20,     0,    31,    32,     0,    21,    22,    23,
      24,     0,     0,     0,     0,    11,   249,    25,     0,     0,
      27,    28,    29,    19,    30,     0,    20,     0,    31,    32,
       0,    21,    22,    23,    24,     0,     0,     0,     0,    11,
       0,    89,     0,     0,    27,    28,    29,    19,    30,     0,
      20,     0,    31,    32,     0,    21,    22,    23,    24,     0,
     110,   111,     0,     0,     0,    25,     0,     0,    27,    28,
      29,     0,    30,   110,   111,     0,    31,    32,   152,     0,
     112,   113,   114,   115,   116,   117,   118,   119,   110,   111,
       0,   153,     0,   112,   113,   114,   115,   116,   117,   118,
     119,   110,   111,     0,     0,     0,   160,     0,   112,   113,
     114,   115,   116,   117,   118,   119,   110,   111,     0,   167,
       0,   112,   113,   114,   115,   116,   117,   118,   119,   110,
     111,     0,   168,     0,     0,     0,   112,   113,   114,   115,
     116,   117,   118,   119,   110,   111,     0,   200,     0,   112,
     113,   114,   115,   116,   117,   118,   119,     0,   245,   110,
     111,     0,     0,     0,   112,   113,   114,   115,   116,   117,
     118,   119,   110,   111,     0,   247,     0,     0,     0,   112,
     113,   114,   115,   116,   117,   118,   119,     0,   248,   110,
     111,     0,   112,   113,   114,   115,   116,   117,   118,   119,
       0,     0,     0,     0,     0,   253,     0,     0,     0,   112,
     113,   114,   115,   116,   117,   118,   119,     7,     0,     0,
       0,     0,    12,    13,    14,    15,    16,    17,    18,     7,
       0,     0,     0,     0,    12,    13,    14,    15,    16,    17,
      18,     7,   162,     0,     0,     0,    12,    13,    14,    15,
      16,    17,    18,     0,   187
};

static const yytype_int16 yycheck[] =
{
       0,     0,     6,     3,    20,    13,    14,     6,     3,    13,
      14,     0,    24,    10,   232,    42,    56,    25,    38,     9,
      10,    25,    16,    24,    44,   172,    25,   245,    25,    73,
      24,    42,    72,    27,    34,    34,    76,    49,    32,    33,
      34,    35,    58,    44,    88,    34,    86,    37,    42,   196,
      44,    45,    46,    47,    29,    49,    36,    38,    36,    53,
      54,    29,    44,    44,    44,    40,    44,    42,    68,    66,
      67,    42,    40,    38,    42,    38,    38,    74,    43,    83,
      43,    89,    44,   127,    83,    89,    83,    38,    38,    38,
      87,    24,    89,    44,    44,    44,    25,    26,    38,    96,
      38,   145,    38,    43,   120,    43,   146,    42,    44,    27,
      28,    42,   109,   157,    43,   159,    45,    46,    47,    48,
      49,    50,    51,    52,   124,    38,   142,   131,    38,   124,
      43,    43,   131,    43,     0,    47,     9,    10,    44,   183,
     184,   145,    44,    44,   141,    24,   145,    25,    26,    47,
      35,   148,   152,   153,     5,    24,    36,   152,   153,   156,
     164,    43,    27,   207,    28,   164,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    47,    43,    36,     4,    42,
      40,   181,    43,    40,    24,    39,   181,    37,    44,    24,
      34,   195,    40,   146,   211,    76,   195,   195,   164,   199,
     215,   175,   202,   203,   199,   205,    -1,   202,   203,    -1,
     205,   208,    -1,    -1,    -1,    25,    26,   214,    -1,    -1,
      -1,    -1,    -1,   220,    -1,    -1,   226,    -1,   228,   229,
      -1,   226,   232,   228,   229,    45,    46,    47,    48,    49,
      50,    51,    52,   240,   244,   245,   246,    -1,    -1,   244,
      -1,   246,   252,    -1,    -1,    -1,     3,   252,     5,     6,
       7,     8,    -1,    -1,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    -1,    -1,
      27,    -1,    -1,    -1,    -1,    32,    33,    34,    35,    36,
      37,    -1,    -1,    -1,    -1,    42,    -1,    44,    45,    46,
      47,    -1,    49,    -1,    -1,    -1,    53,    54,     3,    -1,
       5,     6,     7,     8,    -1,    -1,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      -1,    -1,    27,    -1,    -1,    -1,    -1,    32,    33,    34,
      35,    36,    37,    -1,    -1,    -1,    -1,    42,    -1,    44,
      45,    46,    47,    -1,    49,    -1,    -1,    -1,    53,    54,
       3,    -1,     5,     6,     7,     8,    -1,    -1,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    -1,    -1,    27,    -1,    -1,    -1,    -1,    32,
      33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,    42,
      -1,    44,    45,    46,    47,    -1,    49,    -1,    -1,    -1,
      53,    54,     3,    -1,     5,     6,     7,     8,    -1,    -1,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    -1,    -1,    27,    -1,    -1,    -1,
      -1,    32,    33,    34,    35,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    -1,    44,    45,    46,    47,    -1,    49,    -1,
      12,    -1,    53,    54,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    -1,    -1,    27,    -1,    -1,    -1,    -1,
      32,    33,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,
      42,    43,    -1,    45,    46,    47,    -1,    49,    -1,    12,
      -1,    53,    54,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    -1,    -1,    27,    -1,    -1,    -1,    -1,    32,
      33,    34,    35,    -1,    -1,    -1,    -1,    16,    -1,    42,
      -1,    -1,    45,    46,    47,    24,    49,    -1,    27,    -1,
      53,    54,    -1,    32,    33,    34,    35,    -1,    -1,    -1,
      -1,    16,    -1,    42,    -1,    44,    45,    46,    47,    24,
      49,    -1,    27,    -1,    53,    54,    -1,    32,    33,    34,
      35,    -1,    -1,    -1,    -1,    16,    41,    42,    -1,    -1,
      45,    46,    47,    24,    49,    -1,    27,    -1,    53,    54,
      -1,    32,    33,    34,    35,    -1,    -1,    -1,    -1,    16,
      -1,    42,    43,    -1,    45,    46,    47,    24,    49,    -1,
      27,    -1,    53,    54,    -1,    32,    33,    34,    35,    -1,
      -1,    -1,    -1,    16,    -1,    42,    -1,    44,    45,    46,
      47,    24,    49,    -1,    27,    -1,    53,    54,    -1,    32,
      33,    34,    35,    -1,    -1,    -1,    -1,    16,    -1,    42,
      43,    -1,    45,    46,    47,    24,    49,    -1,    27,    -1,
      53,    54,    -1,    32,    33,    34,    35,    -1,    -1,    -1,
      -1,    16,    -1,    42,    -1,    44,    45,    46,    47,    24,
      49,    -1,    27,    -1,    53,    54,    -1,    32,    33,    34,
      35,    -1,    -1,    -1,    -1,    16,    -1,    42,    43,    -1,
      45,    46,    47,    24,    49,    -1,    27,    -1,    53,    54,
      -1,    32,    33,    34,    35,    -1,    -1,    -1,    -1,    16,
      -1,    42,    43,    -1,    45,    46,    47,    24,    49,    -1,
      27,    -1,    53,    54,    -1,    32,    33,    34,    35,    -1,
      -1,    -1,    -1,    16,    -1,    42,    43,    -1,    45,    46,
      47,    24,    49,    -1,    27,    -1,    53,    54,    -1,    32,
      33,    34,    35,    -1,    -1,    -1,    -1,    16,    41,    42,
      -1,    -1,    45,    46,    47,    24,    49,    -1,    27,    -1,
      53,    54,    -1,    32,    33,    34,    35,    -1,    -1,    -1,
      -1,    16,    41,    42,    -1,    -1,    45,    46,    47,    24,
      49,    -1,    27,    -1,    53,    54,    -1,    32,    33,    34,
      35,    -1,    -1,    -1,    -1,    16,    41,    42,    -1,    -1,
      45,    46,    47,    24,    49,    -1,    27,    -1,    53,    54,
      -1,    32,    33,    34,    35,    -1,    -1,    -1,    -1,    16,
      -1,    42,    -1,    -1,    45,    46,    47,    24,    49,    -1,
      27,    -1,    53,    54,    -1,    32,    33,    34,    35,    -1,
      25,    26,    -1,    -1,    -1,    42,    -1,    -1,    45,    46,
      47,    -1,    49,    25,    26,    -1,    53,    54,    43,    -1,
      45,    46,    47,    48,    49,    50,    51,    52,    25,    26,
      -1,    43,    -1,    45,    46,    47,    48,    49,    50,    51,
      52,    25,    26,    -1,    -1,    -1,    43,    -1,    45,    46,
      47,    48,    49,    50,    51,    52,    25,    26,    -1,    43,
      -1,    45,    46,    47,    48,    49,    50,    51,    52,    25,
      26,    -1,    41,    -1,    -1,    -1,    45,    46,    47,    48,
      49,    50,    51,    52,    25,    26,    -1,    43,    -1,    45,
      46,    47,    48,    49,    50,    51,    52,    -1,    39,    25,
      26,    -1,    -1,    -1,    45,    46,    47,    48,    49,    50,
      51,    52,    25,    26,    -1,    41,    -1,    -1,    -1,    45,
      46,    47,    48,    49,    50,    51,    52,    -1,    41,    25,
      26,    -1,    45,    46,    47,    48,    49,    50,    51,    52,
      -1,    -1,    -1,    -1,    -1,    41,    -1,    -1,    -1,    45,
      46,    47,    48,    49,    50,    51,    52,    12,    -1,    -1,
      -1,    -1,    17,    18,    19,    20,    21,    22,    23,    12,
      -1,    -1,    -1,    -1,    17,    18,    19,    20,    21,    22,
      23,    12,    37,    -1,    -1,    -1,    17,    18,    19,    20,
      21,    22,    23,    -1,    37
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     5,     6,     7,     8,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      27,    32,    33,    34,    35,    42,    44,    45,    46,    47,
      49,    53,    54,    56,    57,    58,    60,    63,    69,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    93,    94,    97,    98,
      99,   100,   101,   102,   103,   104,    42,    42,    36,    60,
      61,    62,    93,    42,    42,    90,    93,    24,    44,    44,
      44,    74,   104,    42,    94,    94,    29,    40,    42,    42,
     102,    93,    94,   104,     0,    58,    38,    44,    44,    44,
      24,    64,    65,   101,    47,    96,   102,    35,    27,    28,
      25,    26,    45,    46,    47,    48,    49,    50,    51,    52,
      95,   104,   104,    37,    59,    62,     5,    44,    69,   104,
      65,    36,    44,    93,   104,   101,    41,   104,    43,    69,
      94,    43,    43,    43,   104,    42,    38,    44,    28,    47,
     104,   102,    43,    43,    37,    62,    42,    44,    69,    44,
      43,    44,    37,    91,    92,    93,    43,    43,    41,    43,
     104,   102,    43,    70,    71,    93,    64,   104,    62,    62,
     104,    43,    69,    44,    44,    69,    36,    37,    91,    24,
      44,    72,    73,    44,    61,    38,    43,    24,    98,     4,
      43,    62,    43,    43,    69,    43,    69,    44,     9,    10,
      37,    66,    67,    68,    40,    38,    44,    70,    44,    61,
      40,    24,    62,    44,    62,    62,    43,    62,    43,    43,
      69,   104,    39,    67,    37,    41,   104,    73,    41,   104,
      40,    62,    62,    62,    43,    39,    59,    41,    41,    41,
     104,    62,    59,    41
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    55,    56,    57,    57,    58,    58,    58,    59,    59,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    61,    61,    62,    62,    63,    64,    64,
      65,    65,    66,    66,    67,    67,    67,    68,    68,    69,
      69,    70,    70,    70,    70,    70,    70,    71,    71,    72,
      72,    73,    73,    73,    74,    74,    75,    75,    76,    76,
      77,    77,    78,    78,    78,    78,    78,    78,    78,    78,
      79,    80,    81,    81,    82,    82,    83,    84,    85,    86,
      87,    87,    88,    89,    90,    90,    91,    91,    92,    92,
      93,    93,    94,    94,    94,    94,    94,    94,    94,    94,
      94,    94,    94,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    96,    96,    97,    97,    97,    97,    97,
      97,    98,    99,    99,    99,    99,   100,   100,   101,   101,
     101,   101,   101,   102,   102,   102,   102,   102,   102,   102,
     102,   103,   103,   104,   104,   104,   104
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     2,     1,     1,     3,     1,     3,
       3,     1,     4,     3,     2,     1,     1,     3,     2,     3,
       1,     2,     3,     4,     5,     5,     6,     3,     1,     3,
       1,     1,     4,     3,     3,     4,     6,     5,     6,     5,
       5,     7,     9,     8,     8,     7,     8,     7,     7,     6,
       5,     7,     7,     6,     2,     3,     2,     1,     2,     2,
       3,     4,     2,     2,     5,     4,     3,     2,     2,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     1,     4,     3,
       1,     3,     1,     1,     1,     3,     4,     2,     2,     2,
       1,     4,     4,     1,     3,     4,     1
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
      
#line 1619 "y.tab.c" /* yacc.c:1646  */
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
#line 229 "b.y" /* yacc.c:1906  */


void yyerror(char *s) {
    fprintf(stderr, "%s\n", s);
}

int main(void) {
    yyparse();
	fprintf(stdout, "parsed successfully\n");
    return 0;
}

