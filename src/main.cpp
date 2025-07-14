#include <iostream>
#include <fstream>
#include <vector>
#include "antlr4-runtime.h"
#include "MinhaLinguagemLexer.h"
#include "MinhaLinguagemParser.h"
#include "SemanticoVisitor.h"
#include "ColetorClasses.h"

using namespace antlr4;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Uso: " << argv[0] << " <arquivos>\n";
        return 1;
    }

    TabelaSimbolos tabelaGlobal;
    std::vector<std::string> errosTotais;
    
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
        parser.addErrorListener(new antlr4::BaseErrorListener());
        
        MinhaLinguagemParser::ProgramaContext* tree = parser.programa();
        
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
        parser.addErrorListener(new BaseErrorListener());
        
        MinhaLinguagemParser::ProgramaContext* tree = parser.programa();
        
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