BISON = bison
CXX = g++
FLEX = flex
CXXFLAGS = -std=c++14 -Wall

all: parser

parser: parser.tab.o lex.yy.o
	$(CXX) $(CXXFLAGS) -o $@ $^ -lfl

parser.tab.c: parser.y
	$(BISON) -d -o $@ $<

lex.yy.c: ../analisador-lexico/lexer.l
	$(FLEX) -o $@ $<

%.o: %.c
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f *.o parser.tab.* lex.yy.c parser