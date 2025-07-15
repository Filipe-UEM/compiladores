#pragma once
#include <string>
#include <vector>

enum class TipoDado {
    INT, 
    FLOAT, 
    CHAR, 
    STRING, 
    VOID, 
    CLASSE, 
    POINTER, 
    CONSTRUTOR,
    VETOR_INT,    
    VETOR_FLOAT,  
    VETOR_CHAR,   
    VETOR_STRING, 
    INVALIDO
};

enum class Categoria {
    VARIAVEL, FUNCAO, CLASSE, PARAMETRO
};

struct Simbolo {
    std::string nome = "";
    TipoDado tipo = TipoDado::INVALIDO;
    Categoria categoria;
    bool isVetor = false;
    int nivelEscopo = 0;
    std::vector<TipoDado> tiposParametros = {};
    std::string nomeSuperClasse = "";
    std::string nomeClasse = "";
    std::vector<Simbolo> membros; 

    Simbolo() = default;

    // Construtor para variáveis
    Simbolo(std::string nome, TipoDado tipo, Categoria cat, bool isVetor, int nivel, std::string nomeClasse = "")
        : nome(nome), tipo(tipo), categoria(cat), isVetor(isVetor), 
          nivelEscopo(nivel), nomeClasse(nomeClasse) {}
    
    // Construtor para classes
    Simbolo(std::string nome, std::string nomeClasse, int nivel)
        : nome(nome), tipo(TipoDado::CLASSE), categoria(Categoria::CLASSE),
          isVetor(false), nivelEscopo(nivel), nomeClasse(nomeClasse) {}
    
    // Construtor para funções
    Simbolo(std::string nome, TipoDado tipo, std::vector<TipoDado> params, int nivel)
        : nome(nome), tipo(tipo), categoria(Categoria::FUNCAO), isVetor(false),
          nivelEscopo(nivel), tiposParametros(params) {
            categoria = Categoria::FUNCAO;
        }

};