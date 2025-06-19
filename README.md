# Projeto Compilador com ANTLR

Este projeto é um compilador desenvolvido em C++ utilizando ANTLR para análise léxica e sintática.

## 📦 Pré-requisitos

Certifique-se de ter as seguintes dependências instaladas:

- ANTLR 4
- Java (para gerar o analisador léxico/sintático com ANTLR)
- CMake e Make
- Compilador C++ (ex: `g++`)
- Biblioteca ANTLR4 C++

## 🔧 Compilando o Projeto

No diretório raiz do projeto, execute:

```bash
make clean
make


## 🚀 Executando o Projeto

Após a compilação, execute o parser com o seguinte comando:

bash
Copy
Edit
LD_LIBRARY_PATH=/usr/local/lib ./parser exemplos/teste.txt
