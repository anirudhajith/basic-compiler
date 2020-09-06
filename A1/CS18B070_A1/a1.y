%token IF ELSE WHILE DO FOR SWITCH CASE DEFAULT EXTERN STRUCT BREAK CONTINUE RETURN SIZEOF
%token INT LONG SHORT FLOAT DOUBLE VOID CHAR
%token IDENTIFIER
%token RELATIONALOP LOGICALOP CREMENTOP EQ STRUCTFIELDACCESSOP DEREF ADDRESSOF
%token CHARACTER NUMBER REALNUMBER STRING
%{
	#include <stdio.h>
	void yyerror(char *);
	int yylex(void);
	extern FILE* yyin; 
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
	| forstatement							{ $$ = $1; maxHeight = max(maxHeight, $$); }
	| whilestatement						{ $$ = $1; maxHeight = max(maxHeight, $$); }
	| dowhilestatement						{ $$ = $1; maxHeight = max(maxHeight, $$); }
	| switchstatement						{ $$ = $1; maxHeight = max(maxHeight, $$); }
	| returnstatement						{ $$ = 0; maxHeight = max(maxHeight, $$); }
	| functioncallstatement					{ $$ = 0; maxHeight = max(maxHeight, $$); }
	| emptystatement						{ $$ = 0; maxHeight = max(maxHeight, $$); }
	| breakstatement						{ $$ = 0; maxHeight = max(maxHeight, $$); }
	| continuestatement						{ $$ = 0; maxHeight = max(maxHeight, $$); }
	| variabledeclarationstatement			{ $$ = 0; maxHeight = max(maxHeight, $$); }
	| structdeclarationstatement			{ $$ = 0; maxHeight = max(maxHeight, $$); }
	| expressionstatment					{ $$ = 0; maxHeight = max(maxHeight, $$); }
; 

nonifstatement: forstatement				{ $$ = $1; maxHeight = max(maxHeight, $$); }
	| whilestatement						{ $$ = $1; maxHeight = max(maxHeight, $$); }
	| dowhilestatement						{ $$ = $1; maxHeight = max(maxHeight, $$); }
	| switchstatement						{ $$ = $1; maxHeight = max(maxHeight, $$); }
	| returnstatement						{ $$ = 0; maxHeight = max(maxHeight, $$); }
	| functioncallstatement					{ $$ = 0; maxHeight = max(maxHeight, $$); }
	| emptystatement						{ $$ = 0; maxHeight = max(maxHeight, $$); }
	| breakstatement						{ $$ = 0; maxHeight = max(maxHeight, $$); }
	| continuestatement 					{ $$ = 0; maxHeight = max(maxHeight, $$); }
	| variabledeclarationstatement 			{ $$ = 0; maxHeight = max(maxHeight, $$); }
	| structdeclarationstatement			{ $$ = 0; maxHeight = max(maxHeight, $$); }
	| expressionstatment					{ $$ = 0; maxHeight = max(maxHeight, $$); }
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

case: CASE expression ':' statements { $$ = $4; maxHeight = max(maxHeight, $$); }
	| CASE expression ':'			 { $$ = 0; maxHeight = max(maxHeight, $$); }
;
caselist: case caselist				{ $$ = max($1, $2); maxHeight = max(maxHeight, $$); }
	| case							{ $$ = $1; maxHeight = max(maxHeight, $$); }
	| defaultcase					{ $$ = $1; maxHeight = max(maxHeight, $$); }
;
defaultcase: DEFAULT ':' statements { $$ = $3; maxHeight = max(maxHeight, $$); }
	| DEFAULT ':'					{ $$ = 0; maxHeight = max(maxHeight, $$); }
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

ifstatement: IF '(' expression ')' degenerableblock								{ numIfWithoutElse++; $$ = $5; maxHeight = max(maxHeight, $$); }
	| IF '(' expression ')' degenerableblock ELSE nonifstatement				{ $$ = max($7 + 1,$5); maxHeight = max(maxHeight, $$); }		
	| IF '(' expression ')' degenerableblock ELSE ifstatement					{ $$ = max($7 + 1,$5); maxHeight = max(maxHeight, $$); }
	| IF '(' expression ')' degenerableblock ELSE block							{ $$ = max($7 + 1,$5); maxHeight = max(maxHeight, $$); }
;

forstatement: FOR '(' expressionlist ';' expressionlist ';' expressionlist ')' degenerableblock { $$ = $9; maxHeight = max(maxHeight, $$); }
	| FOR '(' expressionlist ';' expressionlist ';' ')' degenerableblock						{ $$ = $8; maxHeight = max(maxHeight, $$); }
	| FOR '(' expressionlist ';' ';' expressionlist ')' degenerableblock						{ $$ = $8; maxHeight = max(maxHeight, $$); }
	| FOR '(' expressionlist ';' ';' ')' degenerableblock										{ $$ = $7; maxHeight = max(maxHeight, $$); }
	| FOR '(' ';' expressionlist ';' expressionlist ')' degenerableblock						{ $$ = $8; maxHeight = max(maxHeight, $$); }
	| FOR '(' ';' expressionlist ';' ')' degenerableblock										{ $$ = $7; maxHeight = max(maxHeight, $$); }
	| FOR '(' ';' ';' expressionlist ')' degenerableblock										{ $$ = $7; maxHeight = max(maxHeight, $$); }
	| FOR '(' ';' ';' ')' degenerableblock														{ $$ = $6; maxHeight = max(maxHeight, $$); }
;
whilestatement: WHILE '(' expression ')' degenerableblock										{ $$ = $5; maxHeight = max(maxHeight, $$); };
dowhilestatement: DO degenerableblock WHILE '(' expression ')' ';'								{ $$ = $2; maxHeight = max(maxHeight, $$); };
switchstatement: SWITCH '(' expression ')' '{' caselist '}'										{ $$ = $6; maxHeight = max(maxHeight, $$); }
	| SWITCH '(' expression ')' '{' '}'															{ $$ = 0; maxHeight = max(maxHeight, $$); }
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
    printf("***parsing terminated*** [syntax error]\n");
	error = 1;
}

int main(int argc, char* argv[]) {
	
	FILE *file;
	if (argc != 2) {
		printf("***process terminated*** [input error]: invalid number of command-line arguments\n");
		error = 3;
	} else if (yyin = fopen(argv[1], "r")) {
		yyparse();
		if (error == 0) {
			printf("***parsing successful***\n");
			printf("#global_declarations = %d\n", numGlobalDeclarations);
			printf("#function_definitions = %d\n", numFunctionDefinitions);
			printf("#integer_constants = %d\n", numIntegerConstants);
			printf("#pointers_declarations = %d\n", numPointerDeclarations);
			printf("#ifs_without_else = %d\n", numIfWithoutElse);
			printf("if-else max-depth = %d\n", maxHeight);
		}
		fclose(yyin);
   	} else {
      	printf("***process terminated*** [input error]: no such file %s exists\n", argv[1]);
		error = 3;
   	}

	return error;
}

