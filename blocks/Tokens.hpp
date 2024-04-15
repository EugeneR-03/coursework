#pragma once

#include <string>
#include <variant>
#include "TokenTypes.hpp"

template <typename TokenType>
struct Token
{
    TokenType type;
    int index;

    Token(TokenType tokenType, int index);
    virtual bool operator==(const Token &token) const;
};

struct SimpleToken : Token<SimpleTokenType>
{
    SimpleToken(SimpleTokenType tokenType, int index = 0);
    bool operator==(const SimpleToken &token) const;
};

struct ComplexToken : Token<std::variant<ComplexTokenType, SpecialIdentifierType>>
{
    std::string value;

    ComplexToken(ComplexTokenType tokenType, std::string value, int index = -1);
    ComplexToken(SpecialIdentifierType tokenType, std::string value, int index = -1);
    ComplexToken(std::variant<ComplexTokenType, SpecialIdentifierType> tokenType, std::string value, int index = -1);
    bool operator==(const ComplexToken &token) const;
};