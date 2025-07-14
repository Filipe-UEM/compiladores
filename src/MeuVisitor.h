#include "MinhaLinguagemBaseVisitor.h"  // Nome correto do header
#include "TabelaSimbolos.h"
#include <iostream>
#include <string>
#include <vector>

class MeuVisitor : public MinhaLinguagemBaseVisitor {  // Corrigir a classe base
private:
    TabelaSimbolos tabela;
    int nivel = 0;
    std::vector<std::string> errosSemanticos;

    void printIndent() {
        for (int i = 0; i < nivel; i++) std::cout << "  ";
    }

    void reportarErro(antlr4::ParserRuleContext* ctx, const std::string& mensagem) {
        int linha = ctx->getStart()->getLine();
        int coluna = ctx->getStart()->getCharPositionInLine();
        errosSemanticos.push_back(
            "ERRO [" + std::to_string(linha) + ":" + std::to_string(coluna) + "] " + mensagem
        );
    }

    TipoDado stringParaTipo(const std::string& tipoStr) {
        if (tipoStr == "int") return TipoDado::INT;
        if (tipoStr == "float") return TipoDado::FLOAT;
        if (tipoStr == "char") return TipoDado::CHAR;
        if (tipoStr == "string") return TipoDado::STRING;
        if (tipoStr == "void") return TipoDado::VOID;
        return TipoDado::CLASSE;  // Tipos definidos pelo usuário
    }

public:
    const std::vector<std::string>& getErros() const { return errosSemanticos; }

    antlrcpp::Any visitPrograma(MinhaLinguagemParser::ProgramaContext* ctx) override {
        tabela.entrarEscopo();  // Escopo global
        visitChildren(ctx);
        tabela.sairEscopo();
        return nullptr;
    }
    
    // Declaração de classe
    antlrcpp::Any visitDeclaracao_classe(MinhaLinguagemParser::Declaracao_classeContext* ctx) override {
        std::string nomeClasse = ctx->ID->getText();
        
        // Verificar se classe já existe
        if (tabela.buscarNoEscopoAtual(nomeClasse)) {
            reportarErro(ctx, "Classe '" + nomeClasse + "' já declarada");
        } else {
            tabela.inserirSimbolo(Simbolo{
                nomeClasse, 
                TipoDado::CLASSE, 
                Categoria::CLASSE, 
                false, 
                tabela.nivelAtual
            });
        }

        tabela.entrarEscopo();  // Escopo da classe
        visitChildren(ctx);
        tabela.sairEscopo();
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
    antlrcpp::Any visitDeclaracao_funcao(MinhaLinguagemParser::Declaracao_funcaoContext* ctx) override {
        std::string nomeFuncao = ctx->ID->getText();
        TipoDado tipoRetorno = stringParaTipo(ctx->tipo()->getText());
        
        // Coletar tipos dos parâmetros
        std::vector<TipoDado> tiposParam;
        if (ctx->parametros()) {
            for (auto param : ctx->parametros()->parametro()) {
                tiposParam.push_back(stringParaTipo(param->tipo()->getText()));
            }
        }

        // Verificar se função já existe
        if (tabela.buscarNoEscopoAtual(nomeFuncao)) {
            reportarErro(ctx, "Função '" + nomeFuncao + "' já declarada");
        } else {
            tabela.inserirSimbolo(Simbolo{
                nomeFuncao,
                tipoRetorno,
                tiposParam,
                tabela.nivelAtual
            });
        }

        tabela.entrarEscopo();  // Escopo da função
        visitChildren(ctx);
        tabela.sairEscopo();
        return nullptr;
    }
    
    // Parâmetros de função
    antlrcpp::Any visitParametro(MinhaLinguagemParser::ParametroContext* ctx) override {
        std::string nomeParam = ctx->ID->getText();
        TipoDado tipo = stringParaTipo(ctx->tipo()->getText());
        
        if (tabela.buscarNoEscopoAtual(nomeParam)) {
            reportarErro(ctx, "Parâmetro '" + nomeParam + "' já declarado");
        } else {
            tabela.inserirSimbolo(Simbolo{
                nomeParam,
                tipo,
                Categoria::PARAMETRO,
                false,
                tabela.nivelAtual
            });
        }
        return nullptr;
    }
    
    // Declaração de variável
    antlrcpp::Any visitDeclaracao_variavel(MinhaLinguagemParser::Declaracao_variavelContext* ctx) override {
        std::string nomeVar = ctx->ID->getText();
        TipoDado tipo = stringParaTipo(ctx->tipo()->getText());
        bool isVetor = (ctx->ABRE_COLCHETES() != nullptr);
        
        if (tabela.buscarNoEscopoAtual(nomeVar)) {
            reportarErro(ctx, "Variável '" + nomeVar + "' já declarada");
        } else {
            tabela.inserirSimbolo(Simbolo{
                nomeVar,
                tipo,
                Categoria::VARIAVEL,
                isVetor,
                tabela.nivelAtual
            });
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
    antlrcpp::Any visitVariavel(MinhaLinguagemParser::VariavelContext* ctx) override {
        std::string nome = ctx->IDENTIFICADOR()->getText();
        if (!tabela.buscarSimbolo(nome)) {
            reportarErro(ctx, "Variável não declarada: '" + nome + "'");
        }
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
    antlrcpp::Any visitReturnStmt(MinhaLinguagemParser::ReturnContext *ctx) override {
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