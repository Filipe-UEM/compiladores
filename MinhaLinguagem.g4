grammar MinhaLinguagem;

programa: (declaracao_classe | declaracao_funcao)+ EOF;

declaracao_classe
    : (PUBLIC | PRIVATE | PROTECTED)? STATIC? 'class' ID=IDENTIFICADOR ('extends' IDENTIFICADOR)? '{' membro* '}'
    ;

membro
    : anotacao? declaracao_variavel
    | anotacao? declaracao_funcao
    | anotacao? declaracao_construtor  // Adicionado
    ;

// Regra do construtor:
declaracao_construtor
    : (PUBLIC|PRIVATE|PROTECTED)? IDENTIFICADOR '(' parametros? ')' 
      (DOIS_PONTOS IDENTIFICADOR '(' (expressao (',' expressao)*)? ')')? // Chamada de superclasse
      bloco
    ;

declaracao_funcao
    : tipo ID=IDENTIFICADOR '(' parametros? ')' bloco
    ;

parametros
    : parametro (',' parametro)*
    ;

parametro
    : tipo ID=IDENTIFICADOR
    ;

declaracao_variavel
    : tipo ID=IDENTIFICADOR ('[' expressao? ']')? ('=' expressao)? ';'  
    ;

bloco
    : '{' declaracao* '}'
    ;

declaracao
    : declaracao_variavel                                    # VarDecl
    | estrutura_controle                                     # ControleDecl
    | expressao ';'                                          # ExprStmt
    | 'return' expressao? ';'                                # ReturnStmt
    ;

estrutura_controle
    : 'if' '(' expressao ')' bloco ('else' bloco)?  # If
    | 'while' '(' expressao ')' bloco               # While
    | 'for' '(' (declaracao_variavel | expressao? ) ';' expressao? ';' expressao? ')' bloco # For
    ;

expressao
    : IDENTIFICADOR '=' expressao                             # Atribuicao
    | expressao op=('*' | '/') expressao                      # Binaria
    | expressao op=('+' | '-') expressao                      # Binaria
    | expressao op=('>' | '>=' | '<' | '<=') expressao        # Binaria
    | expressao op=('==' | '!=') expressao                    # Binaria
    | expressao op='&&' expressao                             # Binaria
    | expressao op='||' expressao                             # Binaria
    | '(' expressao ')'                                       # Grupo
    | IDENTIFICADOR '(' (expressao (',' expressao)*)? ')'     # ChamadaFuncao
    | IDENTIFICADOR                                           # Variavel
    | NUM_INT                                                 # Inteiro
    | NUM_FLOAT                                               # Float
    | TEXTO                                                   # String
    | IDENTIFICADOR '[' expressao ']'                         # AcessoVetor
    | 'new' IDENTIFICADOR '(' (expressao (',' expressao)*)? ')'  # NewObjeto  // Corrigido
    | 'new' tipo_base '[' expressao ']'                       # NewVetor     // Corrigido
    | expressao '.' IDENTIFICADOR                             # AcessoMembro
    | expressao '.' IDENTIFICADOR '(' (expressao (',' expressao)*)? ')' # ChamadaMetodo
    | expressao '.' IDENTIFICADOR '=' expressao                # AtribuicaoMembro
    | expressao '[' expressao ']' '=' expressao                # AtribuicaoVetor
    ;

// Corrigido para suportar tipos de classe
tipo_base
    : 'int'    
    | 'float'  
    | 'char'   
    | 'string' 
    | 'String' 
    | IDENTIFICADOR  // Suporte a tipos de classe
    ;

tipo
    : tipo_base ('[' ']')?  // Suporta vetores
    | 'void'
    ;

anotacao
    : OVERRIDE
    ;

// Tokens
PONTO_VIRGULA: ';';
VIRGULA: ',';
ABRE_PARENTESES: '(';
FECHA_PARENTESES: ')';
ABRE_CHAVES: '{';
FECHA_CHAVES: '}';
ATRIBUICAO: '=';
ABRE_COLCHETES: '[';
FECHA_COLCHETES: ']';
PONTO: '.';
DOIS_PONTOS: ':';

PUBLIC: 'public';
PRIVATE: 'private';
PROTECTED: 'protected';
STATIC: 'static';
STRING_TYPE: 'String';
OVERRIDE: '@Override';

MAIS: '+';
MENOS: '-';
MULT: '*';
DIV: '/';

MAIOR: '>';
MAIOR_IGUAL: '>=';
MENOR: '<';
MENOR_IGUAL: '<=';
IGUAL: '==';
DIFERENTE: '!=';

E_LOGICO: '&&';
OU_LOGICO: '||';

IF: 'if';
ELSE: 'else';
WHILE: 'while';
FOR: 'for';
CLASS: 'class';
RETURN: 'return';
INT: 'int';
FLOAT: 'float';
CHAR: 'char';
STRING: 'string';
VOID: 'void';

IDENTIFICADOR: [a-zA-Z_][a-zA-Z0-9_]*;
NUM_INT: [0-9]+;
NUM_FLOAT: [0-9]+ '.' [0-9]+;
TEXTO: '"' .*? '"';

COMENTARIO: '//' ~[\r\n]* -> skip;
COMENTARIO_BLOCO: '/*' .*? '*/' -> skip;
ESPACO: [ \t\r\n]+ -> skip;