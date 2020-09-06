%token IF ELSE WHILE DO FOR SWITCH CASE DEFAULT EXTERN STRUCT BREAK CONTINUE RETURN SIZEOF
%token INT LONG SHORT FLOAT DOUBLE VOID CHAR
%token IDENTIFIER
%token RELATIONALOP LOGICALOP CREMENTOP EQ STRUCTFIELDACCESSOP DEREF ADDRESSOF
%token CHARACTER NUMBER REALNUMBER STRING
%{
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
		//printf("%d %d\n", a, b);
		if (a > b) return a;
		else return b;
	}
%}

%%

program: lines;

lines: oneline 								{ numGlobalDeclarations++; }
	| lines oneline							{ numGlobalDeclarations++; }
;

oneline: variabledeclarationstatement
	| functiondeclaration
	| structdeclarationstatement
	| functiondefinition					{ numFunctionDefinitions++; }
;

statements: statements degenerableblock		{ $$ = max($1, $2); maxHeight = max(maxHeight, $$); }
	| degenerableblock						{ $$ = $1; maxHeight = max(maxHeight, $$); }
;

statement: ifstatement						{ $$ = $1; maxHeight = max(maxHeight, $$); }
	| forstatement							{ $$ = 0; maxHeight = max(maxHeight, $$); }
	| whilestatement						{ $$ = 0; maxHeight = max(maxHeight, $$); }
	| dowhilestatement						{ $$ = 0; maxHeight = max(maxHeight, $$); }
	| switchstatement						{ $$ = 0; maxHeight = max(maxHeight, $$); }
	| returnstatement						{ $$ = 0; maxHeight = max(maxHeight, $$); }
	| functioncallstatement					{ $$ = 0; maxHeight = max(maxHeight, $$); }
	| emptystatement						{ $$ = 0; maxHeight = max(maxHeight, $$); }
	| breakstatement						{ $$ = 0; maxHeight = max(maxHeight, $$); }
	| continuestatement						{ $$ = 0; maxHeight = max(maxHeight, $$); }
	| variabledeclarationstatement			{ $$ = 0; maxHeight = max(maxHeight, $$); }
	| structdeclarationstatement			{ $$ = 0; maxHeight = max(maxHeight, $$); }
	| expressionstatment					{ $$ = 0; maxHeight = max(maxHeight, $$); }
; 

nonifstatement: forstatement
	| whilestatement
	| dowhilestatement
	| switchstatement
	| returnstatement
	| functioncallstatement
	| emptystatement
	| breakstatement
	| continuestatement
	| variabledeclarationstatement
	| structdeclarationstatement
	| expressionstatment
; 

block: '{' statements '}' 			{ $$ = $2; maxHeight = max(maxHeight, $$); }
	| '{' '}'						{ $$ = 0; maxHeight = max(maxHeight, $$); }
;

degenerableblock: block				{ $$ = $1; maxHeight = max(maxHeight, $$); }
	| statement						{ $$ = $1; maxHeight = max(maxHeight, $$); }
;

assignment: value EQ expression ;

declaration: variable | variable EQ expression;
declarationlist: declarationlist ',' declaration
	| declaration
;

case: CASE expression ':' statements
	| CASE expression ':'
;
caselist: case caselist
	| case
	| defaultcase
;
defaultcase: DEFAULT ':' statements
	| DEFAULT ':'
;

expressionlist: expressionlist ',' expression
	| expression
;

argument: type IDENTIFIER
	| type addressof IDENTIFIER
	| type IDENTIFIER arrayindexlist
	| type addressof IDENTIFIER arrayindexlist
;

arrayindexlist: arrayindexlist arrayindex
	| arrayindex
;

arrayindex: '[' ']'
	| '[' expression ']'
;

argumentlist: argumentlist ',' argument
	| argument
;

structmemberlist: structmemberlist ',' structmember
	| structmember
;

structmember: IDENTIFIER
	| IDENTIFIER arrayindexlist
;

functioncall: IDENTIFIER '(' ')'
	| IDENTIFIER '(' expressionlist ')'
;

functiondefinition: type IDENTIFIER '(' argumentlist ')' block
	| type IDENTIFIER '(' ')' block
;

functiondeclaration: type IDENTIFIER '(' argumentlist ')' ';'
	| type IDENTIFIER '('')' ';'
;

ifstatement: IF '(' expression ')' degenerableblock								{ numIfWithoutElse++; $$ = 0; maxHeight = max(maxHeight, $$); }
	| IF '(' expression ')' degenerableblock ELSE nonifstatement				{ $$ = 1; maxHeight = max(maxHeight, $$); }		
	| IF '(' expression ')' degenerableblock ELSE ifstatement					{ $$ = $7 + 1; maxHeight = max(maxHeight, $$); }
	| IF '(' expression ')' degenerableblock ELSE block							{ $$ = $7 + 1; maxHeight = max(maxHeight, $$); }
;
forstatement: FOR '(' expressionlist ';' expressionlist ';' expressionlist ')' degenerableblock
	| FOR '(' expressionlist ';' expressionlist ';' ')' degenerableblock
	| FOR '(' expressionlist ';' ';' expressionlist ')' degenerableblock
	| FOR '(' expressionlist ';' ';' ')' degenerableblock
	| FOR '(' ';' expressionlist ';' expressionlist ')' degenerableblock
	| FOR '(' ';' expressionlist ';' ')' degenerableblock
	| FOR '(' ';'  ';' expressionlist ')' degenerableblock
	| FOR '(' ';' ';' ')' degenerableblock
;
whilestatement: WHILE '(' expression ')' degenerableblock;
dowhilestatement: DO degenerableblock WHILE '(' expression ')' ';';
switchstatement: SWITCH '(' expression ')' '{' caselist '}'
	| SWITCH '(' expression ')' '{' '}'
;

returnstatement: RETURN ';'
	| RETURN expression ';'
;

functioncallstatement: functioncall ';';
emptystatement: ';';
breakstatement: BREAK ';';
continuestatement: CONTINUE ';';
variabledeclarationstatement: type declarationlist ';'
	| EXTERN type declarationlist ';'
;
structdeclarationstatement: structdeclaration ';';
expressionstatment: expressionlist ';';
structdeclaration: STRUCT IDENTIFIER '{' memberdeclaratationlist '}'
	| STRUCT IDENTIFIER '{' '}'
;

memberdeclaratation: type structmemberlist ';'
	| type ';';
memberdeclaratationlist: memberdeclaratationlist memberdeclaratation
	| memberdeclaratation
;

type: primarytype deref								{ numPointerDeclarations++; }
	| primarytype
;

castingtype: primarytype deref;

primarytype: VOID 
	| INT
	| LONG
	| SHORT
	| FLOAT
	| DOUBLE
	| CHAR
	| LONG primarytype
	| SHORT primarytype
	| STRUCT IDENTIFIER
	| structdeclaration
;

binaryop: RELATIONALOP
	| LOGICALOP
	| '+'
	| '-'
	| '*'
	| '/'
	| '&'
	| '|'
	| '^'
	| '%'
;

deref: deref '*'
	| '*';

unaryop:  '+'
	| '-'
	| '!'
	| '*'
	| addressof
	| '~'
;

addressof: '&';

literal: CHARACTER
	| NUMBER									{ numIntegerConstants++; }
	| REALNUMBER
	| stringlist
;

stringlist: stringlist STRING
	| STRING
;

variable: variable arrayindexlist
	| IDENTIFIER
	| variable STRUCTFIELDACCESSOP variable
	| functioncall
;

value: literal
	| variable
	| '(' expression ')'
	| '(' primarytype ')' value
	| CREMENTOP value
	| value CREMENTOP
	| unaryop value
	| sizeof
;

sizeof: SIZEOF '(' type ')'
	| SIZEOF '(' expression ')'
;

expression: value
	| expression binaryop value
	| '(' castingtype ')' expression
	| assignment
;


%%

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

