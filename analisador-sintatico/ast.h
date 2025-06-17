#ifndef AST_H
#define AST_H

#include <vector>
#include <string>
#include <iostream>
#include <memory>

class ASTNode {
public:
    virtual ~ASTNode() = default;
    virtual void print(int indent = 0) const = 0;
};

class ProgramNode : public ASTNode {
    std::vector<std::unique_ptr<ASTNode>> declarations;
public:
    void addDeclaration(std::unique_ptr<ASTNode> decl) {
        declarations.push_back(std::move(decl));
    }

    void print(int indent) const override {
        std::cout << std::string(indent, ' ') << "Programa:\n";
        for (const auto& decl : declarations) {
            decl->print(indent + 2);
        }
    }
};

class ClassNode : public ASTNode {
    std::string name;
    std::vector<std::unique_ptr<ASTNode>> members;
public:
    ClassNode(const std::string& name) : name(name) {}

    void addMember(std::unique_ptr<ASTNode> member) {
        members.push_back(std::move(member));
    }

    void print(int indent) const override {
        std::cout << std::string(indent, ' ') << "Classe: " << name << "\n";
        for (const auto& member : members) {
            member->print(indent + 2);
        }
    }
};

class FunctionNode : public ASTNode {
    std::string name;
    std::vector<std::unique_ptr<ASTNode>> body;
public:
    FunctionNode(const std::string& name) : name(name) {}

    void addStatement(std::unique_ptr<ASTNode> stmt) {
        body.push_back(std::move(stmt));
    }

    void print(int indent) const override {
        std::cout << std::string(indent, ' ') << "Função: " << name << "\n";
        for (const auto& stmt : body) {
            stmt->print(indent + 2);
        }
    }
};

class IfNode : public ASTNode {
    std::unique_ptr<ASTNode> condition;
    std::unique_ptr<ASTNode> trueBranch;
    std::unique_ptr<ASTNode> falseBranch;
public:
    IfNode(std::unique_ptr<ASTNode> cond, 
           std::unique_ptr<ASTNode> trueBr,
           std::unique_ptr<ASTNode> falseBr = nullptr)
        : condition(std::move(cond)), 
          trueBranch(std::move(trueBr)), 
          falseBranch(std::move(falseBr)) {}

    void print(int indent) const override {
        std::cout << std::string(indent, ' ') << "If:\n";
        
        std::cout << std::string(indent+2, ' ') << "Condição:\n";
        condition->print(indent+4);
        
        std::cout << std::string(indent+2, ' ') << "Bloco Verdadeiro:\n";
        trueBranch->print(indent+4);
        
        if (falseBranch) {
            std::cout << std::string(indent+2, ' ') << "Bloco Falso:\n";
            falseBranch->print(indent+4);
        }
    }
};

class WhileNode : public ASTNode {
    std::unique_ptr<ASTNode> condition;
    std::unique_ptr<ASTNode> body;
public:
    WhileNode(std::unique_ptr<ASTNode> cond, std::unique_ptr<ASTNode> b)
        : condition(std::move(cond)), body(std::move(b)) {}

    void print(int indent) const override {
        std::cout << std::string(indent, ' ') << "While:\n";
        
        std::cout << std::string(indent+2, ' ') << "Condição:\n";
        condition->print(indent+4);
        
        std::cout << std::string(indent+2, ' ') << "Corpo:\n";
        body->print(indent+4);
    }
};

class VariableDeclNode : public ASTNode {
    std::string type;
    std::string name;
    std::unique_ptr<ASTNode> initValue;
public:
    VariableDeclNode(const std::string& type, 
                     const std::string& name,
                     std::unique_ptr<ASTNode> init = nullptr)
        : type(type), name(name), initValue(std::move(init)) {}

    void print(int indent) const override {
        std::cout << std::string(indent, ' ') << "Declaração: " 
                  << type << " " << name;
        
        if (initValue) {
            std::cout << " =\n";
            initValue->print(indent + 2);
        } else {
            std::cout << "\n";
        }
    }
};

class AssignmentNode : public ASTNode {
    std::string varName;
    std::unique_ptr<ASTNode> value;
public:
    AssignmentNode(const std::string& name, std::unique_ptr<ASTNode> val)
        : varName(name), value(std::move(val)) {}

    void print(int indent) const override {
        std::cout << std::string(indent, ' ') << "Atribuição: " << varName << " =\n";
        value->print(indent + 2);
    }
};

class BinaryOpNode : public ASTNode {
    std::string op;
    std::unique_ptr<ASTNode> left;
    std::unique_ptr<ASTNode> right;
public:
    BinaryOpNode(const std::string& op,
                 std::unique_ptr<ASTNode> l,
                 std::unique_ptr<ASTNode> r)
        : op(op), left(std::move(l)), right(std::move(r)) {}

    void print(int indent) const override {
        std::cout << std::string(indent, ' ') << "Operação: " << op << "\n";
        std::cout << std::string(indent+2, ' ') << "Esquerda:\n";
        left->print(indent+4);
        std::cout << std::string(indent+2, ' ') << "Direita:\n";
        right->print(indent+4);
    }
};

class IdentifierNode : public ASTNode {
    std::string name;
public:
    IdentifierNode(const std::string& name) : name(name) {}

    void print(int indent) const override {
        std::cout << std::string(indent, ' ') << "Identificador: " << name << "\n";
    }
};

class LiteralNode : public ASTNode {
    std::string value;
    std::string type;
public:
    LiteralNode(const std::string& val, const std::string& type)
        : value(val), type(type) {}

    void print(int indent) const override {
        std::cout << std::string(indent, ' ') 
                  << "Literal [" << type << "]: " << value << "\n";
    }
};

extern std::unique_ptr<ProgramNode> programRoot;
#endif