#pragma once

#include <string>
#include <map>

struct Message
{
    int id;
    int stringIndex;
    int tokenIndex;
    std::string tokenValue = "";
    std::string message;
    static int currentId;

    Message();
    Message(int stringIndex, int tokenIndex, std::string message);
    Message(int stringIndex, int tokenIndex, std::string tokenValue, std::string message);

    bool operator<(const Message& other) const;
    bool operator>(const Message& other) const;
    bool operator==(const Message& other) const;
};

struct MessagePool
{
    static std::map<std::string, std::string> Symbol;
    static std::map<std::string, std::string> SpecialIdentifier;
    static std::map<std::string, std::string> Variable;
    static std::map<std::string, std::string> Operation;
    static std::map<std::string, std::string> String;
    static std::map<std::string, std::string> StringInner;
};