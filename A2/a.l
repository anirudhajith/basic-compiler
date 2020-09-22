%{
	#include <stdlib.h>
	#include <string.h>
	#include "y.tab.h"
	void yyerror(char *);
	extern int yylineno;
	extern int mainDetected;
	extern char mytext[];
	char mainString[] = "main";
%}

%%

    // keywords
if                          { return IF; }
else                        { return ELSE; }
while                       { return WHILE; }
do                          { return DO; }
for                         { return FOR; }
switch                      { return SWITCH; }
case                        { return CASE; }
default                     { return DEFAULT; }
extern                      { return EXTERN; }
struct                      { return STRUCT; }
break                       { return BREAK; }
continue                    { return CONTINUE; }
return                      { return RETURN; }
sizeof                      { return SIZEOF; }
printf						{ return PRINTF; }

int                         { return INT; }
long                        { return LONG; }
short                       { return SHORT; }
float                       { return FLOAT; }
double                      { return DOUBLE; }
void                        { return VOID; }
char                        { return CHAR; }

[a-zA-Z_][a-zA-Z_0-9]*      { mainDetected = strcmp(yytext, mainString); return IDENTIFIER; }

\n							{ yylineno++; }
\"\%d\"						{ return PERCENTD; }
\<\=\>						{ return THREEWAYCOMP; }
\+\+						{ return INCR; }
\-\-						{ return DECR; }
\|\|						{ return LOGICALOR; }
\&\&						{ return LOGICALAND; }
\-\>						{ return POINTERMEMBER; }
\=\=						{ return EQEQ; }
\!\=						{ return NOTEQ; }
\<\=						{ return LESSEREQ; }
\>\=						{ return GREATEREQ; }
(\{|\}|\;|\[|\]|\,|\*|\(|\)|\=|\:|\<|\>|\%|\!|\+|\-|\/|\&|\.) { return yytext[0]; }

([0-9]+|0x[0-9a-fA-F]+)     { return NUMBER; }
([0-9]+\.[0-9]*|\.[0-9]+)   { return REALNUMBER; }


\/\/.*						;
\/\*(.|\n)*\*\/				;
.							;
%%

int yywrap(void) {
    return 1;
}


