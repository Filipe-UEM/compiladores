#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <string>
#include <unordered_map>
#include <vector>
#include <stdexcept>

enum class SymbolType {
    VARIABLE,
    FUNCTION,
    CLASS,
    PARAMETER
};

struct Symbol {
    std::string name;
    std::string type;
    SymbolType symbolType;
    bool isArray;
    std::vector<std::string> parameters; // Para funções
    int scopeLevel;
};

class SymbolTable {
private:
    std::vector<std::unordered_map<std::string, Symbol>> scopes;
    int currentScope = 0;

public:
    SymbolTable() {
        enterScope(); // Escopo global
    }

    void enterScope() {
        scopes.push_back({});
        currentScope++;
    }

    void exitScope() {
        if (currentScope > 0) {
            scopes.pop_back();
            currentScope--;
        }
    }

    void addSymbol(const std::string& name, const std::string& type, SymbolType symbolType, bool isArray = false, const std::vector<std::string>& params = {}) {
        if (scopes.empty()) enterScope();
        
        if (scopes.back().count(name)) {
            throw std::runtime_error("Erro semântico: Símbolo '" + name + "' já declarado neste escopo");
        }
        
        scopes.back()[name] = {name, type, symbolType, isArray, params, currentScope};
    }

    Symbol* lookup(const std::string& name) {
        for (auto it = scopes.rbegin(); it != scopes.rend(); ++it) {
            if (it->count(name)) {
                return &(it->at(name));
            }
        }
        return nullptr;
    }

    bool isInCurrentScope(const std::string& name) {
        return !scopes.empty() && scopes.back().count(name);
    }
};

#endif