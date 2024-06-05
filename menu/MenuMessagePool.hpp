#pragma once

#include <string>
#include <map>

#include "./../utils/Language.hpp"

struct MenuMessagePool
{
private:
    static std::map<std::string, std::string>* other;
    static std::map<std::string, std::string>* mainMenu;
    static std::map<std::string, std::string>* optionsMenu;
    static std::map<std::string, std::string>* workModeMenu;
    static std::map<std::string, std::string>* choosingFileMenu;
    static std::map<std::string, std::string>* choosingLanguageMenu;

public:
    static Language language;    

    static void SwitchPoolToLanguage(Language language);

    static std::string GetMenuMessage(std::string menuType, std::string message);
};

struct MenuMessagePoolEng
{
    static std::map<std::string, std::string> other;
    static std::map<std::string, std::string> mainMenu;
    static std::map<std::string, std::string> optionsMenu;
    static std::map<std::string, std::string> workModeMenu;
    static std::map<std::string, std::string> choosingFileMenu;
    static std::map<std::string, std::string> choosingLanguageMenu;
};

struct MenuMessagePoolRus
{
    static std::map<std::string, std::string> other;
    static std::map<std::string, std::string> mainMenu;
    static std::map<std::string, std::string> optionsMenu;
    static std::map<std::string, std::string> workModeMenu;
    static std::map<std::string, std::string> choosingFileMenu;
    static std::map<std::string, std::string> choosingLanguageMenu;
};