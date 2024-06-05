#include "Debugger.hpp"

const char* Debugger::tokenTypes[] = {
    "Letter", 
    "Digit", 
    "OpeningCurlyBrace", 
    "ClosingCurlyBrace", 
    "OpeningParenthesis", 
    "ClosingParenthesis", 
    "Comma", 
    "Colon", 
    "Semicolon", 
    "QuotationMark", 
    "EqualSign", 
    "ComparisonSign", 
    "ExclamationMark", 
    "ArithmeticSign", 
    "LogicalSign", 
    "SpaceSign", 
    "Other",
};

const char* Debugger::complexTokenTypes[] = {
    "Identifier",             // идентификатор
    "Integer",                // целое число
};

const char* Debugger::specialIdentifierTypes[] = {
    "Operation",
    "OperandOfUnaryOperation",
    "FirstOperandOfBinaryOperation",
    "SecondOperandOfBinaryOperation",
    "V",
    "No",
    "Real",
    "Solution",
    "Modulus",
    "SquareOfNumber",
    "SquareRootOfNumber",
};

Debugger::Debugger()
{
    omp_init_lock(&lock);
}

void Debugger::AddMessageToVector(const Message& message, std::vector<std::set<Message>>& messages)
{
    omp_set_lock(&lock);
    messages[message.stringIndex].insert(message);
    omp_unset_lock(&lock);
}

void Debugger::PrintMessage(std::ofstream& file, const Message& message)
{
    file << MessagePool::GetMessage("Other", "Position") << ": " << message.tokenIndex << "\t" << message.tokenValue << "\t" << message.message << std::endl;
}

void Debugger::PrintMessagesAndResults(std::ofstream& file, std::vector<std::set<Message>>& messages, const std::vector<bool>& results)
{
    for (int i = 0; i < messages.size(); i++)
    {
        file << MessagePool::GetMessage("Other", "String") << ": " << i+1 << std::endl;
        for (auto it = messages[i].begin(); it != messages[i].end(); it++)
        {
            file << "\t";
            PrintMessage(file, *it);
        }
        if (results[i])
        {
            file << "\t" << MessagePool::GetMessage("Other", "Result") << ": " << MessagePool::GetMessage("Other", "Success") << std::endl;
        }
        else
        {
            file << "\t" << MessagePool::GetMessage("Other", "Result") << ": " << MessagePool::GetMessage("Other", "Fail") << std::endl;
        }
        if (i != messages.size() - 1)
        {
            file << std::endl;
        }
    }
}

void Debugger::PrintTokens(std::ofstream& file, const std::string& targetString, const std::vector<VariableToken>& combinedTokens)
{
    for (int i = 0; i < combinedTokens.size(); i++) {
        std::variant<SimpleToken, ComplexToken> combinedToken = combinedTokens[i];
        if (std::holds_alternative<SimpleToken>(combinedToken)) {
            SimpleToken token = std::get<SimpleToken>(combinedToken);
            char symbol = targetString[token.index];
            file << symbol << '\t' << token.index << "\t" << tokenTypes[static_cast<std::underlying_type<SimpleTokenType>::type>(token.type)] << std::endl;
        }
        else {
            ComplexToken token = std::get<ComplexToken>(combinedToken);
            std::string bufStr = targetString.substr(token.index, token.value.length());
            if (std::holds_alternative<ComplexTokenType>(token.type)) {
                file << bufStr << '\t' << token.index << "\t" << complexTokenTypes[static_cast<std::underlying_type<ComplexTokenType>::type>(std::get<ComplexTokenType>(token.type))] << std::endl;
            }
            else if (std::holds_alternative<SpecialIdentifierType>(token.type)) {
                file << bufStr << '\t' << token.index << "\t" << specialIdentifierTypes[static_cast<std::underlying_type<SpecialIdentifierType>::type>(std::get<SpecialIdentifierType>(token.type))] << std::endl;
            }
        }
    }
}