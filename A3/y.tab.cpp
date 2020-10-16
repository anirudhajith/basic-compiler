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
    using namespace std;
    void yyerror(char*);
    int yylex(void);
    void set_programLongestPath(int); // Set Longest Path in the program
    void set_ifLongestPath(int);      // Set Longest Path among all subtrees of if statement
    void set_whileLongestPath(int);   // Set Longest Path among all subtrees of while statement
    void set_mainLongestPath(int);    // Set Longest Path of main subtee
    void set_switchLongestPath(int);  // Set Longest Path among all subtrees of switch statement
    extern FILE* yyin;
    char mytext[10000];
    int programLongestPath = 0;
    int ifLongestPath = 0;
    int whileLongestPath = 0;
    int mainLongestPath = 0;
    int switchLongestPath = 0;
    int isMain = 0;
    unordered_map<string, int> symbolTable;
	string newLabel(void);

    class treeNode {
        public:
            vector<treeNode*> children;   // children
            int maxRootedLength;          // maximum path length passing through this node
            int maxSubtreeLength;         // maximum path length in the subtree rooted at this node  
            int maxDirectLength;          // maximum path length ending at this node
            string nodeName;              // name of the node
            string lexValue;              // lexical value, name of identifier etc.
			string code;				  // corresponding assembly
            int level;                    // for printing
            treeNode(string nodeName, vector<treeNode*> children) {  // for non-terminals, assume valid pointers are passed
                this->nodeName = nodeName;
                this->children = children;
                maxRootedLength = 1;
                maxSubtreeLength = 1;
                maxDirectLength = 1;
                compute();
            }
            treeNode(string nodeName) {     // for epsilon and terminals, no need to call compute
                this->nodeName = nodeName;
                children.assign(0, NULL);
                maxRootedLength = 1;
                maxSubtreeLength = 1;
                maxDirectLength = 1;
            }
            int max_path_in_children() {
                vector<int> x;
                for(auto& child : children) {
                    x.push_back(child->maxSubtreeLength);
                }
                sort(x.rbegin(), x.rend());
                return x[0];
            }
            pair<int, int> max_and_smax_from_children() {
                vector<int> x;
                for(auto& child : children) {
                    if(child) {
                        x.push_back(child->maxDirectLength);
                    }
                }
                sort(x.rbegin(), x.rend());
                return {x[0], x[1]};
            }
            void compute() {
                if(children.size() == 0) {
        
                }
                if(children.size() == 1) {
                    maxDirectLength = 1 + children[0]->maxDirectLength;
                    maxRootedLength = maxDirectLength;
                    maxSubtreeLength = max(maxRootedLength, children[0]->maxSubtreeLength);
                }
                else {
                    pair<int, int> max_and_smax = max_and_smax_from_children();
                    maxDirectLength = 1 + max_and_smax.first;
                    maxRootedLength = 1 + max_and_smax.first + max_and_smax.second;
                    vector<int> x;
                    x.push_back(maxRootedLength);
                    for(auto& child : children) {
                        x.push_back(child->maxSubtreeLength);
                    }            
                    sort(x.rbegin(), x.rend());
                    maxSubtreeLength = x[0];
                }
            }
            void debug() {
                cout << nodeName << endl;
                for(auto& child : children) {
                    if(child) {
                        cout << child->nodeName << ' ';
                    }
                }
                cout << endl;
                cout << maxDirectLength << ' ' << maxRootedLength << ' ' << maxSubtreeLength << endl;
                cout.flush();
            }
    };
    extern char* yytext;
    treeNode* ast;   // pointer to the root of the final abstract syntax tree   

#line 168 "y.tab.cpp" /* yacc.c:339  */

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
#line 106 "a.y" /* yacc.c:355  */

    class treeNode* node;

#line 318 "y.tab.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 335 "y.tab.cpp" /* yacc.c:358  */

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
       0,   213,   213,   221,   227,   233,   239,   245,   251,   258,
     264,   270,   276,   282,   287,   293,   299,   305,   311,   317,
     322,   328,   333,   339,   378,   382,   388,   393,   398,   402,
     408,   413,   419,   424,   429,   434,   439,   443,   447,   451,
     455,   459,   464,   469,   475,   494,   501,   515,   521,   528,
     533,   539,   551,   557,   572,   592,   597,   603,   609,   615,
     624,   628,   633,   639,   645,   654,   661,   669,   678,   686,
     694,   711,   727,   743,   759,   767,   772,   788,   805,   811,
     826,   832,   845,   858,   870,   884,   898,   908,   918,   924,
     929,   934,   939,   944,   950,   956,   960,   966,   973,   980,
     986,   992,   999,  1004,  1009,  1013
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
#line 213 "a.y" /* yacc.c:1646  */
    {
                        vector<treeNode*> v = {(yyvsp[0].node)};
                        (yyval.node) = new treeNode("program", v); 
                        set_programLongestPath((yyval.node)->maxSubtreeLength);
                        ast = (yyval.node);
						(yyval.node)->code = (yyvsp[0].node)->code;
                    }
#line 1594 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 221 "a.y" /* yacc.c:1646  */
    { 
                                vector<treeNode*> v = {(yyvsp[-1].node), (yyvsp[0].node)};
                                (yyval.node) = new treeNode("decl_list", v); 
								(yyval.node)->code = (yyvsp[-1].node)->code + (yyvsp[0].node)->code;
                            }
#line 1604 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 227 "a.y" /* yacc.c:1646  */
    {
                    vector<treeNode*> v = {(yyvsp[0].node)};
                    (yyval.node) = new treeNode("decl_list", v); 
					(yyval.node)->code = (yyvsp[0].node)->code;
                }
#line 1614 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 233 "a.y" /* yacc.c:1646  */
    {   
                    vector<treeNode*> v = {(yyvsp[0].node)};
                    (yyval.node) = new treeNode("decl", v); 
					(yyval.node)->code = (yyvsp[0].node)->code;
                }
#line 1624 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 239 "a.y" /* yacc.c:1646  */
    {
                    vector<treeNode*> v = {(yyvsp[0].node)};
                    (yyval.node) = new treeNode("decl", v); 
					(yyval.node)->code = (yyvsp[0].node)->code;
                }
#line 1634 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 245 "a.y" /* yacc.c:1646  */
    {
                        vector<treeNode*> v = {(yyvsp[0].node)};
                        (yyval.node) = new treeNode("decl", v); 
						(yyval.node)->code = (yyvsp[0].node)->code;
                    }
#line 1644 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 251 "a.y" /* yacc.c:1646  */
    {
                                                            (yyvsp[-5].node) = new treeNode("STRUCT"); (yyvsp[-3].node) = new treeNode("{"); 
                                                            (yyvsp[-1].node) = new treeNode("}"); (yyvsp[0].node) = new treeNode(";");
                                                            vector<treeNode*> v = {(yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                                            (yyval.node) = new treeNode("struct_decl", v); 
                                                        }
#line 1655 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 258 "a.y" /* yacc.c:1646  */
    {
                                        (yyvsp[0].node) = new treeNode(";");
                                        vector<treeNode*> v = {(yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                        (yyval.node) = new treeNode("var_decl", v); 
                                    }
#line 1665 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 264 "a.y" /* yacc.c:1646  */
    {
                                                (yyvsp[-1].node) = new treeNode(",");
                                                vector<treeNode*> v = {(yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                                (yyval.node) = new treeNode("var_decl", v); 
                                            }
#line 1675 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 270 "a.y" /* yacc.c:1646  */
    {
                                                            (yyvsp[-3].node) = new treeNode("["); (yyvsp[-1].node) = new treeNode("]"); (yyvsp[0].node) = new treeNode(";");
                                                            vector<treeNode*> v = {(yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                                            (yyval.node) = new treeNode("var_decl", v); 
                                                        }
#line 1685 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 276 "a.y" /* yacc.c:1646  */
    {
                                                                    (yyvsp[-4].node) = new treeNode("["); (yyvsp[-2].node) = new treeNode("]"); (yyvsp[-1].node) = new treeNode(",");
                                                                    vector<treeNode*> v = {(yyvsp[-6].node), (yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                                                    (yyval.node) = new treeNode("var_decl", v); 
                                                                }
#line 1695 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 282 "a.y" /* yacc.c:1646  */
    {
                                (yyvsp[0].node) = new treeNode("VOID");
                                vector<treeNode*> v = {(yyvsp[-1].node), (yyvsp[0].node)}; 
                                (yyval.node) = new treeNode("type_spec", v); 
                            }
#line 1705 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 287 "a.y" /* yacc.c:1646  */
    {
                                (yyvsp[0].node) = new treeNode("INT");
                                vector<treeNode*> v = {(yyvsp[-1].node), (yyvsp[0].node)}; 
                                (yyval.node) = new treeNode("type_spec", v);
                            }
#line 1715 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 293 "a.y" /* yacc.c:1646  */
    {
                                    (yyvsp[0].node) = new treeNode("FLOAT");
                                    vector<treeNode*> v = {(yyvsp[-1].node), (yyvsp[0].node)}; 
                                    (yyval.node) = new treeNode("type_spec", v);
                                }
#line 1725 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 299 "a.y" /* yacc.c:1646  */
    {
                                    (yyvsp[-1].node) = new treeNode("VOID"); (yyvsp[0].node) = new treeNode("MULT");
                                    vector<treeNode*> v = {(yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)}; 
                                    (yyval.node) = new treeNode("type_spec", v);
                                }
#line 1735 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 305 "a.y" /* yacc.c:1646  */
    {
                                    (yyvsp[-1].node) = new treeNode("INT"); (yyvsp[0].node) = new treeNode("MULT");
                                    vector<treeNode*> v = {(yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)}; 
                                    (yyval.node) = new treeNode("type_spec", v);
                                }
#line 1745 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 311 "a.y" /* yacc.c:1646  */
    {
                                    (yyvsp[-1].node) = new treeNode("FLOAT"); (yyvsp[0].node) = new treeNode("MULT");
                                    vector<treeNode*> v = {(yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)}; 
                                    (yyval.node) = new treeNode("type_spec", v);
                                  }
#line 1755 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 317 "a.y" /* yacc.c:1646  */
    {
                                    (yyvsp[-1].node) = new treeNode("STRUCT");
                                    vector<treeNode*> v = {(yyvsp[-1].node), (yyvsp[0].node)};
                                    (yyval.node) = new treeNode("type_spec", v); 
                                }
#line 1765 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 322 "a.y" /* yacc.c:1646  */
    {
                                        (yyvsp[-2].node) = new treeNode("STRUCT"); (yyvsp[0].node) = new treeNode("MULT");
                                        vector<treeNode*> v = {(yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                        (yyval.node) = new treeNode("type_spec", v);
                                    }
#line 1775 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 328 "a.y" /* yacc.c:1646  */
    {
                        (yyvsp[0].node) = new treeNode("EXTERN");
                        vector<treeNode*> v = {(yyvsp[0].node)};
                        (yyval.node) = new treeNode("extern_spec", v);
                    }
#line 1785 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 333 "a.y" /* yacc.c:1646  */
    {
                    auto x = new treeNode("epsilon");
                    vector<treeNode*> v = {x};
                    (yyval.node) = new treeNode("extern_spec", v);
                }
#line 1795 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 339 "a.y" /* yacc.c:1646  */
    {
                                                                    (yyvsp[-3].node) = new treeNode("("); (yyvsp[-1].node) = new treeNode(")");
                                                                    vector<treeNode*> v = {(yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                                                    (yyval.node) = new treeNode("func_decl", v);      
                                                                    if((yyvsp[-4].node)->lexValue == "main") {
                                                                        set_mainLongestPath((yyval.node)->maxSubtreeLength);
																		(yyval.node)->code = 
																		"   .file	\"test.c\"\n"
																		"   .text\n"
																		"   .comm	glob,4,4\n"
																		"   .section	.rodata\n"
																		".LC0:\n"
																		"   .string	\"%d\\n\"\n"
																		"   .text\n"
																		"   .globl	main\n"
																		"   .type	main, @function\n"
																		"main:\n"
																		".LFB0:\n"
																		"   .cfi_startproc\n"
																		"   pushq	%rbp\n"
																		"   .cfi_def_cfa_offset 16\n"
																		"   .cfi_offset 6, -16\n"
																		"   movq	%rsp, %rbp\n"
																		"   .cfi_def_cfa_register 6\n" + 
																		(yyvsp[0].node)->code + 
																		"   movl	$0, %eax\n"
																		"   leave\n"
																		"   .cfi_def_cfa 7, 8\n"
																		"   ret\n"
																		"   .cfi_endproc\n"
																		".LFE0:\n"
																		"   .size	main, .-main\n"
																		"   .ident	\"GCC: (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0\"\n"
																		"   .section	.note.GNU-stack,\"\",@progbits\n";

																		cout << (yyval.node)->code << flush;
                                                                    }
                                                                }
#line 1838 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 378 "a.y" /* yacc.c:1646  */
    {
                        vector<treeNode*> v = {(yyvsp[0].node)};
                        (yyval.node) = new treeNode("params", v);
                    }
#line 1847 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 382 "a.y" /* yacc.c:1646  */
    {
          auto x = new treeNode("epsilon");
          vector<treeNode*> v = {x};
          (yyval.node) = new treeNode("params", v);
        }
#line 1857 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 388 "a.y" /* yacc.c:1646  */
    {
                                        (yyvsp[-1].node) = new treeNode(",");
                                        vector<treeNode*> v = {(yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                        (yyval.node) = new treeNode("param_list", v);
                                    }
#line 1867 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 393 "a.y" /* yacc.c:1646  */
    {
                        vector<treeNode*> v = {(yyvsp[0].node)};
                        (yyval.node) = new treeNode("param_list", v);
                    }
#line 1876 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 398 "a.y" /* yacc.c:1646  */
    {
                                vector<treeNode*> v = {(yyvsp[-1].node), (yyvsp[0].node)};
                                (yyval.node) = new treeNode("param", v);
                            }
#line 1885 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 402 "a.y" /* yacc.c:1646  */
    {
                                        (yyvsp[-1].node) = new treeNode("["); (yyvsp[0].node) = new treeNode("]");
                                        vector<treeNode*> v = {(yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                        (yyval.node) = new treeNode("param", v);
                                    }
#line 1895 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 408 "a.y" /* yacc.c:1646  */
    {
                                vector<treeNode*> v = {(yyvsp[-1].node), (yyvsp[0].node)};
                                (yyval.node) = new treeNode("stmt_list", v);
                                (yyval.node)->code = (yyvsp[-1].node)->code + (yyvsp[0].node)->code;
                            }
#line 1905 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 413 "a.y" /* yacc.c:1646  */
    {
                    vector<treeNode*> v = {(yyvsp[0].node)};
                    (yyval.node) = new treeNode("stmt_list", v);
                    (yyval.node)->code = (yyvsp[0].node)->code;
                }
#line 1915 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 419 "a.y" /* yacc.c:1646  */
    {
                        vector<treeNode*> v = {(yyvsp[0].node)};
                        (yyval.node) = new treeNode("stmt", v);
						(yyval.node)->code = (yyvsp[0].node)->code;
                    }
#line 1925 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 424 "a.y" /* yacc.c:1646  */
    {
                        vector<treeNode*> v = {(yyvsp[0].node)};
                        (yyval.node) = new treeNode("stmt", v);
                        (yyval.node)->code = (yyvsp[0].node)->code;
                    }
#line 1935 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 429 "a.y" /* yacc.c:1646  */
    {
                    vector<treeNode*> v = {(yyvsp[0].node)};
                    (yyval.node) = new treeNode("stmt", v);
					(yyval.node)->code = (yyvsp[0].node)->code;
                }
#line 1945 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 434 "a.y" /* yacc.c:1646  */
    {
                        vector<treeNode*> v = {(yyvsp[0].node)};
                        (yyval.node) = new treeNode("stmt", v);
						(yyval.node)->code = (yyvsp[0].node)->code;
                    }
#line 1955 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 439 "a.y" /* yacc.c:1646  */
    {
                        vector<treeNode*> v = {(yyvsp[0].node)};
                        (yyval.node) = new treeNode("stmt", v);
                    }
#line 1964 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 443 "a.y" /* yacc.c:1646  */
    {
                        vector<treeNode*> v = {(yyvsp[0].node)};
                        (yyval.node) = new treeNode("stmt", v);
                    }
#line 1973 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 447 "a.y" /* yacc.c:1646  */
    {
                    vector<treeNode*> v = {(yyvsp[0].node)};
                    (yyval.node) = new treeNode("stmt", v);
                 }
#line 1982 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 451 "a.y" /* yacc.c:1646  */
    {
                        vector<treeNode*> v = {(yyvsp[0].node)};
                        (yyval.node) = new treeNode("stmt", v);
                    }
#line 1991 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 455 "a.y" /* yacc.c:1646  */
    {    
                        vector<treeNode*> v = {(yyvsp[0].node)};
                        (yyval.node) = new treeNode("stmt", v);
                    }
#line 2000 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 459 "a.y" /* yacc.c:1646  */
    {
                        vector<treeNode*> v = {(yyvsp[0].node)};
                        (yyval.node) = new treeNode("stmt", v);
						(yyval.node)->code = (yyvsp[0].node)->code;
                    }
#line 2010 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 464 "a.y" /* yacc.c:1646  */
    {
                    vector<treeNode*> v = {(yyvsp[0].node)};
                    (yyval.node) = new treeNode("stmt", v);
                    (yyval.node)->code = (yyvsp[0].node)->code;
                }
#line 2020 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 469 "a.y" /* yacc.c:1646  */
    {   
                    vector<treeNode*> v = {(yyvsp[0].node)};
                    (yyval.node) = new treeNode("stmt", v);
                    (yyval.node)->code = (yyvsp[0].node)->code;
                }
#line 2030 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 475 "a.y" /* yacc.c:1646  */
    { 
                                        (yyvsp[-4].node) = new treeNode("WHILE");
                                        (yyvsp[-3].node) = new treeNode("("); (yyvsp[-1].node) = new treeNode(")");
                                        vector<treeNode*> v = {(yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                        (yyval.node) = new treeNode("while_stmt", v); 
                                        set_whileLongestPath((yyval.node)->maxSubtreeLength); 
                                        string l_end = newLabel();
                                        string l_cond = newLabel();
                                        (yyval.node)->code = 
                                        l_cond + ":\n" + 
                                        (yyvsp[-2].node)->code + 
                                        "   cmp $0, 0(%rsp)\n"
                                        "   popq %rax\n"
                                        "   je " + l_end + "\n" +
                                        (yyvsp[0].node)->code +
                                        "   jmp " + l_cond + "\n" +
                                        l_end + ":\n";
                                    }
#line 2053 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 494 "a.y" /* yacc.c:1646  */
    { 
                                                (yyvsp[-6].node) = new treeNode("DO"); (yyvsp[-4].node) = new treeNode("WHILE");
                                                (yyvsp[-3].node) = new treeNode("("); (yyvsp[-1].node) = new treeNode(")"); (yyvsp[0].node) = new treeNode(";");
                                                vector<treeNode*> v = {(yyvsp[-6].node), (yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                                (yyval.node) = new treeNode("dowhile_stmt", v);  
                                            }
#line 2064 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 501 "a.y" /* yacc.c:1646  */
    {
                                                                    (yyvsp[-6].node) = new treeNode("PRINTF"); (yyvsp[-5].node) = new treeNode("("); (yyvsp[-3].node) = new treeNode(",");
                                                                    (yyvsp[-1].node) = new treeNode(")"); (yyvsp[0].node) = new treeNode(";");
                                                                    vector<treeNode*> v = {(yyvsp[-6].node), (yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                                                    (yyval.node) = new treeNode("print_stmt", v); 
                                                                    (yyval.node)->code = 
																	"   movl	-" + to_string(symbolTable[(yyvsp[-2].node)->lexValue]) + "(%rbp), %eax\n"
	                                                                "   movl	%eax, %esi\n"
	                                                                "   leaq	.LC0(%rip), %rdi\n"
	                                                                "   movl	$0, %eax\n"
	                                                                "   call	printf@PLT\n";
                                                                    //cout << $$->code << flush;
                                                                }
#line 2082 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 515 "a.y" /* yacc.c:1646  */
    {
                                (yyvsp[0].node) = new treeNode("PERCENTD");
                                vector<treeNode*> v = {(yyvsp[0].node)};
                                (yyval.node) = new treeNode("format_specifier", v);
                            }
#line 2092 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 521 "a.y" /* yacc.c:1646  */
    {
                                                    (yyvsp[-3].node) = new treeNode("{"); (yyvsp[0].node) = new treeNode("}");
                                                    vector<treeNode*> v = {(yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                                    (yyval.node) = new treeNode("compound_stmt", v);
                                                    (yyval.node)->code = (yyvsp[-2].node)->code + (yyvsp[-1].node)->code;
                                                }
#line 2103 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 528 "a.y" /* yacc.c:1646  */
    {
                                        vector<treeNode*> v = {(yyvsp[-1].node), (yyvsp[0].node)};
                                        (yyval.node) = new treeNode("local_decls", v);
                                        (yyval.node)->code = (yyvsp[-1].node)->code + (yyvsp[0].node)->code;
                                    }
#line 2113 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 533 "a.y" /* yacc.c:1646  */
    {
                    auto x = new treeNode("epsilon");
                    vector<treeNode*> v = {x};
                    (yyval.node) = new treeNode("local_decls", v);
                }
#line 2123 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 539 "a.y" /* yacc.c:1646  */
    {
                                            (yyvsp[0].node) = new treeNode(";");
                                            vector<treeNode*> v = {(yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                            (yyval.node) = new treeNode("local_decl", v);
                                            int offset = 8 * symbolTable.size() + 8;
                                            symbolTable[(yyvsp[-1].node)->lexValue] = offset;
                                            (yyval.node)->code = 
                                            "   pushq $0\n"
                                            "   movq %rbp, %rsp\n"
                                            "   subq $" + to_string(offset) + ", %rsp\n";
                                            //cout << $$->code << flush;
                                        }
#line 2140 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 551 "a.y" /* yacc.c:1646  */
    {
                                                        (yyvsp[-3].node) = new treeNode("["); (yyvsp[-1].node) = new treeNode("]"); (yyvsp[0].node) = new treeNode(";");
                                                        vector<treeNode*> v = {(yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                                        (yyval.node) = new treeNode("local_decl", v); 
                                                    }
#line 2150 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 557 "a.y" /* yacc.c:1646  */
    {   
                                    (yyvsp[-4].node) = new treeNode("IF");
                                    (yyvsp[-3].node) = new treeNode("("); (yyvsp[-1].node) = new treeNode(")");
                                    vector<treeNode*> v = {(yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                    (yyval.node) = new treeNode("if_stmt", v);
                                    set_ifLongestPath((yyval.node)->maxSubtreeLength); 
                                    string l = newLabel();
                                    (yyval.node)->code = 
                                    (yyvsp[-2].node)->code + 
                                    "   cmp $0, 0(%rsp)\n"
                                    "   popq %rax\n"
                                    "   je " + l + "\n" +
                                    (yyvsp[0].node)->code +
                                    l + ":\n";
                                }
#line 2170 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 572 "a.y" /* yacc.c:1646  */
    { 
                                            (yyvsp[-6].node) = new treeNode("IF");
                                            (yyvsp[-5].node) = new treeNode("("); (yyvsp[-3].node) = new treeNode(")"); (yyvsp[-1].node) = new treeNode("ELSE");
                                            vector<treeNode*> v = {(yyvsp[-6].node), (yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                            (yyval.node) = new treeNode("if_stmt", v);
                                            set_ifLongestPath((yyval.node)->maxSubtreeLength); 
                                            string l_end = newLabel();
                                            string l_else = newLabel();
                                            (yyval.node)->code = 
                                            (yyvsp[-4].node)->code + 
                                            "   cmp $0, 0(%rsp)\n"
                                            "   popq %rax\n"
                                            "   je " + l_else + "\n" +
                                            (yyvsp[-2].node)->code +
                                            "   jmp " + l_end + "\n" +
                                            l_else + ":\n" + 
                                            (yyvsp[0].node)->code + 
                                            l_end + ":\n";
                                        }
#line 2194 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 592 "a.y" /* yacc.c:1646  */
    { 
                            (yyvsp[-1].node) = new treeNode("RETURN"); (yyvsp[0].node) = new treeNode(";");
                            vector<treeNode*> v = {(yyvsp[-1].node), (yyvsp[0].node)};
                            (yyval.node) = new treeNode("return_stmt", v);
                        }
#line 2204 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 597 "a.y" /* yacc.c:1646  */
    {
                                    (yyvsp[-2].node) = new treeNode("RETURN"); (yyvsp[0].node) = new treeNode(";");
                                    vector<treeNode*> v = {(yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                    (yyval.node) = new treeNode("return_stmt", v);
                                }
#line 2214 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 603 "a.y" /* yacc.c:1646  */
    {
                            (yyvsp[-1].node) = new treeNode("BREAK"); (yyvsp[0].node) = new treeNode(";");
                            vector<treeNode*> v = {(yyvsp[-1].node), (yyvsp[0].node)};
                            (yyval.node) = new treeNode("break_stmt", v);
                        }
#line 2224 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 609 "a.y" /* yacc.c:1646  */
    {
                                (yyvsp[-1].node) = new treeNode("CONTINUE"); (yyvsp[0].node) = new treeNode(";");
                                vector<treeNode*> v = {(yyvsp[-1].node), (yyvsp[0].node)};
                                (yyval.node) = new treeNode("continue_stmt", v);
                            }
#line 2234 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 615 "a.y" /* yacc.c:1646  */
    {
                                                                        (yyvsp[-7].node) = new treeNode("SWITCH");
                                                                        (yyvsp[-6].node) = new treeNode("("); (yyvsp[-4].node) = new treeNode(")");
                                                                        (yyvsp[-3].node) = new treeNode("{"); (yyvsp[0].node) = new treeNode("}");
                                                                        vector<treeNode*> v = {(yyvsp[-7].node), (yyvsp[-6].node), (yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                                                        (yyval.node) = new treeNode("switch_stmt", v);
                                                                        set_switchLongestPath((yyval.node)->maxSubtreeLength);    
                                                                    }
#line 2247 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 624 "a.y" /* yacc.c:1646  */
    {
                                                vector<treeNode*> v = {(yyvsp[-1].node), (yyvsp[0].node)};
                                                (yyval.node) = new treeNode("compound_case", v); 
                                            }
#line 2256 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 628 "a.y" /* yacc.c:1646  */
    {
                                vector<treeNode*> v = {(yyvsp[0].node)};
                                (yyval.node) = new treeNode("compound_case", v);
                            }
#line 2265 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 633 "a.y" /* yacc.c:1646  */
    {
                                                (yyvsp[-3].node) = new treeNode("CASE"); (yyvsp[-1].node) = new treeNode(":");
                                                vector<treeNode*> v = {(yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                                (yyval.node) = new treeNode("single_case", v);
                                            }
#line 2275 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 639 "a.y" /* yacc.c:1646  */
    {
                                        (yyvsp[-2].node) = new treeNode("DEFAULT"); (yyvsp[-1].node) = new treeNode(":");
                                        vector<treeNode*> v = {(yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                        (yyval.node) = new treeNode("default_case", v);
                                    }
#line 2285 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 645 "a.y" /* yacc.c:1646  */
    {
                                        vector<treeNode*> u = {(yyvsp[-3].node), (yyvsp[-1].node)};
                                        (yyvsp[-2].node) = new treeNode("EQ", u);
                                        (yyvsp[0].node) = new treeNode(";");
                                        vector<treeNode*> v = {(yyvsp[-2].node), (yyvsp[0].node)};
                                        (yyval.node) = new treeNode("assign_stmt", v);
                                        (yyval.node)->code = 	(yyvsp[-1].node)->code + 
													"   popq -" + to_string(symbolTable[(yyvsp[-3].node)->lexValue]) + "(%rbp)\n";
                                    }
#line 2299 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 654 "a.y" /* yacc.c:1646  */
    {   // check this one
                                                        (yyvsp[-5].node) = new treeNode("["); (yyvsp[-3].node) = new treeNode("]"); (yyvsp[0].node) = new treeNode(";");
                                                        vector<treeNode*> u = {(yyvsp[-6].node), (yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-1].node)};
                                                        (yyvsp[-2].node) = new treeNode("EQ", u);
                                                        vector<treeNode*> v = {(yyvsp[-2].node), (yyvsp[0].node)};
                                                        (yyval.node) = new treeNode("assign_stmt", v);    
                                                    }
#line 2311 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 661 "a.y" /* yacc.c:1646  */
    {
                                                            (yyvsp[0].node) = new treeNode(";");
                                                            (yyvsp[-4].node) = new treeNode("ARROW");
                                                            vector<treeNode*> u = {(yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-1].node)};
                                                            (yyvsp[-2].node) = new treeNode("EQ", u);
                                                            vector<treeNode*> v = {(yyvsp[-2].node), (yyvsp[0].node)};
                                                            (yyval.node) = new treeNode("assign_stmt", v);
                                                        }
#line 2324 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 669 "a.y" /* yacc.c:1646  */
    {
                                                        (yyvsp[0].node) = new treeNode(";");
                                                        (yyvsp[-4].node) = new treeNode(".");
                                                        vector<treeNode*> u = {(yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-1].node)};
                                                        (yyvsp[-2].node) = new treeNode("EQ", u);
                                                        vector<treeNode*> v = {(yyvsp[-2].node), (yyvsp[0].node)};
                                                        (yyval.node) = new treeNode("assign_stmt", v);
                                                    }
#line 2337 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 678 "a.y" /* yacc.c:1646  */
    {
                                    (yyvsp[0].node) = new treeNode(";");
                                    (yyvsp[-1].node) = new treeNode("INC");
                                    vector<treeNode*> v = {(yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                    (yyval.node) = new treeNode("incr_stmt", v);
                                    (yyval.node)->code = "   incq -" + to_string(symbolTable[(yyvsp[-2].node)->lexValue]) + "(%rbp)\n";
                                }
#line 2349 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 686 "a.y" /* yacc.c:1646  */
    {
                                    (yyvsp[0].node) = new treeNode(";");
                                    (yyvsp[-1].node) = new treeNode("DEC");
                                    vector<treeNode*> v = {(yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                    (yyval.node) = new treeNode("decr_stmt", v);
                                    (yyval.node)->code = "   decq -" + to_string(symbolTable[(yyvsp[-2].node)->lexValue]) + "(%rbp)\n";
                                }
#line 2361 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 694 "a.y" /* yacc.c:1646  */
    {
                            vector<treeNode*> u = {(yyvsp[-2].node), (yyvsp[0].node)};
                            (yyvsp[-1].node) = new treeNode("LT", u);
                            vector<treeNode*> v = {(yyvsp[-1].node)};
                            (yyval.node) = new treeNode("expr", v);
							string l = newLabel();
							(yyval.node)->code = 
							(yyvsp[-2].node)->code + 
							(yyvsp[0].node)->code +
                            "   popq %rax\n"
							"   cmp %rax, 0(%rsp)\n"
							"   movq $0, 0(%rsp)\n"
							"   jnl " + l + "\n"
							"   notq 0(%rsp)\n" + 
							l + ":\n";

                        }
#line 2383 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 711 "a.y" /* yacc.c:1646  */
    {   
                            vector<treeNode*> u = {(yyvsp[-2].node), (yyvsp[0].node)};
                            (yyvsp[-1].node) = new treeNode("GT", u);
                            vector<treeNode*> v = {(yyvsp[-1].node)};
                            (yyval.node) = new treeNode("expr", v);
                            string l = newLabel();
							(yyval.node)->code = 
							(yyvsp[-2].node)->code + 
							(yyvsp[0].node)->code +
							"   popq %rax\n"
							"   cmp %rax, 0(%rsp)\n"
							"   movq $0, 0(%rsp)\n"
							"   jng " + l + "\n"
							"   notq 0(%rsp)\n" + 
							l + ":\n";
                        }
#line 2404 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 727 "a.y" /* yacc.c:1646  */
    {
                            vector<treeNode*> u = {(yyvsp[-2].node), (yyvsp[0].node)};
                            (yyvsp[-1].node) = new treeNode("LEQ", u);
                            vector<treeNode*> v = {(yyvsp[-1].node)};
                            (yyval.node) = new treeNode("expr", v);
                            string l = newLabel();
							(yyval.node)->code = 
							(yyvsp[-2].node)->code + 
							(yyvsp[0].node)->code +
							"   popq %rax\n"
							"   cmp %rax, 0(%rsp)\n"
							"   movq $0, 0(%rsp)\n"
							"   jnle " + l + "\n"
							"   notq 0(%rsp)\n" + 
							l + ":\n";
                        }
#line 2425 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 743 "a.y" /* yacc.c:1646  */
    {
                            vector<treeNode*> u = {(yyvsp[-2].node), (yyvsp[0].node)};
                            (yyvsp[-1].node) = new treeNode("GEQ", u);
                            vector<treeNode*> v = {(yyvsp[-1].node)};
                            (yyval.node) = new treeNode("expr", v);
                            string l = newLabel();
							(yyval.node)->code = 
							(yyvsp[-2].node)->code + 
							(yyvsp[0].node)->code +
							"   popq %rax\n"
							"   cmp %rax, 0(%rsp)\n"
							"   movq $0, 0(%rsp)\n"
							"   jnge " + l + "\n"
							"   notq 0(%rsp)\n" + 
							l + ":\n";
                        }
#line 2446 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 759 "a.y" /* yacc.c:1646  */
    {
                            vector<treeNode*> u = {(yyvsp[-2].node), (yyvsp[0].node)};
                            (yyvsp[-1].node) = new treeNode("OR", u);
                            vector<treeNode*> v = {(yyvsp[-1].node)};
                            (yyval.node) = new treeNode("expr", v);
                            "   or 0(%rsp), 8(%rsp)\n"
							"   popq %rax\n";
                        }
#line 2459 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 767 "a.y" /* yacc.c:1646  */
    {
                                (yyvsp[-3].node) = new treeNode("SIZEOF"); (yyvsp[-2].node) = new treeNode("("); (yyvsp[0].node) = new treeNode(")");
                                vector<treeNode*> v = {(yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                (yyval.node) = new treeNode("expr", v);
                            }
#line 2469 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 772 "a.y" /* yacc.c:1646  */
    {
                            vector<treeNode*> u = {(yyvsp[-2].node), (yyvsp[0].node)};
                            (yyvsp[-1].node) = new treeNode("EQEQ", u);
                            vector<treeNode*> v = {(yyvsp[-1].node)};
                            (yyval.node) = new treeNode("expr", v);
							string l = newLabel();
							(yyval.node)->code = 
							(yyvsp[-2].node)->code + 
							(yyvsp[0].node)->code +
							"   popq %rax\n"
							"   cmp %rax, 0(%rsp)\n"
							"   movq $0, 0(%rsp)\n"
							"   jne " + l + "\n"
							"   notq 0(%rsp)\n" + 
							l + ":\n";
                        }
#line 2490 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 788 "a.y" /* yacc.c:1646  */
    {
                            vector<treeNode*> u = {(yyvsp[-2].node), (yyvsp[0].node)};
                            (yyvsp[-1].node) = new treeNode("NEQ", u);
                            vector<treeNode*> v = {(yyvsp[-1].node)};
                            (yyval.node) = new treeNode("expr", v); 
                            string l = newLabel();
							(yyval.node)->code = 
							(yyvsp[-2].node)->code + 
							(yyvsp[0].node)->code +
							"   popq %rax\n"
							"   cmp %rax, 0(%rsp)\n"
							"   movq $0, 0(%rsp)\n"
							"   je " + l + "\n"
							"   notq 0(%rsp)\n" + 
							l + ":\n";
							
                        }
#line 2512 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 805 "a.y" /* yacc.c:1646  */
    {
                            vector<treeNode*> u = {(yyvsp[-2].node), (yyvsp[0].node)};
                            (yyvsp[-1].node) = new treeNode("NEWOP", u);
                            vector<treeNode*> v = {(yyvsp[-1].node)};
                            (yyval.node) = new treeNode("expr", v);	//TODO
                        }
#line 2523 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 811 "a.y" /* yacc.c:1646  */
    {
                            vector<treeNode*> u = {(yyvsp[-2].node), (yyvsp[0].node)};
                            (yyvsp[-1].node) = new treeNode("AND", u);
                            vector<treeNode*> v = {(yyvsp[-1].node)};
                            (yyval.node) = new treeNode("expr", v);
							(yyval.node)->code = 
							(yyvsp[-2].node)->code + 
							(yyvsp[0].node)->code +
							"   popq %rax\n"
                            "   popq %rbx\n"
							"   andq %rax, %rbx\n"
							"   pushq %rbx\n";

							
                        }
#line 2543 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 826 "a.y" /* yacc.c:1646  */
    {
                            vector<treeNode*> u = {(yyvsp[-2].node), (yyvsp[0].node)};
                            (yyvsp[-1].node) = new treeNode("ARROW", u);
                            vector<treeNode*> v = {(yyvsp[-1].node)};
                            (yyval.node) = new treeNode("expr", v);
                        }
#line 2554 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 832 "a.y" /* yacc.c:1646  */
    {
                            vector<treeNode*> u = {(yyvsp[-2].node), (yyvsp[0].node)};
                            (yyvsp[-1].node) = new treeNode("PLUS", u);
                            vector<treeNode*> v = {(yyvsp[-1].node)};
                            (yyval.node) = new treeNode("expr", v);
							(yyval.node)->code = 
							(yyvsp[-2].node)->code + 
							(yyvsp[0].node)->code + 
                            "   popq %rax\n"
                            "   popq %rbx\n"
							"   addq %rax, %rbx\n"
							"   pushq %rbx\n";
                        }
#line 2572 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 845 "a.y" /* yacc.c:1646  */
    {
                            vector<treeNode*> u = {(yyvsp[-2].node), (yyvsp[0].node)};
                            (yyvsp[-1].node) = new treeNode("MINUS", u);
                            vector<treeNode*> v = {(yyvsp[-1].node)};
                            (yyval.node) = new treeNode("expr", v);
							(yyval.node)->code = 
							(yyvsp[-2].node)->code + 
							(yyvsp[0].node)->code + 
							"   popq %rax\n"
                            "   popq %rbx\n"
							"   subq %rax, %rbx\n"
							"   pushq %rbx\n";
                        }
#line 2590 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 858 "a.y" /* yacc.c:1646  */
    {
                            vector<treeNode*> u = {(yyvsp[-2].node), (yyvsp[0].node)};
                            (yyvsp[-1].node) = new treeNode("MULT", u);
                            vector<treeNode*> v = {(yyvsp[-1].node)};
                            (yyval.node) = new treeNode("expr", v);
							(yyval.node)->code = 
							(yyvsp[-2].node)->code + 
							(yyvsp[0].node)->code + 
                            "   popq %rax\n"
							"   imulq 0(%rsp)\n"
							"   mov %rax, 0(%rsp)\n";
                        }
#line 2607 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 870 "a.y" /* yacc.c:1646  */
    {
                            vector<treeNode*> u = {(yyvsp[-2].node), (yyvsp[0].node)};
                            (yyvsp[-1].node) = new treeNode("DIV", u);
                            vector<treeNode*> v = {(yyvsp[-1].node)};
                            (yyval.node) = new treeNode("expr", v);
							(yyval.node)->code = 
							(yyvsp[-2].node)->code + 
							(yyvsp[0].node)->code + 
                            "   popq %rbx\n"
                            "   popq %rax\n"
                            "   cqto\n"
							"   idivq %rbx\n"
                            "   pushq %rax\n";
                        }
#line 2626 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 884 "a.y" /* yacc.c:1646  */
    {
                            vector<treeNode*> u = {(yyvsp[-2].node), (yyvsp[0].node)};
                            (yyvsp[-1].node) = new treeNode("MOD", u);
                            vector<treeNode*> v = {(yyvsp[-1].node)};
                            (yyval.node) = new treeNode("expr", v);
							(yyval.node)->code = 
							(yyvsp[-2].node)->code + 
							(yyvsp[0].node)->code + 
							"   popq %rbx\n"
                            "   popq %rax\n"
                            "   cqto\n"
							"   idivq %rbx\n"
                            "   pushq %rdx\n";
                        }
#line 2645 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 898 "a.y" /* yacc.c:1646  */
    {
                    (yyvsp[-1].node) = new treeNode("NOT");
                    vector<treeNode*> v = {(yyvsp[-1].node), (yyvsp[0].node)};
                    (yyval.node) = new treeNode("expr", v);
					(yyval.node)->code = 
					(yyvsp[0].node)->code + 
                    "   popq %rax\n"
					"   notq %rax\n"
                    "   pushq %rax\n";
                }
#line 2660 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 908 "a.y" /* yacc.c:1646  */
    {
                        (yyvsp[-1].node) = new treeNode("MINUS");
                        vector<treeNode*> v = {(yyvsp[-1].node), (yyvsp[0].node)};
                        (yyval.node) = new treeNode("expr", v);
						(yyval.node)->code = 
						(yyvsp[0].node)->code +
						"   popq %rax\n"
                        "   negq %rax\n"
                        "   pushq %rax\n";
                    }
#line 2675 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 918 "a.y" /* yacc.c:1646  */
    {
                        (yyvsp[-1].node) = new treeNode("PLUS");
                        vector<treeNode*> v = {(yyvsp[-1].node), (yyvsp[0].node)};
                        (yyval.node) = new treeNode("expr", v);
						(yyval.node)->code = (yyvsp[0].node)->code;
                    }
#line 2686 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 924 "a.y" /* yacc.c:1646  */
    {
                        (yyvsp[-1].node) = new treeNode("MULT");
                        vector<treeNode*> v = {(yyvsp[-1].node), (yyvsp[0].node)};
                        (yyval.node) = new treeNode("expr", v);
                    }
#line 2696 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 929 "a.y" /* yacc.c:1646  */
    {   
                        (yyvsp[-1].node) = new treeNode("BITAND");
                        vector<treeNode*> v = {(yyvsp[-1].node), (yyvsp[0].node)};
                        (yyval.node) = new treeNode("expr", v);
                    }
#line 2706 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 934 "a.y" /* yacc.c:1646  */
    {
                vector<treeNode*> v = {(yyvsp[0].node)};
                (yyval.node) = new treeNode("expr", v);
				(yyval.node)->code = (yyvsp[0].node)->code;
            }
#line 2716 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 939 "a.y" /* yacc.c:1646  */
    {
                                    (yyvsp[-2].node) = new treeNode("("); (yyvsp[0].node) = new treeNode(")");
                                    vector<treeNode*> v = {(yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                    (yyval.node) = new treeNode("expr", v); 
                                }
#line 2726 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 944 "a.y" /* yacc.c:1646  */
    {
                                    (yyvsp[-2].node) = new treeNode("["); (yyvsp[0].node) = new treeNode("]");
                                    vector<treeNode*> v = {(yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                    (yyval.node) = new treeNode("expr", v); 
                                }
#line 2736 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 950 "a.y" /* yacc.c:1646  */
    {
                        vector<treeNode*> v = {(yyvsp[0].node)};
                        (yyval.node) = new treeNode("Pexpr", v);
						(yyval.node)->code = 
						"   pushq $" + (yyvsp[0].node)->lexValue + "\n";
                    }
#line 2747 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 956 "a.y" /* yacc.c:1646  */
    {
                    vector<treeNode*> v = {(yyvsp[0].node)};
                    (yyval.node) = new treeNode("Pexpr", v);
                }
#line 2756 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 960 "a.y" /* yacc.c:1646  */
    {
                        vector<treeNode*> v = {(yyvsp[0].node)};
                        (yyval.node) = new treeNode("Pexpr", v);
                        (yyval.node)->code = 
						"   pushq -" + to_string(symbolTable[(yyvsp[0].node)->lexValue]) + "(%rbp)\n";
                    }
#line 2767 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 966 "a.y" /* yacc.c:1646  */
    {
                        (yyvsp[-2].node) = new treeNode("("); (yyvsp[0].node) = new treeNode(")");
                        vector<treeNode*> v = {(yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                        (yyval.node) = new treeNode("Pexpr", v);
                        (yyval.node)->code = (yyvsp[-1].node)->code;
                    }
#line 2778 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 973 "a.y" /* yacc.c:1646  */
    {
                                (yyvsp[0].node) = new treeNode("INTEGER_NUMBER");
                                vector<treeNode*> v = {(yyvsp[0].node)};
                                (yyval.node) = new treeNode("intergerLit", v);
								(yyval.node)->lexValue = mytext;
                            }
#line 2789 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 980 "a.y" /* yacc.c:1646  */
    {
                            (yyvsp[0].node) = new treeNode("FLOAT_NUMBER");
                            vector<treeNode*> v = {(yyvsp[0].node)};
                            (yyval.node) = new treeNode("floatLit", v);
                        }
#line 2799 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 986 "a.y" /* yacc.c:1646  */
    {
                            (yyvsp[0].node) = new treeNode("IDENTIFIER");
                            vector<treeNode*> v = {(yyvsp[0].node)};
                            (yyval.node) = new treeNode("identifier", v);
                            (yyval.node)->lexValue = mytext;
                        }
#line 2810 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 992 "a.y" /* yacc.c:1646  */
    {
                        (yyvsp[0].node) = new treeNode("IDENTIFIER");
                        vector<treeNode*> v = {(yyvsp[0].node)};
                        (yyval.node) = new treeNode("identifier", v);
                        (yyval.node)->lexValue = "printf";
                    }
#line 2821 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 999 "a.y" /* yacc.c:1646  */
    {
                                (yyvsp[-1].node) = new treeNode(",");
                                vector<treeNode*> v = {(yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                (yyval.node) = new treeNode("arg_list", v);
                            }
#line 2831 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 1004 "a.y" /* yacc.c:1646  */
    {
                    vector<treeNode*> v = {(yyvsp[0].node)};
                    (yyval.node) = new treeNode("arg_list", v);
                }
#line 2840 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 1009 "a.y" /* yacc.c:1646  */
    {
                    vector<treeNode*> v = {(yyvsp[0].node)};
                    (yyval.node) = new treeNode("args", v);
                }
#line 2849 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 1013 "a.y" /* yacc.c:1646  */
    {
            auto x = new treeNode("epsilon");
            vector<treeNode*> v = {x};
            (yyval.node) = new treeNode("args", v);
        }
#line 2859 "y.tab.cpp" /* yacc.c:1646  */
    break;


#line 2863 "y.tab.cpp" /* yacc.c:1646  */
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
#line 1019 "a.y" /* yacc.c:1906  */


void yyerror(char* s) {
    //printf("***parsing terminated*** [syntax error]\n");
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

void printAST() {   // not a pretty printer
    queue<treeNode*> q;
    ast->level = 0;
    q.push(ast);
    int previous_level = 0;
    while(!q.empty()) {
        auto curr = q.front();
        q.pop();
        if(curr->level > previous_level) {
            cout << endl;
            previous_level = curr->level;
        }
        cout << curr->nodeName;
        for(int i = 0; i < 5; i++) {
            cout << ' ';
        }
        for(auto& child : curr->children) {
            child->level = 1 + curr->level;
            q.push(child);
        }
    }
    cout << endl;
}

void printAST(treeNode* root, string prefix = "", bool isLast = true) {
    if(root == NULL) {
        return;
    }
    cout << prefix;
    if(isLast) {
        cout << "└───────";
    }
    else {
        cout << "├───────";
    }
    cout << root->nodeName << endl;
    for(int i = 0; i < root->children.size(); i++) {
        if(i == root->children.size() - 1) {
            printAST(root->children[i], prefix + "|        ", true);
        }
        else {
            printAST(root->children[i], prefix + "|        ", false);
        }
    }
}

string newLabel() {
	static int count = 1;
	return "L" + to_string(++count);// + ":\n";
}

int main() {
    yyparse();
    /*
    // printf("***parsing successful***\n");
    printf("%d\n", programLongestPath);
    printf("%d\n", ifLongestPath);
    printf("%d\n", whileLongestPath);
    printf("%d\n", switchLongestPath);
    printf("%d\n", mainLongestPath);
    // printAST(ast, "", true);
    */
    return 0;
}
