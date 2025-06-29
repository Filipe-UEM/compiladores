# Projeto Compilador com ANTLR

Este projeto é um compilador desenvolvido em C++ utilizando ANTLR para análise léxica e sintática.

## 📦 Pré-requisitos

Certifique-se de ter as seguintes dependências instaladas:

- ANTLR 4
- Java (para gerar o analisador léxico/sintático com ANTLR)
- CMake e Make
- Compilador C++ (ex: `g++`)
- Biblioteca ANTLR4 C++

### Instalar dependências para C++

```bash
sudo apt install cmake make g++ uuid-dev pkg-config
```

### Instalar o Runtime C++ do ANTLR

```bash
wget https://www.antlr.org/download/antlr4-cpp-runtime-4.13.1-source.zip
unzip antlr4-cpp-runtime-4.13.1-source.zip
cd antlr4-cpp-runtime-4.13.1/
mkdir build && cd build
cmake ..
make
sudo make install
```


### Configurar bibliotecas

```bash
sudo ldconfig
echo 'export LD_LIBRARY_PATH=/usr/local/lib:$LD_LIBRARY_PATH' >> ~/.bashrc
source ~/.bashrc
```

## 🔧 Compilando o Projeto

No diretório raiz do projeto, execute:

```bash
make clean
make
```

## 🚀 Executando o Projeto

Após a compilação, execute o parser com o seguinte comando:

```bash
LD_LIBRARY_PATH=/usr/local/lib ./parser exemplos/teste.txt
```
## teste