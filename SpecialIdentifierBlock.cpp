#include "SpecialIdentifierBlock.h"


// std::unordered_map<std::size_t, SpecialIdentifierType> specialIdentifiersHashes = {
//     {std::hash<std::string>{}("op"), SpecialIdentifierType::Operation},         // Operation
//     {std::hash<std::string>{}("od"), SpecialIdentifierType::OperandOfUnaryOperation},         // OperandOfUnaryOperation
//     {std::hash<std::string>{}("fO"), SpecialIdentifierType::FirstOperandOfBinaryOperation},         // FirstOperandOfBinaryOperation
//     {std::hash<std::string>{}("sO"), SpecialIdentifierType::SecondOperandOfBinaryOperation},         // SecondOperandOfBinaryOperation
//     {std::hash<std::string>{}("abs"), SpecialIdentifierType::Modulus},       // Modulus
//     {std::hash<std::string>{}("sqr"), SpecialIdentifierType::SquareOfNumber},       // SquareOfNumber
//     {std::hash<std::string>{}("sqrt"), SpecialIdentifierType::SquareRootOfNumber},     // SquareRootOfNumber
// };

void SpecialIdentifierBlock::TryChangeIdentifierTypeToSpecial(ComplexToken &token)
{
    std::string value = token.value;
    std::optional<SpecialIdentifierType> identifier = CheckString(value);
    if (identifier.has_value())
        token.type = identifier.value();
}

bool SpecialIdentifierBlock::IsSpecialIdentifier(ComplexToken token)
{
    if (std::get<ComplexTokenType>(token.type) != ComplexTokenType::Identifier)
        return false;

    std::string value = token.value;
    std::optional<SpecialIdentifierType> identifier = CheckString(value);
    if (identifier.has_value())
        return true;
    return false;
}

std::optional<SpecialIdentifierType> SpecialIdentifierBlock::CheckString(std::string str)
{
    std::size_t hash = std::hash<std::string>{}(str);
    if (SpecialIdentifierBlock::specialIdentifiersHashes.count(hash) > 0)
        return specialIdentifiersHashes.at(hash);
    
    return std::nullopt;
}