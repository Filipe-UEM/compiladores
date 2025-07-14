#pragma once
#include "Simbolo.h"
#include <unordered_map>
#include <vector>
#include <stdexcept>

class TabelaSimbolos {
    std::vector<std::unordered_map<std::string, Simbolo>> escopos;
    int nivelAtual = 0;

public:
    TabelaSimbolos() { entrarEscopo(); }
        
    int getNivelAtual() const { return nivelAtual; } // Adicione este getter

    void entrarEscopo() {
        escopos.push_back({});
        nivelAtual++;
    }
    
    void sairEscopo() {
        if (escopos.size() > 1) {
            escopos.pop_back();
            nivelAtual--;
        }
    }

    void imprimirTabela() const {
        for (const auto& escopo : escopos) {
            std::cout << "--- Escopo Nível " << escopos.size() << " ---\n";
            for (const auto& [nome, simbolo] : escopo) {
                std::cout << "  " << nome << " | Categoria: " << static_cast<int>(simbolo.categoria)
                        << " | Tipo: " << static_cast<int>(simbolo.tipo) << "\n";
            }
        }
    }

    bool inserirSimbolo(const Simbolo& simbolo) {
        auto& escopoAtual = escopos.back();
        return escopoAtual.emplace(simbolo.nome, simbolo).second;
    }

    Simbolo* buscarSimbolo(const std::string& nome) {
        // Busca segura em todos os escopos
        for (auto it = escopos.rbegin(); it != escopos.rend(); ++it) {
            auto found = it->find(nome);
            if (found != it->end()) {
                return &(found->second); // Retorna cópia segura
            }
        }
        return nullptr; // Não encontrado
    }

    // Busca apenas no escopo atual
    Simbolo* buscarNoEscopoAtual(const std::string& nome) {
        auto& escopoAtual = escopos.back();
        auto found = escopoAtual.find(nome);
        if (found != escopoAtual.end()) {
            return &found->second;
        }
        return nullptr;
    }

    Simbolo* buscarSimboloGlobal(const std::string& nome) {
        for (auto& escopo : escopos) {
            auto found = escopo.find(nome);
            if (found != escopo.end()) {
                return &found->second;
            }
        }
        return nullptr;
    }
};