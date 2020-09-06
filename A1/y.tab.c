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
	int numGlobalDeclarations = 0;
	int numFunctionDefinitions = 0;
	int numIntegerConstants = 0;
	int numPointerDeclarations = 0;
	int numIfWithoutElse = 0;
	int maxHeight = 0;
	int error = 0;

	int max(int a, int b) {
		printf("%d %d\n", a, b);
		if (a > b) return a;
		else return b;
	}

#line 86 "y.tab.c" /* yacc.c:339  */

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

#line 207 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  25
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   895

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  54
/* YYNRULES -- Number of rules.  */
#define YYNRULES  162
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  264

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
static const yytype_uint16 yyrline[] =
{
       0,    28,    28,    30,    31,    34,    35,    36,    37,    40,
      41,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    73,    74,    77,    78,
      81,    83,    83,    84,    85,    88,    89,    91,    92,    93,
      95,    96,    99,   100,   103,   104,   105,   106,   109,   110,
     113,   114,   117,   118,   121,   122,   125,   126,   129,   130,
     133,   134,   137,   138,   141,   142,   143,   144,   147,   148,
     149,   150,   151,   152,   153,   154,   156,   157,   158,   159,
     162,   163,   166,   167,   168,   169,   170,   171,   173,   174,
     175,   176,   179,   180,   181,   182,   185,   186,   189,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     216,   217,   219,   220,   221,   222,   223,   224,   227,   229,
     230,   231,   232,   235,   236,   239,   240,   241,   242,   245,
     246,   247,   248,   249,   250,   251,   252,   255,   256,   259,
     260,   261,   262
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
  "statement", "nonifstatement", "block", "degenerableblock", "assignment",
  "declaration", "declarationlist", "case", "caselist", "defaultcase",
  "expressionlist", "argument", "arrayindexlist", "arrayindex",
  "argumentlist", "structmemberlist", "structmember", "functioncall",
  "functiondefinition", "functiondeclaration", "ifstatement",
  "forstatement", "whilestatement", "dowhilestatement", "switchstatement",
  "returnstatement", "functioncallstatement", "emptystatement",
  "breakstatement", "continuestatement", "variabledeclarationstatement",
  "structdeclarationstatement", "expressionstatment", "structdeclaration",
  "memberdeclaratation", "memberdeclaratationlist", "type", "castingtype",
  "primarytype", "binaryop", "deref", "unaryop", "addressof", "literal",
  "stringlist", "variable", "value", "sizeof", "expression", YY_NULLPTR
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

#define YYPACT_NINF -224

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-224)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      93,   209,    21,  -224,   209,   209,  -224,  -224,  -224,  -224,
      20,    93,  -224,  -224,  -224,  -224,  -224,    -8,    43,    -6,
    -224,    46,    87,  -224,  -224,  -224,  -224,  -224,    75,  -224,
      10,  -224,    -2,  -224,    89,    92,    19,   846,   393,    46,
    -224,   672,    46,   171,    97,  -224,  -224,   456,  -224,  -224,
    -224,   858,     5,    96,   696,  -224,  -224,  -224,  -224,   432,
       6,  -224,  -224,  -224,  -224,  -224,  -224,  -224,    -4,  -224,
      57,   -16,   696,  -224,  -224,   107,    -5,    16,  -224,   805,
    -224,   805,    -5,  -224,    33,  -224,  -224,  -224,  -224,    97,
    -224,    22,  -224,   432,   432,   117,   102,    55,   708,   250,
    -224,  -224,   672,  -224,   209,    17,    97,   124,   117,  -224,
    -224,   672,  -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,
    -224,  -224,   696,  -224,    97,   125,  -224,   111,   721,   114,
     672,   696,    89,  -224,   116,   121,   354,   126,   128,   115,
     122,   480,  -224,  -224,   302,  -224,  -224,  -224,    24,   127,
    -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,
    -224,  -224,  -224,    46,   805,  -224,  -224,  -224,    97,    97,
     805,   117,  -224,  -224,  -224,   805,   117,   672,   672,   156,
     504,   672,  -224,  -224,  -224,   736,  -224,  -224,  -224,  -224,
      97,   749,   764,   130,   528,    49,   777,  -224,   354,   354,
     672,   552,    50,   576,   137,   170,  -224,   792,   354,    58,
     600,   624,    53,     9,   354,   134,  -224,   354,   354,    81,
     354,    82,   648,   672,   140,  -224,   119,   144,  -224,  -224,
    -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,
    -224,  -224,  -224,  -224,  -224,  -224,  -224,   354,  -224,   354,
     354,    83,   197,   354,  -224,  -224,  -224,  -224,  -224,   354,
     354,   354,  -224,   354
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,   110,   111,   112,   113,   114,   109,   115,
       0,     2,     3,     8,     6,     5,     7,   119,     0,   107,
     119,     0,   118,   116,   117,     1,     4,    98,   146,    44,
       0,   148,    41,   131,   106,   146,     0,     0,     0,     0,
      96,     0,     0,     0,   145,    59,   130,     0,    97,   101,
     105,     0,     0,     0,     0,   139,   140,   141,   144,     0,
      68,   132,   133,   135,   138,   134,   137,   162,     0,    63,
       0,     0,     0,   136,   149,   142,   150,   159,   156,    53,
      43,    42,   147,    60,     0,    58,    68,   100,   104,    66,
     103,     0,    65,     0,     0,   153,     0,     0,     0,     0,
      73,    71,     0,    69,     0,     0,    54,     0,   155,   143,
     154,     0,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,     0,    61,    67,     0,   102,     0,     0,     0,
       0,     0,   108,   151,     0,     0,     0,     0,     0,     0,
       0,     0,    37,    93,     0,    39,    38,    10,     0,   148,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,     0,    52,    62,    72,    70,    56,    55,
      40,   160,    64,   157,   158,   161,   152,     0,     0,     0,
       0,     0,    94,    95,    90,     0,    36,     9,    99,    92,
      57,     0,     0,     0,     0,     0,     0,    91,     0,     0,
       0,     0,     0,     0,     0,    74,    86,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    85,     0,     0,     0,
       0,     0,     0,     0,     0,    89,    48,     0,    49,    75,
      77,    76,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    87,    84,    83,     0,    81,     0,
       0,     0,     0,    51,    47,    88,    82,    80,    79,     0,
      46,    50,    78,    45
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -224,  -224,  -224,   173,  -223,  -224,  -224,   -58,    -9,  -224,
     152,   176,  -224,   -26,  -224,   -34,    98,   -83,   -35,  -224,
    -224,    76,   -67,  -224,  -224,    -7,    23,    25,    37,    45,
      61,    62,    64,    65,    66,     0,     1,    67,    71,   159,
    -224,    14,  -224,    12,  -224,   136,  -224,   148,  -224,  -224,
     -11,   -32,  -224,   -38
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    10,    11,    12,   144,   145,   229,   146,   147,    67,
      29,    30,   226,   227,   228,   148,    69,    44,    45,    70,
      91,    92,    31,    13,    14,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,    17,    50,
      51,   163,    96,    19,   122,    34,    72,    73,    74,    75,
      76,    77,    78,    79
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
      15,    16,   101,    81,    68,    84,   124,    32,   106,    85,
      32,    15,    16,    68,    18,    21,    23,    24,   223,   224,
      25,    98,    95,   168,    42,    18,    41,    42,    32,    89,
     261,    82,   149,    64,   102,    43,    27,   263,    43,   103,
     108,    33,    99,   110,   111,    22,   225,   167,    39,    90,
     100,    52,    71,    99,    40,   128,    98,    39,   112,   113,
     125,   166,   102,    48,   164,    52,   126,    28,   188,   149,
      35,    97,    20,   170,   123,    20,    20,   149,   114,   115,
     116,   117,   118,   119,   120,   121,   190,   102,   102,    85,
     171,   102,   175,   203,   210,   104,   102,   222,   131,   176,
     105,   217,    33,   185,     1,     2,   129,   127,    20,    20,
       3,     4,     5,     6,     7,     8,     9,    38,    71,   102,
     102,   102,    20,    37,   247,   249,   259,   179,   223,   224,
      20,   149,   149,    85,    47,   187,    46,    43,    93,   191,
     192,   149,   109,   196,   110,   130,   195,   149,   169,    89,
     149,   149,    32,   149,   173,    85,   230,   131,   177,   182,
     202,   193,   207,   178,    20,    20,   183,   209,   180,   212,
     181,   189,   200,   213,   214,    20,   219,   221,   244,   253,
     149,   255,   149,   149,    26,   252,   149,    53,   251,   205,
     206,    80,   149,   149,   149,    35,   149,    36,    54,   216,
     254,   172,   165,    55,    56,    57,    58,   231,   245,   246,
      88,   248,    83,    59,   241,   242,    61,    62,    63,   107,
      64,     2,   112,   113,    65,    66,     3,     4,     5,     6,
       7,     8,     9,   132,     0,     0,   260,   232,   256,   233,
     257,   258,   114,   115,   116,   117,   118,   119,   120,   121,
     262,   234,   187,   134,   187,   135,   136,   137,   138,   235,
       0,     1,     2,   139,   140,   141,    53,     3,     4,     5,
       6,     7,     8,     9,    35,   236,   237,    54,   238,   239,
     240,   243,    55,    56,    57,    58,    99,   142,     0,     0,
       0,     0,    59,     0,   143,    61,    62,    63,     0,    64,
       0,     0,     0,    65,    66,   134,     0,   135,   136,   137,
     138,     0,     0,     1,     2,   139,   140,   141,    53,     3,
       4,     5,     6,     7,     8,     9,    35,     0,     0,    54,
       0,     0,     0,     0,    55,    56,    57,    58,    99,   186,
       0,     0,     0,     0,    59,     0,   143,    61,    62,    63,
       0,    64,     0,     0,     0,    65,    66,   134,     0,   135,
     136,   137,   138,     0,     0,     1,     2,   139,   140,   141,
      53,     3,     4,     5,     6,     7,     8,     9,    35,     0,
       0,    54,     0,     0,     0,     0,    55,    56,    57,    58,
      99,     0,     0,     0,     0,     0,    59,     0,   143,    61,
      62,    63,     0,    64,     0,     2,     0,    65,    66,    53,
       3,     4,     5,     6,     7,     8,     9,    35,     0,     0,
      54,     0,     0,     0,     0,    55,    56,    57,    58,     0,
       0,     0,     0,     0,     0,    59,    60,     0,    61,    62,
      63,     0,    64,     0,     2,     0,    65,    66,    53,     3,
       4,     5,     6,     7,     8,     9,    35,     0,     0,    54,
       0,     0,     0,     0,    55,    56,    57,    58,     0,     0,
       0,     0,    53,     0,    59,     0,     0,    61,    62,    63,
      35,    64,     0,    54,     0,    65,    66,     0,    55,    56,
      57,    58,     0,     0,     0,     0,    53,     0,    59,    86,
       0,    61,    62,    63,    35,    64,     0,    54,     0,    65,
      66,     0,    55,    56,    57,    58,     0,     0,     0,     0,
      53,     0,    59,     0,   184,    61,    62,    63,    35,    64,
       0,    54,     0,    65,    66,     0,    55,    56,    57,    58,
       0,     0,     0,     0,    53,     0,    59,     0,   194,    61,
      62,    63,    35,    64,     0,    54,     0,    65,    66,     0,
      55,    56,    57,    58,     0,     0,     0,     0,    53,     0,
      59,     0,   201,    61,    62,    63,    35,    64,     0,    54,
       0,    65,    66,     0,    55,    56,    57,    58,     0,     0,
       0,     0,    53,     0,    59,   208,     0,    61,    62,    63,
      35,    64,     0,    54,     0,    65,    66,     0,    55,    56,
      57,    58,     0,     0,     0,     0,    53,     0,    59,     0,
     211,    61,    62,    63,    35,    64,     0,    54,     0,    65,
      66,     0,    55,    56,    57,    58,     0,     0,     0,     0,
      53,     0,    59,   218,     0,    61,    62,    63,    35,    64,
       0,    54,     0,    65,    66,     0,    55,    56,    57,    58,
       0,     0,     0,     0,    53,     0,    59,   220,     0,    61,
      62,    63,    35,    64,     0,    54,     0,    65,    66,     0,
      55,    56,    57,    58,     0,     0,     0,     0,    53,     0,
      59,   250,     0,    61,    62,    63,    35,    64,     0,    54,
       0,    65,    66,     0,    55,    56,    57,    58,     0,     0,
       0,     0,    53,     0,    59,     0,     0,    61,    62,    63,
      35,    64,     0,    54,     0,    65,    66,     0,    55,    56,
      57,    58,     0,   112,   113,     0,     0,     0,    94,     0,
       0,    61,    62,    63,     0,    64,   112,   113,     0,    65,
      66,   133,     0,   114,   115,   116,   117,   118,   119,   120,
     121,   112,   113,     0,   174,     0,   114,   115,   116,   117,
     118,   119,   120,   121,   112,   113,     0,     0,     0,     0,
     197,   114,   115,   116,   117,   118,   119,   120,   121,   112,
     113,     0,   198,     0,   114,   115,   116,   117,   118,   119,
     120,   121,   112,   113,     0,     0,     0,   199,     0,   114,
     115,   116,   117,   118,   119,   120,   121,   112,   113,     0,
     204,     0,   114,   115,   116,   117,   118,   119,   120,   121,
     112,   113,     0,     0,     0,   215,     0,   114,   115,   116,
     117,   118,   119,   120,   121,     0,     0,     0,     0,     0,
     114,   115,   116,   117,   118,   119,   120,   121,     2,     0,
       0,     0,     0,     3,     4,     5,     6,     7,     8,     9,
       2,     0,     0,     0,     0,     3,     4,     5,     6,     7,
       8,     9,     0,    49,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    87
};

static const yytype_int16 yycheck[] =
{
       0,     0,    60,    41,    38,    43,    89,    18,    24,    44,
      21,    11,    11,    47,     0,     1,     4,     5,     9,    10,
       0,    59,    54,   106,    29,    11,    28,    29,    39,    24,
     253,    42,    99,    49,    38,    40,    44,   260,    40,    43,
      72,    47,    36,    27,    28,    24,    37,   105,    38,    44,
      44,    37,    38,    36,    44,    93,    94,    38,    25,    26,
      38,    44,    38,    44,   102,    51,    44,    24,    44,   136,
      24,    59,     1,   111,    41,     4,     5,   144,    45,    46,
      47,    48,    49,    50,    51,    52,   169,    38,    38,   124,
     122,    38,   130,    44,    44,    38,    38,    44,    43,   131,
      43,    43,    47,   141,    11,    12,    94,    93,    37,    38,
      17,    18,    19,    20,    21,    22,    23,    42,   104,    38,
      38,    38,    51,    36,    43,    43,    43,   136,     9,    10,
      59,   198,   199,   168,    42,   144,    47,    40,    42,   177,
     178,   208,    35,   181,    27,    43,   180,   214,    24,    24,
     217,   218,   163,   220,    43,   190,   214,    43,    42,    44,
     194,     5,   200,    42,    93,    94,    44,   201,    42,   203,
      42,    44,    42,    36,     4,   104,   210,   211,    44,    39,
     247,    37,   249,   250,    11,   223,   253,    16,   222,   198,
     199,    39,   259,   260,   261,    24,   263,    21,    27,   208,
     226,   125,   104,    32,    33,    34,    35,   214,   217,   218,
      51,   220,    41,    42,   214,   214,    45,    46,    47,    71,
      49,    12,    25,    26,    53,    54,    17,    18,    19,    20,
      21,    22,    23,    97,    -1,    -1,    39,   214,   247,   214,
     249,   250,    45,    46,    47,    48,    49,    50,    51,    52,
     259,   214,   261,     3,   263,     5,     6,     7,     8,   214,
      -1,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,   214,   214,    27,   214,   214,
     214,   214,    32,    33,    34,    35,    36,    37,    -1,    -1,
      -1,    -1,    42,    -1,    44,    45,    46,    47,    -1,    49,
      -1,    -1,    -1,    53,    54,     3,    -1,     5,     6,     7,
       8,    -1,    -1,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    -1,    -1,    27,
      -1,    -1,    -1,    -1,    32,    33,    34,    35,    36,    37,
      -1,    -1,    -1,    -1,    42,    -1,    44,    45,    46,    47,
      -1,    49,    -1,    -1,    -1,    53,    54,     3,    -1,     5,
       6,     7,     8,    -1,    -1,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    -1,
      -1,    27,    -1,    -1,    -1,    -1,    32,    33,    34,    35,
      36,    -1,    -1,    -1,    -1,    -1,    42,    -1,    44,    45,
      46,    47,    -1,    49,    -1,    12,    -1,    53,    54,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    -1,    -1,
      27,    -1,    -1,    -1,    -1,    32,    33,    34,    35,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    43,    -1,    45,    46,
      47,    -1,    49,    -1,    12,    -1,    53,    54,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    -1,    -1,    27,
      -1,    -1,    -1,    -1,    32,    33,    34,    35,    -1,    -1,
      -1,    -1,    16,    -1,    42,    -1,    -1,    45,    46,    47,
      24,    49,    -1,    27,    -1,    53,    54,    -1,    32,    33,
      34,    35,    -1,    -1,    -1,    -1,    16,    -1,    42,    43,
      -1,    45,    46,    47,    24,    49,    -1,    27,    -1,    53,
      54,    -1,    32,    33,    34,    35,    -1,    -1,    -1,    -1,
      16,    -1,    42,    -1,    44,    45,    46,    47,    24,    49,
      -1,    27,    -1,    53,    54,    -1,    32,    33,    34,    35,
      -1,    -1,    -1,    -1,    16,    -1,    42,    -1,    44,    45,
      46,    47,    24,    49,    -1,    27,    -1,    53,    54,    -1,
      32,    33,    34,    35,    -1,    -1,    -1,    -1,    16,    -1,
      42,    -1,    44,    45,    46,    47,    24,    49,    -1,    27,
      -1,    53,    54,    -1,    32,    33,    34,    35,    -1,    -1,
      -1,    -1,    16,    -1,    42,    43,    -1,    45,    46,    47,
      24,    49,    -1,    27,    -1,    53,    54,    -1,    32,    33,
      34,    35,    -1,    -1,    -1,    -1,    16,    -1,    42,    -1,
      44,    45,    46,    47,    24,    49,    -1,    27,    -1,    53,
      54,    -1,    32,    33,    34,    35,    -1,    -1,    -1,    -1,
      16,    -1,    42,    43,    -1,    45,    46,    47,    24,    49,
      -1,    27,    -1,    53,    54,    -1,    32,    33,    34,    35,
      -1,    -1,    -1,    -1,    16,    -1,    42,    43,    -1,    45,
      46,    47,    24,    49,    -1,    27,    -1,    53,    54,    -1,
      32,    33,    34,    35,    -1,    -1,    -1,    -1,    16,    -1,
      42,    43,    -1,    45,    46,    47,    24,    49,    -1,    27,
      -1,    53,    54,    -1,    32,    33,    34,    35,    -1,    -1,
      -1,    -1,    16,    -1,    42,    -1,    -1,    45,    46,    47,
      24,    49,    -1,    27,    -1,    53,    54,    -1,    32,    33,
      34,    35,    -1,    25,    26,    -1,    -1,    -1,    42,    -1,
      -1,    45,    46,    47,    -1,    49,    25,    26,    -1,    53,
      54,    43,    -1,    45,    46,    47,    48,    49,    50,    51,
      52,    25,    26,    -1,    43,    -1,    45,    46,    47,    48,
      49,    50,    51,    52,    25,    26,    -1,    -1,    -1,    -1,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    25,
      26,    -1,    43,    -1,    45,    46,    47,    48,    49,    50,
      51,    52,    25,    26,    -1,    -1,    -1,    43,    -1,    45,
      46,    47,    48,    49,    50,    51,    52,    25,    26,    -1,
      43,    -1,    45,    46,    47,    48,    49,    50,    51,    52,
      25,    26,    -1,    -1,    -1,    43,    -1,    45,    46,    47,
      48,    49,    50,    51,    52,    -1,    -1,    -1,    -1,    -1,
      45,    46,    47,    48,    49,    50,    51,    52,    12,    -1,
      -1,    -1,    -1,    17,    18,    19,    20,    21,    22,    23,
      12,    -1,    -1,    -1,    -1,    17,    18,    19,    20,    21,
      22,    23,    -1,    37,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    37
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    11,    12,    17,    18,    19,    20,    21,    22,    23,
      56,    57,    58,    78,    79,    90,    91,    93,    96,    98,
      93,    96,    24,    98,    98,     0,    58,    44,    24,    65,
      66,    77,   105,    47,   100,    24,    66,    36,    42,    38,
      44,    28,    29,    40,    72,    73,    47,    42,    44,    37,
      94,    95,    96,    16,    27,    32,    33,    34,    35,    42,
      43,    45,    46,    47,    49,    53,    54,    64,    70,    71,
      74,    96,   101,   102,   103,   104,   105,   106,   107,   108,
      65,   108,   105,    41,   108,    73,    43,    37,    94,    24,
      44,    75,    76,    42,    42,   106,    97,    98,   108,    36,
      44,    62,    38,    43,    38,    43,    24,   102,   106,    35,
      27,    28,    25,    26,    45,    46,    47,    48,    49,    50,
      51,    52,    99,    41,    72,    38,    44,    96,   108,    98,
      43,    43,   100,    43,     3,     5,     6,     7,     8,    13,
      14,    15,    37,    44,    59,    60,    62,    63,    70,    77,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    96,   108,    71,    44,    62,    72,    24,
     108,   106,    76,    43,    43,   108,   106,    42,    42,    63,
      42,    42,    44,    44,    44,   108,    37,    63,    44,    44,
      72,   108,   108,     5,    44,    70,   108,    44,    43,    43,
      42,    44,    70,    44,    43,    63,    63,   108,    43,    70,
      44,    44,    70,    36,     4,    43,    63,    43,    43,    70,
      43,    70,    44,     9,    10,    37,    67,    68,    69,    61,
      62,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    44,    63,    63,    43,    63,    43,
      43,    70,   108,    39,    68,    37,    63,    63,    63,    43,
      39,    59,    63,    59
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    55,    56,    57,    57,    58,    58,    58,    58,    59,
      59,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    62,    62,    63,    63,
      64,    65,    65,    66,    66,    67,    67,    68,    68,    68,
      69,    69,    70,    70,    71,    71,    71,    71,    72,    72,
      73,    73,    74,    74,    75,    75,    76,    76,    77,    77,
      78,    78,    79,    79,    80,    80,    80,    80,    81,    81,
      81,    81,    81,    81,    81,    81,    82,    83,    84,    84,
      85,    85,    86,    87,    88,    89,    90,    90,    91,    92,
      93,    93,    94,    94,    95,    95,    96,    96,    97,    98,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    98,
      99,    99,    99,    99,    99,    99,    99,    99,    99,    99,
     100,   100,   101,   101,   101,   101,   101,   101,   102,   103,
     103,   103,   103,   104,   104,   105,   105,   105,   105,   106,
     106,   106,   106,   106,   106,   106,   106,   107,   107,   108,
     108,   108,   108
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     2,     1,     1,
       3,     1,     3,     3,     1,     4,     3,     2,     1,     1,
       3,     2,     3,     1,     2,     3,     3,     4,     2,     1,
       2,     3,     3,     1,     3,     1,     1,     2,     3,     4,
       6,     5,     6,     5,     5,     7,     7,     7,     9,     8,
       8,     7,     8,     7,     7,     6,     5,     7,     7,     6,
       2,     3,     2,     1,     2,     2,     3,     4,     2,     2,
       5,     4,     3,     2,     2,     1,     2,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     2,     1,     3,     1,     1,
       1,     3,     4,     2,     2,     2,     1,     4,     4,     1,
       3,     4,     1
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
        case 3:
#line 30 "b.y" /* yacc.c:1646  */
    { numGlobalDeclarations++; }
#line 1613 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 31 "b.y" /* yacc.c:1646  */
    { numGlobalDeclarations++; }
#line 1619 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 37 "b.y" /* yacc.c:1646  */
    { numFunctionDefinitions++; }
#line 1625 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 40 "b.y" /* yacc.c:1646  */
    { (yyval) = max((yyvsp[-1]), (yyvsp[0])); maxHeight = max(maxHeight, (yyval)); }
#line 1631 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 41 "b.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); maxHeight = max(maxHeight, (yyval)); }
#line 1637 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 44 "b.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); maxHeight = max(maxHeight, (yyval)); }
#line 1643 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 45 "b.y" /* yacc.c:1646  */
    { (yyval) = 0; maxHeight = max(maxHeight, (yyval)); }
#line 1649 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 46 "b.y" /* yacc.c:1646  */
    { (yyval) = 0; maxHeight = max(maxHeight, (yyval)); }
#line 1655 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 47 "b.y" /* yacc.c:1646  */
    { (yyval) = 0; maxHeight = max(maxHeight, (yyval)); }
#line 1661 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 48 "b.y" /* yacc.c:1646  */
    { (yyval) = 0; maxHeight = max(maxHeight, (yyval)); }
#line 1667 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 49 "b.y" /* yacc.c:1646  */
    { (yyval) = 0; maxHeight = max(maxHeight, (yyval)); }
#line 1673 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 50 "b.y" /* yacc.c:1646  */
    { (yyval) = 0; maxHeight = max(maxHeight, (yyval)); }
#line 1679 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 51 "b.y" /* yacc.c:1646  */
    { (yyval) = 0; maxHeight = max(maxHeight, (yyval)); }
#line 1685 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 52 "b.y" /* yacc.c:1646  */
    { (yyval) = 0; maxHeight = max(maxHeight, (yyval)); }
#line 1691 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 53 "b.y" /* yacc.c:1646  */
    { (yyval) = 0; maxHeight = max(maxHeight, (yyval)); }
#line 1697 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 54 "b.y" /* yacc.c:1646  */
    { (yyval) = 0; maxHeight = max(maxHeight, (yyval)); }
#line 1703 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 55 "b.y" /* yacc.c:1646  */
    { (yyval) = 0; maxHeight = max(maxHeight, (yyval)); }
#line 1709 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 56 "b.y" /* yacc.c:1646  */
    { (yyval) = 0; maxHeight = max(maxHeight, (yyval)); }
#line 1715 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 73 "b.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]); maxHeight = max(maxHeight, (yyval)); }
#line 1721 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 74 "b.y" /* yacc.c:1646  */
    { (yyval) = 0; maxHeight = max(maxHeight, (yyval)); }
#line 1727 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 77 "b.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); maxHeight = max(maxHeight, (yyval)); }
#line 1733 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 78 "b.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); maxHeight = max(maxHeight, (yyval)); }
#line 1739 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 141 "b.y" /* yacc.c:1646  */
    { numIfWithoutElse++; (yyval) = (yyvsp[0]); maxHeight = max(maxHeight, (yyval)); }
#line 1745 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 142 "b.y" /* yacc.c:1646  */
    { (yyval) = max(1,(yyvsp[-2])); maxHeight = max(maxHeight, (yyval)); }
#line 1751 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 143 "b.y" /* yacc.c:1646  */
    { (yyval) = max((yyvsp[0]) + 1,(yyvsp[-2])); maxHeight = max(maxHeight, (yyval)); }
#line 1757 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 144 "b.y" /* yacc.c:1646  */
    { (yyval) = max((yyvsp[0]) + 1,(yyvsp[-2])); maxHeight = max(maxHeight, (yyval)); }
#line 1763 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 185 "b.y" /* yacc.c:1646  */
    { numPointerDeclarations++; }
#line 1769 "y.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 230 "b.y" /* yacc.c:1646  */
    { numIntegerConstants++; }
#line 1775 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1779 "y.tab.c" /* yacc.c:1646  */
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
#line 266 "b.y" /* yacc.c:1906  */


void yyerror(char *s) {
    fprintf(stderr, "***parsing terminated*** [%s]\n", s);
	error = 1;
}

int main(void) {
    yyparse();
	if (error == 0) {
		printf("***parsing successful***\n");
		printf("#global_declarations = %d\n", numGlobalDeclarations);
		printf("#function_definitions = %d\n", numFunctionDefinitions);
		printf("#integer_constants = %d\n", numIntegerConstants);
		printf("#pointer_declarations = %d\n", numPointerDeclarations);
		printf("#if_without_else = %d\n", numIfWithoutElse);
		printf("if-else max-depth = %d\n", maxHeight);
	}

	return error;
}

