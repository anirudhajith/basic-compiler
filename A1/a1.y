%token TYPE VARIABLE EQ NUMBER
%{
	#include <stdio.h>
	void yyerror(char *);
	int yylex(void);
	char mytext[100];
%}

%%
program: lines;

lines: oneline {
		printf("lines: oneline\n");
    	}
	| oneline lines {
		printf("lines: oneline lines\n");
	}
;

oneline: TYPE VARIABLE EQ NUMBER ';' {
		printf("oneline\n");
	}
;

%%

void yyerror(char *s) {
    fprintf(stderr, "%s\n", s);
}

int main(void) {
    yyparse();
    return 0;
}

