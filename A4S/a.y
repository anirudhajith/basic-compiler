%token IDENTIFIER INTEGER_NUMBER FLOAT_NUMBER PLUS MINUS MULT DIV IF ELSE FOR WHILE DO INT FLOAT CHAR EQ EQEQ GEQ LEQ GT LT
%token NEWOP NEQ BITAND BITOR BITNOT BITXOR AND OR NOT MOD EXTERN LONG SHORT DOUBLE PRINTF PERCENTD
%token VOID SWITCH CASE STRUCT BREAK CONTINUE RETURN STRLITERAL CHARLITERAL INC DEC ARROW SIZEOF DEFAULT
%{
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
%}

%union {
    class treeNode* node;
}

%type <node> program
%type <node> decl_list
%type <node> decl
%type <node> struct_decl
%type <node> var_decl
%type <node> type_spec
%type <node> extern_spec
%type <node> func_decl
%type <node> params
%type <node> param_list
%type <node> param
%type <node> stmt_list
%type <node> stmt
// %type <node> expr_stmt
%type <node> while_stmt
%type <node> dowhile_stmt
%type <node> print_stmt
%type <node> format_specifier
%type <node> compound_stmt
%type <node> local_decls
%type <node> local_decl
%type <node> if_stmt
%type <node> return_stmt
%type <node> break_stmt
%type <node> continue_stmt
%type <node> switch_stmt
%type <node> compound_case
%type <node> single_case
%type <node> default_case
%type <node> assign_stmt
%type <node> incr_stmt
%type <node> decr_stmt
%type <node> expr
%type <node> Pexpr
%type <node> integerLit
%type <node> floatLit
%type <node> identifier
%type <node> arg_list
%type <node> args

%type <node> IDENTIFIER
%type <node> INTEGER_NUMBER
%type <node> FLOAT_NUMBER
%type <node> PRINTF
%type <node> PERCENTD
%type <node> PLUS
%type <node> MINUS
%type <node> MULT
%type <node> DIV
%type <node> IF
%type <node> ELSE
%type <node> FOR
%type <node> WHILE
%type <node> DO
%type <node> INT
%type <node> FLOAT
%type <node> CHAR
%type <node> EQ
%type <node> EQEQ
%type <node> GEQ
%type <node> LEQ
%type <node> GT
%type <node> LT
%type <node> NEWOP
%type <node> NEQ
%type <node> BITAND
%type <node> BITOR
%type <node> BITNOT
%type <node> BITXOR
%type <node> AND
%type <node> OR
%type <node> NOT
%type <node> MOD
%type <node> EXTERN
%type <node> LONG
%type <node> SHORT
%type <node> DOUBLE
%type <node> VOID
%type <node> SWITCH
%type <node> CASE
%type <node> STRUCT
%type <node> BREAK
%type <node> CONTINUE
%type <node> RETURN
%type <node> STRLITERAL
%type <node> CHARLITERAL
%type <node> INC
%type <node> DEC
%type <node> ARROW
%type <node> SIZEOF
%type <node> DEFAULT
%type <node> '['
%type <node> ']'
%type <node> '('
%type <node> ')'
%type <node> ';'
%type <node> ','
%type <node> ':'
%type <node> '{'
%type <node> '}'
%type <node> '.'
%%

program: decl_list  {
                        vector<treeNode*> v = {$1};
                        $$ = new treeNode("program", v); 
                        set_programLongestPath($$->maxSubtreeLength);
                        ast = $$;
                    };

decl_list: decl_list decl   { 
                                vector<treeNode*> v = {$1, $2};
                                $$ = new treeNode("decl_list", v); 
                            }

         | decl {
                    vector<treeNode*> v = {$1};
                    $$ = new treeNode("decl_list", v); 
                };
         
decl: var_decl  {   
                    vector<treeNode*> v = {$1};
                    $$ = new treeNode("decl", v); 
                }

    | func_decl {
                    vector<treeNode*> v = {$1};
                    $$ = new treeNode("decl", v); 
                }

    | struct_decl   {
                        vector<treeNode*> v = {$1};
                        $$ = new treeNode("decl", v); 
                    };

struct_decl: STRUCT identifier '{' local_decls '}' ';'  {
                                                            $1 = new treeNode("STRUCT"); $3 = new treeNode("{"); 
                                                            $5 = new treeNode("}"); $6 = new treeNode(";");
                                                            vector<treeNode*> v = {$1, $2, $3, $4, $5, $6};
                                                            $$ = new treeNode("struct_decl", v); 
                                                        };

var_decl: type_spec identifier ';'  {
                                        $3 = new treeNode(";");
                                        vector<treeNode*> v = {$1, $2, $3};
                                        $$ = new treeNode("var_decl", v); 
                                    }

        | type_spec identifier ',' var_decl {
                                                $3 = new treeNode(",");
                                                vector<treeNode*> v = {$1, $2, $3, $4};
                                                $$ = new treeNode("var_decl", v); 
                                            }   

        | type_spec identifier '[' integerLit ']' ';'   {
                                                            $3 = new treeNode("["); $5 = new treeNode("]"); $6 = new treeNode(";");
                                                            vector<treeNode*> v = {$1, $2, $3, $4, $5, $6};
                                                            $$ = new treeNode("var_decl", v); 
                                                        }
    
        | type_spec identifier '[' integerLit ']' ',' var_decl  {
                                                                    $3 = new treeNode("["); $5 = new treeNode("]"); $6 = new treeNode(",");
                                                                    vector<treeNode*> v = {$1, $2, $3, $4, $5, $6, $7};
                                                                    $$ = new treeNode("var_decl", v); 
                                                                };

type_spec: extern_spec VOID {
                                $2 = new treeNode("VOID");
                                vector<treeNode*> v = {$1, $2}; 
                                $$ = new treeNode("type_spec", v); 
                            }
         | extern_spec INT  {
                                $2 = new treeNode("INT");
                                vector<treeNode*> v = {$1, $2}; 
                                $$ = new treeNode("type_spec", v);
                                $$->width = 4;
                            }

         | extern_spec FLOAT    {
                                    $2 = new treeNode("FLOAT");
                                    vector<treeNode*> v = {$1, $2}; 
                                    $$ = new treeNode("type_spec", v);
                                    $$->width = 8;
                                }

         | extern_spec VOID MULT {
                                    $2 = new treeNode("VOID"); $3 = new treeNode("MULT");
                                    vector<treeNode*> v = {$1, $2, $3}; 
                                    $$ = new treeNode("type_spec", v);
                                }

         | extern_spec INT MULT {
                                    $2 = new treeNode("INT"); $3 = new treeNode("MULT");
                                    vector<treeNode*> v = {$1, $2, $3}; 
                                    $$ = new treeNode("type_spec", v);
                                }

         | extern_spec FLOAT MULT {
                                    $2 = new treeNode("FLOAT"); $3 = new treeNode("MULT");
                                    vector<treeNode*> v = {$1, $2, $3}; 
                                    $$ = new treeNode("type_spec", v);
                                  }

         | STRUCT identifier    {
                                    $1 = new treeNode("STRUCT");
                                    vector<treeNode*> v = {$1, $2};
                                    $$ = new treeNode("type_spec", v); 
                                }
         | STRUCT identifier MULT   {
                                        $1 = new treeNode("STRUCT"); $3 = new treeNode("MULT");
                                        vector<treeNode*> v = {$1, $2, $3};
                                        $$ = new treeNode("type_spec", v);
                                    };

extern_spec: EXTERN {
                        $1 = new treeNode("EXTERN");
                        vector<treeNode*> v = {$1};
                        $$ = new treeNode("extern_spec", v);
                    }
           |    {
                    auto x = new treeNode("epsilon");
                    vector<treeNode*> v = {x};
                    $$ = new treeNode("extern_spec", v);
                };

func_decl: type_spec identifier '(' params ')' compound_stmt    {
                                                                    $3 = new treeNode("("); $5 = new treeNode(")");
                                                                    vector<treeNode*> v = {$1, $2, $3, $4, $5, $6};
                                                                    $$ = new treeNode("func_decl", v);      
                                                                    if($2->lexValue == "main") {
                                                                        set_mainLongestPath($$->maxSubtreeLength);
                                                                    }
                                                                };

params: param_list  {
                        vector<treeNode*> v = {$1};
                        $$ = new treeNode("params", v);
                    } 
      | {
          auto x = new treeNode("epsilon");
          vector<treeNode*> v = {x};
          $$ = new treeNode("params", v);
        };

param_list: param_list ',' param    {
                                        $2 = new treeNode(",");
                                        vector<treeNode*> v = {$1, $2, $3};
                                        $$ = new treeNode("param_list", v);
                                    }
          | param   {
                        vector<treeNode*> v = {$1};
                        $$ = new treeNode("param_list", v);
                    };

param: type_spec identifier {
                                vector<treeNode*> v = {$1, $2};
                                $$ = new treeNode("param", v);
                            }
     | type_spec identifier '[' ']' {
                                        $3 = new treeNode("["); $4 = new treeNode("]");
                                        vector<treeNode*> v = {$1, $2, $3, $4};
                                        $$ = new treeNode("param", v);
                                    };

stmt_list: stmt_list stmt   {
                                vector<treeNode*> v = {$1, $2};
                                $$ = new treeNode("stmt_list", v);
                            }
         | stmt {
                    vector<treeNode*> v = {$1};
                    $$ = new treeNode("stmt_list", v);
                };

stmt: assign_stmt   {
                        vector<treeNode*> v = {$1};
                        $$ = new treeNode("stmt", v);
                    }
    | compound_stmt {
                        vector<treeNode*> v = {$1};
                        $$ = new treeNode("stmt", v);
                    }
    | if_stmt   {
                    vector<treeNode*> v = {$1};
                    $$ = new treeNode("stmt", v);
                }
    | while_stmt    {
                        vector<treeNode*> v = {$1};
                        $$ = new treeNode("stmt", v);
                    }
    | switch_stmt   {
                        vector<treeNode*> v = {$1};
                        $$ = new treeNode("stmt", v);
                    }
    | return_stmt   {
                        vector<treeNode*> v = {$1};
                        $$ = new treeNode("stmt", v);
                    }
    | break_stmt {
                    vector<treeNode*> v = {$1};
                    $$ = new treeNode("stmt", v);
                 }
    | continue_stmt {
                        vector<treeNode*> v = {$1};
                        $$ = new treeNode("stmt", v);
                    }
    | dowhile_stmt  {    
                        vector<treeNode*> v = {$1};
                        $$ = new treeNode("stmt", v);
                    }
    | print_stmt    {
                        vector<treeNode*> v = {$1};
                        $$ = new treeNode("stmt", v);
                    }
    | incr_stmt {
                    vector<treeNode*> v = {$1};
                    $$ = new treeNode("stmt", v);
                }  
    | decr_stmt {   
                    vector<treeNode*> v = {$1};
                    $$ = new treeNode("stmt", v);
                }; 

while_stmt: WHILE '(' expr ')' stmt { 
                                        $1 = new treeNode("WHILE");
                                        $2 = new treeNode("("); $4 = new treeNode(")");
                                        vector<treeNode*> v = {$1, $2, $3, $4, $5};
                                        $$ = new treeNode("while_stmt", v); 
                                        set_whileLongestPath($$->maxSubtreeLength); 
                                    };

dowhile_stmt: DO stmt WHILE '(' expr ')' ';' { 
                                                $1 = new treeNode("DO"); $3 = new treeNode("WHILE");
                                                $4 = new treeNode("("); $6 = new treeNode(")"); $7 = new treeNode(";");
                                                vector<treeNode*> v = {$1, $2, $3, $4, $5, $6, $7};
                                                $$ = new treeNode("dowhile_stmt", v);  
                                            };

print_stmt: PRINTF '(' format_specifier ',' identifier ')' ';'  {
                                                                    $1 = new treeNode("PRINTF"); $2 = new treeNode("("); $4 = new treeNode(",");
                                                                    $6 = new treeNode(")"); $7 = new treeNode(";");
                                                                    vector<treeNode*> v = {$1, $2, $3, $4, $5, $6, $7};
                                                                    $$ = new treeNode("print_stmt", v); 
                                                                };

format_specifier: PERCENTD  {
                                $1 = new treeNode("PERCENTD");
                                vector<treeNode*> v = {$1};
                                $$ = new treeNode("format_specifier", v);
                            };

compound_stmt: '{' local_decls stmt_list '}'    {
                                                    $1 = new treeNode("{"); $4 = new treeNode("}");
                                                    vector<treeNode*> v = {$1, $2, $3, $4};
                                                    $$ = new treeNode("compound_stmt", v);
                                                };

local_decls: local_decls local_decl {
                                        vector<treeNode*> v = {$1, $2};
                                        $$ = new treeNode("local_decls", v);
                                    } 
           |    {
                    auto x = new treeNode("epsilon");
                    vector<treeNode*> v = {x};
                    $$ = new treeNode("local_decls", v);
                };

local_decl: type_spec identifier ';'    {
                                            $3 = new treeNode(";");
                                            vector<treeNode*> v = {$1, $2, $3};
                                            $$ = new treeNode("local_decl", v);
                                        }
          | type_spec identifier '[' expr ']' ';'   {
                                                        $3 = new treeNode("["); $5 = new treeNode("]"); $6 = new treeNode(";");
                                                        vector<treeNode*> v = {$1, $2, $3, $4, $5, $6};
                                                        $$ = new treeNode("local_decl", v); 
                                                    };

if_stmt: IF '(' expr ')' stmt   {   
                                    $1 = new treeNode("IF");
                                    $2 = new treeNode("("); $4 = new treeNode(")");
                                    vector<treeNode*> v = {$1, $2, $3, $4, $5};
                                    $$ = new treeNode("if_stmt", v);
                                    set_ifLongestPath($$->maxSubtreeLength); 
                                }
       | IF '(' expr ')' stmt ELSE stmt { 
                                            $1 = new treeNode("IF");
                                            $2 = new treeNode("("); $4 = new treeNode(")"); $6 = new treeNode("ELSE");
                                            vector<treeNode*> v = {$1, $2, $3, $4, $5, $6, $7};
                                            $$ = new treeNode("if_stmt", v);
                                            set_ifLongestPath($$->maxSubtreeLength); 
                                        };

return_stmt: RETURN ';' { 
                            $1 = new treeNode("RETURN"); $2 = new treeNode(";");
                            vector<treeNode*> v = {$1, $2};
                            $$ = new treeNode("return_stmt", v);
                        }
           | RETURN expr ';'    {
                                    $1 = new treeNode("RETURN"); $3 = new treeNode(";");
                                    vector<treeNode*> v = {$1, $2, $3};
                                    $$ = new treeNode("return_stmt", v);
                                };

break_stmt: BREAK ';'   {
                            $1 = new treeNode("BREAK"); $2 = new treeNode(";");
                            vector<treeNode*> v = {$1, $2};
                            $$ = new treeNode("break_stmt", v);
                        };

continue_stmt: CONTINUE ';' {
                                $1 = new treeNode("CONTINUE"); $2 = new treeNode(";");
                                vector<treeNode*> v = {$1, $2};
                                $$ = new treeNode("continue_stmt", v);
                            };

switch_stmt: SWITCH '(' expr ')' '{' compound_case default_case '}' {
                                                                        $1 = new treeNode("SWITCH");
                                                                        $2 = new treeNode("("); $4 = new treeNode(")");
                                                                        $5 = new treeNode("{"); $8 = new treeNode("}");
                                                                        vector<treeNode*> v = {$1, $2, $3, $4, $5, $6, $7, $8};
                                                                        $$ = new treeNode("switch_stmt", v);
                                                                        set_switchLongestPath($$->maxSubtreeLength);    
                                                                    };

compound_case: single_case compound_case    {
                                                vector<treeNode*> v = {$1, $2};
                                                $$ = new treeNode("compound_case", v); 
                                            }
             | single_case  {
                                vector<treeNode*> v = {$1};
                                $$ = new treeNode("compound_case", v);
                            };

single_case: CASE integerLit ':' stmt_list  {
                                                $1 = new treeNode("CASE"); $3 = new treeNode(":");
                                                vector<treeNode*> v = {$1, $2, $3, $4};
                                                $$ = new treeNode("single_case", v);
                                            };

default_case: DEFAULT ':' stmt_list {
                                        $1 = new treeNode("DEFAULT"); $2 = new treeNode(":");
                                        vector<treeNode*> v = {$1, $2, $3};
                                        $$ = new treeNode("default_case", v);
                                    };

assign_stmt: identifier EQ expr ';' {
                                        vector<treeNode*> u = {$1, $3};
                                        $2 = new treeNode("EQ", u);
                                        $4 = new treeNode(";");
                                        vector<treeNode*> v = {$2, $4};
                                        $$ = new treeNode("assign_stmt", v);
                                        
                                    }
           | identifier '[' expr ']' EQ expr ';'    {   // check this one
                                                        $2 = new treeNode("["); $4 = new treeNode("]"); $7 = new treeNode(";");
                                                        vector<treeNode*> u = {$1, $2, $3, $4, $6};
                                                        $5 = new treeNode("EQ", u);
                                                        vector<treeNode*> v = {$5, $7};
                                                        $$ = new treeNode("assign_stmt", v);    
                                                    }
           | identifier ARROW identifier EQ expr ';'    {
                                                            $6 = new treeNode(";");
                                                            $2 = new treeNode("ARROW");
                                                            vector<treeNode*> u = {$1, $2, $3, $5};
                                                            $4 = new treeNode("EQ", u);
                                                            vector<treeNode*> v = {$4, $6};
                                                            $$ = new treeNode("assign_stmt", v);
                                                        }
           | identifier '.' identifier EQ expr ';'  {
                                                        $6 = new treeNode(";");
                                                        $2 = new treeNode(".");
                                                        vector<treeNode*> u = {$1, $2, $3, $5};
                                                        $4 = new treeNode("EQ", u);
                                                        vector<treeNode*> v = {$4, $6};
                                                        $$ = new treeNode("assign_stmt", v);
                                                    };

incr_stmt: identifier INC ';'   {
                                    $3 = new treeNode(";");
                                    $2 = new treeNode("INC");
                                    vector<treeNode*> v = {$1, $2, $3};
                                    $$ = new treeNode("incr_stmt", v);
                                };

decr_stmt: identifier DEC ';'   {
                                    $3 = new treeNode(";");
                                    $2 = new treeNode("DEC");
                                    vector<treeNode*> v = {$1, $2, $3};
                                    $$ = new treeNode("decr_stmt", v);
                                };

expr: Pexpr LT Pexpr    {
                            vector<treeNode*> u = {$1, $3};
                            $2 = new treeNode("LT", u);
                            vector<treeNode*> v = {$2};
                            $$ = new treeNode("expr", v);
                        }
    | Pexpr GT Pexpr    {   
                            vector<treeNode*> u = {$1, $3};
                            $2 = new treeNode("GT", u);
                            vector<treeNode*> v = {$2};
                            $$ = new treeNode("expr", v);
                        }
    | Pexpr LEQ Pexpr   {
                            vector<treeNode*> u = {$1, $3};
                            $2 = new treeNode("LEQ", u);
                            vector<treeNode*> v = {$2};
                            $$ = new treeNode("expr", v);
                        }
    | Pexpr GEQ Pexpr   {
                            vector<treeNode*> u = {$1, $3};
                            $2 = new treeNode("GEQ", u);
                            vector<treeNode*> v = {$2};
                            $$ = new treeNode("expr", v);
                        }
    | Pexpr OR Pexpr    {
                            vector<treeNode*> u = {$1, $3};
                            $2 = new treeNode("OR", u);
                            vector<treeNode*> v = {$2};
                            $$ = new treeNode("expr", v);
                        }
    | SIZEOF '(' Pexpr ')'  {
                                $1 = new treeNode("SIZEOF"); $2 = new treeNode("("); $4 = new treeNode(")");
                                vector<treeNode*> v = {$1, $2, $3, $4};
                                $$ = new treeNode("expr", v);
                            }
    | Pexpr EQEQ Pexpr  {
                            vector<treeNode*> u = {$1, $3};
                            $2 = new treeNode("EQEQ", u);
                            vector<treeNode*> v = {$2};
                            $$ = new treeNode("expr", v);
                        }
    | Pexpr NEQ Pexpr   {
                            vector<treeNode*> u = {$1, $3};
                            $2 = new treeNode("NEQ", u);
                            vector<treeNode*> v = {$2};
                            $$ = new treeNode("expr", v);
                        }
    | Pexpr NEWOP Pexpr {
                            vector<treeNode*> u = {$1, $3};
                            $2 = new treeNode("NEWOP", u);
                            vector<treeNode*> v = {$2};
                            $$ = new treeNode("expr", v);
                        }
    | Pexpr AND Pexpr   {
                            vector<treeNode*> u = {$1, $3};
                            $2 = new treeNode("AND", u);
                            vector<treeNode*> v = {$2};
                            $$ = new treeNode("expr", v);
                        }
    | Pexpr ARROW Pexpr {
                            vector<treeNode*> u = {$1, $3};
                            $2 = new treeNode("ARROW", u);
                            vector<treeNode*> v = {$2};
                            $$ = new treeNode("expr", v);
                        }
    | Pexpr PLUS Pexpr  {
                            vector<treeNode*> u = {$1, $3};
                            $2 = new treeNode("PLUS", u);
                            vector<treeNode*> v = {$2};
                            $$ = new treeNode("expr", v);
                        }
    | Pexpr MINUS Pexpr {
                            vector<treeNode*> u = {$1, $3};
                            $2 = new treeNode("MINUS", u);
                            vector<treeNode*> v = {$2};
                            $$ = new treeNode("expr", v);
                        }
    | Pexpr MULT Pexpr  {
                            vector<treeNode*> u = {$1, $3};
                            $2 = new treeNode("MULT", u);
                            vector<treeNode*> v = {$2};
                            $$ = new treeNode("expr", v);
                        }
    | Pexpr DIV Pexpr   {
                            vector<treeNode*> u = {$1, $3};
                            $2 = new treeNode("DIV", u);
                            vector<treeNode*> v = {$2};
                            $$ = new treeNode("expr", v);
                        }
    | Pexpr MOD Pexpr   {
                            vector<treeNode*> u = {$1, $3};
                            $2 = new treeNode("MOD", u);
                            vector<treeNode*> v = {$2};
                            $$ = new treeNode("expr", v);
                        }
    | NOT Pexpr {
                    $1 = new treeNode("NOT");
                    vector<treeNode*> v = {$1, $2};
                    $$ = new treeNode("expr", v);
                }
    | MINUS Pexpr   {
                        $1 = new treeNode("MINUS");
                        vector<treeNode*> v = {$1, $2};
                        $$ = new treeNode("expr", v);
                    }
    | PLUS Pexpr    {
                        $1 = new treeNode("PLUS");
                        vector<treeNode*> v = {$1, $2};
                        $$ = new treeNode("expr", v);
                    }
    | MULT Pexpr    {
                        $1 = new treeNode("MULT");
                        vector<treeNode*> v = {$1, $2};
                        $$ = new treeNode("expr", v);
                    }
    | BITAND Pexpr  {   
                        $1 = new treeNode("BITAND");
                        vector<treeNode*> v = {$1, $2};
                        $$ = new treeNode("expr", v);
                    }
    | Pexpr {
                vector<treeNode*> v = {$1};
                $$ = new treeNode("expr", v);
            }
    | identifier '(' args ')'   {
                                    $2 = new treeNode("("); $4 = new treeNode(")");
                                    vector<treeNode*> v = {$1, $2, $3, $4};
                                    $$ = new treeNode("expr", v); 
                                }
    | identifier '[' expr ']'   {
                                    $2 = new treeNode("["); $4 = new treeNode("]");
                                    vector<treeNode*> v = {$1, $2, $3, $4};
                                    $$ = new treeNode("expr", v); 
                                };

Pexpr: integerLit   {
                        vector<treeNode*> v = {$1};
                        $$ = new treeNode("Pexpr", v);
                    }
     | floatLit {
                    vector<treeNode*> v = {$1};
                    $$ = new treeNode("Pexpr", v);
                }
     | identifier   {
                        vector<treeNode*> v = {$1};
                        $$ = new treeNode("Pexpr", v);
                    }
     | '(' expr ')' {
                        $1 = new treeNode("("); $3 = new treeNode(")");
                        vector<treeNode*> v = {$1, $2, $3};
                        $$ = new treeNode("Pexpr", v);
                    };

integerLit: INTEGER_NUMBER  {
                                $1 = new treeNode("INTEGER_NUMBER");
                                vector<treeNode*> v = {$1};
                                $$ = new treeNode("intergerLit", v);
                                $$->lexValue = mytext;
                                $$->width = 4;
                            };

floatLit: FLOAT_NUMBER  {
                            $1 = new treeNode("FLOAT_NUMBER");
                            vector<treeNode*> v = {$1};
                            $$ = new treeNode("floatLit", v);
                            $$->lexValue = mytext;
                            $$->width = 8;
                        };

identifier: IDENTIFIER  {
                            $1 = new treeNode("IDENTIFIER");
                            vector<treeNode*> v = {$1};
                            $$ = new treeNode("identifier", v);
                            $$->lexValue = mytext;
                        } 
          | PRINTF  {
                        $1 = new treeNode("IDENTIFIER");
                        vector<treeNode*> v = {$1};
                        $$ = new treeNode("identifier", v);
                        $$->lexValue = "printf";
                    };

arg_list: arg_list ',' expr {
                                $2 = new treeNode(",");
                                vector<treeNode*> v = {$1, $2, $3};
                                $$ = new treeNode("arg_list", v);
                            }
        | expr  {
                    vector<treeNode*> v = {$1};
                    $$ = new treeNode("arg_list", v);
                };

args: arg_list  {
                    vector<treeNode*> v = {$1};
                    $$ = new treeNode("args", v);
                }
    |   {
            auto x = new treeNode("epsilon");
            vector<treeNode*> v = {x};
            $$ = new treeNode("args", v);
        };

%%

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
