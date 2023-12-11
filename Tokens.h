#pragma once

#include <string>
#include <variant>
#include "TokenTypes.h"

template <typename TokenType>
struct Token
{
    TokenType type;
    int index;

    Token(TokenType tokenType, int index);
};

struct SimpleToken : Token<SimpleTokenType>
{
    SimpleToken(SimpleTokenType tokenType, int index);
};

struct ComplexToken : Token<std::variant<ComplexTokenType, SpecialIdentifierType>>
{
    std::string value;

    ComplexToken(std::variant<ComplexTokenType, SpecialIdentifierType> tokenType, std::string value, int index);
};