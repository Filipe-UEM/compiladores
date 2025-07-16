#pragma once

#include "MinhaLinguagemParser.h"
#include "MinhaLinguagemBaseVisitor.h"
#include "TabelaSimbolos.h"
#include <sstream>
#include <stack>
#include <vector>
#include <map>
#include <llvm/IR/Value.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Verifier.h>

using namespace llvm;

class LLVMGenerator : 
    public MinhaLinguagemBaseVisitor {
private:
    std::unique_ptr<LLVMContext> context;
    std::unique_ptr<Module> module;
    std::unique_ptr<IRBuilder<>> builder;
    TabelaSimbolos& tabela;
    std::map<std::string, Value*> namedValues;
    std::stack<std::string> loopEndLabels;
    std::stack<std::string> loopStartLabels;
    Function *currentFunction = nullptr;
    Type *currentReturnType = nullptr;
    std::string currentClassName;
    std::map<std::string, StructType*> classTypes;

    // Tipos LLVM básicos
    Type *i32Type;
    Type *floatType;
    Type *i8Type;
    Type *i8PtrType;
    Type *voidType;

    // Funções de runtime
    Function *printfFunc = nullptr;
    Function *scanfFunc = nullptr;
    Function *mallocFunc = nullptr;

    // Gerenciamento de temporários/blocos
    int tempCount = 0;
    int labelCount = 0;

    std::string newTemp() {
        return "t" + std::to_string(tempCount++);
    }

    std::string newLabel(std::string base = "L") {
        return base + std::to_string(labelCount++);
    }

    // Obter tipo LLVM a partir de TipoDado
    Type* getLLVMType(TipoDado tipo, const std::string& className = "") {
        switch (tipo) {
            case TipoDado::INT: return i32Type;
            case TipoDado::FLOAT: return floatType;
            case TipoDado::CHAR: return i8Type;
            case TipoDado::STRING: return i8PtrType;
            case TipoDado::VOID: return voidType;
            case TipoDado::CLASSE: {
                if (classTypes.find(className) != classTypes.end()) {
                    return classTypes[className]->getPointerTo();
                }
                return nullptr;
            }
            case TipoDado::VETOR_INT: return i32Type->getPointerTo();
            case TipoDado::VETOR_FLOAT: return floatType->getPointerTo();
            case TipoDado::VETOR_CHAR: return i8PtrType;
            case TipoDado::VETOR_STRING: return i8PtrType->getPointerTo();
            default: return nullptr;
        }
    }

    // Obter tipo base para vetores
    Type* getBaseType(TipoDado tipo) {
        switch (tipo) {
            case TipoDado::VETOR_INT: return i32Type;
            case TipoDado::VETOR_FLOAT: return floatType;
            case TipoDado::VETOR_CHAR: return i8Type;
            case TipoDado::VETOR_STRING: return i8PtrType;
            default: return nullptr;
        }
    }

    // Obter tamanho do tipo
    uint64_t getTypeSize(Type *type) {
        return module->getDataLayout().getTypeAllocSize(type);
    }

    // Declarar funções de runtime
    void declareRuntimeFunctions() {
        // printf: int printf(char*, ...)
        FunctionType *printfType = FunctionType::get(
            i32Type, 
            {i8PtrType}, 
            true
        );
        printfFunc = Function::Create(
            printfType, 
            Function::ExternalLinkage, 
            "printf", 
            *module
        );

        // scanf: int scanf(char*, ...)
        FunctionType *scanfType = FunctionType::get(
            i32Type, 
            {i8PtrType}, 
            true
        );
        scanfFunc = Function::Create(
            scanfType, 
            Function::ExternalLinkage, 
            "scanf", 
            *module
        );

        // malloc: void* malloc(size_t)
        FunctionType *mallocType = FunctionType::get(
            i8PtrType, 
            {i32Type}, 
            false
        );
        mallocFunc = Function::Create(
            mallocType, 
            Function::ExternalLinkage, 
            "malloc", 
            *module
        );

        // Adicionar putchar
        FunctionType* putcharType = FunctionType::get(i32Type, {i8Type}, false);
        Function::Create(putcharType, Function::ExternalLinkage, "putchar", *module
        );
    }

    // Função auxiliar para converter string para TipoDado
    TipoDado stringParaTipo(const std::string& tipoStr) {
        if (tipoStr == "int") return TipoDado::INT;
        if (tipoStr == "float") return TipoDado::FLOAT;
        if (tipoStr == "char") return TipoDado::CHAR;
        if (tipoStr == "string") return TipoDado::STRING;
        if (tipoStr == "void") return TipoDado::VOID;
        return TipoDado::CLASSE;
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

    LLVMGenerator(TabelaSimbolos& tabelaGlobal) 
        : context(std::make_unique<LLVMContext>()),
          module(std::make_unique<Module>("MinhaLinguagem", *context)),
          builder(std::make_unique<IRBuilder<>>(*context)),
          tabela(tabelaGlobal) {
        
        // Inicializar tipos básicos
        i32Type = Type::getInt32Ty(*context);
        floatType = Type::getFloatTy(*context);
        i8Type = Type::getInt8Ty(*context);
        i8PtrType = Type::getInt8PtrTy(*context);
        voidType = Type::getVoidTy(*context);

        // Declarar funções de runtime
        declareRuntimeFunctions();
    }

    Module* getModule() { return module.get(); }

    antlrcpp::Any visitFuncaoMain(MinhaLinguagemParser::FuncaoMainContext* ctx) override {
        // Criar função main
        FunctionType *mainType = FunctionType::get(
            i32Type, 
            {},
            false
        );
        
        Function *mainFunc = Function::Create(
            mainType, 
            Function::ExternalLinkage, 
            "main", 
            *module
        );
        
        BasicBlock *entryBB = BasicBlock::Create(*context, "entry", mainFunc);
        builder->SetInsertPoint(entryBB);
        
        // Chamar a função main da classe Programa
        Function *programaMain = module->getFunction("Programa_main");
        if (programaMain) {
            builder->CreateCall(programaMain);
        } else {
            std::cerr << "ERRO: Função Programa_main não encontrada!\n";
        }
        
        // Retornar 0
        builder->CreateRet(ConstantInt::get(i32Type, 0));
        
        return nullptr;
    }

    void generateMainFunction() {
        // Criar função main
        FunctionType *mainType = FunctionType::get(
            i32Type, 
            {},
            false
        );
        
        Function *mainFunc = Function::Create(
            mainType, 
            Function::ExternalLinkage, 
            "main", 
            *module
        );
        
        BasicBlock *entryBB = BasicBlock::Create(*context, "entry", mainFunc);
        builder->SetInsertPoint(entryBB);
        
        // Chamar a função main da classe Programa
        Function *programaMain = module->getFunction("Programa_main");
        if (programaMain) {
            builder->CreateCall(programaMain);
        } else {
            // Tratar erro se necessário
        }
        
        // Retornar 0
        builder->CreateRet(ConstantInt::get(i32Type, 0));
    }

    antlrcpp::Any visitPrograma(MinhaLinguagemParser::ProgramaContext* ctx) override {
        // Processar classes primeiro
        for (auto decl : ctx->declaracao_classe()) {
            visitDeclaracao_classe(decl);
        }
        
        // Processar funções globais
        for (auto decl : ctx->declaracao_funcao()) {
            visitDeclaracao_funcao(decl);
        }
        
        // Processar funções dentro de classes
        for (auto classe : ctx->declaracao_classe()) {
            for (auto membro : classe->membro()) {
                if (auto func = dynamic_cast<MinhaLinguagemParser::Declaracao_funcaoContext*>(membro)) {
                    visitDeclaracao_funcao(func);
                }
            }
        }
        
        // Gerar função main que chama Programa::main
        generateMainFunction();
        
        return nullptr;
    }

    antlrcpp::Any visitDeclaracao_classe(MinhaLinguagemParser::Declaracao_classeContext* ctx) override {
        std::string className = ctx->ID->getText();
        currentClassName = className;
        std::string superClasse = "";

        if (ctx->IDENTIFICADOR().size() > 1) {
            superClasse = ctx->IDENTIFICADOR(1)->getText();
        }
        
        // Criar struct type se não existir
        if (classTypes.find(className) == classTypes.end()) {
            std::vector<Type*> memberTypes;
            Simbolo* classSymbol = tabela.buscarSimbolo(className);
            if (classSymbol) {
                for (const auto& member : classSymbol->membros) {
                    if (member.categoria == Categoria::VARIAVEL) {
                        Type* memberType = getLLVMType(member.tipo, member.nomeClasse);
                        if (memberType) memberTypes.push_back(memberType);
                    }
                }
            }
            StructType *classType = StructType::create(*context, className);
            classType->setBody(memberTypes);
            classTypes[className] = classType;
        }

        // Incluir campos da superclasse
        if (!superClasse.empty() && classTypes.find(superClasse) != classTypes.end()) {
            StructType* superType = classTypes[superClasse];
            for (auto* type : superType->elements()) {
                memberTypes.push_back(type); // Campos da superclasse
            }
        }

        // Coletar função main se for a classe Programa
        if (className == "Programa") {
            membros.push_back(Simbolo{
                "main",
                TipoDado::VOID,
                {},
                tabela.getNivelAtual()
            });
        }

        for (auto membroCtx : ctx->membro()) {
            if (auto constrCtx = dynamic_cast<MinhaLinguagemParser::Declaracao_construtorContext*>(membroCtx)) {
                visitDeclaracao_construtor(constrCtx);
            }
            else if (auto funcCtx = dynamic_cast<MinhaLinguagemParser::Declaracao_funcaoContext*>(membroCtx)) {
                visitDeclaracao_funcao(funcCtx);
            }
        }
        
        return nullptr;
    }

    antlrcpp::Any visitDeclaracao_funcao(MinhaLinguagemParser::Declaracao_funcaoContext *ctx) override {
        std::string funcName = ctx->ID->getText();
        if (!currentClassName.empty()) {
            funcName = currentClassName + "_" + funcName; // Prefixo de classe
        }

        std::cerr << "Visitando função: " << ctx->ID->getText() << "\n";            
        TipoDado retType = stringParaTipo(ctx->tipo()->getText());
        
        // Converter tipo de retorno
        Type *llvmRetType = getLLVMType(retType);
        if (!llvmRetType) {
            // Tratar erro
            return nullptr;
        }
        
        // Coletar tipos dos parâmetros
        std::vector<Type*> paramTypes;
        if (ctx->parametros()) {
            for (auto param : ctx->parametros()->parametro()) {
                TipoDado paramType = stringParaTipo(param->tipo()->getText());
                Type *llvmParamType = getLLVMType(paramType);
                if (llvmParamType) {
                    paramTypes.push_back(llvmParamType);
                }
            }
        }
        
        // Criar função
        FunctionType *funcType = FunctionType::get(
            llvmRetType, 
            paramTypes, 
            false
        );
        
        Function *func = Function::Create(
            funcType, 
            Function::ExternalLinkage, 
            funcName, 
            *module
        );
        
        // Criar bloco básico de entrada
        BasicBlock *entryBB = BasicBlock::Create(*context, "entry", func);
        builder->SetInsertPoint(entryBB);
        
        // Registrar parâmetros como variáveis nomeadas
        unsigned idx = 0;
        for (auto &arg : func->args()) {
            std::string paramName = ctx->parametros()->parametro(idx)->ID->getText();
            arg.setName(paramName);
            namedValues[paramName] = &arg;
            idx++;
        }
        
        // Armazenar contexto atual
        currentFunction = func;
        currentReturnType = llvmRetType;
        
        // Visitar corpo da função
        visit(ctx->bloco());
        
        // Adicionar retorno padrão se necessário
        if (llvmRetType->isVoidTy() && !builder->GetInsertBlock()->getTerminator()) {
            builder->CreateRetVoid();
        }
        
        // Verificar função
        verifyFunction(*func);
        
        // Limpar contexto
        currentFunction = nullptr;
        currentReturnType = nullptr;
        namedValues.clear();
        
        return nullptr;
    }

    antlrcpp::Any visitBloco(MinhaLinguagemParser::BlocoContext *ctx) override {
        // Entrar em novo escopo
        std::map<std::string, Value*> oldNamedValues = namedValues;
        
        // Visitar todas as declarações no bloco
        visitChildren(ctx);
        
        // Restaurar escopo anterior
        namedValues = oldNamedValues;
        return nullptr;
    }

    antlrcpp::Any visitDeclaracao_variavel(MinhaLinguagemParser::Declaracao_variavelContext *ctx) override {
        std::string varName = ctx->ID->getText();
        TipoDado varType = stringParaTipo(ctx->tipo()->getText());
        bool isArray = (ctx->ABRE_COLCHETES() != nullptr);
        
        // Obter tipo LLVM
        Type *llvmType = getLLVMType(varType);
        if (!llvmType) return nullptr;
        
        // Alocar variável
        Value *alloca = nullptr;
        if (currentFunction) {
            // Variável local
            IRBuilder<> tmpBuilder(&currentFunction->getEntryBlock(), currentFunction->getEntryBlock().begin());
            alloca = tmpBuilder.CreateAlloca(llvmType, nullptr, varName);
            builder->CreateStore(Constant::getNullValue(llvmType), alloca);
        } else {
            // Variável global
            module->getOrInsertGlobal(varName, llvmType);
            GlobalVariable *gVar = module->getNamedGlobal(varName);
            gVar->setInitializer(Constant::getNullValue(llvmType));
            alloca = gVar;
        }
        
        namedValues[varName] = alloca;
        
        // Tratar inicialização
        if (ctx->ATRIBUICAO() && ctx->expressao().size() > 0) {
            Value *initValue = std::any_cast<Value*>(visit(ctx->expressao(0)));
            if (initValue) {
                builder->CreateStore(initValue, alloca);
            }
        }
        
        return nullptr;
    }

    antlrcpp::Any visitAtribuicao(MinhaLinguagemParser::AtribuicaoContext *ctx) override {
        std::string varName = ctx->IDENTIFICADOR()->getText();
        Value *target = namedValues[varName];
        
        if (!target) {
            // Tratar erro: variável não encontrada
            return nullptr;
        }
        
        Value *value = std::any_cast<Value*>(visit(ctx->expressao()));
        if (value) {
            builder->CreateStore(value, target);
        }
        
        return value;
    }

    antlrcpp::Any visitIf(MinhaLinguagemParser::IfContext *ctx) override {
        Function *func = builder->GetInsertBlock()->getParent();
        
        // Criar blocos básicos
        BasicBlock *thenBB = BasicBlock::Create(*context, "then", func);
        BasicBlock *elseBB = BasicBlock::Create(*context, "else", func);
        BasicBlock *mergeBB = BasicBlock::Create(*context, "ifcont", func);
        
        // Gerar condição
        Value *condValue = std::any_cast<Value*>(visit(ctx->expressao()));
        if (!condValue) return nullptr;
        
        // Converter para booleano se necessário
        if (!condValue->getType()->isIntegerTy(1)) {
            condValue = builder->CreateICmpNE(
                condValue, 
                ConstantInt::get(condValue->getType(), 0),
                "ifcond"
            );
        }
        
        builder->CreateCondBr(condValue, thenBB, elseBB);
        
        // Bloco then
        builder->SetInsertPoint(thenBB);
        visit(ctx->bloco(0));
        builder->CreateBr(mergeBB);
        thenBB = builder->GetInsertBlock();
        
        // Bloco else
        builder->SetInsertPoint(elseBB);
        if (ctx->bloco().size() > 1) {
            visit(ctx->bloco(1));
        }
        builder->CreateBr(mergeBB);
        elseBB = builder->GetInsertBlock();
        
        // Merge
        builder->SetInsertPoint(mergeBB);
        return nullptr;
    }

    antlrcpp::Any visitWhile(MinhaLinguagemParser::WhileContext *ctx) override {
        Function *func = builder->GetInsertBlock()->getParent();
        
        // Criar blocos básicos
        BasicBlock *condBB = BasicBlock::Create(*context, "while.cond", func);
        BasicBlock *bodyBB = BasicBlock::Create(*context, "while.body", func);
        BasicBlock *endBB = BasicBlock::Create(*context, "while.end", func);
        
        // Salvar blocos para break/continue
        loopStartLabels.push("while.cond");
        loopEndLabels.push("while.end");
        
        // Entrar no bloco condicional
        builder->CreateBr(condBB);
        builder->SetInsertPoint(condBB);
        
        // Gerar condição
        Value *condValue = std::any_cast<Value*>(visit(ctx->expressao()));
        if (!condValue) return nullptr;
        
        // Converter para booleano
        if (!condValue->getType()->isIntegerTy(1)) {
            condValue = builder->CreateICmpNE(
                condValue, 
                ConstantInt::get(condValue->getType(), 0),
                "whilecond"
            );
        }
        
        builder->CreateCondBr(condValue, bodyBB, endBB);
        
        // Bloco do corpo
        builder->SetInsertPoint(bodyBB);
        visit(ctx->bloco());
        builder->CreateBr(condBB);
        
        // Bloco de término
        builder->SetInsertPoint(endBB);
        
        // Remover blocos da pilha
        loopStartLabels.pop();
        loopEndLabels.pop();
        
        return nullptr;
    }

    antlrcpp::Any visitReturnStmt(MinhaLinguagemParser::ReturnStmtContext *ctx) override {
        if (ctx->expressao()) {
            Value *retValue = std::any_cast<Value*>(visit(ctx->expressao()));
            if (retValue) {
                // Conversão implícita se necessário
                if (retValue->getType() != currentReturnType) {
                    if (currentReturnType->isFloatTy() && retValue->getType()->isIntegerTy()) {
                        retValue = builder->CreateSIToFP(retValue, currentReturnType);
                    }
                    // Outras conversões...
                }
                builder->CreateRet(retValue);
            }
        } else {
            builder->CreateRetVoid();
        }
        return nullptr;
    }

    antlrcpp::Any visitChamadaFuncao(MinhaLinguagemParser::ChamadaFuncaoContext *ctx) override {
        std::string funcName = ctx->IDENTIFICADOR()->getText();
        Function *callee = module->getFunction(funcName);
        
        if (!callee) {
            // Tratar erro: função não encontrada
            return nullptr;
        }
        
        // Coletar argumentos
        std::vector<Value*> args;
        for (auto expr : ctx->expressao()) {
            Value *argValue = std::any_cast<Value*>(visit(expr));
            if (argValue) {
                args.push_back(argValue);
            }
        }
        
        return builder->CreateCall(callee, args, "calltmp");
    }

    antlrcpp::Any visitNewVetor(MinhaLinguagemParser::NewVetorContext *ctx) override {
        TipoDado baseType = stringParaTipo(ctx->tipo_base()->getText());
        Value *sizeValue = std::any_cast<Value*>(visit(ctx->expressao()));
        
        if (!sizeValue) return nullptr;
        
        // Calcular tamanho em bytes
        Type *elementType = getBaseType(converterParaTipoVetorial(baseType));
        Value *typeSize = ConstantInt::get(i32Type, getTypeSize(elementType));
        Value *totalSize = builder->CreateMul(sizeValue, typeSize, "memsize");
        
        // Chamar malloc
        Value *mallocCall = builder->CreateCall(
            mallocFunc, 
            {builder->CreateIntCast(totalSize, i32Type, true)}, 
            "malloc"
        );
        
        // Fazer cast para o tipo apropriado
        Type *arrayType = getLLVMType(converterParaTipoVetorial(baseType));
        return builder->CreateBitCast(mallocCall, arrayType, "arrayptr");
    }

    antlrcpp::Any visitNewObjeto(MinhaLinguagemParser::NewObjetoContext *ctx) override {

        std::string constructorName = className + "_ctor"; // Nome diferenciado
        Function *constructor = module->getFunction(constructorName);
        
        std::string className = ctx->IDENTIFICADOR()->getText();
        StructType *classType = classTypes[className];
        
        if (!classType) {
            // Tratar erro: classe não definida
            return nullptr;
        }
        
        // Alocar memória
        Value *size = ConstantInt::get(i32Type, getTypeSize(classType));
        Value *mallocCall = builder->CreateCall(mallocFunc, {size}, "malloc");
        Value *objectPtr = builder->CreateBitCast(
            mallocCall, 
            classType->getPointerTo(), 
            "objectptr"
        );
        
        // Chamar construtor se existir
        std::string constructorName = className;
        Function *constructor = module->getFunction(constructorName);
        if (constructor) {
            std::vector<Value*> args;
            args.push_back(objectPtr);
            for (auto expr : ctx->expressao()) {
                Value *arg = std::any_cast<Value*>(visit(expr));
                if (arg) args.push_back(arg);
            }
            builder->CreateCall(constructor, args);
        }
        
        return objectPtr;
    }

    antlrcpp::Any visitAcessoVetor(MinhaLinguagemParser::AcessoVetorContext *ctx) override {
        Value *arrayPtr = namedValues[ctx->IDENTIFICADOR()->getText()];
        Value *index = std::any_cast<Value*>(visit(ctx->expressao()));
        
        if (!arrayPtr || !index) return nullptr;
        
        // Obter ponteiro para o elemento
        Value *indices[] = {index};
        return builder->CreateGEP(
            arrayPtr->getType()->getScalarType(),
            arrayPtr,
            indices,
            "elementptr"
        );
    }

    antlrcpp::Any visitBinaria(MinhaLinguagemParser::BinariaContext *ctx) override {
        Value *L = std::any_cast<Value*>(visit(ctx->expressao(0)));
        Value *R = std::any_cast<Value*>(visit(ctx->expressao(1)));
        
        if (!L || !R) return nullptr;
        
        std::string op = ctx->op->getText();
        
        if (op == "+") {
            if (L->getType()->isFloatingPointTy()) {
                return builder->CreateFAdd(L, R, "addtmp");
            } else {
                return builder->CreateAdd(L, R, "addtmp");
            }
        } else if (op == "-") {
            if (L->getType()->isFloatingPointTy()) {
                return builder->CreateFSub(L, R, "subtmp");
            } else {
                return builder->CreateSub(L, R, "subtmp");
            }
        } else if (op == "*") {
            if (L->getType()->isFloatingPointTy()) {
                return builder->CreateFMul(L, R, "multmp");
            } else {
                return builder->CreateMul(L, R, "multmp");
            }
        } else if (op == "/") {
            if (L->getType()->isFloatingPointTy()) {
                return builder->CreateFDiv(L, R, "divtmp");
            } else {
                return builder->CreateSDiv(L, R, "divtmp");
            }
        }
        // Outros operadores...
        
        return nullptr;
    }

    antlrcpp::Any visitInteiro(MinhaLinguagemParser::InteiroContext *ctx) override {
        int val = std::stoi(ctx->NUM_INT()->getText());
        return ConstantInt::get(i32Type, val);
    }

    antlrcpp::Any visitFloat(MinhaLinguagemParser::FloatContext *ctx) override {
        float val = std::stof(ctx->NUM_FLOAT()->getText());
        return ConstantFP::get(floatType, val);
    }

    antlrcpp::Any visitString(MinhaLinguagemParser::StringContext *ctx) override {
        std::string text = ctx->TEXTO()->getText();
        // Remover aspas
        text = text.substr(1, text.size() - 2);
        return builder->CreateGlobalStringPtr(text, "str");
    }

    // Adicione esta função para suporte ao 'for'
    antlrcpp::Any visitFor(MinhaLinguagemParser::ForContext* ctx) override {
        Function* func = builder->GetInsertBlock()->getParent();
        
        // Bloco de inicialização
        if (ctx->declaracao_variavel()) {
            visit(ctx->declaracao_variavel());
        } else if (ctx->expressao(0)) {
            visit(ctx->expressao(0));
        }
        
        BasicBlock* condBB = BasicBlock::Create(*context, "for.cond", func);
        BasicBlock* bodyBB = BasicBlock::Create(*context, "for.body", func);
        BasicBlock* endBB = BasicBlock::Create(*context, "for.end", func);
        
        builder->CreateBr(condBB);
        
        // Condição
        builder->SetInsertPoint(condBB);
        if (ctx->expressao(1)) {
            Value* cond = std::any_cast<Value*>(visit(ctx->expressao(1)));
            builder->CreateCondBr(cond, bodyBB, endBB);
        } else {
            builder->CreateBr(bodyBB); // Loop infinito se não houver condição
        }
        
        // Corpo
        builder->SetInsertPoint(bodyBB);
        visit(ctx->bloco());
        
        // Incremento
        if (ctx->expressao(2)) {
            visit(ctx->expressao(2));
        }
        
        builder->CreateBr(condBB);
        builder->SetInsertPoint(endBB);
        
        return nullptr;
    }

    // Adicione para vetores (exemplo de atribuição)
    antlrcpp::Any visitAtribuicaoVetor(MinhaLinguagemParser::AtribuicaoVetorContext* ctx) override {
        Value* array = std::any_cast<Value*>(visit(ctx->expressao(0)));
        Value* index = std::any_cast<Value*>(visit(ctx->expressao(1)));
        Value* value = std::any_cast<Value*>(visit(ctx->expressao(2)));
        Value* ptr = builder->CreateGEP(array, index, "elementptr");
        builder->CreateStore(value, ptr);
        return value;
    }

    antlrcpp::Any visitCharLiteral(MinhaLinguagemParser::CharLiteralContext* ctx) override {
        std::string text = ctx->getText();
        char val = text[1]; // Extrai o caractere
        return ConstantInt::get(i8Type, val);
    }

    antlrcpp::Any visitDeclaracao_construtor(MinhaLinguagemParser::Declaracao_construtorContext* ctx) override {
        std::string className = ctx->IDENTIFICADOR(0)->getText();    
        std::cerr << "GERANDO CONSTRUTOR: " << className << "\n";  // Log
 

        // Verificar se a struct da classe já foi definida
        StructType* classType = classTypes[className];
        if (!classType) {
            // Tratar erro: classe não definida
            return nullptr;
        }

        // 1. Coletar tipos de parâmetros
        std::vector<Type*> paramTypes;
        // Primeiro parâmetro: ponteiro 'this' (implícito)
        paramTypes.push_back(classType->getPointerTo());
        
        // Parâmetros adicionais
        if (ctx->parametros()) {
            for (auto param : ctx->parametros()->parametro()) {
                TipoDado paramType = stringParaTipo(param->tipo()->getText());
                Type* llvmType = getLLVMType(paramType);
                if (llvmType) {
                    paramTypes.push_back(llvmType);
                }
            }
        }

        // 2. Criar função construtora
        FunctionType* funcType = FunctionType::get(
            Type::getVoidTy(*context),  // Construtor não retorna valor
            paramTypes,
            false
        );
        
        Function* constructor = Function::Create(
            funcType,
            Function::ExternalLinkage,
            className,  // Mesmo nome da classe
            *module
        );

        // 3. Criar bloco de entrada
        BasicBlock* entryBB = BasicBlock::Create(*context, "entry", constructor);
        builder->SetInsertPoint(entryBB);

        // 4. Registrar parâmetros
        std::vector<Value*> args;
        auto argIt = constructor->arg_begin();
        
        // Primeiro argumento: 'this'
        Value* thisPtr = &*argIt++;
        thisPtr->setName("this");
        namedValues["this"] = thisPtr;
        args.push_back(thisPtr);
        
        // Demais argumentos
        if (ctx->parametros()) {
            int idx = 0;
            for (auto param : ctx->parametros()->parametro()) {
                Value* arg = &*argIt++;
                arg->setName(param->ID->getText());
                namedValues[param->ID->getText()] = arg;
                args.push_back(arg);
                idx++;
            }
        }

        // 5. Inicializar membros da classe
        Simbolo* classSymbol = tabela.buscarSimbolo(className);
        if (classSymbol) {
            int memberIdx = 0;
            for (const auto& member : classSymbol->membros) {
                if (member.categoria == Categoria::VARIAVEL) {
                    // Encontrar valor do parâmetro correspondente (se existir)
                    Value* initValue = nullptr;
                    for (size_t i = 0; i < args.size(); i++) {
                        if (i > 0 && args[i]->getName() == member.nome) {
                            initValue = args[i];
                            break;
                        }
                    }
                    
                    if (!initValue) {
                        // Inicializar com valor padrão
                        Type* memberType = getLLVMType(member.tipo, member.nomeClasse);
                        if (memberType) {
                            if (memberType->isIntegerTy()) {
                                initValue = ConstantInt::get(memberType, 0);
                            } else if (memberType->isFloatingPointTy()) {
                                initValue = ConstantFP::get(memberType, 0.0);
                            } else if (memberType->isPointerTy()) {
                                initValue = ConstantPointerNull::get(cast<PointerType>(memberType));
                            }
                        }
                    }

                    if (initValue) {
                        // Calcular endereço do membro
                        Value* memberPtr = builder->CreateStructGEP(
                            classType,
                            thisPtr,
                            memberIdx,
                            member.nome + "_ptr"
                        );
                        // Armazenar valor
                        builder->CreateStore(initValue, memberPtr);
                    }
                    memberIdx++;
                }
            }
        }

        // 6. Chamada à superclasse (se existir)
        if (ctx->DOIS_PONTOS()) {
            std::string superName = ctx->IDENTIFICADOR(1)->getText();
            Function* superCtor = module->getFunction(superName);
            if (superCtor) {
                std::vector<Value*> superArgs;
                superArgs.push_back(thisPtr);
                for (auto expr : ctx->expressao()) {
                    superArgs.push_back(std::any_cast<Value*>(visit(expr)));
                }
                builder->CreateCall(superCtor, superArgs);
            }
        }

        // 7. Finalizar construtor
        builder->CreateRetVoid();
        
        // Verificar e limpar
        verifyFunction(*constructor);
        
        // Limpar variáveis locais
        namedValues.clear();
        for (auto& arg : args) {
            namedValues.erase(arg->getName().str());
        }
        
        return nullptr;
    }
};  