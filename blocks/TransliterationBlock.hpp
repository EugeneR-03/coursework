#pragma once

#include <string>
#include <vector>
#include "Tokens.hpp"

class TransliterationBlock
{
public:
    static SimpleToken TransliterateSymbol(char symbol, int index);
    static std::vector<SimpleToken> TransliterateString(std::string str);
};