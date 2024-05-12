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

// omp_lock_t Debugger::lock;

Debugger::Debugger()
{
    omp_init_lock(&lock);
}

void Debugger::AddMessageToVector(const Message& message, std::vector<std::set<Message>>& messages)
{
    // #pragma omp critical
    // {
    omp_set_lock(&lock);
    // lock.lock();
    // printf("String number %d\n", message.stringIndex);
    messages[message.stringIndex].insert(message);
    omp_unset_lock(&lock);
    // lock.unlock();
    // }
}

void Debugger::PrintMessage(std::ofstream& file, const Message& message)
{
    file << "Index: " << message.tokenIndex << "\t" << message.tokenValue << "\t" << message.message << std::endl;
}

void Debugger::PrintMessagesAndResults(std::ofstream& file, std::vector<std::set<Message>>& messages, const std::vector<bool>& results)
{
    for (int i = 0; i < messages.size(); i++)
    {
        file << "String: " << i+1 << std::endl;
        // for (int j = 0; j < messages[i].size(); j++)
        // {
        //     file << "\t";
        //     PrintMessage(file, messages[i][j]);
        // }
        for (auto it = messages[i].begin(); it != messages[i].end(); it++)
        {
            file << "\t";
            PrintMessage(file, *it);
        }
        if (results[i])
        {
            file << "\tResult: true" << std::endl;
        }
        else
        {
            file << "\tResult: false" << std::endl;
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