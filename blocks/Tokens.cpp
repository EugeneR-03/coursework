#include "Tokens.hpp"

template<typename TokenType>
Token<TokenType>::Token(TokenType tokenType, int index) : type(tokenType), index(index) {}

template<typename TokenType>
bool Token<TokenType>::operator==(const Token &token) const
{
    return type == token.type && index == token.index;
}

SimpleToken::SimpleToken(SimpleTokenType tokenType, int index) : Token(tokenType, index) {}

bool SimpleToken::operator==(const SimpleToken &token) const
{
    return type == token.type && index == token.index;
}

ComplexToken::ComplexToken(ComplexTokenType tokenType, const std::string& value, int index) : Token(tokenType, index)
{
    this->value = value;
}

ComplexToken::ComplexToken(SpecialIdentifierType tokenType, const std::string& value, int index) : Token(tokenType, index)
{
    this->value = value;
}

ComplexToken::ComplexToken(const std::variant<ComplexTokenType, SpecialIdentifierType>& tokenType, const std::string& value, int index) : Token(tokenType, index)
{
    this->value = value;
}

bool ComplexToken::operator==(const ComplexToken &token) const
{
    return type == token.type && index == token.index && value == token.value;
}