#pragma once

#include <string>
#include <unordered_map>
#include "Tokens.hpp"
#include "LexicalBlock.hpp"

class SpecialIdentifierBlock
{
public:
    static void TryChangeIdentifierTypeToSpecial(ComplexToken &token);
    static bool IsSpecialIdentifier(ComplexToken token);
private:
    static std::unordered_map<std::size_t, SpecialIdentifierType> specialIdentifiersHashes;
    static std::optional<SpecialIdentifierType> CheckString(std::string str);
};