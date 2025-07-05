#include <iostream>
#include <fstream>
#include "antlr4-runtime.h"
#include "MinhaLinguagemLexer.h"
#include "MinhaLinguagemParser.h"
#include "MeuVisitor.h"
#include "SemanticVisitor.h"  // Inclua o novo header

using namespace antlr4;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "Uso: " << argv[0] << " <arquivo>\n";
        return 1;
    }

    std::ifstream stream(argv[1]);
    ANTLRInputStream input(stream);
    
    MinhaLinguagemLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    
    MinhaLinguagemParser parser(&tokens);
    MinhaLinguagemParser::ProgramaContext *tree = parser.programa();

    // 1. Imprime a árvore sintática
    std::cout << "Árvore Sintática:\n";
    std::cout << tree->toStringTree(&parser) << std::endl;

    // 2. Executa o visitor de impressão
    std::cout << "\nEstrutura do Programa:\n";
    MeuVisitor visitor;
    visitor.visitPrograma(tree);

    // 3. Executa a análise semântica
    std::cout << "\nAnálise Semântica:\n";
    try {
        SemanticVisitor semanticVisitor;
        semanticVisitor.visitPrograma(tree);
        std::cout << "Análise semântica concluída sem erros.\n";
    } catch (const std::runtime_error& e) {
        std::cerr << "ERRO: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}