#ifndef TRANSLITERATIONBLOCK_H
#define TRANSLITERATIONBLOCK_H

#include <string>
#include <vector>
#include "Tokens.h"

class TransliterationBlock
{
public:
    static SimpleToken TransliterateSymbol(char symbol, int index);
    static std::vector<SimpleToken> TransliterateString(std::string str);
};


#endif