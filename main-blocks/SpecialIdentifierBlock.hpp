#pragma once

#include <string>
#include <unordered_map>
#include "./../base-blocks/Tokens.hpp"
#include "LexicalBlock.hpp"

class SpecialIdentifierBlock
{
private:
    static std::unordered_map<std::size_t, SpecialIdentifierType> specialIdentifiersHashes;
    std::optional<SpecialIdentifierType> CheckString(const std::string& str);
public:
    SpecialIdentifierBlock();
    ~SpecialIdentifierBlock();
    void TryChangeIdentifierTypeToSpecial(ComplexToken& token);
    bool IsSpecialIdentifier(const ComplexToken& token);
};