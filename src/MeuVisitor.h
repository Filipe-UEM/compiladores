#include "gramaticaBaseVisitor.h"
#include <iostream>
#include <string>
#include <vector>

class MeuVisitor : public gramaticaBaseVisitor {
private:
    int nivel = 0;
    
    void printIndent() {
        for (int i = 0; i < nivel; i++) {
            std::cout << "  ";
        }
    }

public:
    // Visita o nó raiz do programa
    antlrcpp::Any visitPrograma(gramaticaParser::ProgramaContext *ctx) override {
        std::cout << "PROGRAMA\n";
        nivel++;
        visitChildren(ctx);
        nivel--;
        return nullptr;
    }
    
    // Declaração de classe
    antlrcpp::Any visitDeclaracao_classe(gramaticaParser::Declaracao_classeContext *ctx) override {
        printIndent();
        std::cout << "CLASSE: " << ctx->ID->getText() << "\n";
        nivel++;
        visitChildren(ctx);
        nivel--;
        return nullptr;
    }
    
    // Membro de classe
    antlrcpp::Any visitMembro(gramaticaParser::MembroContext *ctx) override {
        printIndent();
        std::cout << "MEMBRO\n";
        nivel++;
        visitChildren(ctx);
        nivel--;
        return nullptr;
    }
    
    // Declaração de função
    antlrcpp::Any visitDeclaracao_funcao(gramaticaParser::Declaracao_funcaoContext *ctx) override {
        printIndent();
        std::cout << "FUNÇÃO: " << ctx->ID->getText() 
                  << " (Tipo: " << ctx->tipo()->getText() << ")\n";
        nivel++;
        visitChildren(ctx);
        nivel--;
        return nullptr;
    }
    
    // Parâmetros de função
    antlrcpp::Any visitParametros(gramaticaParser::ParametrosContext *ctx) override {
        printIndent();
        std::cout << "PARÂMETROS (" << ctx->parametro().size() << ")\n";
        nivel++;
        visitChildren(ctx);
        nivel--;
        return nullptr;
    }
    
    // Parâmetro individual
    antlrcpp::Any visitParametro(gramaticaParser::ParametroContext *ctx) override {
        printIndent();
        std::cout << "PARÂMETRO: " << ctx->ID->getText()
                  << " (Tipo: " << ctx->tipo()->getText() << ")\n";
        return nullptr;
    }
    
    // Declaração de variável
    antlrcpp::Any visitDeclaracao_variavel(gramaticaParser::Declaracao_variavelContext *ctx) override {
        printIndent();
        std::cout << "VARIÁVEL: " << ctx->ID->getText()
                  << " (Tipo: " << ctx->tipo()->getText() << ")";
        
        if (ctx->expressao()) {
            std::cout << " com inicialização";
        }
        std::cout << "\n";
        return nullptr;
    }
    
    // Bloco de código
    antlrcpp::Any visitBloco(gramaticaParser::BlocoContext *ctx) override {
        printIndent();
        std::cout << "BLOCO (" << ctx->declaracao().size() << " declarações)\n";
        nivel++;
        visitChildren(ctx);
        nivel--;
        return nullptr;
    }
    
    // Estrutura de controle: IF
    antlrcpp::Any visitIf(gramaticaParser::IfContext *ctx) override {
        printIndent();
        std::cout << "IF\n";
        nivel++;
        
        printIndent();
        std::cout << "CONDIÇÃO:\n";
        nivel++;
        visit(ctx->expressao());
        nivel--;
        
        printIndent();
        std::cout << "BLOCO IF:\n";
        nivel++;
        visit(ctx->declaracao(0));
        nivel--;
        
        if (ctx->declaracao().size() > 1) {
            printIndent();
            std::cout << "BLOCO ELSE:\n";
            nivel++;
            visit(ctx->declaracao(1));
            nivel--;
        }
        
        nivel--;
        return nullptr;
    }
    
    // Estrutura de controle: WHILE
    antlrcpp::Any visitWhile(gramaticaParser::WhileContext *ctx) override {
        printIndent();
        std::cout << "WHILE\n";
        nivel++;
        
        printIndent();
        std::cout << "CONDIÇÃO:\n";
        nivel++;
        visit(ctx->expressao());
        nivel--;
        
        printIndent();
        std::cout << "CORPO:\n";
        nivel++;
        visit(ctx->declaracao());
        nivel--;
        
        nivel--;
        return nullptr;
    }
    
    // Expressão: atribuição
    antlrcpp::Any visitAtribuicao(gramaticaParser::AtribuicaoContext *ctx) override {
        printIndent();
        std::cout << "ATRIBUIÇÃO: " << ctx->IDENTIFICADOR()->getText() << "\n";
        nivel++;
        visit(ctx->expressao());
        nivel--;
        return nullptr;
    }
    
    // Expressão: binária
    antlrcpp::Any visitBinaria(gramaticaParser::BinariaContext *ctx) override {
        printIndent();
        std::cout << "OPERAÇÃO: " << ctx->op->getText() << "\n";
        nivel++;
        visit(ctx->expressao(0));
        visit(ctx->expressao(1));
        nivel--;
        return nullptr;
    }
    
    // Expressão: chamada de função
    antlrcpp::Any visitChamadaFuncao(gramaticaParser::ChamadaFuncaoContext *ctx) override {
        printIndent();
        std::cout << "CHAMADA: " << ctx->IDENTIFICADOR()->getText()
                  << " (" << ctx->expressao().size() << " argumentos)\n";
        nivel++;
        for (auto expr : ctx->expressao()) {
            visit(expr);
        }
        nivel--;
        return nullptr;
    }
    
    // Expressão: variável
    antlrcpp::Any visitVariavel(gramaticaParser::VariavelContext *ctx) override {
        printIndent();
        std::cout << "VARIÁVEL: " << ctx->IDENTIFICADOR()->getText() << "\n";
        return nullptr;
    }
    
    // Expressão: literal inteiro
    antlrcpp::Any visitInteiro(gramaticaParser::InteiroContext *ctx) override {
        printIndent();
        std::cout << "INTEIRO: " << ctx->NUM_INT()->getText() << "\n";
        return nullptr;
    }
    
    // Expressão: literal float
    antlrcpp::Any visitFloat(gramaticaParser::FloatContext *ctx) override {
        printIndent();
        std::cout << "FLOAT: " << ctx->NUM_FLOAT()->getText() << "\n";
        return nullptr;
    }
    
    // Expressão: literal string
    antlrcpp::Any visitString(gramaticaParser::StringContext *ctx) override {
        printIndent();
        std::cout << "STRING: " << ctx->TEXTO()->getText() << "\n";
        return nullptr;
    }
    
    // Expressão: return
    antlrcpp::Any visitReturn(gramaticaParser::ReturnContext *ctx) override {
        printIndent();
        std::cout << "RETURN";
        if (ctx->expressao()) {
            std::cout << " com expressão\n";
            nivel++;
            visit(ctx->expressao());
            nivel--;
        } else {
            std::cout << "\n";
        }
        return nullptr;
    }
};