ANTLR_JAR = antlr-4.13.1-complete.jar
GRAMATICA = gramatica.g4
GERADOS = gramaticaLexer.cpp gramaticaParser.cpp gramaticaBaseVisitor.cpp gramaticaBaseListener.cpp
HEADERS = gramaticaLexer.h gramaticaParser.h gramaticaBaseVisitor.h gramaticaBaseListener.h

all: parser

parser: $(GERADOS) $(HEADERS) src/main.cpp src/MeuVisitor.h
	g++ -std=c++17 -I src -I. $(GERADOS) src/main.cpp -lantlr4-runtime -o parser

$(GERADOS) $(HEADERS): $(GRAMATICA) $(ANTLR_JAR)
	java -jar $(ANTLR_JAR) -Dlanguage=Cpp -visitor -no-listener $(GRAMATICA)

run: parser
	./parser exemplos/teste.txt

clean:
	rm -f $(GERADOS) $(HEADERS) *.tokens *.interp parser ast.txt