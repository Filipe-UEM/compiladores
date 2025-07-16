#pragma once

#ifndef SEMANTICOVISITOR_H
#define SEMANTICOVISITOR_H

#include "MinhaLinguagemBaseVisitor.h"
#include "TabelaSimbolos.h"
#include <vector>
#include <string>
#include <set>
#include <unordered_map>


class SemanticoVisitor :
    public MinhaLinguagemBaseVisitor {

private:
    TabelaSimbolos& tabela; 
    TipoDado tipoRetornoAtual = TipoDado::VOID;
    std::vector<std::string> erros;
    std::unordered_map<std::string, std::vector<Simbolo>> membrosClasses;
    std::string classeAtual = "";
    std::string currentClassName = "";
    bool emLoop = false;
    bool emFuncao = false;
    bool emConstrutor = false; 
    bool temReturn = false;
    bool caminhoRetornaValor = false;
    bool caminhoNaoRetorna = false;

    void reportarErro(antlr4::ParserRuleContext* ctx, const std::string& msg) {
        int linha = ctx->getStart()->getLine();
        int coluna = ctx->getStart()->getCharPositionInLine();
        std::string trecho = ctx->getText(); // Trecho do código
        erros.push_back(
            "[SEMÂNTICO] " + std::to_string(linha) + ":" + std::to_string(coluna) + 
            " - " + msg + "\n   Trecho: '" + trecho + "'"
        );
    }

    TipoDado stringParaTipo(const std::string& tipoStr) {
        if (tipoStr == "int") return TipoDado::INT;
        if (tipoStr == "float") return TipoDado::FLOAT;
        if (tipoStr == "char") return TipoDado::CHAR;
        if (tipoStr == "string") return TipoDado::STRING;
        if (tipoStr == "void") return TipoDado::VOID;
        
        // Verificação para vetores
        if (tipoStr.find("int[]") != std::string::npos) return TipoDado::VETOR_INT;
        if (tipoStr.find("float[]") != std::string::npos) return TipoDado::VETOR_FLOAT;
        if (tipoStr.find("char[]") != std::string::npos) return TipoDado::VETOR_CHAR;
        if (tipoStr.find("string[]") != std::string::npos) return TipoDado::VETOR_STRING;
        
        return TipoDado::CLASSE;
    }

    TipoDado converterTipoVetorialParaBase(TipoDado vetorial) {
        switch(vetorial) {
            case TipoDado::VETOR_INT: return TipoDado::INT;
            case TipoDado::VETOR_FLOAT: return TipoDado::FLOAT;
            case TipoDado::VETOR_CHAR: return TipoDado::CHAR;
            case TipoDado::VETOR_STRING: return TipoDado::STRING;
            default: return vetorial;
        }
    }

    std::string tipoParaString(TipoDado tipo) {
        switch(tipo) {
            case TipoDado::INT: return "int";
            case TipoDado::FLOAT: return "float";
            case TipoDado::CHAR: return "char";
            case TipoDado::STRING: return "string";
            case TipoDado::VOID: return "void";
            case TipoDado::POINTER: return "pointer";
            case TipoDado::VETOR_INT: return "int[]";
            case TipoDado::VETOR_FLOAT: return "float[]";
            case TipoDado::VETOR_CHAR: return "char[]";
            case TipoDado::VETOR_STRING: return "string[]";
            case TipoDado::CLASSE: return "classe"; // Simplified
            default: return "invalido";
        }
    }

    bool tiposCompativeis(TipoDado t1, TipoDado t2, bool atribuicao = false) {
        
        // Adicione esta verificação para classes
        if (t1 == TipoDado::CLASSE && t2 == TipoDado::CLASSE) {
            return true;
        }

        // Conversões implícitas permitidas em atribuições
        if (atribuicao) {
            // int → float
            if (t1 == TipoDado::FLOAT && t2 == TipoDado::INT) return true;
            
            // char → string
            if (t1 == TipoDado::STRING && t2 == TipoDado::CHAR) return true;
            
            // Ponteiros (para scanf)
            if (t1 == TipoDado::POINTER && t2 != TipoDado::VOID) return true;
            
            return false;
        }

        // Adicionar conversões numéricas
        if ((t1 == TipoDado::INT || t1 == TipoDado::FLOAT || t1 == TipoDado::CHAR) &&
            (t2 == TipoDado::INT || t2 == TipoDado::FLOAT || t2 == TipoDado::CHAR)) {
            return true;
        }
        
        // Vetores do mesmo tipo
        if (t1 >= TipoDado::VETOR_INT && t1 == t2) {
            return true;
        }
        
        // char → string
        if (t1 == TipoDado::STRING && t2 == TipoDado::CHAR) {
            return true;
        }

        // Conversões implícitas permitidas em operações
        if (t1 == TipoDado::FLOAT && t2 == TipoDado::INT) return true;
        if (t1 == TipoDado::INT && t2 == TipoDado::FLOAT) return true;
        
        // Conversões char/string
        if (t1 == TipoDado::STRING && t2 == TipoDado::CHAR) return true;
        if (t1 == TipoDado::CHAR && t2 == TipoDado::STRING) return true;
        
        // Tipos numéricos em comparações
        if ((t1 == TipoDado::INT || t1 == TipoDado::FLOAT) && 
            (t2 == TipoDado::INT || t2 == TipoDado::FLOAT)) {
            return true;
        }
        
        // Vetores do mesmo tipo base
        if (t1 == TipoDado::VETOR_INT && t2 == TipoDado::VETOR_INT) return true;
        if (t1 == TipoDado::VETOR_FLOAT && t2 == TipoDado::VETOR_FLOAT) return true;
        if (t1 == TipoDado::VETOR_CHAR && t2 == TipoDado::VETOR_CHAR) return true;
        if (t1 == TipoDado::VETOR_STRING && t2 == TipoDado::VETOR_STRING) return true;
        
        return false;
    }

    // Função auxiliar para converter antlrcpp::Any para TipoDado
    TipoDado getTipoComo(antlrcpp::Any any) {
        if (!any.has_value()) 
            return TipoDado::INVALIDO;
        
        try {
            return std::any_cast<TipoDado>(any);
        } catch (const std::bad_any_cast&) {
            return TipoDado::INVALIDO;
        }
    }

    Simbolo* buscarMembroClasseRecursivo(
        const std::string& nomeClasse,
        const std::string& nomeMembro,
        std::set<std::string>& classesVisitadas
    ) {
        if (classesVisitadas.find(nomeClasse) != classesVisitadas.end()) 
            return nullptr;
        
        classesVisitadas.insert(nomeClasse);
        
        // Buscar símbolo da classe na tabela
        Simbolo* classe = tabela.buscarSimbolo(nomeClasse);
        if (!classe) 
            return nullptr;
        
        // Buscar membro na classe atual (incluindo construtores)
        for (auto& membro : classe->membros) {
            // Busca normal de membros
            if (membro.nome == nomeMembro) {
                return &membro;
            }
            
            // Busca especial para construtores
            if (membro.tipo == TipoDado::CONSTRUTOR && 
                membro.nome == nomeClasse && 
                nomeMembro == nomeClasse) {
                return &membro;
            }
        }
        
        // Buscar na superclasse
        if (!classe->nomeSuperClasse.empty()) {
            return buscarMembroClasseRecursivo(
                classe->nomeSuperClasse, 
                nomeMembro, 
                classesVisitadas
            );
        }
        
        return nullptr;
    }

    Simbolo* buscarMembroClasse(const std::string& nomeClasse, const std::string& nomeMembro) {
        std::set<std::string> classesVisitadas;
        return buscarMembroClasseRecursivo(nomeClasse, nomeMembro, classesVisitadas);
    }

    TipoDado converterParaTipoVetorial(TipoDado base) {
        switch(base) {
            case TipoDado::INT: return TipoDado::VETOR_INT;
            case TipoDado::FLOAT: return TipoDado::VETOR_FLOAT;
            case TipoDado::CHAR: return TipoDado::VETOR_CHAR;
            case TipoDado::STRING: return TipoDado::VETOR_STRING;
            default: return base;
        }
    }

public:
    const std::vector<std::string>& getErros() const { return erros; }
    SemanticoVisitor(TabelaSimbolos& tabelaGlobal) : tabela(tabelaGlobal) {}

    antlrcpp::Any visitPrograma(MinhaLinguagemParser::ProgramaContext* ctx) override {
        tabela.entrarEscopo();
        
        // Adicionar funções built-in
        // printf: int printf(string formato, ...)
        std::vector<TipoDado> printfParams = {TipoDado::STRING};
        tabela.inserirSimbolo(Simbolo{
            "printf", 
            TipoDado::INT, 
            printfParams,
            tabela.getNivelAtual()
        });
        
        // scanf: int scanf(string formato, ...)
        std::vector<TipoDado> scanfParams = {TipoDado::STRING};
        tabela.inserirSimbolo(Simbolo{
            "scanf", 
            TipoDado::INT, 
            scanfParams,
            tabela.getNivelAtual()
        });

        tabela.inserirSimbolo(Simbolo{
            "print", 
            TipoDado::VOID, 
            {TipoDado::STRING},
            tabela.getNivelAtual()
        });
    
        visitChildren(ctx);
        tabela.sairEscopo();
        // tabela.imprimirTabela(); 
        return nullptr;
    }

    antlrcpp::Any visitDeclaracao_classe(MinhaLinguagemParser::Declaracao_classeContext* ctx) override {
        std::string className = ctx->ID->getText();
        currentClassName = className;
        std::string superClasse = "";
        
        if (ctx->IDENTIFICADOR().size() > 1) {
            superClasse = ctx->IDENTIFICADOR(1)->getText();
        }

        // Semantic checks only
        if (!superClasse.empty() && !tabela.buscarSimbolo(superClasse)) {
            reportarErro(ctx, "Superclasse não encontrada: " + superClasse);
        }

        // Check for duplicate class
        if (tabela.buscarSimbolo(className)) {
            reportarErro(ctx, "Classe duplicada: " + className);
        } else {
            // Insert class symbol
            Simbolo simboloClasse;
            simboloClasse.nome = className;
            simboloClasse.tipo = TipoDado::CLASSE;
            simboloClasse.categoria = Categoria::CLASSE;
            simboloClasse.nivelEscopo = tabela.getNivelAtual();
            simboloClasse.nomeSuperClasse = superClasse;
            tabela.inserirSimbolo(simboloClasse);
        }

        // Process members
        for (auto membroCtx : ctx->membro()) {
            visit(membroCtx);
        }
        
        currentClassName = "";
        return nullptr;
    }

    antlrcpp::Any visitDeclaracao_funcao(MinhaLinguagemParser::Declaracao_funcaoContext* ctx) override {
        std::string nome = ctx->ID->getText();
        TipoDado tipoRetorno = stringParaTipo(ctx->tipo()->getText());
        // Verificação especial para main
        if (nome == "main" && classeAtual == "Programa") {
            if (tipoRetorno != TipoDado::VOID) {
                reportarErro(ctx, "Função main deve retornar void");
            }
            
            if (ctx->parametros() && !ctx->parametros()->parametro().empty()) {
                reportarErro(ctx, "Função main não deve ter parâmetros");
            }
        }
        
        std::vector<TipoDado> tiposParam;
        if (ctx->parametros()) {
            for (auto param : ctx->parametros()->parametro()) {
                tiposParam.push_back(stringParaTipo(param->tipo()->getText()));
            }
        }

        Simbolo func(
            nome,
            tipoRetorno,
            tiposParam,
            tabela.getNivelAtual()
        );
        func.categoria = Categoria::FUNCAO;

        if (!tabela.inserirSimbolo(func)) {
            reportarErro(ctx, "Função '" + nome + "' já declarada");
        }

        // Resetar estado de verificação de return
        tipoRetornoAtual = tipoRetorno;
        bool estavaEmFuncao = emFuncao;
        bool estavaEmLoop = emLoop;
        emFuncao = true;
        emLoop = false;
        temReturn = false;
        caminhoRetornaValor = false;
        caminhoNaoRetorna = false;

        tabela.entrarEscopo();
        if (ctx->parametros()) {
            visit(ctx->parametros());
        }
        visit(ctx->bloco());
        tabela.sairEscopo();

        // Verificação final de return para a função
        if (emFuncao) {
            if (tipoRetornoAtual != TipoDado::VOID && !temReturn) {
                reportarErro(ctx, "Função não-void '" + nome + "' não tem declaração return");
            }
            
            if (tipoRetornoAtual != TipoDado::VOID && caminhoNaoRetorna) {
                reportarErro(ctx, "Função não-void '" + nome + "' tem caminho que não retorna valor");
            }
        }

        // Restaurar estado anterior
        emFuncao = estavaEmFuncao;
        emLoop = estavaEmLoop;
        return nullptr;
    }


    antlrcpp::Any visitParametro(MinhaLinguagemParser::ParametroContext* ctx) override {
        std::string nome = ctx->ID->getText();
        TipoDado tipo = stringParaTipo(ctx->tipo()->getText());
        
        if (!tabela.inserirSimbolo(Simbolo{
            nome, tipo, Categoria::PARAMETRO, false, tabela.getNivelAtual()
        })) {
            reportarErro(ctx, "Parâmetro '" + nome + "' já declarado");
        }
        return nullptr;
    }

    antlrcpp::Any visitDeclaracao_variavel(MinhaLinguagemParser::Declaracao_variavelContext* ctx) override {
        std::string nome = ctx->ID->getText();
        std::string tipoStr = ctx->tipo()->getText();
        bool isVetor = (ctx->ABRE_COLCHETES() != nullptr);
        
        if (tabela.buscarNoEscopoAtual(nome)) {
            reportarErro(ctx, "Variável duplicada: " + nome);
        }

        TipoDado tipo;
        if (isVetor) {
            // Converter para tipo vetorial
            if (tipoStr == "int") tipo = TipoDado::VETOR_INT;
            else if (tipoStr == "float") tipo = TipoDado::VETOR_FLOAT;
            else if (tipoStr == "char") tipo = TipoDado::VETOR_CHAR;
            else if (tipoStr == "string") tipo = TipoDado::VETOR_STRING;
            else tipo = TipoDado::INVALIDO;
        } else {
            tipo = stringParaTipo(tipoStr);
        }
    
        if (!tabela.inserirSimbolo(Simbolo{
            nome, tipo, Categoria::VARIAVEL, isVetor, tabela.getNivelAtual()
        })) {
            reportarErro(ctx, "Variável '" + nome + "' já declarada");
            return nullptr;
        }
    
        // Verificar expressão de tamanho para vetores
        if (isVetor && ctx->expressao(0)) {
            TipoDado tipoTamanho = getTipoComo(visit(ctx->expressao(0)));
            if (tipoTamanho != TipoDado::INT) {
                reportarErro(ctx, "Tamanho do vetor deve ser inteiro");
            }
            
            // Verificar se tamanho é positivo
            if (auto inteiro = dynamic_cast<MinhaLinguagemParser::InteiroContext*>(ctx->expressao(0))) {
                int valor = std::stoi(inteiro->NUM_INT()->getText());
                if (valor <= 0) {
                    reportarErro(ctx, "Tamanho do vetor deve ser positivo");
                }
            }
        }
    
        // Verificar atribuição
        if (ctx->ATRIBUICAO()) {
            int idx = isVetor && ctx->expressao(0) ? 1 : 0;
            TipoDado tipoExpr = getTipoComo(visit(ctx->expressao(idx)));
            
            // Permitir atribuição de classes
            if (tipo == TipoDado::CLASSE && tipoExpr == TipoDado::CLASSE) {
                // Verificação simplificada - classes compatíveis
            } 
            else if (!tiposCompativeis(tipo, tipoExpr, true)) {
                reportarErro(ctx, "Atribuição incompatível");
            }
        }
    
        return nullptr;
    }

    antlrcpp::Any visitDeclaracao_construtor(MinhaLinguagemParser::Declaracao_construtorContext* ctx) override {
        if (classeAtual.empty()) {
            reportarErro(ctx, "Construtor declarado fora de uma classe");
            return nullptr;
        }

        // Corrigido: acessar primeiro IDENTIFICADOR
        std::string nomeConstrutor = ctx->IDENTIFICADOR(0)->getText();
        
        // Verificar se o nome do construtor é o mesmo da classe
        if (nomeConstrutor != classeAtual) {
            reportarErro(ctx, "Construtor '" + nomeConstrutor + "' deve ter o mesmo nome da classe '" + classeAtual + "'");
        }
        
        // Tratar chamada de superclasse
        if (ctx->DOIS_PONTOS()) {
            std::string superName = ctx->IDENTIFICADOR(1)->getText();
            Simbolo* superClass = tabela.buscarSimbolo(superName);
            if (!superClass) {
                reportarErro(ctx, "Superclasse não encontrada: " + superName);
            }
        }
        
        // Verificar duplicatas de construtores com mesma assinatura
        bool duplicata = false;
        for (const auto& membro : membrosClasses[classeAtual]) {
            if (membro.nome == nomeConstrutor && membro.tipo == TipoDado::CONSTRUTOR) {
                // Verificar se os parâmetros são iguais
                if (membro.tiposParametros.size() == ctx->parametros()->parametro().size()) {
                    bool parametrosIguais = true;
                    for (size_t i = 0; i < membro.tiposParametros.size(); i++) {
                        std::string tipoParam = ctx->parametros()->parametro(i)->tipo()->getText();
                        if (membro.tiposParametros[i] != stringParaTipo(tipoParam)) {
                            parametrosIguais = false;
                            break;
                        }
                    }
                    if (parametrosIguais) {
                        duplicata = true;
                        break;
                    }
                }
            }
        }
        
        if (duplicata) {
            reportarErro(ctx, "Construtor duplicado com a mesma assinatura em '" + classeAtual + "'");
        } else {
            // Coletar tipos dos parâmetros
            std::vector<TipoDado> tiposParam;
            if (ctx->parametros()) {
                for (auto param : ctx->parametros()->parametro()) {
                    tiposParam.push_back(stringParaTipo(param->tipo()->getText()));
                }
            }
            
            // Criar símbolo para o construtor
            Simbolo construtor;
            construtor.nome = nomeConstrutor;
            construtor.tipo = TipoDado::CONSTRUTOR;
            construtor.categoria = Categoria::FUNCAO;
            construtor.tiposParametros = tiposParam;
            construtor.nivelEscopo = tabela.getNivelAtual();
            
            // Adicionar à lista de membros da classe
            membrosClasses[classeAtual].push_back(construtor);
        }

        // Entrar no escopo do construtor
        tabela.entrarEscopo();
        
        // Registrar parâmetros no escopo
        if (ctx->parametros()) {
            visit(ctx->parametros());
        }
        
        // Processar corpo do construtor
        visit(ctx->bloco());
        
        // Verificar return em construtor
        if (temReturn) {
            reportarErro(ctx, "Construtores não podem ter declarações return");
        }
        
        tabela.sairEscopo();
        return nullptr;
    }

    antlrcpp::Any visitBloco(MinhaLinguagemParser::BlocoContext* ctx) override {
        bool blocoExterno = !emFuncao;
        bool localTemReturn = false;
        bool localCaminhoRetorna = false;
        bool localCaminhoNaoRetorna = false;
    
        tabela.entrarEscopo();
        visitChildren(ctx);
        tabela.sairEscopo();
    
        if (emFuncao && !blocoExterno) {
            if (localTemReturn) {
                temReturn = true;
            }
            if (localCaminhoRetorna) {
                caminhoRetornaValor = true;
            }
            if (localCaminhoNaoRetorna) {
                caminhoNaoRetorna = true;
            }
        }
        return nullptr;
    }    

    antlrcpp::Any visitAtribuicaoVetor(MinhaLinguagemParser::AtribuicaoVetorContext* ctx) override {
        TipoDado tipoArray = getTipoComo(visit(ctx->expressao(0)));
        Value* array = std::any_cast<Value*>(visit(ctx->expressao(0)));
        Value* index = std::any_cast<Value*>(visit(ctx->expressao(1)));
        Value* value = std::any_cast<Value*>(visit(ctx->expressao(2)));
        
        Value* indices[] = {index};
        Value* ptr = builder->CreateGEP(array, indices, "elementptr");
        builder->CreateStore(value, ptr);

        return nullptr;
    } 

    antlrcpp::Any visitAtribuicao(MinhaLinguagemParser::AtribuicaoContext* ctx) override {
        std::string nome = ctx->IDENTIFICADOR()->getText();
        Simbolo* simbolo = tabela.buscarSimbolo(nome);
        
        if (!simbolo) {
            reportarErro(ctx, "Variável não declarada: '" + nome + "'");
            return TipoDado::INVALIDO;
        }
    
        if (simbolo->isVetor) {
            reportarErro(ctx, "Atribuição direta a vetor não permitida");
            return TipoDado::INVALIDO;
        }

        if (simbolo->categoria != Categoria::VARIAVEL && 
            simbolo->categoria != Categoria::PARAMETRO) {
            reportarErro(ctx, "'" + nome + "' não é uma variável");
            return TipoDado::INVALIDO;
        }

        if (simbolo->isVetor) {
            reportarErro(ctx, "Atribuição direta a vetor não permitida");
        }

        TipoDado tipoExpr = getTipoComo(visit(ctx->expressao()));
        if (!tiposCompativeis(simbolo->tipo, tipoExpr, true)) {
            reportarErro(ctx, "Atribuição incompatível");
        }

        return simbolo->tipo;
    }

    antlrcpp::Any visitAtribuicaoMembro(MinhaLinguagemParser::AtribuicaoMembroContext* ctx) override {
        // Corrigir: usar getTipoComo para converter o resultado
        TipoDado tipoObj = getTipoComo(visit(ctx->expressao(0)));
        std::string membro = ctx->IDENTIFICADOR()->getText();
        
        Simbolo* membroSimbolo = buscarMembroClasse(tipoParaString(tipoObj), membro);
        if (!membroSimbolo) {
            reportarErro(ctx, "Membro '" + membro + "' não existe");
            return nullptr;
        }
        
        // Corrigir: usar getTipoComo para converter o resultado
        TipoDado tipoExpr = getTipoComo(visit(ctx->expressao(1)));
        if (!tiposCompativeis(membroSimbolo->tipo, tipoExpr, true)) {
            reportarErro(ctx, "Atribuição incompatível para membro");
        }
        return nullptr;
    }

    antlrcpp::Any visitBinaria(MinhaLinguagemParser::BinariaContext* ctx) override {
        TipoDado tipoEsq = getTipoComo(visit(ctx->expressao(0)));
        TipoDado tipoDir = getTipoComo(visit(ctx->expressao(1)));
        std::string op = ctx->op->getText();
    
        // Operações aritméticas
        if (op == "+" || op == "-" || op == "*" || op == "/") {
            // Verificar vetores
            if (tipoEsq >= TipoDado::VETOR_INT || tipoDir >= TipoDado::VETOR_INT) {
                reportarErro(ctx, "Operações aritméticas não suportadas para vetores");
                return TipoDado::INVALIDO;
            }
            
            // Verificar tipos numéricos
            if (tipoEsq != TipoDado::INT && tipoEsq != TipoDado::FLOAT) {
                reportarErro(ctx, "Operando esquerdo deve ser numérico");
            }
            if (tipoDir != TipoDado::INT && tipoDir != TipoDado::FLOAT) {
                reportarErro(ctx, "Operando direito deve ser numérico");
            }
            
            // Determinar tipo de retorno
            if (tipoEsq == TipoDado::FLOAT || tipoDir == TipoDado::FLOAT) {
                return TipoDado::FLOAT;
            }

            if ((tipoEsq == TipoDado::CHAR && tipoDir == TipoDado::STRING) ||
                (tipoEsq == TipoDado::STRING && tipoDir == TipoDado::CHAR)) {
                return TipoDado::STRING;
            }            

            return TipoDado::INT;
        }
        
        // Operações de comparação
        if (op == ">" || op == ">=" || op == "<" || op == "<=" || op == "==" || op == "!=") {
            // Comparação entre vetores não permitida
            if (tipoEsq >= TipoDado::VETOR_INT || tipoDir >= TipoDado::VETOR_INT) {
                reportarErro(ctx, "Comparações não suportadas para vetores");
                return TipoDado::INVALIDO;
            }
            
            if (!tiposCompativeis(tipoEsq, tipoDir)) {
                reportarErro(ctx, "Tipos incompatíveis para comparação");
            }
            return TipoDado::INT;
        }
        
        // Operações lógicas
        if (op == "&&" || op == "||") {
            // Verificar vetores
            if (tipoEsq >= TipoDado::VETOR_INT || tipoDir >= TipoDado::VETOR_INT) {
                reportarErro(ctx, "Operações lógicas não suportadas para vetores");
                return TipoDado::INVALIDO;
            }
            
            if (tipoEsq != TipoDado::INT || tipoDir != TipoDado::INT) {
                reportarErro(ctx, "Operandos devem ser inteiros");
            }
            return TipoDado::INT;
        }
        
        return TipoDado::INVALIDO;
    }

    antlrcpp::Any visitIf(MinhaLinguagemParser::IfContext* ctx) override {
        // Verificar condição
        TipoDado tipoCond = getTipoComo(visit(ctx->expressao()));
        if (tipoCond != TipoDado::INT) {
            reportarErro(ctx, "Condição do if deve ser inteira");
        }

        // Estado para ramos condicionais
        bool ifRetorna = false;
        bool elseRetorna = false;

        // Processar bloco if
        tabela.entrarEscopo();
        visit(ctx->bloco(0));
        tabela.sairEscopo();
        if (emFuncao) ifRetorna = caminhoRetornaValor;

        // Processar bloco else se existir
        if (ctx->bloco().size() > 1) {
            tabela.entrarEscopo();
            visit(ctx->bloco(1));
            tabela.sairEscopo();
            if (emFuncao) elseRetorna = caminhoRetornaValor;
        }

        // Atualizar estado de caminhos de retorno
        if (emFuncao) {
            // Ambos os caminhos retornam?
            if (ifRetorna && elseRetorna) {
                caminhoRetornaValor = true;
            } 
            // Pelo menos um caminho não retorna?
            else if (!ifRetorna || !elseRetorna) {
                caminhoNaoRetorna = true;
            }
        }
        
        return nullptr;
    }


    antlrcpp::Any visitWhile(MinhaLinguagemParser::WhileContext* ctx) override {
        TipoDado tipoCond = getTipoComo(visit(ctx->expressao()));
        if (tipoCond != TipoDado::INT) {
            reportarErro(ctx, "Condição do while deve ser inteira");
        }
        
        bool estavaEmLoop = emLoop;
        emLoop = true;

        tabela.entrarEscopo();
        visit(ctx->bloco());
        tabela.sairEscopo();
        
        emLoop = estavaEmLoop;
        
        // Loops são considerados caminhos que podem não retornar
        if (emFuncao) {
            caminhoNaoRetorna = true;
        }
        
        return nullptr;
    }

    antlrcpp::Any visitFor(MinhaLinguagemParser::ForContext* ctx) override {
        tabela.entrarEscopo();

        if (ctx->declaracao_variavel()) {
            visit(ctx->declaracao_variavel());
        } else if (ctx->expressao(0)) {
            visit(ctx->expressao(0));
        }
        
        if (ctx->expressao(0)) { // Condição
            TipoDado tipoCond = getTipoComo(visit(ctx->expressao(0)));
            if (tipoCond != TipoDado::INT) {
                reportarErro(ctx, "Condição do for deve ser inteira");
            }
        }
        
        if (ctx->expressao(1)) { // Incremento
            visit(ctx->expressao(1));
        }
        
        bool estavaEmLoop = emLoop;
        emLoop = true;

        visit(ctx->bloco());

        tabela.sairEscopo();  
        emLoop = estavaEmLoop;
        
        // Loops são considerados caminhos que podem não retornar
        if (emFuncao) {
            caminhoNaoRetorna = true;
        }
        
        return nullptr;
    }

    // antlrcpp::Any visitReturn(MinhaLinguagemParser::ReturnContext* ctx) override {
    //     temReturn = true;
    //     blocoTemReturn = true;
        
    //     if (ctx->expressao()) {
    //         TipoDado tipoExpr = getTipoComo(visit(ctx->expressao()));
            
    //         if (tipoRetornoAtual == TipoDado::VOID) {
    //             reportarErro(ctx, "Função void não pode retornar valor");
    //         }
    //         else if (!tiposCompativeis(tipoRetornoAtual, tipoExpr)) {
    //             reportarErro(ctx, "Tipo de retorno incompatível");
    //         }
            
    //         // Este caminho retorna um valor
    //         caminhoRetornaValor = true;
    //         blocoCaminhoRetorna = true;
    //     }
    //     else if (tipoRetornoAtual != TipoDado::VOID) {
    //         reportarErro(ctx, "Função não-void deve retornar valor");
            
    //         // Este caminho não retorna valor adequado
    //         caminhoNaoRetorna = true;
    //         blocoCaminhoNaoRetorna = true;
    //     }
    //     else {
    //         // Void sem valor - caminho válido
    //         caminhoRetornaValor = true;
    //         blocoCaminhoRetorna = true;
    //     }
        
    //     return nullptr;
    // }

    antlrcpp::Any visitReturnStmt(MinhaLinguagemParser::ReturnStmtContext* ctx) override {
        temReturn = true;

        if (tipoRetornoAtual == TipoDado::VOID && ctx->expressao()) {
            reportarErro(ctx, "Função void não pode retornar valor");
        }        

        if (emConstrutor) {
            reportarErro(ctx, "Construtores não podem ter declarações return");
            return nullptr;
        }        
        
        if (ctx->expressao()) {
            TipoDado tipoExpr = getTipoComo(visit(ctx->expressao()));
            
            if (tipoRetornoAtual == TipoDado::VOID) {
                reportarErro(ctx, "Função void não pode retornar valor");
            }
            else if (!tiposCompativeis(tipoRetornoAtual, tipoExpr)) {
                reportarErro(ctx, "Tipo de retorno incompatível");
            }
            else {
                caminhoRetornaValor = true;
            }
        }
        else {
            if (tipoRetornoAtual != TipoDado::VOID) {
                reportarErro(ctx, "Função não-void deve retornar valor");
                caminhoNaoRetorna = true;
            }
            else {
                caminhoRetornaValor = true;
            }
        }
        
        return nullptr;
    }

    antlrcpp::Any visitCharLiteral(MinhaLinguagemParser::CharLiteralContext* ctx) override {
        std::string text = ctx->getText();
        char val = text[1]; // Extract char from 'a'
        // Handle special cases and return appropriate value
    }

    antlrcpp::Any visitChamadaFuncao(MinhaLinguagemParser::ChamadaFuncaoContext* ctx) override {
        std::string nome = ctx->IDENTIFICADOR()->getText();
        Simbolo* simbolo = tabela.buscarSimbolo(nome);
        
        if (!simbolo || simbolo->categoria != Categoria::FUNCAO) {
            reportarErro(ctx, "Função não declarada: '" + nome + "'");
            return TipoDado::INVALIDO;
        }
        
        auto args = ctx->expressao();
        
        // Verificação especial para printf/scanf (funções variádicas)
        if (nome == "printf" || nome == "scanf") {
            if (args.size() < 1) {
                reportarErro(ctx, "Função '" + nome + "' requer pelo menos 1 argumento");
            } else {
                // Verificar primeiro argumento (string)
                TipoDado tipoPrimeiro = getTipoComo(visit(args[0]));
                if (tipoPrimeiro != TipoDado::STRING) {
                    reportarErro(ctx, "Primeiro argumento de '" + nome + "' deve ser string");
                }
                
                // Verificar demais argumentos (devem ser endereços)
                for (size_t i = 1; i < args.size(); i++) {
                    if (auto varCtx = dynamic_cast<MinhaLinguagemParser::VariavelContext*>(args[i])) {
                        std::string varNome = varCtx->IDENTIFICADOR()->getText();
                        Simbolo* varSimbolo = tabela.buscarSimbolo(varNome);
                        
                        if (!varSimbolo || varSimbolo->categoria != Categoria::VARIAVEL) {
                            reportarErro(ctx, "Argumento " + std::to_string(i+1) + " deve ser variável");
                        }
                    } else {
                        reportarErro(ctx, "Argumento " + std::to_string(i+1) + " deve ser variável (endereço)");
                    }
                }
            }
            return TipoDado::INT;
        }
        
        // Verificação normal para outras funções
        if (args.size() != simbolo->tiposParametros.size()) {
            reportarErro(ctx, "Número incorreto de argumentos para '" + nome + "'");
            return simbolo->tipo;
        }
        
        for (size_t i = 0; i < args.size(); i++) {
            TipoDado tipoArg = getTipoComo(visit(args[i]));
            if (!tiposCompativeis(simbolo->tiposParametros[i], tipoArg)) {
                reportarErro(ctx, "Tipo incorreto para argumento " + std::to_string(i+1));
            }
        }
        
        return simbolo->tipo;
    }

    antlrcpp::Any visitAcessoVetor(MinhaLinguagemParser::AcessoVetorContext* ctx) override {
        Value *arrayPtr = namedValues[ctx->IDENTIFICADOR()->getText()];
        Value *index = std::any_cast<Value*>(visit(ctx->expressao()));
        
        if (!arrayPtr || !index) return nullptr;
        
        Value *indices[] = {index};
        return builder->CreateGEP(arrayPtr, indices, "elementptr");
    }

    antlrcpp::Any visitNewVetor(MinhaLinguagemParser::NewVetorContext* ctx) override {
        TipoDado tipo = stringParaTipo(ctx->tipo_base()->getText());
        
        if (ctx->expressao()) {
            TipoDado tamanho = getTipoComo(visit(ctx->expressao()));
            if (tamanho != TipoDado::INT) {
                reportarErro(ctx, "Tamanho do vetor deve ser inteiro");
            }
            
            // Verificar se tamanho é positivo
            if (auto inteiro = dynamic_cast<MinhaLinguagemParser::InteiroContext*>(ctx->expressao())) {
                int valor = std::stoi(inteiro->NUM_INT()->getText());
                if (valor <= 0) {
                    reportarErro(ctx, "Tamanho do vetor deve ser positivo");
                }
            }
        }
        
        return tipo;
    }

    antlrcpp::Any visitNewObjeto(MinhaLinguagemParser::NewObjetoContext* ctx) override {
        std::string nomeClasse = ctx->IDENTIFICADOR()->getText();
        Simbolo* classe = tabela.buscarSimbolo(nomeClasse);
        
        if (!classe || classe->tipo != TipoDado::CLASSE) {
            reportarErro(ctx, "Classe não definida: '" + nomeClasse + "'");
            return TipoDado::INVALIDO;
        }

        // Verificar construtores
        bool construtorEncontrado = false;
        for (const auto& membro : classe->membros) {
            if (membro.tipo == TipoDado::CONSTRUTOR) {
                // Verificar compatibilidade de parâmetros
                if (membro.tiposParametros.size() == ctx->expressao().size()) {
                    bool compativel = true;
                    for (size_t i = 0; i < membro.tiposParametros.size(); i++) {
                        TipoDado tipoArg = getTipoComo(visit(ctx->expressao(i)));
                        if (!tiposCompativeis(membro.tiposParametros[i], tipoArg)) {
                            compativel = false;
                            break;
                        }
                    }
                    if (compativel) {
                        construtorEncontrado = true;
                        break;
                    }
                }
            }
        }

        if (!construtorEncontrado) {
            reportarErro(ctx, "Nenhum construtor compatível encontrado para '" + nomeClasse + "'");
        }

        return TipoDado::CLASSE;
    }

    antlrcpp::Any visitInteiro(MinhaLinguagemParser::InteiroContext* ctx) override {
        return TipoDado::INT;
    }

    antlrcpp::Any visitFloat(MinhaLinguagemParser::FloatContext* ctx) override {
        return TipoDado::FLOAT;
    }

    antlrcpp::Any visitString(MinhaLinguagemParser::StringContext* ctx) override {
        return TipoDado::STRING;
    }

    antlrcpp::Any visitVariavel(MinhaLinguagemParser::VariavelContext* ctx) override {
        std::string nome = ctx->IDENTIFICADOR()->getText();
        Simbolo* simbolo = tabela.buscarSimbolo(nome);
        
        if (!simbolo) {
            reportarErro(ctx, "Variável não declarada: '" + nome + "'");
            return TipoDado::INVALIDO;
        }

        
        if (ctx->parent) {
            std::string parentText = ctx->parent->getText();
            if (parentText.find('&') != std::string::npos) {
                return TipoDado::POINTER;
            }
        }

        return simbolo->tipo;
    }

    // antlrcpp::Any visitOperacaoVetor(MinhaLinguagemParser::OperacaoVetorContext* ctx) override {
    //     // Verificar operações específicas com vetores
    //     if (ctx->op->getText() == "+=" || ctx->op->getText() == "=") {
    //         std::string nome = ctx->IDENTIFICADOR()->getText();
    //         Simbolo* simbolo = tabela.buscarSimbolo(nome);
            
    //         if (simbolo && !simbolo->isVetor) {
    //             reportarErro(ctx, "Operação vetorial aplicada a não-vetor");
    //         }
    //     }
    //     return visitChildren(ctx);
    // }

    antlrcpp::Any visitAcessoMembro(MinhaLinguagemParser::AcessoMembroContext* ctx) override {
        TipoDado tipoExpr = getTipoComo(visit(ctx->expressao()));
        
        if (tipoExpr != TipoDado::CLASSE) {
            reportarErro(ctx, "Acesso a membro em tipo não-classe");
            return TipoDado::INVALIDO;
        }
        
        std::string nomeMembro = ctx->IDENTIFICADOR()->getText();
        
        // Obter classe real do objeto
        Simbolo* simboloExpr = tabela.buscarSimbolo(ctx->expressao()->getText());
        if (!simboloExpr) {
            reportarErro(ctx, "Símbolo não encontrado: " + ctx->expressao()->getText());
            return TipoDado::INVALIDO;
        }
        
        Simbolo* simboloMembro = buscarMembroClasse(simboloExpr->nomeClasse, nomeMembro);
        
        if (!simboloMembro) {
            reportarErro(ctx, "Membro '" + nomeMembro + "' não existe");
            return TipoDado::INVALIDO;
        }
        
        return simboloMembro->tipo;
    }

    antlrcpp::Any visitChamadaMetodo(MinhaLinguagemParser::ChamadaMetodoContext* ctx) override {
        // Corrigir: usar getTipoComo para converter o resultado
        TipoDado tipoExpr = getTipoComo(visit(ctx->expressao(0)));
        std::string nomeClasse = tipoParaString(tipoExpr);
        std::string nomeMetodo = ctx->IDENTIFICADOR()->getText();
        
        Simbolo* simboloMetodo = buscarMembroClasse(nomeClasse, nomeMetodo);
        
        if (!simboloMetodo || simboloMetodo->categoria != Categoria::FUNCAO) {
            reportarErro(ctx, "Método não encontrado: " + nomeMetodo);
            return TipoDado::INVALIDO;
        }
        
        auto args = ctx->expressao();
        for (size_t i = 1; i < args.size(); i++) {
            // Corrigir: usar getTipoComo para converter o resultado
            TipoDado tipoArg = getTipoComo(visit(args[i]));
            if (i-1 < simboloMetodo->tiposParametros.size() && 
                !tiposCompativeis(simboloMetodo->tiposParametros[i-1], tipoArg)) {
                reportarErro(ctx, "Tipo incorreto para argumento " + std::to_string(i));
            }
        }
        
        return simboloMetodo->tipo;
    }

};

#endif // SEMANTICOVISITOR_H