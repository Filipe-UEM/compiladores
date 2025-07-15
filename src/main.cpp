#include <iostream>
#include <fstream>
#include <vector>
#include "antlr4-runtime.h"
#include "MinhaLinguagemLexer.h"
#include "MinhaLinguagemParser.h"
#include "SemanticoVisitor.h"
#include "ColetorClasses.h"
// Add this include
#include "MinhaLinguagemBaseListener.h"

using namespace antlr4;

class SyntaxErrorListener : public antlr4::BaseErrorListener {
public:
    void syntaxError(
        antlr4::Recognizer *recognizer,
        antlr4::Token *offendingSymbol,
        size_t line, size_t charPositionInLine,
        const std::string &msg, std::exception_ptr e
    ) override {
        std::cerr << "[SINTAXE] Linha " << line << ":" << charPositionInLine
                  << " - " << msg << std::endl;
    }
};

class SimpleTreeListener : public MinhaLinguagemBaseListener {
public:
    void enterEveryRule(antlr4::ParserRuleContext *ctx) override {
        std::cout << ctx->getText() << std::endl;
    }
};

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Uso: " << argv[0] << " <arquivos>\n";
        return 1;
    }

    TabelaSimbolos tabelaGlobal;
    std::vector<std::string> errosTotais;
    SyntaxErrorListener errorListener; // Movido para cá
    
    // 1ª Passagem: Coletar classes
    for (int i = 1; i < argc; ++i) {
        std::ifstream stream(argv[i]);
        if (!stream.is_open()) {
            std::cerr << "Erro ao abrir: " << argv[i] << std::endl;
            continue;
        }
        
        ANTLRInputStream input(stream);
        MinhaLinguagemLexer lexer(&input);
        CommonTokenStream tokens(&lexer);
        MinhaLinguagemParser parser(&tokens);
        
        parser.removeErrorListeners();
        parser.addErrorListener(&errorListener); // Usando nosso listener
        
        MinhaLinguagemParser::ProgramaContext* tree = parser.programa();

        // Imprimir árvore sintática
        SimpleTreeListener listener;
        antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, tree);

        if (parser.getNumberOfSyntaxErrors() > 0) {
            std::cerr << "[FALHA] Erros sintáticos em " << argv[i] << "\n";
            return 1;
        }
        
        ColetorClasses coletor(tabelaGlobal);
        coletor.visitPrograma(tree);
    }

    // 2ª Passagem: Análise semântica
    for (int i = 1; i < argc; ++i) {
        std::ifstream stream(argv[i]);
        if (!stream.is_open()) continue;
        
        ANTLRInputStream input(stream);
        MinhaLinguagemLexer lexer(&input);
        CommonTokenStream tokens(&lexer);
        MinhaLinguagemParser parser(&tokens);
        
        parser.removeErrorListeners();
        parser.addErrorListener(&errorListener); // Usando nosso listener
        
        MinhaLinguagemParser::ProgramaContext* tree = parser.programa();

        // Imprimir árvore sintática novamente
        SimpleTreeListener listener;
        antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, tree);

        if (parser.getNumberOfSyntaxErrors() == 0) {
            SemanticoVisitor semantico(tabelaGlobal);
            semantico.visitPrograma(tree);
            
            for (const auto& erro : semantico.getErros()) {
                errosTotais.push_back(erro);
            }
        }
    }

    // Reportar erros
    for (const auto& erro : errosTotais) {
        std::cerr << erro << std::endl;
    }

    if (!errosTotais.empty()) {
        std::cerr << "\n[FALHA] " << errosTotais.size() << " erros\n";
        return 1;
    }

    std::cout << "[SUCESSO] Programa correto!\n";
    return 0;
}