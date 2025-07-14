# Configurações atualizadas
ANTLR_JAR = antlr-4.13.1-complete.jar
GRAMMAR = MinhaLinguagem.g4
TARGET = compilador
SRC_DIR = src
EXAMPLES_DIR = exemplos
EXAMPLE = teste.txt

# Comandos
ANTLR_CMD = java -jar $(ANTLR_JAR)
CXX = g++
CXXFLAGS = -std=c++17 -I. -I$(SRC_DIR) -Iantlr4-runtime
LDFLAGS = -L/usr/local/lib -lantlr4-runtime
LIBS = -lantlr4-runtime

# Arquivos gerados pelo ANTLR
GENERATED = MinhaLinguagemLexer.cpp MinhaLinguagemParser.cpp \
            MinhaLinguagemBaseVisitor.cpp MinhaLinguagemVisitor.cpp

# Todos os arquivos fonte
SRC_FILES = $(SRC_DIR)/main.cpp \
            $(GENERATED)

.PHONY: all clean run

all: $(TARGET)

generate: $(GRAMMAR)
	$(ANTLR_CMD) -Dlanguage=Cpp -visitor -no-listener $(GRAMMAR)
	touch $(GENERATED)

$(TARGET): generate $(SRC_FILES)
	$(CXX) $(CXXFLAGS) $(SRC_FILES) $(LDFLAGS) -o $@

run: $(TARGET)
    LD_LIBRARY_PATH=/usr/local/lib ./$(TARGET) $(EXAMPLES_DIR)/Pessoa.txt $(EXAMPLES_DIR)/Estudante.txt $(EXAMPLES_DIR)/Programa.txt

clean:
	rm -f $(GENERATED) *.tokens *.interp $(TARGET) MinhaLinguagem*.h
	find $(SRC_DIR) -name "*.o" -delete