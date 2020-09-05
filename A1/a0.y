%token TYPE VARIABLE EQ NUMBER
%{
	#include <stdio.h>
	void yyerror(char *);
	int yylex(void);
	char mytext[100];
%}

%%

// CFG RULES

%%

void yyerror(char *s) {
    fprintf(stderr, "%s\n", s);
}

int main(void) {
    yyparse();
    return 0;
}

