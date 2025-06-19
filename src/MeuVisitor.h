#include "MinhaLinguagemBaseVisitor.h"  // Nome correto do header
#include <iostream>
#include <string>
#include <vector>

class MeuVisitor : public MinhaLinguagemBaseVisitor {  // Corrigir a classe base
private:
    int nivel = 0;
    
    void printIndent() {
        for (int i = 0; i < nivel; i++) {
            std::cout << "  ";
        }
    }

public:
    // Corrigir todos os contextos para MinhaLinguagemParser::
    antlrcpp::Any visitPrograma(MinhaLinguagemParser::ProgramaContext *ctx) override {
        std::cout << "PROGRAMA\n";
        nivel++;
        visitChildren(ctx);
        nivel--;
        return nullptr;
    }
    
    // Declaração de classe
    antlrcpp::Any visitDeclaracao_classe(MinhaLinguagemParser::Declaracao_classeContext *ctx) override {
        printIndent();
        std::cout << "CLASSE: " << ctx->ID->getText() << "\n";
        nivel++;
        visitChildren(ctx);
        nivel--;
        return nullptr;
    }
    
    // Membro de classe
    antlrcpp::Any visitMembro(MinhaLinguagemParser::MembroContext *ctx) override {
        printIndent();
        std::cout << "MEMBRO\n";
        nivel++;
        visitChildren(ctx);
        nivel--;
        return nullptr;
    }
    
    // Declaração de função
    antlrcpp::Any visitDeclaracao_funcao(MinhaLinguagemParser::Declaracao_funcaoContext *ctx) override {
        printIndent();
        std::cout << "FUNÇÃO: " << ctx->ID->getText() 
                  << " (Tipo: " << ctx->tipo()->getText() << ")\n";
        nivel++;
        visitChildren(ctx);
        nivel--;
        return nullptr;
    }
    
    // Parâmetros de função
    antlrcpp::Any visitParametros(MinhaLinguagemParser::ParametrosContext *ctx) override {
        printIndent();
        std::cout << "PARÂMETROS (" << ctx->parametro().size() << ")\n";
        nivel++;
        visitChildren(ctx);
        nivel--;
        return nullptr;
    }
    
    // Parâmetro individual
    antlrcpp::Any visitParametro(MinhaLinguagemParser::ParametroContext *ctx) override {
        printIndent();
        std::cout << "PARÂMETRO: " << ctx->ID->getText()
                  << " (Tipo: " << ctx->tipo()->getText() << ")\n";
        return nullptr;
    }
    
    // Declaração de variável
    antlrcpp::Any visitDeclaracao_variavel(MinhaLinguagemParser::Declaracao_variavelContext *ctx) override {
        printIndent();
        std::cout << "VARIÁVEL: " << ctx->ID->getText();
        
        // Verificar se é vetor
        if (ctx->getToken(MinhaLinguagemParser::ABRE_COLCHETES, 0) != nullptr) {
            std::cout << " (VETOR)";
        }
        
        std::cout << " (Tipo: " << ctx->tipo()->getText() << ")";
        
        // Verificar se há inicialização
        if (ctx->ATRIBUICAO() != nullptr) {
            std::cout << " com inicialização";
        }
        std::cout << "\n";
        
        // Se houver expressões (tamanho ou valor), visitá-las
        if (!ctx->expressao().empty()) {
            nivel++;
            for (auto expr : ctx->expressao()) {
                visit(expr);
            }
            nivel--;
        }
        return nullptr;
    }
    
    // Bloco de código
    antlrcpp::Any visitBloco(MinhaLinguagemParser::BlocoContext *ctx) override {
        printIndent();
        std::cout << "BLOCO (" << ctx->declaracao().size() << " declarações)\n";
        nivel++;
        visitChildren(ctx);
        nivel--;
        return nullptr;
    }
    
    // Estrutura de controle: IF
    antlrcpp::Any visitIf(MinhaLinguagemParser::IfContext *ctx) override {
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
        visit(ctx->bloco(0));
        nivel--;
        
        if (ctx->bloco().size() > 1) {
            printIndent();
            std::cout << "BLOCO ELSE:\n";
            nivel++;
            visit(ctx->bloco(1));
            nivel--;
        }
        
        nivel--;
        return nullptr;
    }
    
    // Estrutura de controle: WHILE
    antlrcpp::Any visitWhile(MinhaLinguagemParser::WhileContext *ctx) override {
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
        visit(ctx->bloco());
        nivel--;
        
        nivel--;
        return nullptr;
    }

    antlrcpp::Any visitFor(MinhaLinguagemParser::ForContext *ctx) override {
        printIndent();
        std::cout << "FOR\n";
        nivel++;
        
        printIndent();
        std::cout << "INICIALIZAÇÃO:\n";
        nivel++;
        visit(ctx->declaracao_variavel());
        nivel--;
        
        printIndent();
        std::cout << "CONDIÇÃO:\n";
        nivel++;
        visit(ctx->expressao(0));
        nivel--;
        
        printIndent();
        std::cout << "INCREMENTO:\n";
        nivel++;
        visit(ctx->expressao(1));
        nivel--;
        
        printIndent();
        std::cout << "CORPO:\n";
        nivel++;
        visit(ctx->bloco());
        nivel--;
        
        nivel--;
        return nullptr;
    }

    // New
    antlrcpp::Any visitNew(MinhaLinguagemParser::NewContext *ctx) override {
        printIndent();
        std::cout << "NEW: " << ctx->tipo()->getText();
        
        if (ctx->expressao()) {  // Verifica se há expressão (tamanho)
            std::cout << " com tamanho\n";
            nivel++;
            visit(ctx->expressao());  // Visita apenas a expressão do tamanho
            nivel--;
        } else {
            std::cout << "\n";
        }
        return nullptr;
    }
    
    // Expressão: atribuição
    antlrcpp::Any visitAtribuicao(MinhaLinguagemParser::AtribuicaoContext *ctx) override {
        printIndent();
        std::cout << "ATRIBUIÇÃO: " << ctx->IDENTIFICADOR()->getText() << "\n";
        nivel++;
        visit(ctx->expressao());
        nivel--;
        return nullptr;
    }
    
    // Expressão: binária
    antlrcpp::Any visitBinaria(MinhaLinguagemParser::BinariaContext *ctx) override {
        printIndent();
        std::cout << "OPERAÇÃO: " << ctx->op->getText() << "\n";
        nivel++;
        visit(ctx->expressao(0));
        visit(ctx->expressao(1));
        nivel--;
        return nullptr;
    }
    
    // Expressão: chamada de função
    antlrcpp::Any visitChamadaFuncao(MinhaLinguagemParser::ChamadaFuncaoContext *ctx) override {
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
    antlrcpp::Any visitVariavel(MinhaLinguagemParser::VariavelContext *ctx) override {
        printIndent();
        std::cout << "VARIÁVEL: " << ctx->IDENTIFICADOR()->getText() << "\n";
        return nullptr;
    }
    
    // Expressão: literal inteiro
    antlrcpp::Any visitInteiro(MinhaLinguagemParser::InteiroContext *ctx) override {
        printIndent();
        std::cout << "INTEIRO: " << ctx->NUM_INT()->getText() << "\n";
        return nullptr;
    }
    
    // Expressão: literal float
    antlrcpp::Any visitFloat(MinhaLinguagemParser::FloatContext *ctx) override {
        printIndent();
        std::cout << "FLOAT: " << ctx->NUM_FLOAT()->getText() << "\n";
        return nullptr;
    }
    
    // Expressão: literal string
    antlrcpp::Any visitString(MinhaLinguagemParser::StringContext *ctx) override {
        printIndent();
        std::cout << "STRING: " << ctx->TEXTO()->getText() << "\n";
        return nullptr;
    }
    
    antlrcpp::Any visitAcessoVetor(MinhaLinguagemParser::AcessoVetorContext *ctx) override {
        printIndent();
        std::cout << "ACESSO VETOR: " << ctx->IDENTIFICADOR()->getText() << "\n";
        nivel++;
        visit(ctx->expressao()); // índice
        nivel--;
        return nullptr;
    }


    // Expressão: return
    // antlrcpp::Any visitReturn(MinhaLinguagemParser::ReturnContext *ctx) override {
    //     printIndent();
    //     std::cout << "RETURN";
    //     if (ctx->expressao()) {
    //         std::cout << " com expressão\n";
    //         nivel++;
    //         visit(ctx->expressao());
    //         nivel--;
    //     } else {
    //         std::cout << "\n";
    //     }
    //     return nullptr;
    // }

};