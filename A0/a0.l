%{
	#include <stdlib.h>
	#include "y.tab.h"
	void yyerror(char *);
	extern char mytext[];
%}

%%

// REGEX RULES

%%

int yywrap(void) {
    return 1;
}


