grammar MinhaLinguagem;

programa: (declaracao_classe | declaracao_funcao)+ EOF;

declaracao_classe
    : 'class' ID=IDENTIFICADOR '{' membro* '}'
    ;

membro
    : declaracao_variavel
    | declaracao_funcao
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
    : declaracao_variavel
    | estrutura_controle
    | expressao ';'
    | 'return' expressao? ';'
    ;

estrutura_controle
    : 'if' '(' expressao ')' bloco ('else' bloco)?  # If  // Usar bloco em vez de declaracao
    | 'while' '(' expressao ')' bloco               # While
    | 'for' '(' declaracao_variavel expressao ';' expressao ')' bloco # For
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
    | 'new' tipo ('[' expressao ']')?                         # New 
    ;

tipo
    : 'int' ('[' ']')?    
    | 'float' ('[' ']')?  
    | 'char' ('[' ']')?   
    | 'string' ('[' ']')? 
    | 'void'
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