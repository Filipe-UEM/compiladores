CC = g++
FLEX = flex

all: lexer

lexer: lex.yy.o yylval.o
	$(CC) -o $@ $^ -lfl

lex.yy.c: lexer.l
	$(FLEX) -o $@ $<

lex.yy.o: lex.yy.c tokens.h
	$(CC) -c -o $@ $<

yylval.o: yylval.cpp tokens.h
	$(CC) -c -o $@ $<

clean:
	rm -f lex.yy.c *.o lexer