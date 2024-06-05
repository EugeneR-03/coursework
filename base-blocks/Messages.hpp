#pragma once

#include <string>
#include <map>

#include "./../utils/Language.hpp"

struct Message
{
    int stringIndex;
    int tokenIndex;
    std::string tokenValue = "";
    std::string message = "";

    Message();
    Message(int stringIndex, int tokenIndex, const std::string& message);
    Message(int stringIndex, int tokenIndex, const std::string& tokenValue, const std::string& message);

    bool operator<(const Message& other) const;
    bool operator>(const Message& other) const;
    bool operator==(const Message& other) const;
};

struct MessagePool
{
private:
    static std::map<std::string, std::string>* other;
    static std::map<std::string, std::string>* symbol;
    static std::map<std::string, std::string>* specialIdentifier;
    static std::map<std::string, std::string>* variable;
    static std::map<std::string, std::string>* operation;
    static std::map<std::string, std::string>* string;
    static std::map<std::string, std::string>* stringInner;

public:
    static Language language;    

    static std::string GetMessage(std::string poolType, std::string message);
    static void SwitchPoolToLanguage(Language language);
};

struct MessagePoolEng
{
    static std::map<std::string, std::string> other;
    static std::map<std::string, std::string> symbol;
    static std::map<std::string, std::string> specialIdentifier;
    static std::map<std::string, std::string> variable;
    static std::map<std::string, std::string> operation;
    static std::map<std::string, std::string> string;
    static std::map<std::string, std::string> stringInner;
};

struct MessagePoolRus
{
    static std::map<std::string, std::string> other;
    static std::map<std::string, std::string> symbol;
    static std::map<std::string, std::string> specialIdentifier;
    static std::map<std::string, std::string> variable;
    static std::map<std::string, std::string> operation;
    static std::map<std::string, std::string> string;
    static std::map<std::string, std::string> stringInner;
};