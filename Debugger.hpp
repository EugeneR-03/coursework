#pragma once

#include <fstream>
#include <string>
#include <vector>
#include <map>
#include "./blocks/Tokens.hpp"
#include "./blocks/Messages.hpp"

using VariableToken = std::variant<SimpleToken, ComplexToken>;

enum class DebuggerWorkingMode
{
    None,
    Normal,
    Verbose
};

class Debugger
{
    static const char* tokenTypes[];
    static const char* complexTokenTypes[];
    static const char* specialIdentifierTypes[];
public:
    static void AddMessageToVector(Message message, std::vector<std::vector<Message>>& messages);
    static void PrintMessage(std::ofstream& file, Message message);
    static void PrintMessagesAndResults(std::ofstream& file, std::vector<std::vector<Message>> messages, std::vector<bool> results);
    static void PrintTokens(std::ofstream& file, std::string targetString, std::vector<VariableToken> combinedTokens);
};