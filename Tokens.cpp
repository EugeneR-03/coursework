#include "Tokens.h"

template<typename TokenType>
Token<TokenType>::Token(TokenType tokenType, int index) : type(tokenType), index(index) {}

SimpleToken::SimpleToken(SimpleTokenType tokenType, int index = 0) : Token(tokenType, index) {}

ComplexToken::ComplexToken(std::variant<ComplexTokenType, SpecialIdentifierType> tokenType, std::string value, int index = -1) : Token(tokenType, index), value(value) {}