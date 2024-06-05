#pragma once

#include "./../utils/FileSystem.hpp"
#include "./../utils/Settings.hpp"
#include "MenuMessagePool.hpp"
#include "MenuController.hpp"

class CustomMenu
{
private:
    Settings settings;
    int mainMenuItemNumber;
    int optionsMenuItemNumber;
    int workModeMenuItemNumber;
    int choosingFileMenuItemNumber;
    int choosingLanguageMenuItemNumber;
    MenuController mainMenuController;
    MenuController optionsMenuController;
    MenuController workModeMenuController;
    MenuController choosingFileMenuController;
    MenuController filesMenuController;
    MenuController choosingLanguageMenuController;
    bool isChanged;

    std::string GetErrorsMode(SyntaxBlockWorkingMode& errorsMode);
    void Init();
    void ProcessMainMenuCommand(int menuItemNumber);
    void ProcessOptionsMenuCommand(int menuItemNumber);
    void ProcessWorkModeMenuCommand(int menuItemNumber);
    void ProcessChoosingInputFileMenuCommand(int menuItemNumber);
    void ProcessChoosingOutputFileMenuCommand(int menuItemNumber);
    void ProcessChoosingLanguageMenuCommand(int menuItemNumber);

public:
    CustomMenu(Settings& settings);
    void Launch();
};