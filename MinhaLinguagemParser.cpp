
// Generated from MinhaLinguagem.g4 by ANTLR 4.13.1


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
      "tipo", "anotacao"
    },
    std::vector<std::string>{
      "", "'extends'", "'new'", "';'", "','", "'('", "')'", "'{'", "'}'", 
      "'='", "'['", "']'", "'.'", "':'", "'public'", "'private'", "'protected'", 
      "'static'", "'String'", "'@Override'", "'+'", "'-'", "'*'", "'/'", 
      "'>'", "'>='", "'<'", "'<='", "'=='", "'!='", "'&&'", "'||'", "'if'", 
      "'else'", "'while'", "'for'", "'class'", "'return'", "'int'", "'float'", 
      "'char'", "'string'", "'void'"
    },
    std::vector<std::string>{
      "", "", "", "PONTO_VIRGULA", "VIRGULA", "ABRE_PARENTESES", "FECHA_PARENTESES", 
      "ABRE_CHAVES", "FECHA_CHAVES", "ATRIBUICAO", "ABRE_COLCHETES", "FECHA_COLCHETES", 
      "PONTO", "DOIS_PONTOS", "PUBLIC", "PRIVATE", "PROTECTED", "STATIC", 
      "STRING_TYPE", "OVERRIDE", "MAIS", "MENOS", "MULT", "DIV", "MAIOR", 
      "MAIOR_IGUAL", "MENOR", "MENOR_IGUAL", "IGUAL", "DIFERENTE", "E_LOGICO", 
      "OU_LOGICO", "IF", "ELSE", "WHILE", "FOR", "CLASS", "RETURN", "INT", 
      "FLOAT", "CHAR", "STRING", "VOID", "IDENTIFICADOR", "NUM_INT", "NUM_FLOAT", 
      "TEXTO", "COMENTARIO", "COMENTARIO_BLOCO", "ESPACO"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,49,309,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,1,0,1,0,4,0,33,8,0,11,0,12,0,34,1,0,1,0,1,1,3,1,40,8,1,1,1,3,1,43,
  	8,1,1,1,1,1,1,1,1,1,3,1,49,8,1,1,1,1,1,5,1,53,8,1,10,1,12,1,56,9,1,1,
  	1,1,1,1,2,3,2,61,8,2,1,2,1,2,3,2,65,8,2,1,2,1,2,3,2,69,8,2,1,2,3,2,72,
  	8,2,1,3,3,3,75,8,3,1,3,1,3,1,3,3,3,80,8,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,
  	5,3,89,8,3,10,3,12,3,92,9,3,3,3,94,8,3,1,3,3,3,97,8,3,1,3,1,3,1,4,1,4,
  	1,4,1,4,3,4,105,8,4,1,4,1,4,1,4,1,5,1,5,1,5,5,5,113,8,5,10,5,12,5,116,
  	9,5,1,6,1,6,1,6,1,7,1,7,1,7,1,7,3,7,125,8,7,1,7,3,7,128,8,7,1,7,1,7,3,
  	7,132,8,7,1,7,1,7,1,8,1,8,5,8,138,8,8,10,8,12,8,141,9,8,1,8,1,8,1,9,1,
  	9,1,9,1,9,1,9,1,9,1,9,3,9,152,8,9,1,9,3,9,155,8,9,1,10,1,10,1,10,1,10,
  	1,10,1,10,1,10,3,10,164,8,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,
  	1,10,1,10,3,10,176,8,10,3,10,178,8,10,1,10,1,10,3,10,182,8,10,1,10,1,
  	10,3,10,186,8,10,1,10,1,10,3,10,190,8,10,1,11,1,11,1,11,1,11,1,11,1,11,
  	1,11,1,11,1,11,1,11,1,11,1,11,1,11,5,11,205,8,11,10,11,12,11,208,9,11,
  	3,11,210,8,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,
  	1,11,1,11,1,11,1,11,1,11,5,11,228,8,11,10,11,12,11,231,9,11,3,11,233,
  	8,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,3,11,242,8,11,1,11,1,11,1,11,
  	1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,
  	1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,
  	1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,5,11,284,8,11,10,11,12,11,
  	287,9,11,3,11,289,8,11,1,11,5,11,292,8,11,10,11,12,11,295,9,11,1,12,1,
  	12,1,13,1,13,1,13,3,13,302,8,13,1,13,3,13,305,8,13,1,14,1,14,1,14,0,1,
  	22,15,0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,0,6,1,0,14,16,1,0,22,23,
  	1,0,20,21,1,0,24,27,1,0,28,29,3,0,18,18,38,41,43,43,353,0,32,1,0,0,0,
  	2,39,1,0,0,0,4,71,1,0,0,0,6,74,1,0,0,0,8,100,1,0,0,0,10,109,1,0,0,0,12,
  	117,1,0,0,0,14,120,1,0,0,0,16,135,1,0,0,0,18,154,1,0,0,0,20,189,1,0,0,
  	0,22,241,1,0,0,0,24,296,1,0,0,0,26,304,1,0,0,0,28,306,1,0,0,0,30,33,3,
  	2,1,0,31,33,3,8,4,0,32,30,1,0,0,0,32,31,1,0,0,0,33,34,1,0,0,0,34,32,1,
  	0,0,0,34,35,1,0,0,0,35,36,1,0,0,0,36,37,5,0,0,1,37,1,1,0,0,0,38,40,7,
  	0,0,0,39,38,1,0,0,0,39,40,1,0,0,0,40,42,1,0,0,0,41,43,5,17,0,0,42,41,
  	1,0,0,0,42,43,1,0,0,0,43,44,1,0,0,0,44,45,5,36,0,0,45,48,5,43,0,0,46,
  	47,5,1,0,0,47,49,5,43,0,0,48,46,1,0,0,0,48,49,1,0,0,0,49,50,1,0,0,0,50,
  	54,5,7,0,0,51,53,3,4,2,0,52,51,1,0,0,0,53,56,1,0,0,0,54,52,1,0,0,0,54,
  	55,1,0,0,0,55,57,1,0,0,0,56,54,1,0,0,0,57,58,5,8,0,0,58,3,1,0,0,0,59,
  	61,3,28,14,0,60,59,1,0,0,0,60,61,1,0,0,0,61,62,1,0,0,0,62,72,3,14,7,0,
  	63,65,3,28,14,0,64,63,1,0,0,0,64,65,1,0,0,0,65,66,1,0,0,0,66,72,3,8,4,
  	0,67,69,3,28,14,0,68,67,1,0,0,0,68,69,1,0,0,0,69,70,1,0,0,0,70,72,3,6,
  	3,0,71,60,1,0,0,0,71,64,1,0,0,0,71,68,1,0,0,0,72,5,1,0,0,0,73,75,7,0,
  	0,0,74,73,1,0,0,0,74,75,1,0,0,0,75,76,1,0,0,0,76,77,5,43,0,0,77,79,5,
  	5,0,0,78,80,3,10,5,0,79,78,1,0,0,0,79,80,1,0,0,0,80,81,1,0,0,0,81,96,
  	5,6,0,0,82,83,5,13,0,0,83,84,5,43,0,0,84,93,5,5,0,0,85,90,3,22,11,0,86,
  	87,5,4,0,0,87,89,3,22,11,0,88,86,1,0,0,0,89,92,1,0,0,0,90,88,1,0,0,0,
  	90,91,1,0,0,0,91,94,1,0,0,0,92,90,1,0,0,0,93,85,1,0,0,0,93,94,1,0,0,0,
  	94,95,1,0,0,0,95,97,5,6,0,0,96,82,1,0,0,0,96,97,1,0,0,0,97,98,1,0,0,0,
  	98,99,3,16,8,0,99,7,1,0,0,0,100,101,3,26,13,0,101,102,5,43,0,0,102,104,
  	5,5,0,0,103,105,3,10,5,0,104,103,1,0,0,0,104,105,1,0,0,0,105,106,1,0,
  	0,0,106,107,5,6,0,0,107,108,3,16,8,0,108,9,1,0,0,0,109,114,3,12,6,0,110,
  	111,5,4,0,0,111,113,3,12,6,0,112,110,1,0,0,0,113,116,1,0,0,0,114,112,
  	1,0,0,0,114,115,1,0,0,0,115,11,1,0,0,0,116,114,1,0,0,0,117,118,3,26,13,
  	0,118,119,5,43,0,0,119,13,1,0,0,0,120,121,3,26,13,0,121,127,5,43,0,0,
  	122,124,5,10,0,0,123,125,3,22,11,0,124,123,1,0,0,0,124,125,1,0,0,0,125,
  	126,1,0,0,0,126,128,5,11,0,0,127,122,1,0,0,0,127,128,1,0,0,0,128,131,
  	1,0,0,0,129,130,5,9,0,0,130,132,3,22,11,0,131,129,1,0,0,0,131,132,1,0,
  	0,0,132,133,1,0,0,0,133,134,5,3,0,0,134,15,1,0,0,0,135,139,5,7,0,0,136,
  	138,3,18,9,0,137,136,1,0,0,0,138,141,1,0,0,0,139,137,1,0,0,0,139,140,
  	1,0,0,0,140,142,1,0,0,0,141,139,1,0,0,0,142,143,5,8,0,0,143,17,1,0,0,
  	0,144,155,3,14,7,0,145,155,3,20,10,0,146,147,3,22,11,0,147,148,5,3,0,
  	0,148,155,1,0,0,0,149,151,5,37,0,0,150,152,3,22,11,0,151,150,1,0,0,0,
  	151,152,1,0,0,0,152,153,1,0,0,0,153,155,5,3,0,0,154,144,1,0,0,0,154,145,
  	1,0,0,0,154,146,1,0,0,0,154,149,1,0,0,0,155,19,1,0,0,0,156,157,5,32,0,
  	0,157,158,5,5,0,0,158,159,3,22,11,0,159,160,5,6,0,0,160,163,3,16,8,0,
  	161,162,5,33,0,0,162,164,3,16,8,0,163,161,1,0,0,0,163,164,1,0,0,0,164,
  	190,1,0,0,0,165,166,5,34,0,0,166,167,5,5,0,0,167,168,3,22,11,0,168,169,
  	5,6,0,0,169,170,3,16,8,0,170,190,1,0,0,0,171,172,5,35,0,0,172,177,5,5,
  	0,0,173,178,3,14,7,0,174,176,3,22,11,0,175,174,1,0,0,0,175,176,1,0,0,
  	0,176,178,1,0,0,0,177,173,1,0,0,0,177,175,1,0,0,0,178,179,1,0,0,0,179,
  	181,5,3,0,0,180,182,3,22,11,0,181,180,1,0,0,0,181,182,1,0,0,0,182,183,
  	1,0,0,0,183,185,5,3,0,0,184,186,3,22,11,0,185,184,1,0,0,0,185,186,1,0,
  	0,0,186,187,1,0,0,0,187,188,5,6,0,0,188,190,3,16,8,0,189,156,1,0,0,0,
  	189,165,1,0,0,0,189,171,1,0,0,0,190,21,1,0,0,0,191,192,6,11,-1,0,192,
  	193,5,43,0,0,193,194,5,9,0,0,194,242,3,22,11,20,195,196,5,5,0,0,196,197,
  	3,22,11,0,197,198,5,6,0,0,198,242,1,0,0,0,199,200,5,43,0,0,200,209,5,
  	5,0,0,201,206,3,22,11,0,202,203,5,4,0,0,203,205,3,22,11,0,204,202,1,0,
  	0,0,205,208,1,0,0,0,206,204,1,0,0,0,206,207,1,0,0,0,207,210,1,0,0,0,208,
  	206,1,0,0,0,209,201,1,0,0,0,209,210,1,0,0,0,210,211,1,0,0,0,211,242,5,
  	6,0,0,212,242,5,43,0,0,213,242,5,44,0,0,214,242,5,45,0,0,215,242,5,46,
  	0,0,216,217,5,43,0,0,217,218,5,10,0,0,218,219,3,22,11,0,219,220,5,11,
  	0,0,220,242,1,0,0,0,221,222,5,2,0,0,222,223,5,43,0,0,223,232,5,5,0,0,
  	224,229,3,22,11,0,225,226,5,4,0,0,226,228,3,22,11,0,227,225,1,0,0,0,228,
  	231,1,0,0,0,229,227,1,0,0,0,229,230,1,0,0,0,230,233,1,0,0,0,231,229,1,
  	0,0,0,232,224,1,0,0,0,232,233,1,0,0,0,233,234,1,0,0,0,234,242,5,6,0,0,
  	235,236,5,2,0,0,236,237,3,24,12,0,237,238,5,10,0,0,238,239,3,22,11,0,
  	239,240,5,11,0,0,240,242,1,0,0,0,241,191,1,0,0,0,241,195,1,0,0,0,241,
  	199,1,0,0,0,241,212,1,0,0,0,241,213,1,0,0,0,241,214,1,0,0,0,241,215,1,
  	0,0,0,241,216,1,0,0,0,241,221,1,0,0,0,241,235,1,0,0,0,242,293,1,0,0,0,
  	243,244,10,19,0,0,244,245,7,1,0,0,245,292,3,22,11,20,246,247,10,18,0,
  	0,247,248,7,2,0,0,248,292,3,22,11,19,249,250,10,17,0,0,250,251,7,3,0,
  	0,251,292,3,22,11,18,252,253,10,16,0,0,253,254,7,4,0,0,254,292,3,22,11,
  	17,255,256,10,15,0,0,256,257,5,30,0,0,257,292,3,22,11,16,258,259,10,14,
  	0,0,259,260,5,31,0,0,260,292,3,22,11,15,261,262,10,2,0,0,262,263,5,12,
  	0,0,263,264,5,43,0,0,264,265,5,9,0,0,265,292,3,22,11,3,266,267,10,1,0,
  	0,267,268,5,10,0,0,268,269,3,22,11,0,269,270,5,11,0,0,270,271,5,9,0,0,
  	271,272,3,22,11,2,272,292,1,0,0,0,273,274,10,4,0,0,274,275,5,12,0,0,275,
  	292,5,43,0,0,276,277,10,3,0,0,277,278,5,12,0,0,278,279,5,43,0,0,279,288,
  	5,5,0,0,280,285,3,22,11,0,281,282,5,4,0,0,282,284,3,22,11,0,283,281,1,
  	0,0,0,284,287,1,0,0,0,285,283,1,0,0,0,285,286,1,0,0,0,286,289,1,0,0,0,
  	287,285,1,0,0,0,288,280,1,0,0,0,288,289,1,0,0,0,289,290,1,0,0,0,290,292,
  	5,6,0,0,291,243,1,0,0,0,291,246,1,0,0,0,291,249,1,0,0,0,291,252,1,0,0,
  	0,291,255,1,0,0,0,291,258,1,0,0,0,291,261,1,0,0,0,291,266,1,0,0,0,291,
  	273,1,0,0,0,291,276,1,0,0,0,292,295,1,0,0,0,293,291,1,0,0,0,293,294,1,
  	0,0,0,294,23,1,0,0,0,295,293,1,0,0,0,296,297,7,5,0,0,297,25,1,0,0,0,298,
  	301,3,24,12,0,299,300,5,10,0,0,300,302,5,11,0,0,301,299,1,0,0,0,301,302,
  	1,0,0,0,302,305,1,0,0,0,303,305,5,42,0,0,304,298,1,0,0,0,304,303,1,0,
  	0,0,305,27,1,0,0,0,306,307,5,19,0,0,307,29,1,0,0,0,40,32,34,39,42,48,
  	54,60,64,68,71,74,79,90,93,96,104,114,124,127,131,139,151,154,163,175,
  	177,181,185,189,206,209,229,232,241,285,288,291,293,301,304
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
    setState(32); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(32);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case MinhaLinguagemParser::PUBLIC:
        case MinhaLinguagemParser::PRIVATE:
        case MinhaLinguagemParser::PROTECTED:
        case MinhaLinguagemParser::STATIC:
        case MinhaLinguagemParser::CLASS: {
          setState(30);
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
          setState(31);
          declaracao_funcao();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(34); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 17386028122112) != 0));
    setState(36);
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
    setState(39);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 114688) != 0)) {
      setState(38);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 114688) != 0))) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
    setState(42);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MinhaLinguagemParser::STATIC) {
      setState(41);
      match(MinhaLinguagemParser::STATIC);
    }
    setState(44);
    match(MinhaLinguagemParser::CLASS);
    setState(45);
    antlrcpp::downCast<Declaracao_classeContext *>(_localctx)->ID = match(MinhaLinguagemParser::IDENTIFICADOR);
    setState(48);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MinhaLinguagemParser::T__0) {
      setState(46);
      match(MinhaLinguagemParser::T__0);
      setState(47);
      match(MinhaLinguagemParser::IDENTIFICADOR);
    }
    setState(50);
    match(MinhaLinguagemParser::ABRE_CHAVES);
    setState(54);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 17317309038592) != 0)) {
      setState(51);
      membro();
      setState(56);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(57);
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
    setState(71);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(60);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == MinhaLinguagemParser::OVERRIDE) {
        setState(59);
        anotacao();
      }
      setState(62);
      declaracao_variavel();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(64);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == MinhaLinguagemParser::OVERRIDE) {
        setState(63);
        anotacao();
      }
      setState(66);
      declaracao_funcao();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(68);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == MinhaLinguagemParser::OVERRIDE) {
        setState(67);
        anotacao();
      }
      setState(70);
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
    setState(74);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 114688) != 0)) {
      setState(73);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 114688) != 0))) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
    setState(76);
    match(MinhaLinguagemParser::IDENTIFICADOR);
    setState(77);
    match(MinhaLinguagemParser::ABRE_PARENTESES);
    setState(79);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 17317308399616) != 0)) {
      setState(78);
      parametros();
    }
    setState(81);
    match(MinhaLinguagemParser::FECHA_PARENTESES);
    setState(96);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MinhaLinguagemParser::DOIS_PONTOS) {
      setState(82);
      match(MinhaLinguagemParser::DOIS_PONTOS);
      setState(83);
      match(MinhaLinguagemParser::IDENTIFICADOR);
      setState(84);
      match(MinhaLinguagemParser::ABRE_PARENTESES);
      setState(93);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 131941395333156) != 0)) {
        setState(85);
        expressao(0);
        setState(90);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == MinhaLinguagemParser::VIRGULA) {
          setState(86);
          match(MinhaLinguagemParser::VIRGULA);
          setState(87);
          expressao(0);
          setState(92);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(95);
      match(MinhaLinguagemParser::FECHA_PARENTESES);
    }
    setState(98);
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
    setState(100);
    tipo();
    setState(101);
    antlrcpp::downCast<Declaracao_funcaoContext *>(_localctx)->ID = match(MinhaLinguagemParser::IDENTIFICADOR);
    setState(102);
    match(MinhaLinguagemParser::ABRE_PARENTESES);
    setState(104);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 17317308399616) != 0)) {
      setState(103);
      parametros();
    }
    setState(106);
    match(MinhaLinguagemParser::FECHA_PARENTESES);
    setState(107);
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
    setState(109);
    parametro();
    setState(114);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MinhaLinguagemParser::VIRGULA) {
      setState(110);
      match(MinhaLinguagemParser::VIRGULA);
      setState(111);
      parametro();
      setState(116);
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
    setState(117);
    tipo();
    setState(118);
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


size_t MinhaLinguagemParser::Declaracao_variavelContext::getRuleIndex() const {
  return MinhaLinguagemParser::RuleDeclaracao_variavel;
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
    setState(120);
    tipo();
    setState(121);
    antlrcpp::downCast<Declaracao_variavelContext *>(_localctx)->ID = match(MinhaLinguagemParser::IDENTIFICADOR);
    setState(127);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MinhaLinguagemParser::ABRE_COLCHETES) {
      setState(122);
      match(MinhaLinguagemParser::ABRE_COLCHETES);
      setState(124);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 131941395333156) != 0)) {
        setState(123);
        expressao(0);
      }
      setState(126);
      match(MinhaLinguagemParser::FECHA_COLCHETES);
    }
    setState(131);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MinhaLinguagemParser::ATRIBUICAO) {
      setState(129);
      match(MinhaLinguagemParser::ATRIBUICAO);
      setState(130);
      expressao(0);
    }
    setState(133);
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
    setState(135);
    match(MinhaLinguagemParser::ABRE_CHAVES);
    setState(139);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 140655884238884) != 0)) {
      setState(136);
      declaracao();
      setState(141);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(142);
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
    setState(154);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<MinhaLinguagemParser::VarDeclContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(144);
      declaracao_variavel();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<MinhaLinguagemParser::ControleDeclContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(145);
      estrutura_controle();
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<MinhaLinguagemParser::ExprStmtContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(146);
      expressao(0);
      setState(147);
      match(MinhaLinguagemParser::PONTO_VIRGULA);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<MinhaLinguagemParser::ReturnStmtContext>(_localctx);
      enterOuterAlt(_localctx, 4);
      setState(149);
      match(MinhaLinguagemParser::RETURN);
      setState(151);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 131941395333156) != 0)) {
        setState(150);
        expressao(0);
      }
      setState(153);
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
    setState(189);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MinhaLinguagemParser::IF: {
        _localctx = _tracker.createInstance<MinhaLinguagemParser::IfContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(156);
        match(MinhaLinguagemParser::IF);
        setState(157);
        match(MinhaLinguagemParser::ABRE_PARENTESES);
        setState(158);
        expressao(0);
        setState(159);
        match(MinhaLinguagemParser::FECHA_PARENTESES);
        setState(160);
        bloco();
        setState(163);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == MinhaLinguagemParser::ELSE) {
          setState(161);
          match(MinhaLinguagemParser::ELSE);
          setState(162);
          bloco();
        }
        break;
      }

      case MinhaLinguagemParser::WHILE: {
        _localctx = _tracker.createInstance<MinhaLinguagemParser::WhileContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(165);
        match(MinhaLinguagemParser::WHILE);
        setState(166);
        match(MinhaLinguagemParser::ABRE_PARENTESES);
        setState(167);
        expressao(0);
        setState(168);
        match(MinhaLinguagemParser::FECHA_PARENTESES);
        setState(169);
        bloco();
        break;
      }

      case MinhaLinguagemParser::FOR: {
        _localctx = _tracker.createInstance<MinhaLinguagemParser::ForContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(171);
        match(MinhaLinguagemParser::FOR);
        setState(172);
        match(MinhaLinguagemParser::ABRE_PARENTESES);
        setState(177);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx)) {
        case 1: {
          setState(173);
          declaracao_variavel();
          break;
        }

        case 2: {
          setState(175);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if ((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 131941395333156) != 0)) {
            setState(174);
            expressao(0);
          }
          break;
        }

        default:
          break;
        }
        setState(179);
        match(MinhaLinguagemParser::PONTO_VIRGULA);
        setState(181);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 131941395333156) != 0)) {
          setState(180);
          expressao(0);
        }
        setState(183);
        match(MinhaLinguagemParser::PONTO_VIRGULA);
        setState(185);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 131941395333156) != 0)) {
          setState(184);
          expressao(0);
        }
        setState(187);
        match(MinhaLinguagemParser::FECHA_PARENTESES);
        setState(188);
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


std::any MinhaLinguagemParser::AtribuicaoVetorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MinhaLinguagemVisitor*>(visitor))
    return parserVisitor->visitAtribuicaoVetor(this);
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
    setState(241);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<AtribuicaoContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(192);
      match(MinhaLinguagemParser::IDENTIFICADOR);
      setState(193);
      match(MinhaLinguagemParser::ATRIBUICAO);
      setState(194);
      expressao(20);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<GrupoContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(195);
      match(MinhaLinguagemParser::ABRE_PARENTESES);
      setState(196);
      expressao(0);
      setState(197);
      match(MinhaLinguagemParser::FECHA_PARENTESES);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<ChamadaFuncaoContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(199);
      match(MinhaLinguagemParser::IDENTIFICADOR);
      setState(200);
      match(MinhaLinguagemParser::ABRE_PARENTESES);
      setState(209);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 131941395333156) != 0)) {
        setState(201);
        expressao(0);
        setState(206);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == MinhaLinguagemParser::VIRGULA) {
          setState(202);
          match(MinhaLinguagemParser::VIRGULA);
          setState(203);
          expressao(0);
          setState(208);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(211);
      match(MinhaLinguagemParser::FECHA_PARENTESES);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<VariavelContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(212);
      match(MinhaLinguagemParser::IDENTIFICADOR);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<InteiroContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(213);
      match(MinhaLinguagemParser::NUM_INT);
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<FloatContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(214);
      match(MinhaLinguagemParser::NUM_FLOAT);
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<StringContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(215);
      match(MinhaLinguagemParser::TEXTO);
      break;
    }

    case 8: {
      _localctx = _tracker.createInstance<AcessoVetorContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(216);
      match(MinhaLinguagemParser::IDENTIFICADOR);
      setState(217);
      match(MinhaLinguagemParser::ABRE_COLCHETES);
      setState(218);
      expressao(0);
      setState(219);
      match(MinhaLinguagemParser::FECHA_COLCHETES);
      break;
    }

    case 9: {
      _localctx = _tracker.createInstance<NewObjetoContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(221);
      match(MinhaLinguagemParser::T__1);
      setState(222);
      match(MinhaLinguagemParser::IDENTIFICADOR);
      setState(223);
      match(MinhaLinguagemParser::ABRE_PARENTESES);
      setState(232);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 131941395333156) != 0)) {
        setState(224);
        expressao(0);
        setState(229);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == MinhaLinguagemParser::VIRGULA) {
          setState(225);
          match(MinhaLinguagemParser::VIRGULA);
          setState(226);
          expressao(0);
          setState(231);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(234);
      match(MinhaLinguagemParser::FECHA_PARENTESES);
      break;
    }

    case 10: {
      _localctx = _tracker.createInstance<NewVetorContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(235);
      match(MinhaLinguagemParser::T__1);
      setState(236);
      tipo_base();
      setState(237);
      match(MinhaLinguagemParser::ABRE_COLCHETES);
      setState(238);
      expressao(0);
      setState(239);
      match(MinhaLinguagemParser::FECHA_COLCHETES);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(293);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 37, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(291);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 36, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<BinariaContext>(_tracker.createInstance<ExpressaoContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpressao);
          setState(243);

          if (!(precpred(_ctx, 19))) throw FailedPredicateException(this, "precpred(_ctx, 19)");
          setState(244);
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
          setState(245);
          expressao(20);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<BinariaContext>(_tracker.createInstance<ExpressaoContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpressao);
          setState(246);

          if (!(precpred(_ctx, 18))) throw FailedPredicateException(this, "precpred(_ctx, 18)");
          setState(247);
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
          setState(248);
          expressao(19);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<BinariaContext>(_tracker.createInstance<ExpressaoContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpressao);
          setState(249);

          if (!(precpred(_ctx, 17))) throw FailedPredicateException(this, "precpred(_ctx, 17)");
          setState(250);
          antlrcpp::downCast<BinariaContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 251658240) != 0))) {
            antlrcpp::downCast<BinariaContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(251);
          expressao(18);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<BinariaContext>(_tracker.createInstance<ExpressaoContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpressao);
          setState(252);

          if (!(precpred(_ctx, 16))) throw FailedPredicateException(this, "precpred(_ctx, 16)");
          setState(253);
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
          setState(254);
          expressao(17);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<BinariaContext>(_tracker.createInstance<ExpressaoContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpressao);
          setState(255);

          if (!(precpred(_ctx, 15))) throw FailedPredicateException(this, "precpred(_ctx, 15)");
          setState(256);
          antlrcpp::downCast<BinariaContext *>(_localctx)->op = match(MinhaLinguagemParser::E_LOGICO);
          setState(257);
          expressao(16);
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<BinariaContext>(_tracker.createInstance<ExpressaoContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpressao);
          setState(258);

          if (!(precpred(_ctx, 14))) throw FailedPredicateException(this, "precpred(_ctx, 14)");
          setState(259);
          antlrcpp::downCast<BinariaContext *>(_localctx)->op = match(MinhaLinguagemParser::OU_LOGICO);
          setState(260);
          expressao(15);
          break;
        }

        case 7: {
          auto newContext = _tracker.createInstance<AtribuicaoMembroContext>(_tracker.createInstance<ExpressaoContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpressao);
          setState(261);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(262);
          match(MinhaLinguagemParser::PONTO);
          setState(263);
          match(MinhaLinguagemParser::IDENTIFICADOR);
          setState(264);
          match(MinhaLinguagemParser::ATRIBUICAO);
          setState(265);
          expressao(3);
          break;
        }

        case 8: {
          auto newContext = _tracker.createInstance<AtribuicaoVetorContext>(_tracker.createInstance<ExpressaoContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpressao);
          setState(266);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(267);
          match(MinhaLinguagemParser::ABRE_COLCHETES);
          setState(268);
          expressao(0);
          setState(269);
          match(MinhaLinguagemParser::FECHA_COLCHETES);
          setState(270);
          match(MinhaLinguagemParser::ATRIBUICAO);
          setState(271);
          expressao(2);
          break;
        }

        case 9: {
          auto newContext = _tracker.createInstance<AcessoMembroContext>(_tracker.createInstance<ExpressaoContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpressao);
          setState(273);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(274);
          match(MinhaLinguagemParser::PONTO);
          setState(275);
          match(MinhaLinguagemParser::IDENTIFICADOR);
          break;
        }

        case 10: {
          auto newContext = _tracker.createInstance<ChamadaMetodoContext>(_tracker.createInstance<ExpressaoContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpressao);
          setState(276);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(277);
          match(MinhaLinguagemParser::PONTO);
          setState(278);
          match(MinhaLinguagemParser::IDENTIFICADOR);
          setState(279);
          match(MinhaLinguagemParser::ABRE_PARENTESES);
          setState(288);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if ((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 131941395333156) != 0)) {
            setState(280);
            expressao(0);
            setState(285);
            _errHandler->sync(this);
            _la = _input->LA(1);
            while (_la == MinhaLinguagemParser::VIRGULA) {
              setState(281);
              match(MinhaLinguagemParser::VIRGULA);
              setState(282);
              expressao(0);
              setState(287);
              _errHandler->sync(this);
              _la = _input->LA(1);
            }
          }
          setState(290);
          match(MinhaLinguagemParser::FECHA_PARENTESES);
          break;
        }

        default:
          break;
        } 
      }
      setState(295);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 37, _ctx);
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
    setState(296);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 12919261888512) != 0))) {
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
    setState(304);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MinhaLinguagemParser::STRING_TYPE:
      case MinhaLinguagemParser::INT:
      case MinhaLinguagemParser::FLOAT:
      case MinhaLinguagemParser::CHAR:
      case MinhaLinguagemParser::STRING:
      case MinhaLinguagemParser::IDENTIFICADOR: {
        enterOuterAlt(_localctx, 1);
        setState(298);
        tipo_base();
        setState(301);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == MinhaLinguagemParser::ABRE_COLCHETES) {
          setState(299);
          match(MinhaLinguagemParser::ABRE_COLCHETES);
          setState(300);
          match(MinhaLinguagemParser::FECHA_COLCHETES);
        }
        break;
      }

      case MinhaLinguagemParser::VOID: {
        enterOuterAlt(_localctx, 2);
        setState(303);
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
    setState(306);
    match(MinhaLinguagemParser::OVERRIDE);
   
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
    case 0: return precpred(_ctx, 19);
    case 1: return precpred(_ctx, 18);
    case 2: return precpred(_ctx, 17);
    case 3: return precpred(_ctx, 16);
    case 4: return precpred(_ctx, 15);
    case 5: return precpred(_ctx, 14);
    case 6: return precpred(_ctx, 2);
    case 7: return precpred(_ctx, 1);
    case 8: return precpred(_ctx, 4);
    case 9: return precpred(_ctx, 3);

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
