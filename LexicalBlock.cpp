#include "LexicalBlock.h"

// начальное значение
LexicalBlockState LexicalBlock::state = LexicalBlockState::SPACE;

std::vector<VariableToken> LexicalBlock::combinedTokenVector;

void LexicalBlock::SwitchState(LexicalBlockState newState)
{
    LexicalBlock::state = newState;
}

void LexicalBlock::Process(VariableToken token, std::optional<char> symbol = std::nullopt)
{
    if (std::holds_alternative<ComplexToken>(combinedTokenVector[combinedTokenVector.size() - 2]))
    {
        SpecialIdentifierBlock::TryChangeIdentifierTypeToSpecial(std::get<ComplexToken>(combinedTokenVector[combinedTokenVector.size() - 2]));
    }
    if (!symbol.has_value())
        return;

    if (std::holds_alternative<ComplexToken>(combinedTokenVector.back()))
    {
        ComplexToken &token = std::get<ComplexToken>(combinedTokenVector.back());
        token.value += symbol.value();
    }
    
    return;
}

void LexicalBlock::StartIdentifier(SimpleToken token, char symbol)
{
    if (token.type != SimpleTokenType::Letter)
        throw std::invalid_argument("Invalid identifier");

    LexicalBlock::combinedTokenVector.push_back(ComplexToken(ComplexTokenType::Identifier, "", token.index));
    LexicalBlock::Process(token, symbol);
}

void LexicalBlock::StartInteger(SimpleToken token, char symbol)
{
    if (token.type != SimpleTokenType::Digit)
        throw std::invalid_argument("Invalid integer");

    LexicalBlock::combinedTokenVector.push_back(ComplexToken(ComplexTokenType::Integer, "", token.index));
    LexicalBlock::Process(token, symbol);
}

void LexicalBlock::StartArithmeticSign(SimpleToken token)
{
    if (token.type != SimpleTokenType::ArithmeticSign)
        throw std::invalid_argument("Invalid arithmetic sign");
    
    LexicalBlock::combinedTokenVector.push_back(token);
    LexicalBlock::Process(token);
}

void LexicalBlock::StartComparisonSign(SimpleToken token)
{
    if (token.type != SimpleTokenType::ComparisonSign)
        throw std::invalid_argument("Invalid comparison sign");
    
    LexicalBlock::combinedTokenVector.push_back(token);
    LexicalBlock::Process(token);
}

void LexicalBlock::StartLogicalSign(SimpleToken token)
{
    if (token.type != SimpleTokenType::LogicalSign)
        throw std::invalid_argument("Invalid logical sign");
    
    LexicalBlock::combinedTokenVector.push_back(token);
    LexicalBlock::Process(token);
}

void LexicalBlock::StartEqualSign(SimpleToken token)
{
    if (token.type != SimpleTokenType::EqualSign)
        throw std::invalid_argument("Invalid equal sign");
    
    LexicalBlock::combinedTokenVector.push_back(token);
    LexicalBlock::Process(token);
}

void LexicalBlock::StartExclamationMark(SimpleToken token)
{
    if (token.type != SimpleTokenType::ExclamationMark)
        throw std::invalid_argument("Invalid exclamation mark");
    
    LexicalBlock::combinedTokenVector.push_back(token);
    LexicalBlock::Process(token);
}

void LexicalBlock::StartOpeningCurlyBrace(SimpleToken token)
{
    if (token.type != SimpleTokenType::OpeningCurlyBrace)
        throw std::invalid_argument("Invalid opening curly brace");

    LexicalBlock::combinedTokenVector.push_back(token);
    LexicalBlock::Process(token);
}

void LexicalBlock::StartClosingCurlyBrace(SimpleToken token)
{
    if (token.type != SimpleTokenType::ClosingCurlyBrace)
        throw std::invalid_argument("Invalid closing curly brace");

    LexicalBlock::combinedTokenVector.push_back(token);
    LexicalBlock::Process(token);
}

void LexicalBlock::StartOpeningParenthesis(SimpleToken token)
{
    if (token.type != SimpleTokenType::OpeningParenthesis)
        throw std::invalid_argument("Invalid opening parenthesis");

    LexicalBlock::combinedTokenVector.push_back(token);
    LexicalBlock::Process(token);
}

void LexicalBlock::StartClosingParenthesis(SimpleToken token)
{
    if (token.type != SimpleTokenType::ClosingParenthesis)
        throw std::invalid_argument("Invalid closing parenthesis");
    
    LexicalBlock::combinedTokenVector.push_back(token);
    LexicalBlock::Process(token);
}

void LexicalBlock::StartComma(SimpleToken token)
{
    if (token.type != SimpleTokenType::Comma)
        throw std::invalid_argument("Invalid comma");
        
    LexicalBlock::combinedTokenVector.push_back(token);
    LexicalBlock::Process(token);
}

void LexicalBlock::StartColon(SimpleToken token)
{
    if (token.type != SimpleTokenType::Colon)
        throw std::invalid_argument("Invalid colon");
    
    LexicalBlock::combinedTokenVector.push_back(token);
    LexicalBlock::Process(token);
}

void LexicalBlock::StartSemicolon(SimpleToken token)
{
    if (token.type != SimpleTokenType::Semicolon)
        throw std::invalid_argument("Invalid semicolon");

    LexicalBlock::combinedTokenVector.push_back(token);
    LexicalBlock::Process(token);
}

void LexicalBlock::StartQuotationMark(SimpleToken token)
{
    if (token.type != SimpleTokenType::QuotationMark)
        throw std::invalid_argument("Invalid quotation mark");

    LexicalBlock::combinedTokenVector.push_back(token);
    LexicalBlock::Process(token);
}

void LexicalBlock::ProcessSymbolInState_SPACE(SimpleToken token, std::optional<char> symbol = std::nullopt)
{
    switch (token.type)
    {
        case SimpleTokenType::Letter:
            if (!symbol.has_value())
                throw std::invalid_argument("Invalid letter");
            LexicalBlock::StartIdentifier(token, symbol.value());
            LexicalBlock::SwitchState(LexicalBlockState::IDENTIFIER_BEGIN);
            return;
        case SimpleTokenType::Digit:
            if (!symbol.has_value())
                throw std::invalid_argument("Invalid digit");
            LexicalBlock::StartInteger(token, symbol.value());
            LexicalBlock::SwitchState(LexicalBlockState::INTEGER);
            return;
        case SimpleTokenType::OpeningCurlyBrace:
            LexicalBlock::StartOpeningCurlyBrace(token);
            return;
        case SimpleTokenType::ClosingCurlyBrace:
            LexicalBlock::StartClosingCurlyBrace(token);
            return;
        case SimpleTokenType::OpeningParenthesis:
            LexicalBlock::StartOpeningParenthesis(token);
            return;
        case SimpleTokenType::ClosingParenthesis:
            LexicalBlock::StartClosingParenthesis(token);
            return;
        case SimpleTokenType::Comma:
            LexicalBlock::StartComma(token);
            return;
        case SimpleTokenType::Colon:
            LexicalBlock::StartColon(token);
            return;
        case SimpleTokenType::Semicolon:
            LexicalBlock::StartSemicolon(token);
            return;
        case SimpleTokenType::QuotationMark:
            LexicalBlock::StartQuotationMark(token);
            return;
        case SimpleTokenType::EqualSign:
            LexicalBlock::StartEqualSign(token);
            return;
        case SimpleTokenType::ExclamationMark:
            LexicalBlock::StartExclamationMark(token);
            return;
        case SimpleTokenType::ComparisonSign:
            LexicalBlock::StartComparisonSign(token);
            return;
        case SimpleTokenType::ArithmeticSign:
            LexicalBlock::StartArithmeticSign(token);
            return;
        case SimpleTokenType::LogicalSign:
            LexicalBlock::StartLogicalSign(token);
            return;
        case SimpleTokenType::SpaceSign:
        case SimpleTokenType::Other:
            return;
    }
}

void LexicalBlock::ProcessSymbolInState_IDENTIFIER_BEGIN(SimpleToken token, std::optional<char> symbol = std::nullopt)
{
    switch (token.type)
    {
        case SimpleTokenType::Letter:
            if (!symbol.has_value())
                throw std::invalid_argument("Invalid letter");
            LexicalBlock::Process(token, symbol.value());
            LexicalBlock::SwitchState(LexicalBlockState::IDENTIFIER_BEGIN);
            return;
        case SimpleTokenType::Digit:
            if (!symbol.has_value())
                throw std::invalid_argument("Invalid digit");
            LexicalBlock::Process(token, symbol.value());
            LexicalBlock::SwitchState(LexicalBlockState::IDENTIFIER_END);
            return;
        case SimpleTokenType::OpeningCurlyBrace:
            LexicalBlock::StartOpeningCurlyBrace(token);
            LexicalBlock::SwitchState(LexicalBlockState::SPACE);
            return;
        case SimpleTokenType::ClosingCurlyBrace:
            LexicalBlock::StartClosingCurlyBrace(token);
            LexicalBlock::SwitchState(LexicalBlockState::SPACE);
            return;
        case SimpleTokenType::OpeningParenthesis:
            LexicalBlock::StartOpeningParenthesis(token);
            LexicalBlock::SwitchState(LexicalBlockState::SPACE);
            return;
        case SimpleTokenType::ClosingParenthesis:
            LexicalBlock::StartClosingParenthesis(token);
            LexicalBlock::SwitchState(LexicalBlockState::SPACE);
            return;
        case SimpleTokenType::Comma:
            LexicalBlock::StartComma(token);
            LexicalBlock::SwitchState(LexicalBlockState::SPACE);
            return;
        case SimpleTokenType::Colon:
            LexicalBlock::StartColon(token);
            LexicalBlock::SwitchState(LexicalBlockState::SPACE);
            return;
        case SimpleTokenType::Semicolon:
            LexicalBlock::StartSemicolon(token);
            LexicalBlock::SwitchState(LexicalBlockState::SPACE);
            return;
        case SimpleTokenType::QuotationMark:
            LexicalBlock::StartQuotationMark(token);
            LexicalBlock::SwitchState(LexicalBlockState::SPACE);
            return;
        case SimpleTokenType::EqualSign:
            LexicalBlock::StartEqualSign(token);
            LexicalBlock::SwitchState(LexicalBlockState::SPACE);
            return;
        case SimpleTokenType::ExclamationMark:
            LexicalBlock::StartExclamationMark(token);
            LexicalBlock::SwitchState(LexicalBlockState::SPACE);
            return;
        case SimpleTokenType::ComparisonSign:
            LexicalBlock::StartComparisonSign(token);
            LexicalBlock::SwitchState(LexicalBlockState::SPACE);
            return;
        case SimpleTokenType::ArithmeticSign:
            LexicalBlock::StartArithmeticSign(token);
            LexicalBlock::SwitchState(LexicalBlockState::SPACE);
            return;
        case SimpleTokenType::LogicalSign:
            LexicalBlock::StartLogicalSign(token);
            LexicalBlock::SwitchState(LexicalBlockState::SPACE);
            return;
        case SimpleTokenType::SpaceSign:
        case SimpleTokenType::Other:
            LexicalBlock::SwitchState(LexicalBlockState::SPACE);
            return;
    }
}

void LexicalBlock::ProcessSymbolInState_IDENTIFIER_END(SimpleToken token, std::optional<char> symbol = std::nullopt)
{
    switch (token.type)
    {
        case SimpleTokenType::Letter:
            if (!symbol.has_value())
                throw std::invalid_argument("Invalid letter");
            LexicalBlock::StartIdentifier(token, symbol.value());
            LexicalBlock::SwitchState(LexicalBlockState::IDENTIFIER_BEGIN);
            return;
        case SimpleTokenType::Digit:
            if (!symbol.has_value())
                throw std::invalid_argument("Invalid digit");
            LexicalBlock::Process(token, symbol.value());
            LexicalBlock::SwitchState(LexicalBlockState::IDENTIFIER_END);
            return;
        case SimpleTokenType::OpeningCurlyBrace:
            LexicalBlock::StartOpeningCurlyBrace(token);
            LexicalBlock::SwitchState(LexicalBlockState::SPACE);
            return;
        case SimpleTokenType::ClosingCurlyBrace:
            LexicalBlock::StartClosingCurlyBrace(token);
            LexicalBlock::SwitchState(LexicalBlockState::SPACE);
            return;
        case SimpleTokenType::OpeningParenthesis:
            LexicalBlock::StartOpeningParenthesis(token);
            LexicalBlock::SwitchState(LexicalBlockState::SPACE);
            return;
        case SimpleTokenType::ClosingParenthesis:
            LexicalBlock::StartClosingParenthesis(token);
            LexicalBlock::SwitchState(LexicalBlockState::SPACE);
            return;
        case SimpleTokenType::Comma:
            LexicalBlock::StartComma(token);
            LexicalBlock::SwitchState(LexicalBlockState::SPACE);
            return;
        case SimpleTokenType::Colon:
            LexicalBlock::StartColon(token);
            LexicalBlock::SwitchState(LexicalBlockState::SPACE);
            return;
        case SimpleTokenType::Semicolon:
            LexicalBlock::StartSemicolon(token);
            LexicalBlock::SwitchState(LexicalBlockState::SPACE);
            return;
        case SimpleTokenType::QuotationMark:
            LexicalBlock::StartQuotationMark(token);
            LexicalBlock::SwitchState(LexicalBlockState::SPACE);
            return;
        case SimpleTokenType::EqualSign:
            LexicalBlock::StartEqualSign(token);
            LexicalBlock::SwitchState(LexicalBlockState::SPACE);
            return;
        case SimpleTokenType::ExclamationMark:
            LexicalBlock::StartExclamationMark(token);
            LexicalBlock::SwitchState(LexicalBlockState::SPACE);
            return;
        case SimpleTokenType::ComparisonSign:
            LexicalBlock::StartComparisonSign(token);
            LexicalBlock::SwitchState(LexicalBlockState::SPACE);
            return;
        case SimpleTokenType::ArithmeticSign:
            LexicalBlock::StartArithmeticSign(token);
            LexicalBlock::SwitchState(LexicalBlockState::SPACE);
            return;
        case SimpleTokenType::LogicalSign:
            LexicalBlock::StartLogicalSign(token);
            LexicalBlock::SwitchState(LexicalBlockState::SPACE);
            return;
        case SimpleTokenType::SpaceSign:
        case SimpleTokenType::Other:
            LexicalBlock::SwitchState(LexicalBlockState::SPACE);
            return;
    }
}

void LexicalBlock::ProcessSymbolInState_INTEGER(SimpleToken token, std::optional<char> symbol = std::nullopt)
{
    switch (token.type)
    {
        case SimpleTokenType::Letter:
            if (!symbol.has_value())
                throw std::invalid_argument("Invalid letter");
            LexicalBlock::StartIdentifier(token, symbol.value());
            LexicalBlock::SwitchState(LexicalBlockState::IDENTIFIER_BEGIN);
            return;
        case SimpleTokenType::Digit:
            if (!symbol.has_value())
                throw std::invalid_argument("Invalid digit");
            LexicalBlock::Process(token, symbol.value());
            LexicalBlock::SwitchState(LexicalBlockState::INTEGER);
            return;
        case SimpleTokenType::OpeningCurlyBrace:
            LexicalBlock::StartOpeningCurlyBrace(token);
            LexicalBlock::SwitchState(LexicalBlockState::SPACE);
            return;
        case SimpleTokenType::ClosingCurlyBrace:
            LexicalBlock::StartClosingCurlyBrace(token);
            LexicalBlock::SwitchState(LexicalBlockState::SPACE);
            return;
        case SimpleTokenType::OpeningParenthesis:
            LexicalBlock::StartOpeningParenthesis(token);
            LexicalBlock::SwitchState(LexicalBlockState::SPACE);
            return;
        case SimpleTokenType::ClosingParenthesis:
            LexicalBlock::StartClosingParenthesis(token);
            LexicalBlock::SwitchState(LexicalBlockState::SPACE);
            return;
        case SimpleTokenType::Comma:
            LexicalBlock::StartComma(token);
            LexicalBlock::SwitchState(LexicalBlockState::SPACE);
            return;
        case SimpleTokenType::Colon:
            LexicalBlock::StartColon(token);
            LexicalBlock::SwitchState(LexicalBlockState::SPACE);
            return;
        case SimpleTokenType::Semicolon:
            LexicalBlock::StartSemicolon(token);
            LexicalBlock::SwitchState(LexicalBlockState::SPACE);
            return;
        case SimpleTokenType::QuotationMark:
            LexicalBlock::StartQuotationMark(token);
            LexicalBlock::SwitchState(LexicalBlockState::SPACE);
            return;
        case SimpleTokenType::EqualSign:
            LexicalBlock::StartEqualSign(token);
            LexicalBlock::SwitchState(LexicalBlockState::SPACE);
            return;
        case SimpleTokenType::ExclamationMark:
            LexicalBlock::StartExclamationMark(token);
            LexicalBlock::SwitchState(LexicalBlockState::SPACE);
            return;
        case SimpleTokenType::ComparisonSign:
            LexicalBlock::StartComparisonSign(token);
            LexicalBlock::SwitchState(LexicalBlockState::SPACE);
            return;
        case SimpleTokenType::ArithmeticSign:
            LexicalBlock::StartArithmeticSign(token);
            LexicalBlock::SwitchState(LexicalBlockState::SPACE);
            return;
        case SimpleTokenType::LogicalSign:
            LexicalBlock::StartLogicalSign(token);
            LexicalBlock::SwitchState(LexicalBlockState::SPACE);
            return;
        case SimpleTokenType::SpaceSign:
        case SimpleTokenType::Other:
            LexicalBlock::SwitchState(LexicalBlockState::SPACE);
            return;
    }
}

void LexicalBlock::ProcessSymbolDependingOnState(SimpleToken token, std::optional<char> symbol = std::nullopt)
{
    switch (LexicalBlock::state)
    {
        case LexicalBlockState::SPACE:
            LexicalBlock::ProcessSymbolInState_SPACE(token, symbol);
            break;
        case LexicalBlockState::IDENTIFIER_BEGIN:
            LexicalBlock::ProcessSymbolInState_IDENTIFIER_BEGIN(token, symbol);
            break;
        case LexicalBlockState::IDENTIFIER_END:
            LexicalBlock::ProcessSymbolInState_IDENTIFIER_END(token, symbol);
            break;
        case LexicalBlockState::INTEGER:
            LexicalBlock::ProcessSymbolInState_INTEGER(token, symbol);
            break;
    }
}

std::vector<VariableToken> LexicalBlock::TransliterateString(std::string str)
{
    for (int i = 0; i < str.size(); i++)
    {
        char symbol = str[i];
        int index = i;
        SimpleToken token = TransliterationBlock::TransliterateSymbol(symbol, index);
        LexicalBlock::ProcessSymbolDependingOnState(token, symbol);
    }
    std::vector<VariableToken> result = LexicalBlock::combinedTokenVector;
    LexicalBlock::combinedTokenVector.clear();
    return result;
}