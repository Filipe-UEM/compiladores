
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
      "programa", "declaracao_classe", "membro", "declaracao_funcao", "parametros", 
      "parametro", "declaracao_variavel", "bloco", "declaracao", "estrutura_controle", 
      "expressao", "tipo"
    },
    std::vector<std::string>{
      "", "'new'", "';'", "','", "'('", "')'", "'{'", "'}'", "'='", "'['", 
      "']'", "'+'", "'-'", "'*'", "'/'", "'>'", "'>='", "'<'", "'<='", "'=='", 
      "'!='", "'&&'", "'||'", "'if'", "'else'", "'while'", "'for'", "'class'", 
      "'return'", "'int'", "'float'", "'char'", "'string'", "'void'"
    },
    std::vector<std::string>{
      "", "", "PONTO_VIRGULA", "VIRGULA", "ABRE_PARENTESES", "FECHA_PARENTESES", 
      "ABRE_CHAVES", "FECHA_CHAVES", "ATRIBUICAO", "ABRE_COLCHETES", "FECHA_COLCHETES", 
      "MAIS", "MENOS", "MULT", "DIV", "MAIOR", "MAIOR_IGUAL", "MENOR", "MENOR_IGUAL", 
      "IGUAL", "DIFERENTE", "E_LOGICO", "OU_LOGICO", "IF", "ELSE", "WHILE", 
      "FOR", "CLASS", "RETURN", "INT", "FLOAT", "CHAR", "STRING", "VOID", 
      "IDENTIFICADOR", "NUM_INT", "NUM_FLOAT", "TEXTO", "COMENTARIO", "COMENTARIO_BLOCO", 
      "ESPACO"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,40,216,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,1,0,1,0,4,0,27,8,0,11,0,12,
  	0,28,1,0,1,0,1,1,1,1,1,1,1,1,5,1,37,8,1,10,1,12,1,40,9,1,1,1,1,1,1,2,
  	1,2,3,2,46,8,2,1,3,1,3,1,3,1,3,3,3,52,8,3,1,3,1,3,1,3,1,4,1,4,1,4,5,4,
  	60,8,4,10,4,12,4,63,9,4,1,5,1,5,1,5,1,6,1,6,1,6,1,6,3,6,72,8,6,1,6,3,
  	6,75,8,6,1,6,1,6,3,6,79,8,6,1,6,1,6,1,7,1,7,5,7,85,8,7,10,7,12,7,88,9,
  	7,1,7,1,7,1,8,1,8,1,8,1,8,1,8,1,8,1,8,3,8,99,8,8,1,8,3,8,102,8,8,1,9,
  	1,9,1,9,1,9,1,9,1,9,1,9,3,9,111,8,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,
  	9,1,9,1,9,1,9,1,9,1,9,1,9,3,9,128,8,9,1,10,1,10,1,10,1,10,1,10,1,10,1,
  	10,1,10,1,10,1,10,1,10,1,10,1,10,5,10,143,8,10,10,10,12,10,146,9,10,3,
  	10,148,8,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,
  	10,1,10,1,10,1,10,1,10,3,10,166,8,10,3,10,168,8,10,1,10,1,10,1,10,1,10,
  	1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,
  	5,10,188,8,10,10,10,12,10,191,9,10,1,11,1,11,1,11,3,11,196,8,11,1,11,
  	1,11,1,11,3,11,201,8,11,1,11,1,11,1,11,3,11,206,8,11,1,11,1,11,1,11,3,
  	11,211,8,11,1,11,3,11,214,8,11,1,11,0,1,20,12,0,2,4,6,8,10,12,14,16,18,
  	20,22,0,4,1,0,13,14,1,0,11,12,1,0,15,18,1,0,19,20,245,0,26,1,0,0,0,2,
  	32,1,0,0,0,4,45,1,0,0,0,6,47,1,0,0,0,8,56,1,0,0,0,10,64,1,0,0,0,12,67,
  	1,0,0,0,14,82,1,0,0,0,16,101,1,0,0,0,18,127,1,0,0,0,20,167,1,0,0,0,22,
  	213,1,0,0,0,24,27,3,2,1,0,25,27,3,6,3,0,26,24,1,0,0,0,26,25,1,0,0,0,27,
  	28,1,0,0,0,28,26,1,0,0,0,28,29,1,0,0,0,29,30,1,0,0,0,30,31,5,0,0,1,31,
  	1,1,0,0,0,32,33,5,27,0,0,33,34,5,34,0,0,34,38,5,6,0,0,35,37,3,4,2,0,36,
  	35,1,0,0,0,37,40,1,0,0,0,38,36,1,0,0,0,38,39,1,0,0,0,39,41,1,0,0,0,40,
  	38,1,0,0,0,41,42,5,7,0,0,42,3,1,0,0,0,43,46,3,12,6,0,44,46,3,6,3,0,45,
  	43,1,0,0,0,45,44,1,0,0,0,46,5,1,0,0,0,47,48,3,22,11,0,48,49,5,34,0,0,
  	49,51,5,4,0,0,50,52,3,8,4,0,51,50,1,0,0,0,51,52,1,0,0,0,52,53,1,0,0,0,
  	53,54,5,5,0,0,54,55,3,14,7,0,55,7,1,0,0,0,56,61,3,10,5,0,57,58,5,3,0,
  	0,58,60,3,10,5,0,59,57,1,0,0,0,60,63,1,0,0,0,61,59,1,0,0,0,61,62,1,0,
  	0,0,62,9,1,0,0,0,63,61,1,0,0,0,64,65,3,22,11,0,65,66,5,34,0,0,66,11,1,
  	0,0,0,67,68,3,22,11,0,68,74,5,34,0,0,69,71,5,9,0,0,70,72,3,20,10,0,71,
  	70,1,0,0,0,71,72,1,0,0,0,72,73,1,0,0,0,73,75,5,10,0,0,74,69,1,0,0,0,74,
  	75,1,0,0,0,75,78,1,0,0,0,76,77,5,8,0,0,77,79,3,20,10,0,78,76,1,0,0,0,
  	78,79,1,0,0,0,79,80,1,0,0,0,80,81,5,2,0,0,81,13,1,0,0,0,82,86,5,6,0,0,
  	83,85,3,16,8,0,84,83,1,0,0,0,85,88,1,0,0,0,86,84,1,0,0,0,86,87,1,0,0,
  	0,87,89,1,0,0,0,88,86,1,0,0,0,89,90,5,7,0,0,90,15,1,0,0,0,91,102,3,12,
  	6,0,92,102,3,18,9,0,93,94,3,20,10,0,94,95,5,2,0,0,95,102,1,0,0,0,96,98,
  	5,28,0,0,97,99,3,20,10,0,98,97,1,0,0,0,98,99,1,0,0,0,99,100,1,0,0,0,100,
  	102,5,2,0,0,101,91,1,0,0,0,101,92,1,0,0,0,101,93,1,0,0,0,101,96,1,0,0,
  	0,102,17,1,0,0,0,103,104,5,23,0,0,104,105,5,4,0,0,105,106,3,20,10,0,106,
  	107,5,5,0,0,107,110,3,14,7,0,108,109,5,24,0,0,109,111,3,14,7,0,110,108,
  	1,0,0,0,110,111,1,0,0,0,111,128,1,0,0,0,112,113,5,25,0,0,113,114,5,4,
  	0,0,114,115,3,20,10,0,115,116,5,5,0,0,116,117,3,14,7,0,117,128,1,0,0,
  	0,118,119,5,26,0,0,119,120,5,4,0,0,120,121,3,12,6,0,121,122,3,20,10,0,
  	122,123,5,2,0,0,123,124,3,20,10,0,124,125,5,5,0,0,125,126,3,14,7,0,126,
  	128,1,0,0,0,127,103,1,0,0,0,127,112,1,0,0,0,127,118,1,0,0,0,128,19,1,
  	0,0,0,129,130,6,10,-1,0,130,131,5,34,0,0,131,132,5,8,0,0,132,168,3,20,
  	10,15,133,134,5,4,0,0,134,135,3,20,10,0,135,136,5,5,0,0,136,168,1,0,0,
  	0,137,138,5,34,0,0,138,147,5,4,0,0,139,144,3,20,10,0,140,141,5,3,0,0,
  	141,143,3,20,10,0,142,140,1,0,0,0,143,146,1,0,0,0,144,142,1,0,0,0,144,
  	145,1,0,0,0,145,148,1,0,0,0,146,144,1,0,0,0,147,139,1,0,0,0,147,148,1,
  	0,0,0,148,149,1,0,0,0,149,168,5,5,0,0,150,168,5,34,0,0,151,168,5,35,0,
  	0,152,168,5,36,0,0,153,168,5,37,0,0,154,155,5,34,0,0,155,156,5,9,0,0,
  	156,157,3,20,10,0,157,158,5,10,0,0,158,168,1,0,0,0,159,160,5,1,0,0,160,
  	165,3,22,11,0,161,162,5,9,0,0,162,163,3,20,10,0,163,164,5,10,0,0,164,
  	166,1,0,0,0,165,161,1,0,0,0,165,166,1,0,0,0,166,168,1,0,0,0,167,129,1,
  	0,0,0,167,133,1,0,0,0,167,137,1,0,0,0,167,150,1,0,0,0,167,151,1,0,0,0,
  	167,152,1,0,0,0,167,153,1,0,0,0,167,154,1,0,0,0,167,159,1,0,0,0,168,189,
  	1,0,0,0,169,170,10,14,0,0,170,171,7,0,0,0,171,188,3,20,10,15,172,173,
  	10,13,0,0,173,174,7,1,0,0,174,188,3,20,10,14,175,176,10,12,0,0,176,177,
  	7,2,0,0,177,188,3,20,10,13,178,179,10,11,0,0,179,180,7,3,0,0,180,188,
  	3,20,10,12,181,182,10,10,0,0,182,183,5,21,0,0,183,188,3,20,10,11,184,
  	185,10,9,0,0,185,186,5,22,0,0,186,188,3,20,10,10,187,169,1,0,0,0,187,
  	172,1,0,0,0,187,175,1,0,0,0,187,178,1,0,0,0,187,181,1,0,0,0,187,184,1,
  	0,0,0,188,191,1,0,0,0,189,187,1,0,0,0,189,190,1,0,0,0,190,21,1,0,0,0,
  	191,189,1,0,0,0,192,195,5,29,0,0,193,194,5,9,0,0,194,196,5,10,0,0,195,
  	193,1,0,0,0,195,196,1,0,0,0,196,214,1,0,0,0,197,200,5,30,0,0,198,199,
  	5,9,0,0,199,201,5,10,0,0,200,198,1,0,0,0,200,201,1,0,0,0,201,214,1,0,
  	0,0,202,205,5,31,0,0,203,204,5,9,0,0,204,206,5,10,0,0,205,203,1,0,0,0,
  	205,206,1,0,0,0,206,214,1,0,0,0,207,210,5,32,0,0,208,209,5,9,0,0,209,
  	211,5,10,0,0,210,208,1,0,0,0,210,211,1,0,0,0,211,214,1,0,0,0,212,214,
  	5,33,0,0,213,192,1,0,0,0,213,197,1,0,0,0,213,202,1,0,0,0,213,207,1,0,
  	0,0,213,212,1,0,0,0,214,23,1,0,0,0,25,26,28,38,45,51,61,71,74,78,86,98,
  	101,110,127,144,147,165,167,187,189,195,200,205,210,213
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
    setState(26); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(26);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case MinhaLinguagemParser::CLASS: {
          setState(24);
          declaracao_classe();
          break;
        }

        case MinhaLinguagemParser::INT:
        case MinhaLinguagemParser::FLOAT:
        case MinhaLinguagemParser::CHAR:
        case MinhaLinguagemParser::STRING:
        case MinhaLinguagemParser::VOID: {
          setState(25);
          declaracao_funcao();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(28); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 16777216000) != 0));
    setState(30);
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

tree::TerminalNode* MinhaLinguagemParser::Declaracao_classeContext::IDENTIFICADOR() {
  return getToken(MinhaLinguagemParser::IDENTIFICADOR, 0);
}

std::vector<MinhaLinguagemParser::MembroContext *> MinhaLinguagemParser::Declaracao_classeContext::membro() {
  return getRuleContexts<MinhaLinguagemParser::MembroContext>();
}

MinhaLinguagemParser::MembroContext* MinhaLinguagemParser::Declaracao_classeContext::membro(size_t i) {
  return getRuleContext<MinhaLinguagemParser::MembroContext>(i);
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
    setState(32);
    match(MinhaLinguagemParser::CLASS);
    setState(33);
    antlrcpp::downCast<Declaracao_classeContext *>(_localctx)->ID = match(MinhaLinguagemParser::IDENTIFICADOR);
    setState(34);
    match(MinhaLinguagemParser::ABRE_CHAVES);
    setState(38);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 16642998272) != 0)) {
      setState(35);
      membro();
      setState(40);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(41);
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

MinhaLinguagemParser::Declaracao_funcaoContext* MinhaLinguagemParser::MembroContext::declaracao_funcao() {
  return getRuleContext<MinhaLinguagemParser::Declaracao_funcaoContext>(0);
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

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(45);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(43);
      declaracao_variavel();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(44);
      declaracao_funcao();
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
  enterRule(_localctx, 6, MinhaLinguagemParser::RuleDeclaracao_funcao);
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
    setState(47);
    tipo();
    setState(48);
    antlrcpp::downCast<Declaracao_funcaoContext *>(_localctx)->ID = match(MinhaLinguagemParser::IDENTIFICADOR);
    setState(49);
    match(MinhaLinguagemParser::ABRE_PARENTESES);
    setState(51);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 16642998272) != 0)) {
      setState(50);
      parametros();
    }
    setState(53);
    match(MinhaLinguagemParser::FECHA_PARENTESES);
    setState(54);
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
  enterRule(_localctx, 8, MinhaLinguagemParser::RuleParametros);
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
    setState(56);
    parametro();
    setState(61);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MinhaLinguagemParser::VIRGULA) {
      setState(57);
      match(MinhaLinguagemParser::VIRGULA);
      setState(58);
      parametro();
      setState(63);
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
  enterRule(_localctx, 10, MinhaLinguagemParser::RuleParametro);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(64);
    tipo();
    setState(65);
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
  enterRule(_localctx, 12, MinhaLinguagemParser::RuleDeclaracao_variavel);
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
    setState(67);
    tipo();
    setState(68);
    antlrcpp::downCast<Declaracao_variavelContext *>(_localctx)->ID = match(MinhaLinguagemParser::IDENTIFICADOR);
    setState(74);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MinhaLinguagemParser::ABRE_COLCHETES) {
      setState(69);
      match(MinhaLinguagemParser::ABRE_COLCHETES);
      setState(71);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 257698037778) != 0)) {
        setState(70);
        expressao(0);
      }
      setState(73);
      match(MinhaLinguagemParser::FECHA_COLCHETES);
    }
    setState(78);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MinhaLinguagemParser::ATRIBUICAO) {
      setState(76);
      match(MinhaLinguagemParser::ATRIBUICAO);
      setState(77);
      expressao(0);
    }
    setState(80);
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
  enterRule(_localctx, 14, MinhaLinguagemParser::RuleBloco);
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
    setState(82);
    match(MinhaLinguagemParser::ABRE_CHAVES);
    setState(86);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 274718523410) != 0)) {
      setState(83);
      declaracao();
      setState(88);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(89);
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

MinhaLinguagemParser::Declaracao_variavelContext* MinhaLinguagemParser::DeclaracaoContext::declaracao_variavel() {
  return getRuleContext<MinhaLinguagemParser::Declaracao_variavelContext>(0);
}

MinhaLinguagemParser::Estrutura_controleContext* MinhaLinguagemParser::DeclaracaoContext::estrutura_controle() {
  return getRuleContext<MinhaLinguagemParser::Estrutura_controleContext>(0);
}

MinhaLinguagemParser::ExpressaoContext* MinhaLinguagemParser::DeclaracaoContext::expressao() {
  return getRuleContext<MinhaLinguagemParser::ExpressaoContext>(0);
}

tree::TerminalNode* MinhaLinguagemParser::DeclaracaoContext::PONTO_VIRGULA() {
  return getToken(MinhaLinguagemParser::PONTO_VIRGULA, 0);
}

tree::TerminalNode* MinhaLinguagemParser::DeclaracaoContext::RETURN() {
  return getToken(MinhaLinguagemParser::RETURN, 0);
}


size_t MinhaLinguagemParser::DeclaracaoContext::getRuleIndex() const {
  return MinhaLinguagemParser::RuleDeclaracao;
}


std::any MinhaLinguagemParser::DeclaracaoContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MinhaLinguagemVisitor*>(visitor))
    return parserVisitor->visitDeclaracao(this);
  else
    return visitor->visitChildren(this);
}

MinhaLinguagemParser::DeclaracaoContext* MinhaLinguagemParser::declaracao() {
  DeclaracaoContext *_localctx = _tracker.createInstance<DeclaracaoContext>(_ctx, getState());
  enterRule(_localctx, 16, MinhaLinguagemParser::RuleDeclaracao);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(101);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MinhaLinguagemParser::INT:
      case MinhaLinguagemParser::FLOAT:
      case MinhaLinguagemParser::CHAR:
      case MinhaLinguagemParser::STRING:
      case MinhaLinguagemParser::VOID: {
        enterOuterAlt(_localctx, 1);
        setState(91);
        declaracao_variavel();
        break;
      }

      case MinhaLinguagemParser::IF:
      case MinhaLinguagemParser::WHILE:
      case MinhaLinguagemParser::FOR: {
        enterOuterAlt(_localctx, 2);
        setState(92);
        estrutura_controle();
        break;
      }

      case MinhaLinguagemParser::T__0:
      case MinhaLinguagemParser::ABRE_PARENTESES:
      case MinhaLinguagemParser::IDENTIFICADOR:
      case MinhaLinguagemParser::NUM_INT:
      case MinhaLinguagemParser::NUM_FLOAT:
      case MinhaLinguagemParser::TEXTO: {
        enterOuterAlt(_localctx, 3);
        setState(93);
        expressao(0);
        setState(94);
        match(MinhaLinguagemParser::PONTO_VIRGULA);
        break;
      }

      case MinhaLinguagemParser::RETURN: {
        enterOuterAlt(_localctx, 4);
        setState(96);
        match(MinhaLinguagemParser::RETURN);
        setState(98);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 257698037778) != 0)) {
          setState(97);
          expressao(0);
        }
        setState(100);
        match(MinhaLinguagemParser::PONTO_VIRGULA);
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

MinhaLinguagemParser::Declaracao_variavelContext* MinhaLinguagemParser::ForContext::declaracao_variavel() {
  return getRuleContext<MinhaLinguagemParser::Declaracao_variavelContext>(0);
}

std::vector<MinhaLinguagemParser::ExpressaoContext *> MinhaLinguagemParser::ForContext::expressao() {
  return getRuleContexts<MinhaLinguagemParser::ExpressaoContext>();
}

MinhaLinguagemParser::ExpressaoContext* MinhaLinguagemParser::ForContext::expressao(size_t i) {
  return getRuleContext<MinhaLinguagemParser::ExpressaoContext>(i);
}

tree::TerminalNode* MinhaLinguagemParser::ForContext::PONTO_VIRGULA() {
  return getToken(MinhaLinguagemParser::PONTO_VIRGULA, 0);
}

tree::TerminalNode* MinhaLinguagemParser::ForContext::FECHA_PARENTESES() {
  return getToken(MinhaLinguagemParser::FECHA_PARENTESES, 0);
}

MinhaLinguagemParser::BlocoContext* MinhaLinguagemParser::ForContext::bloco() {
  return getRuleContext<MinhaLinguagemParser::BlocoContext>(0);
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
  enterRule(_localctx, 18, MinhaLinguagemParser::RuleEstrutura_controle);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(127);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MinhaLinguagemParser::IF: {
        _localctx = _tracker.createInstance<MinhaLinguagemParser::IfContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(103);
        match(MinhaLinguagemParser::IF);
        setState(104);
        match(MinhaLinguagemParser::ABRE_PARENTESES);
        setState(105);
        expressao(0);
        setState(106);
        match(MinhaLinguagemParser::FECHA_PARENTESES);
        setState(107);
        bloco();
        setState(110);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == MinhaLinguagemParser::ELSE) {
          setState(108);
          match(MinhaLinguagemParser::ELSE);
          setState(109);
          bloco();
        }
        break;
      }

      case MinhaLinguagemParser::WHILE: {
        _localctx = _tracker.createInstance<MinhaLinguagemParser::WhileContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(112);
        match(MinhaLinguagemParser::WHILE);
        setState(113);
        match(MinhaLinguagemParser::ABRE_PARENTESES);
        setState(114);
        expressao(0);
        setState(115);
        match(MinhaLinguagemParser::FECHA_PARENTESES);
        setState(116);
        bloco();
        break;
      }

      case MinhaLinguagemParser::FOR: {
        _localctx = _tracker.createInstance<MinhaLinguagemParser::ForContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(118);
        match(MinhaLinguagemParser::FOR);
        setState(119);
        match(MinhaLinguagemParser::ABRE_PARENTESES);
        setState(120);
        declaracao_variavel();
        setState(121);
        expressao(0);
        setState(122);
        match(MinhaLinguagemParser::PONTO_VIRGULA);
        setState(123);
        expressao(0);
        setState(124);
        match(MinhaLinguagemParser::FECHA_PARENTESES);
        setState(125);
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
//----------------- NewContext ------------------------------------------------------------------

MinhaLinguagemParser::TipoContext* MinhaLinguagemParser::NewContext::tipo() {
  return getRuleContext<MinhaLinguagemParser::TipoContext>(0);
}

tree::TerminalNode* MinhaLinguagemParser::NewContext::ABRE_COLCHETES() {
  return getToken(MinhaLinguagemParser::ABRE_COLCHETES, 0);
}

MinhaLinguagemParser::ExpressaoContext* MinhaLinguagemParser::NewContext::expressao() {
  return getRuleContext<MinhaLinguagemParser::ExpressaoContext>(0);
}

tree::TerminalNode* MinhaLinguagemParser::NewContext::FECHA_COLCHETES() {
  return getToken(MinhaLinguagemParser::FECHA_COLCHETES, 0);
}

MinhaLinguagemParser::NewContext::NewContext(ExpressaoContext *ctx) { copyFrom(ctx); }


std::any MinhaLinguagemParser::NewContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MinhaLinguagemVisitor*>(visitor))
    return parserVisitor->visitNew(this);
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
  size_t startState = 20;
  enterRecursionRule(_localctx, 20, MinhaLinguagemParser::RuleExpressao, precedence);

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
    setState(167);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<AtribuicaoContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(130);
      match(MinhaLinguagemParser::IDENTIFICADOR);
      setState(131);
      match(MinhaLinguagemParser::ATRIBUICAO);
      setState(132);
      expressao(15);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<GrupoContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(133);
      match(MinhaLinguagemParser::ABRE_PARENTESES);
      setState(134);
      expressao(0);
      setState(135);
      match(MinhaLinguagemParser::FECHA_PARENTESES);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<ChamadaFuncaoContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(137);
      match(MinhaLinguagemParser::IDENTIFICADOR);
      setState(138);
      match(MinhaLinguagemParser::ABRE_PARENTESES);
      setState(147);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 257698037778) != 0)) {
        setState(139);
        expressao(0);
        setState(144);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == MinhaLinguagemParser::VIRGULA) {
          setState(140);
          match(MinhaLinguagemParser::VIRGULA);
          setState(141);
          expressao(0);
          setState(146);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(149);
      match(MinhaLinguagemParser::FECHA_PARENTESES);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<VariavelContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(150);
      match(MinhaLinguagemParser::IDENTIFICADOR);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<InteiroContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(151);
      match(MinhaLinguagemParser::NUM_INT);
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<FloatContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(152);
      match(MinhaLinguagemParser::NUM_FLOAT);
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<StringContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(153);
      match(MinhaLinguagemParser::TEXTO);
      break;
    }

    case 8: {
      _localctx = _tracker.createInstance<AcessoVetorContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(154);
      match(MinhaLinguagemParser::IDENTIFICADOR);
      setState(155);
      match(MinhaLinguagemParser::ABRE_COLCHETES);
      setState(156);
      expressao(0);
      setState(157);
      match(MinhaLinguagemParser::FECHA_COLCHETES);
      break;
    }

    case 9: {
      _localctx = _tracker.createInstance<NewContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(159);
      match(MinhaLinguagemParser::T__0);
      setState(160);
      tipo();
      setState(165);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
      case 1: {
        setState(161);
        match(MinhaLinguagemParser::ABRE_COLCHETES);
        setState(162);
        expressao(0);
        setState(163);
        match(MinhaLinguagemParser::FECHA_COLCHETES);
        break;
      }

      default:
        break;
      }
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(189);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(187);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<BinariaContext>(_tracker.createInstance<ExpressaoContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpressao);
          setState(169);

          if (!(precpred(_ctx, 14))) throw FailedPredicateException(this, "precpred(_ctx, 14)");
          setState(170);
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
          setState(171);
          expressao(15);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<BinariaContext>(_tracker.createInstance<ExpressaoContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpressao);
          setState(172);

          if (!(precpred(_ctx, 13))) throw FailedPredicateException(this, "precpred(_ctx, 13)");
          setState(173);
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
          setState(174);
          expressao(14);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<BinariaContext>(_tracker.createInstance<ExpressaoContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpressao);
          setState(175);

          if (!(precpred(_ctx, 12))) throw FailedPredicateException(this, "precpred(_ctx, 12)");
          setState(176);
          antlrcpp::downCast<BinariaContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 491520) != 0))) {
            antlrcpp::downCast<BinariaContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(177);
          expressao(13);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<BinariaContext>(_tracker.createInstance<ExpressaoContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpressao);
          setState(178);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(179);
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
          setState(180);
          expressao(12);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<BinariaContext>(_tracker.createInstance<ExpressaoContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpressao);
          setState(181);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(182);
          antlrcpp::downCast<BinariaContext *>(_localctx)->op = match(MinhaLinguagemParser::E_LOGICO);
          setState(183);
          expressao(11);
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<BinariaContext>(_tracker.createInstance<ExpressaoContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpressao);
          setState(184);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(185);
          antlrcpp::downCast<BinariaContext *>(_localctx)->op = match(MinhaLinguagemParser::OU_LOGICO);
          setState(186);
          expressao(10);
          break;
        }

        default:
          break;
        } 
      }
      setState(191);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
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

tree::TerminalNode* MinhaLinguagemParser::TipoContext::INT() {
  return getToken(MinhaLinguagemParser::INT, 0);
}

tree::TerminalNode* MinhaLinguagemParser::TipoContext::ABRE_COLCHETES() {
  return getToken(MinhaLinguagemParser::ABRE_COLCHETES, 0);
}

tree::TerminalNode* MinhaLinguagemParser::TipoContext::FECHA_COLCHETES() {
  return getToken(MinhaLinguagemParser::FECHA_COLCHETES, 0);
}

tree::TerminalNode* MinhaLinguagemParser::TipoContext::FLOAT() {
  return getToken(MinhaLinguagemParser::FLOAT, 0);
}

tree::TerminalNode* MinhaLinguagemParser::TipoContext::CHAR() {
  return getToken(MinhaLinguagemParser::CHAR, 0);
}

tree::TerminalNode* MinhaLinguagemParser::TipoContext::STRING() {
  return getToken(MinhaLinguagemParser::STRING, 0);
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
  enterRule(_localctx, 22, MinhaLinguagemParser::RuleTipo);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(213);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MinhaLinguagemParser::INT: {
        enterOuterAlt(_localctx, 1);
        setState(192);
        match(MinhaLinguagemParser::INT);
        setState(195);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
        case 1: {
          setState(193);
          match(MinhaLinguagemParser::ABRE_COLCHETES);
          setState(194);
          match(MinhaLinguagemParser::FECHA_COLCHETES);
          break;
        }

        default:
          break;
        }
        break;
      }

      case MinhaLinguagemParser::FLOAT: {
        enterOuterAlt(_localctx, 2);
        setState(197);
        match(MinhaLinguagemParser::FLOAT);
        setState(200);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx)) {
        case 1: {
          setState(198);
          match(MinhaLinguagemParser::ABRE_COLCHETES);
          setState(199);
          match(MinhaLinguagemParser::FECHA_COLCHETES);
          break;
        }

        default:
          break;
        }
        break;
      }

      case MinhaLinguagemParser::CHAR: {
        enterOuterAlt(_localctx, 3);
        setState(202);
        match(MinhaLinguagemParser::CHAR);
        setState(205);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx)) {
        case 1: {
          setState(203);
          match(MinhaLinguagemParser::ABRE_COLCHETES);
          setState(204);
          match(MinhaLinguagemParser::FECHA_COLCHETES);
          break;
        }

        default:
          break;
        }
        break;
      }

      case MinhaLinguagemParser::STRING: {
        enterOuterAlt(_localctx, 4);
        setState(207);
        match(MinhaLinguagemParser::STRING);
        setState(210);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx)) {
        case 1: {
          setState(208);
          match(MinhaLinguagemParser::ABRE_COLCHETES);
          setState(209);
          match(MinhaLinguagemParser::FECHA_COLCHETES);
          break;
        }

        default:
          break;
        }
        break;
      }

      case MinhaLinguagemParser::VOID: {
        enterOuterAlt(_localctx, 5);
        setState(212);
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

bool MinhaLinguagemParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 10: return expressaoSempred(antlrcpp::downCast<ExpressaoContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool MinhaLinguagemParser::expressaoSempred(ExpressaoContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 14);
    case 1: return precpred(_ctx, 13);
    case 2: return precpred(_ctx, 12);
    case 3: return precpred(_ctx, 11);
    case 4: return precpred(_ctx, 10);
    case 5: return precpred(_ctx, 9);

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
