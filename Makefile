ANTLR_JAR = antlr-4.13.1-complete.jar
GRAMMAR = MinhaLinguagem.g4
TARGET = compilador
SRC_DIR = src

ANTLR_CMD = java -jar $(ANTLR_JAR)
CXX = g++

# Configurações do LLVM
LLVM_CONFIG = llvm-config-15
LLVM_CXXFLAGS := $(filter-out -fno-exceptions, $(shell $(LLVM_CONFIG) --cxxflags))
LLVM_CXXFLAGS += -std=c++17 -fexceptions
LLVM_LDFLAGS := $(shell $(LLVM_CONFIG) --ldflags --libs --system-libs)

CXXFLAGS = -std=c++17 -I. -I$(SRC_DIR) -Iantlr4-runtime -g -O0 -fexceptions \
           -I/usr/lib/llvm-15/include -Wno-attributes \
           -D_GNU_SOURCE -D__STDC_CONSTANT_MACROS \
           -D__STDC_FORMAT_MACROS -D__STDC_LIMIT_MACROS

CXXFLAGS += $(LLVM_CXXFLAGS)

LDFLAGS = $(LLVM_LDFLAGS) -L/usr/local/lib -lantlr4-runtime

# Adicione arquivos Listener
GENERATED_CPP = MinhaLinguagemLexer.cpp MinhaLinguagemParser.cpp \
                MinhaLinguagemBaseVisitor.cpp MinhaLinguagemVisitor.cpp \
                MinhaLinguagemBaseListener.cpp MinhaLinguagemListener.cpp
GENERATED_H = MinhaLinguagemLexer.h MinhaLinguagemParser.h \
              MinhaLinguagemBaseVisitor.h MinhaLinguagemVisitor.h \
              MinhaLinguagemBaseListener.h MinhaLinguagemListener.h
GENERATED_OBJ = $(GENERATED_CPP:.cpp=.o)

SRC_CPP = $(SRC_DIR)/main.cpp
SRC_OBJ = $(SRC_CPP:.cpp=.o)
OBJ = $(SRC_OBJ) $(GENERATED_OBJ)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $^ $(LDFLAGS) -o $@

# Gere tanto Visitor quanto Listener
$(GENERATED_CPP) $(GENERATED_H): $(GRAMMAR)
	$(ANTLR_CMD) -Dlanguage=Cpp -visitor -listener $<

$(SRC_OBJ): $(SRC_CPP) $(GENERATED_H)
	$(CXX) $(CXXFLAGS) -c $< -o $@

%.o: %.cpp $(GENERATED_H)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(GENERATED_CPP) $(GENERATED_H) *.tokens *.interp $(TARGET)
	rm -f *.o $(SRC_OBJ)