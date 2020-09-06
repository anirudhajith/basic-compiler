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
%}

%%

program: lines;

lines: oneline 
	| lines oneline
;

oneline: statement
	| functiondeclaration
	| functiondefinition
;

statements: statements statement
	| statement
;

statement: ifstatement
	| forstatement
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

block: '{' statements '}'
	| '{' '}'
;

degenerableblock: block
	| statement
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
	| type IDENTIFIER '[' ']'
	| type IDENTIFIER '[' expression ']'
	| type addressof IDENTIFIER '[' ']'
	| type addressof IDENTIFIER '[' expression ']'
;

argumentlist: argumentlist ',' argument
	| argument
;

structmemberlist: structmemberlist ',' structmember
	| structmember
;

structmember: IDENTIFIER
	| IDENTIFIER '[' expression ']'
	| IDENTIFIER '[' ']'
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

ifstatement: IF '(' expression ')' degenerableblock
	| IF '(' expression ')' degenerableblock ELSE degenerableblock
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

type: primarytype deref
	| primarytype
;

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
	| NUMBER
	| REALNUMBER
	| stringlist
;

stringlist: stringlist STRING
	| STRING
;

variable: IDENTIFIER '[' expression ']'
	| IDENTIFIER '[' ']'
	| IDENTIFIER
	| IDENTIFIER STRUCTFIELDACCESSOP variable
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
	| '(' type ')' expression
	| assignment
;


%%

void yyerror(char *s) {
    fprintf(stderr, "%s\n", s);
}

int main(void) {
    yyparse();
	fprintf(stdout, "parsed successfully\n");
    return 0;
}

