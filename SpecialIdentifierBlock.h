#ifndef SPECIALIDENTIFIERBLOCK_H
#define SPECIALIDENTIFIERBLOCK_H

#include <string>
#include <unordered_map>
#include "Tokens.h"
#include "LexicalBlock.h"

class SpecialIdentifierBlock
{
public:
    static void TryChangeIdentifierTypeToSpecial(ComplexToken &token);
    static bool IsSpecialIdentifier(ComplexToken token);
private:
    // static std::unordered_map<std::size_t, SpecialIdentifierType> specialIdentifiersHashes;
    static inline std::unordered_map<std::size_t, SpecialIdentifierType> specialIdentifiersHashes = {
        {std::hash<std::string>{}("op"), SpecialIdentifierType::Operation},         // Operation
        {std::hash<std::string>{}("od"), SpecialIdentifierType::OperandOfUnaryOperation},         // OperandOfUnaryOperation
        {std::hash<std::string>{}("fO"), SpecialIdentifierType::FirstOperandOfBinaryOperation},         // FirstOperandOfBinaryOperation
        {std::hash<std::string>{}("sO"), SpecialIdentifierType::SecondOperandOfBinaryOperation},         // SecondOperandOfBinaryOperation
        {std::hash<std::string>{}("abs"), SpecialIdentifierType::Modulus},       // Modulus
        {std::hash<std::string>{}("sqr"), SpecialIdentifierType::SquareOfNumber},       // SquareOfNumber
        {std::hash<std::string>{}("sqrt"), SpecialIdentifierType::SquareRootOfNumber},     // SquareRootOfNumber
    };
    static std::optional<SpecialIdentifierType> CheckString(std::string str);
};

#endif