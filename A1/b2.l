%{
	#include <stdlib.h>
	#include "y.tab.h"
	void yyerror(char *);
	extern char mytext[];
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

int                         { return INT; }
long                        { return LONG; }
short                       { return SHORT; }
float                       { return FLOAT; }
double                      { return DOUBLE; }
void                        { return VOID; }
char                        { return CHAR; }

[a-zA-Z_][a-zA-Z_0-9]*      { return IDENTIFIER; }

\*+                         { return DEREF; }
\&                          { return ADDRESSOF; }
(<|>|==|<=|>=|!=|<=>)       { return RELATIONALOP; }
(\+|\-|\*|\/|\&|\||\^|\%)   { return BINARYARIOP; }
(\+|\-|\!|\*|\&|\~)         { return UNARYOP; }
(\&\&|\|\|)                 { return LOGICALOP; }
(\+\+|\-\-)                 { return CREMENTOP; }
=                           { return EQ; }
(\.|->)                     { return STRUCTFIELDACCESSOP; }

\'(\\)?[a-zA-Z0-9]\'        { return CHARACTER; }
([0-9]+|0x[0-9a-fA-F]+)     { return NUMBER; }
([0-9]+\.[0-9]*|\.[0-9]+)   { return REALNUMBER; }
\".*\"                      { return STRING; }

[\;\(\)\[\]\{\}\:\,]        { return yytext[0]; }

\/\/.*
\/\*(.|\n)*\*\/


\n	|
.	;
%%

int yywrap(void) {
    return 1;
}


