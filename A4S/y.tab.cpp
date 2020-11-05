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
#line 4 "a.y" /* yacc.c:339  */

    #include <bits/stdc++.h>
    #include "IRGenerator.hpp"
    using namespace std;
    void yyerror(char*);
    int yylex(void);
    void set_programLongestPath(int); // Set Longest Path in the program
    void set_ifLongestPath(int);      // Set Longest Path among all subtrees of if statement
    void set_whileLongestPath(int);   // Set Longest Path among all subtrees of while statement
    void set_mainLongestPath(int);    // Set Longest Path of main subtee
    void set_switchLongestPath(int);  // Set Longest Path among all subtrees of switch statement
    void remove_unused_vars(treeNode*); // Delete unused var declarations from the ast  
    void constants_and_if_simple(treeNode*);    // perform constant propagation, constant folding and static if simplification
    void staticCalc(treeNode *expr, map<string, int> &variableValues);
    treeNode* makeIntegerLitexpr(int n, bool P);
    void simplifyExpr(treeNode *expr);
    treeNode* placeholder_stmt();

    extern FILE* yyin;
    char mytext[10000];
    int programLongestPath = 0;
    int ifLongestPath = 0;
    int whileLongestPath = 0;
    int mainLongestPath = 0;
    int switchLongestPath = 0;
    int isMain = 0;  
    extern char* yytext;
    treeNode* ast;   // pointer to the root of the final abstract syntax tree   
    stack<string> unused_vars;

#line 97 "y.tab.cpp" /* yacc.c:339  */

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
   by #include "y.tab.hpp".  */
#ifndef YY_YY_Y_TAB_HPP_INCLUDED
# define YY_YY_Y_TAB_HPP_INCLUDED
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
    IDENTIFIER = 258,
    INTEGER_NUMBER = 259,
    FLOAT_NUMBER = 260,
    PLUS = 261,
    MINUS = 262,
    MULT = 263,
    DIV = 264,
    IF = 265,
    ELSE = 266,
    FOR = 267,
    WHILE = 268,
    DO = 269,
    INT = 270,
    FLOAT = 271,
    CHAR = 272,
    EQ = 273,
    EQEQ = 274,
    GEQ = 275,
    LEQ = 276,
    GT = 277,
    LT = 278,
    NEWOP = 279,
    NEQ = 280,
    BITAND = 281,
    BITOR = 282,
    BITNOT = 283,
    BITXOR = 284,
    AND = 285,
    OR = 286,
    NOT = 287,
    MOD = 288,
    EXTERN = 289,
    LONG = 290,
    SHORT = 291,
    DOUBLE = 292,
    PRINTF = 293,
    PERCENTD = 294,
    VOID = 295,
    SWITCH = 296,
    CASE = 297,
    STRUCT = 298,
    BREAK = 299,
    CONTINUE = 300,
    RETURN = 301,
    STRLITERAL = 302,
    CHARLITERAL = 303,
    INC = 304,
    DEC = 305,
    ARROW = 306,
    SIZEOF = 307,
    DEFAULT = 308
  };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define INTEGER_NUMBER 259
#define FLOAT_NUMBER 260
#define PLUS 261
#define MINUS 262
#define MULT 263
#define DIV 264
#define IF 265
#define ELSE 266
#define FOR 267
#define WHILE 268
#define DO 269
#define INT 270
#define FLOAT 271
#define CHAR 272
#define EQ 273
#define EQEQ 274
#define GEQ 275
#define LEQ 276
#define GT 277
#define LT 278
#define NEWOP 279
#define NEQ 280
#define BITAND 281
#define BITOR 282
#define BITNOT 283
#define BITXOR 284
#define AND 285
#define OR 286
#define NOT 287
#define MOD 288
#define EXTERN 289
#define LONG 290
#define SHORT 291
#define DOUBLE 292
#define PRINTF 293
#define PERCENTD 294
#define VOID 295
#define SWITCH 296
#define CASE 297
#define STRUCT 298
#define BREAK 299
#define CONTINUE 300
#define RETURN 301
#define STRLITERAL 302
#define CHARLITERAL 303
#define INC 304
#define DEC 305
#define ARROW 306
#define SIZEOF 307
#define DEFAULT 308

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 35 "a.y" /* yacc.c:355  */

    class treeNode* node;

#line 247 "y.tab.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 264 "y.tab.cpp" /* yacc.c:358  */

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
#define YYLAST   325

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  64
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  105
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  219

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   308

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
      56,    57,     2,     2,    59,     2,    63,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    60,    58,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    54,     2,    55,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    61,     2,    62,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   142,   142,   149,   154,   159,   164,   169,   174,   181,
     187,   193,   199,   205,   210,   217,   224,   230,   236,   242,
     247,   253,   258,   264,   273,   277,   283,   288,   293,   297,
     303,   307,   312,   316,   320,   324,   328,   332,   336,   340,
     344,   348,   352,   356,   361,   369,   376,   383,   389,   395,
     399,   405,   410,   416,   423,   431,   436,   442,   448,   454,
     463,   467,   472,   478,   484,   492,   499,   507,   516,   523,
     530,   536,   542,   548,   554,   560,   565,   571,   577,   583,
     589,   595,   601,   607,   613,   619,   625,   630,   635,   640,
     645,   650,   654,   659,   665,   669,   673,   677,   683,   691,
     699,   705,   712,   717,   722,   726
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "INTEGER_NUMBER",
  "FLOAT_NUMBER", "PLUS", "MINUS", "MULT", "DIV", "IF", "ELSE", "FOR",
  "WHILE", "DO", "INT", "FLOAT", "CHAR", "EQ", "EQEQ", "GEQ", "LEQ", "GT",
  "LT", "NEWOP", "NEQ", "BITAND", "BITOR", "BITNOT", "BITXOR", "AND", "OR",
  "NOT", "MOD", "EXTERN", "LONG", "SHORT", "DOUBLE", "PRINTF", "PERCENTD",
  "VOID", "SWITCH", "CASE", "STRUCT", "BREAK", "CONTINUE", "RETURN",
  "STRLITERAL", "CHARLITERAL", "INC", "DEC", "ARROW", "SIZEOF", "DEFAULT",
  "'['", "']'", "'('", "')'", "';'", "','", "':'", "'{'", "'}'", "'.'",
  "$accept", "program", "decl_list", "decl", "struct_decl", "var_decl",
  "type_spec", "extern_spec", "func_decl", "params", "param_list", "param",
  "stmt_list", "stmt", "while_stmt", "dowhile_stmt", "print_stmt",
  "format_specifier", "compound_stmt", "local_decls", "local_decl",
  "if_stmt", "return_stmt", "break_stmt", "continue_stmt", "switch_stmt",
  "compound_case", "single_case", "default_case", "assign_stmt",
  "incr_stmt", "decr_stmt", "expr", "Pexpr", "integerLit", "floatLit",
  "identifier", "arg_list", "args", YY_NULLPTR
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
     305,   306,   307,   308,    91,    93,    40,    41,    59,    44,
      58,   123,   125,    46
};
# endif

#define YYPACT_NINF -146

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-146)))

#define YYTABLE_NINF -26

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -17,  -146,     1,    33,    53,  -146,  -146,  -146,     1,    19,
    -146,  -146,  -146,    -1,  -146,  -146,    35,    42,    63,    65,
    -146,  -146,    15,    -6,  -146,   -11,  -146,  -146,  -146,   -21,
    -146,    20,     1,     1,    29,    39,  -146,  -146,     1,    34,
       1,  -146,     9,    92,    49,    46,   -11,    43,  -146,     7,
    -146,   -11,    54,  -146,  -146,  -146,   236,  -146,  -146,  -146,
     184,  -146,     6,     6,     6,     6,     6,    48,   236,    55,
     274,  -146,  -146,   -36,    52,    56,    11,    62,    68,    69,
      70,   200,     2,  -146,  -146,  -146,  -146,  -146,  -146,  -146,
    -146,  -146,  -146,  -146,  -146,  -146,    27,  -146,  -146,  -146,
    -146,  -146,  -146,     6,    72,    73,     6,     6,     6,     6,
       6,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       6,   236,   236,   236,   236,    98,    87,   236,  -146,  -146,
    -146,    75,  -146,  -146,   236,    76,    81,     1,   236,     1,
      83,  -146,  -146,  -146,  -146,  -146,  -146,  -146,  -146,  -146,
    -146,  -146,  -146,  -146,  -146,  -146,  -146,  -146,    86,  -146,
      71,    88,    90,    93,    95,  -146,    94,   115,  -146,    91,
    -146,  -146,   134,   100,   155,  -146,  -146,   236,  -146,    11,
      11,   236,     1,   113,  -146,   236,   158,   236,  -146,   171,
    -146,   127,   132,   148,   133,   236,   138,    11,   141,   142,
      15,   149,   148,  -146,   143,  -146,  -146,  -146,  -146,   150,
     151,   157,  -146,  -146,    11,    11,  -146,    11,    11
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      22,    21,     0,     0,    22,     4,     7,     5,     0,     0,
       6,   100,   101,    19,     1,     3,     0,    14,    15,    13,
      20,    50,     0,    22,     9,    22,    17,    18,    16,    22,
      98,     0,     0,     0,     0,    24,    27,    10,     0,     0,
       0,    49,     0,    19,    28,     0,    22,     0,     8,     0,
      11,    22,     0,    50,    23,    26,     0,    51,    12,    29,
      22,    99,     0,     0,     0,     0,     0,     0,     0,     0,
      91,    94,    95,    96,     0,     0,     0,   101,     0,     0,
       0,     0,     0,    31,    35,    40,    41,    33,    34,    37,
      38,    39,    36,    32,    42,    43,     0,    88,    96,    87,
      89,    90,    86,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   105,     0,     0,     0,     0,     0,    57,    58,
      55,     0,    48,    30,     0,     0,     0,     0,     0,     0,
       0,    97,    52,    81,    82,    83,    84,    76,    73,    72,
      71,    70,    78,    77,    79,    74,    85,    80,     0,   103,
     104,     0,     0,     0,     0,    47,     0,     0,    56,     0,
      68,    69,     0,     0,     0,    75,    93,     0,    92,     0,
       0,     0,     0,     0,    64,     0,     0,     0,   102,    53,
      44,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    61,    66,     0,    67,    54,    45,    46,     0,
       0,     0,    60,    65,     0,     0,    59,    62,    63
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -146,  -146,  -146,   213,  -146,   -24,   163,  -146,  -146,  -146,
    -146,   174,  -145,   -74,  -146,  -146,  -146,  -146,   176,   178,
    -146,  -146,  -146,  -146,  -146,  -146,    22,  -146,  -146,  -146,
    -146,  -146,   -39,    51,   -19,  -146,    -2,  -146,  -146
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,     6,     7,     8,     9,    10,    34,
      35,    36,    82,    83,    84,    85,    86,   166,    87,    29,
      41,    88,    89,    90,    91,    92,   201,   202,   211,    93,
      94,    95,    69,    70,    71,    72,    98,   160,   161
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      13,    37,   125,    31,    11,    11,    16,    20,   133,    11,
      30,    61,    74,     1,    11,    75,    76,     1,   121,    30,
     122,    74,    32,     1,    75,    76,     2,    58,     1,   104,
      43,    44,    32,    14,    17,    18,    47,    32,    49,    12,
      77,    39,   131,    78,    12,   134,    79,    80,    81,    77,
      26,   -25,    78,    -2,    73,    79,    80,    81,    96,    19,
      21,    56,    68,    53,   132,    57,    73,    50,    51,   217,
     218,    27,    53,    28,    96,    42,   135,   136,   137,    73,
      96,   138,   158,   159,   162,   163,    45,     1,   167,    22,
     139,    23,    48,    24,    25,   169,     2,    22,    46,   173,
      20,    24,    25,    52,   103,   189,   190,    53,   123,    59,
     105,   164,   124,    97,    99,   100,   101,   102,   126,    73,
      73,    73,    73,   206,   127,    73,   165,   128,   129,   141,
     177,   142,    73,   168,   170,   172,    73,   174,   188,   171,
     175,   176,   191,   133,   133,   178,   194,   179,   196,   184,
     180,   181,   185,   182,   140,   186,   204,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   183,   187,   193,    73,   195,    96,    96,    73,
     192,   209,   197,    73,   198,    73,    33,    11,    38,   199,
     200,   203,    40,    73,    74,    96,   205,    75,    76,   207,
     208,   213,   210,    11,    30,    61,    62,    63,    64,    33,
     214,   215,    96,    96,    38,    96,    96,    15,     1,   216,
      55,    54,    77,    40,   212,    78,    65,    32,    79,    80,
      81,    60,    66,     0,     0,     0,     0,     0,    12,    11,
      30,    61,    62,    63,    64,    53,     0,     0,     0,     0,
       0,     0,    67,     0,     0,     0,    68,     0,   130,     0,
       0,     0,    65,     0,     0,     0,     0,     0,    66,     0,
       0,     0,     0,     0,    12,     0,     0,     0,     0,     0,
     106,   107,   108,   109,     0,     0,     0,     0,    67,     0,
       0,     0,    68,   110,   111,   112,   113,   114,   115,   116,
       0,     0,     0,     0,   117,   118,     0,   119,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   120
};

static const yytype_int16 yycheck[] =
{
       2,    25,    76,    22,     3,     3,     8,     8,    82,     3,
       4,     5,    10,    34,     3,    13,    14,    34,    54,     4,
      56,    10,    43,    34,    13,    14,    43,    51,    34,    68,
      32,    33,    43,     0,    15,    16,    38,    43,    40,    38,
      38,    62,    81,    41,    38,    18,    44,    45,    46,    38,
       8,    57,    41,     0,    56,    44,    45,    46,    60,    40,
      61,    54,    56,    61,    62,    58,    68,    58,    59,   214,
     215,     8,    61,     8,    76,    55,    49,    50,    51,    81,
      82,    54,   121,   122,   123,   124,    57,    34,   127,    54,
      63,    56,    58,    58,    59,   134,    43,    54,    59,   138,
       8,    58,    59,    54,    56,   179,   180,    61,    56,    55,
      55,    13,    56,    62,    63,    64,    65,    66,    56,   121,
     122,   123,   124,   197,    56,   127,    39,    58,    58,    57,
      59,    58,   134,    58,    58,   137,   138,   139,   177,    58,
      57,    55,   181,   217,   218,    57,   185,    57,   187,    58,
      57,    56,    18,    59,   103,    55,   195,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,    57,    18,    61,   177,    18,   179,   180,   181,
     182,   200,    11,   185,    57,   187,    23,     3,    25,    57,
      42,    58,    29,   195,    10,   197,    58,    13,    14,    58,
      58,    58,    53,     3,     4,     5,     6,     7,     8,    46,
      60,    60,   214,   215,    51,   217,   218,     4,    34,    62,
      46,    45,    38,    60,   202,    41,    26,    43,    44,    45,
      46,    53,    32,    -1,    -1,    -1,    -1,    -1,    38,     3,
       4,     5,     6,     7,     8,    61,    -1,    -1,    -1,    -1,
      -1,    -1,    52,    -1,    -1,    -1,    56,    -1,    58,    -1,
      -1,    -1,    26,    -1,    -1,    -1,    -1,    -1,    32,    -1,
      -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,
       6,     7,     8,     9,    -1,    -1,    -1,    -1,    52,    -1,
      -1,    -1,    56,    19,    20,    21,    22,    23,    24,    25,
      -1,    -1,    -1,    -1,    30,    31,    -1,    33,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    51
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    34,    43,    65,    66,    67,    68,    69,    70,    71,
      72,     3,    38,   100,     0,    67,   100,    15,    16,    40,
       8,    61,    54,    56,    58,    59,     8,     8,     8,    83,
       4,    98,    43,    70,    73,    74,    75,    69,    70,    62,
      70,    84,    55,   100,   100,    57,    59,   100,    58,   100,
      58,    59,    54,    61,    82,    75,    54,    58,    69,    55,
      83,     5,     6,     7,     8,    26,    32,    52,    56,    96,
      97,    98,    99,   100,    10,    13,    14,    38,    41,    44,
      45,    46,    76,    77,    78,    79,    80,    82,    85,    86,
      87,    88,    89,    93,    94,    95,   100,    97,   100,    97,
      97,    97,    97,    56,    96,    55,     6,     7,     8,     9,
      19,    20,    21,    22,    23,    24,    25,    30,    31,    33,
      51,    54,    56,    56,    56,    77,    56,    56,    58,    58,
      58,    96,    62,    77,    18,    49,    50,    51,    54,    63,
      97,    57,    58,    97,    97,    97,    97,    97,    97,    97,
      97,    97,    97,    97,    97,    97,    97,    97,    96,    96,
     101,   102,    96,    96,    13,    39,    81,    96,    58,    96,
      58,    58,   100,    96,   100,    57,    55,    59,    57,    57,
      57,    56,    59,    57,    58,    18,    55,    18,    96,    77,
      77,    96,   100,    61,    96,    18,    96,    11,    57,    57,
      42,    90,    91,    58,    96,    58,    77,    58,    58,    98,
      53,    92,    90,    58,    60,    60,    62,    76,    76
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    64,    65,    66,    66,    67,    67,    67,    68,    69,
      69,    69,    69,    70,    70,    70,    70,    70,    70,    70,
      70,    71,    71,    72,    73,    73,    74,    74,    75,    75,
      76,    76,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    78,    79,    80,    81,    82,    83,
      83,    84,    84,    85,    85,    86,    86,    87,    88,    89,
      90,    90,    91,    92,    93,    93,    93,    93,    94,    95,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    97,    97,    97,    97,    98,    99,
     100,   100,   101,   101,   102,   102
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     6,     3,
       4,     6,     7,     2,     2,     2,     3,     3,     3,     2,
       3,     1,     0,     6,     1,     0,     3,     1,     2,     4,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     5,     7,     7,     1,     4,     2,
       0,     3,     6,     5,     7,     2,     3,     2,     2,     8,
       2,     1,     4,     3,     4,     7,     6,     6,     3,     3,
       3,     3,     3,     3,     3,     4,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     2,     2,     2,
       2,     1,     4,     4,     1,     1,     1,     3,     1,     1,
       1,     1,     3,     1,     1,     0
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
#line 142 "a.y" /* yacc.c:1646  */
    {
                        vector<treeNode*> v = {(yyvsp[0].node)};
                        (yyval.node) = new treeNode("program", v); 
                        set_programLongestPath((yyval.node)->maxSubtreeLength);
                        ast = (yyval.node);
                    }
#line 1522 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 149 "a.y" /* yacc.c:1646  */
    { 
                                vector<treeNode*> v = {(yyvsp[-1].node), (yyvsp[0].node)};
                                (yyval.node) = new treeNode("decl_list", v); 
                            }
#line 1531 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 154 "a.y" /* yacc.c:1646  */
    {
                    vector<treeNode*> v = {(yyvsp[0].node)};
                    (yyval.node) = new treeNode("decl_list", v); 
                }
#line 1540 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 159 "a.y" /* yacc.c:1646  */
    {   
                    vector<treeNode*> v = {(yyvsp[0].node)};
                    (yyval.node) = new treeNode("decl", v); 
                }
#line 1549 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 164 "a.y" /* yacc.c:1646  */
    {
                    vector<treeNode*> v = {(yyvsp[0].node)};
                    (yyval.node) = new treeNode("decl", v); 
                }
#line 1558 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 169 "a.y" /* yacc.c:1646  */
    {
                        vector<treeNode*> v = {(yyvsp[0].node)};
                        (yyval.node) = new treeNode("decl", v); 
                    }
#line 1567 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 174 "a.y" /* yacc.c:1646  */
    {
                                                            (yyvsp[-5].node) = new treeNode("STRUCT"); (yyvsp[-3].node) = new treeNode("{"); 
                                                            (yyvsp[-1].node) = new treeNode("}"); (yyvsp[0].node) = new treeNode(";");
                                                            vector<treeNode*> v = {(yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                                            (yyval.node) = new treeNode("struct_decl", v); 
                                                        }
#line 1578 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 181 "a.y" /* yacc.c:1646  */
    {
                                        (yyvsp[0].node) = new treeNode(";");
                                        vector<treeNode*> v = {(yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                        (yyval.node) = new treeNode("var_decl", v); 
                                    }
#line 1588 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 187 "a.y" /* yacc.c:1646  */
    {
                                                (yyvsp[-1].node) = new treeNode(",");
                                                vector<treeNode*> v = {(yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                                (yyval.node) = new treeNode("var_decl", v); 
                                            }
#line 1598 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 193 "a.y" /* yacc.c:1646  */
    {
                                                            (yyvsp[-3].node) = new treeNode("["); (yyvsp[-1].node) = new treeNode("]"); (yyvsp[0].node) = new treeNode(";");
                                                            vector<treeNode*> v = {(yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                                            (yyval.node) = new treeNode("var_decl", v); 
                                                        }
#line 1608 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 199 "a.y" /* yacc.c:1646  */
    {
                                                                    (yyvsp[-4].node) = new treeNode("["); (yyvsp[-2].node) = new treeNode("]"); (yyvsp[-1].node) = new treeNode(",");
                                                                    vector<treeNode*> v = {(yyvsp[-6].node), (yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                                                    (yyval.node) = new treeNode("var_decl", v); 
                                                                }
#line 1618 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 205 "a.y" /* yacc.c:1646  */
    {
                                (yyvsp[0].node) = new treeNode("VOID");
                                vector<treeNode*> v = {(yyvsp[-1].node), (yyvsp[0].node)}; 
                                (yyval.node) = new treeNode("type_spec", v); 
                            }
#line 1628 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 210 "a.y" /* yacc.c:1646  */
    {
                                (yyvsp[0].node) = new treeNode("INT");
                                vector<treeNode*> v = {(yyvsp[-1].node), (yyvsp[0].node)}; 
                                (yyval.node) = new treeNode("type_spec", v);
                                (yyval.node)->width = 4;
                            }
#line 1639 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 217 "a.y" /* yacc.c:1646  */
    {
                                    (yyvsp[0].node) = new treeNode("FLOAT");
                                    vector<treeNode*> v = {(yyvsp[-1].node), (yyvsp[0].node)}; 
                                    (yyval.node) = new treeNode("type_spec", v);
                                    (yyval.node)->width = 8;
                                }
#line 1650 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 224 "a.y" /* yacc.c:1646  */
    {
                                    (yyvsp[-1].node) = new treeNode("VOID"); (yyvsp[0].node) = new treeNode("MULT");
                                    vector<treeNode*> v = {(yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)}; 
                                    (yyval.node) = new treeNode("type_spec", v);
                                }
#line 1660 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 230 "a.y" /* yacc.c:1646  */
    {
                                    (yyvsp[-1].node) = new treeNode("INT"); (yyvsp[0].node) = new treeNode("MULT");
                                    vector<treeNode*> v = {(yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)}; 
                                    (yyval.node) = new treeNode("type_spec", v);
                                }
#line 1670 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 236 "a.y" /* yacc.c:1646  */
    {
                                    (yyvsp[-1].node) = new treeNode("FLOAT"); (yyvsp[0].node) = new treeNode("MULT");
                                    vector<treeNode*> v = {(yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)}; 
                                    (yyval.node) = new treeNode("type_spec", v);
                                  }
#line 1680 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 242 "a.y" /* yacc.c:1646  */
    {
                                    (yyvsp[-1].node) = new treeNode("STRUCT");
                                    vector<treeNode*> v = {(yyvsp[-1].node), (yyvsp[0].node)};
                                    (yyval.node) = new treeNode("type_spec", v); 
                                }
#line 1690 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 247 "a.y" /* yacc.c:1646  */
    {
                                        (yyvsp[-2].node) = new treeNode("STRUCT"); (yyvsp[0].node) = new treeNode("MULT");
                                        vector<treeNode*> v = {(yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                        (yyval.node) = new treeNode("type_spec", v);
                                    }
#line 1700 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 253 "a.y" /* yacc.c:1646  */
    {
                        (yyvsp[0].node) = new treeNode("EXTERN");
                        vector<treeNode*> v = {(yyvsp[0].node)};
                        (yyval.node) = new treeNode("extern_spec", v);
                    }
#line 1710 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 258 "a.y" /* yacc.c:1646  */
    {
                    auto x = new treeNode("epsilon");
                    vector<treeNode*> v = {x};
                    (yyval.node) = new treeNode("extern_spec", v);
                }
#line 1720 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 264 "a.y" /* yacc.c:1646  */
    {
                                                                    (yyvsp[-3].node) = new treeNode("("); (yyvsp[-1].node) = new treeNode(")");
                                                                    vector<treeNode*> v = {(yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                                                    (yyval.node) = new treeNode("func_decl", v);      
                                                                    if((yyvsp[-4].node)->lexValue == "main") {
                                                                        set_mainLongestPath((yyval.node)->maxSubtreeLength);
                                                                    }
                                                                }
#line 1733 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 273 "a.y" /* yacc.c:1646  */
    {
                        vector<treeNode*> v = {(yyvsp[0].node)};
                        (yyval.node) = new treeNode("params", v);
                    }
#line 1742 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 277 "a.y" /* yacc.c:1646  */
    {
          auto x = new treeNode("epsilon");
          vector<treeNode*> v = {x};
          (yyval.node) = new treeNode("params", v);
        }
#line 1752 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 283 "a.y" /* yacc.c:1646  */
    {
                                        (yyvsp[-1].node) = new treeNode(",");
                                        vector<treeNode*> v = {(yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                        (yyval.node) = new treeNode("param_list", v);
                                    }
#line 1762 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 288 "a.y" /* yacc.c:1646  */
    {
                        vector<treeNode*> v = {(yyvsp[0].node)};
                        (yyval.node) = new treeNode("param_list", v);
                    }
#line 1771 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 293 "a.y" /* yacc.c:1646  */
    {
                                vector<treeNode*> v = {(yyvsp[-1].node), (yyvsp[0].node)};
                                (yyval.node) = new treeNode("param", v);
                            }
#line 1780 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 297 "a.y" /* yacc.c:1646  */
    {
                                        (yyvsp[-1].node) = new treeNode("["); (yyvsp[0].node) = new treeNode("]");
                                        vector<treeNode*> v = {(yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                        (yyval.node) = new treeNode("param", v);
                                    }
#line 1790 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 303 "a.y" /* yacc.c:1646  */
    {
                                vector<treeNode*> v = {(yyvsp[-1].node), (yyvsp[0].node)};
                                (yyval.node) = new treeNode("stmt_list", v);
                            }
#line 1799 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 307 "a.y" /* yacc.c:1646  */
    {
                    vector<treeNode*> v = {(yyvsp[0].node)};
                    (yyval.node) = new treeNode("stmt_list", v);
                }
#line 1808 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 312 "a.y" /* yacc.c:1646  */
    {
                        vector<treeNode*> v = {(yyvsp[0].node)};
                        (yyval.node) = new treeNode("stmt", v);
                    }
#line 1817 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 316 "a.y" /* yacc.c:1646  */
    {
                        vector<treeNode*> v = {(yyvsp[0].node)};
                        (yyval.node) = new treeNode("stmt", v);
                    }
#line 1826 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 320 "a.y" /* yacc.c:1646  */
    {
                    vector<treeNode*> v = {(yyvsp[0].node)};
                    (yyval.node) = new treeNode("stmt", v);
                }
#line 1835 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 324 "a.y" /* yacc.c:1646  */
    {
                        vector<treeNode*> v = {(yyvsp[0].node)};
                        (yyval.node) = new treeNode("stmt", v);
                    }
#line 1844 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 328 "a.y" /* yacc.c:1646  */
    {
                        vector<treeNode*> v = {(yyvsp[0].node)};
                        (yyval.node) = new treeNode("stmt", v);
                    }
#line 1853 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 332 "a.y" /* yacc.c:1646  */
    {
                        vector<treeNode*> v = {(yyvsp[0].node)};
                        (yyval.node) = new treeNode("stmt", v);
                    }
#line 1862 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 336 "a.y" /* yacc.c:1646  */
    {
                    vector<treeNode*> v = {(yyvsp[0].node)};
                    (yyval.node) = new treeNode("stmt", v);
                 }
#line 1871 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 340 "a.y" /* yacc.c:1646  */
    {
                        vector<treeNode*> v = {(yyvsp[0].node)};
                        (yyval.node) = new treeNode("stmt", v);
                    }
#line 1880 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 344 "a.y" /* yacc.c:1646  */
    {    
                        vector<treeNode*> v = {(yyvsp[0].node)};
                        (yyval.node) = new treeNode("stmt", v);
                    }
#line 1889 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 348 "a.y" /* yacc.c:1646  */
    {
                        vector<treeNode*> v = {(yyvsp[0].node)};
                        (yyval.node) = new treeNode("stmt", v);
                    }
#line 1898 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 352 "a.y" /* yacc.c:1646  */
    {
                    vector<treeNode*> v = {(yyvsp[0].node)};
                    (yyval.node) = new treeNode("stmt", v);
                }
#line 1907 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 356 "a.y" /* yacc.c:1646  */
    {   
                    vector<treeNode*> v = {(yyvsp[0].node)};
                    (yyval.node) = new treeNode("stmt", v);
                }
#line 1916 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 361 "a.y" /* yacc.c:1646  */
    { 
                                        (yyvsp[-4].node) = new treeNode("WHILE");
                                        (yyvsp[-3].node) = new treeNode("("); (yyvsp[-1].node) = new treeNode(")");
                                        vector<treeNode*> v = {(yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                        (yyval.node) = new treeNode("while_stmt", v); 
                                        set_whileLongestPath((yyval.node)->maxSubtreeLength); 
                                    }
#line 1928 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 369 "a.y" /* yacc.c:1646  */
    { 
                                                (yyvsp[-6].node) = new treeNode("DO"); (yyvsp[-4].node) = new treeNode("WHILE");
                                                (yyvsp[-3].node) = new treeNode("("); (yyvsp[-1].node) = new treeNode(")"); (yyvsp[0].node) = new treeNode(";");
                                                vector<treeNode*> v = {(yyvsp[-6].node), (yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                                (yyval.node) = new treeNode("dowhile_stmt", v);  
                                            }
#line 1939 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 376 "a.y" /* yacc.c:1646  */
    {
                                                                    (yyvsp[-6].node) = new treeNode("PRINTF"); (yyvsp[-5].node) = new treeNode("("); (yyvsp[-3].node) = new treeNode(",");
                                                                    (yyvsp[-1].node) = new treeNode(")"); (yyvsp[0].node) = new treeNode(";");
                                                                    vector<treeNode*> v = {(yyvsp[-6].node), (yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                                                    (yyval.node) = new treeNode("print_stmt", v); 
                                                                }
#line 1950 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 383 "a.y" /* yacc.c:1646  */
    {
                                (yyvsp[0].node) = new treeNode("PERCENTD");
                                vector<treeNode*> v = {(yyvsp[0].node)};
                                (yyval.node) = new treeNode("format_specifier", v);
                            }
#line 1960 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 389 "a.y" /* yacc.c:1646  */
    {
                                                    (yyvsp[-3].node) = new treeNode("{"); (yyvsp[0].node) = new treeNode("}");
                                                    vector<treeNode*> v = {(yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                                    (yyval.node) = new treeNode("compound_stmt", v);
                                                }
#line 1970 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 395 "a.y" /* yacc.c:1646  */
    {
                                        vector<treeNode*> v = {(yyvsp[-1].node), (yyvsp[0].node)};
                                        (yyval.node) = new treeNode("local_decls", v);
                                    }
#line 1979 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 399 "a.y" /* yacc.c:1646  */
    {
                    auto x = new treeNode("epsilon");
                    vector<treeNode*> v = {x};
                    (yyval.node) = new treeNode("local_decls", v);
                }
#line 1989 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 405 "a.y" /* yacc.c:1646  */
    {
                                            (yyvsp[0].node) = new treeNode(";");
                                            vector<treeNode*> v = {(yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                            (yyval.node) = new treeNode("local_decl", v);
                                        }
#line 1999 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 410 "a.y" /* yacc.c:1646  */
    {
                                                        (yyvsp[-3].node) = new treeNode("["); (yyvsp[-1].node) = new treeNode("]"); (yyvsp[0].node) = new treeNode(";");
                                                        vector<treeNode*> v = {(yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                                        (yyval.node) = new treeNode("local_decl", v); 
                                                    }
#line 2009 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 416 "a.y" /* yacc.c:1646  */
    {   
                                    (yyvsp[-4].node) = new treeNode("IF");
                                    (yyvsp[-3].node) = new treeNode("("); (yyvsp[-1].node) = new treeNode(")");
                                    vector<treeNode*> v = {(yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                    (yyval.node) = new treeNode("if_stmt", v);
                                    set_ifLongestPath((yyval.node)->maxSubtreeLength); 
                                }
#line 2021 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 423 "a.y" /* yacc.c:1646  */
    { 
                                            (yyvsp[-6].node) = new treeNode("IF");
                                            (yyvsp[-5].node) = new treeNode("("); (yyvsp[-3].node) = new treeNode(")"); (yyvsp[-1].node) = new treeNode("ELSE");
                                            vector<treeNode*> v = {(yyvsp[-6].node), (yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                            (yyval.node) = new treeNode("if_stmt", v);
                                            set_ifLongestPath((yyval.node)->maxSubtreeLength); 
                                        }
#line 2033 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 431 "a.y" /* yacc.c:1646  */
    { 
                            (yyvsp[-1].node) = new treeNode("RETURN"); (yyvsp[0].node) = new treeNode(";");
                            vector<treeNode*> v = {(yyvsp[-1].node), (yyvsp[0].node)};
                            (yyval.node) = new treeNode("return_stmt", v);
                        }
#line 2043 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 436 "a.y" /* yacc.c:1646  */
    {
                                    (yyvsp[-2].node) = new treeNode("RETURN"); (yyvsp[0].node) = new treeNode(";");
                                    vector<treeNode*> v = {(yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                    (yyval.node) = new treeNode("return_stmt", v);
                                }
#line 2053 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 442 "a.y" /* yacc.c:1646  */
    {
                            (yyvsp[-1].node) = new treeNode("BREAK"); (yyvsp[0].node) = new treeNode(";");
                            vector<treeNode*> v = {(yyvsp[-1].node), (yyvsp[0].node)};
                            (yyval.node) = new treeNode("break_stmt", v);
                        }
#line 2063 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 448 "a.y" /* yacc.c:1646  */
    {
                                (yyvsp[-1].node) = new treeNode("CONTINUE"); (yyvsp[0].node) = new treeNode(";");
                                vector<treeNode*> v = {(yyvsp[-1].node), (yyvsp[0].node)};
                                (yyval.node) = new treeNode("continue_stmt", v);
                            }
#line 2073 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 454 "a.y" /* yacc.c:1646  */
    {
                                                                        (yyvsp[-7].node) = new treeNode("SWITCH");
                                                                        (yyvsp[-6].node) = new treeNode("("); (yyvsp[-4].node) = new treeNode(")");
                                                                        (yyvsp[-3].node) = new treeNode("{"); (yyvsp[0].node) = new treeNode("}");
                                                                        vector<treeNode*> v = {(yyvsp[-7].node), (yyvsp[-6].node), (yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                                                        (yyval.node) = new treeNode("switch_stmt", v);
                                                                        set_switchLongestPath((yyval.node)->maxSubtreeLength);    
                                                                    }
#line 2086 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 463 "a.y" /* yacc.c:1646  */
    {
                                                vector<treeNode*> v = {(yyvsp[-1].node), (yyvsp[0].node)};
                                                (yyval.node) = new treeNode("compound_case", v); 
                                            }
#line 2095 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 467 "a.y" /* yacc.c:1646  */
    {
                                vector<treeNode*> v = {(yyvsp[0].node)};
                                (yyval.node) = new treeNode("compound_case", v);
                            }
#line 2104 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 472 "a.y" /* yacc.c:1646  */
    {
                                                (yyvsp[-3].node) = new treeNode("CASE"); (yyvsp[-1].node) = new treeNode(":");
                                                vector<treeNode*> v = {(yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                                (yyval.node) = new treeNode("single_case", v);
                                            }
#line 2114 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 478 "a.y" /* yacc.c:1646  */
    {
                                        (yyvsp[-2].node) = new treeNode("DEFAULT"); (yyvsp[-1].node) = new treeNode(":");
                                        vector<treeNode*> v = {(yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                        (yyval.node) = new treeNode("default_case", v);
                                    }
#line 2124 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 484 "a.y" /* yacc.c:1646  */
    {
                                        vector<treeNode*> u = {(yyvsp[-3].node), (yyvsp[-1].node)};
                                        (yyvsp[-2].node) = new treeNode("EQ", u);
                                        (yyvsp[0].node) = new treeNode(";");
                                        vector<treeNode*> v = {(yyvsp[-2].node), (yyvsp[0].node)};
                                        (yyval.node) = new treeNode("assign_stmt", v);
                                        
                                    }
#line 2137 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 492 "a.y" /* yacc.c:1646  */
    {   // check this one
                                                        (yyvsp[-5].node) = new treeNode("["); (yyvsp[-3].node) = new treeNode("]"); (yyvsp[0].node) = new treeNode(";");
                                                        vector<treeNode*> u = {(yyvsp[-6].node), (yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-1].node)};
                                                        (yyvsp[-2].node) = new treeNode("EQ", u);
                                                        vector<treeNode*> v = {(yyvsp[-2].node), (yyvsp[0].node)};
                                                        (yyval.node) = new treeNode("assign_stmt", v);    
                                                    }
#line 2149 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 499 "a.y" /* yacc.c:1646  */
    {
                                                            (yyvsp[0].node) = new treeNode(";");
                                                            (yyvsp[-4].node) = new treeNode("ARROW");
                                                            vector<treeNode*> u = {(yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-1].node)};
                                                            (yyvsp[-2].node) = new treeNode("EQ", u);
                                                            vector<treeNode*> v = {(yyvsp[-2].node), (yyvsp[0].node)};
                                                            (yyval.node) = new treeNode("assign_stmt", v);
                                                        }
#line 2162 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 507 "a.y" /* yacc.c:1646  */
    {
                                                        (yyvsp[0].node) = new treeNode(";");
                                                        (yyvsp[-4].node) = new treeNode(".");
                                                        vector<treeNode*> u = {(yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-1].node)};
                                                        (yyvsp[-2].node) = new treeNode("EQ", u);
                                                        vector<treeNode*> v = {(yyvsp[-2].node), (yyvsp[0].node)};
                                                        (yyval.node) = new treeNode("assign_stmt", v);
                                                    }
#line 2175 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 516 "a.y" /* yacc.c:1646  */
    {
                                    (yyvsp[0].node) = new treeNode(";");
                                    (yyvsp[-1].node) = new treeNode("INC");
                                    vector<treeNode*> v = {(yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                    (yyval.node) = new treeNode("incr_stmt", v);
                                }
#line 2186 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 523 "a.y" /* yacc.c:1646  */
    {
                                    (yyvsp[0].node) = new treeNode(";");
                                    (yyvsp[-1].node) = new treeNode("DEC");
                                    vector<treeNode*> v = {(yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                    (yyval.node) = new treeNode("decr_stmt", v);
                                }
#line 2197 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 530 "a.y" /* yacc.c:1646  */
    {
                            vector<treeNode*> u = {(yyvsp[-2].node), (yyvsp[0].node)};
                            (yyvsp[-1].node) = new treeNode("LT", u);
                            vector<treeNode*> v = {(yyvsp[-1].node)};
                            (yyval.node) = new treeNode("expr", v);
                        }
#line 2208 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 536 "a.y" /* yacc.c:1646  */
    {   
                            vector<treeNode*> u = {(yyvsp[-2].node), (yyvsp[0].node)};
                            (yyvsp[-1].node) = new treeNode("GT", u);
                            vector<treeNode*> v = {(yyvsp[-1].node)};
                            (yyval.node) = new treeNode("expr", v);
                        }
#line 2219 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 542 "a.y" /* yacc.c:1646  */
    {
                            vector<treeNode*> u = {(yyvsp[-2].node), (yyvsp[0].node)};
                            (yyvsp[-1].node) = new treeNode("LEQ", u);
                            vector<treeNode*> v = {(yyvsp[-1].node)};
                            (yyval.node) = new treeNode("expr", v);
                        }
#line 2230 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 548 "a.y" /* yacc.c:1646  */
    {
                            vector<treeNode*> u = {(yyvsp[-2].node), (yyvsp[0].node)};
                            (yyvsp[-1].node) = new treeNode("GEQ", u);
                            vector<treeNode*> v = {(yyvsp[-1].node)};
                            (yyval.node) = new treeNode("expr", v);
                        }
#line 2241 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 554 "a.y" /* yacc.c:1646  */
    {
                            vector<treeNode*> u = {(yyvsp[-2].node), (yyvsp[0].node)};
                            (yyvsp[-1].node) = new treeNode("OR", u);
                            vector<treeNode*> v = {(yyvsp[-1].node)};
                            (yyval.node) = new treeNode("expr", v);
                        }
#line 2252 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 560 "a.y" /* yacc.c:1646  */
    {
                                (yyvsp[-3].node) = new treeNode("SIZEOF"); (yyvsp[-2].node) = new treeNode("("); (yyvsp[0].node) = new treeNode(")");
                                vector<treeNode*> v = {(yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                (yyval.node) = new treeNode("expr", v);
                            }
#line 2262 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 565 "a.y" /* yacc.c:1646  */
    {
                            vector<treeNode*> u = {(yyvsp[-2].node), (yyvsp[0].node)};
                            (yyvsp[-1].node) = new treeNode("EQEQ", u);
                            vector<treeNode*> v = {(yyvsp[-1].node)};
                            (yyval.node) = new treeNode("expr", v);
                        }
#line 2273 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 571 "a.y" /* yacc.c:1646  */
    {
                            vector<treeNode*> u = {(yyvsp[-2].node), (yyvsp[0].node)};
                            (yyvsp[-1].node) = new treeNode("NEQ", u);
                            vector<treeNode*> v = {(yyvsp[-1].node)};
                            (yyval.node) = new treeNode("expr", v);
                        }
#line 2284 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 577 "a.y" /* yacc.c:1646  */
    {
                            vector<treeNode*> u = {(yyvsp[-2].node), (yyvsp[0].node)};
                            (yyvsp[-1].node) = new treeNode("NEWOP", u);
                            vector<treeNode*> v = {(yyvsp[-1].node)};
                            (yyval.node) = new treeNode("expr", v);
                        }
#line 2295 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 583 "a.y" /* yacc.c:1646  */
    {
                            vector<treeNode*> u = {(yyvsp[-2].node), (yyvsp[0].node)};
                            (yyvsp[-1].node) = new treeNode("AND", u);
                            vector<treeNode*> v = {(yyvsp[-1].node)};
                            (yyval.node) = new treeNode("expr", v);
                        }
#line 2306 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 589 "a.y" /* yacc.c:1646  */
    {
                            vector<treeNode*> u = {(yyvsp[-2].node), (yyvsp[0].node)};
                            (yyvsp[-1].node) = new treeNode("ARROW", u);
                            vector<treeNode*> v = {(yyvsp[-1].node)};
                            (yyval.node) = new treeNode("expr", v);
                        }
#line 2317 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 595 "a.y" /* yacc.c:1646  */
    {
                            vector<treeNode*> u = {(yyvsp[-2].node), (yyvsp[0].node)};
                            (yyvsp[-1].node) = new treeNode("PLUS", u);
                            vector<treeNode*> v = {(yyvsp[-1].node)};
                            (yyval.node) = new treeNode("expr", v);
                        }
#line 2328 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 601 "a.y" /* yacc.c:1646  */
    {
                            vector<treeNode*> u = {(yyvsp[-2].node), (yyvsp[0].node)};
                            (yyvsp[-1].node) = new treeNode("MINUS", u);
                            vector<treeNode*> v = {(yyvsp[-1].node)};
                            (yyval.node) = new treeNode("expr", v);
                        }
#line 2339 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 607 "a.y" /* yacc.c:1646  */
    {
                            vector<treeNode*> u = {(yyvsp[-2].node), (yyvsp[0].node)};
                            (yyvsp[-1].node) = new treeNode("MULT", u);
                            vector<treeNode*> v = {(yyvsp[-1].node)};
                            (yyval.node) = new treeNode("expr", v);
                        }
#line 2350 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 613 "a.y" /* yacc.c:1646  */
    {
                            vector<treeNode*> u = {(yyvsp[-2].node), (yyvsp[0].node)};
                            (yyvsp[-1].node) = new treeNode("DIV", u);
                            vector<treeNode*> v = {(yyvsp[-1].node)};
                            (yyval.node) = new treeNode("expr", v);
                        }
#line 2361 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 619 "a.y" /* yacc.c:1646  */
    {
                            vector<treeNode*> u = {(yyvsp[-2].node), (yyvsp[0].node)};
                            (yyvsp[-1].node) = new treeNode("MOD", u);
                            vector<treeNode*> v = {(yyvsp[-1].node)};
                            (yyval.node) = new treeNode("expr", v);
                        }
#line 2372 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 625 "a.y" /* yacc.c:1646  */
    {
                    (yyvsp[-1].node) = new treeNode("NOT");
                    vector<treeNode*> v = {(yyvsp[-1].node), (yyvsp[0].node)};
                    (yyval.node) = new treeNode("expr", v);
                }
#line 2382 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 630 "a.y" /* yacc.c:1646  */
    {
                        (yyvsp[-1].node) = new treeNode("MINUS");
                        vector<treeNode*> v = {(yyvsp[-1].node), (yyvsp[0].node)};
                        (yyval.node) = new treeNode("expr", v);
                    }
#line 2392 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 635 "a.y" /* yacc.c:1646  */
    {
                        (yyvsp[-1].node) = new treeNode("PLUS");
                        vector<treeNode*> v = {(yyvsp[-1].node), (yyvsp[0].node)};
                        (yyval.node) = new treeNode("expr", v);
                    }
#line 2402 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 640 "a.y" /* yacc.c:1646  */
    {
                        (yyvsp[-1].node) = new treeNode("MULT");
                        vector<treeNode*> v = {(yyvsp[-1].node), (yyvsp[0].node)};
                        (yyval.node) = new treeNode("expr", v);
                    }
#line 2412 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 645 "a.y" /* yacc.c:1646  */
    {   
                        (yyvsp[-1].node) = new treeNode("BITAND");
                        vector<treeNode*> v = {(yyvsp[-1].node), (yyvsp[0].node)};
                        (yyval.node) = new treeNode("expr", v);
                    }
#line 2422 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 650 "a.y" /* yacc.c:1646  */
    {
                vector<treeNode*> v = {(yyvsp[0].node)};
                (yyval.node) = new treeNode("expr", v);
            }
#line 2431 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 654 "a.y" /* yacc.c:1646  */
    {
                                    (yyvsp[-2].node) = new treeNode("("); (yyvsp[0].node) = new treeNode(")");
                                    vector<treeNode*> v = {(yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                    (yyval.node) = new treeNode("expr", v); 
                                }
#line 2441 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 659 "a.y" /* yacc.c:1646  */
    {
                                    (yyvsp[-2].node) = new treeNode("["); (yyvsp[0].node) = new treeNode("]");
                                    vector<treeNode*> v = {(yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                    (yyval.node) = new treeNode("expr", v); 
                                }
#line 2451 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 665 "a.y" /* yacc.c:1646  */
    {
                        vector<treeNode*> v = {(yyvsp[0].node)};
                        (yyval.node) = new treeNode("Pexpr", v);
                    }
#line 2460 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 669 "a.y" /* yacc.c:1646  */
    {
                    vector<treeNode*> v = {(yyvsp[0].node)};
                    (yyval.node) = new treeNode("Pexpr", v);
                }
#line 2469 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 673 "a.y" /* yacc.c:1646  */
    {
                        vector<treeNode*> v = {(yyvsp[0].node)};
                        (yyval.node) = new treeNode("Pexpr", v);
                    }
#line 2478 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 677 "a.y" /* yacc.c:1646  */
    {
                        (yyvsp[-2].node) = new treeNode("("); (yyvsp[0].node) = new treeNode(")");
                        vector<treeNode*> v = {(yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                        (yyval.node) = new treeNode("Pexpr", v);
                    }
#line 2488 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 683 "a.y" /* yacc.c:1646  */
    {
                                (yyvsp[0].node) = new treeNode("INTEGER_NUMBER");
                                vector<treeNode*> v = {(yyvsp[0].node)};
                                (yyval.node) = new treeNode("intergerLit", v);
                                (yyval.node)->lexValue = mytext;
                                (yyval.node)->width = 4;
                            }
#line 2500 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 691 "a.y" /* yacc.c:1646  */
    {
                            (yyvsp[0].node) = new treeNode("FLOAT_NUMBER");
                            vector<treeNode*> v = {(yyvsp[0].node)};
                            (yyval.node) = new treeNode("floatLit", v);
                            (yyval.node)->lexValue = mytext;
                            (yyval.node)->width = 8;
                        }
#line 2512 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 699 "a.y" /* yacc.c:1646  */
    {
                            (yyvsp[0].node) = new treeNode("IDENTIFIER");
                            vector<treeNode*> v = {(yyvsp[0].node)};
                            (yyval.node) = new treeNode("identifier", v);
                            (yyval.node)->lexValue = mytext;
                        }
#line 2523 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 705 "a.y" /* yacc.c:1646  */
    {
                        (yyvsp[0].node) = new treeNode("IDENTIFIER");
                        vector<treeNode*> v = {(yyvsp[0].node)};
                        (yyval.node) = new treeNode("identifier", v);
                        (yyval.node)->lexValue = "printf";
                    }
#line 2534 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 712 "a.y" /* yacc.c:1646  */
    {
                                (yyvsp[-1].node) = new treeNode(",");
                                vector<treeNode*> v = {(yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                (yyval.node) = new treeNode("arg_list", v);
                            }
#line 2544 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 717 "a.y" /* yacc.c:1646  */
    {
                    vector<treeNode*> v = {(yyvsp[0].node)};
                    (yyval.node) = new treeNode("arg_list", v);
                }
#line 2553 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 722 "a.y" /* yacc.c:1646  */
    {
                    vector<treeNode*> v = {(yyvsp[0].node)};
                    (yyval.node) = new treeNode("args", v);
                }
#line 2562 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 726 "a.y" /* yacc.c:1646  */
    {
            auto x = new treeNode("epsilon");
            vector<treeNode*> v = {x};
            (yyval.node) = new treeNode("args", v);
        }
#line 2572 "y.tab.cpp" /* yacc.c:1646  */
    break;


#line 2576 "y.tab.cpp" /* yacc.c:1646  */
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
#line 732 "a.y" /* yacc.c:1906  */


void yyerror(char* s) {
    printf("***parsing terminated*** [syntax error]\n");
    exit(0);
}

void set_programLongestPath(int x) {
    programLongestPath = max(programLongestPath, x);
}

void set_ifLongestPath(int x) {
    ifLongestPath = max(ifLongestPath, x);
}

void set_whileLongestPath(int x) {
    whileLongestPath = max(whileLongestPath, x);
}

void set_switchLongestPath(int x) {
    switchLongestPath = max(switchLongestPath, x);
}

void set_mainLongestPath(int x) {
     mainLongestPath = max(mainLongestPath, x);
}

void remove_unused_vars(treeNode* root) {
    if (root->nodeName == "compound_stmt") {
        treeNode* declarations = root->children[1];
        treeNode* statements = root->children[2];

        set<string> variablesUsed;
        stack<treeNode*> S;
        
        S.push(statements);
        while(!S.empty()) {
            treeNode* top = S.top(); S.pop();
            if(top->nodeName == "identifier") 
                variablesUsed.insert(top->lexValue);
            for(treeNode* c: top->children) {
                S.push(c);
            }
        }

        while(declarations->children[0]->nodeName != "epsilon") {
            string variableDeclared = declarations->children[1]->children[1]->lexValue;
            if(variablesUsed.count(variableDeclared) == 0) {
                unused_vars.push(variableDeclared);
                *declarations = *(declarations->children[0]);
            } else {
                declarations = declarations->children[0];
            }
        }
    } else {
        for(treeNode* c: root->children) {
            remove_unused_vars(c);
        }
    }
}

void constants_and_if_simple(treeNode *ast) {
    map<string, int> variableValues;

    stack<treeNode*> S;   
    S.push(ast);

    while(!S.empty()) {
        treeNode* top = S.top(); S.pop();
        cout << top->nodeName << endl;

        if(top->nodeName == "local_decl") 
            variableValues[top->children[1]->lexValue] = 0;
        else if (top->nodeName == "assign_stmt") {
            cout << "Entered" << endl;
            for(auto c: top->children[0]->children) cout << c->nodeName << " "; cout << endl;
            staticCalc(top->children[0]->children[1], variableValues);
            cout << "Staticed" << endl;
            simplifyExpr(top->children[0]->children[1]);
            cout << "Simplified" << endl;
            if (top->children[0]->children[1]->staticexpr) {
                variableValues[top->children[0]->children[0]->lexValue] = top->children[0]->children[1]->exprval;
            } else {
                variableValues.erase(top->children[0]->children[0]->lexValue);
            }
        } else if (top->nodeName == "stmt" && top->children[0]->nodeName == "if_stmt") {
            treeNode* condition = top->children[0]->children[2];
            staticCalc(condition, variableValues);
            simplifyExpr(condition);
            if (condition->staticexpr) {
                if(condition->exprval) {
                    *top = *(top->children[0]->children[4]);
                } else {
                    if (top->children[0]->children.size() == 7) {
                        *top = *(top->children[0]->children[6]);
                    } else {
                        top->children[0] = placeholder_stmt();
                    }
                }
            }
            for(int i = top->children.size()-1; i >= 0; i--) {
                S.push(top->children[i]);
            }
        } else if (top->nodeName == "return_stmt") {
            staticCalc(top->children[1], variableValues);
            simplifyExpr(top->children[1]);
        } else {
            for(int i = top->children.size()-1; i >= 0; i--) {
                S.push(top->children[i]);
            }
        }
    }

}


void staticCalc(treeNode *expr, map<string, int> &variableValues) {
    cout << expr->nodeName << endl;
    if (expr->nodeName == "Pexpr") {
        if (expr->children[0]->nodeName == "intergerLit") {                             // integerLit
            expr->staticexpr = true;
            expr->exprval = stoi(expr->children[0]->lexValue);
        } else if (expr->children[0]->nodeName == "identifier") {                       // identifier
            string varName = expr->children[0]->lexValue;
            if (variableValues.count(varName) > 0) {
                expr->staticexpr = true;
                expr->exprval = variableValues[varName];
            }
        } else if (expr->children[1]->nodeName == "expr") {                             // '(' expr ')'
            staticCalc(expr->children[1], variableValues);
            expr->staticexpr = expr->children[1]->staticexpr;
            expr->exprval = expr->children[1]->exprval;
        }
    } else if (expr->nodeName == "expr") {
        if (expr->children.size() == 1 && expr->children[0]->nodeName != "Pexpr") {
            staticCalc(expr->children[0]->children[0], variableValues);
            staticCalc(expr->children[0]->children[1], variableValues);
            expr->staticexpr = expr->children[0]->children[0]->staticexpr && expr->children[0]->children[1]->staticexpr;
            if (expr->staticexpr) {
                if (expr->children[0]->nodeName == "LT") {
                    expr->exprval = expr->children[0]->children[0]->exprval < expr->children[0]->children[1]->exprval;
                } else if (expr->children[0]->nodeName == "GT") {
                    expr->exprval = expr->children[0]->children[0]->exprval > expr->children[0]->children[1]->exprval;
                } else if (expr->children[0]->nodeName == "LEQ") {
                    expr->exprval = expr->children[0]->children[0]->exprval <= expr->children[0]->children[1]->exprval;
                } else if (expr->children[0]->nodeName == "GEQ") {
                    expr->exprval = expr->children[0]->children[0]->exprval >= expr->children[0]->children[1]->exprval;
                } else if (expr->children[0]->nodeName == "OR") {
                    expr->exprval = expr->children[0]->children[0]->exprval || expr->children[0]->children[1]->exprval;
                } else if (expr->children[0]->nodeName == "EQEQ") {
                    expr->exprval = expr->children[0]->children[0]->exprval == expr->children[0]->children[1]->exprval;
                } else if (expr->children[0]->nodeName == "NEQ") {
                    expr->exprval = expr->children[0]->children[0]->exprval != expr->children[0]->children[1]->exprval;
                } else if (expr->children[0]->nodeName == "AND") {
                    expr->exprval = expr->children[0]->children[0]->exprval && expr->children[0]->children[1]->exprval;
                } else if (expr->children[0]->nodeName == "PLUS") {
                    expr->exprval = expr->children[0]->children[0]->exprval + expr->children[0]->children[1]->exprval;
                } else if (expr->children[0]->nodeName == "MINUS") {
                    expr->exprval = expr->children[0]->children[0]->exprval - expr->children[0]->children[1]->exprval;
                } else if (expr->children[0]->nodeName == "MULT") {
                    expr->exprval = expr->children[0]->children[0]->exprval * expr->children[0]->children[1]->exprval;
                } else if (expr->children[0]->nodeName == "DIV") {
                    expr->exprval = expr->children[0]->children[0]->exprval / expr->children[0]->children[1]->exprval;
                } else if (expr->children[0]->nodeName == "MOD") {
                    expr->exprval = expr->children[0]->children[0]->exprval % expr->children[0]->children[1]->exprval;
                }
            }
        } else if (expr->children.size() == 2) {
            staticCalc(expr->children[1], variableValues);
            expr->staticexpr = expr->children[1]->staticexpr;
            if (expr->staticexpr) {
                if (expr->children[0]->nodeName == "NOT") {
                    expr->exprval = !expr->children[1]->exprval;
                } else if (expr->children[0]->nodeName == "MINUS") {
                    expr->exprval = - expr->children[1]->exprval;
                } else if (expr->children[0]->nodeName == "PLUS") {
                    expr->exprval = expr->children[1]->exprval;
                }
            }
        } else if (expr->children.size() == 1) {
            staticCalc(expr->children[0], variableValues);
            expr->staticexpr = expr->children[0]->staticexpr;
            expr->exprval = expr->children[0]->exprval;
        }
    }
    cout << expr->staticexpr << " " << expr->exprval << endl;
}

treeNode* makeIntegerLitexpr(int n, bool P) {
    treeNode* base = new treeNode("INTEGER_NUMBER");
    vector<treeNode*> v = {base};
    treeNode* iL = new treeNode("intergerLit", v);
    iL->staticexpr = true;
    iL->exprval = n;
    iL->lexValue = to_string(n);
    iL->width = 4;
    v = {iL};
    treeNode* p = new treeNode("Pexpr", v);
    p->staticexpr = true;
    p->exprval = n;
    if(P) return p;
    else {
        v = {p};
        treeNode* e = new treeNode("expr", v);
        e->staticexpr = true;
        e->exprval = n;
        return e;
    }
}

void simplifyExpr(treeNode *expr) {
    stack<treeNode*> S;   
    S.push(expr);
    while(!S.empty()) {
        treeNode* top = S.top(); S.pop();
        cout << top->nodeName << endl;
        if (top->staticexpr) {
            *top = *makeIntegerLitexpr(top->exprval, (top->nodeName == "Pexpr"));
        } else {
            for(treeNode* c: top->children) {
                S.push(c);
            }
        }
    }
}

treeNode* placeholder_stmt() {
    auto a1 = new treeNode("CONTINUE"); auto a2 = new treeNode(";");
    vector<treeNode*> v = {a1, a2};
    return new treeNode("continue_stmt", v);
}

int main() {
    yyparse();
    remove_unused_vars(ast);
    /*
    while(!unused_vars.empty()) {
        cout << unused_vars.top() << " "; unused_vars.pop();
    }
    cout << endl;
    */
    constants_and_if_simple(ast);




    // printf("***parsing successful***\n");
    // printf("%d\n", programLongestPath);
    // printf("%d\n", ifLongestPath);
    // printf("%d\n", whileLongestPath);
    // printf("%d\n", switchLongestPath);
    // printf("%d\n", mainLongestPath);
    int a = generateIR();   // generate 3AC intermediate representation
    return 0;
}
