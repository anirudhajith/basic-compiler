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
#line 12 "a.y" /* yacc.c:339  */

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
    int intDeclarations = 0;
    

    string newLabel() {
        static int LabelId = 0;
        return ".L" + to_string (++LabelId);
    }

    string makeIns (string com, string op1, string op2) {
        return "\t" + com + "\t" + op1 +  ", " + op2 + "\n";
    }
    string makeIns (string com, string op1) {
        return "\t" + com + "\t" + op1 +   "\n";
    }
    string putLabel (string L) {
        return L + ":\n";
    }


    string makeCompare (string jump_ins) {
        string L1 = newLabel();
        string L2 = newLabel();

        string res = "";
        res += makeIns ("cmpl", "%ebx", "%eax");
        res += makeIns(jump_ins, L1);
        res += makeIns ("movl", "$0", "%eax");
        res += makeIns ("jmp", L2);
        res += putLabel (L1);
        res += makeIns ("movl", "$1", "%eax");
        res += putLabel (L2);

        return res;
    } 
    

    class SymbolTableClass {
        public:
        vector <map<string, int>> ST;
        int offset = 0;

        SymbolTableClass () {
            incrementScope();
        }

        void incrementScope () {
            ST.push_back({});
        }

        int put (string var) {
            int l = ST.size() - 1;
            if (ST[l].find(var) != ST[l].end()) {
                cout << "Symbol Table Error: Multiple declarations of <" << var << "> in the same scope" << endl;

            }
            offset++;
            ST[l][var] = offset;
            
            return 4*offset;
        }

        void putArray (string var, int siz) {
            for (int i = 0; i <siz; i++) {
                put(var + "eesdj[" +  to_string(i) +  "]");
            }
            put (var);
        }

       

        int get (string var) {
            for (int i = ST.size() - 1; i >=0; i--) {
                if (ST[i].find(var) != ST[i].end()) {
                    return 4*ST[i][var];
                }
            }
            cout << "////Symbol Table Error: use of undeclared variable <" << var << ">" << endl;
            return -1;
        }

        void decrementScope () {
            int l = ST.size() - 1;
            offset -= ST[l].size();
            ST.pop_back();  
        }

    };

    SymbolTableClass symbolTable;




    class treeNode {
        public:
            vector<treeNode*> children;   // children
            int maxRootedLength;          // maximum path length passing through this node
            int maxSubtreeLength;         // maximum path length in the subtree rooted at this node  
            int maxDirectLength;          // maximum path length ending at this node
            string nodeName;              // name of the node
            string lexValue;              // lexical value, name of identifier etc.
            int level;                    // for printing
            int val = 0;


            string code = "";

            void addIns (string ins) {
                code += ("\t" + ins + "\n");
 
            }
            
            void append (treeNode *t) {
                code += t->code;
                std::string().swap(t->code); //Deletes this string and reclaims memory 

            }

            void append (string s) {
                code += s;
            }


            void makeIns (string com, string op1, string op2) {
                addIns(com + "\t" + op1 +  ", " + op2) ;
            }
            void makeIns (string com, string op1) {
                addIns( com + "\t" + op1 );
            }
            void makeIns (string ins) {
                addIns(ins);
            }
            void putLabel (string L) {
                code += (L + ":" + "\n");
            }


            treeNode(string nodeName, vector<treeNode*> children) {  // for non-terminals, assume valid pointers are passed
                this->nodeName = nodeName;
                this->children = children;
                maxRootedLength = 1;
                maxSubtreeLength = 1;
                maxDirectLength = 1;
                compute();
                // cout << nodeName << endl;
            }
            treeNode(string nodeName) {     // for epsilon and terminals, no need to call compute
                this->nodeName = nodeName;
                children.assign(0, NULL);
                maxRootedLength = 1;
                maxSubtreeLength = 1;
                maxDirectLength = 1;
                // cout << nodeName << endl;
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

#line 294 "y.tab.cpp" /* yacc.c:339  */

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
    SCANF = 294,
    PERCENTD = 295,
    VOID = 296,
    SWITCH = 297,
    CASE = 298,
    STRUCT = 299,
    BREAK = 300,
    CONTINUE = 301,
    RETURN = 302,
    STRLITERAL = 303,
    CHARLITERAL = 304,
    INC = 305,
    DEC = 306,
    ARROW = 307,
    SIZEOF = 308,
    DEFAULT = 309
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
#define SCANF 294
#define PERCENTD 295
#define VOID 296
#define SWITCH 297
#define CASE 298
#define STRUCT 299
#define BREAK 300
#define CONTINUE 301
#define RETURN 302
#define STRLITERAL 303
#define CHARLITERAL 304
#define INC 305
#define DEC 306
#define ARROW 307
#define SIZEOF 308
#define DEFAULT 309

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 240 "a.y" /* yacc.c:355  */

    class treeNode* node;

#line 446 "y.tab.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 463 "y.tab.cpp" /* yacc.c:358  */

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
#define YYLAST   356

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  111
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  231

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   309

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
      57,    58,     2,     2,    60,     2,    64,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    61,    59,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    55,     2,    56,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    62,     2,    63,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   350,   350,   360,   368,   375,   380,   388,   393,   400,
     406,   412,   418,   424,   430,   438,   444,   450,   456,   462,
     467,   473,   478,   484,   506,   506,   512,   518,   526,   534,
     541,   555,   567,   570,   576,   584,   590,   590,   597,   603,
     609,   613,   618,   622,   626,   630,   636,   642,   648,   655,
     676,   683,   699,   716,   722,   730,   736,   742,   754,   767,
     785,   805,   812,   822,   828,   834,   843,   847,   852,   858,
     864,   879,   895,   903,   912,   925,   936,   951,   963,   975,
     987,   999,  1007,  1020,  1032,  1072,  1084,  1092,  1108,  1122,
    1136,  1152,  1170,  1182,  1192,  1200,  1207,  1212,  1219,  1231,
    1244,  1253,  1257,  1266,  1275,  1283,  1289,  1295,  1302,  1313,
    1324,  1336
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
  "NOT", "MOD", "EXTERN", "LONG", "SHORT", "DOUBLE", "PRINTF", "SCANF",
  "PERCENTD", "VOID", "SWITCH", "CASE", "STRUCT", "BREAK", "CONTINUE",
  "RETURN", "STRLITERAL", "CHARLITERAL", "INC", "DEC", "ARROW", "SIZEOF",
  "DEFAULT", "'['", "']'", "'('", "')'", "';'", "','", "':'", "'{'", "'}'",
  "'.'", "$accept", "program", "decl_list", "decl", "struct_decl",
  "var_decl", "type_spec", "extern_spec", "func_decl", "params1", "$@1",
  "params", "param_list", "param", "stmt_list", "stmt", "$@2",
  "while_stmt", "dowhile_stmt", "print_stmt", "scan_stmt",
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
     305,   306,   307,   308,   309,    91,    93,    40,    41,    59,
      44,    58,   123,   125,    46
};
# endif

#define YYPACT_NINF -154

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-154)))

#define YYTABLE_NINF -70

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -15,  -154,    17,     3,    18,  -154,  -154,  -154,    17,    -8,
    -154,  -154,  -154,    -4,  -154,  -154,   -29,     2,     9,    40,
    -154,  -154,    55,  -154,  -154,    19,  -154,  -154,  -154,   -22,
    -154,    10,    20,   -23,    17,  -154,    17,    21,    17,  -154,
       5,    15,    17,  -154,    25,  -154,    78,     1,  -154,    24,
    -154,    19,  -154,  -154,    34,    19,   264,  -154,  -154,   219,
      49,  -154,  -154,    11,    11,    11,    11,    11,    50,   264,
      52,   285,  -154,  -154,   -32,    53,    56,   309,    57,    58,
      59,    47,    68,   114,   167,  -154,    15,  -154,  -154,  -154,
    -154,  -154,  -154,  -154,  -154,  -154,  -154,  -154,  -154,   -13,
    -154,  -154,  -154,  -154,  -154,  -154,  -154,    11,    51,    70,
      11,    11,    11,    11,    11,    11,    11,    11,    11,    11,
      11,    11,    11,    11,    11,   264,   264,   264,   264,   120,
      94,    94,   264,  -154,  -154,  -154,    76,  -154,  -154,  -154,
     264,    77,    85,    17,   264,    17,    87,  -154,  -154,  -154,
    -154,  -154,  -154,  -154,  -154,  -154,  -154,  -154,  -154,  -154,
    -154,  -154,  -154,  -154,    91,  -154,    90,    93,    98,   100,
     102,  -154,   101,   103,   104,  -154,   105,  -154,  -154,   142,
     109,   148,  -154,  -154,   264,  -154,   309,   309,   264,    17,
     143,   106,  -154,   264,   154,   264,  -154,   163,  -154,   118,
     130,    17,   135,   131,   264,   133,   309,   136,   137,   139,
      55,   140,   135,  -154,   144,  -154,  -154,  -154,  -154,   149,
     155,   156,   138,  -154,  -154,  -154,   309,   309,  -154,   237,
     197
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      22,    21,     0,     0,    22,     4,     7,     5,     0,     0,
       6,   106,   107,    19,     1,     3,     0,    14,    15,    13,
      20,    56,     0,    24,     9,    22,    17,    18,    16,    22,
     104,     0,     0,    22,     0,    10,     0,     0,     0,    55,
       0,     0,    32,    25,    26,    29,    19,     0,     8,     0,
      11,    22,    56,    23,    30,    22,     0,    57,    12,    22,
       0,    28,   105,     0,     0,     0,     0,     0,     0,     0,
       0,    97,   100,   101,   102,     0,     0,    36,   107,     0,
       0,     0,     0,     0,    36,    34,     0,    39,    44,    45,
      46,    38,    41,    42,    43,    40,    35,    47,    48,     0,
      31,    94,   102,    93,    95,    96,    92,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   111,     0,     0,     0,
       0,     0,     0,    63,    64,    61,     0,    54,    33,    37,
       0,     0,     0,     0,     0,     0,     0,   103,    58,    87,
      88,    89,    90,    82,    79,    78,    77,    76,    84,    83,
      85,    80,    91,    86,     0,   109,   110,     0,     0,     0,
       0,    53,     0,     0,     0,    62,     0,    74,    75,     0,
       0,     0,    81,    99,     0,    98,    36,    36,     0,     0,
       0,     0,    70,     0,     0,     0,   108,    59,    49,     0,
       0,     0,     0,     0,     0,     0,    36,     0,     0,     0,
       0,     0,    67,    72,     0,    73,    60,    50,    51,     0,
       0,     0,     0,    66,    71,    52,    36,    36,    65,    68,
      36
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -154,  -154,  -154,   194,  -154,    -1,   124,  -154,  -154,  -154,
    -154,  -154,  -154,   160,  -153,   -75,  -154,  -154,  -154,  -154,
    -154,    88,   132,   168,  -154,  -154,  -154,  -154,  -154,  -154,
      14,  -154,  -154,  -154,  -154,  -154,   -56,   -20,   -21,  -154,
      -2,  -154,  -154
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,     6,     7,     8,     9,    10,    32,
      33,    43,    44,    45,    84,    85,    86,    87,    88,    89,
      90,   172,    53,    29,    39,    91,    92,    93,    94,    95,
     211,   212,   222,    96,    97,    98,    70,    71,    72,    73,
     102,   166,   167
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      13,    31,   129,    14,    20,   140,    16,    17,    18,   138,
      26,     1,     1,   108,    11,    30,    62,    27,    -2,     1,
      11,    34,    34,   125,    35,   126,    22,   136,    23,     2,
      24,    25,    46,    19,    47,   -27,    49,   141,   142,   143,
      54,    37,   144,   101,   103,   104,   105,   106,    28,    12,
      58,   145,     1,     1,    74,    12,    22,    99,    21,    30,
      24,    25,     2,    34,    50,    51,    40,    74,    69,   164,
     165,   168,   169,   229,   230,    99,   174,    52,    41,    56,
      48,    74,    99,    57,   176,    55,    20,   146,   180,    60,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   100,   133,   107,   109,   147,
     127,   197,   198,   128,   130,   131,   132,    11,    30,    62,
      63,    64,    65,    74,    74,    74,    74,   134,   196,   148,
      74,   216,   199,   170,   171,   175,   177,   203,    74,   205,
      66,   179,    74,   181,   178,   182,    67,   183,   214,    36,
     184,   185,    12,    38,   138,   138,   186,    42,   187,   188,
     193,   189,   191,   190,   192,   194,   195,    68,   202,   201,
      11,    69,   204,   135,   206,    36,   207,    75,   210,    42,
      76,    77,    74,    38,    99,    99,    74,   200,   208,   220,
     213,    74,   215,    74,   221,   217,   218,   219,    15,   209,
      11,   228,    74,   224,    99,    78,    79,    75,   225,    80,
      76,    77,    81,    82,    83,    61,   226,   227,   139,   173,
      59,     0,    11,     0,    99,    99,   223,    99,    99,    75,
     137,     0,    76,    77,     0,    78,    79,     0,     0,    80,
      11,     0,    81,    82,    83,     0,     0,    75,     0,     0,
      76,    77,     0,     1,     0,     0,     0,    78,    79,     0,
     -69,    80,     0,    34,    81,    82,    83,    11,    30,    62,
      63,    64,    65,     0,     0,    78,    79,     0,     0,    80,
       0,   -36,    81,    82,    83,     0,     0,     0,     0,     0,
      66,   110,   111,   112,   113,     0,    67,     0,     0,   -36,
       0,     0,    12,     0,   114,   115,   116,   117,   118,   119,
     120,     0,    11,     0,     0,   121,   122,    68,   123,    75,
       0,    69,    76,    77,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   124,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    78,    79,     0,
       0,    80,     0,     0,    81,    82,    83
};

static const yytype_int16 yycheck[] =
{
       2,    22,    77,     0,     8,    18,     8,    15,    16,    84,
       8,    34,    34,    69,     3,     4,     5,     8,     0,    34,
       3,    44,    44,    55,    25,    57,    55,    83,    57,    44,
      59,    60,    34,    41,    36,    58,    38,    50,    51,    52,
      42,    63,    55,    63,    64,    65,    66,    67,     8,    38,
      51,    64,    34,    34,    56,    38,    55,    59,    62,     4,
      59,    60,    44,    44,    59,    60,    56,    69,    57,   125,
     126,   127,   128,   226,   227,    77,   132,    62,    58,    55,
      59,    83,    84,    59,   140,    60,     8,   107,   144,    55,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,    56,    59,    57,    56,    58,
      57,   186,   187,    57,    57,    57,    57,     3,     4,     5,
       6,     7,     8,   125,   126,   127,   128,    59,   184,    59,
     132,   206,   188,    13,    40,    59,    59,   193,   140,   195,
      26,   143,   144,   145,    59,    58,    32,    56,   204,    25,
      60,    58,    38,    29,   229,   230,    58,    33,    58,    57,
      18,    60,    58,    60,    59,    56,    18,    53,    62,    26,
       3,    57,    18,    59,    11,    51,    58,    10,    43,    55,
      13,    14,   184,    59,   186,   187,   188,   189,    58,   210,
      59,   193,    59,   195,    54,    59,    59,    58,     4,   201,
       3,    63,   204,    59,   206,    38,    39,    10,    59,    42,
      13,    14,    45,    46,    47,    55,    61,    61,    86,   131,
      52,    -1,     3,    -1,   226,   227,   212,   229,   230,    10,
      63,    -1,    13,    14,    -1,    38,    39,    -1,    -1,    42,
       3,    -1,    45,    46,    47,    -1,    -1,    10,    -1,    -1,
      13,    14,    -1,    34,    -1,    -1,    -1,    38,    39,    -1,
      63,    42,    -1,    44,    45,    46,    47,     3,     4,     5,
       6,     7,     8,    -1,    -1,    38,    39,    -1,    -1,    42,
      -1,    62,    45,    46,    47,    -1,    -1,    -1,    -1,    -1,
      26,     6,     7,     8,     9,    -1,    32,    -1,    -1,    62,
      -1,    -1,    38,    -1,    19,    20,    21,    22,    23,    24,
      25,    -1,     3,    -1,    -1,    30,    31,    53,    33,    10,
      -1,    57,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    -1,
      -1,    42,    -1,    -1,    45,    46,    47
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    34,    44,    66,    67,    68,    69,    70,    71,    72,
      73,     3,    38,   105,     0,    68,   105,    15,    16,    41,
       8,    62,    55,    57,    59,    60,     8,     8,     8,    88,
       4,   103,    74,    75,    44,    70,    71,    63,    71,    89,
      56,    58,    71,    76,    77,    78,   105,   105,    59,   105,
      59,    60,    62,    87,   105,    60,    55,    59,    70,    88,
      55,    78,     5,     6,     7,     8,    26,    32,    53,    57,
     101,   102,   103,   104,   105,    10,    13,    14,    38,    39,
      42,    45,    46,    47,    79,    80,    81,    82,    83,    84,
      85,    90,    91,    92,    93,    94,    98,    99,   100,   105,
      56,   102,   105,   102,   102,   102,   102,    57,   101,    56,
       6,     7,     8,     9,    19,    20,    21,    22,    23,    24,
      25,    30,    31,    33,    52,    55,    57,    57,    57,    80,
      57,    57,    57,    59,    59,    59,   101,    63,    80,    87,
      18,    50,    51,    52,    55,    64,   102,    58,    59,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   102,   102,   101,   101,   106,   107,   101,   101,
      13,    40,    86,    86,   101,    59,   101,    59,    59,   105,
     101,   105,    58,    56,    60,    58,    58,    58,    57,    60,
      60,    58,    59,    18,    56,    18,   101,    80,    80,   101,
     105,    26,    62,   101,    18,   101,    11,    58,    58,   105,
      43,    95,    96,    59,   101,    59,    80,    59,    59,    58,
     103,    54,    97,    95,    59,    59,    61,    61,    63,    79,
      79
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    65,    66,    67,    67,    68,    68,    68,    69,    70,
      70,    70,    70,    71,    71,    71,    71,    71,    71,    71,
      71,    72,    72,    73,    75,    74,    76,    76,    77,    77,
      78,    78,    78,    79,    79,    80,    81,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    82,
      83,    84,    85,    86,    87,    88,    88,    89,    89,    90,
      90,    91,    91,    92,    93,    94,    95,    95,    96,    97,
      98,    98,    98,    98,    99,   100,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     102,   102,   102,   102,   103,   104,   105,   105,   106,   106,
     107,   107
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     6,     3,
       4,     6,     7,     2,     2,     2,     3,     3,     3,     2,
       3,     1,     0,     6,     0,     2,     1,     0,     3,     1,
       2,     4,     1,     2,     1,     1,     0,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     5,
       7,     7,     8,     1,     4,     2,     0,     3,     6,     5,
       7,     2,     3,     2,     2,     8,     2,     1,     4,     3,
       4,     7,     6,     6,     3,     3,     3,     3,     3,     3,
       3,     4,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     2,     2,     2,     2,     1,     4,     4,
       1,     1,     1,     3,     1,     1,     1,     1,     3,     1,
       1,     0
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
#line 350 "a.y" /* yacc.c:1646  */
    {
                        vector<treeNode*> v = {(yyvsp[0].node)};
                        (yyval.node) = new treeNode("program", v); 
                        set_programLongestPath((yyval.node)->maxSubtreeLength);
                        (yyval.node) -> append((yyvsp[0].node));
                        ast = (yyval.node);


                    }
#line 1742 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 360 "a.y" /* yacc.c:1646  */
    { 
                                vector<treeNode*> v = {(yyvsp[-1].node), (yyvsp[0].node)};
                                (yyval.node) = new treeNode("decl_list", v);

                                (yyval.node)->append((yyvsp[-1].node));
                                (yyval.node)->append((yyvsp[0].node)); 
                            }
#line 1754 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 368 "a.y" /* yacc.c:1646  */
    {
                    vector<treeNode*> v = {(yyvsp[0].node)};
                    (yyval.node) = new treeNode("decl_list", v); 
                
                    (yyval.node)->append((yyvsp[0].node));
                }
#line 1765 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 375 "a.y" /* yacc.c:1646  */
    {   
                    vector<treeNode*> v = {(yyvsp[0].node)};
                    (yyval.node) = new treeNode("decl", v); 
                }
#line 1774 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 380 "a.y" /* yacc.c:1646  */
    {
                    vector<treeNode*> v = {(yyvsp[0].node)};
                    (yyval.node) = new treeNode("decl", v); 

                    (yyval.node)->append((yyvsp[0].node));
                    // symbolTable.decrementScope();
                }
#line 1786 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 388 "a.y" /* yacc.c:1646  */
    {
                        vector<treeNode*> v = {(yyvsp[0].node)};
                        (yyval.node) = new treeNode("decl", v); 
                    }
#line 1795 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 393 "a.y" /* yacc.c:1646  */
    {
                                                            (yyvsp[-5].node) = new treeNode("STRUCT"); (yyvsp[-3].node) = new treeNode("{"); 
                                                            (yyvsp[-1].node) = new treeNode("}"); (yyvsp[0].node) = new treeNode(";");
                                                            vector<treeNode*> v = {(yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                                            (yyval.node) = new treeNode("struct_decl", v); 
                                                        }
#line 1806 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 400 "a.y" /* yacc.c:1646  */
    {
                                        (yyvsp[0].node) = new treeNode(";");
                                        vector<treeNode*> v = {(yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                        (yyval.node) = new treeNode("var_decl", v); 
                                    }
#line 1816 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 406 "a.y" /* yacc.c:1646  */
    {
                                                (yyvsp[-1].node) = new treeNode(",");
                                                vector<treeNode*> v = {(yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                                (yyval.node) = new treeNode("var_decl", v); 
                                            }
#line 1826 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 412 "a.y" /* yacc.c:1646  */
    {
                                                            (yyvsp[-3].node) = new treeNode("["); (yyvsp[-1].node) = new treeNode("]"); (yyvsp[0].node) = new treeNode(";");
                                                            vector<treeNode*> v = {(yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                                            (yyval.node) = new treeNode("var_decl", v); 
                                                        }
#line 1836 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 418 "a.y" /* yacc.c:1646  */
    {
                                                                    (yyvsp[-4].node) = new treeNode("["); (yyvsp[-2].node) = new treeNode("]"); (yyvsp[-1].node) = new treeNode(",");
                                                                    vector<treeNode*> v = {(yyvsp[-6].node), (yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                                                    (yyval.node) = new treeNode("var_decl", v); 
                                                                }
#line 1846 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 424 "a.y" /* yacc.c:1646  */
    {
                                (yyvsp[0].node) = new treeNode("VOID");
                                vector<treeNode*> v = {(yyvsp[-1].node), (yyvsp[0].node)}; 
                                (yyval.node) = new treeNode("type_spec", v); 
                                
                            }
#line 1857 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 430 "a.y" /* yacc.c:1646  */
    {
                                (yyvsp[0].node) = new treeNode("INT");
                                vector<treeNode*> v = {(yyvsp[-1].node), (yyvsp[0].node)}; 
                                (yyval.node) = new treeNode("type_spec", v);
                                (yyval.node) -> lexValue = "int";
                                
                            }
#line 1869 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 438 "a.y" /* yacc.c:1646  */
    {
                                    (yyvsp[0].node) = new treeNode("FLOAT");
                                    vector<treeNode*> v = {(yyvsp[-1].node), (yyvsp[0].node)}; 
                                    (yyval.node) = new treeNode("type_spec", v);
                                }
#line 1879 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 444 "a.y" /* yacc.c:1646  */
    {
                                    (yyvsp[-1].node) = new treeNode("VOID"); (yyvsp[0].node) = new treeNode("MULT");
                                    vector<treeNode*> v = {(yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)}; 
                                    (yyval.node) = new treeNode("type_spec", v);
                                }
#line 1889 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 450 "a.y" /* yacc.c:1646  */
    {
                                    (yyvsp[-1].node) = new treeNode("INT"); (yyvsp[0].node) = new treeNode("MULT");
                                    vector<treeNode*> v = {(yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)}; 
                                    (yyval.node) = new treeNode("type_spec", v);
                                }
#line 1899 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 456 "a.y" /* yacc.c:1646  */
    {
                                    (yyvsp[-1].node) = new treeNode("FLOAT"); (yyvsp[0].node) = new treeNode("MULT");
                                    vector<treeNode*> v = {(yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)}; 
                                    (yyval.node) = new treeNode("type_spec", v);
                                  }
#line 1909 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 462 "a.y" /* yacc.c:1646  */
    {
                                    (yyvsp[-1].node) = new treeNode("STRUCT");
                                    vector<treeNode*> v = {(yyvsp[-1].node), (yyvsp[0].node)};
                                    (yyval.node) = new treeNode("type_spec", v); 
                                }
#line 1919 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 467 "a.y" /* yacc.c:1646  */
    {
                                        (yyvsp[-2].node) = new treeNode("STRUCT"); (yyvsp[0].node) = new treeNode("MULT");
                                        vector<treeNode*> v = {(yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                        (yyval.node) = new treeNode("type_spec", v);
                                    }
#line 1929 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 473 "a.y" /* yacc.c:1646  */
    {
                        (yyvsp[0].node) = new treeNode("EXTERN");
                        vector<treeNode*> v = {(yyvsp[0].node)};
                        (yyval.node) = new treeNode("extern_spec", v);
                    }
#line 1939 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 478 "a.y" /* yacc.c:1646  */
    {
                    auto x = new treeNode("epsilon");
                    vector<treeNode*> v = {x};
                    (yyval.node) = new treeNode("extern_spec", v);
                }
#line 1949 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 485 "a.y" /* yacc.c:1646  */
    {
    (yyvsp[-3].node) = new treeNode("("); (yyvsp[-1].node) = new treeNode(")");
    vector<treeNode*> v = {(yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
    (yyval.node) = new treeNode("func_decl", v);      
    if((yyvsp[-4].node)->lexValue == "main") {
        set_mainLongestPath((yyval.node)->maxSubtreeLength);
    }
    (yyval.node)->putLabel((yyvsp[-4].node)->lexValue);
    (yyval.node)->makeIns("pushq", "%rbp");
    //$$->append($4);

    (yyval.node)->makeIns("movq", "%rsp", "%rbp");
    string offset = "$" + to_string(8*intDeclarations + 16);
    (yyval.node)->makeIns("subq", offset, "%rsp");
    (yyval.node)->append((yyvsp[0].node));
    (yyval.node)->makeIns("leave");
    (yyval.node)->makeIns("ret");

    symbolTable.decrementScope();
}
#line 1974 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 506 "a.y" /* yacc.c:1646  */
    {symbolTable.incrementScope();}
#line 1980 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 506 "a.y" /* yacc.c:1646  */
    {
            
            (yyval.node) = (yyvsp[0].node);
            
    }
#line 1990 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 512 "a.y" /* yacc.c:1646  */
    {
                        vector<treeNode*> v = {(yyvsp[0].node)};
                        (yyval.node) = new treeNode("params", v);
                        (yyval.node)->val = (yyvsp[0].node)->val;
                        (yyval.node)->append((yyvsp[0].node));
                    }
#line 2001 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 518 "a.y" /* yacc.c:1646  */
    {
          auto x = new treeNode("epsilon");
          vector<treeNode*> v = {x};
          (yyval.node) = new treeNode("params", v);
          (yyval.node)->val = 0;
        
        }
#line 2013 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 526 "a.y" /* yacc.c:1646  */
    {
                                        (yyvsp[-1].node) = new treeNode(",");
                                        vector<treeNode*> v = {(yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                        (yyval.node) = new treeNode("param_list", v);
                                        (yyval.node)->val = (yyvsp[-2].node)->val + 1;
                                        (yyval.node)->append((yyvsp[-2].node));
                                        (yyval.node)->append((yyvsp[0].node));
                                    }
#line 2026 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 534 "a.y" /* yacc.c:1646  */
    {
                        vector<treeNode*> v = {(yyvsp[0].node)};
                        (yyval.node) = new treeNode("param_list", v);
                        (yyval.node)->val = 1;
                        (yyval.node)->append((yyvsp[0].node));
                    }
#line 2037 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 541 "a.y" /* yacc.c:1646  */
    {
                                vector<treeNode*> v = {(yyvsp[-1].node), (yyvsp[0].node)};
                                (yyval.node) = new treeNode("param", v);
                            
                                if ((yyvsp[-1].node) -> lexValue == "int") {
                                    intDeclarations++;
                                    int offset = symbolTable.put((yyvsp[0].node)->lexValue);
                                    // cout << "Identifier::" << $2->lexValue << endl;
                                    //$$->makeIns("popq", "%rax");
                                    //string arg2 = "-" + to_string(offset) + "(%rsp)";
                                    //$$->makeIns("movl", "%eax", arg2);

                                }
                            }
#line 2056 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 555 "a.y" /* yacc.c:1646  */
    {
                                        (yyvsp[-1].node) = new treeNode("["); (yyvsp[0].node) = new treeNode("]");
                                        vector<treeNode*> v = {(yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                        (yyval.node) = new treeNode("param", v);

                                        if ((yyvsp[-3].node) -> lexValue == "int") {
                                            intDeclarations++;
                                            symbolTable.put((yyvsp[-2].node)->lexValue);
                                            // cout << "Identifier::" << $2->lexValue << endl;
                                        }
                                    
                                    }
#line 2073 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 570 "a.y" /* yacc.c:1646  */
    {
                                vector<treeNode*> v = {(yyvsp[-1].node), (yyvsp[0].node)};
                                (yyval.node) = new treeNode("stmt_list", v);
                                (yyval.node)->append((yyvsp[-1].node));
                                (yyval.node)->append((yyvsp[0].node));
                            }
#line 2084 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 576 "a.y" /* yacc.c:1646  */
    {
                    vector<treeNode*> v = {(yyvsp[0].node)};
                    (yyval.node) = new treeNode("stmt_list", v);
                
                    (yyval.node)->append((yyvsp[0].node));
                    
                }
#line 2096 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 584 "a.y" /* yacc.c:1646  */
    {
                        vector<treeNode*> v = {(yyvsp[0].node)};
                        (yyval.node) = new treeNode("stmt", v);
                    
                        (yyval.node)->append((yyvsp[0].node));
                    }
#line 2107 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 590 "a.y" /* yacc.c:1646  */
    {symbolTable.incrementScope();}
#line 2113 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 590 "a.y" /* yacc.c:1646  */
    {
                        vector<treeNode*> v = {(yyvsp[0].node)};
                        (yyval.node) = new treeNode("stmt", v);
                        symbolTable.decrementScope();

                        (yyval.node)->append((yyvsp[0].node));
                    }
#line 2125 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 597 "a.y" /* yacc.c:1646  */
    {
                    vector<treeNode*> v = {(yyvsp[0].node)};
                    (yyval.node) = new treeNode("stmt", v);
                
                    (yyval.node)->append((yyvsp[0].node));
                }
#line 2136 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 603 "a.y" /* yacc.c:1646  */
    {
                        vector<treeNode*> v = {(yyvsp[0].node)};
                        (yyval.node) = new treeNode("stmt", v);
                    
                        (yyval.node)->append((yyvsp[0].node));
                    }
#line 2147 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 609 "a.y" /* yacc.c:1646  */
    {
                        vector<treeNode*> v = {(yyvsp[0].node)};
                        (yyval.node) = new treeNode("stmt", v);
                    }
#line 2156 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 613 "a.y" /* yacc.c:1646  */
    {
                        vector<treeNode*> v = {(yyvsp[0].node)};
                        (yyval.node) = new treeNode("stmt", v);
                        (yyval.node)->append((yyvsp[0].node));
                    }
#line 2166 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 618 "a.y" /* yacc.c:1646  */
    {
                    vector<treeNode*> v = {(yyvsp[0].node)};
                    (yyval.node) = new treeNode("stmt", v);
                 }
#line 2175 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 622 "a.y" /* yacc.c:1646  */
    {
                        vector<treeNode*> v = {(yyvsp[0].node)};
                        (yyval.node) = new treeNode("stmt", v);
                    }
#line 2184 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 626 "a.y" /* yacc.c:1646  */
    {    
                        vector<treeNode*> v = {(yyvsp[0].node)};
                        (yyval.node) = new treeNode("stmt", v);
                    }
#line 2193 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 630 "a.y" /* yacc.c:1646  */
    {
                        vector<treeNode*> v = {(yyvsp[0].node)};
                        (yyval.node) = new treeNode("stmt", v);
                    
                        (yyval.node)->append((yyvsp[0].node));
                    }
#line 2204 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 636 "a.y" /* yacc.c:1646  */
    {
                        vector<treeNode*> v = {(yyvsp[0].node)};
                        (yyval.node) = new treeNode("stmt", v);
                    
                        (yyval.node)->append((yyvsp[0].node));
                    }
#line 2215 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 642 "a.y" /* yacc.c:1646  */
    {
                    vector<treeNode*> v = {(yyvsp[0].node)};
                    (yyval.node) = new treeNode("stmt", v);

                    (yyval.node)->append((yyvsp[0].node));
                }
#line 2226 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 648 "a.y" /* yacc.c:1646  */
    {   
                    vector<treeNode*> v = {(yyvsp[0].node)};
                    (yyval.node) = new treeNode("stmt", v);
                
                    (yyval.node)->append((yyvsp[0].node));
                }
#line 2237 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 656 "a.y" /* yacc.c:1646  */
    { 
    (yyvsp[-4].node) = new treeNode("WHILE");
    (yyvsp[-3].node) = new treeNode("("); (yyvsp[-1].node) = new treeNode(")");
    vector<treeNode*> v = {(yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
    (yyval.node) = new treeNode("while_stmt", v); 
    set_whileLongestPath((yyval.node)->maxSubtreeLength); 

    string start = newLabel();
    string end = newLabel();

    (yyval.node)->putLabel(start);
    (yyval.node)->append((yyvsp[-2].node));
    (yyval.node)->makeIns("cmpl", "$0", "%eax");
    (yyval.node)->makeIns("je", end);
    (yyval.node)->append((yyvsp[0].node));
    (yyval.node)->makeIns("jmp", start);
    (yyval.node)->putLabel(end);

}
#line 2261 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 676 "a.y" /* yacc.c:1646  */
    { 
                                                (yyvsp[-6].node) = new treeNode("DO"); (yyvsp[-4].node) = new treeNode("WHILE");
                                                (yyvsp[-3].node) = new treeNode("("); (yyvsp[-1].node) = new treeNode(")"); (yyvsp[0].node) = new treeNode(";");
                                                vector<treeNode*> v = {(yyvsp[-6].node), (yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                                (yyval.node) = new treeNode("dowhile_stmt", v);  
                                            }
#line 2272 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 684 "a.y" /* yacc.c:1646  */
    {
    (yyvsp[-6].node) = new treeNode("PRINTF"); (yyvsp[-5].node) = new treeNode("("); (yyvsp[-3].node) = new treeNode(",");
    (yyvsp[-1].node) = new treeNode(")"); (yyvsp[0].node) = new treeNode(";");
    vector<treeNode*> v = {(yyvsp[-6].node), (yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
    (yyval.node) = new treeNode("print_stmt", v);
    
    int offset = symbolTable.get( (yyvsp[-2].node)->lexValue );
    string arg2 = "-" + to_string(offset) + "(%rbp)";
    (yyval.node)->makeIns("movl", arg2, "%esi");
    (yyval.node)->makeIns("leaq", ".LC1(%rip)", "%rdi");
    (yyval.node)->makeIns("movl", "$0", "%eax");
    (yyval.node)->makeIns("call", "printf@PLT");

}
#line 2291 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 700 "a.y" /* yacc.c:1646  */
    {
    (yyvsp[-7].node) = new treeNode("SCANF"); (yyvsp[-6].node) = new treeNode("("); (yyvsp[-4].node) = new treeNode(",");
    (yyvsp[-3].node) = new treeNode("BITAND");
    (yyvsp[-1].node) = new treeNode(")"); (yyvsp[0].node) = new treeNode(";");
    vector<treeNode*> v = {(yyvsp[-7].node), (yyvsp[-6].node), (yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
    (yyval.node) = new treeNode("scan_stmt", v);
    // TODO
    int offset = symbolTable.get( (yyvsp[-2].node)->lexValue );
    string arg2 = "-" + to_string(offset) + "(%rbp)";
    (yyval.node)->makeIns("leaq", arg2, "%rsi");
    (yyval.node)->makeIns("leaq", ".LC0(%rip)", "%rdi");
    (yyval.node)->makeIns("movl", "$0", "%eax");
    (yyval.node)->makeIns("call", "__isoc99_scanf");

}
#line 2311 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 716 "a.y" /* yacc.c:1646  */
    {
                                (yyvsp[0].node) = new treeNode("PERCENTD");
                                vector<treeNode*> v = {(yyvsp[0].node)};
                                (yyval.node) = new treeNode("format_specifier", v);
                            }
#line 2321 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 722 "a.y" /* yacc.c:1646  */
    {
                                                    (yyvsp[-3].node) = new treeNode("{"); (yyvsp[0].node) = new treeNode("}");
                                                    vector<treeNode*> v = {(yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                                    (yyval.node) = new treeNode("compound_stmt", v);
                                                    (yyval.node)->append((yyvsp[-2].node));
                                                    (yyval.node)->append((yyvsp[-1].node));
                                                }
#line 2333 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 730 "a.y" /* yacc.c:1646  */
    {
                                        vector<treeNode*> v = {(yyvsp[-1].node), (yyvsp[0].node)};
                                        (yyval.node) = new treeNode("local_decls", v);
                                        (yyval.node)->append((yyvsp[-1].node));
                                        (yyval.node)->append((yyvsp[0].node));
                                    }
#line 2344 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 736 "a.y" /* yacc.c:1646  */
    {
                    auto x = new treeNode("epsilon");
                    vector<treeNode*> v = {x};
                    (yyval.node) = new treeNode("local_decls", v);
                }
#line 2354 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 742 "a.y" /* yacc.c:1646  */
    {
                                            (yyvsp[0].node) = new treeNode(";");
                                            vector<treeNode*> v = {(yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                            (yyval.node) = new treeNode("local_decl", v);
                                            
                                            // cout << "type_spec::" << $1->lexValue << endl;
                                            if ((yyvsp[-2].node) -> lexValue == "int") {
                                                intDeclarations++;
                                                symbolTable.put((yyvsp[-1].node)->lexValue);
                                                // cout << "Identifier::" << $2->lexValue << endl;
                                            }
                                        }
#line 2371 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 754 "a.y" /* yacc.c:1646  */
    {
                                                        (yyvsp[-3].node) = new treeNode("["); (yyvsp[-1].node) = new treeNode("]"); (yyvsp[0].node) = new treeNode(";");
                                                        vector<treeNode*> v = {(yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                                        (yyval.node) = new treeNode("local_decl", v); 
                                                    
                                                        if ((yyvsp[-5].node) -> lexValue == "int") {
                                                            intDeclarations+= (yyvsp[-2].node)->val;
                                                            symbolTable.putArray((yyvsp[-4].node)->lexValue, (yyvsp[-2].node)->val);
                                                            // cout << "Identifier::" << $2->lexValue << endl;
                                                        }

                                                    }
#line 2388 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 767 "a.y" /* yacc.c:1646  */
    {   
                                    (yyvsp[-4].node) = new treeNode("IF");
                                    (yyvsp[-3].node) = new treeNode("("); (yyvsp[-1].node) = new treeNode(")");
                                    vector<treeNode*> v = {(yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                    (yyval.node) = new treeNode("if_stmt", v);
                                    set_ifLongestPath((yyval.node)->maxSubtreeLength);

                                    string end = newLabel();
                                    (yyval.node)->append((yyvsp[-2].node));
                                    (yyval.node)->makeIns("cmpl", "$0", "%eax");
                                    (yyval.node)->makeIns("je", end);
                                    (yyval.node)->append((yyvsp[0].node));
                                    (yyval.node)->putLabel(end);




                                }
#line 2411 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 785 "a.y" /* yacc.c:1646  */
    { 
                                            (yyvsp[-6].node) = new treeNode("IF");
                                            (yyvsp[-5].node) = new treeNode("("); (yyvsp[-3].node) = new treeNode(")"); (yyvsp[-1].node) = new treeNode("ELSE");
                                            vector<treeNode*> v = {(yyvsp[-6].node), (yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                            (yyval.node) = new treeNode("if_stmt", v);
                                            set_ifLongestPath((yyval.node)->maxSubtreeLength); 
                                        
                                            string els = newLabel();
                                            string end = newLabel();
                                            (yyval.node)->append((yyvsp[-4].node));
                                            (yyval.node)->makeIns("cmpl", "$0", "%eax");
                                            (yyval.node)->makeIns("je", els);
                                            (yyval.node)->append((yyvsp[-2].node));
                                            (yyval.node)->makeIns("jmp", end);
                                            (yyval.node)->putLabel(els);
                                            (yyval.node)->append((yyvsp[0].node));
                                            (yyval.node)->putLabel(end);       
                                        
                                        }
#line 2435 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 805 "a.y" /* yacc.c:1646  */
    { 
                            (yyvsp[-1].node) = new treeNode("RETURN"); (yyvsp[0].node) = new treeNode(";");
                            vector<treeNode*> v = {(yyvsp[-1].node), (yyvsp[0].node)};
                            (yyval.node) = new treeNode("return_stmt", v);
                            (yyval.node)->makeIns("leave");
                            (yyval.node)->makeIns("ret");
                        }
#line 2447 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 812 "a.y" /* yacc.c:1646  */
    {
                                    (yyvsp[-2].node) = new treeNode("RETURN"); (yyvsp[0].node) = new treeNode(";");
                                    vector<treeNode*> v = {(yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                    (yyval.node) = new treeNode("return_stmt", v);
                                
                                    (yyval.node)->append((yyvsp[-1].node));
                                    (yyval.node)->makeIns("leave");
                                    (yyval.node)->makeIns("ret");  
                                }
#line 2461 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 822 "a.y" /* yacc.c:1646  */
    {
                            (yyvsp[-1].node) = new treeNode("BREAK"); (yyvsp[0].node) = new treeNode(";");
                            vector<treeNode*> v = {(yyvsp[-1].node), (yyvsp[0].node)};
                            (yyval.node) = new treeNode("break_stmt", v);
                        }
#line 2471 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 828 "a.y" /* yacc.c:1646  */
    {
                                (yyvsp[-1].node) = new treeNode("CONTINUE"); (yyvsp[0].node) = new treeNode(";");
                                vector<treeNode*> v = {(yyvsp[-1].node), (yyvsp[0].node)};
                                (yyval.node) = new treeNode("continue_stmt", v);
                            }
#line 2481 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 834 "a.y" /* yacc.c:1646  */
    {
                                                                        (yyvsp[-7].node) = new treeNode("SWITCH");
                                                                        (yyvsp[-6].node) = new treeNode("("); (yyvsp[-4].node) = new treeNode(")");
                                                                        (yyvsp[-3].node) = new treeNode("{"); (yyvsp[0].node) = new treeNode("}");
                                                                        vector<treeNode*> v = {(yyvsp[-7].node), (yyvsp[-6].node), (yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                                                        (yyval.node) = new treeNode("switch_stmt", v);
                                                                        set_switchLongestPath((yyval.node)->maxSubtreeLength);    
                                                                    }
#line 2494 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 843 "a.y" /* yacc.c:1646  */
    {
                                                vector<treeNode*> v = {(yyvsp[-1].node), (yyvsp[0].node)};
                                                (yyval.node) = new treeNode("compound_case", v); 
                                            }
#line 2503 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 847 "a.y" /* yacc.c:1646  */
    {
                                vector<treeNode*> v = {(yyvsp[0].node)};
                                (yyval.node) = new treeNode("compound_case", v);
                            }
#line 2512 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 852 "a.y" /* yacc.c:1646  */
    {
                                                (yyvsp[-3].node) = new treeNode("CASE"); (yyvsp[-1].node) = new treeNode(":");
                                                vector<treeNode*> v = {(yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                                (yyval.node) = new treeNode("single_case", v);
                                            }
#line 2522 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 858 "a.y" /* yacc.c:1646  */
    {
                                        (yyvsp[-2].node) = new treeNode("DEFAULT"); (yyvsp[-1].node) = new treeNode(":");
                                        vector<treeNode*> v = {(yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                        (yyval.node) = new treeNode("default_case", v);
                                    }
#line 2532 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 864 "a.y" /* yacc.c:1646  */
    {
                                        vector<treeNode*> u = {(yyvsp[-3].node), (yyvsp[-1].node)};
                                        (yyvsp[-2].node) = new treeNode("EQ", u);
                                        (yyvsp[0].node) = new treeNode(";");
                                        vector<treeNode*> v = {(yyvsp[-2].node), (yyvsp[0].node)};
                                        (yyval.node) = new treeNode("assign_stmt", v);
                                        
                                        int offset = symbolTable.get( (yyvsp[-3].node)->lexValue );
                                        string arg2 = "-" + to_string(offset) + "(%rbp)";
                                        
                                        (yyval.node)->append((yyvsp[-1].node));
                                        (yyval.node)->makeIns("movl", "%eax", arg2);


                                    }
#line 2552 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 879 "a.y" /* yacc.c:1646  */
    {   // check this one
                                                        (yyvsp[-5].node) = new treeNode("["); (yyvsp[-3].node) = new treeNode("]"); (yyvsp[0].node) = new treeNode(";");
                                                        vector<treeNode*> u = {(yyvsp[-6].node), (yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-1].node)};
                                                        (yyvsp[-2].node) = new treeNode("EQ", u);
                                                        vector<treeNode*> v = {(yyvsp[-2].node), (yyvsp[0].node)};
                                                        (yyval.node) = new treeNode("assign_stmt", v);    
                                                    
                                                        int offset = symbolTable.get( (yyvsp[-6].node)->lexValue );
                                                        string arg1 = "-" + to_string(offset) + "(%rbp,%rax,4)";
                                                        (yyval.node)->append((yyvsp[-1].node));
                                                        (yyval.node)->makeIns("movl", "%eax", "%ebx");
                                                        
                                                        (yyval.node)->append((yyvsp[-4].node));
                                                        (yyval.node)->makeIns("movl", "%ebx"  ,arg1);    

                                                    }
#line 2573 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 895 "a.y" /* yacc.c:1646  */
    {
                                                            (yyvsp[0].node) = new treeNode(";");
                                                            (yyvsp[-4].node) = new treeNode("ARROW");
                                                            vector<treeNode*> u = {(yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-1].node)};
                                                            (yyvsp[-2].node) = new treeNode("EQ", u);
                                                            vector<treeNode*> v = {(yyvsp[-2].node), (yyvsp[0].node)};
                                                            (yyval.node) = new treeNode("assign_stmt", v);
                                                        }
#line 2586 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 903 "a.y" /* yacc.c:1646  */
    {
                                                        (yyvsp[0].node) = new treeNode(";");
                                                        (yyvsp[-4].node) = new treeNode(".");
                                                        vector<treeNode*> u = {(yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-1].node)};
                                                        (yyvsp[-2].node) = new treeNode("EQ", u);
                                                        vector<treeNode*> v = {(yyvsp[-2].node), (yyvsp[0].node)};
                                                        (yyval.node) = new treeNode("assign_stmt", v);
                                                    }
#line 2599 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 912 "a.y" /* yacc.c:1646  */
    {
                                    (yyvsp[0].node) = new treeNode(";");
                                    (yyvsp[-1].node) = new treeNode("INC");
                                    vector<treeNode*> v = {(yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                    (yyval.node) = new treeNode("incr_stmt", v);

                                    int offset = symbolTable.get( (yyvsp[-2].node)->lexValue );
                                    string arg2 = "-" + to_string(offset) + "(%rbp)";
                                    (yyval.node)->makeIns("addl", "$1", arg2);


                                }
#line 2616 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 925 "a.y" /* yacc.c:1646  */
    {
                                    (yyvsp[0].node) = new treeNode(";");
                                    (yyvsp[-1].node) = new treeNode("DEC");
                                    vector<treeNode*> v = {(yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                    (yyval.node) = new treeNode("decr_stmt", v);

                                    int offset = symbolTable.get( (yyvsp[-2].node)->lexValue );
                                    string arg2 = "-" + to_string(offset) + "(%rbp)";
                                    (yyval.node)->makeIns("subl", "$1", arg2);
                                }
#line 2631 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 936 "a.y" /* yacc.c:1646  */
    {
                            vector<treeNode*> u = {(yyvsp[-2].node), (yyvsp[0].node)};
                            (yyvsp[-1].node) = new treeNode("LT", u);
                            vector<treeNode*> v = {(yyvsp[-1].node)};
                            (yyval.node) = new treeNode("expr", v);

                            
                            (yyval.node)->append((yyvsp[0].node));
                            (yyval.node)->makeIns("pushq", "%rax");
                            (yyval.node)->append((yyvsp[-2].node));
                            (yyval.node)->makeIns("popq", "%rbx");
                            (yyval.node)->append(makeCompare("jl"));


                        }
#line 2651 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 951 "a.y" /* yacc.c:1646  */
    {   
                            vector<treeNode*> u = {(yyvsp[-2].node), (yyvsp[0].node)};
                            (yyvsp[-1].node) = new treeNode("GT", u);
                            vector<treeNode*> v = {(yyvsp[-1].node)};
                            (yyval.node) = new treeNode("expr", v);

                            (yyval.node)->append((yyvsp[0].node));
                            (yyval.node)->makeIns("pushq", "%rax");
                            (yyval.node)->append((yyvsp[-2].node));
                            (yyval.node)->makeIns("popq", "%rbx");
                            (yyval.node)->append(makeCompare("jg"));
                        }
#line 2668 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 963 "a.y" /* yacc.c:1646  */
    {
                            vector<treeNode*> u = {(yyvsp[-2].node), (yyvsp[0].node)};
                            (yyvsp[-1].node) = new treeNode("LEQ", u);
                            vector<treeNode*> v = {(yyvsp[-1].node)};
                            (yyval.node) = new treeNode("expr", v);

                            (yyval.node)->append((yyvsp[0].node));
                            (yyval.node)->makeIns("pushq", "%rax");
                            (yyval.node)->append((yyvsp[-2].node));
                            (yyval.node)->makeIns("popq", "%rbx");
                            (yyval.node)->append(makeCompare("jle"));
                        }
#line 2685 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 975 "a.y" /* yacc.c:1646  */
    {
                            vector<treeNode*> u = {(yyvsp[-2].node), (yyvsp[0].node)};
                            (yyvsp[-1].node) = new treeNode("GEQ", u);
                            vector<treeNode*> v = {(yyvsp[-1].node)};
                            (yyval.node) = new treeNode("expr", v);

                            (yyval.node)->append((yyvsp[0].node));
                            (yyval.node)->makeIns("pushq", "%rax");
                            (yyval.node)->append((yyvsp[-2].node));
                            (yyval.node)->makeIns("popq", "%rbx");
                            (yyval.node)->append(makeCompare("jge"));
                        }
#line 2702 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 987 "a.y" /* yacc.c:1646  */
    {
                            vector<treeNode*> u = {(yyvsp[-2].node), (yyvsp[0].node)};
                            (yyvsp[-1].node) = new treeNode("OR", u);
                            vector<treeNode*> v = {(yyvsp[-1].node)};
                            (yyval.node) = new treeNode("expr", v);

                            (yyval.node)->append((yyvsp[0].node));
                            (yyval.node)->makeIns("pushq", "%rax");
                            (yyval.node)->append((yyvsp[-2].node));
                            (yyval.node)->makeIns("popq", "%rbx");
                            (yyval.node)->makeIns("orl", "%ebx", "%eax");
                        }
#line 2719 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 999 "a.y" /* yacc.c:1646  */
    {
                                (yyvsp[-3].node) = new treeNode("SIZEOF"); (yyvsp[-2].node) = new treeNode("("); (yyvsp[0].node) = new treeNode(")");
                                vector<treeNode*> v = {(yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                (yyval.node) = new treeNode("expr", v);

                                (yyval.node)->makeIns("movl", "$4", "%eax");

                            }
#line 2732 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 1007 "a.y" /* yacc.c:1646  */
    {
                            vector<treeNode*> u = {(yyvsp[-2].node), (yyvsp[0].node)};
                            (yyvsp[-1].node) = new treeNode("EQEQ", u);
                            vector<treeNode*> v = {(yyvsp[-1].node)};
                            (yyval.node) = new treeNode("expr", v);

                            (yyval.node)->append((yyvsp[0].node));
                            (yyval.node)->makeIns("pushq", "%rax");
                            (yyval.node)->append((yyvsp[-2].node));
                            (yyval.node)->makeIns("popq", "%rbx");
                            (yyval.node)->append(makeCompare("je"));

                        }
#line 2750 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 1020 "a.y" /* yacc.c:1646  */
    {
                            vector<treeNode*> u = {(yyvsp[-2].node), (yyvsp[0].node)};
                            (yyvsp[-1].node) = new treeNode("NEQ", u);
                            vector<treeNode*> v = {(yyvsp[-1].node)};
                            (yyval.node) = new treeNode("expr", v);

                            (yyval.node)->append((yyvsp[0].node));
                            (yyval.node)->makeIns("pushq", "%rax");
                            (yyval.node)->append((yyvsp[-2].node));
                            (yyval.node)->makeIns("popq", "%rbx");
                            (yyval.node)->append(makeCompare("jne"));
                        }
#line 2767 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 1032 "a.y" /* yacc.c:1646  */
    {
                            vector<treeNode*> u = {(yyvsp[-2].node), (yyvsp[0].node)};
                            (yyvsp[-1].node) = new treeNode("NEWOP", u);
                            vector<treeNode*> v = {(yyvsp[-1].node)};
                            (yyval.node) = new treeNode("expr", v);

                            string less = newLabel();
                            string more = newLabel();
                            string end = newLabel();
                            
                            (yyval.node)->append((yyvsp[0].node));
                            (yyval.node)->makeIns("pushq", "%rax");
                            (yyval.node)->append((yyvsp[-2].node));
                            (yyval.node)->makeIns("popq", "%rbx");


                            (yyval.node)->makeIns ("cmpl", "%ebx", "%eax");
                            (yyval.node)-> makeIns("jl", less);

                            (yyval.node)-> makeIns ("cmpl", "%ebx", "%eax");
                            (yyval.node)-> makeIns("jg", more);

                            (yyval.node)->makeIns("movl", "$0", "%eax");
                            (yyval.node)-> makeIns("jmp", end);

                            (yyval.node)->putLabel(more);
                            (yyval.node)->makeIns("movl", "$1", "%eax");
                            (yyval.node)-> makeIns("jmp", end);

                            (yyval.node)->putLabel(less);
                            (yyval.node)->makeIns("movl", "$-1", "%eax");
                            (yyval.node)-> makeIns("jmp", end);

                            (yyval.node)->putLabel(end);

                            



                        }
#line 2812 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 1072 "a.y" /* yacc.c:1646  */
    {
                            vector<treeNode*> u = {(yyvsp[-2].node), (yyvsp[0].node)};
                            (yyvsp[-1].node) = new treeNode("AND", u);
                            vector<treeNode*> v = {(yyvsp[-1].node)};
                            (yyval.node) = new treeNode("expr", v);
                            
                            (yyval.node)->append((yyvsp[0].node));
                            (yyval.node)->makeIns("pushq", "%rax");
                            (yyval.node)->append((yyvsp[-2].node));
                            (yyval.node)->makeIns("popq", "%rbx");
                            (yyval.node)->makeIns("andl", "%ebx", "%eax");
                        }
#line 2829 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 1084 "a.y" /* yacc.c:1646  */
    {
                            vector<treeNode*> u = {(yyvsp[-2].node), (yyvsp[0].node)};
                            (yyvsp[-1].node) = new treeNode("ARROW", u);
                            vector<treeNode*> v = {(yyvsp[-1].node)};
                            (yyval.node) = new treeNode("expr", v);


                        }
#line 2842 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 1092 "a.y" /* yacc.c:1646  */
    {
                            vector<treeNode*> u = {(yyvsp[-2].node), (yyvsp[0].node)};
                            (yyvsp[-1].node) = new treeNode("PLUS", u);
                            vector<treeNode*> v = {(yyvsp[-1].node)};
                            (yyval.node) = new treeNode("expr", v);

                            (yyval.node)->append((yyvsp[0].node));
                            (yyval.node)->makeIns("pushq", "%rax");
                            (yyval.node)->append((yyvsp[-2].node));
                            (yyval.node)->makeIns("popq", "%rbx");
                            (yyval.node)->makeIns("addl", "%ebx", "%eax");

                            (yyval.node)->val = (yyvsp[-2].node)->val + (yyvsp[0].node)->val;

                        
                        }
#line 2863 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 1108 "a.y" /* yacc.c:1646  */
    {
                            vector<treeNode*> u = {(yyvsp[-2].node), (yyvsp[0].node)};
                            (yyvsp[-1].node) = new treeNode("MINUS", u);
                            vector<treeNode*> v = {(yyvsp[-1].node)};
                            (yyval.node) = new treeNode("expr", v);

                            (yyval.node)->append((yyvsp[0].node));
                            (yyval.node)->makeIns("pushq", "%rax");
                            (yyval.node)->append((yyvsp[-2].node));
                            (yyval.node)->makeIns("popq", "%rbx");
                            (yyval.node)->makeIns("subl", "%ebx", "%eax");

                            (yyval.node)->val = (yyvsp[-2].node)->val - (yyvsp[0].node)->val;
                        }
#line 2882 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 1122 "a.y" /* yacc.c:1646  */
    {
                            vector<treeNode*> u = {(yyvsp[-2].node), (yyvsp[0].node)};
                            (yyvsp[-1].node) = new treeNode("MULT", u);
                            vector<treeNode*> v = {(yyvsp[-1].node)};
                            (yyval.node) = new treeNode("expr", v);

                            (yyval.node)->append((yyvsp[0].node));
                            (yyval.node)->makeIns("pushq", "%rax");
                            (yyval.node)->append((yyvsp[-2].node));
                            (yyval.node)->makeIns("popq", "%rbx");
                            (yyval.node)->makeIns("imul", "%ebx", "%eax");
                            
                            (yyval.node)->val = (yyvsp[-2].node)->val * (yyvsp[0].node)->val;
                        }
#line 2901 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 1136 "a.y" /* yacc.c:1646  */
    {
                            vector<treeNode*> u = {(yyvsp[-2].node), (yyvsp[0].node)};
                            (yyvsp[-1].node) = new treeNode("DIV", u);
                            vector<treeNode*> v = {(yyvsp[-1].node)};
                            (yyval.node) = new treeNode("expr", v);

                            (yyval.node)->append((yyvsp[0].node));
                            (yyval.node)->makeIns("pushq", "%rax");
                            (yyval.node)->append((yyvsp[-2].node));
                            (yyval.node)->makeIns("popq", "%rbx");
                            (yyval.node)->makeIns("movl", "$0" ,"%edx");
                            (yyval.node)->makeIns("idivl", "%ebx");

                            if ((yyvsp[0].node)->val != 0)
                                (yyval.node)->val = (yyvsp[-2].node)->val / (yyvsp[0].node)->val;
                        }
#line 2922 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 1152 "a.y" /* yacc.c:1646  */
    {
                            vector<treeNode*> u = {(yyvsp[-2].node), (yyvsp[0].node)};
                            (yyvsp[-1].node) = new treeNode("MOD", u);
                            vector<treeNode*> v = {(yyvsp[-1].node)};
                            (yyval.node) = new treeNode("expr", v);

                            (yyval.node)->append((yyvsp[0].node));
                            (yyval.node)->makeIns("pushq", "%rax");
                            (yyval.node)->append((yyvsp[-2].node));
                            (yyval.node)->makeIns("popq", "%rbx");
                            (yyval.node)->makeIns("movl", "$0" ,"%edx");
                            (yyval.node)->makeIns("idivl", "%ebx");
                            (yyval.node)->makeIns("movl", "%edx" ,"%eax");

                            if ((yyvsp[0].node)->val != 0)
                                (yyval.node)->val = (yyvsp[-2].node)->val % (yyvsp[0].node)->val;

                        }
#line 2945 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 1170 "a.y" /* yacc.c:1646  */
    {
                    (yyvsp[-1].node) = new treeNode("NOT");
                    vector<treeNode*> v = {(yyvsp[-1].node), (yyvsp[0].node)};
                    (yyval.node) = new treeNode("expr", v);

                    (yyval.node)->append((yyvsp[0].node));
                    (yyval.node)->makeIns("movl", "%eax", "%ebx");
                    (yyval.node)->makeIns("xorl", "%eax", "%eax");
                    (yyval.node)->makeIns("test", "%ebx", "%ebx");
                    (yyval.node)->makeIns("sete", "%al");

                }
#line 2962 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 1182 "a.y" /* yacc.c:1646  */
    {
                        (yyvsp[-1].node) = new treeNode("MINUS");
                        vector<treeNode*> v = {(yyvsp[-1].node), (yyvsp[0].node)};
                        (yyval.node) = new treeNode("expr", v);

                        (yyval.node)->append((yyvsp[0].node));
                        (yyval.node)->makeIns("negl", "%eax");
                        (yyval.node)->val = - (yyvsp[0].node)->val;

                    }
#line 2977 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 1192 "a.y" /* yacc.c:1646  */
    {
                        (yyvsp[-1].node) = new treeNode("PLUS");
                        vector<treeNode*> v = {(yyvsp[-1].node), (yyvsp[0].node)};
                        (yyval.node) = new treeNode("expr", v);

                        (yyval.node)->append((yyvsp[0].node));
                        (yyval.node)->val = (yyvsp[0].node)->val;
                    }
#line 2990 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 1200 "a.y" /* yacc.c:1646  */
    {
                        (yyvsp[-1].node) = new treeNode("MULT");
                        vector<treeNode*> v = {(yyvsp[-1].node), (yyvsp[0].node)};
                        (yyval.node) = new treeNode("expr", v);
                        //Incorrect
                        (yyval.node)->append((yyvsp[0].node));
                    }
#line 3002 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 1207 "a.y" /* yacc.c:1646  */
    {   
                        (yyvsp[-1].node) = new treeNode("BITAND");
                        vector<treeNode*> v = {(yyvsp[-1].node), (yyvsp[0].node)};
                        (yyval.node) = new treeNode("expr", v);
                    }
#line 3012 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 1212 "a.y" /* yacc.c:1646  */
    {
                vector<treeNode*> v = {(yyvsp[0].node)};
                (yyval.node) = new treeNode("expr", v);
                
                (yyval.node)->append((yyvsp[0].node));
                (yyval.node)->val = (yyvsp[0].node)->val;
            }
#line 3024 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 1219 "a.y" /* yacc.c:1646  */
    {
                                    (yyvsp[-2].node) = new treeNode("("); (yyvsp[0].node) = new treeNode(")");
                                    vector<treeNode*> v = {(yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                    (yyval.node) = new treeNode("expr", v); 

                                    
                                
                                    (yyval.node)->append((yyvsp[-1].node));
                                    (yyval.node)->makeIns("call", (yyvsp[-3].node)->lexValue);

                                
                                }
#line 3041 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 1231 "a.y" /* yacc.c:1646  */
    {
                                    (yyvsp[-2].node) = new treeNode("["); (yyvsp[0].node) = new treeNode("]");
                                    vector<treeNode*> v = {(yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                    (yyval.node) = new treeNode("expr", v); 
                                
                                    
                                    int offset = symbolTable.get( (yyvsp[-3].node)->lexValue );
                                    string arg1 = "-" + to_string(offset) + "(%rbp,%rax,4)";
                                    (yyval.node)->append((yyvsp[-1].node));
                                    (yyval.node)->makeIns("movl", arg1, "%eax");    
                                
                                }
#line 3058 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 1244 "a.y" /* yacc.c:1646  */
    {
                        vector<treeNode*> v = {(yyvsp[0].node)};
                        (yyval.node) = new treeNode("Pexpr", v);

                        string num = "$" + (yyvsp[0].node)->lexValue;
                        (yyval.node)->makeIns("movl", num , "%eax");
                        (yyval.node)->val = stoi ((yyvsp[0].node)->lexValue);
                    
                    }
#line 3072 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 1253 "a.y" /* yacc.c:1646  */
    {
                    vector<treeNode*> v = {(yyvsp[0].node)};
                    (yyval.node) = new treeNode("Pexpr", v);
                }
#line 3081 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 1257 "a.y" /* yacc.c:1646  */
    {
                        vector<treeNode*> v = {(yyvsp[0].node)};
                        (yyval.node) = new treeNode("Pexpr", v);

                        int offset = symbolTable.get( (yyvsp[0].node)->lexValue );
                        string arg1 = "-" + to_string(offset) + "(%rbp)";
                        (yyval.node)->makeIns("movl", arg1, "%eax");

                    }
#line 3095 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 1266 "a.y" /* yacc.c:1646  */
    {
                        (yyvsp[-2].node) = new treeNode("("); (yyvsp[0].node) = new treeNode(")");
                        vector<treeNode*> v = {(yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                        (yyval.node) = new treeNode("Pexpr", v);

                        (yyval.node)->append((yyvsp[-1].node));
                    }
#line 3107 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 1275 "a.y" /* yacc.c:1646  */
    {
                                (yyvsp[0].node) = new treeNode("INTEGER_NUMBER");
                                vector<treeNode*> v = {(yyvsp[0].node)};
                                (yyval.node) = new treeNode("intergerLit", v);
                                (yyval.node)->lexValue = mytext;

                            }
#line 3119 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 1283 "a.y" /* yacc.c:1646  */
    {
                            (yyvsp[0].node) = new treeNode("FLOAT_NUMBER");
                            vector<treeNode*> v = {(yyvsp[0].node)};
                            (yyval.node) = new treeNode("floatLit", v);
                        }
#line 3129 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 1289 "a.y" /* yacc.c:1646  */
    {
                            (yyvsp[0].node) = new treeNode("IDENTIFIER");
                            vector<treeNode*> v = {(yyvsp[0].node)};
                            (yyval.node) = new treeNode("identifier", v);
                            (yyval.node)->lexValue = mytext;
                        }
#line 3140 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 1295 "a.y" /* yacc.c:1646  */
    {
                        (yyvsp[0].node) = new treeNode("IDENTIFIER");
                        vector<treeNode*> v = {(yyvsp[0].node)};
                        (yyval.node) = new treeNode("identifier", v);
                        (yyval.node)->lexValue = "printf";
                    }
#line 3151 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 1302 "a.y" /* yacc.c:1646  */
    {
                                (yyvsp[-1].node) = new treeNode(",");
                                vector<treeNode*> v = {(yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                (yyval.node) = new treeNode("arg_list", v);

                                (yyval.node)->append((yyvsp[-2].node));
                                (yyval.node)->append((yyvsp[0].node));
                                (yyval.node)->makeIns("subq", "$4", "%rsp");
                                (yyval.node)->makeIns("movl", "%eax", "0(%rsp)");
                                (yyval.node)->val = (yyvsp[-2].node)->val + 1;
                            }
#line 3167 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 1313 "a.y" /* yacc.c:1646  */
    {
                    vector<treeNode*> v = {(yyvsp[0].node)};
                    (yyval.node) = new treeNode("arg_list", v);
                    (yyval.node)->val = 1;

                    (yyval.node)->append((yyvsp[0].node));
                    (yyval.node)->makeIns("subq", "$4", "%rsp");
                    (yyval.node)->makeIns("movl", "%eax", "0(%rsp)");

                }
#line 3182 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 1324 "a.y" /* yacc.c:1646  */
    {
                    vector<treeNode*> v = {(yyvsp[0].node)};
                    (yyval.node) = new treeNode("args", v);
                
                    (yyval.node)->makeIns("pushq", "$0");
                    (yyval.node)->makeIns("pushq", "$0");
                    (yyval.node)->append((yyvsp[0].node));
                    (yyval.node)->val = (yyvsp[0].node)->val;                

                    string arg1 = "$" + to_string(4*((yyval.node)->val) + 16);
                    (yyval.node)->makeIns("addq", arg1, "%rsp");
                }
#line 3199 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 1336 "a.y" /* yacc.c:1646  */
    {
            auto x = new treeNode("epsilon");
            vector<treeNode*> v = {x};
            (yyval.node) = new treeNode("args", v);
        }
#line 3209 "y.tab.cpp" /* yacc.c:1646  */
    break;


#line 3213 "y.tab.cpp" /* yacc.c:1646  */
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
#line 1342 "a.y" /* yacc.c:1906  */




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
void yyerror(char* s) {
    printAST(ast);
    printf("***parsing terminated*** [syntax error]::%s \n", s);
    exit(0);
}

int main() {
    yyparse();
    // printf("***parsing successful***\n");
    // printf("%d\n", programLongestPath);
    // printf("%d\n", ifLongestPath);
    // printf("%d\n", whileLongestPath);
    // printf("%d\n", switchLongestPath);
    // printf("%d\n", mainLongestPath);
    // printAST(ast, "", true);
    string prefix = "";
    prefix += "\t.text\n";
    prefix += "\t.section   .rodata\n";
    prefix += ".LC0:\n";
    prefix += "\t.string \"%d\" \n";
    prefix += ".LC1:\n";
    prefix += "\t.string \"%d\\n\" \n";
    prefix += "\t.text\n";
    prefix += "\t.globl  main\n";
    prefix += "\t.type	main, @function\n";
    

    


    cout << prefix << ast->code << endl;
    return 0;
}
