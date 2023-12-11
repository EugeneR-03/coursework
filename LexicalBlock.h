#pragma once

#include <string>
#include <vector>
#include <variant>
#include <optional>
#include <stdexcept>
#include "Tokens.h"
#include "TransliterationBlock.h"
#include "SpecialIdentifierBlock.h"

using VariableToken = std::variant<SimpleToken, ComplexToken>;

enum class LexicalBlockState
{
    SPACE,
    IDENTIFIER_BEGIN,
    IDENTIFIER_END,
    INTEGER,
};

// класс реализует алгоритм работы ДКА
class LexicalBlock
{
public:
    static std::vector<VariableToken> TransliterateSimpleTokenVector(std::vector<VariableToken> tokens);
    static std::vector<VariableToken> TransliterateString(std::string str);
private:
    static std::vector<VariableToken> combinedTokenVector;      // итоговый список лексем

    static LexicalBlockState state;     // состояние автомата
    static void SwitchState(LexicalBlockState newState);

    static void Process(VariableToken token, std::optional<char> symbol);
    // сложные (составные) лексемы
    static void StartIdentifier(SimpleToken token, char symbol);
    static void StartInteger(SimpleToken token, char symbol);
    // простые (односимвольные) лексемы
    static void StartArithmeticSign(SimpleToken token);
    static void StartComparisonSign(SimpleToken token);
    static void StartLogicalSign(SimpleToken token);
    static void StartExclamationMark(SimpleToken token);
    static void StartEqualSign(SimpleToken token);
    static void StartOpeningCurlyBrace(SimpleToken token);
    static void StartClosingCurlyBrace(SimpleToken token);
    static void StartOpeningParenthesis(SimpleToken token);
    static void StartClosingParenthesis(SimpleToken token);
    static void StartComma(SimpleToken token);
    static void StartColon(SimpleToken token);
    static void StartSemicolon(SimpleToken token);
    static void StartQuotationMark(SimpleToken token);
    
    static void ProcessSymbolInState_SPACE(SimpleToken token, std::optional<char> symbol);
    static void ProcessSymbolInState_IDENTIFIER_BEGIN(SimpleToken token, std::optional<char> symbol);
    static void ProcessSymbolInState_IDENTIFIER_END(SimpleToken token, std::optional<char> symbol);
    static void ProcessSymbolInState_INTEGER(SimpleToken token, std::optional<char> symbol);
    static void ProcessSymbolDependingOnState(SimpleToken token, std::optional<char> symbol);
};