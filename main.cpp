#include "tokens.h"
#include <FlexLexer.h>
#include <iostream>
#include <iomanip>
#include <vector>

// Protótipo necessário
extern YYSTYPE yylval;

// Nomes amigáveis para os tokens
const char* token_names[] = {
    "INT", "FLOAT", "CHAR", "STRING",
    "IF", "ELSE", "FOR", "WHILE",
    "CLASS", "RETURN", "PRINT",
    "[", "]", "=", ">", "<", ".", ";", "(", ")", "{", "}", ",",
    "+", "-", "*", "/",
    "ID", "INT_LIT", "FLOAT_LIT", "CHAR_LIT", "STRING_LIT",
    "ERRO", "EOF"
};

int main() {
    yyFlexLexer lexer;
    int token;
    int token_count = 0;
    std::vector<std::string> output_lines;
    
    std::cout << "=== ANALISADOR LÉXICO ===" << std::endl;
    std::cout << std::left << std::setw(20) << "LEXEMA" 
              << std::setw(15) << "TOKEN" 
              << "VALOR" << std::endl;
    std::cout << "----------------------------------------" << std::endl;

    while((token = lexer.yylex()) != 0) {
        token_count++;
        std::string token_info = std::string(lexer.YYText());
        token_info += " ";
        token_info += std::to_string(token);
        
        std::string token_value;
        switch(token) {
            case TOK_ID:
            case TOK_STRING_LIT:
                token_value = *yylval.str_val;
                delete yylval.str_val;
                break;
            case TOK_INT_LIT:
                token_value = std::to_string(yylval.int_val);
                break;
            case TOK_FLOAT_LIT:
                token_value = std::to_string(yylval.float_val);
                break;
            case TOK_CHAR_LIT:
                token_value = std::string(1, yylval.char_val);
                break;
            default:
                token_value = "---";
        }
        
        output_lines.push_back(
            std::string(lexer.YYText()) + " | " +
            token_names[token] + " | " +
            token_value
        );
    }
    
    // Imprime todos os tokens formatados
    for (const auto& line : output_lines) {
        std::cout << line << std::endl;
    }
    
    std::cout << "\nTotal de tokens reconhecidos: " << token_count << std::endl;
    return 0;
}