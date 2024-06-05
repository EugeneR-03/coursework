#pragma once

#include <string>
#include <vector>
#include <variant>
#include <optional>
#include <stdexcept>
#include "./../base-blocks/Tokens.hpp"
#include "TransliterationBlock.hpp"
#include "SpecialIdentifierBlock.hpp"

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
private:
    std::vector<VariableToken> combinedTokenVector;      // итоговый список лексем

    LexicalBlockState state;     // состояние автомата
    void SwitchState(LexicalBlockState newState);

    void Process(const VariableToken& token, std::optional<char> symbol);
    // сложные (составные) лексемы
    void StartIdentifier(SimpleToken& token, char symbol);
    void StartInteger(SimpleToken& token, char symbol);
    // простые (односимвольные) лексемы
    void StartArithmeticSign(SimpleToken& token);
    void StartComparisonSign(SimpleToken& token);
    void StartLogicalSign(SimpleToken& token);
    void StartExclamationMark(SimpleToken& token);
    void StartEqualSign(SimpleToken& token);
    void StartOpeningCurlyBrace(SimpleToken& token);
    void StartClosingCurlyBrace(SimpleToken& token);
    void StartOpeningParenthesis(SimpleToken& token);
    void StartClosingParenthesis(SimpleToken& token);
    void StartComma(SimpleToken& token);
    void StartColon(SimpleToken& token);
    void StartSemicolon(SimpleToken& token);
    void StartQuotationMark(SimpleToken& token);
    
    void ProcessSymbolInState_SPACE(SimpleToken& token, std::optional<char> symbol);
    void ProcessSymbolInState_IDENTIFIER_BEGIN(SimpleToken& token, std::optional<char> symbol);
    void ProcessSymbolInState_IDENTIFIER_END(SimpleToken& token, std::optional<char> symbol);
    void ProcessSymbolInState_INTEGER(SimpleToken& token, std::optional<char> symbol);
    void ProcessSymbolDependingOnState(SimpleToken& token, std::optional<char> symbol);

public:
    LexicalBlock();
    std::vector<VariableToken> TransliterateSimpleTokenVector(std::vector<VariableToken>& tokens);
    std::vector<VariableToken> TransliterateString(const std::string& str);
};