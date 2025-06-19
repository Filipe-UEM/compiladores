#include <iostream>
#include <fstream>
#include "antlr4-runtime.h"
#include "MinhaLinguagemLexer.h"
#include "MinhaLinguagemParser.h"
#include "MeuVisitor.h"

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

    // Imprime a árvore sintática
    std::cout << tree->toStringTree(&parser) << std::endl;

    // Executa o visitor
    MeuVisitor visitor;
    visitor.visitPrograma(tree);

    return 0;
}