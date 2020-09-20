%token IF ELSE WHILE DO FOR SWITCH CASE DEFAULT EXTERN STRUCT BREAK CONTINUE RETURN SIZEOF PRINTF
%token INT LONG SHORT FLOAT DOUBLE VOID CHAR
%token IDENTIFIER
%token CHARACTER NUMBER REALNUMBER STRING PERCENTD
%token THREEWAYCOMP INCR DECR LOGICALAND LOGICALOR POINTERMEMBER EQEQ NOTEQ LESSEREQ GREATEREQ
%{
	#include <stdio.h>
	void yyerror(char *);
	int yylex(void);
	char mytext[100];
	
%}

%%

program: decl_list;

decl_list: decl_list decl 
	| decl
;

decl: var_decl 
	| fun_decl 
	| struct_decl
;

struct_decl: STRUCT identifier '{' local_decls '}' ';';

var_decl: type_spec identifier ';'
	| type_spec identifier ',' var_decl
	| type_spec identifier '[' integerLit ']' ';'
	| type_spec identifier '[' integerLit ']' ',' var_decl
;

type_spec: extern_spec VOID
	| extern_spec INT
	| extern_spec FLOAT
	| extern_spec VOID '*'
	| extern_spec INT '*'
	| extern_spec FLOAT '*'
	| STRUCT identifier
	| STRUCT identifier '*'
;

extern_spec: EXTERN 
	| epsilon
;

fun_decl: type_spec identifier '(' params ')' compound_stmt;

params: param_list
	| epsilon
;

param_list: param_list ',' param
	| param
;

param: type_spec identifier
	| type_spec identifier '[' ']'
	| type_spec '[' ']' identifier
;

stmt_list: stmt_list stmt
	| stmt
;

stmt: assign_stmt
	| compound_stmt
	| if_stmt
	| while_stmt
	| switch_stmt
	| return_stmt
	| break_stmt
	| continue_stmt
	| dowhile_stmt
	| print_stmt
	| incr_stmt
	| decr_stmt
	| expr_stmt
;

expr_stmt: expr ';';

while_stmt: WHILE '(' expr ')' stmt;

dowhile_stmt: DO stmt WHILE '(' expr ')' ';';

print_stmt: PRINTF '(' format_specifier ',' identifier ')' ';';

format_specifier: PERCENTD;

compound_stmt: '{' local_decls stmt_list '}';

local_decls: local_decls local_decl
	| epsilon
;

local_decl: type_spec identifier ';'
	| type_spec identifier '[' expr ']' ';'
;

if_stmt: IF '(' expr ')' stmt
	| IF '(' expr ')' stmt ELSE stmt
;

return_stmt: RETURN ';'
	| RETURN expr ';'
;

break_stmt: BREAK ';';

continue_stmt: CONTINUE ';';

switch_stmt: SWITCH '(' expr ')' '{' compound_case default_case '}';

compound_case: single_case compound_case
	| single_case
;

single_case: CASE integerLit ':' stmt_list;

default_case: DEFAULT ':' stmt_list;

assign_stmt: identifier '=' expr ';'
	| identifier '[' expr ']' '=' expr ';'
	| identifier POINTERMEMBER identifier '=' expr ';'
	| identifier '.' identifier '=' expr ';'
;

incr_stmt: identifier INCR ';';

decr_stmt: identifier DECR ';';

expr: Pexpr '<' Pexpr
	| Pexpr '>' Pexpr
	| Pexpr LESSEREQ Pexpr
	| Pexpr GREATEREQ Pexpr
	| Pexpr LOGICALOR Pexpr
	| SIZEOF '(' Pexpr ')'
	| Pexpr EQEQ Pexpr
	| Pexpr NOTEQ Pexpr
	| Pexpr THREEWAYCOMP Pexpr
	| Pexpr LOGICALAND Pexpr
	| Pexpr POINTERMEMBER Pexpr
	| Pexpr '+' Pexpr
	| Pexpr '-' Pexpr
	| Pexpr '*' Pexpr
	| Pexpr '/' Pexpr
	| Pexpr '%' Pexpr
	| '!' Pexpr
	| '-' Pexpr
	| '+' Pexpr
	| '*' Pexpr
	| '&' Pexpr
	| Pexpr
	| identifier '(' args ')'
	| identifier '[' expr ']'
;

Pexpr: integerLit
	| floatLit
	| identifier
	| '(' expr ')'
;

integerLit: NUMBER;

floatLit: REALNUMBER;

identifier: IDENTIFIER;

arg_list: arg_list ',' expr
	| expr
;

args: arg_list
	| epsilon
;

epsilon: ;
%%

void yyerror(char *s) {
	extern int yylineno;
    fprintf(stderr, "%s on line %d\n", s, yylineno);
}

int main(void) {
    yyparse();
	fprintf(stdout, "parsed successfully\n");
    return 0;
}

