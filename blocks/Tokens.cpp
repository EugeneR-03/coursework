#include "Tokens.hpp"

template<typename TokenType>
Token<TokenType>::Token(TokenType tokenType, int index) : type(tokenType), index(index) {}

template<typename TokenType>
bool Token<TokenType>::operator==(const Token &token) const
{
    return type == token.type && index == token.index;
}

SimpleToken::SimpleToken(SimpleTokenType tokenType, int index = 0) : Token(tokenType, index) {}

bool SimpleToken::operator==(const SimpleToken &token) const
{
    return type == token.type && index == token.index;
}

ComplexToken::ComplexToken(ComplexTokenType tokenType, std::string value, int index = -1) : Token(tokenType, index), value(value) {}

ComplexToken::ComplexToken(SpecialIdentifierType tokenType, std::string value, int index = -1) : Token(tokenType, index), value(value) {}

ComplexToken::ComplexToken(std::variant<ComplexTokenType, SpecialIdentifierType> tokenType, std::string value, int index = -1) : Token(tokenType, index), value(value) {}

bool ComplexToken::operator==(const ComplexToken &token) const
{
    return type == token.type && index == token.index && value == token.value;
}