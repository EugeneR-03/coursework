#include "Tokens.h"

SimpleToken::SimpleToken(SimpleTokenType tokenType, int index = 0)
{
    this->type = tokenType;
    this->index = index;
}

ComplexToken::ComplexToken(ComplexTokenType tokenType, std::string value, int index = -1)
{
    this->type = tokenType;
    this->value = value;
    this->index = index;
}