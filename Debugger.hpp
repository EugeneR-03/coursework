#pragma once

#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include "./blocks/Tokens.hpp"
#include "./blocks/Messages.hpp"

#include <mutex>
#include <omp.h>

using VariableToken = std::variant<SimpleToken, ComplexToken>;

struct CompareStruct
{
    bool operator()(const Message& lhs, const Message& rhs) const
    {
        return lhs.tokenIndex < rhs.tokenIndex;
    }
};

enum class DebuggerWorkingMode
{
    None,
    Normal,
    Verbose
};

class Debugger
{
    omp_lock_t lock;
    static const char* tokenTypes[];
    static const char* complexTokenTypes[];
    static const char* specialIdentifierTypes[];
public:
    Debugger();
    void AddMessageToVector(const Message& message, std::vector<std::set<Message>>& messages);
    void PrintMessage(std::ofstream& file, const Message& message);
    void PrintMessagesAndResults(std::ofstream& file, std::vector<std::set<Message>>& messages, const std::vector<bool>& results);
    void PrintTokens(std::ofstream& file, const std::string& targetString, const std::vector<VariableToken>& combinedTokens);
};