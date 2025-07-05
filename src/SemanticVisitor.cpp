#include "SemanticVisitor.h"
#include <algorithm>

using namespace std;

void SemanticVisitor::checkTypeCompatibility(const string& expected, const string& actual, const string& context) {
    if (expected != actual) {
        throw runtime_error("Erro semântico: Incompatibilidade de tipos em " + context + 
                          ". Esperado: " + expected + ", Encontrado: " + actual);
    }
}

string SemanticVisitor::getExpressionType(MinhaLinguagemParser::ExpressaoContext *ctx) {
    // Handle integer literals
    if (dynamic_cast<MinhaLinguagemParser::InteiroContext*>(ctx)) {
        return "int";
    }
    // Handle float literals
    else if (dynamic_cast<MinhaLinguagemParser::FloatContext*>(ctx)) {
        return "float";
    }
    // Handle string literals
    else if (dynamic_cast<MinhaLinguagemParser::StringContext*>(ctx)) {
        return "string";
    }
    // Handle variable access
    else if (auto varCtx = dynamic_cast<MinhaLinguagemParser::VariavelContext*>(ctx)) {
        Symbol* sym = symbolTable.lookup(varCtx->IDENTIFICADOR()->getText());
        if (!sym) {
            throw runtime_error("Erro semântico: Variável '" + varCtx->IDENTIFICADOR()->getText() + "' não declarada");
        }
        return sym->type;
    }
    // Handle binary operations
    else if (auto binCtx = dynamic_cast<MinhaLinguagemParser::BinariaContext*>(ctx)) {
        string leftType = getExpressionType(binCtx->expressao(0));
        string rightType = getExpressionType(binCtx->expressao(1));
        
        if (leftType != rightType) {
            throw runtime_error("Erro semântico: Tipos incompatíveis em operação binária: " + 
                              leftType + " e " + rightType);
        }
        return leftType;
    }
    // Handle function calls
    else if (auto callCtx = dynamic_cast<MinhaLinguagemParser::ChamadaFuncaoContext*>(ctx)) {
        Symbol* sym = symbolTable.lookup(callCtx->IDENTIFICADOR()->getText());
        if (!sym || sym->symbolType != SymbolType::FUNCTION) {
            throw runtime_error("Erro semântico: Função '" + callCtx->IDENTIFICADOR()->getText() + "' não declarada");
        }
        return sym->type;
    }
    // Handle array access
    else if (auto arrayCtx = dynamic_cast<MinhaLinguagemParser::AcessoVetorContext*>(ctx)) {
        Symbol* sym = symbolTable.lookup(arrayCtx->IDENTIFICADOR()->getText());
        if (!sym) {
            throw runtime_error("Erro semântico: Array '" + arrayCtx->IDENTIFICADOR()->getText() + "' não declarado");
        }
        if (!sym->isArray) {
            throw runtime_error("Erro semântico: '" + arrayCtx->IDENTIFICADOR()->getText() + "' não é um array");
        }
        return sym->type.substr(0, sym->type.find("[")); // Return base type
    }
    // Handle new array creation
    else if (auto newCtx = dynamic_cast<MinhaLinguagemParser::NewContext*>(ctx)) {
        string type = newCtx->tipo()->getText();
        if (newCtx->ABRE_COLCHETES()) {
            return type + "[]";
        }
        return type;
    }
    // Handle array element assignment
    else if (auto assignArrCtx = dynamic_cast<MinhaLinguagemParser::AtribuicaoArrayContext*>(ctx)) {
        visitAtribuicaoArray(assignArrCtx);
        return "void";
    }
    // Handle regular assignment
    else if (auto assignCtx = dynamic_cast<MinhaLinguagemParser::AtribuicaoContext*>(ctx)) {
        visitAtribuicao(assignCtx);
        return "void";
    }

    return "void";
}

antlrcpp::Any SemanticVisitor::visitAtribuicaoArray(MinhaLinguagemParser::AtribuicaoArrayContext *ctx) {
    string arrayName = ctx->IDENTIFICADOR()->getText();
    Symbol* sym = symbolTable.lookup(arrayName);
    
    if (!sym) {
        throw runtime_error("Erro semântico: Array '" + arrayName + "' não declarado");
    }
    
    if (!sym->isArray) {
        throw runtime_error("Erro semântico: '" + arrayName + "' não é um array");
    }
    
    // Check index type
    string indexType = getExpressionType(ctx->expressao(0));
    checkTypeCompatibility("int", indexType, "índice de array");
    
    // Check value type
    string valueType = getExpressionType(ctx->expressao(1));
    string baseType = sym->type.substr(0, sym->type.find("["));
    checkTypeCompatibility(baseType, valueType, "atribuição a elemento de array");
    
    return nullptr;
}

antlrcpp::Any SemanticVisitor::visitPrograma(MinhaLinguagemParser::ProgramaContext *ctx) {
    symbolTable.enterScope();
    visitChildren(ctx);
    symbolTable.exitScope();
    return nullptr;
}

antlrcpp::Any SemanticVisitor::visitDeclaracao_classe(MinhaLinguagemParser::Declaracao_classeContext *ctx) {
    string className = ctx->ID->getText();
    symbolTable.addSymbol(className, "class", SymbolType::CLASS);
    
    symbolTable.enterScope();
    visitChildren(ctx);
    symbolTable.exitScope();
    return nullptr;
}

antlrcpp::Any SemanticVisitor::visitDeclaracao_funcao(MinhaLinguagemParser::Declaracao_funcaoContext *ctx) {
    string funcName = ctx->ID->getText();
    string returnType = ctx->tipo()->getText();
    
    currentFunctionType = returnType;
    inFunction = true;
    
    vector<string> paramTypes;
    if (ctx->parametros()) {
        for (auto param : ctx->parametros()->parametro()) {
            paramTypes.push_back(param->tipo()->getText());
        }
    }
    
    symbolTable.addSymbol(funcName, returnType, SymbolType::FUNCTION, false, paramTypes);
    
    symbolTable.enterScope();
    visitChildren(ctx);
    symbolTable.exitScope();
    
    inFunction = false;
    currentFunctionType = "void";
    return nullptr;
}

antlrcpp::Any SemanticVisitor::visitParametros(MinhaLinguagemParser::ParametrosContext *ctx) {
    for (auto param : ctx->parametro()) {
        visit(param);
    }
    return nullptr;
}

antlrcpp::Any SemanticVisitor::visitParametro(MinhaLinguagemParser::ParametroContext *ctx) {
    string paramName = ctx->ID->getText();
    string paramType = ctx->tipo()->getText();
    symbolTable.addSymbol(paramName, paramType, SymbolType::PARAMETER);
    return nullptr;
}

antlrcpp::Any SemanticVisitor::visitDeclaracao_variavel(MinhaLinguagemParser::Declaracao_variavelContext *ctx) {
    string varName = ctx->ID->getText();
    string varType = ctx->tipo()->getText();
    bool isArray = false;

    // Check for array declaration (either with [] or new)
    if (ctx->ABRE_COLCHETES() != nullptr) {
        isArray = true;
        varType += "[]";
        
        // Check array size if specified
        if (ctx->expressao().size() > 0 && ctx->ATRIBUICAO() == nullptr) {
            string sizeType = getExpressionType(ctx->expressao(0));
            checkTypeCompatibility("int", sizeType, "tamanho de array");
        }
    }

    // Add to symbol table
    symbolTable.addSymbol(varName, varType, SymbolType::VARIABLE, isArray);

    // Handle initialization if present
    if (ctx->ATRIBUICAO()) {
        string exprType = getExpressionType(ctx->expressao().back());
        
        // Special handling for array initialization
        if (isArray) {
            if (exprType != varType) {
                string errorMsg = "Erro semântico: Incompatibilidade de tipos em inicialização de array. Esperado: ";
                errorMsg += varType + ", Encontrado: " + exprType;
                throw runtime_error(errorMsg);
            }
        } 
        // Regular variable initialization
        else {
            checkTypeCompatibility(varType, exprType, "inicialização de variável");
        }
    }

    return nullptr;
}

antlrcpp::Any SemanticVisitor::visitBloco(MinhaLinguagemParser::BlocoContext *ctx) {
    symbolTable.enterScope();
    visitChildren(ctx);
    symbolTable.exitScope();
    return nullptr;
}

antlrcpp::Any SemanticVisitor::visitIf(MinhaLinguagemParser::IfContext *ctx) {
    string condType = getExpressionType(ctx->expressao());
    checkTypeCompatibility("int", condType, "condição do if");
    
    visit(ctx->expressao());
    visit(ctx->bloco(0));
    
    if (ctx->bloco().size() > 1) {
        visit(ctx->bloco(1));
    }
    return nullptr;
}

antlrcpp::Any SemanticVisitor::visitWhile(MinhaLinguagemParser::WhileContext *ctx) {
    bool wasInLoop = inLoop;
    inLoop = true;
    
    string condType = getExpressionType(ctx->expressao());
    checkTypeCompatibility("int", condType, "condição do while");
    
    visit(ctx->expressao());
    visit(ctx->bloco());
    
    inLoop = wasInLoop;
    return nullptr;
}

antlrcpp::Any SemanticVisitor::visitFor(MinhaLinguagemParser::ForContext *ctx) {
    bool wasInLoop = inLoop;
    inLoop = true;
    
    symbolTable.enterScope();
    visit(ctx->declaracao_variavel());
    
    string condType = getExpressionType(ctx->expressao(0));
    checkTypeCompatibility("int", condType, "condição do for");
    
    visit(ctx->expressao(0));
    visit(ctx->expressao(1));
    visit(ctx->bloco());
    
    symbolTable.exitScope();
    inLoop = wasInLoop;
    return nullptr;
}

antlrcpp::Any SemanticVisitor::visitAtribuicao(MinhaLinguagemParser::AtribuicaoContext *ctx) {
    string varName = ctx->IDENTIFICADOR()->getText();
    Symbol* sym = symbolTable.lookup(varName);
    
    if (!sym) {
        throw runtime_error("Erro semântico: Variável '" + varName + "' não declarada");
    }
    
    string exprType = getExpressionType(ctx->expressao());
    string expectedType = sym->type;
    
    // Handle array types
    if (sym->isArray) {
        if (exprType != expectedType) {
            string errorMsg = "Erro semântico: Incompatibilidade de tipos em atribuição de array. Esperado: ";
            errorMsg += expectedType + ", Encontrado: " + exprType;
            throw runtime_error(errorMsg);
        }
    }
    // Handle regular variables
    else {
        checkTypeCompatibility(expectedType, exprType, "atribuição");
    }
    
    return nullptr;
}

antlrcpp::Any SemanticVisitor::visitBinaria(MinhaLinguagemParser::BinariaContext *ctx) {
    visitChildren(ctx);
    return nullptr;
}

antlrcpp::Any SemanticVisitor::visitChamadaFuncao(MinhaLinguagemParser::ChamadaFuncaoContext *ctx) {
    string funcName = ctx->IDENTIFICADOR()->getText();
    Symbol* sym = symbolTable.lookup(funcName);
    
    if (!sym || sym->symbolType != SymbolType::FUNCTION) {
        throw runtime_error("Erro semântico: Função '" + funcName + "' não declarada");
    }
    
    size_t expectedParams = sym->parameters.size();
    size_t actualParams = ctx->expressao().size();
    
    if (expectedParams != actualParams) {
        throw runtime_error("Erro semântico: Número incorreto de argumentos para '" + funcName + 
                          "'. Esperado: " + to_string(expectedParams) + 
                          ", Encontrado: " + to_string(actualParams));
    }
    
    for (size_t i = 0; i < actualParams; i++) {
        string actualType = getExpressionType(ctx->expressao(i));
        string expectedType = sym->parameters[i];
        checkTypeCompatibility(expectedType, actualType, 
                             "argumento " + to_string(i+1) + " da função '" + funcName + "'");
    }
    
    return sym->type; // Retorna o tipo de retorno da função
}

antlrcpp::Any SemanticVisitor::visitReturnStat(MinhaLinguagemParser::ReturnStatContext *ctx) {
    if (!inFunction) {
        throw runtime_error("Erro semântico: 'return' fora de função");
    }
    
    if (ctx->expressao()) {
        string returnType = getExpressionType(ctx->expressao());
        checkTypeCompatibility(currentFunctionType, returnType, "retorno de função");
    } else if (currentFunctionType != "void") {
        throw runtime_error("Erro semântico: Função deve retornar um valor do tipo " + currentFunctionType);
    }
    
    return nullptr;
}

antlrcpp::Any SemanticVisitor::visitNew(MinhaLinguagemParser::NewContext *ctx) {
    if (ctx->expressao()) {
        string sizeType = getExpressionType(ctx->expressao());
        checkTypeCompatibility("int", sizeType, "tamanho de array");
    }
    return nullptr;
}

antlrcpp::Any SemanticVisitor::visitAcessoVetor(MinhaLinguagemParser::AcessoVetorContext *ctx) {
    string varName = ctx->IDENTIFICADOR()->getText();
    Symbol* sym = symbolTable.lookup(varName);
    
    if (!sym) {
        throw runtime_error("Erro semântico: Variável '" + varName + "' não declarada");
    }
    
    if (!sym->isArray) {
        throw runtime_error("Erro semântico: '" + varName + "' não é um array");
    }
    
    string indexType = getExpressionType(ctx->expressao());
    checkTypeCompatibility("int", indexType, "índice de array");
    
    return sym->type.substr(0, sym->type.find("[")); // Retorna tipo base do array
}

antlrcpp::Any SemanticVisitor::visitInteiro(MinhaLinguagemParser::InteiroContext *ctx) {
    return "int";
}

antlrcpp::Any SemanticVisitor::visitFloat(MinhaLinguagemParser::FloatContext *ctx) {
    return "float";
}

antlrcpp::Any SemanticVisitor::visitString(MinhaLinguagemParser::StringContext *ctx) {
    return "string";
}

antlrcpp::Any SemanticVisitor::visitVariavel(MinhaLinguagemParser::VariavelContext *ctx) {
    string varName = ctx->IDENTIFICADOR()->getText();
    Symbol* sym = symbolTable.lookup(varName);
    
    if (!sym) {
        throw runtime_error("Erro semântico: Variável '" + varName + "' não declarada");
    }
    
    return sym->type;
}