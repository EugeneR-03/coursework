#include "LexicalBlock.hpp"

// начальное значение
// LexicalBlockState LexicalBlock::state = LexicalBlockState::SPACE;

// std::vector<VariableToken> LexicalBlock::combinedTokenVector;

LexicalBlock::LexicalBlock()
{
    this->state = LexicalBlockState::SPACE;
}

void LexicalBlock::SwitchState(LexicalBlockState newState)
{
    this->state = newState;
}

void LexicalBlock::Process(const VariableToken& token, std::optional<char> symbol = std::nullopt)
{
    // auto buf = combinedTokenVector[combinedTokenVector.size() - 2];
    if (combinedTokenVector.size() > 1)
    {
        // auto buf = combinedTokenVector[combinedTokenVector.size() - 2];
        if (std::holds_alternative<ComplexToken>(combinedTokenVector[combinedTokenVector.size() - 2]))
        {
            SpecialIdentifierBlock specialIdentifierBlock = SpecialIdentifierBlock();
            specialIdentifierBlock.TryChangeIdentifierTypeToSpecial(std::get<ComplexToken>(combinedTokenVector[combinedTokenVector.size() - 2]));
        }
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

void LexicalBlock::StartIdentifier(SimpleToken& token, char symbol)
{
    if (token.type != SimpleTokenType::Letter)
        throw std::invalid_argument("Invalid identifier");

    std::string value = "";
    this->combinedTokenVector.push_back(ComplexToken(ComplexTokenType::Identifier, value, token.index));
    this->Process(token, symbol);
}

void LexicalBlock::StartInteger(SimpleToken& token, char symbol)
{
    if (token.type != SimpleTokenType::Digit)
        throw std::invalid_argument("Invalid integer");

    std::string value = "";
    this->combinedTokenVector.push_back(ComplexToken(ComplexTokenType::Integer, value, token.index));
    this->Process(token, symbol);
}

void LexicalBlock::StartArithmeticSign(SimpleToken& token)
{
    if (token.type != SimpleTokenType::ArithmeticSign)
        throw std::invalid_argument("Invalid arithmetic sign");
    
    this->combinedTokenVector.push_back(token);
    this->Process(token);
}

void LexicalBlock::StartComparisonSign(SimpleToken& token)
{
    if (token.type != SimpleTokenType::ComparisonSign)
        throw std::invalid_argument("Invalid comparison sign");
    
    this->combinedTokenVector.push_back(token);
    this->Process(token);
}

void LexicalBlock::StartLogicalSign(SimpleToken& token)
{
    if (token.type != SimpleTokenType::LogicalSign)
        throw std::invalid_argument("Invalid logical sign");
    
    this->combinedTokenVector.push_back(token);
    this->Process(token);
}

void LexicalBlock::StartEqualSign(SimpleToken& token)
{
    if (token.type != SimpleTokenType::EqualSign)
        throw std::invalid_argument("Invalid equal sign");
    
    this->combinedTokenVector.push_back(token);
    this->Process(token);
}

void LexicalBlock::StartExclamationMark(SimpleToken& token)
{
    if (token.type != SimpleTokenType::ExclamationMark)
        throw std::invalid_argument("Invalid exclamation mark");
    
    this->combinedTokenVector.push_back(token);
    this->Process(token);
}

void LexicalBlock::StartOpeningCurlyBrace(SimpleToken& token)
{
    if (token.type != SimpleTokenType::OpeningCurlyBrace)
        throw std::invalid_argument("Invalid opening curly brace");

    this->combinedTokenVector.push_back(token);
    this->Process(token);
}

void LexicalBlock::StartClosingCurlyBrace(SimpleToken& token)
{
    if (token.type != SimpleTokenType::ClosingCurlyBrace)
        throw std::invalid_argument("Invalid closing curly brace");

    this->combinedTokenVector.push_back(token);
    this->Process(token);
}

void LexicalBlock::StartOpeningParenthesis(SimpleToken& token)
{
    if (token.type != SimpleTokenType::OpeningParenthesis)
        throw std::invalid_argument("Invalid opening parenthesis");

    this->combinedTokenVector.push_back(token);
    this->Process(token);
}

void LexicalBlock::StartClosingParenthesis(SimpleToken& token)
{
    if (token.type != SimpleTokenType::ClosingParenthesis)
        throw std::invalid_argument("Invalid closing parenthesis");
    
    this->combinedTokenVector.push_back(token);
    this->Process(token);
}

void LexicalBlock::StartComma(SimpleToken& token)
{
    if (token.type != SimpleTokenType::Comma)
        throw std::invalid_argument("Invalid comma");
        
    this->combinedTokenVector.push_back(token);
    this->Process(token);
}

void LexicalBlock::StartColon(SimpleToken& token)
{
    if (token.type != SimpleTokenType::Colon)
        throw std::invalid_argument("Invalid colon");
    
    this->combinedTokenVector.push_back(token);
    this->Process(token);
}

void LexicalBlock::StartSemicolon(SimpleToken& token)
{
    if (token.type != SimpleTokenType::Semicolon)
        throw std::invalid_argument("Invalid semicolon");

    this->combinedTokenVector.push_back(token);
    this->Process(token);
}

void LexicalBlock::StartQuotationMark(SimpleToken& token)
{
    if (token.type != SimpleTokenType::QuotationMark)
        throw std::invalid_argument("Invalid quotation mark");

    this->combinedTokenVector.push_back(token);
    this->Process(token);
}

void LexicalBlock::ProcessSymbolInState_SPACE(SimpleToken& token, std::optional<char> symbol = std::nullopt)
{
    switch (token.type)
    {
        case SimpleTokenType::Letter:
            if (!symbol.has_value())
                throw std::invalid_argument("Invalid letter");
            this->StartIdentifier(token, symbol.value());
            this->SwitchState(LexicalBlockState::IDENTIFIER_BEGIN);
            return;
        case SimpleTokenType::Digit:
            if (!symbol.has_value())
                throw std::invalid_argument("Invalid digit");
            this->StartInteger(token, symbol.value());
            this->SwitchState(LexicalBlockState::INTEGER);
            return;
        case SimpleTokenType::OpeningCurlyBrace:
            this->StartOpeningCurlyBrace(token);
            return;
        case SimpleTokenType::ClosingCurlyBrace:
            this->StartClosingCurlyBrace(token);
            return;
        case SimpleTokenType::OpeningParenthesis:
            this->StartOpeningParenthesis(token);
            return;
        case SimpleTokenType::ClosingParenthesis:
            this->StartClosingParenthesis(token);
            return;
        case SimpleTokenType::Comma:
            this->StartComma(token);
            return;
        case SimpleTokenType::Colon:
            this->StartColon(token);
            return;
        case SimpleTokenType::Semicolon:
            this->StartSemicolon(token);
            return;
        case SimpleTokenType::QuotationMark:
            this->StartQuotationMark(token);
            return;
        case SimpleTokenType::EqualSign:
            this->StartEqualSign(token);
            return;
        case SimpleTokenType::ExclamationMark:
            this->StartExclamationMark(token);
            return;
        case SimpleTokenType::ComparisonSign:
            this->StartComparisonSign(token);
            return;
        case SimpleTokenType::ArithmeticSign:
            this->StartArithmeticSign(token);
            return;
        case SimpleTokenType::LogicalSign:
            this->StartLogicalSign(token);
            return;
        case SimpleTokenType::SpaceSign:
            return;
        case SimpleTokenType::Other:
            throw std::invalid_argument("Invalid symbol: '" + std::string(1, symbol.value()) + "', index: " + std::to_string(token.index));
    }
}

void LexicalBlock::ProcessSymbolInState_IDENTIFIER_BEGIN(SimpleToken& token, std::optional<char> symbol = std::nullopt)
{
    switch (token.type)
    {
        case SimpleTokenType::Letter:
            if (!symbol.has_value())
                throw std::invalid_argument("Invalid letter");
            this->Process(token, symbol.value());
            this->SwitchState(LexicalBlockState::IDENTIFIER_BEGIN);
            return;
        case SimpleTokenType::Digit:
            if (!symbol.has_value())
                throw std::invalid_argument("Invalid digit");
            this->Process(token, symbol.value());
            this->SwitchState(LexicalBlockState::IDENTIFIER_END);
            return;
        case SimpleTokenType::OpeningCurlyBrace:
            this->StartOpeningCurlyBrace(token);
            this->SwitchState(LexicalBlockState::SPACE);
            return;
        case SimpleTokenType::ClosingCurlyBrace:
            this->StartClosingCurlyBrace(token);
            this->SwitchState(LexicalBlockState::SPACE);
            return;
        case SimpleTokenType::OpeningParenthesis:
            this->StartOpeningParenthesis(token);
            this->SwitchState(LexicalBlockState::SPACE);
            return;
        case SimpleTokenType::ClosingParenthesis:
            this->StartClosingParenthesis(token);
            this->SwitchState(LexicalBlockState::SPACE);
            return;
        case SimpleTokenType::Comma:
            this->StartComma(token);
            this->SwitchState(LexicalBlockState::SPACE);
            return;
        case SimpleTokenType::Colon:
            this->StartColon(token);
            this->SwitchState(LexicalBlockState::SPACE);
            return;
        case SimpleTokenType::Semicolon:
            this->StartSemicolon(token);
            this->SwitchState(LexicalBlockState::SPACE);
            return;
        case SimpleTokenType::QuotationMark:
            this->StartQuotationMark(token);
            this->SwitchState(LexicalBlockState::SPACE);
            return;
        case SimpleTokenType::EqualSign:
            this->StartEqualSign(token);
            this->SwitchState(LexicalBlockState::SPACE);
            return;
        case SimpleTokenType::ExclamationMark:
            this->StartExclamationMark(token);
            this->SwitchState(LexicalBlockState::SPACE);
            return;
        case SimpleTokenType::ComparisonSign:
            this->StartComparisonSign(token);
            this->SwitchState(LexicalBlockState::SPACE);
            return;
        case SimpleTokenType::ArithmeticSign:
            this->StartArithmeticSign(token);
            this->SwitchState(LexicalBlockState::SPACE);
            return;
        case SimpleTokenType::LogicalSign:
            this->StartLogicalSign(token);
            this->SwitchState(LexicalBlockState::SPACE);
            return;
        case SimpleTokenType::SpaceSign:
        case SimpleTokenType::Other:
            this->SwitchState(LexicalBlockState::SPACE);
            return;
    }
}

void LexicalBlock::ProcessSymbolInState_IDENTIFIER_END(SimpleToken& token, std::optional<char> symbol = std::nullopt)
{
    switch (token.type)
    {
        case SimpleTokenType::Letter:
            if (!symbol.has_value())
                throw std::invalid_argument("Invalid letter");
            this->StartIdentifier(token, symbol.value());
            this->SwitchState(LexicalBlockState::IDENTIFIER_BEGIN);
            return;
        case SimpleTokenType::Digit:
            if (!symbol.has_value())
                throw std::invalid_argument("Invalid digit");
            this->Process(token, symbol.value());
            this->SwitchState(LexicalBlockState::IDENTIFIER_END);
            return;
        case SimpleTokenType::OpeningCurlyBrace:
            this->StartOpeningCurlyBrace(token);
            this->SwitchState(LexicalBlockState::SPACE);
            return;
        case SimpleTokenType::ClosingCurlyBrace:
            this->StartClosingCurlyBrace(token);
            this->SwitchState(LexicalBlockState::SPACE);
            return;
        case SimpleTokenType::OpeningParenthesis:
            this->StartOpeningParenthesis(token);
            this->SwitchState(LexicalBlockState::SPACE);
            return;
        case SimpleTokenType::ClosingParenthesis:
            this->StartClosingParenthesis(token);
            this->SwitchState(LexicalBlockState::SPACE);
            return;
        case SimpleTokenType::Comma:
            this->StartComma(token);
            this->SwitchState(LexicalBlockState::SPACE);
            return;
        case SimpleTokenType::Colon:
            this->StartColon(token);
            this->SwitchState(LexicalBlockState::SPACE);
            return;
        case SimpleTokenType::Semicolon:
            this->StartSemicolon(token);
            this->SwitchState(LexicalBlockState::SPACE);
            return;
        case SimpleTokenType::QuotationMark:
            this->StartQuotationMark(token);
            this->SwitchState(LexicalBlockState::SPACE);
            return;
        case SimpleTokenType::EqualSign:
            this->StartEqualSign(token);
            this->SwitchState(LexicalBlockState::SPACE);
            return;
        case SimpleTokenType::ExclamationMark:
            this->StartExclamationMark(token);
            this->SwitchState(LexicalBlockState::SPACE);
            return;
        case SimpleTokenType::ComparisonSign:
            this->StartComparisonSign(token);
            this->SwitchState(LexicalBlockState::SPACE);
            return;
        case SimpleTokenType::ArithmeticSign:
            this->StartArithmeticSign(token);
            this->SwitchState(LexicalBlockState::SPACE);
            return;
        case SimpleTokenType::LogicalSign:
            this->StartLogicalSign(token);
            this->SwitchState(LexicalBlockState::SPACE);
            return;
        case SimpleTokenType::SpaceSign:
        case SimpleTokenType::Other:
            this->SwitchState(LexicalBlockState::SPACE);
            return;
    }
}

void LexicalBlock::ProcessSymbolInState_INTEGER(SimpleToken& token, std::optional<char> symbol = std::nullopt)
{
    switch (token.type)
    {
        case SimpleTokenType::Letter:
            if (!symbol.has_value())
                throw std::invalid_argument("Invalid letter");
            this->StartIdentifier(token, symbol.value());
            this->SwitchState(LexicalBlockState::IDENTIFIER_BEGIN);
            return;
        case SimpleTokenType::Digit:
            if (!symbol.has_value())
                throw std::invalid_argument("Invalid digit");
            this->Process(token, symbol.value());
            this->SwitchState(LexicalBlockState::INTEGER);
            return;
        case SimpleTokenType::OpeningCurlyBrace:
            this->StartOpeningCurlyBrace(token);
            this->SwitchState(LexicalBlockState::SPACE);
            return;
        case SimpleTokenType::ClosingCurlyBrace:
            this->StartClosingCurlyBrace(token);
            this->SwitchState(LexicalBlockState::SPACE);
            return;
        case SimpleTokenType::OpeningParenthesis:
            this->StartOpeningParenthesis(token);
            this->SwitchState(LexicalBlockState::SPACE);
            return;
        case SimpleTokenType::ClosingParenthesis:
            this->StartClosingParenthesis(token);
            this->SwitchState(LexicalBlockState::SPACE);
            return;
        case SimpleTokenType::Comma:
            this->StartComma(token);
            this->SwitchState(LexicalBlockState::SPACE);
            return;
        case SimpleTokenType::Colon:
            this->StartColon(token);
            this->SwitchState(LexicalBlockState::SPACE);
            return;
        case SimpleTokenType::Semicolon:
            this->StartSemicolon(token);
            this->SwitchState(LexicalBlockState::SPACE);
            return;
        case SimpleTokenType::QuotationMark:
            this->StartQuotationMark(token);
            this->SwitchState(LexicalBlockState::SPACE);
            return;
        case SimpleTokenType::EqualSign:
            this->StartEqualSign(token);
            this->SwitchState(LexicalBlockState::SPACE);
            return;
        case SimpleTokenType::ExclamationMark:
            this->StartExclamationMark(token);
            this->SwitchState(LexicalBlockState::SPACE);
            return;
        case SimpleTokenType::ComparisonSign:
            this->StartComparisonSign(token);
            this->SwitchState(LexicalBlockState::SPACE);
            return;
        case SimpleTokenType::ArithmeticSign:
            this->StartArithmeticSign(token);
            this->SwitchState(LexicalBlockState::SPACE);
            return;
        case SimpleTokenType::LogicalSign:
            this->StartLogicalSign(token);
            this->SwitchState(LexicalBlockState::SPACE);
            return;
        case SimpleTokenType::SpaceSign:
        case SimpleTokenType::Other:
            this->SwitchState(LexicalBlockState::SPACE);
            return;
    }
}

void LexicalBlock::ProcessSymbolDependingOnState(SimpleToken& token, std::optional<char> symbol = std::nullopt)
{
    switch (this->state)
    {
        case LexicalBlockState::SPACE:
            this->ProcessSymbolInState_SPACE(token, symbol);
            break;
        case LexicalBlockState::IDENTIFIER_BEGIN:
            this->ProcessSymbolInState_IDENTIFIER_BEGIN(token, symbol);
            break;
        case LexicalBlockState::IDENTIFIER_END:
            this->ProcessSymbolInState_IDENTIFIER_END(token, symbol);
            break;
        case LexicalBlockState::INTEGER:
            this->ProcessSymbolInState_INTEGER(token, symbol);
            break;
    }
}

std::vector<VariableToken> LexicalBlock::TransliterateString(const std::string& str)
{
    TransliterationBlock transliterationBlock = TransliterationBlock();
    for (int i = 0; i < str.size(); i++)
    {
        char symbol = str[i];
        int index = i;
        SimpleToken token = transliterationBlock.TransliterateSymbol(symbol, index);
        this->ProcessSymbolDependingOnState(token, symbol);
    }
    std::vector<VariableToken> result = this->combinedTokenVector;
    this->combinedTokenVector.clear();
    return result;
}