a.out: y.tab.c lex.yy.c
	gcc -O3 lex.yy.c y.tab.c
	@echo "Run the program as ./a.out <input.txt"

y.tab.c: b.y 
	yacc -v -d b.y

lex.yy.c: b.l y.tab.h
	lex b.l

clean:
	@rm lex.yy.c y.tab.h y.tab.c a.out

