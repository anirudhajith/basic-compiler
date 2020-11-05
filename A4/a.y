%token IDENTIFIER INTEGER_NUMBER FLOAT_NUMBER PLUS MINUS MULT DIV IF ELSE FOR WHILE DO INT FLOAT CHAR EQ EQEQ GEQ LEQ GT LT
%token NEWOP NEQ BITAND BITOR BITNOT BITXOR AND OR NOT MOD EXTERN LONG SHORT DOUBLE PRINTF SCANF PERCENTD
%token VOID SWITCH CASE STRUCT BREAK CONTINUE RETURN STRLITERAL CHARLITERAL INC DEC ARROW SIZEOF DEFAULT
%left LT GT
%left LEQ GEQ
%left OR 
%left EQEQ NEQ NEWOP
%left AND ARROW
%left PLUS MINUS
%left MULT DIV MOD

%{
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
%type <node> params1
%type <node> param_list
%type <node> param
%type <node> stmt_list
%type <node> stmt
// %type <node> expr_stmt
%type <node> while_stmt
%type <node> dowhile_stmt
%type <node> print_stmt
%type <node> scan_stmt
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
%type <node> SCANF
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
                        $$ -> append($1);
                        ast = $$;


                    };

decl_list: decl_list decl   { 
                                vector<treeNode*> v = {$1, $2};
                                $$ = new treeNode("decl_list", v);

                                $$->append($1);
                                $$->append($2); 
                            }

         | decl {
                    vector<treeNode*> v = {$1};
                    $$ = new treeNode("decl_list", v); 
                
                    $$->append($1);
                };
         
decl: var_decl  {   
                    vector<treeNode*> v = {$1};
                    $$ = new treeNode("decl", v); 
                }

    | func_decl {
                    vector<treeNode*> v = {$1};
                    $$ = new treeNode("decl", v); 

                    $$->append($1);
                    // symbolTable.decrementScope();
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
                                $$ -> lexValue = "int";
                                
                            }

         | extern_spec FLOAT    {
                                    $2 = new treeNode("FLOAT");
                                    vector<treeNode*> v = {$1, $2}; 
                                    $$ = new treeNode("type_spec", v);
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

func_decl: type_spec identifier '(' params1 ')' compound_stmt    
{
    $3 = new treeNode("("); $5 = new treeNode(")");
    vector<treeNode*> v = {$1, $2, $3, $4, $5, $6};
    $$ = new treeNode("func_decl", v);      
    if($2->lexValue == "main") {
        set_mainLongestPath($$->maxSubtreeLength);
    }
    $$->putLabel($2->lexValue);
    $$->makeIns("pushq", "%rbp");
    //$$->append($4);

    $$->makeIns("movq", "%rsp", "%rbp");
    string offset = "$" + to_string(8*intDeclarations + 16);
    $$->makeIns("subq", offset, "%rsp");
    $$->append($6);
    $$->makeIns("leave");
    $$->makeIns("ret");

    symbolTable.decrementScope();
};

params1: {symbolTable.incrementScope();} params {
            
            $$ = $2;
            
    }

params: param_list  {
                        vector<treeNode*> v = {$1};
                        $$ = new treeNode("params", v);
                        $$->val = $1->val;
                        $$->append($1);
                    } 
      | {
          auto x = new treeNode("epsilon");
          vector<treeNode*> v = {x};
          $$ = new treeNode("params", v);
          $$->val = 0;
        
        };

param_list: param_list ',' param    {
                                        $2 = new treeNode(",");
                                        vector<treeNode*> v = {$1, $2, $3};
                                        $$ = new treeNode("param_list", v);
                                        $$->val = $1->val + 1;
                                        $$->append($1);
                                        $$->append($3);
                                    }
          | param   {
                        vector<treeNode*> v = {$1};
                        $$ = new treeNode("param_list", v);
                        $$->val = 1;
                        $$->append($1);
                    };

param: type_spec identifier {
                                vector<treeNode*> v = {$1, $2};
                                $$ = new treeNode("param", v);
                            
                                if ($1 -> lexValue == "int") {
                                    intDeclarations++;
                                    int offset = symbolTable.put($2->lexValue);
                                    // cout << "Identifier::" << $2->lexValue << endl;
                                    //$$->makeIns("popq", "%rax");
                                    //string arg2 = "-" + to_string(offset) + "(%rsp)";
                                    //$$->makeIns("movl", "%eax", arg2);

                                }
                            }
     | type_spec identifier '[' ']' {
                                        $3 = new treeNode("["); $4 = new treeNode("]");
                                        vector<treeNode*> v = {$1, $2, $3, $4};
                                        $$ = new treeNode("param", v);

                                        if ($1 -> lexValue == "int") {
                                            intDeclarations++;
                                            symbolTable.put($2->lexValue);
                                            // cout << "Identifier::" << $2->lexValue << endl;
                                        }
                                    
                                    }
    | type_spec 

;
stmt_list: stmt_list stmt   {
                                vector<treeNode*> v = {$1, $2};
                                $$ = new treeNode("stmt_list", v);
                                $$->append($1);
                                $$->append($2);
                            }
         | stmt {
                    vector<treeNode*> v = {$1};
                    $$ = new treeNode("stmt_list", v);
                
                    $$->append($1);
                    
                };

stmt: assign_stmt   {
                        vector<treeNode*> v = {$1};
                        $$ = new treeNode("stmt", v);
                    
                        $$->append($1);
                    }
    | {symbolTable.incrementScope();} compound_stmt {
                        vector<treeNode*> v = {$2};
                        $$ = new treeNode("stmt", v);
                        symbolTable.decrementScope();

                        $$->append($2);
                    }
    | if_stmt   {
                    vector<treeNode*> v = {$1};
                    $$ = new treeNode("stmt", v);
                
                    $$->append($1);
                }
    | while_stmt    {
                        vector<treeNode*> v = {$1};
                        $$ = new treeNode("stmt", v);
                    
                        $$->append($1);
                    }
    | switch_stmt   {
                        vector<treeNode*> v = {$1};
                        $$ = new treeNode("stmt", v);
                    }
    | return_stmt   {
                        vector<treeNode*> v = {$1};
                        $$ = new treeNode("stmt", v);
                        $$->append($1);
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
                    
                        $$->append($1);
                    }
    | scan_stmt     {
                        vector<treeNode*> v = {$1};
                        $$ = new treeNode("stmt", v);
                    
                        $$->append($1);
                    }
    | incr_stmt {
                    vector<treeNode*> v = {$1};
                    $$ = new treeNode("stmt", v);

                    $$->append($1);
                }  
    | decr_stmt {   
                    vector<treeNode*> v = {$1};
                    $$ = new treeNode("stmt", v);
                
                    $$->append($1);
                }; 

while_stmt: WHILE '(' expr ')' stmt 
{ 
    $1 = new treeNode("WHILE");
    $2 = new treeNode("("); $4 = new treeNode(")");
    vector<treeNode*> v = {$1, $2, $3, $4, $5};
    $$ = new treeNode("while_stmt", v); 
    set_whileLongestPath($$->maxSubtreeLength); 

    string start = newLabel();
    string end = newLabel();

    $$->putLabel(start);
    $$->append($3);
    $$->makeIns("cmpl", "$0", "%eax");
    $$->makeIns("je", end);
    $$->append($5);
    $$->makeIns("jmp", start);
    $$->putLabel(end);

};

dowhile_stmt: DO stmt WHILE '(' expr ')' ';' { 
                                                $1 = new treeNode("DO"); $3 = new treeNode("WHILE");
                                                $4 = new treeNode("("); $6 = new treeNode(")"); $7 = new treeNode(";");
                                                vector<treeNode*> v = {$1, $2, $3, $4, $5, $6, $7};
                                                $$ = new treeNode("dowhile_stmt", v);  
                                            };

print_stmt: PRINTF '(' format_specifier ',' identifier ')' ';'  
{
    $1 = new treeNode("PRINTF"); $2 = new treeNode("("); $4 = new treeNode(",");
    $6 = new treeNode(")"); $7 = new treeNode(";");
    vector<treeNode*> v = {$1, $2, $3, $4, $5, $6, $7};
    $$ = new treeNode("print_stmt", v);
    
    int offset = symbolTable.get( $5->lexValue );
    string arg2 = "-" + to_string(offset) + "(%rbp)";
    $$->makeIns("movl", arg2, "%esi");
    $$->makeIns("leaq", ".LC1(%rip)", "%rdi");
    $$->makeIns("movl", "$0", "%eax");
    $$->makeIns("call", "printf@PLT");

};

scan_stmt: SCANF '(' format_specifier ',' BITAND identifier ')' ';'  
{
    $1 = new treeNode("SCANF"); $2 = new treeNode("("); $4 = new treeNode(",");
    $5 = new treeNode("BITAND");
    $7 = new treeNode(")"); $8 = new treeNode(";");
    vector<treeNode*> v = {$1, $2, $3, $4, $5, $6, $7, $8};
    $$ = new treeNode("scan_stmt", v);
    // TODO
    int offset = symbolTable.get( $6->lexValue );
    string arg2 = "-" + to_string(offset) + "(%rbp)";
    $$->makeIns("leaq", arg2, "%rsi");
    $$->makeIns("leaq", ".LC0(%rip)", "%rdi");
    $$->makeIns("movl", "$0", "%eax");
    $$->makeIns("call", "__isoc99_scanf");

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
                                                    $$->append($2);
                                                    $$->append($3);
                                                };

local_decls: local_decls local_decl {
                                        vector<treeNode*> v = {$1, $2};
                                        $$ = new treeNode("local_decls", v);
                                        $$->append($1);
                                        $$->append($2);
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
                                            
                                            // cout << "type_spec::" << $1->lexValue << endl;
                                            if ($1 -> lexValue == "int") {
                                                intDeclarations++;
                                                symbolTable.put($2->lexValue);
                                                // cout << "Identifier::" << $2->lexValue << endl;
                                            }
                                        }
          | type_spec identifier '[' expr ']' ';'   {
                                                        $3 = new treeNode("["); $5 = new treeNode("]"); $6 = new treeNode(";");
                                                        vector<treeNode*> v = {$1, $2, $3, $4, $5, $6};
                                                        $$ = new treeNode("local_decl", v); 
                                                    
                                                        if ($1 -> lexValue == "int") {
                                                            intDeclarations+= $4->val;
                                                            symbolTable.putArray($2->lexValue, $4->val);
                                                            // cout << "Identifier::" << $2->lexValue << endl;
                                                        }

                                                    };

if_stmt: IF '(' expr ')' stmt   {   
                                    $1 = new treeNode("IF");
                                    $2 = new treeNode("("); $4 = new treeNode(")");
                                    vector<treeNode*> v = {$1, $2, $3, $4, $5};
                                    $$ = new treeNode("if_stmt", v);
                                    set_ifLongestPath($$->maxSubtreeLength);

                                    string end = newLabel();
                                    $$->append($3);
                                    $$->makeIns("cmpl", "$0", "%eax");
                                    $$->makeIns("je", end);
                                    $$->append($5);
                                    $$->putLabel(end);




                                }
       | IF '(' expr ')' stmt ELSE stmt { 
                                            $1 = new treeNode("IF");
                                            $2 = new treeNode("("); $4 = new treeNode(")"); $6 = new treeNode("ELSE");
                                            vector<treeNode*> v = {$1, $2, $3, $4, $5, $6, $7};
                                            $$ = new treeNode("if_stmt", v);
                                            set_ifLongestPath($$->maxSubtreeLength); 
                                        
                                            string els = newLabel();
                                            string end = newLabel();
                                            $$->append($3);
                                            $$->makeIns("cmpl", "$0", "%eax");
                                            $$->makeIns("je", els);
                                            $$->append($5);
                                            $$->makeIns("jmp", end);
                                            $$->putLabel(els);
                                            $$->append($7);
                                            $$->putLabel(end);       
                                        
                                        };

return_stmt: RETURN ';' { 
                            $1 = new treeNode("RETURN"); $2 = new treeNode(";");
                            vector<treeNode*> v = {$1, $2};
                            $$ = new treeNode("return_stmt", v);
                            $$->makeIns("leave");
                            $$->makeIns("ret");
                        }
           | RETURN expr ';'    {
                                    $1 = new treeNode("RETURN"); $3 = new treeNode(";");
                                    vector<treeNode*> v = {$1, $2, $3};
                                    $$ = new treeNode("return_stmt", v);
                                
                                    $$->append($2);
                                    $$->makeIns("leave");
                                    $$->makeIns("ret");  
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
                                        
                                        int offset = symbolTable.get( $1->lexValue );
                                        string arg2 = "-" + to_string(offset) + "(%rbp)";
                                        
                                        $$->append($3);
                                        $$->makeIns("movl", "%eax", arg2);


                                    }
           | identifier '[' expr ']' EQ expr ';'    {   // check this one
                                                        $2 = new treeNode("["); $4 = new treeNode("]"); $7 = new treeNode(";");
                                                        vector<treeNode*> u = {$1, $2, $3, $4, $6};
                                                        $5 = new treeNode("EQ", u);
                                                        vector<treeNode*> v = {$5, $7};
                                                        $$ = new treeNode("assign_stmt", v);    
                                                    
                                                        int offset = symbolTable.get( $1->lexValue );
                                                        string arg1 = "-" + to_string(offset) + "(%rbp,%rax,4)";
                                                        $$->append($6);
                                                        $$->makeIns("movl", "%eax", "%ebx");
                                                        
                                                        $$->append($3);
                                                        $$->makeIns("movl", "%ebx"  ,arg1);    

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

                                    int offset = symbolTable.get( $1->lexValue );
                                    string arg2 = "-" + to_string(offset) + "(%rbp)";
                                    $$->makeIns("addl", "$1", arg2);


                                };

decr_stmt: identifier DEC ';'   {
                                    $3 = new treeNode(";");
                                    $2 = new treeNode("DEC");
                                    vector<treeNode*> v = {$1, $2, $3};
                                    $$ = new treeNode("decr_stmt", v);

                                    int offset = symbolTable.get( $1->lexValue );
                                    string arg2 = "-" + to_string(offset) + "(%rbp)";
                                    $$->makeIns("subl", "$1", arg2);
                                };

expr: Pexpr LT Pexpr    {
                            vector<treeNode*> u = {$1, $3};
                            $2 = new treeNode("LT", u);
                            vector<treeNode*> v = {$2};
                            $$ = new treeNode("expr", v);

                            
                            $$->append($3);
                            $$->makeIns("pushq", "%rax");
                            $$->append($1);
                            $$->makeIns("popq", "%rbx");
                            $$->append(makeCompare("jl"));


                        }
    | Pexpr GT Pexpr    {   
                            vector<treeNode*> u = {$1, $3};
                            $2 = new treeNode("GT", u);
                            vector<treeNode*> v = {$2};
                            $$ = new treeNode("expr", v);

                            $$->append($3);
                            $$->makeIns("pushq", "%rax");
                            $$->append($1);
                            $$->makeIns("popq", "%rbx");
                            $$->append(makeCompare("jg"));
                        }
    | Pexpr LEQ Pexpr   {
                            vector<treeNode*> u = {$1, $3};
                            $2 = new treeNode("LEQ", u);
                            vector<treeNode*> v = {$2};
                            $$ = new treeNode("expr", v);

                            $$->append($3);
                            $$->makeIns("pushq", "%rax");
                            $$->append($1);
                            $$->makeIns("popq", "%rbx");
                            $$->append(makeCompare("jle"));
                        }
    | Pexpr GEQ Pexpr   {
                            vector<treeNode*> u = {$1, $3};
                            $2 = new treeNode("GEQ", u);
                            vector<treeNode*> v = {$2};
                            $$ = new treeNode("expr", v);

                            $$->append($3);
                            $$->makeIns("pushq", "%rax");
                            $$->append($1);
                            $$->makeIns("popq", "%rbx");
                            $$->append(makeCompare("jge"));
                        }
    | Pexpr OR Pexpr    {
                            vector<treeNode*> u = {$1, $3};
                            $2 = new treeNode("OR", u);
                            vector<treeNode*> v = {$2};
                            $$ = new treeNode("expr", v);

                            $$->append($3);
                            $$->makeIns("pushq", "%rax");
                            $$->append($1);
                            $$->makeIns("popq", "%rbx");
                            $$->makeIns("orl", "%ebx", "%eax");
                        }
    | SIZEOF '(' Pexpr ')'  {
                                $1 = new treeNode("SIZEOF"); $2 = new treeNode("("); $4 = new treeNode(")");
                                vector<treeNode*> v = {$1, $2, $3, $4};
                                $$ = new treeNode("expr", v);

                                $$->makeIns("movl", "$4", "%eax");

                            }
    | Pexpr EQEQ Pexpr  {
                            vector<treeNode*> u = {$1, $3};
                            $2 = new treeNode("EQEQ", u);
                            vector<treeNode*> v = {$2};
                            $$ = new treeNode("expr", v);

                            $$->append($3);
                            $$->makeIns("pushq", "%rax");
                            $$->append($1);
                            $$->makeIns("popq", "%rbx");
                            $$->append(makeCompare("je"));

                        }
    | Pexpr NEQ Pexpr   {
                            vector<treeNode*> u = {$1, $3};
                            $2 = new treeNode("NEQ", u);
                            vector<treeNode*> v = {$2};
                            $$ = new treeNode("expr", v);

                            $$->append($3);
                            $$->makeIns("pushq", "%rax");
                            $$->append($1);
                            $$->makeIns("popq", "%rbx");
                            $$->append(makeCompare("jne"));
                        }
    | Pexpr NEWOP Pexpr {
                            vector<treeNode*> u = {$1, $3};
                            $2 = new treeNode("NEWOP", u);
                            vector<treeNode*> v = {$2};
                            $$ = new treeNode("expr", v);

                            string less = newLabel();
                            string more = newLabel();
                            string end = newLabel();
                            
                            $$->append($3);
                            $$->makeIns("pushq", "%rax");
                            $$->append($1);
                            $$->makeIns("popq", "%rbx");


                            $$->makeIns ("cmpl", "%ebx", "%eax");
                            $$-> makeIns("jl", less);

                            $$-> makeIns ("cmpl", "%ebx", "%eax");
                            $$-> makeIns("jg", more);

                            $$->makeIns("movl", "$0", "%eax");
                            $$-> makeIns("jmp", end);

                            $$->putLabel(more);
                            $$->makeIns("movl", "$1", "%eax");
                            $$-> makeIns("jmp", end);

                            $$->putLabel(less);
                            $$->makeIns("movl", "$-1", "%eax");
                            $$-> makeIns("jmp", end);

                            $$->putLabel(end);

                            



                        }
    | Pexpr AND Pexpr   {
                            vector<treeNode*> u = {$1, $3};
                            $2 = new treeNode("AND", u);
                            vector<treeNode*> v = {$2};
                            $$ = new treeNode("expr", v);
                            
                            $$->append($3);
                            $$->makeIns("pushq", "%rax");
                            $$->append($1);
                            $$->makeIns("popq", "%rbx");
                            $$->makeIns("andl", "%ebx", "%eax");
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

                            $$->append($3);
                            $$->makeIns("pushq", "%rax");
                            $$->append($1);
                            $$->makeIns("popq", "%rbx");
                            $$->makeIns("addl", "%ebx", "%eax");

                            $$->val = $1->val + $3->val;

                        
                        }
    | Pexpr MINUS Pexpr {
                            vector<treeNode*> u = {$1, $3};
                            $2 = new treeNode("MINUS", u);
                            vector<treeNode*> v = {$2};
                            $$ = new treeNode("expr", v);

                            $$->append($3);
                            $$->makeIns("pushq", "%rax");
                            $$->append($1);
                            $$->makeIns("popq", "%rbx");
                            $$->makeIns("subl", "%ebx", "%eax");

                            $$->val = $1->val - $3->val;
                        }
    | Pexpr MULT Pexpr  {
                            vector<treeNode*> u = {$1, $3};
                            $2 = new treeNode("MULT", u);
                            vector<treeNode*> v = {$2};
                            $$ = new treeNode("expr", v);

                            $$->append($3);
                            $$->makeIns("pushq", "%rax");
                            $$->append($1);
                            $$->makeIns("popq", "%rbx");
                            $$->makeIns("imul", "%ebx", "%eax");
                            
                            $$->val = $1->val * $3->val;
                        }
    | Pexpr DIV Pexpr   {
                            vector<treeNode*> u = {$1, $3};
                            $2 = new treeNode("DIV", u);
                            vector<treeNode*> v = {$2};
                            $$ = new treeNode("expr", v);

                            $$->append($3);
                            $$->makeIns("pushq", "%rax");
                            $$->append($1);
                            $$->makeIns("popq", "%rbx");
                            $$->makeIns("movl", "$0" ,"%edx");
                            $$->makeIns("idivl", "%ebx");

                            if ($3->val != 0)
                                $$->val = $1->val / $3->val;
                        }
    | Pexpr MOD Pexpr   {
                            vector<treeNode*> u = {$1, $3};
                            $2 = new treeNode("MOD", u);
                            vector<treeNode*> v = {$2};
                            $$ = new treeNode("expr", v);

                            $$->append($3);
                            $$->makeIns("pushq", "%rax");
                            $$->append($1);
                            $$->makeIns("popq", "%rbx");
                            $$->makeIns("movl", "$0" ,"%edx");
                            $$->makeIns("idivl", "%ebx");
                            $$->makeIns("movl", "%edx" ,"%eax");

                            if ($3->val != 0)
                                $$->val = $1->val % $3->val;

                        }
    | NOT Pexpr {
                    $1 = new treeNode("NOT");
                    vector<treeNode*> v = {$1, $2};
                    $$ = new treeNode("expr", v);

                    $$->append($2);
                    $$->makeIns("movl", "%eax", "%ebx");
                    $$->makeIns("xorl", "%eax", "%eax");
                    $$->makeIns("test", "%ebx", "%ebx");
                    $$->makeIns("sete", "%al");

                }
    | MINUS Pexpr   {
                        $1 = new treeNode("MINUS");
                        vector<treeNode*> v = {$1, $2};
                        $$ = new treeNode("expr", v);

                        $$->append($2);
                        $$->makeIns("negl", "%eax");
                        $$->val = - $2->val;

                    }
    | PLUS Pexpr    {
                        $1 = new treeNode("PLUS");
                        vector<treeNode*> v = {$1, $2};
                        $$ = new treeNode("expr", v);

                        $$->append($2);
                        $$->val = $2->val;
                    }
    | MULT Pexpr    {
                        $1 = new treeNode("MULT");
                        vector<treeNode*> v = {$1, $2};
                        $$ = new treeNode("expr", v);
                        //Incorrect
                        $$->append($2);
                    }
    | BITAND Pexpr  {   
                        $1 = new treeNode("BITAND");
                        vector<treeNode*> v = {$1, $2};
                        $$ = new treeNode("expr", v);
                    }
    | Pexpr {
                vector<treeNode*> v = {$1};
                $$ = new treeNode("expr", v);
                
                $$->append($1);
                $$->val = $1->val;
            }
    | identifier '(' args ')'   {
                                    $2 = new treeNode("("); $4 = new treeNode(")");
                                    vector<treeNode*> v = {$1, $2, $3, $4};
                                    $$ = new treeNode("expr", v); 

                                    
                                
                                    $$->append($3);
                                    $$->makeIns("call", $1->lexValue);

                                
                                }
    | identifier '[' expr ']'   {
                                    $2 = new treeNode("["); $4 = new treeNode("]");
                                    vector<treeNode*> v = {$1, $2, $3, $4};
                                    $$ = new treeNode("expr", v); 
                                
                                    
                                    int offset = symbolTable.get( $1->lexValue );
                                    string arg1 = "-" + to_string(offset) + "(%rbp,%rax,4)";
                                    $$->append($3);
                                    $$->makeIns("movl", arg1, "%eax");    
                                
                                };

Pexpr: integerLit   {
                        vector<treeNode*> v = {$1};
                        $$ = new treeNode("Pexpr", v);

                        string num = "$" + $1->lexValue;
                        $$->makeIns("movl", num , "%eax");
                        $$->val = stoi ($1->lexValue);
                    
                    }
     | floatLit {
                    vector<treeNode*> v = {$1};
                    $$ = new treeNode("Pexpr", v);
                }
     | identifier   {
                        vector<treeNode*> v = {$1};
                        $$ = new treeNode("Pexpr", v);

                        int offset = symbolTable.get( $1->lexValue );
                        string arg1 = "-" + to_string(offset) + "(%rbp)";
                        $$->makeIns("movl", arg1, "%eax");

                    }
     | '(' expr ')' {
                        $1 = new treeNode("("); $3 = new treeNode(")");
                        vector<treeNode*> v = {$1, $2, $3};
                        $$ = new treeNode("Pexpr", v);

                        $$->append($2);
                    };
    

integerLit: INTEGER_NUMBER  {
                                $1 = new treeNode("INTEGER_NUMBER");
                                vector<treeNode*> v = {$1};
                                $$ = new treeNode("intergerLit", v);
                                $$->lexValue = mytext;

                            };

floatLit: FLOAT_NUMBER  {
                            $1 = new treeNode("FLOAT_NUMBER");
                            vector<treeNode*> v = {$1};
                            $$ = new treeNode("floatLit", v);
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

                                $$->append($1);
                                $$->append($3);
                                $$->makeIns("subq", "$4", "%rsp");
                                $$->makeIns("movl", "%eax", "0(%rsp)");
                                $$->val = $1->val + 1;
                            }
        | expr  {
                    vector<treeNode*> v = {$1};
                    $$ = new treeNode("arg_list", v);
                    $$->val = 1;

                    $$->append($1);
                    $$->makeIns("subq", "$4", "%rsp");
                    $$->makeIns("movl", "%eax", "0(%rsp)");

                };

args: arg_list  {
                    vector<treeNode*> v = {$1};
                    $$ = new treeNode("args", v);
                
                    $$->makeIns("pushq", "$0");
                    $$->makeIns("pushq", "$0");
                    $$->append($1);
                    $$->val = $1->val;                

                    string arg1 = "$" + to_string(4*($$->val) + 16);
                    $$->makeIns("addq", arg1, "%rsp");
                }
    |   {
            auto x = new treeNode("epsilon");
            vector<treeNode*> v = {x};
            $$ = new treeNode("args", v);
        };

%%



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
