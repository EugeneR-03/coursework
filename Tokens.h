#ifndef TOKENS_H
#define TOKENS_H

#include <string>
#include <variant>
#include "TokenTypes.h"

struct SimpleToken
{
    SimpleTokenType type;
    int index;

    SimpleToken(SimpleTokenType tokenType, int index);
};

struct ComplexToken
{
    std::variant<ComplexTokenType, SpecialIdentifierType> type;
    std::string value;
    int index;

    ComplexToken(ComplexTokenType tokenType, std::string value, int index);
};

#endif