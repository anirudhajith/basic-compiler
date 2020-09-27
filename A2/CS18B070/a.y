%token IF ELSE WHILE DO FOR SWITCH CASE DEFAULT EXTERN STRUCT BREAK CONTINUE RETURN SIZEOF PRINTF
%token INT LONG SHORT FLOAT DOUBLE VOID CHAR
%token IDENTIFIER
%token CHARACTER NUMBER REALNUMBER STRING PERCENTD
%token THREEWAYCOMP INCR DECR LOGICALAND LOGICALOR POINTERMEMBER EQEQ NOTEQ LESSEREQ GREATEREQ
%union
{
  struct
  {
    int h;
    int d;
  } type_id;
}
%type <type_id> program decl_list decl struct_decl var_decl type_spec extern_spec fun_decl params param_list param stmt_list stmt expr_stmt while_stmt dowhile_stmt print_stmt format_specifier compound_stmt local_decls local_decl if_stmt return_stmt break_stmt continue_stmt switch_stmt compound_case single_case default_case assign_stmt incr_stmt decr_stmt expr Pexpr integerLit floatLit identifier arg_list args epsilon IF ELSE WHILE DO FOR SWITCH CASE DEFAULT EXTERN STRUCT BREAK CONTINUE RETURN SIZEOF PRINTF INT LONG SHORT FLOAT DOUBLE VOID CHAR IDENTIFIER CHARACTER NUMBER REALNUMBER STRING PERCENTD THREEWAYCOMP INCR DECR LOGICALAND LOGICALOR POINTERMEMBER EQEQ NOTEQ LESSEREQ GREATEREQ '!' '-' '+' '*' '&' '(' ')' '{' '}' '[' ']' ';' ':' '.'
%{
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

%}

%%

program: decl_list														{ int h[1] = {$1.h}; int d[1] = {$1.d};			$$.h = getH(1, h); $$.d = getD(1, h, d); 	programDiameter = $$.d + 1; }
;

decl_list: decl_list decl 												{ int h[2] = {$1.h, $2.h}; int d[2] = {$1.d, $2.d};			$$.h = getH(2, h); $$.d = getD(2, h, d); }
	| decl																{ int h[1] = {$1.h}; int d[1] = {$1.d};			$$.h = getH(1, h); $$.d = getD(1, h, d); }
;

decl: var_decl 															{ int h[1] = {$1.h}; int d[1] = {$1.d};			$$.h = getH(1, h); $$.d = getD(1, h, d); }
	| fun_decl 															{ int h[1] = {$1.h}; int d[1] = {$1.d};			$$.h = getH(1, h); $$.d = getD(1, h, d); }
	| struct_decl														{ int h[1] = {$1.h}; int d[1] = {$1.d};			$$.h = getH(1, h); $$.d = getD(1, h, d); }
;

struct_decl: STRUCT identifier '{' local_decls '}' ';'					{ int h[6] = {0, $2.h, 0, $4.h, 0, 0}; int d[6] = {0, $2.d, 0, $4.d, 0, 0};			$$.h = getH(6, h); $$.d = getD(6, h, d); }
;

var_decl: type_spec identifier ';'										{ int h[3] = {$1.h, $2.h, 0}; int d[3] = {$1.d, $2.d, 0};			$$.h = getH(3, h); $$.d = getD(3, h, d); }
	| type_spec identifier ',' var_decl									{ int h[4] = {$1.h, $2.h, 0, $4.h}; int d[4] = {$1.d, $2.d, 0, $4.d};			$$.h = getH(4, h); $$.d = getD(4, h, d); }
	| type_spec identifier '[' integerLit ']' ';'						{ int h[6] = {$1.h, $2.h, 0, $4.h, 0, 0}; int d[6] = {$1.d, $2.d, 0, $4.d, 0, 0};			$$.h = getH(6, h); $$.d = getD(6, h, d); }
	| type_spec identifier '[' integerLit ']' ',' var_decl				{ int h[7] = {$1.h, $2.h, 0, $4.h, 0, 0, $7.h}; int d[7] = {$1.d, $2.d, 0, $4.d, 0, 0, $7.d};			$$.h = getH(7, h); $$.d = getD(7, h, d); }
;

type_spec: extern_spec VOID												{ int h[2] = {$1.h, 0}; int d[2] = {$1.d, 0};			$$.h = getH(2, h); $$.d = getD(2, h, d); }
	| extern_spec INT													{ int h[2] = {$1.h, 0}; int d[2] = {$1.d, 0};			$$.h = getH(2, h); $$.d = getD(2, h, d); }
	| extern_spec FLOAT													{ int h[2] = {$1.h, 0}; int d[2] = {$1.d, 0};			$$.h = getH(2, h); $$.d = getD(2, h, d); }
	| extern_spec VOID '*'												{ int h[3] = {$1.h, 0, 0}; int d[3] = {$1.d, 0, 0};			$$.h = getH(3, h); $$.d = getD(3, h, d); }
	| extern_spec INT '*'												{ int h[3] = {$1.h, 0, 0}; int d[3] = {$1.d, 0, 0};			$$.h = getH(3, h); $$.d = getD(3, h, d); }
	| extern_spec FLOAT '*'												{ int h[3] = {$1.h, 0, 0}; int d[3] = {$1.d, 0, 0};			$$.h = getH(3, h); $$.d = getD(3, h, d); }
	| STRUCT identifier													{ int h[2] = {0, $2.h}; int d[2] = {0, $2.d};			$$.h = getH(2, h); $$.d = getD(2, h, d); }
	| STRUCT identifier '*'												{ int h[3] = {0, $2.h, 0}; int d[3] = {0, $2.d, 0};			$$.h = getH(3, h); $$.d = getD(3, h, d); }
;

extern_spec: EXTERN 													{ int h[1] = {0}; int d[1] = {0};			$$.h = getH(1, h); $$.d = getD(1, h, d); }
	| epsilon															{ int h[1] = {0}; int d[1] = {0};			$$.h = getH(1, h); $$.d = getD(1, h, d); }
;

fun_decl: type_spec identifier { if (mainDetected == 0) updateMain = 1; } '(' params ')' compound_stmt				{ int h[6] = {$1.h, $2.h, 0, $5.h, 0, $7.h}; int d[6] = {$1.d, $2.d, 0, $5.d, 0, $7.d};			$$.h = getH(6, h); $$.d = getD(6, h, d); 		if (updateMain == 1) {mainDiameter = max(mainDiameter, $$.d + 1); updateMain = 0;} }
;

params: param_list														{ int h[1] = {$1.h}; int d[1] = {$1.d};			$$.h = getH(1, h); $$.d = getD(1, h, d); }
	| epsilon															{ int h[1] = {0}; int d[1] = {0};			$$.h = getH(1, h); $$.d = getD(1, h, d); }
;

param_list: param_list ',' param										{ int h[3] = {$1.h, 0, $3.h}; int d[3] = {$1.d, 0, $3.d};			$$.h = getH(3, h); $$.d = getD(3, h, d); }
	| param																{ int h[1] = {$1.h}; int d[1] = {$1.d};			$$.h = getH(1, h); $$.d = getD(1, h, d); }
;

param: type_spec identifier												{ int h[2] = {$1.h, $2.h}; int d[2] = {$1.d, $2.d};			$$.h = getH(2, h); $$.d = getD(2, h, d); }
	| type_spec identifier '[' ']'										{ int h[4] = {$1.h, $2.h, 0, 0}; int d[4] = {$1.d, $2.d, 0, 0};			$$.h = getH(4, h); $$.d = getD(4, h, d); }
	| type_spec '[' ']' identifier										{ int h[4] = {$1.h, 0, 0, $4.h}; int d[4] = {$1.d, 0, 0, $4.d};			$$.h = getH(4, h); $$.d = getD(4, h, d); }
;

stmt_list: stmt_list stmt												{ int h[2] = {$1.h, $2.h}; int d[2] = {$1.d, $2.d};			$$.h = getH(2, h); $$.d = getD(2, h, d); }
	| stmt																{ int h[1] = {$1.h}; int d[1] = {$1.d};			$$.h = getH(1, h); $$.d = getD(1, h, d); }
;

stmt: assign_stmt														{ int h[1] = {$1.h}; int d[1] = {$1.d};			$$.h = getH(1, h); $$.d = getD(1, h, d); }
	| compound_stmt														{ int h[1] = {$1.h}; int d[1] = {$1.d};			$$.h = getH(1, h); $$.d = getD(1, h, d); }
	| if_stmt															{ int h[1] = {$1.h}; int d[1] = {$1.d};			$$.h = getH(1, h); $$.d = getD(1, h, d); }
	| while_stmt														{ int h[1] = {$1.h}; int d[1] = {$1.d};			$$.h = getH(1, h); $$.d = getD(1, h, d); }
	| switch_stmt														{ int h[1] = {$1.h}; int d[1] = {$1.d};			$$.h = getH(1, h); $$.d = getD(1, h, d); }
	| return_stmt														{ int h[1] = {$1.h}; int d[1] = {$1.d};			$$.h = getH(1, h); $$.d = getD(1, h, d); }
	| break_stmt														{ int h[1] = {$1.h}; int d[1] = {$1.d};			$$.h = getH(1, h); $$.d = getD(1, h, d); }
	| continue_stmt														{ int h[1] = {$1.h}; int d[1] = {$1.d};			$$.h = getH(1, h); $$.d = getD(1, h, d); }
	| dowhile_stmt														{ int h[1] = {$1.h}; int d[1] = {$1.d};			$$.h = getH(1, h); $$.d = getD(1, h, d); }
	| print_stmt														{ int h[1] = {$1.h}; int d[1] = {$1.d};			$$.h = getH(1, h); $$.d = getD(1, h, d); }
	| incr_stmt															{ int h[1] = {$1.h}; int d[1] = {$1.d};			$$.h = getH(1, h); $$.d = getD(1, h, d); }
	| decr_stmt															{ int h[1] = {$1.h}; int d[1] = {$1.d};			$$.h = getH(1, h); $$.d = getD(1, h, d); }
	| expr_stmt															{ int h[1] = {$1.h}; int d[1] = {$1.d};			$$.h = getH(1, h); $$.d = getD(1, h, d); }
;

expr_stmt: expr ';'														{ int h[2] = {$1.h, 0}; int d[2] = {$1.d, 0};			$$.h = getH(2, h); $$.d = getD(2, h, d); }
;

while_stmt: WHILE '(' expr ')' stmt										{ int h[5] = {0, 0, $3.h, 0, $5.h}; int d[5] = {0, 0, $3.d, 0, $5.d};			$$.h = getH(5, h); $$.d = getD(5, h, d); 		whileDiameter = max(whileDiameter, $$.d + 1); }
;

dowhile_stmt: DO stmt WHILE '(' expr ')' ';'							{ int h[7] = {0, $2.h, 0, 0, $5.h, 0, 0}; int d[7] = {0, $2.d, 0, 0, $5.d, 0, 0};			$$.h = getH(7, h); $$.d = getD(7, h, d); }
;

print_stmt: PRINTF '(' format_specifier ',' identifier ')' ';'			{ int h[7] = {0, 0, $3.h, 0, $5.h, 0, 0}; int d[7] = {0, 0, $3.d, 0, $5.d, 0, 0};			$$.h = getH(7, h); $$.d = getD(7, h, d); }
;

format_specifier: PERCENTD												{ int h[1] = {0}; int d[1] = {0};			$$.h = getH(1, h); $$.d = getD(1, h, d); }
;

compound_stmt: '{' local_decls stmt_list '}'							{ int h[4] = {0, $2.h, $3.h, 0}; int d[4] = {0, $2.d, $3.d, 0};			$$.h = getH(4, h); $$.d = getD(4, h, d); }
;

local_decls: local_decls local_decl										{ int h[2] = {$1.h, $2.h}; int d[2] = {$1.d, $2.d};			$$.h = getH(2, h); $$.d = getD(2, h, d); }
	| epsilon															{ int h[1] = {0}; int d[1] = {0};			$$.h = getH(1, h); $$.d = getD(1, h, d); }
;

local_decl: type_spec identifier ';'									{ int h[3] = {$1.h, $2.h, 0}; int d[3] = {$1.d, $2.d, 0};			$$.h = getH(3, h); $$.d = getD(3, h, d); }
	| type_spec identifier '[' expr ']' ';'								{ int h[6] = {$1.h, $2.h, 0, $4.h, 0, 0}; int d[6] = {$1.d, $2.d, 0, $4.d, 0, 0};			$$.h = getH(6, h); $$.d = getD(6, h, d); }
;

if_stmt: IF '(' expr ')' stmt											{ int h[5] = {0, 0, $3.h, 0, $5.h}; int d[5] = {0, 0, $3.d, 0, $5.d};			$$.h = getH(5, h); $$.d = getD(5, h, d); 		ifDiameter = max(ifDiameter, $$.d + 1); }
	| IF '(' expr ')' stmt ELSE stmt									{ int h[7] = {0, 0, $3.h, 0, $5.h, 0, $7.h}; int d[7] = {0, 0, $3.d, 0, $5.d, 0, $7.d};			$$.h = getH(7, h); $$.d = getD(7, h, d); 		ifDiameter = max(ifDiameter, $$.d + 1); }
;

return_stmt: RETURN ';'													{ int h[2] = {0, 0}; int d[2] = {0, 0};			$$.h = getH(2, h); $$.d = getD(2, h, d); }
	| RETURN expr ';'													{ int h[3] = {0, $2.h, 0}; int d[3] = {0, $2.d, 0};			$$.h = getH(3, h); $$.d = getD(3, h, d); }
;

break_stmt: BREAK ';'													{ int h[2] = {0, 0}; int d[2] = {0, 0};			$$.h = getH(2, h); $$.d = getD(2, h, d); }
;

continue_stmt: CONTINUE ';'												{ int h[2] = {0, 0}; int d[2] = {0, 0};			$$.h = getH(2, h); $$.d = getD(2, h, d); }
;

switch_stmt: SWITCH '(' expr ')' '{' compound_case default_case '}'		{ int h[8] = {0, 0, $3.h, 0, 0, $6.h, $7.h, 0}; int d[8] = {0, 0, $3.d, 0, 0, $6.d, $7.d, 0};			$$.h = getH(8, h); $$.d = getD(8, h, d); 			switchDiameter = max(switchDiameter, $$.d + 1); }
;

compound_case: single_case compound_case								{ int h[2] = {$1.h, $2.h}; int d[2] = {$1.d, $2.d};			$$.h = getH(2, h); $$.d = getD(2, h, d); }
	| single_case														{ int h[1] = {$1.h}; int d[1] = {$1.d};			$$.h = getH(1, h); $$.d = getD(1, h, d); }
;

single_case: CASE integerLit ':' stmt_list								{ int h[4] = {0, $2.h, 0, $4.h}; int d[4] = {0, $2.d, 0, $4.d};			$$.h = getH(4, h); $$.d = getD(4, h, d); }
;

default_case: DEFAULT ':' stmt_list										{ int h[3] = {0, 0, $3.h}; int d[3] = {0, 0, $3.d};			$$.h = getH(3, h); $$.d = getD(3, h, d); }

assign_stmt: identifier '=' expr ';'									{ int h[2] = {$1.h, $3.h}; int d[2] = {$1.d, $3.d};         $$.h = getH(2, h) + 1; $$.d = max(getD(2, h, d), $$.h + 1); }
	| identifier '[' expr ']' '=' expr ';'								{ int h[3] = {$1.h, $3.h, $6.h}; int d[3] = {$1.d, $3.d, $6.d};         $$.h = getH(3, h) + 1; $$.d = max(getD(3, h, d), $$.h + 1); }
	| identifier POINTERMEMBER identifier '=' expr ';'					{ int h[4] = {$1.h, $2.h, $3.h, $5.h}; int d[4] = {$1.d, $2.d, $3.d, $5.d};         $$.h = getH(4, h) + 1; $$.d = max(getD(4, h, d), $$.h + 1); }
	| identifier '.' identifier '=' expr ';'							{ int h[4] = {$1.h, $2.h, $3.h, $5.h}; int d[4] = {$1.d, $2.d, $3.d, $5.d};         $$.h = getH(4, h) + 1; $$.d = max(getD(4, h, d), $$.h + 1); }
;

incr_stmt: identifier INCR ';'											{ int h[3] = {$1.h, 0, 0}; int d[3] = {$1.d, 0, 0};			$$.h = getH(3, h); $$.d = getD(3, h, d); }
;

decr_stmt: identifier DECR ';'											{ int h[3] = {$1.h, 0, 0}; int d[3] = {$1.d, 0, 0};			$$.h = getH(3, h); $$.d = getD(3, h, d); }
;

expr: Pexpr '<' Pexpr													{ $$.h = max($1.h, $3.h) + 2; $$.d = max(max(max($1.d, $3.d), $1.h + $3.h + 2), $$.h); }
	| Pexpr '>' Pexpr													{ $$.h = max($1.h, $3.h) + 2; $$.d = max(max(max($1.d, $3.d), $1.h + $3.h + 2), $$.h); }
	| Pexpr LESSEREQ Pexpr												{ $$.h = max($1.h, $3.h) + 2; $$.d = max(max(max($1.d, $3.d), $1.h + $3.h + 2), $$.h); }
	| Pexpr GREATEREQ Pexpr												{ $$.h = max($1.h, $3.h) + 2; $$.d = max(max(max($1.d, $3.d), $1.h + $3.h + 2), $$.h); }
	| Pexpr LOGICALOR Pexpr												{ $$.h = max($1.h, $3.h) + 2; $$.d = max(max(max($1.d, $3.d), $1.h + $3.h + 2), $$.h); }
	| SIZEOF '(' Pexpr ')'												{ int h[4] = {0, 0, $3.h, 0}; int d[4] = {0, 0, $3.d, 0};			$$.h = getH(4, h); $$.d = getD(4, h, d); }
	| Pexpr EQEQ Pexpr													{ $$.h = max($1.h, $3.h) + 2; $$.d = max(max(max($1.d, $3.d), $1.h + $3.h + 2), $$.h); }
	| Pexpr NOTEQ Pexpr													{ $$.h = max($1.h, $3.h) + 2; $$.d = max(max(max($1.d, $3.d), $1.h + $3.h + 2), $$.h); }
	| Pexpr THREEWAYCOMP Pexpr											{ $$.h = max($1.h, $3.h) + 2; $$.d = max(max(max($1.d, $3.d), $1.h + $3.h + 2), $$.h); }
	| Pexpr LOGICALAND Pexpr											{ $$.h = max($1.h, $3.h) + 2; $$.d = max(max(max($1.d, $3.d), $1.h + $3.h + 2), $$.h); }
	| Pexpr POINTERMEMBER Pexpr											{ $$.h = max($1.h, $3.h) + 2; $$.d = max(max(max($1.d, $3.d), $1.h + $3.h + 2), $$.h); }
	| Pexpr '+' Pexpr													{ $$.h = max($1.h, $3.h) + 2; $$.d = max(max(max($1.d, $3.d), $1.h + $3.h + 2), $$.h); }
	| Pexpr '-' Pexpr													{ $$.h = max($1.h, $3.h) + 2; $$.d = max(max(max($1.d, $3.d), $1.h + $3.h + 2), $$.h); }
	| Pexpr '*' Pexpr													{ $$.h = max($1.h, $3.h) + 2; $$.d = max(max(max($1.d, $3.d), $1.h + $3.h + 2), $$.h); }
	| Pexpr '/' Pexpr													{ $$.h = max($1.h, $3.h) + 2; $$.d = max(max(max($1.d, $3.d), $1.h + $3.h + 2), $$.h); }
	| Pexpr '%' Pexpr													{ $$.h = max($1.h, $3.h) + 2; $$.d = max(max(max($1.d, $3.d), $1.h + $3.h + 2), $$.h); }
	| '!' Pexpr															{ int h[2] = {0, $2.h}; int d[2] = {0, $2.d};			$$.h = getH(2, h); $$.d = getD(2, h, d); }
	| '-' Pexpr															{ int h[2] = {0, $2.h}; int d[2] = {0, $2.d};			$$.h = getH(2, h); $$.d = getD(2, h, d); }
	| '+' Pexpr															{ int h[2] = {0, $2.h}; int d[2] = {0, $2.d};			$$.h = getH(2, h); $$.d = getD(2, h, d); }
	| '*' Pexpr															{ int h[2] = {0, $2.h}; int d[2] = {0, $2.d};			$$.h = getH(2, h); $$.d = getD(2, h, d); }
	| '&' Pexpr															{ int h[2] = {0, $2.h}; int d[2] = {0, $2.d};			$$.h = getH(2, h); $$.d = getD(2, h, d); }
	| Pexpr																{ int h[1] = {$1.h}; int d[1] = {$1.d};			$$.h = getH(1, h); $$.d = getD(1, h, d); }
	| identifier '(' args ')'											{ int h[4] = {$1.h, 0, $3.h, 0}; int d[4] = {$1.d, 0, $3.d, 0};			$$.h = getH(4, h); $$.d = getD(4, h, d); }
	| identifier '[' expr ']'											{ int h[4] = {$1.h, 0, $3.h, 0}; int d[4] = {$1.d, 0, $3.d, 0};			$$.h = getH(4, h); $$.d = getD(4, h, d); }
;

Pexpr: integerLit														{ int h[1] = {$1.h}; int d[1] = {$1.d};			$$.h = getH(1, h); $$.d = getD(1, h, d); }
	| floatLit															{ int h[1] = {$1.h}; int d[1] = {$1.d};			$$.h = getH(1, h); $$.d = getD(1, h, d); }
	| identifier														{ int h[1] = {$1.h}; int d[1] = {$1.d};			$$.h = getH(1, h); $$.d = getD(1, h, d); }
	| '(' expr ')'														{ int h[3] = {0, $2.h, 0}; int d[3] = {0, $2.d, 0};			$$.h = getH(3, h); $$.d = getD(3, h, d); }
;

integerLit: NUMBER														{ int h[1] = {0}; int d[1] = {0};			$$.h = getH(1, h); $$.d = getD(1, h, d); }
;

floatLit: REALNUMBER													{ int h[1] = {0}; int d[1] = {0};			$$.h = getH(1, h); $$.d = getD(1, h, d); }
;

identifier: IDENTIFIER													{ int h[1] = {0}; int d[1] = {0};			$$.h = getH(1, h); $$.d = getD(1, h, d); }
;

arg_list: arg_list ',' expr												{ int h[3] = {$1.h, 0, $3.h}; int d[3] = {$1.d, 0, $3.d};			$$.h = getH(3, h); $$.d = getD(3, h, d); }
	| expr																{ int h[1] = {$1.h}; int d[1] = {$1.d};			$$.h = getH(1, h); $$.d = getD(1, h, d); }
;

args: arg_list															{ int h[1] = {$1.h}; int d[1] = {$1.d};			$$.h = getH(1, h); $$.d = getD(1, h, d); }
	| epsilon															{ int h[1] = {0}; int d[1] = {0};			$$.h = getH(1, h); $$.d = getD(1, h, d); }
;

epsilon:																{ $$.h = 0; $$.d = 0; }
;
%%

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

