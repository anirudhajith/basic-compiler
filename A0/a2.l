%{
	#include <stdlib.h>
	#include "y.tab.h"
	void yyerror(char *);
	extern char mytext[];
%}

%%

int		{ printf("Lex type: %s\n", yytext); strcpy(mytext, yytext); return TYPE;}

[a-zA-Z_][a-zA-Z_0-9]*	{ printf("Lex var: %s\n", yytext); strcpy(mytext, yytext); return VARIABLE; }

=		{ printf("Lex eq: =\n"); return EQ; }

[0-9]+		{ printf("Lex number: %s\n", yytext); strcpy(mytext, yytext); return NUMBER; }


\n	|
.	;
%%

int yywrap(void) {
    return 1;
}


