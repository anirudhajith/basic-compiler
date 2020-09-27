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
	#include <stdlib.h>
	void yyerror(char *);
	int yylex(void);
	char mytext[100];
	int mainDetected;
	int updateMain = 0;
	int programDiameter = 0;
	int ifDiameter = 0;
	int whileDiameter = 0;
	int switchDiameter = 0;
	int mainDiameter = 0;
	int error = 0;

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


#line 266 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   368

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  61
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  42
/* YYNRULES -- Number of rules.  */
#define YYNRULES  109
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  229

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
       0,    72,    72,    75,    76,    79,    80,    81,    84,    87,
      88,    89,    90,    93,    94,    95,    96,    97,    98,    99,
     100,   103,   104,   107,   107,   110,   111,   114,   115,   118,
     119,   120,   123,   124,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   142,   145,   148,
     151,   154,   157,   160,   161,   164,   165,   168,   169,   172,
     173,   176,   179,   182,   185,   186,   189,   192,   194,   195,
     196,   197,   200,   203,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   232,   233,
     234,   235,   238,   241,   244,   247,   248,   251,   252,   255
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
  "type_spec", "extern_spec", "fun_decl", "$@1", "params", "param_list",
  "param", "stmt_list", "stmt", "expr_stmt", "while_stmt", "dowhile_stmt",
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

#define YYPACT_NINF -145

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-145)))

#define YYTABLE_NINF -27

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      63,  -145,   -10,    24,    26,  -145,  -145,  -145,   -10,    44,
    -145,  -145,  -145,   -39,  -145,  -145,     1,   -12,     8,    11,
    -145,  -145,     7,  -145,    67,    30,  -145,  -145,  -145,     0,
    -145,  -145,    31,   -10,  -145,   -10,    67,    40,   -10,  -145,
      16,    49,     1,   -22,    47,    41,  -145,    48,  -145,   -36,
    -145,    67,    50,    54,    51,    67,     2,  -145,  -145,   -10,
      56,  -145,  -145,  -145,    52,  -145,    -6,    -6,    -6,    -6,
      -6,     2,    62,   308,  -145,  -145,    14,  -145,  -145,   224,
      -6,  -145,  -145,  -145,  -145,  -145,  -145,    58,    64,    -6,
      -6,    -6,    -6,    -6,    -6,    -6,    -6,    -6,    -6,    -6,
      -6,    -6,    -6,    -6,     2,     2,    71,    73,   268,    76,
      72,    74,    45,    83,   169,  -145,  -145,  -145,  -145,  -145,
    -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,    78,
      82,    84,  -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,
    -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,
      79,    86,  -145,    88,     2,     2,   130,     2,  -145,  -145,
    -145,    85,   110,  -145,  -145,  -145,    89,    90,   -10,     2,
     -10,     2,  -145,     2,  -145,  -145,    96,    97,    99,   100,
    -145,  -145,    93,  -145,  -145,    94,   103,   101,   104,  -145,
     268,   268,     2,   112,   -10,     2,   102,     2,  -145,   157,
    -145,   115,   154,   117,   113,     2,   118,   268,   121,     7,
     166,   154,   126,  -145,   127,  -145,  -145,  -145,   128,   134,
     131,  -145,  -145,  -145,   268,   268,  -145,   268,   268
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
     109,    21,     0,     0,   109,     4,     7,     5,     0,     0,
       6,    22,   104,    19,     1,     3,    23,    14,    15,    13,
      20,   109,     0,     9,   109,     0,    17,    18,    16,   109,
      54,   102,     0,     0,    10,     0,   109,     0,     0,    53,
       0,    19,     0,     0,     0,    25,    28,    22,     8,     0,
      11,   109,     0,    29,     0,   109,     0,    55,    12,     0,
       0,   109,    24,    27,     0,   103,     0,     0,     0,     0,
       0,     0,     0,    95,    98,    99,   100,    31,    30,   109,
       0,    90,   100,    91,    92,    93,    94,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   109,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    46,    37,    42,    43,
      35,    36,    39,    40,    41,    38,    34,    44,    45,     0,
     100,     0,   101,    56,    82,    83,    78,    84,    80,    81,
      76,    77,    86,    85,    87,    74,    75,    88,    89,   106,
     107,     0,   108,     0,     0,     0,     0,     0,    61,    62,
      59,     0,     0,    52,    32,    47,     0,     0,     0,     0,
       0,     0,    79,     0,    96,    97,     0,     0,     0,     0,
      60,    51,     0,    72,    73,     0,     0,     0,     0,   105,
       0,     0,     0,     0,     0,     0,    97,     0,    68,    57,
      48,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    65,     0,    70,     0,    71,    58,    49,     0,     0,
       0,    64,    50,    69,     0,     0,    63,    66,    67
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -145,  -145,  -145,   194,  -145,    -1,   -16,  -145,  -145,  -145,
    -145,  -145,   144,  -144,  -107,  -145,  -145,  -145,  -145,  -145,
     146,   140,  -145,  -145,  -145,  -145,  -145,  -145,    -9,  -145,
    -145,  -145,  -145,  -145,   -46,   235,   -18,  -145,    -2,  -145,
    -145,   -19
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,     6,     7,     8,     9,    10,    25,
      44,    45,    46,   114,   115,   116,   117,   118,   119,   182,
     120,    29,    39,   121,   122,   123,   124,   125,   210,   211,
     220,   126,   127,   128,   129,    73,    74,    75,    82,   150,
     151,    11
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      13,   156,    30,    12,    32,    20,    16,   164,    35,    21,
      72,     1,    33,    38,    56,    12,    57,    47,    64,    12,
      43,    31,    65,    34,    14,    87,    -2,    12,    52,    31,
      65,    41,    26,    42,    31,    35,    49,     1,     2,    43,
      71,    53,    30,    66,    67,    68,    69,    70,    71,    37,
      58,    22,    27,    23,    76,    28,    24,    77,   149,   153,
     104,    64,    17,    38,   105,    18,   161,    19,    50,    76,
      12,    51,    31,    65,     1,     2,    36,   130,     1,    33,
     227,   228,    40,   199,   200,   152,    66,    67,    68,    69,
      70,    71,    48,    20,    54,   -26,    55,   160,    80,    61,
     216,    59,    76,    76,    60,   132,   130,    78,   176,   177,
      76,   179,   130,    88,   166,   167,   133,   154,   168,   155,
     164,   164,   157,   186,   158,   188,   159,   189,   104,   162,
     165,   172,   169,   174,   173,   178,   170,   180,   171,   175,
     181,   183,   184,   190,   191,   192,   201,   193,   194,   204,
     195,   206,    76,    76,   196,    76,   198,   197,   205,   214,
     202,   207,   208,   209,   212,   213,   185,    76,   187,    76,
     215,    76,   106,   217,   107,   108,   219,   109,   222,   223,
     226,   224,   110,   111,   112,    64,   113,   225,   130,   130,
      76,   218,   203,    76,    12,    76,    31,    65,    15,    63,
      62,    79,   221,    76,     0,   130,     0,     0,     0,     0,
      66,    67,    68,    69,    70,    71,     0,    61,   163,     0,
       0,     0,   130,   130,     0,   130,   130,   106,     0,   107,
     108,     0,   109,     0,     0,     1,    33,   110,   111,   112,
      64,   113,     0,     0,     0,     0,     0,     0,     0,    12,
       0,    31,    65,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    66,    67,    68,    69,    70,
      71,   106,    61,   107,   108,     0,   109,     0,     0,     0,
       0,   110,   111,   112,    64,   113,     0,     0,     0,     0,
       0,     0,     0,    12,     0,    31,    65,     0,     0,     0,
       0,    81,    83,    84,    85,    86,     0,     0,     0,    66,
      67,    68,    69,    70,    71,   131,    61,     0,     0,     0,
       0,     0,     0,     0,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,    89,
       0,     0,    90,    91,    92,    93,    94,    95,    96,     0,
      97,    98,    99,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   100,   101,   102,   103
};

static const yytype_int16 yycheck[] =
{
       2,   108,    21,    25,    22,    44,     8,   114,    24,    48,
      56,    11,    12,    29,    50,    25,    52,    36,    16,    25,
      36,    27,    28,    24,     0,    71,     0,    25,    50,    27,
      28,    33,    44,    35,    27,    51,    38,    11,    12,    55,
      46,    43,    61,    41,    42,    43,    44,    45,    46,    49,
      51,    50,    44,    52,    56,    44,    55,    59,   104,   105,
      46,    16,    18,    79,    50,    21,   112,    23,    52,    71,
      25,    55,    27,    28,    11,    12,    46,    79,    11,    12,
     224,   225,    51,   190,   191,   104,    41,    42,    43,    44,
      45,    46,    52,    44,    47,    47,    55,    52,    46,    48,
     207,    51,   104,   105,    50,    47,   108,    51,   154,   155,
     112,   157,   114,    51,    32,    33,    52,    46,    36,    46,
     227,   228,    46,   169,    52,   171,    52,   173,    46,    46,
      52,    47,    50,    47,    55,     5,    54,    52,    56,    51,
      30,    52,    52,    47,    47,    46,   192,    47,    55,   195,
      56,   197,   154,   155,    51,   157,    52,    56,    56,   205,
      48,     4,    47,     9,    47,    52,   168,   169,   170,   171,
      52,   173,     3,    52,     5,     6,    10,     8,    52,    52,
      49,    53,    13,    14,    15,    16,    17,    53,   190,   191,
     192,   209,   194,   195,    25,   197,    27,    28,     4,    55,
      54,    61,   211,   205,    -1,   207,    -1,    -1,    -1,    -1,
      41,    42,    43,    44,    45,    46,    -1,    48,    49,    -1,
      -1,    -1,   224,   225,    -1,   227,   228,     3,    -1,     5,
       6,    -1,     8,    -1,    -1,    11,    12,    13,    14,    15,
      16,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,
      -1,    27,    28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    41,    42,    43,    44,    45,
      46,     3,    48,     5,     6,    -1,     8,    -1,    -1,    -1,
      -1,    13,    14,    15,    16,    17,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    25,    -1,    27,    28,    -1,    -1,    -1,
      -1,    66,    67,    68,    69,    70,    -1,    -1,    -1,    41,
      42,    43,    44,    45,    46,    80,    48,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,    31,
      -1,    -1,    34,    35,    36,    37,    38,    39,    40,    -1,
      42,    43,    44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    57,    58,    59,    60
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    11,    12,    62,    63,    64,    65,    66,    67,    68,
      69,   102,    25,    99,     0,    64,    99,    18,    21,    23,
      44,    48,    50,    52,    55,    70,    44,    44,    44,    82,
     102,    27,    97,    12,    66,    67,    46,    49,    67,    83,
      51,    99,    99,    67,    71,    72,    73,   102,    52,    99,
      52,    55,    50,    99,    47,    55,    50,    52,    66,    51,
      50,    48,    81,    73,    16,    28,    41,    42,    43,    44,
      45,    46,    95,    96,    97,    98,    99,    99,    51,    82,
      46,    96,    99,    96,    96,    96,    96,    95,    51,    31,
      34,    35,    36,    37,    38,    39,    40,    42,    43,    44,
      57,    58,    59,    60,    46,    50,     3,     5,     6,     8,
      13,    14,    15,    17,    74,    75,    76,    77,    78,    79,
      81,    84,    85,    86,    87,    88,    92,    93,    94,    95,
      99,    96,    47,    52,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    95,
     100,   101,   102,    95,    46,    46,    75,    46,    52,    52,
      52,    95,    46,    49,    75,    52,    32,    33,    36,    50,
      54,    56,    47,    55,    47,    51,    95,    95,     5,    95,
      52,    30,    80,    52,    52,    99,    95,    99,    95,    95,
      47,    47,    46,    47,    55,    56,    51,    56,    52,    75,
      75,    95,    48,    99,    95,    56,    95,     4,    47,     9,
      89,    90,    47,    52,    95,    52,    75,    52,    97,    10,
      91,    89,    52,    52,    53,    53,    49,    74,    74
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    61,    62,    63,    63,    64,    64,    64,    65,    66,
      66,    66,    66,    67,    67,    67,    67,    67,    67,    67,
      67,    68,    68,    70,    69,    71,    71,    72,    72,    73,
      73,    73,    74,    74,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    76,    77,    78,
      79,    80,    81,    82,    82,    83,    83,    84,    84,    85,
      85,    86,    87,    88,    89,    89,    90,    91,    92,    92,
      92,    92,    93,    94,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    96,    96,
      96,    96,    97,    98,    99,   100,   100,   101,   101,   102
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     6,     3,
       4,     6,     7,     2,     2,     2,     3,     3,     3,     2,
       3,     1,     1,     0,     7,     1,     1,     3,     1,     2,
       4,     4,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     5,     7,
       7,     1,     4,     2,     1,     3,     6,     5,     7,     2,
       3,     2,     2,     8,     2,     1,     4,     3,     4,     7,
       6,     6,     3,     3,     3,     3,     3,     3,     3,     4,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     2,     2,     2,     2,     1,     4,     4,     1,     1,
       1,     3,     1,     1,     1,     3,     1,     1,     1,     0
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
#line 72 "a.y" /* yacc.c:1646  */
    { int h[1] = {(yyvsp[0].type_id).h}; int d[1] = {(yyvsp[0].type_id).d};			(yyval.type_id).h = getH(1, h); (yyval.type_id).d = getD(1, h, d); 	programDiameter = (yyval.type_id).d + 1; }
#line 1531 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 75 "a.y" /* yacc.c:1646  */
    { int h[2] = {(yyvsp[-1].type_id).h, (yyvsp[0].type_id).h}; int d[2] = {(yyvsp[-1].type_id).d, (yyvsp[0].type_id).d};			(yyval.type_id).h = getH(2, h); (yyval.type_id).d = getD(2, h, d); }
#line 1537 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 76 "a.y" /* yacc.c:1646  */
    { int h[1] = {(yyvsp[0].type_id).h}; int d[1] = {(yyvsp[0].type_id).d};			(yyval.type_id).h = getH(1, h); (yyval.type_id).d = getD(1, h, d); }
#line 1543 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 79 "a.y" /* yacc.c:1646  */
    { int h[1] = {(yyvsp[0].type_id).h}; int d[1] = {(yyvsp[0].type_id).d};			(yyval.type_id).h = getH(1, h); (yyval.type_id).d = getD(1, h, d); }
#line 1549 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 80 "a.y" /* yacc.c:1646  */
    { int h[1] = {(yyvsp[0].type_id).h}; int d[1] = {(yyvsp[0].type_id).d};			(yyval.type_id).h = getH(1, h); (yyval.type_id).d = getD(1, h, d); }
#line 1555 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 81 "a.y" /* yacc.c:1646  */
    { int h[1] = {(yyvsp[0].type_id).h}; int d[1] = {(yyvsp[0].type_id).d};			(yyval.type_id).h = getH(1, h); (yyval.type_id).d = getD(1, h, d); }
#line 1561 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 84 "a.y" /* yacc.c:1646  */
    { int h[6] = {0, (yyvsp[-4].type_id).h, 0, (yyvsp[-2].type_id).h, 0, 0}; int d[6] = {0, (yyvsp[-4].type_id).d, 0, (yyvsp[-2].type_id).d, 0, 0};			(yyval.type_id).h = getH(6, h); (yyval.type_id).d = getD(6, h, d); }
#line 1567 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 87 "a.y" /* yacc.c:1646  */
    { int h[3] = {(yyvsp[-2].type_id).h, (yyvsp[-1].type_id).h, 0}; int d[3] = {(yyvsp[-2].type_id).d, (yyvsp[-1].type_id).d, 0};			(yyval.type_id).h = getH(3, h); (yyval.type_id).d = getD(3, h, d); }
#line 1573 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 88 "a.y" /* yacc.c:1646  */
    { int h[4] = {(yyvsp[-3].type_id).h, (yyvsp[-2].type_id).h, 0, (yyvsp[0].type_id).h}; int d[4] = {(yyvsp[-3].type_id).d, (yyvsp[-2].type_id).d, 0, (yyvsp[0].type_id).d};			(yyval.type_id).h = getH(4, h); (yyval.type_id).d = getD(4, h, d); }
#line 1579 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 89 "a.y" /* yacc.c:1646  */
    { int h[6] = {(yyvsp[-5].type_id).h, (yyvsp[-4].type_id).h, 0, (yyvsp[-2].type_id).h, 0, 0}; int d[6] = {(yyvsp[-5].type_id).d, (yyvsp[-4].type_id).d, 0, (yyvsp[-2].type_id).d, 0, 0};			(yyval.type_id).h = getH(6, h); (yyval.type_id).d = getD(6, h, d); }
#line 1585 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 90 "a.y" /* yacc.c:1646  */
    { int h[7] = {(yyvsp[-6].type_id).h, (yyvsp[-5].type_id).h, 0, (yyvsp[-3].type_id).h, 0, 0, (yyvsp[0].type_id).h}; int d[7] = {(yyvsp[-6].type_id).d, (yyvsp[-5].type_id).d, 0, (yyvsp[-3].type_id).d, 0, 0, (yyvsp[0].type_id).d};			(yyval.type_id).h = getH(7, h); (yyval.type_id).d = getD(7, h, d); }
#line 1591 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 93 "a.y" /* yacc.c:1646  */
    { int h[2] = {(yyvsp[-1].type_id).h, 0}; int d[2] = {(yyvsp[-1].type_id).d, 0};			(yyval.type_id).h = getH(2, h); (yyval.type_id).d = getD(2, h, d); }
#line 1597 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 94 "a.y" /* yacc.c:1646  */
    { int h[2] = {(yyvsp[-1].type_id).h, 0}; int d[2] = {(yyvsp[-1].type_id).d, 0};			(yyval.type_id).h = getH(2, h); (yyval.type_id).d = getD(2, h, d); }
#line 1603 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 95 "a.y" /* yacc.c:1646  */
    { int h[2] = {(yyvsp[-1].type_id).h, 0}; int d[2] = {(yyvsp[-1].type_id).d, 0};			(yyval.type_id).h = getH(2, h); (yyval.type_id).d = getD(2, h, d); }
#line 1609 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 96 "a.y" /* yacc.c:1646  */
    { int h[3] = {(yyvsp[-2].type_id).h, 0, 0}; int d[3] = {(yyvsp[-2].type_id).d, 0, 0};			(yyval.type_id).h = getH(3, h); (yyval.type_id).d = getD(3, h, d); }
#line 1615 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 97 "a.y" /* yacc.c:1646  */
    { int h[3] = {(yyvsp[-2].type_id).h, 0, 0}; int d[3] = {(yyvsp[-2].type_id).d, 0, 0};			(yyval.type_id).h = getH(3, h); (yyval.type_id).d = getD(3, h, d); }
#line 1621 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 98 "a.y" /* yacc.c:1646  */
    { int h[3] = {(yyvsp[-2].type_id).h, 0, 0}; int d[3] = {(yyvsp[-2].type_id).d, 0, 0};			(yyval.type_id).h = getH(3, h); (yyval.type_id).d = getD(3, h, d); }
#line 1627 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 99 "a.y" /* yacc.c:1646  */
    { int h[2] = {0, (yyvsp[0].type_id).h}; int d[2] = {0, (yyvsp[0].type_id).d};			(yyval.type_id).h = getH(2, h); (yyval.type_id).d = getD(2, h, d); }
#line 1633 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 100 "a.y" /* yacc.c:1646  */
    { int h[3] = {0, (yyvsp[-1].type_id).h, 0}; int d[3] = {0, (yyvsp[-1].type_id).d, 0};			(yyval.type_id).h = getH(3, h); (yyval.type_id).d = getD(3, h, d); }
#line 1639 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 103 "a.y" /* yacc.c:1646  */
    { int h[1] = {0}; int d[1] = {0};			(yyval.type_id).h = getH(1, h); (yyval.type_id).d = getD(1, h, d); }
#line 1645 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 104 "a.y" /* yacc.c:1646  */
    { int h[1] = {0}; int d[1] = {0};			(yyval.type_id).h = getH(1, h); (yyval.type_id).d = getD(1, h, d); }
#line 1651 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 107 "a.y" /* yacc.c:1646  */
    { if (mainDetected == 0) updateMain = 1; }
#line 1657 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 107 "a.y" /* yacc.c:1646  */
    { int h[6] = {(yyvsp[-6].type_id).h, (yyvsp[-5].type_id).h, 0, (yyvsp[-2].type_id).h, 0, (yyvsp[0].type_id).h}; int d[6] = {(yyvsp[-6].type_id).d, (yyvsp[-5].type_id).d, 0, (yyvsp[-2].type_id).d, 0, (yyvsp[0].type_id).d};			(yyval.type_id).h = getH(6, h); (yyval.type_id).d = getD(6, h, d); 		if (updateMain == 1) {mainDiameter = max(mainDiameter, (yyval.type_id).d + 1); updateMain = 0;} }
#line 1663 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 110 "a.y" /* yacc.c:1646  */
    { int h[1] = {(yyvsp[0].type_id).h}; int d[1] = {(yyvsp[0].type_id).d};			(yyval.type_id).h = getH(1, h); (yyval.type_id).d = getD(1, h, d); }
#line 1669 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 111 "a.y" /* yacc.c:1646  */
    { int h[1] = {0}; int d[1] = {0};			(yyval.type_id).h = getH(1, h); (yyval.type_id).d = getD(1, h, d); }
#line 1675 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 114 "a.y" /* yacc.c:1646  */
    { int h[3] = {(yyvsp[-2].type_id).h, 0, (yyvsp[0].type_id).h}; int d[3] = {(yyvsp[-2].type_id).d, 0, (yyvsp[0].type_id).d};			(yyval.type_id).h = getH(3, h); (yyval.type_id).d = getD(3, h, d); }
#line 1681 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 115 "a.y" /* yacc.c:1646  */
    { int h[1] = {(yyvsp[0].type_id).h}; int d[1] = {(yyvsp[0].type_id).d};			(yyval.type_id).h = getH(1, h); (yyval.type_id).d = getD(1, h, d); }
#line 1687 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 118 "a.y" /* yacc.c:1646  */
    { int h[2] = {(yyvsp[-1].type_id).h, (yyvsp[0].type_id).h}; int d[2] = {(yyvsp[-1].type_id).d, (yyvsp[0].type_id).d};			(yyval.type_id).h = getH(2, h); (yyval.type_id).d = getD(2, h, d); }
#line 1693 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 119 "a.y" /* yacc.c:1646  */
    { int h[4] = {(yyvsp[-3].type_id).h, (yyvsp[-2].type_id).h, 0, 0}; int d[4] = {(yyvsp[-3].type_id).d, (yyvsp[-2].type_id).d, 0, 0};			(yyval.type_id).h = getH(4, h); (yyval.type_id).d = getD(4, h, d); }
#line 1699 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 120 "a.y" /* yacc.c:1646  */
    { int h[4] = {(yyvsp[-3].type_id).h, 0, 0, (yyvsp[0].type_id).h}; int d[4] = {(yyvsp[-3].type_id).d, 0, 0, (yyvsp[0].type_id).d};			(yyval.type_id).h = getH(4, h); (yyval.type_id).d = getD(4, h, d); }
#line 1705 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 123 "a.y" /* yacc.c:1646  */
    { int h[2] = {(yyvsp[-1].type_id).h, (yyvsp[0].type_id).h}; int d[2] = {(yyvsp[-1].type_id).d, (yyvsp[0].type_id).d};			(yyval.type_id).h = getH(2, h); (yyval.type_id).d = getD(2, h, d); }
#line 1711 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 124 "a.y" /* yacc.c:1646  */
    { int h[1] = {(yyvsp[0].type_id).h}; int d[1] = {(yyvsp[0].type_id).d};			(yyval.type_id).h = getH(1, h); (yyval.type_id).d = getD(1, h, d); }
#line 1717 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 127 "a.y" /* yacc.c:1646  */
    { int h[1] = {(yyvsp[0].type_id).h}; int d[1] = {(yyvsp[0].type_id).d};			(yyval.type_id).h = getH(1, h); (yyval.type_id).d = getD(1, h, d); }
#line 1723 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 128 "a.y" /* yacc.c:1646  */
    { int h[1] = {(yyvsp[0].type_id).h}; int d[1] = {(yyvsp[0].type_id).d};			(yyval.type_id).h = getH(1, h); (yyval.type_id).d = getD(1, h, d); }
#line 1729 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 129 "a.y" /* yacc.c:1646  */
    { int h[1] = {(yyvsp[0].type_id).h}; int d[1] = {(yyvsp[0].type_id).d};			(yyval.type_id).h = getH(1, h); (yyval.type_id).d = getD(1, h, d); }
#line 1735 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 130 "a.y" /* yacc.c:1646  */
    { int h[1] = {(yyvsp[0].type_id).h}; int d[1] = {(yyvsp[0].type_id).d};			(yyval.type_id).h = getH(1, h); (yyval.type_id).d = getD(1, h, d); }
#line 1741 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 131 "a.y" /* yacc.c:1646  */
    { int h[1] = {(yyvsp[0].type_id).h}; int d[1] = {(yyvsp[0].type_id).d};			(yyval.type_id).h = getH(1, h); (yyval.type_id).d = getD(1, h, d); }
#line 1747 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 132 "a.y" /* yacc.c:1646  */
    { int h[1] = {(yyvsp[0].type_id).h}; int d[1] = {(yyvsp[0].type_id).d};			(yyval.type_id).h = getH(1, h); (yyval.type_id).d = getD(1, h, d); }
#line 1753 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 133 "a.y" /* yacc.c:1646  */
    { int h[1] = {(yyvsp[0].type_id).h}; int d[1] = {(yyvsp[0].type_id).d};			(yyval.type_id).h = getH(1, h); (yyval.type_id).d = getD(1, h, d); }
#line 1759 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 134 "a.y" /* yacc.c:1646  */
    { int h[1] = {(yyvsp[0].type_id).h}; int d[1] = {(yyvsp[0].type_id).d};			(yyval.type_id).h = getH(1, h); (yyval.type_id).d = getD(1, h, d); }
#line 1765 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 135 "a.y" /* yacc.c:1646  */
    { int h[1] = {(yyvsp[0].type_id).h}; int d[1] = {(yyvsp[0].type_id).d};			(yyval.type_id).h = getH(1, h); (yyval.type_id).d = getD(1, h, d); }
#line 1771 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 136 "a.y" /* yacc.c:1646  */
    { int h[1] = {(yyvsp[0].type_id).h}; int d[1] = {(yyvsp[0].type_id).d};			(yyval.type_id).h = getH(1, h); (yyval.type_id).d = getD(1, h, d); }
#line 1777 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 137 "a.y" /* yacc.c:1646  */
    { int h[1] = {(yyvsp[0].type_id).h}; int d[1] = {(yyvsp[0].type_id).d};			(yyval.type_id).h = getH(1, h); (yyval.type_id).d = getD(1, h, d); }
#line 1783 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 138 "a.y" /* yacc.c:1646  */
    { int h[1] = {(yyvsp[0].type_id).h}; int d[1] = {(yyvsp[0].type_id).d};			(yyval.type_id).h = getH(1, h); (yyval.type_id).d = getD(1, h, d); }
#line 1789 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 139 "a.y" /* yacc.c:1646  */
    { int h[1] = {(yyvsp[0].type_id).h}; int d[1] = {(yyvsp[0].type_id).d};			(yyval.type_id).h = getH(1, h); (yyval.type_id).d = getD(1, h, d); }
#line 1795 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 142 "a.y" /* yacc.c:1646  */
    { int h[2] = {(yyvsp[-1].type_id).h, 0}; int d[2] = {(yyvsp[-1].type_id).d, 0};			(yyval.type_id).h = getH(2, h); (yyval.type_id).d = getD(2, h, d); }
#line 1801 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 145 "a.y" /* yacc.c:1646  */
    { int h[5] = {0, 0, (yyvsp[-2].type_id).h, 0, (yyvsp[0].type_id).h}; int d[5] = {0, 0, (yyvsp[-2].type_id).d, 0, (yyvsp[0].type_id).d};			(yyval.type_id).h = getH(5, h); (yyval.type_id).d = getD(5, h, d); 		whileDiameter = max(whileDiameter, (yyval.type_id).d + 1); }
#line 1807 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 148 "a.y" /* yacc.c:1646  */
    { int h[7] = {0, (yyvsp[-5].type_id).h, 0, 0, (yyvsp[-2].type_id).h, 0, 0}; int d[7] = {0, (yyvsp[-5].type_id).d, 0, 0, (yyvsp[-2].type_id).d, 0, 0};			(yyval.type_id).h = getH(7, h); (yyval.type_id).d = getD(7, h, d); }
#line 1813 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 151 "a.y" /* yacc.c:1646  */
    { int h[7] = {0, 0, (yyvsp[-4].type_id).h, 0, (yyvsp[-2].type_id).h, 0, 0}; int d[7] = {0, 0, (yyvsp[-4].type_id).d, 0, (yyvsp[-2].type_id).d, 0, 0};			(yyval.type_id).h = getH(7, h); (yyval.type_id).d = getD(7, h, d); }
#line 1819 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 154 "a.y" /* yacc.c:1646  */
    { int h[1] = {0}; int d[1] = {0};			(yyval.type_id).h = getH(1, h); (yyval.type_id).d = getD(1, h, d); }
#line 1825 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 157 "a.y" /* yacc.c:1646  */
    { int h[4] = {0, (yyvsp[-2].type_id).h, (yyvsp[-1].type_id).h, 0}; int d[4] = {0, (yyvsp[-2].type_id).d, (yyvsp[-1].type_id).d, 0};			(yyval.type_id).h = getH(4, h); (yyval.type_id).d = getD(4, h, d); }
#line 1831 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 160 "a.y" /* yacc.c:1646  */
    { int h[2] = {(yyvsp[-1].type_id).h, (yyvsp[0].type_id).h}; int d[2] = {(yyvsp[-1].type_id).d, (yyvsp[0].type_id).d};			(yyval.type_id).h = getH(2, h); (yyval.type_id).d = getD(2, h, d); }
#line 1837 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 161 "a.y" /* yacc.c:1646  */
    { int h[1] = {0}; int d[1] = {0};			(yyval.type_id).h = getH(1, h); (yyval.type_id).d = getD(1, h, d); }
#line 1843 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 164 "a.y" /* yacc.c:1646  */
    { int h[3] = {(yyvsp[-2].type_id).h, (yyvsp[-1].type_id).h, 0}; int d[3] = {(yyvsp[-2].type_id).d, (yyvsp[-1].type_id).d, 0};			(yyval.type_id).h = getH(3, h); (yyval.type_id).d = getD(3, h, d); }
#line 1849 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 165 "a.y" /* yacc.c:1646  */
    { int h[6] = {(yyvsp[-5].type_id).h, (yyvsp[-4].type_id).h, 0, (yyvsp[-2].type_id).h, 0, 0}; int d[6] = {(yyvsp[-5].type_id).d, (yyvsp[-4].type_id).d, 0, (yyvsp[-2].type_id).d, 0, 0};			(yyval.type_id).h = getH(6, h); (yyval.type_id).d = getD(6, h, d); }
#line 1855 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 168 "a.y" /* yacc.c:1646  */
    { int h[5] = {0, 0, (yyvsp[-2].type_id).h, 0, (yyvsp[0].type_id).h}; int d[5] = {0, 0, (yyvsp[-2].type_id).d, 0, (yyvsp[0].type_id).d};			(yyval.type_id).h = getH(5, h); (yyval.type_id).d = getD(5, h, d); 		ifDiameter = max(ifDiameter, (yyval.type_id).d + 1); }
#line 1861 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 169 "a.y" /* yacc.c:1646  */
    { int h[7] = {0, 0, (yyvsp[-4].type_id).h, 0, (yyvsp[-2].type_id).h, 0, (yyvsp[0].type_id).h}; int d[7] = {0, 0, (yyvsp[-4].type_id).d, 0, (yyvsp[-2].type_id).d, 0, (yyvsp[0].type_id).d};			(yyval.type_id).h = getH(7, h); (yyval.type_id).d = getD(7, h, d); 		ifDiameter = max(ifDiameter, (yyval.type_id).d + 1); }
#line 1867 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 172 "a.y" /* yacc.c:1646  */
    { int h[2] = {0, 0}; int d[2] = {0, 0};			(yyval.type_id).h = getH(2, h); (yyval.type_id).d = getD(2, h, d); }
#line 1873 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 173 "a.y" /* yacc.c:1646  */
    { int h[3] = {0, (yyvsp[-1].type_id).h, 0}; int d[3] = {0, (yyvsp[-1].type_id).d, 0};			(yyval.type_id).h = getH(3, h); (yyval.type_id).d = getD(3, h, d); }
#line 1879 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 176 "a.y" /* yacc.c:1646  */
    { int h[2] = {0, 0}; int d[2] = {0, 0};			(yyval.type_id).h = getH(2, h); (yyval.type_id).d = getD(2, h, d); }
#line 1885 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 179 "a.y" /* yacc.c:1646  */
    { int h[2] = {0, 0}; int d[2] = {0, 0};			(yyval.type_id).h = getH(2, h); (yyval.type_id).d = getD(2, h, d); }
#line 1891 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 182 "a.y" /* yacc.c:1646  */
    { int h[8] = {0, 0, (yyvsp[-5].type_id).h, 0, 0, (yyvsp[-2].type_id).h, (yyvsp[-1].type_id).h, 0}; int d[8] = {0, 0, (yyvsp[-5].type_id).d, 0, 0, (yyvsp[-2].type_id).d, (yyvsp[-1].type_id).d, 0};			(yyval.type_id).h = getH(8, h); (yyval.type_id).d = getD(8, h, d); 			switchDiameter = max(switchDiameter, (yyval.type_id).d + 1); }
#line 1897 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 185 "a.y" /* yacc.c:1646  */
    { int h[2] = {(yyvsp[-1].type_id).h, (yyvsp[0].type_id).h}; int d[2] = {(yyvsp[-1].type_id).d, (yyvsp[0].type_id).d};			(yyval.type_id).h = getH(2, h); (yyval.type_id).d = getD(2, h, d); }
#line 1903 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 186 "a.y" /* yacc.c:1646  */
    { int h[1] = {(yyvsp[0].type_id).h}; int d[1] = {(yyvsp[0].type_id).d};			(yyval.type_id).h = getH(1, h); (yyval.type_id).d = getD(1, h, d); }
#line 1909 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 189 "a.y" /* yacc.c:1646  */
    { int h[4] = {0, (yyvsp[-2].type_id).h, 0, (yyvsp[0].type_id).h}; int d[4] = {0, (yyvsp[-2].type_id).d, 0, (yyvsp[0].type_id).d};			(yyval.type_id).h = getH(4, h); (yyval.type_id).d = getD(4, h, d); }
#line 1915 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 192 "a.y" /* yacc.c:1646  */
    { int h[3] = {0, 0, (yyvsp[0].type_id).h}; int d[3] = {0, 0, (yyvsp[0].type_id).d};			(yyval.type_id).h = getH(3, h); (yyval.type_id).d = getD(3, h, d); }
#line 1921 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 194 "a.y" /* yacc.c:1646  */
    { int h[2] = {(yyvsp[-3].type_id).h, (yyvsp[-1].type_id).h}; int d[2] = {(yyvsp[-3].type_id).d, (yyvsp[-1].type_id).d};         (yyval.type_id).h = getH(2, h) + 1; (yyval.type_id).d = max(getD(2, h, d), (yyval.type_id).h + 1); }
#line 1927 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 195 "a.y" /* yacc.c:1646  */
    { int h[3] = {(yyvsp[-6].type_id).h, (yyvsp[-4].type_id).h, (yyvsp[-1].type_id).h}; int d[3] = {(yyvsp[-6].type_id).d, (yyvsp[-4].type_id).d, (yyvsp[-1].type_id).d};         (yyval.type_id).h = getH(3, h) + 1; (yyval.type_id).d = max(getD(3, h, d), (yyval.type_id).h + 1); }
#line 1933 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 196 "a.y" /* yacc.c:1646  */
    { int h[4] = {(yyvsp[-5].type_id).h, (yyvsp[-4].type_id).h, (yyvsp[-3].type_id).h, (yyvsp[-1].type_id).h}; int d[4] = {(yyvsp[-5].type_id).d, (yyvsp[-4].type_id).d, (yyvsp[-3].type_id).d, (yyvsp[-1].type_id).d};         (yyval.type_id).h = getH(4, h) + 1; (yyval.type_id).d = max(getD(4, h, d), (yyval.type_id).h + 1); }
#line 1939 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 197 "a.y" /* yacc.c:1646  */
    { int h[4] = {(yyvsp[-5].type_id).h, (yyvsp[-4].type_id).h, (yyvsp[-3].type_id).h, (yyvsp[-1].type_id).h}; int d[4] = {(yyvsp[-5].type_id).d, (yyvsp[-4].type_id).d, (yyvsp[-3].type_id).d, (yyvsp[-1].type_id).d};         (yyval.type_id).h = getH(4, h) + 1; (yyval.type_id).d = max(getD(4, h, d), (yyval.type_id).h + 1); }
#line 1945 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 200 "a.y" /* yacc.c:1646  */
    { int h[3] = {(yyvsp[-2].type_id).h, 0, 0}; int d[3] = {(yyvsp[-2].type_id).d, 0, 0};			(yyval.type_id).h = getH(3, h); (yyval.type_id).d = getD(3, h, d); }
#line 1951 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 203 "a.y" /* yacc.c:1646  */
    { int h[3] = {(yyvsp[-2].type_id).h, 0, 0}; int d[3] = {(yyvsp[-2].type_id).d, 0, 0};			(yyval.type_id).h = getH(3, h); (yyval.type_id).d = getD(3, h, d); }
#line 1957 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 206 "a.y" /* yacc.c:1646  */
    { (yyval.type_id).h = max((yyvsp[-2].type_id).h, (yyvsp[0].type_id).h) + 2; (yyval.type_id).d = max(max(max((yyvsp[-2].type_id).d, (yyvsp[0].type_id).d), (yyvsp[-2].type_id).h + (yyvsp[0].type_id).h + 2), (yyval.type_id).h); }
#line 1963 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 207 "a.y" /* yacc.c:1646  */
    { (yyval.type_id).h = max((yyvsp[-2].type_id).h, (yyvsp[0].type_id).h) + 2; (yyval.type_id).d = max(max(max((yyvsp[-2].type_id).d, (yyvsp[0].type_id).d), (yyvsp[-2].type_id).h + (yyvsp[0].type_id).h + 2), (yyval.type_id).h); }
#line 1969 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 208 "a.y" /* yacc.c:1646  */
    { (yyval.type_id).h = max((yyvsp[-2].type_id).h, (yyvsp[0].type_id).h) + 2; (yyval.type_id).d = max(max(max((yyvsp[-2].type_id).d, (yyvsp[0].type_id).d), (yyvsp[-2].type_id).h + (yyvsp[0].type_id).h + 2), (yyval.type_id).h); }
#line 1975 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 209 "a.y" /* yacc.c:1646  */
    { (yyval.type_id).h = max((yyvsp[-2].type_id).h, (yyvsp[0].type_id).h) + 2; (yyval.type_id).d = max(max(max((yyvsp[-2].type_id).d, (yyvsp[0].type_id).d), (yyvsp[-2].type_id).h + (yyvsp[0].type_id).h + 2), (yyval.type_id).h); }
#line 1981 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 210 "a.y" /* yacc.c:1646  */
    { (yyval.type_id).h = max((yyvsp[-2].type_id).h, (yyvsp[0].type_id).h) + 2; (yyval.type_id).d = max(max(max((yyvsp[-2].type_id).d, (yyvsp[0].type_id).d), (yyvsp[-2].type_id).h + (yyvsp[0].type_id).h + 2), (yyval.type_id).h); }
#line 1987 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 211 "a.y" /* yacc.c:1646  */
    { int h[4] = {0, 0, (yyvsp[-1].type_id).h, 0}; int d[4] = {0, 0, (yyvsp[-1].type_id).d, 0};			(yyval.type_id).h = getH(4, h); (yyval.type_id).d = getD(4, h, d); }
#line 1993 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 212 "a.y" /* yacc.c:1646  */
    { (yyval.type_id).h = max((yyvsp[-2].type_id).h, (yyvsp[0].type_id).h) + 2; (yyval.type_id).d = max(max(max((yyvsp[-2].type_id).d, (yyvsp[0].type_id).d), (yyvsp[-2].type_id).h + (yyvsp[0].type_id).h + 2), (yyval.type_id).h); }
#line 1999 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 213 "a.y" /* yacc.c:1646  */
    { (yyval.type_id).h = max((yyvsp[-2].type_id).h, (yyvsp[0].type_id).h) + 2; (yyval.type_id).d = max(max(max((yyvsp[-2].type_id).d, (yyvsp[0].type_id).d), (yyvsp[-2].type_id).h + (yyvsp[0].type_id).h + 2), (yyval.type_id).h); }
#line 2005 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 214 "a.y" /* yacc.c:1646  */
    { (yyval.type_id).h = max((yyvsp[-2].type_id).h, (yyvsp[0].type_id).h) + 2; (yyval.type_id).d = max(max(max((yyvsp[-2].type_id).d, (yyvsp[0].type_id).d), (yyvsp[-2].type_id).h + (yyvsp[0].type_id).h + 2), (yyval.type_id).h); }
#line 2011 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 215 "a.y" /* yacc.c:1646  */
    { (yyval.type_id).h = max((yyvsp[-2].type_id).h, (yyvsp[0].type_id).h) + 2; (yyval.type_id).d = max(max(max((yyvsp[-2].type_id).d, (yyvsp[0].type_id).d), (yyvsp[-2].type_id).h + (yyvsp[0].type_id).h + 2), (yyval.type_id).h); }
#line 2017 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 216 "a.y" /* yacc.c:1646  */
    { (yyval.type_id).h = max((yyvsp[-2].type_id).h, (yyvsp[0].type_id).h) + 2; (yyval.type_id).d = max(max(max((yyvsp[-2].type_id).d, (yyvsp[0].type_id).d), (yyvsp[-2].type_id).h + (yyvsp[0].type_id).h + 2), (yyval.type_id).h); }
#line 2023 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 217 "a.y" /* yacc.c:1646  */
    { (yyval.type_id).h = max((yyvsp[-2].type_id).h, (yyvsp[0].type_id).h) + 2; (yyval.type_id).d = max(max(max((yyvsp[-2].type_id).d, (yyvsp[0].type_id).d), (yyvsp[-2].type_id).h + (yyvsp[0].type_id).h + 2), (yyval.type_id).h); }
#line 2029 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 218 "a.y" /* yacc.c:1646  */
    { (yyval.type_id).h = max((yyvsp[-2].type_id).h, (yyvsp[0].type_id).h) + 2; (yyval.type_id).d = max(max(max((yyvsp[-2].type_id).d, (yyvsp[0].type_id).d), (yyvsp[-2].type_id).h + (yyvsp[0].type_id).h + 2), (yyval.type_id).h); }
#line 2035 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 219 "a.y" /* yacc.c:1646  */
    { (yyval.type_id).h = max((yyvsp[-2].type_id).h, (yyvsp[0].type_id).h) + 2; (yyval.type_id).d = max(max(max((yyvsp[-2].type_id).d, (yyvsp[0].type_id).d), (yyvsp[-2].type_id).h + (yyvsp[0].type_id).h + 2), (yyval.type_id).h); }
#line 2041 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 220 "a.y" /* yacc.c:1646  */
    { (yyval.type_id).h = max((yyvsp[-2].type_id).h, (yyvsp[0].type_id).h) + 2; (yyval.type_id).d = max(max(max((yyvsp[-2].type_id).d, (yyvsp[0].type_id).d), (yyvsp[-2].type_id).h + (yyvsp[0].type_id).h + 2), (yyval.type_id).h); }
#line 2047 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 221 "a.y" /* yacc.c:1646  */
    { (yyval.type_id).h = max((yyvsp[-2].type_id).h, (yyvsp[0].type_id).h) + 2; (yyval.type_id).d = max(max(max((yyvsp[-2].type_id).d, (yyvsp[0].type_id).d), (yyvsp[-2].type_id).h + (yyvsp[0].type_id).h + 2), (yyval.type_id).h); }
#line 2053 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 222 "a.y" /* yacc.c:1646  */
    { int h[2] = {0, (yyvsp[0].type_id).h}; int d[2] = {0, (yyvsp[0].type_id).d};			(yyval.type_id).h = getH(2, h); (yyval.type_id).d = getD(2, h, d); }
#line 2059 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 223 "a.y" /* yacc.c:1646  */
    { int h[2] = {0, (yyvsp[0].type_id).h}; int d[2] = {0, (yyvsp[0].type_id).d};			(yyval.type_id).h = getH(2, h); (yyval.type_id).d = getD(2, h, d); }
#line 2065 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 224 "a.y" /* yacc.c:1646  */
    { int h[2] = {0, (yyvsp[0].type_id).h}; int d[2] = {0, (yyvsp[0].type_id).d};			(yyval.type_id).h = getH(2, h); (yyval.type_id).d = getD(2, h, d); }
#line 2071 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 225 "a.y" /* yacc.c:1646  */
    { int h[2] = {0, (yyvsp[0].type_id).h}; int d[2] = {0, (yyvsp[0].type_id).d};			(yyval.type_id).h = getH(2, h); (yyval.type_id).d = getD(2, h, d); }
#line 2077 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 226 "a.y" /* yacc.c:1646  */
    { int h[2] = {0, (yyvsp[0].type_id).h}; int d[2] = {0, (yyvsp[0].type_id).d};			(yyval.type_id).h = getH(2, h); (yyval.type_id).d = getD(2, h, d); }
#line 2083 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 227 "a.y" /* yacc.c:1646  */
    { int h[1] = {(yyvsp[0].type_id).h}; int d[1] = {(yyvsp[0].type_id).d};			(yyval.type_id).h = getH(1, h); (yyval.type_id).d = getD(1, h, d); }
#line 2089 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 228 "a.y" /* yacc.c:1646  */
    { int h[4] = {(yyvsp[-3].type_id).h, 0, (yyvsp[-1].type_id).h, 0}; int d[4] = {(yyvsp[-3].type_id).d, 0, (yyvsp[-1].type_id).d, 0};			(yyval.type_id).h = getH(4, h); (yyval.type_id).d = getD(4, h, d); }
#line 2095 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 229 "a.y" /* yacc.c:1646  */
    { int h[4] = {(yyvsp[-3].type_id).h, 0, (yyvsp[-1].type_id).h, 0}; int d[4] = {(yyvsp[-3].type_id).d, 0, (yyvsp[-1].type_id).d, 0};			(yyval.type_id).h = getH(4, h); (yyval.type_id).d = getD(4, h, d); }
#line 2101 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 232 "a.y" /* yacc.c:1646  */
    { int h[1] = {(yyvsp[0].type_id).h}; int d[1] = {(yyvsp[0].type_id).d};			(yyval.type_id).h = getH(1, h); (yyval.type_id).d = getD(1, h, d); }
#line 2107 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 233 "a.y" /* yacc.c:1646  */
    { int h[1] = {(yyvsp[0].type_id).h}; int d[1] = {(yyvsp[0].type_id).d};			(yyval.type_id).h = getH(1, h); (yyval.type_id).d = getD(1, h, d); }
#line 2113 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 234 "a.y" /* yacc.c:1646  */
    { int h[1] = {(yyvsp[0].type_id).h}; int d[1] = {(yyvsp[0].type_id).d};			(yyval.type_id).h = getH(1, h); (yyval.type_id).d = getD(1, h, d); }
#line 2119 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 235 "a.y" /* yacc.c:1646  */
    { int h[3] = {0, (yyvsp[-1].type_id).h, 0}; int d[3] = {0, (yyvsp[-1].type_id).d, 0};			(yyval.type_id).h = getH(3, h); (yyval.type_id).d = getD(3, h, d); }
#line 2125 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 238 "a.y" /* yacc.c:1646  */
    { int h[1] = {0}; int d[1] = {0};			(yyval.type_id).h = getH(1, h); (yyval.type_id).d = getD(1, h, d); }
#line 2131 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 241 "a.y" /* yacc.c:1646  */
    { int h[1] = {0}; int d[1] = {0};			(yyval.type_id).h = getH(1, h); (yyval.type_id).d = getD(1, h, d); }
#line 2137 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 244 "a.y" /* yacc.c:1646  */
    { int h[1] = {0}; int d[1] = {0};			(yyval.type_id).h = getH(1, h); (yyval.type_id).d = getD(1, h, d); }
#line 2143 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 247 "a.y" /* yacc.c:1646  */
    { int h[3] = {(yyvsp[-2].type_id).h, 0, (yyvsp[0].type_id).h}; int d[3] = {(yyvsp[-2].type_id).d, 0, (yyvsp[0].type_id).d};			(yyval.type_id).h = getH(3, h); (yyval.type_id).d = getD(3, h, d); }
#line 2149 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 248 "a.y" /* yacc.c:1646  */
    { int h[1] = {(yyvsp[0].type_id).h}; int d[1] = {(yyvsp[0].type_id).d};			(yyval.type_id).h = getH(1, h); (yyval.type_id).d = getD(1, h, d); }
#line 2155 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 251 "a.y" /* yacc.c:1646  */
    { int h[1] = {(yyvsp[0].type_id).h}; int d[1] = {(yyvsp[0].type_id).d};			(yyval.type_id).h = getH(1, h); (yyval.type_id).d = getD(1, h, d); }
#line 2161 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 252 "a.y" /* yacc.c:1646  */
    { int h[1] = {0}; int d[1] = {0};			(yyval.type_id).h = getH(1, h); (yyval.type_id).d = getD(1, h, d); }
#line 2167 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 255 "a.y" /* yacc.c:1646  */
    { (yyval.type_id).h = 0; (yyval.type_id).d = 0; }
#line 2173 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2177 "y.tab.c" /* yacc.c:1646  */
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
#line 257 "a.y" /* yacc.c:1906  */


void yyerror(char *s) {
    printf("syntax error\n");
	error = 1;
	exit(error);
}


int main(void) {
    yyparse();
	//fprintf(stdout, "parsed successfully\n");
	if (error == 0) {
		fprintf(stdout, "%d\n%d\n%d\n%d\n%d\n", programDiameter, ifDiameter, whileDiameter, switchDiameter, mainDiameter);
	}
    return 0;
}

