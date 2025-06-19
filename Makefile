ANTLR_JAR=antlr-4.13.1-complete.jar
GRAMMAR=MinhaLinguagem.g4
TARGET=parser

all: $(TARGET)

generate:
	java -jar $(ANTLR_JAR) -Dlanguage=Cpp -visitor -no-listener $(GRAMMAR)

$(TARGET): generate
	g++ -std=c++17 -I. -I./antlr4-runtime \
		MinhaLinguagem*.cpp \
		src/main.cpp \
		-L/usr/local/lib -lantlr4-runtime -o $(TARGET)

clean:
	rm -f MinhaLinguagem*.cpp MinhaLinguagem*.h *.interp *.tokens
	rm -f $(TARGET)

run: $(TARGET)
	LD_LIBRARY_PATH=/usr/local/lib ./$(TARGET) exemplos/teste.txt