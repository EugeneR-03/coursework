#pragma once

#include <string>
#include <vector>
#include "./../base-blocks/Tokens.hpp"

class TransliterationBlock
{
public:
    TransliterationBlock();
    SimpleToken TransliterateSymbol(char symbol, int index);
    std::vector<SimpleToken> TransliterateString(const std::string& str);
};