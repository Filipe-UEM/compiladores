
// Generated from MinhaLinguagem.g4 by ANTLR 4.13.1


#include "MinhaLinguagemListener.h"
#include "MinhaLinguagemVisitor.h"

#include "MinhaLinguagemParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct MinhaLinguagemParserStaticData final {
  MinhaLinguagemParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  MinhaLinguagemParserStaticData(const MinhaLinguagemParserStaticData&) = delete;
  MinhaLinguagemParserStaticData(MinhaLinguagemParserStaticData&&) = delete;
  MinhaLinguagemParserStaticData& operator=(const MinhaLinguagemParserStaticData&) = delete;
  MinhaLinguagemParserStaticData& operator=(MinhaLinguagemParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag minhalinguagemParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
MinhaLinguagemParserStaticData *minhalinguagemParserStaticData = nullptr;

void minhalinguagemParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (minhalinguagemParserStaticData != nullptr) {
    return;
  }
#else
  assert(minhalinguagemParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<MinhaLinguagemParserStaticData>(
    std::vector<std::string>{
      "programa", "declaracao_classe", "membro", "declaracao_construtor", 
      "declaracao_funcao", "parametros", "parametro", "declaracao_variavel", 
      "bloco", "declaracao", "estrutura_controle", "expressao", "tipo_base", 
      "tipo", "anotacao", "funcaoMain"
    },
    std::vector<std::string>{
      "", "'extends'", "'new'", "'main'", "';'", "','", "'('", "')'", "'{'", 
      "'}'", "'='", "'['", "']'", "'.'", "':'", "'public'", "'private'", 
      "'protected'", "'static'", "'String'", "'@Override'", "'+'", "'-'", 
      "'*'", "'/'", "'>'", "'>='", "'<'", "'<='", "'=='", "'!='", "'&&'", 
      "'||'", "'if'", "'else'", "'while'", "'for'", "'class'", "'return'", 
      "'int'", "'float'", "'char'", "'string'", "'void'"
    },
    std::vector<std::string>{
      "", "", "", "", "PONTO_VIRGULA", "VIRGULA", "ABRE_PARENTESES", "FECHA_PARENTESES", 
      "ABRE_CHAVES", "FECHA_CHAVES", "ATRIBUICAO", "ABRE_COLCHETES", "FECHA_COLCHETES", 
      "PONTO", "DOIS_PONTOS", "PUBLIC", "PRIVATE", "PROTECTED", "STATIC", 
      "STRING_TYPE", "OVERRIDE", "MAIS", "MENOS", "MULT", "DIV", "MAIOR", 
      "MAIOR_IGUAL", "MENOR", "MENOR_IGUAL", "IGUAL", "DIFERENTE", "E_LOGICO", 
      "OU_LOGICO", "IF", "ELSE", "WHILE", "FOR", "CLASS", "RETURN", "INT", 
      "FLOAT", "CHAR", "STRING", "VOID", "IDENTIFICADOR", "NUM_INT", "NUM_FLOAT", 
      "TEXTO", "COMENTARIO", "COMENTARIO_BLOCO", "ESPACO", "CARACTERE"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,51,320,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,1,0,1,0,4,0,35,8,0,11,0,12,0,36,1,0,1,0,1,1,3,1,42,8,1,1,
  	1,3,1,45,8,1,1,1,1,1,1,1,1,1,3,1,51,8,1,1,1,1,1,5,1,55,8,1,10,1,12,1,
  	58,9,1,1,1,1,1,1,2,3,2,63,8,2,1,2,1,2,3,2,67,8,2,1,2,1,2,3,2,71,8,2,1,
  	2,3,2,74,8,2,1,3,3,3,77,8,3,1,3,1,3,1,3,3,3,82,8,3,1,3,1,3,1,3,1,3,1,
  	3,1,3,1,3,5,3,91,8,3,10,3,12,3,94,9,3,3,3,96,8,3,1,3,3,3,99,8,3,1,3,1,
  	3,1,4,1,4,1,4,1,4,3,4,107,8,4,1,4,1,4,1,4,1,5,1,5,1,5,5,5,115,8,5,10,
  	5,12,5,118,9,5,1,6,1,6,1,6,1,7,3,7,124,8,7,1,7,1,7,1,7,1,7,3,7,130,8,
  	7,1,7,3,7,133,8,7,1,7,1,7,3,7,137,8,7,1,7,1,7,1,8,1,8,5,8,143,8,8,10,
  	8,12,8,146,9,8,1,8,1,8,1,9,1,9,1,9,1,9,1,9,1,9,1,9,3,9,157,8,9,1,9,3,
  	9,160,8,9,1,10,1,10,1,10,1,10,1,10,1,10,1,10,3,10,169,8,10,1,10,1,10,
  	1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,3,10,181,8,10,1,10,3,10,184,8,
  	10,1,10,3,10,187,8,10,1,10,1,10,3,10,191,8,10,1,10,1,10,3,10,195,8,10,
  	1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,5,11,
  	210,8,11,10,11,12,11,213,9,11,3,11,215,8,11,1,11,1,11,1,11,1,11,1,11,
  	1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,5,11,233,8,11,
  	10,11,12,11,236,9,11,3,11,238,8,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,
  	1,11,3,11,248,8,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,
  	1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,
  	1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,
  	1,11,1,11,5,11,290,8,11,10,11,12,11,293,9,11,3,11,295,8,11,1,11,5,11,
  	298,8,11,10,11,12,11,301,9,11,1,12,1,12,1,13,1,13,1,13,3,13,308,8,13,
  	1,13,3,13,311,8,13,1,14,1,14,1,15,1,15,1,15,1,15,1,15,1,15,0,1,22,16,
  	0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,0,6,1,0,15,17,1,0,23,24,1,
  	0,21,22,1,0,25,28,1,0,29,30,3,0,19,19,39,42,44,44,365,0,34,1,0,0,0,2,
  	41,1,0,0,0,4,73,1,0,0,0,6,76,1,0,0,0,8,102,1,0,0,0,10,111,1,0,0,0,12,
  	119,1,0,0,0,14,123,1,0,0,0,16,140,1,0,0,0,18,159,1,0,0,0,20,194,1,0,0,
  	0,22,247,1,0,0,0,24,302,1,0,0,0,26,310,1,0,0,0,28,312,1,0,0,0,30,314,
  	1,0,0,0,32,35,3,2,1,0,33,35,3,8,4,0,34,32,1,0,0,0,34,33,1,0,0,0,35,36,
  	1,0,0,0,36,34,1,0,0,0,36,37,1,0,0,0,37,38,1,0,0,0,38,39,5,0,0,1,39,1,
  	1,0,0,0,40,42,7,0,0,0,41,40,1,0,0,0,41,42,1,0,0,0,42,44,1,0,0,0,43,45,
  	5,18,0,0,44,43,1,0,0,0,44,45,1,0,0,0,45,46,1,0,0,0,46,47,5,37,0,0,47,
  	50,5,44,0,0,48,49,5,1,0,0,49,51,5,44,0,0,50,48,1,0,0,0,50,51,1,0,0,0,
  	51,52,1,0,0,0,52,56,5,8,0,0,53,55,3,4,2,0,54,53,1,0,0,0,55,58,1,0,0,0,
  	56,54,1,0,0,0,56,57,1,0,0,0,57,59,1,0,0,0,58,56,1,0,0,0,59,60,5,9,0,0,
  	60,3,1,0,0,0,61,63,3,28,14,0,62,61,1,0,0,0,62,63,1,0,0,0,63,64,1,0,0,
  	0,64,74,3,14,7,0,65,67,3,28,14,0,66,65,1,0,0,0,66,67,1,0,0,0,67,68,1,
  	0,0,0,68,74,3,8,4,0,69,71,3,28,14,0,70,69,1,0,0,0,70,71,1,0,0,0,71,72,
  	1,0,0,0,72,74,3,6,3,0,73,62,1,0,0,0,73,66,1,0,0,0,73,70,1,0,0,0,74,5,
  	1,0,0,0,75,77,7,0,0,0,76,75,1,0,0,0,76,77,1,0,0,0,77,78,1,0,0,0,78,79,
  	5,44,0,0,79,81,5,6,0,0,80,82,3,10,5,0,81,80,1,0,0,0,81,82,1,0,0,0,82,
  	83,1,0,0,0,83,98,5,7,0,0,84,85,5,14,0,0,85,86,5,44,0,0,86,95,5,6,0,0,
  	87,92,3,22,11,0,88,89,5,5,0,0,89,91,3,22,11,0,90,88,1,0,0,0,91,94,1,0,
  	0,0,92,90,1,0,0,0,92,93,1,0,0,0,93,96,1,0,0,0,94,92,1,0,0,0,95,87,1,0,
  	0,0,95,96,1,0,0,0,96,97,1,0,0,0,97,99,5,7,0,0,98,84,1,0,0,0,98,99,1,0,
  	0,0,99,100,1,0,0,0,100,101,3,16,8,0,101,7,1,0,0,0,102,103,3,26,13,0,103,
  	104,5,44,0,0,104,106,5,6,0,0,105,107,3,10,5,0,106,105,1,0,0,0,106,107,
  	1,0,0,0,107,108,1,0,0,0,108,109,5,7,0,0,109,110,3,16,8,0,110,9,1,0,0,
  	0,111,116,3,12,6,0,112,113,5,5,0,0,113,115,3,12,6,0,114,112,1,0,0,0,115,
  	118,1,0,0,0,116,114,1,0,0,0,116,117,1,0,0,0,117,11,1,0,0,0,118,116,1,
  	0,0,0,119,120,3,26,13,0,120,121,5,44,0,0,121,13,1,0,0,0,122,124,7,0,0,
  	0,123,122,1,0,0,0,123,124,1,0,0,0,124,125,1,0,0,0,125,126,3,26,13,0,126,
  	132,5,44,0,0,127,129,5,11,0,0,128,130,3,22,11,0,129,128,1,0,0,0,129,130,
  	1,0,0,0,130,131,1,0,0,0,131,133,5,12,0,0,132,127,1,0,0,0,132,133,1,0,
  	0,0,133,136,1,0,0,0,134,135,5,10,0,0,135,137,3,22,11,0,136,134,1,0,0,
  	0,136,137,1,0,0,0,137,138,1,0,0,0,138,139,5,4,0,0,139,15,1,0,0,0,140,
  	144,5,8,0,0,141,143,3,18,9,0,142,141,1,0,0,0,143,146,1,0,0,0,144,142,
  	1,0,0,0,144,145,1,0,0,0,145,147,1,0,0,0,146,144,1,0,0,0,147,148,5,9,0,
  	0,148,17,1,0,0,0,149,160,3,14,7,0,150,160,3,20,10,0,151,152,3,22,11,0,
  	152,153,5,4,0,0,153,160,1,0,0,0,154,156,5,38,0,0,155,157,3,22,11,0,156,
  	155,1,0,0,0,156,157,1,0,0,0,157,158,1,0,0,0,158,160,5,4,0,0,159,149,1,
  	0,0,0,159,150,1,0,0,0,159,151,1,0,0,0,159,154,1,0,0,0,160,19,1,0,0,0,
  	161,162,5,33,0,0,162,163,5,6,0,0,163,164,3,22,11,0,164,165,5,7,0,0,165,
  	168,3,16,8,0,166,167,5,34,0,0,167,169,3,16,8,0,168,166,1,0,0,0,168,169,
  	1,0,0,0,169,195,1,0,0,0,170,171,5,35,0,0,171,172,5,6,0,0,172,173,3,22,
  	11,0,173,174,5,7,0,0,174,175,3,16,8,0,175,195,1,0,0,0,176,177,5,36,0,
  	0,177,183,5,6,0,0,178,184,3,14,7,0,179,181,3,22,11,0,180,179,1,0,0,0,
  	180,181,1,0,0,0,181,182,1,0,0,0,182,184,5,4,0,0,183,178,1,0,0,0,183,180,
  	1,0,0,0,184,186,1,0,0,0,185,187,3,22,11,0,186,185,1,0,0,0,186,187,1,0,
  	0,0,187,188,1,0,0,0,188,190,5,4,0,0,189,191,3,22,11,0,190,189,1,0,0,0,
  	190,191,1,0,0,0,191,192,1,0,0,0,192,193,5,7,0,0,193,195,3,16,8,0,194,
  	161,1,0,0,0,194,170,1,0,0,0,194,176,1,0,0,0,195,21,1,0,0,0,196,197,6,
  	11,-1,0,197,198,5,44,0,0,198,199,5,10,0,0,199,248,3,22,11,21,200,201,
  	5,6,0,0,201,202,3,22,11,0,202,203,5,7,0,0,203,248,1,0,0,0,204,205,5,44,
  	0,0,205,214,5,6,0,0,206,211,3,22,11,0,207,208,5,5,0,0,208,210,3,22,11,
  	0,209,207,1,0,0,0,210,213,1,0,0,0,211,209,1,0,0,0,211,212,1,0,0,0,212,
  	215,1,0,0,0,213,211,1,0,0,0,214,206,1,0,0,0,214,215,1,0,0,0,215,216,1,
  	0,0,0,216,248,5,7,0,0,217,248,5,44,0,0,218,248,5,45,0,0,219,248,5,46,
  	0,0,220,248,5,47,0,0,221,222,5,44,0,0,222,223,5,11,0,0,223,224,3,22,11,
  	0,224,225,5,12,0,0,225,248,1,0,0,0,226,227,5,2,0,0,227,228,5,44,0,0,228,
  	237,5,6,0,0,229,234,3,22,11,0,230,231,5,5,0,0,231,233,3,22,11,0,232,230,
  	1,0,0,0,233,236,1,0,0,0,234,232,1,0,0,0,234,235,1,0,0,0,235,238,1,0,0,
  	0,236,234,1,0,0,0,237,229,1,0,0,0,237,238,1,0,0,0,238,239,1,0,0,0,239,
  	248,5,7,0,0,240,241,5,2,0,0,241,242,3,24,12,0,242,243,5,11,0,0,243,244,
  	3,22,11,0,244,245,5,12,0,0,245,248,1,0,0,0,246,248,5,51,0,0,247,196,1,
  	0,0,0,247,200,1,0,0,0,247,204,1,0,0,0,247,217,1,0,0,0,247,218,1,0,0,0,
  	247,219,1,0,0,0,247,220,1,0,0,0,247,221,1,0,0,0,247,226,1,0,0,0,247,240,
  	1,0,0,0,247,246,1,0,0,0,248,299,1,0,0,0,249,250,10,20,0,0,250,251,7,1,
  	0,0,251,298,3,22,11,21,252,253,10,19,0,0,253,254,7,2,0,0,254,298,3,22,
  	11,20,255,256,10,18,0,0,256,257,7,3,0,0,257,298,3,22,11,19,258,259,10,
  	17,0,0,259,260,7,4,0,0,260,298,3,22,11,18,261,262,10,16,0,0,262,263,5,
  	31,0,0,263,298,3,22,11,17,264,265,10,15,0,0,265,266,5,32,0,0,266,298,
  	3,22,11,16,267,268,10,3,0,0,268,269,5,13,0,0,269,270,5,44,0,0,270,271,
  	5,10,0,0,271,298,3,22,11,4,272,273,10,2,0,0,273,274,5,11,0,0,274,275,
  	3,22,11,0,275,276,5,12,0,0,276,277,5,10,0,0,277,278,3,22,11,3,278,298,
  	1,0,0,0,279,280,10,5,0,0,280,281,5,13,0,0,281,298,5,44,0,0,282,283,10,
  	4,0,0,283,284,5,13,0,0,284,285,5,44,0,0,285,294,5,6,0,0,286,291,3,22,
  	11,0,287,288,5,5,0,0,288,290,3,22,11,0,289,287,1,0,0,0,290,293,1,0,0,
  	0,291,289,1,0,0,0,291,292,1,0,0,0,292,295,1,0,0,0,293,291,1,0,0,0,294,
  	286,1,0,0,0,294,295,1,0,0,0,295,296,1,0,0,0,296,298,5,7,0,0,297,249,1,
  	0,0,0,297,252,1,0,0,0,297,255,1,0,0,0,297,258,1,0,0,0,297,261,1,0,0,0,
  	297,264,1,0,0,0,297,267,1,0,0,0,297,272,1,0,0,0,297,279,1,0,0,0,297,282,
  	1,0,0,0,298,301,1,0,0,0,299,297,1,0,0,0,299,300,1,0,0,0,300,23,1,0,0,
  	0,301,299,1,0,0,0,302,303,7,5,0,0,303,25,1,0,0,0,304,307,3,24,12,0,305,
  	306,5,11,0,0,306,308,5,12,0,0,307,305,1,0,0,0,307,308,1,0,0,0,308,311,
  	1,0,0,0,309,311,5,43,0,0,310,304,1,0,0,0,310,309,1,0,0,0,311,27,1,0,0,
  	0,312,313,5,20,0,0,313,29,1,0,0,0,314,315,5,3,0,0,315,316,5,6,0,0,316,
  	317,5,7,0,0,317,318,3,16,8,0,318,31,1,0,0,0,41,34,36,41,44,50,56,62,66,
  	70,73,76,81,92,95,98,106,116,123,129,132,136,144,156,159,168,180,183,
  	186,190,194,211,214,234,237,247,291,294,297,299,307,310
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  minhalinguagemParserStaticData = staticData.release();
}

}

MinhaLinguagemParser::MinhaLinguagemParser(TokenStream *input) : MinhaLinguagemParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

MinhaLinguagemParser::MinhaLinguagemParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  MinhaLinguagemParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *minhalinguagemParserStaticData->atn, minhalinguagemParserStaticData->decisionToDFA, minhalinguagemParserStaticData->sharedContextCache, options);
}

MinhaLinguagemParser::~MinhaLinguagemParser() {
  delete _interpreter;
}

const atn::ATN& MinhaLinguagemParser::getATN() const {
  return *minhalinguagemParserStaticData->atn;
}

std::string MinhaLinguagemParser::getGrammarFileName() const {
  return "MinhaLinguagem.g4";
}

const std::vector<std::string>& MinhaLinguagemParser::getRuleNames() const {
  return minhalinguagemParserStaticData->ruleNames;
}

const dfa::Vocabulary& MinhaLinguagemParser::getVocabulary() const {
  return minhalinguagemParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView MinhaLinguagemParser::getSerializedATN() const {
  return minhalinguagemParserStaticData->serializedATN;
}


//----------------- ProgramaContext ------------------------------------------------------------------

MinhaLinguagemParser::ProgramaContext::ProgramaContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MinhaLinguagemParser::ProgramaContext::EOF() {
  return getToken(MinhaLinguagemParser::EOF, 0);
}

std::vector<MinhaLinguagemParser::Declaracao_classeContext *> MinhaLinguagemParser::ProgramaContext::declaracao_classe() {
  return getRuleContexts<MinhaLinguagemParser::Declaracao_classeContext>();
}

MinhaLinguagemParser::Declaracao_classeContext* MinhaLinguagemParser::ProgramaContext::declaracao_classe(size_t i) {
  return getRuleContext<MinhaLinguagemParser::Declaracao_classeContext>(i);
}

std::vector<MinhaLinguagemParser::Declaracao_funcaoContext *> MinhaLinguagemParser::ProgramaContext::declaracao_funcao() {
  return getRuleContexts<MinhaLinguagemParser::Declaracao_funcaoContext>();
}

MinhaLinguagemParser::Declaracao_funcaoContext* MinhaLinguagemParser::ProgramaContext::declaracao_funcao(size_t i) {
  return getRuleContext<MinhaLinguagemParser::Declaracao_funcaoContext>(i);
}


size_t MinhaLinguagemParser::ProgramaContext::getRuleIndex() const {
  return MinhaLinguagemParser::RulePrograma;
}

void MinhaLinguagemParser::ProgramaContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MinhaLinguagemListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrograma(this);
}

void MinhaLinguagemParser::ProgramaContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MinhaLinguagemListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrograma(this);
}


std::any MinhaLinguagemParser::ProgramaContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MinhaLinguagemVisitor*>(visitor))
    return parserVisitor->visitPrograma(this);
  else
    return visitor->visitChildren(this);
}

MinhaLinguagemParser::ProgramaContext* MinhaLinguagemParser::programa() {
  ProgramaContext *_localctx = _tracker.createInstance<ProgramaContext>(_ctx, getState());
  enterRule(_localctx, 0, MinhaLinguagemParser::RulePrograma);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(34); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(34);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case MinhaLinguagemParser::PUBLIC:
        case MinhaLinguagemParser::PRIVATE:
        case MinhaLinguagemParser::PROTECTED:
        case MinhaLinguagemParser::STATIC:
        case MinhaLinguagemParser::CLASS: {
          setState(32);
          declaracao_classe();
          break;
        }

        case MinhaLinguagemParser::STRING_TYPE:
        case MinhaLinguagemParser::INT:
        case MinhaLinguagemParser::FLOAT:
        case MinhaLinguagemParser::CHAR:
        case MinhaLinguagemParser::STRING:
        case MinhaLinguagemParser::VOID:
        case MinhaLinguagemParser::IDENTIFICADOR: {
          setState(33);
          declaracao_funcao();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(36); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 34772056244224) != 0));
    setState(38);
    match(MinhaLinguagemParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Declaracao_classeContext ------------------------------------------------------------------

MinhaLinguagemParser::Declaracao_classeContext::Declaracao_classeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MinhaLinguagemParser::Declaracao_classeContext::CLASS() {
  return getToken(MinhaLinguagemParser::CLASS, 0);
}

tree::TerminalNode* MinhaLinguagemParser::Declaracao_classeContext::ABRE_CHAVES() {
  return getToken(MinhaLinguagemParser::ABRE_CHAVES, 0);
}

tree::TerminalNode* MinhaLinguagemParser::Declaracao_classeContext::FECHA_CHAVES() {
  return getToken(MinhaLinguagemParser::FECHA_CHAVES, 0);
}

std::vector<tree::TerminalNode *> MinhaLinguagemParser::Declaracao_classeContext::IDENTIFICADOR() {
  return getTokens(MinhaLinguagemParser::IDENTIFICADOR);
}

tree::TerminalNode* MinhaLinguagemParser::Declaracao_classeContext::IDENTIFICADOR(size_t i) {
  return getToken(MinhaLinguagemParser::IDENTIFICADOR, i);
}

tree::TerminalNode* MinhaLinguagemParser::Declaracao_classeContext::STATIC() {
  return getToken(MinhaLinguagemParser::STATIC, 0);
}

std::vector<MinhaLinguagemParser::MembroContext *> MinhaLinguagemParser::Declaracao_classeContext::membro() {
  return getRuleContexts<MinhaLinguagemParser::MembroContext>();
}

MinhaLinguagemParser::MembroContext* MinhaLinguagemParser::Declaracao_classeContext::membro(size_t i) {
  return getRuleContext<MinhaLinguagemParser::MembroContext>(i);
}

tree::TerminalNode* MinhaLinguagemParser::Declaracao_classeContext::PUBLIC() {
  return getToken(MinhaLinguagemParser::PUBLIC, 0);
}

tree::TerminalNode* MinhaLinguagemParser::Declaracao_classeContext::PRIVATE() {
  return getToken(MinhaLinguagemParser::PRIVATE, 0);
}

tree::TerminalNode* MinhaLinguagemParser::Declaracao_classeContext::PROTECTED() {
  return getToken(MinhaLinguagemParser::PROTECTED, 0);
}


size_t MinhaLinguagemParser::Declaracao_classeContext::getRuleIndex() const {
  return MinhaLinguagemParser::RuleDeclaracao_classe;
}

void MinhaLinguagemParser::Declaracao_classeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MinhaLinguagemListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclaracao_classe(this);
}

void MinhaLinguagemParser::Declaracao_classeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MinhaLinguagemListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclaracao_classe(this);
}


std::any MinhaLinguagemParser::Declaracao_classeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MinhaLinguagemVisitor*>(visitor))
    return parserVisitor->visitDeclaracao_classe(this);
  else
    return visitor->visitChildren(this);
}

MinhaLinguagemParser::Declaracao_classeContext* MinhaLinguagemParser::declaracao_classe() {
  Declaracao_classeContext *_localctx = _tracker.createInstance<Declaracao_classeContext>(_ctx, getState());
  enterRule(_localctx, 2, MinhaLinguagemParser::RuleDeclaracao_classe);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(41);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 229376) != 0)) {
      setState(40);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 229376) != 0))) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
    setState(44);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MinhaLinguagemParser::STATIC) {
      setState(43);
      match(MinhaLinguagemParser::STATIC);
    }
    setState(46);
    match(MinhaLinguagemParser::CLASS);
    setState(47);
    antlrcpp::downCast<Declaracao_classeContext *>(_localctx)->ID = match(MinhaLinguagemParser::IDENTIFICADOR);
    setState(50);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MinhaLinguagemParser::T__0) {
      setState(48);
      match(MinhaLinguagemParser::T__0);
      setState(49);
      match(MinhaLinguagemParser::IDENTIFICADOR);
    }
    setState(52);
    match(MinhaLinguagemParser::ABRE_CHAVES);
    setState(56);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 34634618077184) != 0)) {
      setState(53);
      membro();
      setState(58);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(59);
    match(MinhaLinguagemParser::FECHA_CHAVES);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MembroContext ------------------------------------------------------------------

MinhaLinguagemParser::MembroContext::MembroContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MinhaLinguagemParser::Declaracao_variavelContext* MinhaLinguagemParser::MembroContext::declaracao_variavel() {
  return getRuleContext<MinhaLinguagemParser::Declaracao_variavelContext>(0);
}

MinhaLinguagemParser::AnotacaoContext* MinhaLinguagemParser::MembroContext::anotacao() {
  return getRuleContext<MinhaLinguagemParser::AnotacaoContext>(0);
}

MinhaLinguagemParser::Declaracao_funcaoContext* MinhaLinguagemParser::MembroContext::declaracao_funcao() {
  return getRuleContext<MinhaLinguagemParser::Declaracao_funcaoContext>(0);
}

MinhaLinguagemParser::Declaracao_construtorContext* MinhaLinguagemParser::MembroContext::declaracao_construtor() {
  return getRuleContext<MinhaLinguagemParser::Declaracao_construtorContext>(0);
}


size_t MinhaLinguagemParser::MembroContext::getRuleIndex() const {
  return MinhaLinguagemParser::RuleMembro;
}

void MinhaLinguagemParser::MembroContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MinhaLinguagemListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMembro(this);
}

void MinhaLinguagemParser::MembroContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MinhaLinguagemListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMembro(this);
}


std::any MinhaLinguagemParser::MembroContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MinhaLinguagemVisitor*>(visitor))
    return parserVisitor->visitMembro(this);
  else
    return visitor->visitChildren(this);
}

MinhaLinguagemParser::MembroContext* MinhaLinguagemParser::membro() {
  MembroContext *_localctx = _tracker.createInstance<MembroContext>(_ctx, getState());
  enterRule(_localctx, 4, MinhaLinguagemParser::RuleMembro);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(73);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(62);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == MinhaLinguagemParser::OVERRIDE) {
        setState(61);
        anotacao();
      }
      setState(64);
      declaracao_variavel();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(66);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == MinhaLinguagemParser::OVERRIDE) {
        setState(65);
        anotacao();
      }
      setState(68);
      declaracao_funcao();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(70);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == MinhaLinguagemParser::OVERRIDE) {
        setState(69);
        anotacao();
      }
      setState(72);
      declaracao_construtor();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Declaracao_construtorContext ------------------------------------------------------------------

MinhaLinguagemParser::Declaracao_construtorContext::Declaracao_construtorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> MinhaLinguagemParser::Declaracao_construtorContext::IDENTIFICADOR() {
  return getTokens(MinhaLinguagemParser::IDENTIFICADOR);
}

tree::TerminalNode* MinhaLinguagemParser::Declaracao_construtorContext::IDENTIFICADOR(size_t i) {
  return getToken(MinhaLinguagemParser::IDENTIFICADOR, i);
}

std::vector<tree::TerminalNode *> MinhaLinguagemParser::Declaracao_construtorContext::ABRE_PARENTESES() {
  return getTokens(MinhaLinguagemParser::ABRE_PARENTESES);
}

tree::TerminalNode* MinhaLinguagemParser::Declaracao_construtorContext::ABRE_PARENTESES(size_t i) {
  return getToken(MinhaLinguagemParser::ABRE_PARENTESES, i);
}

std::vector<tree::TerminalNode *> MinhaLinguagemParser::Declaracao_construtorContext::FECHA_PARENTESES() {
  return getTokens(MinhaLinguagemParser::FECHA_PARENTESES);
}

tree::TerminalNode* MinhaLinguagemParser::Declaracao_construtorContext::FECHA_PARENTESES(size_t i) {
  return getToken(MinhaLinguagemParser::FECHA_PARENTESES, i);
}

MinhaLinguagemParser::BlocoContext* MinhaLinguagemParser::Declaracao_construtorContext::bloco() {
  return getRuleContext<MinhaLinguagemParser::BlocoContext>(0);
}

MinhaLinguagemParser::ParametrosContext* MinhaLinguagemParser::Declaracao_construtorContext::parametros() {
  return getRuleContext<MinhaLinguagemParser::ParametrosContext>(0);
}

tree::TerminalNode* MinhaLinguagemParser::Declaracao_construtorContext::DOIS_PONTOS() {
  return getToken(MinhaLinguagemParser::DOIS_PONTOS, 0);
}

tree::TerminalNode* MinhaLinguagemParser::Declaracao_construtorContext::PUBLIC() {
  return getToken(MinhaLinguagemParser::PUBLIC, 0);
}

tree::TerminalNode* MinhaLinguagemParser::Declaracao_construtorContext::PRIVATE() {
  return getToken(MinhaLinguagemParser::PRIVATE, 0);
}

tree::TerminalNode* MinhaLinguagemParser::Declaracao_construtorContext::PROTECTED() {
  return getToken(MinhaLinguagemParser::PROTECTED, 0);
}

std::vector<MinhaLinguagemParser::ExpressaoContext *> MinhaLinguagemParser::Declaracao_construtorContext::expressao() {
  return getRuleContexts<MinhaLinguagemParser::ExpressaoContext>();
}

MinhaLinguagemParser::ExpressaoContext* MinhaLinguagemParser::Declaracao_construtorContext::expressao(size_t i) {
  return getRuleContext<MinhaLinguagemParser::ExpressaoContext>(i);
}

std::vector<tree::TerminalNode *> MinhaLinguagemParser::Declaracao_construtorContext::VIRGULA() {
  return getTokens(MinhaLinguagemParser::VIRGULA);
}

tree::TerminalNode* MinhaLinguagemParser::Declaracao_construtorContext::VIRGULA(size_t i) {
  return getToken(MinhaLinguagemParser::VIRGULA, i);
}


size_t MinhaLinguagemParser::Declaracao_construtorContext::getRuleIndex() const {
  return MinhaLinguagemParser::RuleDeclaracao_construtor;
}

void MinhaLinguagemParser::Declaracao_construtorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MinhaLinguagemListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclaracao_construtor(this);
}

void MinhaLinguagemParser::Declaracao_construtorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MinhaLinguagemListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclaracao_construtor(this);
}


std::any MinhaLinguagemParser::Declaracao_construtorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MinhaLinguagemVisitor*>(visitor))
    return parserVisitor->visitDeclaracao_construtor(this);
  else
    return visitor->visitChildren(this);
}

MinhaLinguagemParser::Declaracao_construtorContext* MinhaLinguagemParser::declaracao_construtor() {
  Declaracao_construtorContext *_localctx = _tracker.createInstance<Declaracao_construtorContext>(_ctx, getState());
  enterRule(_localctx, 6, MinhaLinguagemParser::RuleDeclaracao_construtor);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(76);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 229376) != 0)) {
      setState(75);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 229376) != 0))) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
    setState(78);
    match(MinhaLinguagemParser::IDENTIFICADOR);
    setState(79);
    match(MinhaLinguagemParser::ABRE_PARENTESES);
    setState(81);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 34634616799232) != 0)) {
      setState(80);
      parametros();
    }
    setState(83);
    match(MinhaLinguagemParser::FECHA_PARENTESES);
    setState(98);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MinhaLinguagemParser::DOIS_PONTOS) {
      setState(84);
      match(MinhaLinguagemParser::DOIS_PONTOS);
      setState(85);
      match(MinhaLinguagemParser::IDENTIFICADOR);
      setState(86);
      match(MinhaLinguagemParser::ABRE_PARENTESES);
      setState(95);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 2515682604351556) != 0)) {
        setState(87);
        expressao(0);
        setState(92);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == MinhaLinguagemParser::VIRGULA) {
          setState(88);
          match(MinhaLinguagemParser::VIRGULA);
          setState(89);
          expressao(0);
          setState(94);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(97);
      match(MinhaLinguagemParser::FECHA_PARENTESES);
    }
    setState(100);
    bloco();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Declaracao_funcaoContext ------------------------------------------------------------------

MinhaLinguagemParser::Declaracao_funcaoContext::Declaracao_funcaoContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MinhaLinguagemParser::TipoContext* MinhaLinguagemParser::Declaracao_funcaoContext::tipo() {
  return getRuleContext<MinhaLinguagemParser::TipoContext>(0);
}

tree::TerminalNode* MinhaLinguagemParser::Declaracao_funcaoContext::ABRE_PARENTESES() {
  return getToken(MinhaLinguagemParser::ABRE_PARENTESES, 0);
}

tree::TerminalNode* MinhaLinguagemParser::Declaracao_funcaoContext::FECHA_PARENTESES() {
  return getToken(MinhaLinguagemParser::FECHA_PARENTESES, 0);
}

MinhaLinguagemParser::BlocoContext* MinhaLinguagemParser::Declaracao_funcaoContext::bloco() {
  return getRuleContext<MinhaLinguagemParser::BlocoContext>(0);
}

tree::TerminalNode* MinhaLinguagemParser::Declaracao_funcaoContext::IDENTIFICADOR() {
  return getToken(MinhaLinguagemParser::IDENTIFICADOR, 0);
}

MinhaLinguagemParser::ParametrosContext* MinhaLinguagemParser::Declaracao_funcaoContext::parametros() {
  return getRuleContext<MinhaLinguagemParser::ParametrosContext>(0);
}


size_t MinhaLinguagemParser::Declaracao_funcaoContext::getRuleIndex() const {
  return MinhaLinguagemParser::RuleDeclaracao_funcao;
}

void MinhaLinguagemParser::Declaracao_funcaoContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MinhaLinguagemListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclaracao_funcao(this);
}

void MinhaLinguagemParser::Declaracao_funcaoContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MinhaLinguagemListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclaracao_funcao(this);
}


std::any MinhaLinguagemParser::Declaracao_funcaoContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MinhaLinguagemVisitor*>(visitor))
    return parserVisitor->visitDeclaracao_funcao(this);
  else
    return visitor->visitChildren(this);
}

MinhaLinguagemParser::Declaracao_funcaoContext* MinhaLinguagemParser::declaracao_funcao() {
  Declaracao_funcaoContext *_localctx = _tracker.createInstance<Declaracao_funcaoContext>(_ctx, getState());
  enterRule(_localctx, 8, MinhaLinguagemParser::RuleDeclaracao_funcao);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(102);
    tipo();
    setState(103);
    antlrcpp::downCast<Declaracao_funcaoContext *>(_localctx)->ID = match(MinhaLinguagemParser::IDENTIFICADOR);
    setState(104);
    match(MinhaLinguagemParser::ABRE_PARENTESES);
    setState(106);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 34634616799232) != 0)) {
      setState(105);
      parametros();
    }
    setState(108);
    match(MinhaLinguagemParser::FECHA_PARENTESES);
    setState(109);
    bloco();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParametrosContext ------------------------------------------------------------------

MinhaLinguagemParser::ParametrosContext::ParametrosContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MinhaLinguagemParser::ParametroContext *> MinhaLinguagemParser::ParametrosContext::parametro() {
  return getRuleContexts<MinhaLinguagemParser::ParametroContext>();
}

MinhaLinguagemParser::ParametroContext* MinhaLinguagemParser::ParametrosContext::parametro(size_t i) {
  return getRuleContext<MinhaLinguagemParser::ParametroContext>(i);
}

std::vector<tree::TerminalNode *> MinhaLinguagemParser::ParametrosContext::VIRGULA() {
  return getTokens(MinhaLinguagemParser::VIRGULA);
}

tree::TerminalNode* MinhaLinguagemParser::ParametrosContext::VIRGULA(size_t i) {
  return getToken(MinhaLinguagemParser::VIRGULA, i);
}


size_t MinhaLinguagemParser::ParametrosContext::getRuleIndex() const {
  return MinhaLinguagemParser::RuleParametros;
}

void MinhaLinguagemParser::ParametrosContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MinhaLinguagemListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParametros(this);
}

void MinhaLinguagemParser::ParametrosContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MinhaLinguagemListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParametros(this);
}


std::any MinhaLinguagemParser::ParametrosContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MinhaLinguagemVisitor*>(visitor))
    return parserVisitor->visitParametros(this);
  else
    return visitor->visitChildren(this);
}

MinhaLinguagemParser::ParametrosContext* MinhaLinguagemParser::parametros() {
  ParametrosContext *_localctx = _tracker.createInstance<ParametrosContext>(_ctx, getState());
  enterRule(_localctx, 10, MinhaLinguagemParser::RuleParametros);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(111);
    parametro();
    setState(116);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MinhaLinguagemParser::VIRGULA) {
      setState(112);
      match(MinhaLinguagemParser::VIRGULA);
      setState(113);
      parametro();
      setState(118);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParametroContext ------------------------------------------------------------------

MinhaLinguagemParser::ParametroContext::ParametroContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MinhaLinguagemParser::TipoContext* MinhaLinguagemParser::ParametroContext::tipo() {
  return getRuleContext<MinhaLinguagemParser::TipoContext>(0);
}

tree::TerminalNode* MinhaLinguagemParser::ParametroContext::IDENTIFICADOR() {
  return getToken(MinhaLinguagemParser::IDENTIFICADOR, 0);
}


size_t MinhaLinguagemParser::ParametroContext::getRuleIndex() const {
  return MinhaLinguagemParser::RuleParametro;
}

void MinhaLinguagemParser::ParametroContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MinhaLinguagemListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParametro(this);
}

void MinhaLinguagemParser::ParametroContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MinhaLinguagemListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParametro(this);
}


std::any MinhaLinguagemParser::ParametroContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MinhaLinguagemVisitor*>(visitor))
    return parserVisitor->visitParametro(this);
  else
    return visitor->visitChildren(this);
}

MinhaLinguagemParser::ParametroContext* MinhaLinguagemParser::parametro() {
  ParametroContext *_localctx = _tracker.createInstance<ParametroContext>(_ctx, getState());
  enterRule(_localctx, 12, MinhaLinguagemParser::RuleParametro);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(119);
    tipo();
    setState(120);
    antlrcpp::downCast<ParametroContext *>(_localctx)->ID = match(MinhaLinguagemParser::IDENTIFICADOR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Declaracao_variavelContext ------------------------------------------------------------------

MinhaLinguagemParser::Declaracao_variavelContext::Declaracao_variavelContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MinhaLinguagemParser::TipoContext* MinhaLinguagemParser::Declaracao_variavelContext::tipo() {
  return getRuleContext<MinhaLinguagemParser::TipoContext>(0);
}

tree::TerminalNode* MinhaLinguagemParser::Declaracao_variavelContext::PONTO_VIRGULA() {
  return getToken(MinhaLinguagemParser::PONTO_VIRGULA, 0);
}

tree::TerminalNode* MinhaLinguagemParser::Declaracao_variavelContext::IDENTIFICADOR() {
  return getToken(MinhaLinguagemParser::IDENTIFICADOR, 0);
}

tree::TerminalNode* MinhaLinguagemParser::Declaracao_variavelContext::ABRE_COLCHETES() {
  return getToken(MinhaLinguagemParser::ABRE_COLCHETES, 0);
}

tree::TerminalNode* MinhaLinguagemParser::Declaracao_variavelContext::FECHA_COLCHETES() {
  return getToken(MinhaLinguagemParser::FECHA_COLCHETES, 0);
}

tree::TerminalNode* MinhaLinguagemParser::Declaracao_variavelContext::ATRIBUICAO() {
  return getToken(MinhaLinguagemParser::ATRIBUICAO, 0);
}

std::vector<MinhaLinguagemParser::ExpressaoContext *> MinhaLinguagemParser::Declaracao_variavelContext::expressao() {
  return getRuleContexts<MinhaLinguagemParser::ExpressaoContext>();
}

MinhaLinguagemParser::ExpressaoContext* MinhaLinguagemParser::Declaracao_variavelContext::expressao(size_t i) {
  return getRuleContext<MinhaLinguagemParser::ExpressaoContext>(i);
}

tree::TerminalNode* MinhaLinguagemParser::Declaracao_variavelContext::PUBLIC() {
  return getToken(MinhaLinguagemParser::PUBLIC, 0);
}

tree::TerminalNode* MinhaLinguagemParser::Declaracao_variavelContext::PRIVATE() {
  return getToken(MinhaLinguagemParser::PRIVATE, 0);
}

tree::TerminalNode* MinhaLinguagemParser::Declaracao_variavelContext::PROTECTED() {
  return getToken(MinhaLinguagemParser::PROTECTED, 0);
}


size_t MinhaLinguagemParser::Declaracao_variavelContext::getRuleIndex() const {
  return MinhaLinguagemParser::RuleDeclaracao_variavel;
}

void MinhaLinguagemParser::Declaracao_variavelContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MinhaLinguagemListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclaracao_variavel(this);
}

void MinhaLinguagemParser::Declaracao_variavelContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MinhaLinguagemListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclaracao_variavel(this);
}


std::any MinhaLinguagemParser::Declaracao_variavelContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MinhaLinguagemVisitor*>(visitor))
    return parserVisitor->visitDeclaracao_variavel(this);
  else
    return visitor->visitChildren(this);
}

MinhaLinguagemParser::Declaracao_variavelContext* MinhaLinguagemParser::declaracao_variavel() {
  Declaracao_variavelContext *_localctx = _tracker.createInstance<Declaracao_variavelContext>(_ctx, getState());
  enterRule(_localctx, 14, MinhaLinguagemParser::RuleDeclaracao_variavel);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(123);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 229376) != 0)) {
      setState(122);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 229376) != 0))) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
    setState(125);
    tipo();
    setState(126);
    antlrcpp::downCast<Declaracao_variavelContext *>(_localctx)->ID = match(MinhaLinguagemParser::IDENTIFICADOR);
    setState(132);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MinhaLinguagemParser::ABRE_COLCHETES) {
      setState(127);
      match(MinhaLinguagemParser::ABRE_COLCHETES);
      setState(129);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 2515682604351556) != 0)) {
        setState(128);
        expressao(0);
      }
      setState(131);
      match(MinhaLinguagemParser::FECHA_COLCHETES);
    }
    setState(136);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MinhaLinguagemParser::ATRIBUICAO) {
      setState(134);
      match(MinhaLinguagemParser::ATRIBUICAO);
      setState(135);
      expressao(0);
    }
    setState(138);
    match(MinhaLinguagemParser::PONTO_VIRGULA);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlocoContext ------------------------------------------------------------------

MinhaLinguagemParser::BlocoContext::BlocoContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MinhaLinguagemParser::BlocoContext::ABRE_CHAVES() {
  return getToken(MinhaLinguagemParser::ABRE_CHAVES, 0);
}

tree::TerminalNode* MinhaLinguagemParser::BlocoContext::FECHA_CHAVES() {
  return getToken(MinhaLinguagemParser::FECHA_CHAVES, 0);
}

std::vector<MinhaLinguagemParser::DeclaracaoContext *> MinhaLinguagemParser::BlocoContext::declaracao() {
  return getRuleContexts<MinhaLinguagemParser::DeclaracaoContext>();
}

MinhaLinguagemParser::DeclaracaoContext* MinhaLinguagemParser::BlocoContext::declaracao(size_t i) {
  return getRuleContext<MinhaLinguagemParser::DeclaracaoContext>(i);
}


size_t MinhaLinguagemParser::BlocoContext::getRuleIndex() const {
  return MinhaLinguagemParser::RuleBloco;
}

void MinhaLinguagemParser::BlocoContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MinhaLinguagemListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBloco(this);
}

void MinhaLinguagemParser::BlocoContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MinhaLinguagemListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBloco(this);
}


std::any MinhaLinguagemParser::BlocoContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MinhaLinguagemVisitor*>(visitor))
    return parserVisitor->visitBloco(this);
  else
    return visitor->visitChildren(this);
}

MinhaLinguagemParser::BlocoContext* MinhaLinguagemParser::bloco() {
  BlocoContext *_localctx = _tracker.createInstance<BlocoContext>(_ctx, getState());
  enterRule(_localctx, 16, MinhaLinguagemParser::RuleBloco);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(140);
    match(MinhaLinguagemParser::ABRE_CHAVES);
    setState(144);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 2533111582392388) != 0)) {
      setState(141);
      declaracao();
      setState(146);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(147);
    match(MinhaLinguagemParser::FECHA_CHAVES);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclaracaoContext ------------------------------------------------------------------

MinhaLinguagemParser::DeclaracaoContext::DeclaracaoContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MinhaLinguagemParser::DeclaracaoContext::getRuleIndex() const {
  return MinhaLinguagemParser::RuleDeclaracao;
}

void MinhaLinguagemParser::DeclaracaoContext::copyFrom(DeclaracaoContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ExprStmtContext ------------------------------------------------------------------

MinhaLinguagemParser::ExpressaoContext* MinhaLinguagemParser::ExprStmtContext::expressao() {
  return getRuleContext<MinhaLinguagemParser::ExpressaoContext>(0);
}

tree::TerminalNode* MinhaLinguagemParser::ExprStmtContext::PONTO_VIRGULA() {
  return getToken(MinhaLinguagemParser::PONTO_VIRGULA, 0);
}

MinhaLinguagemParser::ExprStmtContext::ExprStmtContext(DeclaracaoContext *ctx) { copyFrom(ctx); }

void MinhaLinguagemParser::ExprStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MinhaLinguagemListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExprStmt(this);
}
void MinhaLinguagemParser::ExprStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MinhaLinguagemListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExprStmt(this);
}

std::any MinhaLinguagemParser::ExprStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MinhaLinguagemVisitor*>(visitor))
    return parserVisitor->visitExprStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- VarDeclContext ------------------------------------------------------------------

MinhaLinguagemParser::Declaracao_variavelContext* MinhaLinguagemParser::VarDeclContext::declaracao_variavel() {
  return getRuleContext<MinhaLinguagemParser::Declaracao_variavelContext>(0);
}

MinhaLinguagemParser::VarDeclContext::VarDeclContext(DeclaracaoContext *ctx) { copyFrom(ctx); }

void MinhaLinguagemParser::VarDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MinhaLinguagemListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarDecl(this);
}
void MinhaLinguagemParser::VarDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MinhaLinguagemListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarDecl(this);
}

std::any MinhaLinguagemParser::VarDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MinhaLinguagemVisitor*>(visitor))
    return parserVisitor->visitVarDecl(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ReturnStmtContext ------------------------------------------------------------------

tree::TerminalNode* MinhaLinguagemParser::ReturnStmtContext::RETURN() {
  return getToken(MinhaLinguagemParser::RETURN, 0);
}

tree::TerminalNode* MinhaLinguagemParser::ReturnStmtContext::PONTO_VIRGULA() {
  return getToken(MinhaLinguagemParser::PONTO_VIRGULA, 0);
}

MinhaLinguagemParser::ExpressaoContext* MinhaLinguagemParser::ReturnStmtContext::expressao() {
  return getRuleContext<MinhaLinguagemParser::ExpressaoContext>(0);
}

MinhaLinguagemParser::ReturnStmtContext::ReturnStmtContext(DeclaracaoContext *ctx) { copyFrom(ctx); }

void MinhaLinguagemParser::ReturnStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MinhaLinguagemListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReturnStmt(this);
}
void MinhaLinguagemParser::ReturnStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MinhaLinguagemListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReturnStmt(this);
}

std::any MinhaLinguagemParser::ReturnStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MinhaLinguagemVisitor*>(visitor))
    return parserVisitor->visitReturnStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ControleDeclContext ------------------------------------------------------------------

MinhaLinguagemParser::Estrutura_controleContext* MinhaLinguagemParser::ControleDeclContext::estrutura_controle() {
  return getRuleContext<MinhaLinguagemParser::Estrutura_controleContext>(0);
}

MinhaLinguagemParser::ControleDeclContext::ControleDeclContext(DeclaracaoContext *ctx) { copyFrom(ctx); }

void MinhaLinguagemParser::ControleDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MinhaLinguagemListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterControleDecl(this);
}
void MinhaLinguagemParser::ControleDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MinhaLinguagemListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitControleDecl(this);
}

std::any MinhaLinguagemParser::ControleDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MinhaLinguagemVisitor*>(visitor))
    return parserVisitor->visitControleDecl(this);
  else
    return visitor->visitChildren(this);
}
MinhaLinguagemParser::DeclaracaoContext* MinhaLinguagemParser::declaracao() {
  DeclaracaoContext *_localctx = _tracker.createInstance<DeclaracaoContext>(_ctx, getState());
  enterRule(_localctx, 18, MinhaLinguagemParser::RuleDeclaracao);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(159);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<MinhaLinguagemParser::VarDeclContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(149);
      declaracao_variavel();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<MinhaLinguagemParser::ControleDeclContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(150);
      estrutura_controle();
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<MinhaLinguagemParser::ExprStmtContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(151);
      expressao(0);
      setState(152);
      match(MinhaLinguagemParser::PONTO_VIRGULA);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<MinhaLinguagemParser::ReturnStmtContext>(_localctx);
      enterOuterAlt(_localctx, 4);
      setState(154);
      match(MinhaLinguagemParser::RETURN);
      setState(156);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 2515682604351556) != 0)) {
        setState(155);
        expressao(0);
      }
      setState(158);
      match(MinhaLinguagemParser::PONTO_VIRGULA);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Estrutura_controleContext ------------------------------------------------------------------

MinhaLinguagemParser::Estrutura_controleContext::Estrutura_controleContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MinhaLinguagemParser::Estrutura_controleContext::getRuleIndex() const {
  return MinhaLinguagemParser::RuleEstrutura_controle;
}

void MinhaLinguagemParser::Estrutura_controleContext::copyFrom(Estrutura_controleContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ForContext ------------------------------------------------------------------

tree::TerminalNode* MinhaLinguagemParser::ForContext::FOR() {
  return getToken(MinhaLinguagemParser::FOR, 0);
}

tree::TerminalNode* MinhaLinguagemParser::ForContext::ABRE_PARENTESES() {
  return getToken(MinhaLinguagemParser::ABRE_PARENTESES, 0);
}

std::vector<tree::TerminalNode *> MinhaLinguagemParser::ForContext::PONTO_VIRGULA() {
  return getTokens(MinhaLinguagemParser::PONTO_VIRGULA);
}

tree::TerminalNode* MinhaLinguagemParser::ForContext::PONTO_VIRGULA(size_t i) {
  return getToken(MinhaLinguagemParser::PONTO_VIRGULA, i);
}

tree::TerminalNode* MinhaLinguagemParser::ForContext::FECHA_PARENTESES() {
  return getToken(MinhaLinguagemParser::FECHA_PARENTESES, 0);
}

MinhaLinguagemParser::BlocoContext* MinhaLinguagemParser::ForContext::bloco() {
  return getRuleContext<MinhaLinguagemParser::BlocoContext>(0);
}

MinhaLinguagemParser::Declaracao_variavelContext* MinhaLinguagemParser::ForContext::declaracao_variavel() {
  return getRuleContext<MinhaLinguagemParser::Declaracao_variavelContext>(0);
}

std::vector<MinhaLinguagemParser::ExpressaoContext *> MinhaLinguagemParser::ForContext::expressao() {
  return getRuleContexts<MinhaLinguagemParser::ExpressaoContext>();
}

MinhaLinguagemParser::ExpressaoContext* MinhaLinguagemParser::ForContext::expressao(size_t i) {
  return getRuleContext<MinhaLinguagemParser::ExpressaoContext>(i);
}

MinhaLinguagemParser::ForContext::ForContext(Estrutura_controleContext *ctx) { copyFrom(ctx); }

void MinhaLinguagemParser::ForContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MinhaLinguagemListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFor(this);
}
void MinhaLinguagemParser::ForContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MinhaLinguagemListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFor(this);
}

std::any MinhaLinguagemParser::ForContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MinhaLinguagemVisitor*>(visitor))
    return parserVisitor->visitFor(this);
  else
    return visitor->visitChildren(this);
}
//----------------- WhileContext ------------------------------------------------------------------

tree::TerminalNode* MinhaLinguagemParser::WhileContext::WHILE() {
  return getToken(MinhaLinguagemParser::WHILE, 0);
}

tree::TerminalNode* MinhaLinguagemParser::WhileContext::ABRE_PARENTESES() {
  return getToken(MinhaLinguagemParser::ABRE_PARENTESES, 0);
}

MinhaLinguagemParser::ExpressaoContext* MinhaLinguagemParser::WhileContext::expressao() {
  return getRuleContext<MinhaLinguagemParser::ExpressaoContext>(0);
}

tree::TerminalNode* MinhaLinguagemParser::WhileContext::FECHA_PARENTESES() {
  return getToken(MinhaLinguagemParser::FECHA_PARENTESES, 0);
}

MinhaLinguagemParser::BlocoContext* MinhaLinguagemParser::WhileContext::bloco() {
  return getRuleContext<MinhaLinguagemParser::BlocoContext>(0);
}

MinhaLinguagemParser::WhileContext::WhileContext(Estrutura_controleContext *ctx) { copyFrom(ctx); }

void MinhaLinguagemParser::WhileContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MinhaLinguagemListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWhile(this);
}
void MinhaLinguagemParser::WhileContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MinhaLinguagemListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWhile(this);
}

std::any MinhaLinguagemParser::WhileContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MinhaLinguagemVisitor*>(visitor))
    return parserVisitor->visitWhile(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IfContext ------------------------------------------------------------------

tree::TerminalNode* MinhaLinguagemParser::IfContext::IF() {
  return getToken(MinhaLinguagemParser::IF, 0);
}

tree::TerminalNode* MinhaLinguagemParser::IfContext::ABRE_PARENTESES() {
  return getToken(MinhaLinguagemParser::ABRE_PARENTESES, 0);
}

MinhaLinguagemParser::ExpressaoContext* MinhaLinguagemParser::IfContext::expressao() {
  return getRuleContext<MinhaLinguagemParser::ExpressaoContext>(0);
}

tree::TerminalNode* MinhaLinguagemParser::IfContext::FECHA_PARENTESES() {
  return getToken(MinhaLinguagemParser::FECHA_PARENTESES, 0);
}

std::vector<MinhaLinguagemParser::BlocoContext *> MinhaLinguagemParser::IfContext::bloco() {
  return getRuleContexts<MinhaLinguagemParser::BlocoContext>();
}

MinhaLinguagemParser::BlocoContext* MinhaLinguagemParser::IfContext::bloco(size_t i) {
  return getRuleContext<MinhaLinguagemParser::BlocoContext>(i);
}

tree::TerminalNode* MinhaLinguagemParser::IfContext::ELSE() {
  return getToken(MinhaLinguagemParser::ELSE, 0);
}

MinhaLinguagemParser::IfContext::IfContext(Estrutura_controleContext *ctx) { copyFrom(ctx); }

void MinhaLinguagemParser::IfContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MinhaLinguagemListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIf(this);
}
void MinhaLinguagemParser::IfContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MinhaLinguagemListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIf(this);
}

std::any MinhaLinguagemParser::IfContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MinhaLinguagemVisitor*>(visitor))
    return parserVisitor->visitIf(this);
  else
    return visitor->visitChildren(this);
}
MinhaLinguagemParser::Estrutura_controleContext* MinhaLinguagemParser::estrutura_controle() {
  Estrutura_controleContext *_localctx = _tracker.createInstance<Estrutura_controleContext>(_ctx, getState());
  enterRule(_localctx, 20, MinhaLinguagemParser::RuleEstrutura_controle);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(194);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MinhaLinguagemParser::IF: {
        _localctx = _tracker.createInstance<MinhaLinguagemParser::IfContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(161);
        match(MinhaLinguagemParser::IF);
        setState(162);
        match(MinhaLinguagemParser::ABRE_PARENTESES);
        setState(163);
        expressao(0);
        setState(164);
        match(MinhaLinguagemParser::FECHA_PARENTESES);
        setState(165);
        bloco();
        setState(168);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == MinhaLinguagemParser::ELSE) {
          setState(166);
          match(MinhaLinguagemParser::ELSE);
          setState(167);
          bloco();
        }
        break;
      }

      case MinhaLinguagemParser::WHILE: {
        _localctx = _tracker.createInstance<MinhaLinguagemParser::WhileContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(170);
        match(MinhaLinguagemParser::WHILE);
        setState(171);
        match(MinhaLinguagemParser::ABRE_PARENTESES);
        setState(172);
        expressao(0);
        setState(173);
        match(MinhaLinguagemParser::FECHA_PARENTESES);
        setState(174);
        bloco();
        break;
      }

      case MinhaLinguagemParser::FOR: {
        _localctx = _tracker.createInstance<MinhaLinguagemParser::ForContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(176);
        match(MinhaLinguagemParser::FOR);
        setState(177);
        match(MinhaLinguagemParser::ABRE_PARENTESES);
        setState(183);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx)) {
        case 1: {
          setState(178);
          declaracao_variavel();
          break;
        }

        case 2: {
          setState(180);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if ((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 2515682604351556) != 0)) {
            setState(179);
            expressao(0);
          }
          setState(182);
          match(MinhaLinguagemParser::PONTO_VIRGULA);
          break;
        }

        default:
          break;
        }
        setState(186);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 2515682604351556) != 0)) {
          setState(185);
          expressao(0);
        }
        setState(188);
        match(MinhaLinguagemParser::PONTO_VIRGULA);
        setState(190);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 2515682604351556) != 0)) {
          setState(189);
          expressao(0);
        }
        setState(192);
        match(MinhaLinguagemParser::FECHA_PARENTESES);
        setState(193);
        bloco();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressaoContext ------------------------------------------------------------------

MinhaLinguagemParser::ExpressaoContext::ExpressaoContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MinhaLinguagemParser::ExpressaoContext::getRuleIndex() const {
  return MinhaLinguagemParser::RuleExpressao;
}

void MinhaLinguagemParser::ExpressaoContext::copyFrom(ExpressaoContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- VariavelContext ------------------------------------------------------------------

tree::TerminalNode* MinhaLinguagemParser::VariavelContext::IDENTIFICADOR() {
  return getToken(MinhaLinguagemParser::IDENTIFICADOR, 0);
}

MinhaLinguagemParser::VariavelContext::VariavelContext(ExpressaoContext *ctx) { copyFrom(ctx); }

void MinhaLinguagemParser::VariavelContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MinhaLinguagemListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariavel(this);
}
void MinhaLinguagemParser::VariavelContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MinhaLinguagemListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariavel(this);
}

std::any MinhaLinguagemParser::VariavelContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MinhaLinguagemVisitor*>(visitor))
    return parserVisitor->visitVariavel(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AtribuicaoVetorContext ------------------------------------------------------------------

std::vector<MinhaLinguagemParser::ExpressaoContext *> MinhaLinguagemParser::AtribuicaoVetorContext::expressao() {
  return getRuleContexts<MinhaLinguagemParser::ExpressaoContext>();
}

MinhaLinguagemParser::ExpressaoContext* MinhaLinguagemParser::AtribuicaoVetorContext::expressao(size_t i) {
  return getRuleContext<MinhaLinguagemParser::ExpressaoContext>(i);
}

tree::TerminalNode* MinhaLinguagemParser::AtribuicaoVetorContext::ABRE_COLCHETES() {
  return getToken(MinhaLinguagemParser::ABRE_COLCHETES, 0);
}

tree::TerminalNode* MinhaLinguagemParser::AtribuicaoVetorContext::FECHA_COLCHETES() {
  return getToken(MinhaLinguagemParser::FECHA_COLCHETES, 0);
}

tree::TerminalNode* MinhaLinguagemParser::AtribuicaoVetorContext::ATRIBUICAO() {
  return getToken(MinhaLinguagemParser::ATRIBUICAO, 0);
}

MinhaLinguagemParser::AtribuicaoVetorContext::AtribuicaoVetorContext(ExpressaoContext *ctx) { copyFrom(ctx); }

void MinhaLinguagemParser::AtribuicaoVetorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MinhaLinguagemListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAtribuicaoVetor(this);
}
void MinhaLinguagemParser::AtribuicaoVetorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MinhaLinguagemListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAtribuicaoVetor(this);
}

std::any MinhaLinguagemParser::AtribuicaoVetorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MinhaLinguagemVisitor*>(visitor))
    return parserVisitor->visitAtribuicaoVetor(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CharLiteralContext ------------------------------------------------------------------

tree::TerminalNode* MinhaLinguagemParser::CharLiteralContext::CARACTERE() {
  return getToken(MinhaLinguagemParser::CARACTERE, 0);
}

MinhaLinguagemParser::CharLiteralContext::CharLiteralContext(ExpressaoContext *ctx) { copyFrom(ctx); }

void MinhaLinguagemParser::CharLiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MinhaLinguagemListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCharLiteral(this);
}
void MinhaLinguagemParser::CharLiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MinhaLinguagemListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCharLiteral(this);
}

std::any MinhaLinguagemParser::CharLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MinhaLinguagemVisitor*>(visitor))
    return parserVisitor->visitCharLiteral(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ChamadaFuncaoContext ------------------------------------------------------------------

tree::TerminalNode* MinhaLinguagemParser::ChamadaFuncaoContext::IDENTIFICADOR() {
  return getToken(MinhaLinguagemParser::IDENTIFICADOR, 0);
}

tree::TerminalNode* MinhaLinguagemParser::ChamadaFuncaoContext::ABRE_PARENTESES() {
  return getToken(MinhaLinguagemParser::ABRE_PARENTESES, 0);
}

tree::TerminalNode* MinhaLinguagemParser::ChamadaFuncaoContext::FECHA_PARENTESES() {
  return getToken(MinhaLinguagemParser::FECHA_PARENTESES, 0);
}

std::vector<MinhaLinguagemParser::ExpressaoContext *> MinhaLinguagemParser::ChamadaFuncaoContext::expressao() {
  return getRuleContexts<MinhaLinguagemParser::ExpressaoContext>();
}

MinhaLinguagemParser::ExpressaoContext* MinhaLinguagemParser::ChamadaFuncaoContext::expressao(size_t i) {
  return getRuleContext<MinhaLinguagemParser::ExpressaoContext>(i);
}

std::vector<tree::TerminalNode *> MinhaLinguagemParser::ChamadaFuncaoContext::VIRGULA() {
  return getTokens(MinhaLinguagemParser::VIRGULA);
}

tree::TerminalNode* MinhaLinguagemParser::ChamadaFuncaoContext::VIRGULA(size_t i) {
  return getToken(MinhaLinguagemParser::VIRGULA, i);
}

MinhaLinguagemParser::ChamadaFuncaoContext::ChamadaFuncaoContext(ExpressaoContext *ctx) { copyFrom(ctx); }

void MinhaLinguagemParser::ChamadaFuncaoContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MinhaLinguagemListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterChamadaFuncao(this);
}
void MinhaLinguagemParser::ChamadaFuncaoContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MinhaLinguagemListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitChamadaFuncao(this);
}

std::any MinhaLinguagemParser::ChamadaFuncaoContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MinhaLinguagemVisitor*>(visitor))
    return parserVisitor->visitChamadaFuncao(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NewVetorContext ------------------------------------------------------------------

MinhaLinguagemParser::Tipo_baseContext* MinhaLinguagemParser::NewVetorContext::tipo_base() {
  return getRuleContext<MinhaLinguagemParser::Tipo_baseContext>(0);
}

tree::TerminalNode* MinhaLinguagemParser::NewVetorContext::ABRE_COLCHETES() {
  return getToken(MinhaLinguagemParser::ABRE_COLCHETES, 0);
}

MinhaLinguagemParser::ExpressaoContext* MinhaLinguagemParser::NewVetorContext::expressao() {
  return getRuleContext<MinhaLinguagemParser::ExpressaoContext>(0);
}

tree::TerminalNode* MinhaLinguagemParser::NewVetorContext::FECHA_COLCHETES() {
  return getToken(MinhaLinguagemParser::FECHA_COLCHETES, 0);
}

MinhaLinguagemParser::NewVetorContext::NewVetorContext(ExpressaoContext *ctx) { copyFrom(ctx); }

void MinhaLinguagemParser::NewVetorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MinhaLinguagemListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNewVetor(this);
}
void MinhaLinguagemParser::NewVetorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MinhaLinguagemListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNewVetor(this);
}

std::any MinhaLinguagemParser::NewVetorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MinhaLinguagemVisitor*>(visitor))
    return parserVisitor->visitNewVetor(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ChamadaMetodoContext ------------------------------------------------------------------

std::vector<MinhaLinguagemParser::ExpressaoContext *> MinhaLinguagemParser::ChamadaMetodoContext::expressao() {
  return getRuleContexts<MinhaLinguagemParser::ExpressaoContext>();
}

MinhaLinguagemParser::ExpressaoContext* MinhaLinguagemParser::ChamadaMetodoContext::expressao(size_t i) {
  return getRuleContext<MinhaLinguagemParser::ExpressaoContext>(i);
}

tree::TerminalNode* MinhaLinguagemParser::ChamadaMetodoContext::PONTO() {
  return getToken(MinhaLinguagemParser::PONTO, 0);
}

tree::TerminalNode* MinhaLinguagemParser::ChamadaMetodoContext::IDENTIFICADOR() {
  return getToken(MinhaLinguagemParser::IDENTIFICADOR, 0);
}

tree::TerminalNode* MinhaLinguagemParser::ChamadaMetodoContext::ABRE_PARENTESES() {
  return getToken(MinhaLinguagemParser::ABRE_PARENTESES, 0);
}

tree::TerminalNode* MinhaLinguagemParser::ChamadaMetodoContext::FECHA_PARENTESES() {
  return getToken(MinhaLinguagemParser::FECHA_PARENTESES, 0);
}

std::vector<tree::TerminalNode *> MinhaLinguagemParser::ChamadaMetodoContext::VIRGULA() {
  return getTokens(MinhaLinguagemParser::VIRGULA);
}

tree::TerminalNode* MinhaLinguagemParser::ChamadaMetodoContext::VIRGULA(size_t i) {
  return getToken(MinhaLinguagemParser::VIRGULA, i);
}

MinhaLinguagemParser::ChamadaMetodoContext::ChamadaMetodoContext(ExpressaoContext *ctx) { copyFrom(ctx); }

void MinhaLinguagemParser::ChamadaMetodoContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MinhaLinguagemListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterChamadaMetodo(this);
}
void MinhaLinguagemParser::ChamadaMetodoContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MinhaLinguagemListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitChamadaMetodo(this);
}

std::any MinhaLinguagemParser::ChamadaMetodoContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MinhaLinguagemVisitor*>(visitor))
    return parserVisitor->visitChamadaMetodo(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StringContext ------------------------------------------------------------------

tree::TerminalNode* MinhaLinguagemParser::StringContext::TEXTO() {
  return getToken(MinhaLinguagemParser::TEXTO, 0);
}

MinhaLinguagemParser::StringContext::StringContext(ExpressaoContext *ctx) { copyFrom(ctx); }

void MinhaLinguagemParser::StringContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MinhaLinguagemListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterString(this);
}
void MinhaLinguagemParser::StringContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MinhaLinguagemListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitString(this);
}

std::any MinhaLinguagemParser::StringContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MinhaLinguagemVisitor*>(visitor))
    return parserVisitor->visitString(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AtribuicaoMembroContext ------------------------------------------------------------------

std::vector<MinhaLinguagemParser::ExpressaoContext *> MinhaLinguagemParser::AtribuicaoMembroContext::expressao() {
  return getRuleContexts<MinhaLinguagemParser::ExpressaoContext>();
}

MinhaLinguagemParser::ExpressaoContext* MinhaLinguagemParser::AtribuicaoMembroContext::expressao(size_t i) {
  return getRuleContext<MinhaLinguagemParser::ExpressaoContext>(i);
}

tree::TerminalNode* MinhaLinguagemParser::AtribuicaoMembroContext::PONTO() {
  return getToken(MinhaLinguagemParser::PONTO, 0);
}

tree::TerminalNode* MinhaLinguagemParser::AtribuicaoMembroContext::IDENTIFICADOR() {
  return getToken(MinhaLinguagemParser::IDENTIFICADOR, 0);
}

tree::TerminalNode* MinhaLinguagemParser::AtribuicaoMembroContext::ATRIBUICAO() {
  return getToken(MinhaLinguagemParser::ATRIBUICAO, 0);
}

MinhaLinguagemParser::AtribuicaoMembroContext::AtribuicaoMembroContext(ExpressaoContext *ctx) { copyFrom(ctx); }

void MinhaLinguagemParser::AtribuicaoMembroContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MinhaLinguagemListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAtribuicaoMembro(this);
}
void MinhaLinguagemParser::AtribuicaoMembroContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MinhaLinguagemListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAtribuicaoMembro(this);
}

std::any MinhaLinguagemParser::AtribuicaoMembroContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MinhaLinguagemVisitor*>(visitor))
    return parserVisitor->visitAtribuicaoMembro(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FloatContext ------------------------------------------------------------------

tree::TerminalNode* MinhaLinguagemParser::FloatContext::NUM_FLOAT() {
  return getToken(MinhaLinguagemParser::NUM_FLOAT, 0);
}

MinhaLinguagemParser::FloatContext::FloatContext(ExpressaoContext *ctx) { copyFrom(ctx); }

void MinhaLinguagemParser::FloatContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MinhaLinguagemListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFloat(this);
}
void MinhaLinguagemParser::FloatContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MinhaLinguagemListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFloat(this);
}

std::any MinhaLinguagemParser::FloatContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MinhaLinguagemVisitor*>(visitor))
    return parserVisitor->visitFloat(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NewObjetoContext ------------------------------------------------------------------

tree::TerminalNode* MinhaLinguagemParser::NewObjetoContext::IDENTIFICADOR() {
  return getToken(MinhaLinguagemParser::IDENTIFICADOR, 0);
}

tree::TerminalNode* MinhaLinguagemParser::NewObjetoContext::ABRE_PARENTESES() {
  return getToken(MinhaLinguagemParser::ABRE_PARENTESES, 0);
}

tree::TerminalNode* MinhaLinguagemParser::NewObjetoContext::FECHA_PARENTESES() {
  return getToken(MinhaLinguagemParser::FECHA_PARENTESES, 0);
}

std::vector<MinhaLinguagemParser::ExpressaoContext *> MinhaLinguagemParser::NewObjetoContext::expressao() {
  return getRuleContexts<MinhaLinguagemParser::ExpressaoContext>();
}

MinhaLinguagemParser::ExpressaoContext* MinhaLinguagemParser::NewObjetoContext::expressao(size_t i) {
  return getRuleContext<MinhaLinguagemParser::ExpressaoContext>(i);
}

std::vector<tree::TerminalNode *> MinhaLinguagemParser::NewObjetoContext::VIRGULA() {
  return getTokens(MinhaLinguagemParser::VIRGULA);
}

tree::TerminalNode* MinhaLinguagemParser::NewObjetoContext::VIRGULA(size_t i) {
  return getToken(MinhaLinguagemParser::VIRGULA, i);
}

MinhaLinguagemParser::NewObjetoContext::NewObjetoContext(ExpressaoContext *ctx) { copyFrom(ctx); }

void MinhaLinguagemParser::NewObjetoContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MinhaLinguagemListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNewObjeto(this);
}
void MinhaLinguagemParser::NewObjetoContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MinhaLinguagemListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNewObjeto(this);
}

std::any MinhaLinguagemParser::NewObjetoContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MinhaLinguagemVisitor*>(visitor))
    return parserVisitor->visitNewObjeto(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AcessoMembroContext ------------------------------------------------------------------

MinhaLinguagemParser::ExpressaoContext* MinhaLinguagemParser::AcessoMembroContext::expressao() {
  return getRuleContext<MinhaLinguagemParser::ExpressaoContext>(0);
}

tree::TerminalNode* MinhaLinguagemParser::AcessoMembroContext::PONTO() {
  return getToken(MinhaLinguagemParser::PONTO, 0);
}

tree::TerminalNode* MinhaLinguagemParser::AcessoMembroContext::IDENTIFICADOR() {
  return getToken(MinhaLinguagemParser::IDENTIFICADOR, 0);
}

MinhaLinguagemParser::AcessoMembroContext::AcessoMembroContext(ExpressaoContext *ctx) { copyFrom(ctx); }

void MinhaLinguagemParser::AcessoMembroContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MinhaLinguagemListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAcessoMembro(this);
}
void MinhaLinguagemParser::AcessoMembroContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MinhaLinguagemListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAcessoMembro(this);
}

std::any MinhaLinguagemParser::AcessoMembroContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MinhaLinguagemVisitor*>(visitor))
    return parserVisitor->visitAcessoMembro(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BinariaContext ------------------------------------------------------------------

std::vector<MinhaLinguagemParser::ExpressaoContext *> MinhaLinguagemParser::BinariaContext::expressao() {
  return getRuleContexts<MinhaLinguagemParser::ExpressaoContext>();
}

MinhaLinguagemParser::ExpressaoContext* MinhaLinguagemParser::BinariaContext::expressao(size_t i) {
  return getRuleContext<MinhaLinguagemParser::ExpressaoContext>(i);
}

tree::TerminalNode* MinhaLinguagemParser::BinariaContext::MULT() {
  return getToken(MinhaLinguagemParser::MULT, 0);
}

tree::TerminalNode* MinhaLinguagemParser::BinariaContext::DIV() {
  return getToken(MinhaLinguagemParser::DIV, 0);
}

tree::TerminalNode* MinhaLinguagemParser::BinariaContext::MAIS() {
  return getToken(MinhaLinguagemParser::MAIS, 0);
}

tree::TerminalNode* MinhaLinguagemParser::BinariaContext::MENOS() {
  return getToken(MinhaLinguagemParser::MENOS, 0);
}

tree::TerminalNode* MinhaLinguagemParser::BinariaContext::MAIOR() {
  return getToken(MinhaLinguagemParser::MAIOR, 0);
}

tree::TerminalNode* MinhaLinguagemParser::BinariaContext::MAIOR_IGUAL() {
  return getToken(MinhaLinguagemParser::MAIOR_IGUAL, 0);
}

tree::TerminalNode* MinhaLinguagemParser::BinariaContext::MENOR() {
  return getToken(MinhaLinguagemParser::MENOR, 0);
}

tree::TerminalNode* MinhaLinguagemParser::BinariaContext::MENOR_IGUAL() {
  return getToken(MinhaLinguagemParser::MENOR_IGUAL, 0);
}

tree::TerminalNode* MinhaLinguagemParser::BinariaContext::IGUAL() {
  return getToken(MinhaLinguagemParser::IGUAL, 0);
}

tree::TerminalNode* MinhaLinguagemParser::BinariaContext::DIFERENTE() {
  return getToken(MinhaLinguagemParser::DIFERENTE, 0);
}

tree::TerminalNode* MinhaLinguagemParser::BinariaContext::E_LOGICO() {
  return getToken(MinhaLinguagemParser::E_LOGICO, 0);
}

tree::TerminalNode* MinhaLinguagemParser::BinariaContext::OU_LOGICO() {
  return getToken(MinhaLinguagemParser::OU_LOGICO, 0);
}

MinhaLinguagemParser::BinariaContext::BinariaContext(ExpressaoContext *ctx) { copyFrom(ctx); }

void MinhaLinguagemParser::BinariaContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MinhaLinguagemListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBinaria(this);
}
void MinhaLinguagemParser::BinariaContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MinhaLinguagemListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBinaria(this);
}

std::any MinhaLinguagemParser::BinariaContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MinhaLinguagemVisitor*>(visitor))
    return parserVisitor->visitBinaria(this);
  else
    return visitor->visitChildren(this);
}
//----------------- GrupoContext ------------------------------------------------------------------

tree::TerminalNode* MinhaLinguagemParser::GrupoContext::ABRE_PARENTESES() {
  return getToken(MinhaLinguagemParser::ABRE_PARENTESES, 0);
}

MinhaLinguagemParser::ExpressaoContext* MinhaLinguagemParser::GrupoContext::expressao() {
  return getRuleContext<MinhaLinguagemParser::ExpressaoContext>(0);
}

tree::TerminalNode* MinhaLinguagemParser::GrupoContext::FECHA_PARENTESES() {
  return getToken(MinhaLinguagemParser::FECHA_PARENTESES, 0);
}

MinhaLinguagemParser::GrupoContext::GrupoContext(ExpressaoContext *ctx) { copyFrom(ctx); }

void MinhaLinguagemParser::GrupoContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MinhaLinguagemListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGrupo(this);
}
void MinhaLinguagemParser::GrupoContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MinhaLinguagemListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGrupo(this);
}

std::any MinhaLinguagemParser::GrupoContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MinhaLinguagemVisitor*>(visitor))
    return parserVisitor->visitGrupo(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AtribuicaoContext ------------------------------------------------------------------

tree::TerminalNode* MinhaLinguagemParser::AtribuicaoContext::IDENTIFICADOR() {
  return getToken(MinhaLinguagemParser::IDENTIFICADOR, 0);
}

tree::TerminalNode* MinhaLinguagemParser::AtribuicaoContext::ATRIBUICAO() {
  return getToken(MinhaLinguagemParser::ATRIBUICAO, 0);
}

MinhaLinguagemParser::ExpressaoContext* MinhaLinguagemParser::AtribuicaoContext::expressao() {
  return getRuleContext<MinhaLinguagemParser::ExpressaoContext>(0);
}

MinhaLinguagemParser::AtribuicaoContext::AtribuicaoContext(ExpressaoContext *ctx) { copyFrom(ctx); }

void MinhaLinguagemParser::AtribuicaoContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MinhaLinguagemListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAtribuicao(this);
}
void MinhaLinguagemParser::AtribuicaoContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MinhaLinguagemListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAtribuicao(this);
}

std::any MinhaLinguagemParser::AtribuicaoContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MinhaLinguagemVisitor*>(visitor))
    return parserVisitor->visitAtribuicao(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AcessoVetorContext ------------------------------------------------------------------

tree::TerminalNode* MinhaLinguagemParser::AcessoVetorContext::IDENTIFICADOR() {
  return getToken(MinhaLinguagemParser::IDENTIFICADOR, 0);
}

tree::TerminalNode* MinhaLinguagemParser::AcessoVetorContext::ABRE_COLCHETES() {
  return getToken(MinhaLinguagemParser::ABRE_COLCHETES, 0);
}

MinhaLinguagemParser::ExpressaoContext* MinhaLinguagemParser::AcessoVetorContext::expressao() {
  return getRuleContext<MinhaLinguagemParser::ExpressaoContext>(0);
}

tree::TerminalNode* MinhaLinguagemParser::AcessoVetorContext::FECHA_COLCHETES() {
  return getToken(MinhaLinguagemParser::FECHA_COLCHETES, 0);
}

MinhaLinguagemParser::AcessoVetorContext::AcessoVetorContext(ExpressaoContext *ctx) { copyFrom(ctx); }

void MinhaLinguagemParser::AcessoVetorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MinhaLinguagemListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAcessoVetor(this);
}
void MinhaLinguagemParser::AcessoVetorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MinhaLinguagemListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAcessoVetor(this);
}

std::any MinhaLinguagemParser::AcessoVetorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MinhaLinguagemVisitor*>(visitor))
    return parserVisitor->visitAcessoVetor(this);
  else
    return visitor->visitChildren(this);
}
//----------------- InteiroContext ------------------------------------------------------------------

tree::TerminalNode* MinhaLinguagemParser::InteiroContext::NUM_INT() {
  return getToken(MinhaLinguagemParser::NUM_INT, 0);
}

MinhaLinguagemParser::InteiroContext::InteiroContext(ExpressaoContext *ctx) { copyFrom(ctx); }

void MinhaLinguagemParser::InteiroContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MinhaLinguagemListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInteiro(this);
}
void MinhaLinguagemParser::InteiroContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MinhaLinguagemListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInteiro(this);
}

std::any MinhaLinguagemParser::InteiroContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MinhaLinguagemVisitor*>(visitor))
    return parserVisitor->visitInteiro(this);
  else
    return visitor->visitChildren(this);
}

MinhaLinguagemParser::ExpressaoContext* MinhaLinguagemParser::expressao() {
   return expressao(0);
}

MinhaLinguagemParser::ExpressaoContext* MinhaLinguagemParser::expressao(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  MinhaLinguagemParser::ExpressaoContext *_localctx = _tracker.createInstance<ExpressaoContext>(_ctx, parentState);
  MinhaLinguagemParser::ExpressaoContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 22;
  enterRecursionRule(_localctx, 22, MinhaLinguagemParser::RuleExpressao, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(247);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<AtribuicaoContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(197);
      match(MinhaLinguagemParser::IDENTIFICADOR);
      setState(198);
      match(MinhaLinguagemParser::ATRIBUICAO);
      setState(199);
      expressao(21);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<GrupoContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(200);
      match(MinhaLinguagemParser::ABRE_PARENTESES);
      setState(201);
      expressao(0);
      setState(202);
      match(MinhaLinguagemParser::FECHA_PARENTESES);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<ChamadaFuncaoContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(204);
      match(MinhaLinguagemParser::IDENTIFICADOR);
      setState(205);
      match(MinhaLinguagemParser::ABRE_PARENTESES);
      setState(214);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 2515682604351556) != 0)) {
        setState(206);
        expressao(0);
        setState(211);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == MinhaLinguagemParser::VIRGULA) {
          setState(207);
          match(MinhaLinguagemParser::VIRGULA);
          setState(208);
          expressao(0);
          setState(213);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(216);
      match(MinhaLinguagemParser::FECHA_PARENTESES);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<VariavelContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(217);
      match(MinhaLinguagemParser::IDENTIFICADOR);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<InteiroContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(218);
      match(MinhaLinguagemParser::NUM_INT);
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<FloatContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(219);
      match(MinhaLinguagemParser::NUM_FLOAT);
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<StringContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(220);
      match(MinhaLinguagemParser::TEXTO);
      break;
    }

    case 8: {
      _localctx = _tracker.createInstance<AcessoVetorContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(221);
      match(MinhaLinguagemParser::IDENTIFICADOR);
      setState(222);
      match(MinhaLinguagemParser::ABRE_COLCHETES);
      setState(223);
      expressao(0);
      setState(224);
      match(MinhaLinguagemParser::FECHA_COLCHETES);
      break;
    }

    case 9: {
      _localctx = _tracker.createInstance<NewObjetoContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(226);
      match(MinhaLinguagemParser::T__1);
      setState(227);
      match(MinhaLinguagemParser::IDENTIFICADOR);
      setState(228);
      match(MinhaLinguagemParser::ABRE_PARENTESES);
      setState(237);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 2515682604351556) != 0)) {
        setState(229);
        expressao(0);
        setState(234);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == MinhaLinguagemParser::VIRGULA) {
          setState(230);
          match(MinhaLinguagemParser::VIRGULA);
          setState(231);
          expressao(0);
          setState(236);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(239);
      match(MinhaLinguagemParser::FECHA_PARENTESES);
      break;
    }

    case 10: {
      _localctx = _tracker.createInstance<NewVetorContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(240);
      match(MinhaLinguagemParser::T__1);
      setState(241);
      tipo_base();
      setState(242);
      match(MinhaLinguagemParser::ABRE_COLCHETES);
      setState(243);
      expressao(0);
      setState(244);
      match(MinhaLinguagemParser::FECHA_COLCHETES);
      break;
    }

    case 11: {
      _localctx = _tracker.createInstance<CharLiteralContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(246);
      match(MinhaLinguagemParser::CARACTERE);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(299);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 38, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(297);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 37, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<BinariaContext>(_tracker.createInstance<ExpressaoContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpressao);
          setState(249);

          if (!(precpred(_ctx, 20))) throw FailedPredicateException(this, "precpred(_ctx, 20)");
          setState(250);
          antlrcpp::downCast<BinariaContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == MinhaLinguagemParser::MULT

          || _la == MinhaLinguagemParser::DIV)) {
            antlrcpp::downCast<BinariaContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(251);
          expressao(21);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<BinariaContext>(_tracker.createInstance<ExpressaoContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpressao);
          setState(252);

          if (!(precpred(_ctx, 19))) throw FailedPredicateException(this, "precpred(_ctx, 19)");
          setState(253);
          antlrcpp::downCast<BinariaContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == MinhaLinguagemParser::MAIS

          || _la == MinhaLinguagemParser::MENOS)) {
            antlrcpp::downCast<BinariaContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(254);
          expressao(20);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<BinariaContext>(_tracker.createInstance<ExpressaoContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpressao);
          setState(255);

          if (!(precpred(_ctx, 18))) throw FailedPredicateException(this, "precpred(_ctx, 18)");
          setState(256);
          antlrcpp::downCast<BinariaContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 503316480) != 0))) {
            antlrcpp::downCast<BinariaContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(257);
          expressao(19);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<BinariaContext>(_tracker.createInstance<ExpressaoContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpressao);
          setState(258);

          if (!(precpred(_ctx, 17))) throw FailedPredicateException(this, "precpred(_ctx, 17)");
          setState(259);
          antlrcpp::downCast<BinariaContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == MinhaLinguagemParser::IGUAL

          || _la == MinhaLinguagemParser::DIFERENTE)) {
            antlrcpp::downCast<BinariaContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(260);
          expressao(18);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<BinariaContext>(_tracker.createInstance<ExpressaoContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpressao);
          setState(261);

          if (!(precpred(_ctx, 16))) throw FailedPredicateException(this, "precpred(_ctx, 16)");
          setState(262);
          antlrcpp::downCast<BinariaContext *>(_localctx)->op = match(MinhaLinguagemParser::E_LOGICO);
          setState(263);
          expressao(17);
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<BinariaContext>(_tracker.createInstance<ExpressaoContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpressao);
          setState(264);

          if (!(precpred(_ctx, 15))) throw FailedPredicateException(this, "precpred(_ctx, 15)");
          setState(265);
          antlrcpp::downCast<BinariaContext *>(_localctx)->op = match(MinhaLinguagemParser::OU_LOGICO);
          setState(266);
          expressao(16);
          break;
        }

        case 7: {
          auto newContext = _tracker.createInstance<AtribuicaoMembroContext>(_tracker.createInstance<ExpressaoContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpressao);
          setState(267);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(268);
          match(MinhaLinguagemParser::PONTO);
          setState(269);
          match(MinhaLinguagemParser::IDENTIFICADOR);
          setState(270);
          match(MinhaLinguagemParser::ATRIBUICAO);
          setState(271);
          expressao(4);
          break;
        }

        case 8: {
          auto newContext = _tracker.createInstance<AtribuicaoVetorContext>(_tracker.createInstance<ExpressaoContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpressao);
          setState(272);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(273);
          match(MinhaLinguagemParser::ABRE_COLCHETES);
          setState(274);
          expressao(0);
          setState(275);
          match(MinhaLinguagemParser::FECHA_COLCHETES);
          setState(276);
          match(MinhaLinguagemParser::ATRIBUICAO);
          setState(277);
          expressao(3);
          break;
        }

        case 9: {
          auto newContext = _tracker.createInstance<AcessoMembroContext>(_tracker.createInstance<ExpressaoContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpressao);
          setState(279);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(280);
          match(MinhaLinguagemParser::PONTO);
          setState(281);
          match(MinhaLinguagemParser::IDENTIFICADOR);
          break;
        }

        case 10: {
          auto newContext = _tracker.createInstance<ChamadaMetodoContext>(_tracker.createInstance<ExpressaoContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpressao);
          setState(282);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(283);
          match(MinhaLinguagemParser::PONTO);
          setState(284);
          match(MinhaLinguagemParser::IDENTIFICADOR);
          setState(285);
          match(MinhaLinguagemParser::ABRE_PARENTESES);
          setState(294);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if ((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 2515682604351556) != 0)) {
            setState(286);
            expressao(0);
            setState(291);
            _errHandler->sync(this);
            _la = _input->LA(1);
            while (_la == MinhaLinguagemParser::VIRGULA) {
              setState(287);
              match(MinhaLinguagemParser::VIRGULA);
              setState(288);
              expressao(0);
              setState(293);
              _errHandler->sync(this);
              _la = _input->LA(1);
            }
          }
          setState(296);
          match(MinhaLinguagemParser::FECHA_PARENTESES);
          break;
        }

        default:
          break;
        } 
      }
      setState(301);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 38, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Tipo_baseContext ------------------------------------------------------------------

MinhaLinguagemParser::Tipo_baseContext::Tipo_baseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MinhaLinguagemParser::Tipo_baseContext::INT() {
  return getToken(MinhaLinguagemParser::INT, 0);
}

tree::TerminalNode* MinhaLinguagemParser::Tipo_baseContext::FLOAT() {
  return getToken(MinhaLinguagemParser::FLOAT, 0);
}

tree::TerminalNode* MinhaLinguagemParser::Tipo_baseContext::CHAR() {
  return getToken(MinhaLinguagemParser::CHAR, 0);
}

tree::TerminalNode* MinhaLinguagemParser::Tipo_baseContext::STRING() {
  return getToken(MinhaLinguagemParser::STRING, 0);
}

tree::TerminalNode* MinhaLinguagemParser::Tipo_baseContext::STRING_TYPE() {
  return getToken(MinhaLinguagemParser::STRING_TYPE, 0);
}

tree::TerminalNode* MinhaLinguagemParser::Tipo_baseContext::IDENTIFICADOR() {
  return getToken(MinhaLinguagemParser::IDENTIFICADOR, 0);
}


size_t MinhaLinguagemParser::Tipo_baseContext::getRuleIndex() const {
  return MinhaLinguagemParser::RuleTipo_base;
}

void MinhaLinguagemParser::Tipo_baseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MinhaLinguagemListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTipo_base(this);
}

void MinhaLinguagemParser::Tipo_baseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MinhaLinguagemListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTipo_base(this);
}


std::any MinhaLinguagemParser::Tipo_baseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MinhaLinguagemVisitor*>(visitor))
    return parserVisitor->visitTipo_base(this);
  else
    return visitor->visitChildren(this);
}

MinhaLinguagemParser::Tipo_baseContext* MinhaLinguagemParser::tipo_base() {
  Tipo_baseContext *_localctx = _tracker.createInstance<Tipo_baseContext>(_ctx, getState());
  enterRule(_localctx, 24, MinhaLinguagemParser::RuleTipo_base);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(302);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 25838523777024) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TipoContext ------------------------------------------------------------------

MinhaLinguagemParser::TipoContext::TipoContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MinhaLinguagemParser::Tipo_baseContext* MinhaLinguagemParser::TipoContext::tipo_base() {
  return getRuleContext<MinhaLinguagemParser::Tipo_baseContext>(0);
}

tree::TerminalNode* MinhaLinguagemParser::TipoContext::ABRE_COLCHETES() {
  return getToken(MinhaLinguagemParser::ABRE_COLCHETES, 0);
}

tree::TerminalNode* MinhaLinguagemParser::TipoContext::FECHA_COLCHETES() {
  return getToken(MinhaLinguagemParser::FECHA_COLCHETES, 0);
}

tree::TerminalNode* MinhaLinguagemParser::TipoContext::VOID() {
  return getToken(MinhaLinguagemParser::VOID, 0);
}


size_t MinhaLinguagemParser::TipoContext::getRuleIndex() const {
  return MinhaLinguagemParser::RuleTipo;
}

void MinhaLinguagemParser::TipoContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MinhaLinguagemListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTipo(this);
}

void MinhaLinguagemParser::TipoContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MinhaLinguagemListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTipo(this);
}


std::any MinhaLinguagemParser::TipoContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MinhaLinguagemVisitor*>(visitor))
    return parserVisitor->visitTipo(this);
  else
    return visitor->visitChildren(this);
}

MinhaLinguagemParser::TipoContext* MinhaLinguagemParser::tipo() {
  TipoContext *_localctx = _tracker.createInstance<TipoContext>(_ctx, getState());
  enterRule(_localctx, 26, MinhaLinguagemParser::RuleTipo);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(310);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MinhaLinguagemParser::STRING_TYPE:
      case MinhaLinguagemParser::INT:
      case MinhaLinguagemParser::FLOAT:
      case MinhaLinguagemParser::CHAR:
      case MinhaLinguagemParser::STRING:
      case MinhaLinguagemParser::IDENTIFICADOR: {
        enterOuterAlt(_localctx, 1);
        setState(304);
        tipo_base();
        setState(307);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == MinhaLinguagemParser::ABRE_COLCHETES) {
          setState(305);
          match(MinhaLinguagemParser::ABRE_COLCHETES);
          setState(306);
          match(MinhaLinguagemParser::FECHA_COLCHETES);
        }
        break;
      }

      case MinhaLinguagemParser::VOID: {
        enterOuterAlt(_localctx, 2);
        setState(309);
        match(MinhaLinguagemParser::VOID);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AnotacaoContext ------------------------------------------------------------------

MinhaLinguagemParser::AnotacaoContext::AnotacaoContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MinhaLinguagemParser::AnotacaoContext::OVERRIDE() {
  return getToken(MinhaLinguagemParser::OVERRIDE, 0);
}


size_t MinhaLinguagemParser::AnotacaoContext::getRuleIndex() const {
  return MinhaLinguagemParser::RuleAnotacao;
}

void MinhaLinguagemParser::AnotacaoContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MinhaLinguagemListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAnotacao(this);
}

void MinhaLinguagemParser::AnotacaoContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MinhaLinguagemListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAnotacao(this);
}


std::any MinhaLinguagemParser::AnotacaoContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MinhaLinguagemVisitor*>(visitor))
    return parserVisitor->visitAnotacao(this);
  else
    return visitor->visitChildren(this);
}

MinhaLinguagemParser::AnotacaoContext* MinhaLinguagemParser::anotacao() {
  AnotacaoContext *_localctx = _tracker.createInstance<AnotacaoContext>(_ctx, getState());
  enterRule(_localctx, 28, MinhaLinguagemParser::RuleAnotacao);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(312);
    match(MinhaLinguagemParser::OVERRIDE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncaoMainContext ------------------------------------------------------------------

MinhaLinguagemParser::FuncaoMainContext::FuncaoMainContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MinhaLinguagemParser::FuncaoMainContext::ABRE_PARENTESES() {
  return getToken(MinhaLinguagemParser::ABRE_PARENTESES, 0);
}

tree::TerminalNode* MinhaLinguagemParser::FuncaoMainContext::FECHA_PARENTESES() {
  return getToken(MinhaLinguagemParser::FECHA_PARENTESES, 0);
}

MinhaLinguagemParser::BlocoContext* MinhaLinguagemParser::FuncaoMainContext::bloco() {
  return getRuleContext<MinhaLinguagemParser::BlocoContext>(0);
}


size_t MinhaLinguagemParser::FuncaoMainContext::getRuleIndex() const {
  return MinhaLinguagemParser::RuleFuncaoMain;
}

void MinhaLinguagemParser::FuncaoMainContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MinhaLinguagemListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncaoMain(this);
}

void MinhaLinguagemParser::FuncaoMainContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MinhaLinguagemListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncaoMain(this);
}


std::any MinhaLinguagemParser::FuncaoMainContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MinhaLinguagemVisitor*>(visitor))
    return parserVisitor->visitFuncaoMain(this);
  else
    return visitor->visitChildren(this);
}

MinhaLinguagemParser::FuncaoMainContext* MinhaLinguagemParser::funcaoMain() {
  FuncaoMainContext *_localctx = _tracker.createInstance<FuncaoMainContext>(_ctx, getState());
  enterRule(_localctx, 30, MinhaLinguagemParser::RuleFuncaoMain);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(314);
    match(MinhaLinguagemParser::T__2);
    setState(315);
    match(MinhaLinguagemParser::ABRE_PARENTESES);
    setState(316);
    match(MinhaLinguagemParser::FECHA_PARENTESES);
    setState(317);
    bloco();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool MinhaLinguagemParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 11: return expressaoSempred(antlrcpp::downCast<ExpressaoContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool MinhaLinguagemParser::expressaoSempred(ExpressaoContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 20);
    case 1: return precpred(_ctx, 19);
    case 2: return precpred(_ctx, 18);
    case 3: return precpred(_ctx, 17);
    case 4: return precpred(_ctx, 16);
    case 5: return precpred(_ctx, 15);
    case 6: return precpred(_ctx, 3);
    case 7: return precpred(_ctx, 2);
    case 8: return precpred(_ctx, 5);
    case 9: return precpred(_ctx, 4);

  default:
    break;
  }
  return true;
}

void MinhaLinguagemParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  minhalinguagemParserInitialize();
#else
  ::antlr4::internal::call_once(minhalinguagemParserOnceFlag, minhalinguagemParserInitialize);
#endif
}
