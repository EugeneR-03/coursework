#include "MenuMessagePool.hpp"

// MenuMessagePool

// инициализация по умолчанию
Language MenuMessagePool::language = Language::Russian;
std::map<std::string, std::string>* MenuMessagePool::other = &MenuMessagePoolRus::other;
std::map<std::string, std::string>* MenuMessagePool::mainMenu = &MenuMessagePoolRus::mainMenu;
std::map<std::string, std::string>* MenuMessagePool::optionsMenu = &MenuMessagePoolRus::optionsMenu;
std::map<std::string, std::string>* MenuMessagePool::workModeMenu = &MenuMessagePoolRus::workModeMenu;
std::map<std::string, std::string>* MenuMessagePool::choosingFileMenu = &MenuMessagePoolRus::choosingFileMenu;
std::map<std::string, std::string>* MenuMessagePool::choosingLanguageMenu = &MenuMessagePoolRus::choosingLanguageMenu;

void MenuMessagePool::SwitchPoolToLanguage(Language language)
{
    switch (language)
    {
        case Language::English:
            MenuMessagePool::other = &MenuMessagePoolEng::other;
            MenuMessagePool::mainMenu = &MenuMessagePoolEng::mainMenu;
            MenuMessagePool::optionsMenu = &MenuMessagePoolEng::optionsMenu;
            MenuMessagePool::workModeMenu = &MenuMessagePoolEng::workModeMenu;
            MenuMessagePool::choosingFileMenu = &MenuMessagePoolEng::choosingFileMenu;
            MenuMessagePool::choosingLanguageMenu = &MenuMessagePoolEng::choosingLanguageMenu;
            break;
        case Language::Russian:
            MenuMessagePool::other = &MenuMessagePoolRus::other;
            MenuMessagePool::mainMenu = &MenuMessagePoolRus::mainMenu;
            MenuMessagePool::optionsMenu = &MenuMessagePoolRus::optionsMenu;
            MenuMessagePool::workModeMenu = &MenuMessagePoolRus::workModeMenu;
            MenuMessagePool::choosingFileMenu = &MenuMessagePoolRus::choosingFileMenu;
            MenuMessagePool::choosingLanguageMenu = &MenuMessagePoolRus::choosingLanguageMenu;
            break;
    }
}

std::string MenuMessagePool::GetMenuMessage(std::string menuType, std::string message)
{
    if (menuType == "Other")
    {
        return (*MenuMessagePool::other)[message];
    }
    else if (menuType == "MainMenu")
    {
        return (*MenuMessagePool::mainMenu)[message];
    }
    else if (menuType == "OptionsMenu")
    {
        return (*MenuMessagePool::optionsMenu)[message];
    }
    else if (menuType == "WorkModeMenu")
    {
        return (*MenuMessagePool::workModeMenu)[message];
    }
    else if (menuType == "ChoosingFileMenu")
    {
        return (*MenuMessagePool::choosingFileMenu)[message];
    }
    else if (menuType == "ChoosingLanguageMenu")
    {
        return (*MenuMessagePool::choosingLanguageMenu)[message];
    }

    return "";
}

// MenuMessagePoolEng

std::map<std::string, std::string> MenuMessagePoolEng::other
{
    {"Error", "Error"},
    {"Success", "Success"},
    {"Running", "The program is running"},
    {"None", "None"},
};

std::map<std::string, std::string> MenuMessagePoolEng::mainMenu
{
    {"Start", "Start the program"},
    {"Options", "Options"},
    {"Exit", "Exit"},
};

std::map<std::string, std::string> MenuMessagePoolEng::optionsMenu
{
    {"Settings", "Settings:"},
    {"ChangeInputFilePath", "Change the path to the input file"},
    {"ChangeOutputFilePath", "Change the path to the output file"},
    {"ChangeWorkMode", "Change the work mode"},
    {"ChangeLanguage", "Change the language"},
    {"Exit", "Exit"},
};

std::map<std::string, std::string> MenuMessagePoolEng::workModeMenu
{
    {"CurrentWorkMode", "Current work mode:"},
    {"UntilFirstError", "Check until the first error"},
    {"AllErrors", "Check all errors with considering nesting level"},
    {"AllErrorsWithoutInner", "Check all errors without considering nesting level"},
};

std::map<std::string, std::string> MenuMessagePoolEng::choosingFileMenu
{
    {"SelectionMode", "File selection mode:"},
    {"Manually", "Manually"},
    {"FromFolder", "From folder"},
    {"InputFileName", "Enter the name of the input file:"},
    {"OutputFileName", "Enter the name of the output file:"},
    {"CurrentInputFile", "Current input file:"},
    {"CurrentOutputFile", "Current output file:"},
};

std::map<std::string, std::string> MenuMessagePoolEng::choosingLanguageMenu
{
    {"Language", "Language:"},
    {"English", "English"},
    {"Russian", "Russian"},
};

// MenuMessagePoolRus

std::map<std::string, std::string> MenuMessagePoolRus::other
{
    {"Error", "Ошибка"},
    {"Success", "Успех"},
    {"Running", "Программа запущена"},
    {"None", "Нет"},
};

std::map<std::string, std::string> MenuMessagePoolRus::mainMenu
{
    {"Start", "Запустить программу"},
    {"Options", "Настройки"},
    {"Exit", "Выход"},
};

std::map<std::string, std::string> MenuMessagePoolRus::optionsMenu
{
    {"Settings", "Настройки:"},
    {"ChangeInputFilePath", "Изменить путь ко входному файлу"},
    {"ChangeOutputFilePath", "Изменить путь к выходному файлу"},
    {"ChangeWorkMode", "Изменить режим работы"},
    {"ChangeLanguage", "Изменить язык"},
    {"Exit", "Выход"},
};

std::map<std::string, std::string> MenuMessagePoolRus::workModeMenu
{
    {"CurrentWorkMode", "Текущий режим работы:"},
    {"UntilFirstError", "Проверять до первой ошибки"},
    {"AllErrors", "Проверять все ошибки с учётом уровня вложенности"},
    {"AllErrorsWithoutInner", "Проверять все ошибки без учёта уровня вложенности"},
};

std::map<std::string, std::string> MenuMessagePoolRus::choosingFileMenu
{
    {"SelectionMode", "Вариант выбора файла:"},
    {"Manually", "Ввести вручную"},
    {"FromFolder", "Выбрать из папки"},
    {"InputFileName", "Введите название входного файла:"},
    {"OutputFileName", "Введите название выходного файла:"},
    {"CurrentInputFile", "Текущий входной файл:"},
    {"CurrentOutputFile", "Текущий выходной файл:"},
};

std::map<std::string, std::string> MenuMessagePoolRus::choosingLanguageMenu
{
    {"Language", "Язык:"},
    {"English", "Английский"},
    {"Russian", "Русский"},
};