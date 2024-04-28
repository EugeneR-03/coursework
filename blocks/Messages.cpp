#include "Messages.hpp"

// Message

int Message::currentId = 0;

Message::Message()
{
    this->id = ++currentId;
    this->stringIndex = -1;
    this->tokenIndex = -1;
    this->tokenValue = "";
    this->message = "";
}

Message::Message(int stringIndex, int tokenIndex, const std::string& message)
{
    this->id = ++currentId;
    this->stringIndex = stringIndex;
    this->tokenIndex = tokenIndex;
    this->tokenValue = "";
    this->message = message;
}

Message::Message(int stringIndex, int tokenIndex, const std::string& tokenValue, const std::string& message)
{
    this->id = ++currentId;
    this->stringIndex = stringIndex;
    this->tokenIndex = tokenIndex;
    this->tokenValue = tokenValue;
    this->message = message;
}

bool Message::operator<(const Message& other) const
{
    return id < other.id;
}

bool Message::operator>(const Message& other) const
{
    return id > other.id;
}

bool Message::operator==(const Message& other) const
{
    return id == other.id;
}

// MessagePool



std::map<std::string, std::string> MessagePool::Symbol
{
    {"OpeningCurlyBrace", "Error: OpeningCurlyBrace"},
    {"ClosingCurlyBrace", "Error: ClosingCurlyBrace"},
    {"OpeningParenthesis", "Error: OpeningParenthesis"},
    {"ClosingParenthesis", "Error: ClosingParenthesis"},
    {"Comma", "Error: Comma"},
    {"Colon", "Error: Colon"},
    {"Semicolon", "Error: Semicolon"},
    {"QuotationMark", "Error: QuotationMark"},
    {"EqualSign", "Error: EqualSign"},
    {"ComparisonSign", "Error: ComparisonSign"},
    {"ExclamationMark", "Error: ExclamationMark"},
    {"ArithmeticSign", "Error: ArithmeticSign"},
    {"LogicalSign", "Error: LogicalSign"},
};

std::map<std::string, std::string> MessagePool::SpecialIdentifier
{
    {"Operation", "Error: SpecialIdentifier::Operation"},
    {"OperandOfUnaryOperation", "Error: SpecialIdentifier::OperandOfUnaryOperation"},
    {"FirstOperandOfBinaryOperation", "Error: SpecialIdentifier::FirstOperandOfBinaryOperation"},
    {"SecondOperandOfBinaryOperation", "Error: SpecialIdentifier::SecondOperandOfBinaryOperation"},
    {"V", "Error: SpecialIdentifier::V"},
    {"No", "Error: SpecialIdentifier::No"},
    {"Real", "Error: SpecialIdentifier::Real"},
    {"Solution", "Error: SpecialIdentifier::Solution"},
    {"Modulus", "Error: SpecialIdentifier::Modulus"},
    {"SquareOfNumber", "Error: SpecialIdentifier::SquareOfNumber"},
    {"SquareRootOfNumber", "Error: SpecialIdentifier::SquareRootOfNumber"},
};

std::map<std::string, std::string> MessagePool::Variable
{
    {"Edge", "Error: Variable::Edge"},
    {"Identifier", "Error: Variable::Identifier"},
    {"Integer", "Error: Variable::Integer"},
    {"Variable", "Error: Variable::Variable"},
};

std::map<std::string, std::string> MessagePool::Operation
{
    {"Logical", "Error: Operation::Logical"},
    {"Arithmetic", "Error: Operation::Arithmetic"},
    {"Operation", "Error: Operation::Operation"},
};

std::map<std::string, std::string> MessagePool::String
{
    {"String", "Error: String"},
    {"Beginning", "Error: String::Beginning"},
    {"Logical", "Error: String::Logical"},
    {"Arithmetic", "Error: String::Arithmetic"},
    {"ArithmeticNoRealSolution", "Error: String::ArithmeticNoRealSolution"},
};

std::map<std::string, std::string> MessagePool::StringInner
{
    {"Operation", "Error: String::Inner::Operation"},
    {"FirstOperandOfBinaryOperation", "Error: String::Inner::FirstOperandOfBinaryOperation"},
    {"SecondOperandOfBinaryOperation", "Error: String::Inner::SecondOperandOfBinaryOperation"},
    {"OperandBinary", "Error: String::Inner::Binary"},
    {"OperandUnary", "Error: String::Inner::Unary"},
    {"OperandVariable", "Error: String::Inner::Variable"},
    {"Operand", "Error: String::Inner::Operand"},
    {"Inner", "Error: String::Inner"},
};