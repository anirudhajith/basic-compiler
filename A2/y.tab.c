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

#line 67 "y.tab.c" /* yacc.c:339  */

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
    PRINTF = 272,
    INT = 273,
    LONG = 274,
    SHORT = 275,
    FLOAT = 276,
    DOUBLE = 277,
    VOID = 278,
    CHAR = 279,
    IDENTIFIER = 280,
    CHARACTER = 281,
    NUMBER = 282,
    REALNUMBER = 283,
    STRING = 284,
    PERCENTD = 285,
    THREEWAYCOMP = 286,
    INCR = 287,
    DECR = 288,
    LOGICALAND = 289,
    LOGICALOR = 290,
    POINTERMEMBER = 291,
    EQEQ = 292,
    NOTEQ = 293,
    LESSEREQ = 294,
    GREATEREQ = 295
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
#define PRINTF 272
#define INT 273
#define LONG 274
#define SHORT 275
#define FLOAT 276
#define DOUBLE 277
#define VOID 278
#define CHAR 279
#define IDENTIFIER 280
#define CHARACTER 281
#define NUMBER 282
#define REALNUMBER 283
#define STRING 284
#define PERCENTD 285
#define THREEWAYCOMP 286
#define INCR 287
#define DECR 288
#define LOGICALAND 289
#define LOGICALOR 290
#define POINTERMEMBER 291
#define EQEQ 292
#define NOTEQ 293
#define LESSEREQ 294
#define GREATEREQ 295

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 7 "a.y" /* yacc.c:355  */

  struct
  {
    int h;
    int d;
  } type_id;

#line 195 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */
#line 15 "a.y" /* yacc.c:358  */

	#include <stdio.h>
	void yyerror(char *);
	int yylex(void);
	char mytext[100];
	int mainDetected;
	int programDiameter = 0;
	int ifDiameter = 0;
	int whileDiameter = 0;
	int switchDiameter = 0;
	int mainDiameter = 0;

	int max(int a, int b) {
		//printf("%d %d\n", a, b);
		if (a > b) return a;
		else return b;
	}

	int getH(int n, int* h) {
		int maxH = h[0];
		for(int i=0; i<n; i++) maxH = max(maxH, h[i]);
		//printf("Heights: "); for(int i=0; i < n; i++) printf("%d ", h[i]); printf("\n H: %d, \n", maxH + 1); 
		return maxH + 1;
	}

	int getD(int n, int* h, int* d) {
		int maxD = d[0];
		for(int i=0; i<n; i++) maxD = max(maxD, d[i]);


		if (n >= 2) {
			int gI = 0; 
			for(int i=0; i < n; i++) { 
				if (h[i] > h[gI]) gI = i;
			} 

			int gI2 = (gI == 0)?1:0; 
			for(int i=0; i < n; i++) { 
				if ((h[i] > h[gI2]) && (i != gI)) gI2 = i;
			} 
			maxD = max(maxD, h[gI] + h[gI2] + 2);
		} else {
			maxD = max(maxD, h[0] + 1);
		}

		//printf("Depths: "); for(int i=0; i < n; i++) printf("%d ", d[i]);
		//printf("\nD: %d \n\n", maxD);
		return maxD;
	}


#line 263 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  14
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   394

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  61
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  41
/* YYNRULES -- Number of rules.  */
#define YYNRULES  108
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  228

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   295

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    41,     2,     2,     2,    60,    45,     2,
      46,    47,    44,    43,    55,    42,    54,    59,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    53,    52,
      57,    56,    58,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    50,     2,    51,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    48,     2,    49,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    69,    69,    72,    73,    76,    77,    78,    81,    84,
      85,    86,    87,    90,    91,    92,    93,    94,    95,    96,
      97,   100,   101,   104,   107,   108,   111,   112,   115,   116,
     117,   120,   121,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   139,   142,   145,   148,
     151,   154,   157,   158,   161,   162,   165,   166,   169,   170,
     173,   176,   179,   182,   183,   186,   189,   191,   192,   193,
     194,   197,   200,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   229,   230,   231,
     232,   235,   238,   241,   244,   245,   248,   249,   252
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IF", "ELSE", "WHILE", "DO", "FOR",
  "SWITCH", "CASE", "DEFAULT", "EXTERN", "STRUCT", "BREAK", "CONTINUE",
  "RETURN", "SIZEOF", "PRINTF", "INT", "LONG", "SHORT", "FLOAT", "DOUBLE",
  "VOID", "CHAR", "IDENTIFIER", "CHARACTER", "NUMBER", "REALNUMBER",
  "STRING", "PERCENTD", "THREEWAYCOMP", "INCR", "DECR", "LOGICALAND",
  "LOGICALOR", "POINTERMEMBER", "EQEQ", "NOTEQ", "LESSEREQ", "GREATEREQ",
  "'!'", "'-'", "'+'", "'*'", "'&'", "'('", "')'", "'{'", "'}'", "'['",
  "']'", "';'", "':'", "'.'", "','", "'='", "'<'", "'>'", "'/'", "'%'",
  "$accept", "program", "decl_list", "decl", "struct_decl", "var_decl",
  "type_spec", "extern_spec", "fun_decl", "params", "param_list", "param",
  "stmt_list", "stmt", "expr_stmt", "while_stmt", "dowhile_stmt",
  "print_stmt", "format_specifier", "compound_stmt", "local_decls",
  "local_decl", "if_stmt", "return_stmt", "break_stmt", "continue_stmt",
  "switch_stmt", "compound_case", "single_case", "default_case",
  "assign_stmt", "incr_stmt", "decr_stmt", "expr", "Pexpr", "integerLit",
  "floatLit", "identifier", "arg_list", "args", "epsilon", YY_NULLPTR
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
     295,    33,    45,    43,    42,    38,    40,    41,   123,   125,
      91,    93,    59,    58,    46,    44,    61,    60,    62,    47,
      37
};
# endif

#define YYPACT_NINF -144

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-144)))

#define YYTABLE_NINF -26

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      42,  -144,   -22,    10,    33,  -144,  -144,  -144,   -22,    43,
    -144,  -144,  -144,   -17,  -144,  -144,   -18,   -26,    -1,     2,
    -144,  -144,    58,    22,  -144,    58,  -144,  -144,  -144,     3,
    -144,   -22,   -24,     9,   -30,  -144,    20,  -144,    21,  -144,
     -22,    35,   -22,  -144,    44,    38,    46,    49,    58,   -43,
      13,  -144,   -33,   -22,    47,  -144,  -144,  -144,  -144,    58,
      78,  -144,  -144,  -144,   270,  -144,    53,  -144,    -4,    -4,
      -4,    -4,    -4,    78,    50,   309,  -144,  -144,    36,    54,
      56,   314,    62,    52,    59,    32,    64,   223,  -144,  -144,
    -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,
    -144,  -144,    63,   338,    -4,  -144,  -144,  -144,  -144,  -144,
    -144,    69,    65,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    78,    78,
      78,    78,   113,    78,  -144,  -144,  -144,    73,   102,  -144,
    -144,  -144,    81,    82,   -22,    78,   -22,    78,    88,  -144,
    -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,
    -144,  -144,  -144,  -144,  -144,  -144,  -144,    83,    89,  -144,
      86,    93,    94,   100,   101,  -144,  -144,    84,  -144,  -144,
      97,    98,   103,   104,  -144,    78,  -144,  -144,   314,   314,
      78,   106,   -22,    78,   109,    78,  -144,  -144,   154,  -144,
     120,   159,   122,   118,    78,   119,   314,   121,    22,   162,
     159,   123,  -144,   124,  -144,  -144,  -144,   125,   126,   128,
    -144,  -144,  -144,   314,   314,  -144,   314,   314
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
     108,    21,     0,     0,   108,     4,     7,     5,     0,     0,
       6,    22,   103,    19,     1,     3,     0,    14,    15,    13,
      20,   108,   108,     0,     9,   108,    17,    18,    16,   108,
      53,     0,     0,     0,    24,    27,    22,   101,     0,    10,
       0,     0,     0,    52,    19,     0,    28,     0,   108,     0,
       0,     8,     0,     0,     0,   108,    23,    26,    11,   108,
       0,    54,    30,    29,   108,    12,     0,   102,     0,     0,
       0,     0,     0,     0,     0,    94,    97,    98,    99,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    32,    45,
      36,    41,    42,    34,    35,    38,    39,    40,    37,    33,
      43,    44,     0,    99,     0,    89,    99,    90,    91,    92,
      93,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   108,     0,
       0,     0,     0,     0,    60,    61,    58,     0,     0,    51,
      31,    46,     0,     0,     0,     0,     0,     0,     0,   100,
      55,    81,    82,    77,    83,    79,    80,    75,    76,    85,
      84,    86,    73,    74,    87,    88,   105,   106,     0,   107,
       0,     0,     0,     0,     0,    59,    50,     0,    71,    72,
       0,     0,     0,     0,    78,     0,    95,    96,     0,     0,
       0,     0,     0,     0,    96,     0,    67,   104,    56,    47,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      64,     0,    69,     0,    70,    57,    48,     0,     0,     0,
      63,    49,    68,     0,     0,    62,    65,    66
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -144,  -144,  -144,   170,  -144,   -23,    -9,  -144,  -144,  -144,
    -144,   132,  -143,   -76,  -144,  -144,  -144,  -144,  -144,   134,
     127,  -144,  -144,  -144,  -144,  -144,  -144,   -25,  -144,  -144,
    -144,  -144,  -144,   -38,    92,   -19,  -144,    -2,  -144,  -144,
     -14
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,     6,     7,     8,     9,    10,    33,
      34,    35,    87,    88,    89,    90,    91,    92,   177,    93,
      29,    43,    94,    95,    96,    97,    98,   209,   210,   219,
      99,   100,   101,   102,    75,    76,    77,   106,   167,   168,
      11
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      13,    12,    39,    12,    38,   132,    16,    30,    36,    58,
      14,   140,    59,    32,     1,    31,    40,    60,    26,    61,
      42,    12,    74,    37,    67,    48,    45,    20,    22,    44,
      46,    21,    23,    -2,    24,   111,    65,    25,    50,    32,
      52,    30,    73,    27,     1,     2,    28,   137,    66,    37,
      40,    62,    41,     1,     2,    42,    47,    12,    78,    37,
      67,    17,   103,    23,    18,    24,    19,   -25,    25,     1,
      31,    78,    49,    68,    69,    70,    71,    72,    73,   103,
     226,   227,   128,    78,   136,   103,   129,    51,    20,    53,
     166,   170,   171,   172,    66,   174,    54,    55,    63,   104,
     130,   112,   131,    12,   134,    37,    67,   181,   133,   183,
     138,   135,   198,   199,   169,   141,   149,   150,   173,    68,
      69,    70,    71,    72,    73,   175,    78,    78,    78,    78,
     215,    78,   176,   178,   179,   184,   186,   187,   185,   192,
     188,   189,   180,    78,   182,    78,   190,   197,   191,   194,
     140,   140,   200,   193,   201,   203,   196,   205,   206,   195,
     105,   107,   108,   109,   110,   204,   213,   207,   208,   211,
     212,   214,   218,   216,    15,   221,   222,   225,   223,   224,
      57,    56,    64,    78,     0,   220,   103,   103,    78,   217,
     202,    78,     0,    78,     0,     0,   148,     0,     0,     0,
       0,     0,    78,     0,   103,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
       0,   103,   103,     0,   103,   103,    79,     0,    80,    81,
       0,    82,     0,     0,     0,     0,    83,    84,    85,    66,
      86,     0,     0,     0,     0,     0,     0,     0,    12,     0,
      37,    67,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    68,    69,    70,    71,    72,    73,
       0,    55,   139,    79,     0,    80,    81,     0,    82,     0,
       0,     1,    31,    83,    84,    85,    66,    86,     0,     0,
       0,     0,     0,     0,     0,    12,     0,    37,    67,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    68,    69,    70,    71,    72,    73,    79,    55,    80,
      81,     0,    82,     0,     0,     0,     0,    83,    84,    85,
      66,    86,     0,     0,     0,     0,     0,     0,     0,    12,
     113,    37,    67,   114,   115,   116,   117,   118,   119,   120,
       0,   121,   122,   123,     0,    68,    69,    70,    71,    72,
      73,     0,    55,     0,     0,     0,   124,   125,   126,   127,
     142,   143,     0,     0,   144,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   128,     0,     0,     0,   145,     0,
       0,     0,   146,     0,   147
};

static const yytype_int16 yycheck[] =
{
       2,    25,    25,    25,    23,    81,     8,    21,    22,    52,
       0,    87,    55,    22,    11,    12,    25,    50,    44,    52,
      29,    25,    60,    27,    28,    55,    50,    44,    46,    31,
      32,    48,    50,     0,    52,    73,    59,    55,    40,    48,
      42,    55,    46,    44,    11,    12,    44,    85,    16,    27,
      59,    53,    49,    11,    12,    64,    47,    25,    60,    27,
      28,    18,    64,    50,    21,    52,    23,    47,    55,    11,
      12,    73,    51,    41,    42,    43,    44,    45,    46,    81,
     223,   224,    46,    85,    52,    87,    50,    52,    44,    51,
     128,   129,   130,   131,    16,   133,    50,    48,    51,    46,
      46,    51,    46,    25,    52,    27,    28,   145,    46,   147,
      46,    52,   188,   189,   128,    52,    47,    52,     5,    41,
      42,    43,    44,    45,    46,    52,   128,   129,   130,   131,
     206,   133,    30,    52,    52,    47,    47,    51,    55,    55,
      47,    47,   144,   145,   146,   147,    46,   185,    47,    51,
     226,   227,   190,    56,    48,   193,    52,   195,     4,    56,
      68,    69,    70,    71,    72,    56,   204,    47,     9,    47,
      52,    52,    10,    52,     4,    52,    52,    49,    53,    53,
      48,    47,    55,   185,    -1,   210,   188,   189,   190,   208,
     192,   193,    -1,   195,    -1,    -1,   104,    -1,    -1,    -1,
      -1,    -1,   204,    -1,   206,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
      -1,   223,   224,    -1,   226,   227,     3,    -1,     5,     6,
      -1,     8,    -1,    -1,    -1,    -1,    13,    14,    15,    16,
      17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,    -1,
      27,    28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    41,    42,    43,    44,    45,    46,
      -1,    48,    49,     3,    -1,     5,     6,    -1,     8,    -1,
      -1,    11,    12,    13,    14,    15,    16,    17,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    25,    -1,    27,    28,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    41,    42,    43,    44,    45,    46,     3,    48,     5,
       6,    -1,     8,    -1,    -1,    -1,    -1,    13,    14,    15,
      16,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,
      31,    27,    28,    34,    35,    36,    37,    38,    39,    40,
      -1,    42,    43,    44,    -1,    41,    42,    43,    44,    45,
      46,    -1,    48,    -1,    -1,    -1,    57,    58,    59,    60,
      32,    33,    -1,    -1,    36,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    46,    -1,    -1,    -1,    50,    -1,
      -1,    -1,    54,    -1,    56
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    11,    12,    62,    63,    64,    65,    66,    67,    68,
      69,   101,    25,    98,     0,    64,    98,    18,    21,    23,
      44,    48,    46,    50,    52,    55,    44,    44,    44,    81,
     101,    12,    67,    70,    71,    72,   101,    27,    96,    66,
      67,    49,    67,    82,    98,    50,    98,    47,    55,    51,
      98,    52,    98,    51,    50,    48,    80,    72,    52,    55,
      50,    52,    98,    51,    81,    66,    16,    28,    41,    42,
      43,    44,    45,    46,    94,    95,    96,    97,    98,     3,
       5,     6,     8,    13,    14,    15,    17,    73,    74,    75,
      76,    77,    78,    80,    83,    84,    85,    86,    87,    91,
      92,    93,    94,    98,    46,    95,    98,    95,    95,    95,
      95,    94,    51,    31,    34,    35,    36,    37,    38,    39,
      40,    42,    43,    44,    57,    58,    59,    60,    46,    50,
      46,    46,    74,    46,    52,    52,    52,    94,    46,    49,
      74,    52,    32,    33,    36,    50,    54,    56,    95,    47,
      52,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    94,    99,   100,   101,
      94,    94,    94,     5,    94,    52,    30,    79,    52,    52,
      98,    94,    98,    94,    47,    55,    47,    51,    47,    47,
      46,    47,    55,    56,    51,    56,    52,    94,    74,    74,
      94,    48,    98,    94,    56,    94,     4,    47,     9,    88,
      89,    47,    52,    94,    52,    74,    52,    96,    10,    90,
      88,    52,    52,    53,    53,    49,    73,    73
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    61,    62,    63,    63,    64,    64,    64,    65,    66,
      66,    66,    66,    67,    67,    67,    67,    67,    67,    67,
      67,    68,    68,    69,    70,    70,    71,    71,    72,    72,
      72,    73,    73,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    75,    76,    77,    78,
      79,    80,    81,    81,    82,    82,    83,    83,    84,    84,
      85,    86,    87,    88,    88,    89,    90,    91,    91,    91,
      91,    92,    93,    94,    94,    94,    94,    94,    94,    94,
      94,    94,    94,    94,    94,    94,    94,    94,    94,    94,
      94,    94,    94,    94,    94,    94,    94,    95,    95,    95,
      95,    96,    97,    98,    99,    99,   100,   100,   101
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     6,     3,
       4,     6,     7,     2,     2,     2,     3,     3,     3,     2,
       3,     1,     1,     6,     1,     1,     3,     1,     2,     4,
       4,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     5,     7,     7,
       1,     4,     2,     1,     3,     6,     5,     7,     2,     3,
       2,     2,     8,     2,     1,     4,     3,     4,     7,     6,
       6,     3,     3,     3,     3,     3,     3,     3,     4,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     2,     2,     2,     1,     4,     4,     1,     1,     1,
       3,     1,     1,     1,     3,     1,     1,     1,     0
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
#line 69 "a.y" /* yacc.c:1646  */
    { int h[1] = {(yyvsp[0].type_id).h}; int d[1] = {(yyvsp[0].type_id).d};			(yyval.type_id).h = getH(1, h); (yyval.type_id).d = getD(1, h, d); 	programDiameter = (yyval.type_id).d + 1; }
#line 1534 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 72 "a.y" /* yacc.c:1646  */
    { int h[2] = {(yyvsp[-1].type_id).h, (yyvsp[0].type_id).h}; int d[2] = {(yyvsp[-1].type_id).d, (yyvsp[0].type_id).d};			(yyval.type_id).h = getH(2, h); (yyval.type_id).d = getD(2, h, d); }
#line 1540 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 73 "a.y" /* yacc.c:1646  */
    { int h[1] = {(yyvsp[0].type_id).h}; int d[1] = {(yyvsp[0].type_id).d};			(yyval.type_id).h = getH(1, h); (yyval.type_id).d = getD(1, h, d); }
#line 1546 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 76 "a.y" /* yacc.c:1646  */
    { int h[1] = {(yyvsp[0].type_id).h}; int d[1] = {(yyvsp[0].type_id).d};			(yyval.type_id).h = getH(1, h); (yyval.type_id).d = getD(1, h, d); }
#line 1552 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 77 "a.y" /* yacc.c:1646  */
    { int h[1] = {(yyvsp[0].type_id).h}; int d[1] = {(yyvsp[0].type_id).d};			(yyval.type_id).h = getH(1, h); (yyval.type_id).d = getD(1, h, d); }
#line 1558 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 78 "a.y" /* yacc.c:1646  */
    { int h[1] = {(yyvsp[0].type_id).h}; int d[1] = {(yyvsp[0].type_id).d};			(yyval.type_id).h = getH(1, h); (yyval.type_id).d = getD(1, h, d); }
#line 1564 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 81 "a.y" /* yacc.c:1646  */
    { int h[6] = {0, (yyvsp[-4].type_id).h, 0, (yyvsp[-2].type_id).h, 0, 0}; int d[6] = {0, (yyvsp[-4].type_id).d, 0, (yyvsp[-2].type_id).d, 0, 0};			(yyval.type_id).h = getH(6, h); (yyval.type_id).d = getD(6, h, d); }
#line 1570 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 84 "a.y" /* yacc.c:1646  */
    { int h[3] = {(yyvsp[-2].type_id).h, (yyvsp[-1].type_id).h, 0}; int d[3] = {(yyvsp[-2].type_id).d, (yyvsp[-1].type_id).d, 0};			(yyval.type_id).h = getH(3, h); (yyval.type_id).d = getD(3, h, d); }
#line 1576 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 85 "a.y" /* yacc.c:1646  */
    { int h[4] = {(yyvsp[-3].type_id).h, (yyvsp[-2].type_id).h, 0, (yyvsp[0].type_id).h}; int d[4] = {(yyvsp[-3].type_id).d, (yyvsp[-2].type_id).d, 0, (yyvsp[0].type_id).d};			(yyval.type_id).h = getH(4, h); (yyval.type_id).d = getD(4, h, d); }
#line 1582 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 86 "a.y" /* yacc.c:1646  */
    { int h[6] = {(yyvsp[-5].type_id).h, (yyvsp[-4].type_id).h, 0, (yyvsp[-2].type_id).h, 0, 0}; int d[6] = {(yyvsp[-5].type_id).d, (yyvsp[-4].type_id).d, 0, (yyvsp[-2].type_id).d, 0, 0};			(yyval.type_id).h = getH(6, h); (yyval.type_id).d = getD(6, h, d); }
#line 1588 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 87 "a.y" /* yacc.c:1646  */
    { int h[7] = {(yyvsp[-6].type_id).h, (yyvsp[-5].type_id).h, 0, (yyvsp[-3].type_id).h, 0, 0, (yyvsp[0].type_id).h}; int d[7] = {(yyvsp[-6].type_id).d, (yyvsp[-5].type_id).d, 0, (yyvsp[-3].type_id).d, 0, 0, (yyvsp[0].type_id).d};			(yyval.type_id).h = getH(7, h); (yyval.type_id).d = getD(7, h, d); }
#line 1594 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 90 "a.y" /* yacc.c:1646  */
    { int h[2] = {(yyvsp[-1].type_id).h, 0}; int d[2] = {(yyvsp[-1].type_id).d, 0};			(yyval.type_id).h = getH(2, h); (yyval.type_id).d = getD(2, h, d); }
#line 1600 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 91 "a.y" /* yacc.c:1646  */
    { int h[2] = {(yyvsp[-1].type_id).h, 0}; int d[2] = {(yyvsp[-1].type_id).d, 0};			(yyval.type_id).h = getH(2, h); (yyval.type_id).d = getD(2, h, d); }
#line 1606 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 92 "a.y" /* yacc.c:1646  */
    { int h[2] = {(yyvsp[-1].type_id).h, 0}; int d[2] = {(yyvsp[-1].type_id).d, 0};			(yyval.type_id).h = getH(2, h); (yyval.type_id).d = getD(2, h, d); }
#line 1612 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 93 "a.y" /* yacc.c:1646  */
    { int h[3] = {(yyvsp[-2].type_id).h, 0, 0}; int d[3] = {(yyvsp[-2].type_id).d, 0, 0};			(yyval.type_id).h = getH(3, h); (yyval.type_id).d = getD(3, h, d); }
#line 1618 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 94 "a.y" /* yacc.c:1646  */
    { int h[3] = {(yyvsp[-2].type_id).h, 0, 0}; int d[3] = {(yyvsp[-2].type_id).d, 0, 0};			(yyval.type_id).h = getH(3, h); (yyval.type_id).d = getD(3, h, d); }
#line 1624 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 95 "a.y" /* yacc.c:1646  */
    { int h[3] = {(yyvsp[-2].type_id).h, 0, 0}; int d[3] = {(yyvsp[-2].type_id).d, 0, 0};			(yyval.type_id).h = getH(3, h); (yyval.type_id).d = getD(3, h, d); }
#line 1630 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 96 "a.y" /* yacc.c:1646  */
    { int h[2] = {0, (yyvsp[0].type_id).h}; int d[2] = {0, (yyvsp[0].type_id).d};			(yyval.type_id).h = getH(2, h); (yyval.type_id).d = getD(2, h, d); }
#line 1636 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 97 "a.y" /* yacc.c:1646  */
    { int h[3] = {0, (yyvsp[-1].type_id).h, 0}; int d[3] = {0, (yyvsp[-1].type_id).d, 0};			(yyval.type_id).h = getH(3, h); (yyval.type_id).d = getD(3, h, d); }
#line 1642 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 100 "a.y" /* yacc.c:1646  */
    { int h[1] = {0}; int d[1] = {0};			(yyval.type_id).h = getH(1, h); (yyval.type_id).d = getD(1, h, d); }
#line 1648 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 101 "a.y" /* yacc.c:1646  */
    { int h[1] = {0}; int d[1] = {0};			(yyval.type_id).h = getH(1, h); (yyval.type_id).d = getD(1, h, d); }
#line 1654 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 104 "a.y" /* yacc.c:1646  */
    { int h[6] = {(yyvsp[-5].type_id).h, (yyvsp[-4].type_id).h, 0, (yyvsp[-2].type_id).h, 0, (yyvsp[0].type_id).h}; int d[6] = {(yyvsp[-5].type_id).d, (yyvsp[-4].type_id).d, 0, (yyvsp[-2].type_id).d, 0, (yyvsp[0].type_id).d};			(yyval.type_id).h = getH(6, h); (yyval.type_id).d = getD(6, h, d); }
#line 1660 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 107 "a.y" /* yacc.c:1646  */
    { int h[1] = {(yyvsp[0].type_id).h}; int d[1] = {(yyvsp[0].type_id).d};			(yyval.type_id).h = getH(1, h); (yyval.type_id).d = getD(1, h, d); }
#line 1666 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 108 "a.y" /* yacc.c:1646  */
    { int h[1] = {0}; int d[1] = {0};			(yyval.type_id).h = getH(1, h); (yyval.type_id).d = getD(1, h, d); }
#line 1672 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 111 "a.y" /* yacc.c:1646  */
    { int h[3] = {(yyvsp[-2].type_id).h, 0, (yyvsp[0].type_id).h}; int d[3] = {(yyvsp[-2].type_id).d, 0, (yyvsp[0].type_id).d};			(yyval.type_id).h = getH(3, h); (yyval.type_id).d = getD(3, h, d); }
#line 1678 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 112 "a.y" /* yacc.c:1646  */
    { int h[1] = {(yyvsp[0].type_id).h}; int d[1] = {(yyvsp[0].type_id).d};			(yyval.type_id).h = getH(1, h); (yyval.type_id).d = getD(1, h, d); }
#line 1684 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 115 "a.y" /* yacc.c:1646  */
    { int h[2] = {(yyvsp[-1].type_id).h, (yyvsp[0].type_id).h}; int d[2] = {(yyvsp[-1].type_id).d, (yyvsp[0].type_id).d};			(yyval.type_id).h = getH(2, h); (yyval.type_id).d = getD(2, h, d); }
#line 1690 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 116 "a.y" /* yacc.c:1646  */
    { int h[4] = {(yyvsp[-3].type_id).h, (yyvsp[-2].type_id).h, 0, 0}; int d[4] = {(yyvsp[-3].type_id).d, (yyvsp[-2].type_id).d, 0, 0};			(yyval.type_id).h = getH(4, h); (yyval.type_id).d = getD(4, h, d); }
#line 1696 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 117 "a.y" /* yacc.c:1646  */
    { int h[4] = {(yyvsp[-3].type_id).h, 0, 0, (yyvsp[0].type_id).h}; int d[4] = {(yyvsp[-3].type_id).d, 0, 0, (yyvsp[0].type_id).d};			(yyval.type_id).h = getH(4, h); (yyval.type_id).d = getD(4, h, d); }
#line 1702 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 120 "a.y" /* yacc.c:1646  */
    { int h[2] = {(yyvsp[-1].type_id).h, (yyvsp[0].type_id).h}; int d[2] = {(yyvsp[-1].type_id).d, (yyvsp[0].type_id).d};			(yyval.type_id).h = getH(2, h); (yyval.type_id).d = getD(2, h, d); }
#line 1708 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 121 "a.y" /* yacc.c:1646  */
    { int h[1] = {(yyvsp[0].type_id).h}; int d[1] = {(yyvsp[0].type_id).d};			(yyval.type_id).h = getH(1, h); (yyval.type_id).d = getD(1, h, d); }
#line 1714 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 124 "a.y" /* yacc.c:1646  */
    { int h[1] = {(yyvsp[0].type_id).h}; int d[1] = {(yyvsp[0].type_id).d};			(yyval.type_id).h = getH(1, h); (yyval.type_id).d = getD(1, h, d); }
#line 1720 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 125 "a.y" /* yacc.c:1646  */
    { int h[1] = {(yyvsp[0].type_id).h}; int d[1] = {(yyvsp[0].type_id).d};			(yyval.type_id).h = getH(1, h); (yyval.type_id).d = getD(1, h, d); }
#line 1726 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 126 "a.y" /* yacc.c:1646  */
    { int h[1] = {(yyvsp[0].type_id).h}; int d[1] = {(yyvsp[0].type_id).d};			(yyval.type_id).h = getH(1, h); (yyval.type_id).d = getD(1, h, d); }
#line 1732 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 127 "a.y" /* yacc.c:1646  */
    { int h[1] = {(yyvsp[0].type_id).h}; int d[1] = {(yyvsp[0].type_id).d};			(yyval.type_id).h = getH(1, h); (yyval.type_id).d = getD(1, h, d); }
#line 1738 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 128 "a.y" /* yacc.c:1646  */
    { int h[1] = {(yyvsp[0].type_id).h}; int d[1] = {(yyvsp[0].type_id).d};			(yyval.type_id).h = getH(1, h); (yyval.type_id).d = getD(1, h, d); }
#line 1744 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 129 "a.y" /* yacc.c:1646  */
    { int h[1] = {(yyvsp[0].type_id).h}; int d[1] = {(yyvsp[0].type_id).d};			(yyval.type_id).h = getH(1, h); (yyval.type_id).d = getD(1, h, d); }
#line 1750 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 130 "a.y" /* yacc.c:1646  */
    { int h[1] = {(yyvsp[0].type_id).h}; int d[1] = {(yyvsp[0].type_id).d};			(yyval.type_id).h = getH(1, h); (yyval.type_id).d = getD(1, h, d); }
#line 1756 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 131 "a.y" /* yacc.c:1646  */
    { int h[1] = {(yyvsp[0].type_id).h}; int d[1] = {(yyvsp[0].type_id).d};			(yyval.type_id).h = getH(1, h); (yyval.type_id).d = getD(1, h, d); }
#line 1762 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 132 "a.y" /* yacc.c:1646  */
    { int h[1] = {(yyvsp[0].type_id).h}; int d[1] = {(yyvsp[0].type_id).d};			(yyval.type_id).h = getH(1, h); (yyval.type_id).d = getD(1, h, d); }
#line 1768 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 133 "a.y" /* yacc.c:1646  */
    { int h[1] = {(yyvsp[0].type_id).h}; int d[1] = {(yyvsp[0].type_id).d};			(yyval.type_id).h = getH(1, h); (yyval.type_id).d = getD(1, h, d); }
#line 1774 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 134 "a.y" /* yacc.c:1646  */
    { int h[1] = {(yyvsp[0].type_id).h}; int d[1] = {(yyvsp[0].type_id).d};			(yyval.type_id).h = getH(1, h); (yyval.type_id).d = getD(1, h, d); }
#line 1780 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 135 "a.y" /* yacc.c:1646  */
    { int h[1] = {(yyvsp[0].type_id).h}; int d[1] = {(yyvsp[0].type_id).d};			(yyval.type_id).h = getH(1, h); (yyval.type_id).d = getD(1, h, d); }
#line 1786 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 136 "a.y" /* yacc.c:1646  */
    { int h[1] = {(yyvsp[0].type_id).h}; int d[1] = {(yyvsp[0].type_id).d};			(yyval.type_id).h = getH(1, h); (yyval.type_id).d = getD(1, h, d); }
#line 1792 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 139 "a.y" /* yacc.c:1646  */
    { int h[2] = {(yyvsp[-1].type_id).h, 0}; int d[2] = {(yyvsp[-1].type_id).d, 0};			(yyval.type_id).h = getH(2, h); (yyval.type_id).d = getD(2, h, d); }
#line 1798 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 142 "a.y" /* yacc.c:1646  */
    { int h[5] = {0, 0, (yyvsp[-2].type_id).h, 0, (yyvsp[0].type_id).h}; int d[5] = {0, 0, (yyvsp[-2].type_id).d, 0, (yyvsp[0].type_id).d};			(yyval.type_id).h = getH(5, h); (yyval.type_id).d = getD(5, h, d); 		whileDiameter = max(whileDiameter, (yyval.type_id).d + 1); }
#line 1804 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 145 "a.y" /* yacc.c:1646  */
    { int h[7] = {0, (yyvsp[-5].type_id).h, 0, 0, (yyvsp[-2].type_id).h, 0, 0}; int d[7] = {0, (yyvsp[-5].type_id).d, 0, 0, (yyvsp[-2].type_id).d, 0, 0};			(yyval.type_id).h = getH(7, h); (yyval.type_id).d = getD(7, h, d); }
#line 1810 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 148 "a.y" /* yacc.c:1646  */
    { int h[7] = {0, 0, (yyvsp[-4].type_id).h, 0, (yyvsp[-2].type_id).h, 0, 0}; int d[7] = {0, 0, (yyvsp[-4].type_id).d, 0, (yyvsp[-2].type_id).d, 0, 0};			(yyval.type_id).h = getH(7, h); (yyval.type_id).d = getD(7, h, d); }
#line 1816 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 151 "a.y" /* yacc.c:1646  */
    { int h[1] = {0}; int d[1] = {0};			(yyval.type_id).h = getH(1, h); (yyval.type_id).d = getD(1, h, d); }
#line 1822 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 154 "a.y" /* yacc.c:1646  */
    { int h[4] = {0, (yyvsp[-2].type_id).h, (yyvsp[-1].type_id).h, 0}; int d[4] = {0, (yyvsp[-2].type_id).d, (yyvsp[-1].type_id).d, 0};			(yyval.type_id).h = getH(4, h); (yyval.type_id).d = getD(4, h, d); }
#line 1828 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 157 "a.y" /* yacc.c:1646  */
    { int h[2] = {(yyvsp[-1].type_id).h, (yyvsp[0].type_id).h}; int d[2] = {(yyvsp[-1].type_id).d, (yyvsp[0].type_id).d};			(yyval.type_id).h = getH(2, h); (yyval.type_id).d = getD(2, h, d); }
#line 1834 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 158 "a.y" /* yacc.c:1646  */
    { int h[1] = {0}; int d[1] = {0};			(yyval.type_id).h = getH(1, h); (yyval.type_id).d = getD(1, h, d); }
#line 1840 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 161 "a.y" /* yacc.c:1646  */
    { int h[3] = {(yyvsp[-2].type_id).h, (yyvsp[-1].type_id).h, 0}; int d[3] = {(yyvsp[-2].type_id).d, (yyvsp[-1].type_id).d, 0};			(yyval.type_id).h = getH(3, h); (yyval.type_id).d = getD(3, h, d); }
#line 1846 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 162 "a.y" /* yacc.c:1646  */
    { int h[6] = {(yyvsp[-5].type_id).h, (yyvsp[-4].type_id).h, 0, (yyvsp[-2].type_id).h, 0, 0}; int d[6] = {(yyvsp[-5].type_id).d, (yyvsp[-4].type_id).d, 0, (yyvsp[-2].type_id).d, 0, 0};			(yyval.type_id).h = getH(6, h); (yyval.type_id).d = getD(6, h, d); }
#line 1852 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 165 "a.y" /* yacc.c:1646  */
    { int h[5] = {0, 0, (yyvsp[-2].type_id).h, 0, (yyvsp[0].type_id).h}; int d[5] = {0, 0, (yyvsp[-2].type_id).d, 0, (yyvsp[0].type_id).d};			(yyval.type_id).h = getH(5, h); (yyval.type_id).d = getD(5, h, d); 		ifDiameter = max(ifDiameter, (yyval.type_id).d + 1); }
#line 1858 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 166 "a.y" /* yacc.c:1646  */
    { int h[7] = {0, 0, (yyvsp[-4].type_id).h, 0, (yyvsp[-2].type_id).h, 0, (yyvsp[0].type_id).h}; int d[7] = {0, 0, (yyvsp[-4].type_id).d, 0, (yyvsp[-2].type_id).d, 0, (yyvsp[0].type_id).d};			(yyval.type_id).h = getH(7, h); (yyval.type_id).d = getD(7, h, d); 		ifDiameter = max(ifDiameter, (yyval.type_id).d + 1); }
#line 1864 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 169 "a.y" /* yacc.c:1646  */
    { int h[2] = {0, 0}; int d[2] = {0, 0};			(yyval.type_id).h = getH(2, h); (yyval.type_id).d = getD(2, h, d); }
#line 1870 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 170 "a.y" /* yacc.c:1646  */
    { int h[3] = {0, (yyvsp[-1].type_id).h, 0}; int d[3] = {0, (yyvsp[-1].type_id).d, 0};			(yyval.type_id).h = getH(3, h); (yyval.type_id).d = getD(3, h, d); }
#line 1876 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 173 "a.y" /* yacc.c:1646  */
    { int h[2] = {0, 0}; int d[2] = {0, 0};			(yyval.type_id).h = getH(2, h); (yyval.type_id).d = getD(2, h, d); }
#line 1882 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 176 "a.y" /* yacc.c:1646  */
    { int h[2] = {0, 0}; int d[2] = {0, 0};			(yyval.type_id).h = getH(2, h); (yyval.type_id).d = getD(2, h, d); }
#line 1888 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 179 "a.y" /* yacc.c:1646  */
    { int h[8] = {0, 0, (yyvsp[-5].type_id).h, 0, 0, (yyvsp[-2].type_id).h, (yyvsp[-1].type_id).h, 0}; int d[8] = {0, 0, (yyvsp[-5].type_id).d, 0, 0, (yyvsp[-2].type_id).d, (yyvsp[-1].type_id).d, 0};			(yyval.type_id).h = getH(8, h); (yyval.type_id).d = getD(8, h, d); 			switchDiameter = max(switchDiameter, (yyval.type_id).d + 1); }
#line 1894 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 182 "a.y" /* yacc.c:1646  */
    { int h[2] = {(yyvsp[-1].type_id).h, (yyvsp[0].type_id).h}; int d[2] = {(yyvsp[-1].type_id).d, (yyvsp[0].type_id).d};			(yyval.type_id).h = getH(2, h); (yyval.type_id).d = getD(2, h, d); }
#line 1900 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 183 "a.y" /* yacc.c:1646  */
    { int h[1] = {(yyvsp[0].type_id).h}; int d[1] = {(yyvsp[0].type_id).d};			(yyval.type_id).h = getH(1, h); (yyval.type_id).d = getD(1, h, d); }
#line 1906 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 186 "a.y" /* yacc.c:1646  */
    { int h[4] = {0, (yyvsp[-2].type_id).h, 0, (yyvsp[0].type_id).h}; int d[4] = {0, (yyvsp[-2].type_id).d, 0, (yyvsp[0].type_id).d};			(yyval.type_id).h = getH(4, h); (yyval.type_id).d = getD(4, h, d); }
#line 1912 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 189 "a.y" /* yacc.c:1646  */
    { int h[3] = {0, 0, (yyvsp[0].type_id).h}; int d[3] = {0, 0, (yyvsp[0].type_id).d};			(yyval.type_id).h = getH(3, h); (yyval.type_id).d = getD(3, h, d); }
#line 1918 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 191 "a.y" /* yacc.c:1646  */
    { int h[2] = {(yyvsp[-3].type_id).h, (yyvsp[-1].type_id).h}; int d[2] = {(yyvsp[-3].type_id).d, (yyvsp[-1].type_id).d};         (yyval.type_id).h = getH(2, h) + 1; (yyval.type_id).d = max(getD(2, h, d), (yyval.type_id).h + 1); }
#line 1924 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 192 "a.y" /* yacc.c:1646  */
    { int h[3] = {(yyvsp[-6].type_id).h, (yyvsp[-4].type_id).h, (yyvsp[-1].type_id).h}; int d[3] = {(yyvsp[-6].type_id).d, (yyvsp[-4].type_id).d, (yyvsp[-1].type_id).d};         (yyval.type_id).h = getH(3, h) + 1; (yyval.type_id).d = max(getD(3, h, d), (yyval.type_id).h + 1); }
#line 1930 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 193 "a.y" /* yacc.c:1646  */
    { int h[4] = {(yyvsp[-5].type_id).h, (yyvsp[-4].type_id).h, (yyvsp[-3].type_id).h, (yyvsp[-1].type_id).h}; int d[4] = {(yyvsp[-5].type_id).d, (yyvsp[-4].type_id).d, (yyvsp[-3].type_id).d, (yyvsp[-1].type_id).d};         (yyval.type_id).h = getH(4, h) + 1; (yyval.type_id).d = max(getD(4, h, d), (yyval.type_id).h + 1); }
#line 1936 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 194 "a.y" /* yacc.c:1646  */
    { int h[4] = {(yyvsp[-5].type_id).h, (yyvsp[-4].type_id).h, (yyvsp[-3].type_id).h, (yyvsp[-1].type_id).h}; int d[4] = {(yyvsp[-5].type_id).d, (yyvsp[-4].type_id).d, (yyvsp[-3].type_id).d, (yyvsp[-1].type_id).d};         (yyval.type_id).h = getH(4, h) + 1; (yyval.type_id).d = max(getD(4, h, d), (yyval.type_id).h + 1); }
#line 1942 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 197 "a.y" /* yacc.c:1646  */
    { int h[3] = {(yyvsp[-2].type_id).h, 0, 0}; int d[3] = {(yyvsp[-2].type_id).d, 0, 0};			(yyval.type_id).h = getH(3, h); (yyval.type_id).d = getD(3, h, d); }
#line 1948 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 200 "a.y" /* yacc.c:1646  */
    { int h[3] = {(yyvsp[-2].type_id).h, 0, 0}; int d[3] = {(yyvsp[-2].type_id).d, 0, 0};			(yyval.type_id).h = getH(3, h); (yyval.type_id).d = getD(3, h, d); }
#line 1954 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 203 "a.y" /* yacc.c:1646  */
    { (yyval.type_id).h = max((yyvsp[-2].type_id).h, (yyvsp[0].type_id).h) + 2; (yyval.type_id).d = max(max(max((yyvsp[-2].type_id).d, (yyvsp[0].type_id).d), (yyvsp[-2].type_id).h + (yyvsp[0].type_id).h + 2), (yyval.type_id).h); }
#line 1960 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 204 "a.y" /* yacc.c:1646  */
    { (yyval.type_id).h = max((yyvsp[-2].type_id).h, (yyvsp[0].type_id).h) + 2; (yyval.type_id).d = max(max(max((yyvsp[-2].type_id).d, (yyvsp[0].type_id).d), (yyvsp[-2].type_id).h + (yyvsp[0].type_id).h + 2), (yyval.type_id).h); }
#line 1966 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 205 "a.y" /* yacc.c:1646  */
    { (yyval.type_id).h = max((yyvsp[-2].type_id).h, (yyvsp[0].type_id).h) + 2; (yyval.type_id).d = max(max(max((yyvsp[-2].type_id).d, (yyvsp[0].type_id).d), (yyvsp[-2].type_id).h + (yyvsp[0].type_id).h + 2), (yyval.type_id).h); }
#line 1972 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 206 "a.y" /* yacc.c:1646  */
    { (yyval.type_id).h = max((yyvsp[-2].type_id).h, (yyvsp[0].type_id).h) + 2; (yyval.type_id).d = max(max(max((yyvsp[-2].type_id).d, (yyvsp[0].type_id).d), (yyvsp[-2].type_id).h + (yyvsp[0].type_id).h + 2), (yyval.type_id).h); }
#line 1978 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 207 "a.y" /* yacc.c:1646  */
    { (yyval.type_id).h = max((yyvsp[-2].type_id).h, (yyvsp[0].type_id).h) + 2; (yyval.type_id).d = max(max(max((yyvsp[-2].type_id).d, (yyvsp[0].type_id).d), (yyvsp[-2].type_id).h + (yyvsp[0].type_id).h + 2), (yyval.type_id).h); }
#line 1984 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 208 "a.y" /* yacc.c:1646  */
    { int h[4] = {0, 0, (yyvsp[-1].type_id).h, 0}; int d[4] = {0, 0, (yyvsp[-1].type_id).d, 0};			(yyval.type_id).h = getH(4, h); (yyval.type_id).d = getD(4, h, d); }
#line 1990 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 209 "a.y" /* yacc.c:1646  */
    { (yyval.type_id).h = max((yyvsp[-2].type_id).h, (yyvsp[0].type_id).h) + 2; (yyval.type_id).d = max(max(max((yyvsp[-2].type_id).d, (yyvsp[0].type_id).d), (yyvsp[-2].type_id).h + (yyvsp[0].type_id).h + 2), (yyval.type_id).h); }
#line 1996 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 210 "a.y" /* yacc.c:1646  */
    { (yyval.type_id).h = max((yyvsp[-2].type_id).h, (yyvsp[0].type_id).h) + 2; (yyval.type_id).d = max(max(max((yyvsp[-2].type_id).d, (yyvsp[0].type_id).d), (yyvsp[-2].type_id).h + (yyvsp[0].type_id).h + 2), (yyval.type_id).h); }
#line 2002 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 211 "a.y" /* yacc.c:1646  */
    { (yyval.type_id).h = max((yyvsp[-2].type_id).h, (yyvsp[0].type_id).h) + 2; (yyval.type_id).d = max(max(max((yyvsp[-2].type_id).d, (yyvsp[0].type_id).d), (yyvsp[-2].type_id).h + (yyvsp[0].type_id).h + 2), (yyval.type_id).h); }
#line 2008 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 212 "a.y" /* yacc.c:1646  */
    { (yyval.type_id).h = max((yyvsp[-2].type_id).h, (yyvsp[0].type_id).h) + 2; (yyval.type_id).d = max(max(max((yyvsp[-2].type_id).d, (yyvsp[0].type_id).d), (yyvsp[-2].type_id).h + (yyvsp[0].type_id).h + 2), (yyval.type_id).h); }
#line 2014 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 213 "a.y" /* yacc.c:1646  */
    { (yyval.type_id).h = max((yyvsp[-2].type_id).h, (yyvsp[0].type_id).h) + 2; (yyval.type_id).d = max(max(max((yyvsp[-2].type_id).d, (yyvsp[0].type_id).d), (yyvsp[-2].type_id).h + (yyvsp[0].type_id).h + 2), (yyval.type_id).h); }
#line 2020 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 214 "a.y" /* yacc.c:1646  */
    { (yyval.type_id).h = max((yyvsp[-2].type_id).h, (yyvsp[0].type_id).h) + 2; (yyval.type_id).d = max(max(max((yyvsp[-2].type_id).d, (yyvsp[0].type_id).d), (yyvsp[-2].type_id).h + (yyvsp[0].type_id).h + 2), (yyval.type_id).h); }
#line 2026 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 215 "a.y" /* yacc.c:1646  */
    { (yyval.type_id).h = max((yyvsp[-2].type_id).h, (yyvsp[0].type_id).h) + 2; (yyval.type_id).d = max(max(max((yyvsp[-2].type_id).d, (yyvsp[0].type_id).d), (yyvsp[-2].type_id).h + (yyvsp[0].type_id).h + 2), (yyval.type_id).h); }
#line 2032 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 216 "a.y" /* yacc.c:1646  */
    { (yyval.type_id).h = max((yyvsp[-2].type_id).h, (yyvsp[0].type_id).h) + 2; (yyval.type_id).d = max(max(max((yyvsp[-2].type_id).d, (yyvsp[0].type_id).d), (yyvsp[-2].type_id).h + (yyvsp[0].type_id).h + 2), (yyval.type_id).h); }
#line 2038 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 217 "a.y" /* yacc.c:1646  */
    { (yyval.type_id).h = max((yyvsp[-2].type_id).h, (yyvsp[0].type_id).h) + 2; (yyval.type_id).d = max(max(max((yyvsp[-2].type_id).d, (yyvsp[0].type_id).d), (yyvsp[-2].type_id).h + (yyvsp[0].type_id).h + 2), (yyval.type_id).h); }
#line 2044 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 218 "a.y" /* yacc.c:1646  */
    { (yyval.type_id).h = max((yyvsp[-2].type_id).h, (yyvsp[0].type_id).h) + 2; (yyval.type_id).d = max(max(max((yyvsp[-2].type_id).d, (yyvsp[0].type_id).d), (yyvsp[-2].type_id).h + (yyvsp[0].type_id).h + 2), (yyval.type_id).h); }
#line 2050 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 219 "a.y" /* yacc.c:1646  */
    { int h[2] = {0, (yyvsp[0].type_id).h}; int d[2] = {0, (yyvsp[0].type_id).d};			(yyval.type_id).h = getH(2, h); (yyval.type_id).d = getD(2, h, d); }
#line 2056 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 220 "a.y" /* yacc.c:1646  */
    { int h[2] = {0, (yyvsp[0].type_id).h}; int d[2] = {0, (yyvsp[0].type_id).d};			(yyval.type_id).h = getH(2, h); (yyval.type_id).d = getD(2, h, d); }
#line 2062 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 221 "a.y" /* yacc.c:1646  */
    { int h[2] = {0, (yyvsp[0].type_id).h}; int d[2] = {0, (yyvsp[0].type_id).d};			(yyval.type_id).h = getH(2, h); (yyval.type_id).d = getD(2, h, d); }
#line 2068 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 222 "a.y" /* yacc.c:1646  */
    { int h[2] = {0, (yyvsp[0].type_id).h}; int d[2] = {0, (yyvsp[0].type_id).d};			(yyval.type_id).h = getH(2, h); (yyval.type_id).d = getD(2, h, d); }
#line 2074 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 223 "a.y" /* yacc.c:1646  */
    { int h[2] = {0, (yyvsp[0].type_id).h}; int d[2] = {0, (yyvsp[0].type_id).d};			(yyval.type_id).h = getH(2, h); (yyval.type_id).d = getD(2, h, d); }
#line 2080 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 224 "a.y" /* yacc.c:1646  */
    { int h[1] = {(yyvsp[0].type_id).h}; int d[1] = {(yyvsp[0].type_id).d};			(yyval.type_id).h = getH(1, h); (yyval.type_id).d = getD(1, h, d); }
#line 2086 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 225 "a.y" /* yacc.c:1646  */
    { int h[4] = {(yyvsp[-3].type_id).h, 0, (yyvsp[-1].type_id).h, 0}; int d[4] = {(yyvsp[-3].type_id).d, 0, (yyvsp[-1].type_id).d, 0};			(yyval.type_id).h = getH(4, h); (yyval.type_id).d = getD(4, h, d); }
#line 2092 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 226 "a.y" /* yacc.c:1646  */
    { int h[4] = {(yyvsp[-3].type_id).h, 0, (yyvsp[-1].type_id).h, 0}; int d[4] = {(yyvsp[-3].type_id).d, 0, (yyvsp[-1].type_id).d, 0};			(yyval.type_id).h = getH(4, h); (yyval.type_id).d = getD(4, h, d); }
#line 2098 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 229 "a.y" /* yacc.c:1646  */
    { int h[1] = {(yyvsp[0].type_id).h}; int d[1] = {(yyvsp[0].type_id).d};			(yyval.type_id).h = getH(1, h); (yyval.type_id).d = getD(1, h, d); }
#line 2104 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 230 "a.y" /* yacc.c:1646  */
    { int h[1] = {(yyvsp[0].type_id).h}; int d[1] = {(yyvsp[0].type_id).d};			(yyval.type_id).h = getH(1, h); (yyval.type_id).d = getD(1, h, d); }
#line 2110 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 231 "a.y" /* yacc.c:1646  */
    { int h[1] = {(yyvsp[0].type_id).h}; int d[1] = {(yyvsp[0].type_id).d};			(yyval.type_id).h = getH(1, h); (yyval.type_id).d = getD(1, h, d); }
#line 2116 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 232 "a.y" /* yacc.c:1646  */
    { int h[3] = {0, (yyvsp[-1].type_id).h, 0}; int d[3] = {0, (yyvsp[-1].type_id).d, 0};			(yyval.type_id).h = getH(3, h); (yyval.type_id).d = getD(3, h, d); }
#line 2122 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 235 "a.y" /* yacc.c:1646  */
    { int h[1] = {0}; int d[1] = {0};			(yyval.type_id).h = getH(1, h); (yyval.type_id).d = getD(1, h, d); }
#line 2128 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 238 "a.y" /* yacc.c:1646  */
    { int h[1] = {0}; int d[1] = {0};			(yyval.type_id).h = getH(1, h); (yyval.type_id).d = getD(1, h, d); }
#line 2134 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 241 "a.y" /* yacc.c:1646  */
    { int h[1] = {0}; int d[1] = {0};			(yyval.type_id).h = getH(1, h); (yyval.type_id).d = getD(1, h, d); }
#line 2140 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 244 "a.y" /* yacc.c:1646  */
    { int h[3] = {(yyvsp[-2].type_id).h, 0, (yyvsp[0].type_id).h}; int d[3] = {(yyvsp[-2].type_id).d, 0, (yyvsp[0].type_id).d};			(yyval.type_id).h = getH(3, h); (yyval.type_id).d = getD(3, h, d); }
#line 2146 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 245 "a.y" /* yacc.c:1646  */
    { int h[1] = {(yyvsp[0].type_id).h}; int d[1] = {(yyvsp[0].type_id).d};			(yyval.type_id).h = getH(1, h); (yyval.type_id).d = getD(1, h, d); }
#line 2152 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 248 "a.y" /* yacc.c:1646  */
    { int h[1] = {(yyvsp[0].type_id).h}; int d[1] = {(yyvsp[0].type_id).d};			(yyval.type_id).h = getH(1, h); (yyval.type_id).d = getD(1, h, d); }
#line 2158 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 249 "a.y" /* yacc.c:1646  */
    { int h[1] = {0}; int d[1] = {0};			(yyval.type_id).h = getH(1, h); (yyval.type_id).d = getD(1, h, d); }
#line 2164 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 252 "a.y" /* yacc.c:1646  */
    { (yyval.type_id).h = 0; (yyval.type_id).d = 0; }
#line 2170 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2174 "y.tab.c" /* yacc.c:1646  */
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
#line 254 "a.y" /* yacc.c:1906  */


void yyerror(char *s) {
	extern int yylineno;
    fprintf(stderr, "%s on line %d\n", s, yylineno);
}

int main(void) {
    yyparse();
	fprintf(stdout, "parsed successfully\n");
	fprintf(stdout, "%d\n%d\n%d\n%d\n%d\n", programDiameter, ifDiameter, whileDiameter, switchDiameter, mainDiameter);
    return 0;
}

