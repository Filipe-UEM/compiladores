CC = g++
LEX = flex
CFLAGS = -std=c++11 -Wall
TARGET = lexer
SRC = lexer.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^ -lfl

lexer.cpp: lexer.l
	$(LEX) -o $@ $<

clean:
	rm -f $(TARGET) lexer.cpp

test:
	@echo "int x = 42; if (x > 0) { print(\"Hello\"); }" | ./$(TARGET)

.PHONY: all clean test