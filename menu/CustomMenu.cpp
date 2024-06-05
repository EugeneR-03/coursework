#include "CustomMenu.hpp"

CustomMenu::CustomMenu(Settings& settings)
{
    this->settings = settings;
    Init();
}

std::string CustomMenu::GetErrorsMode(SyntaxBlockWorkingMode& errorsMode)
{
    std::string workMode = "";
    switch (errorsMode)
    {
        case SyntaxBlockWorkingMode::UntilFirstError:
            workMode = MenuMessagePool::GetMenuMessage("WorkModeMenu", "UntilFirstError");
            break;
        case SyntaxBlockWorkingMode::AllErrorsWithoutInner:
            workMode = MenuMessagePool::GetMenuMessage("WorkModeMenu", "AllErrorsWithoutInner");
            break;
        case SyntaxBlockWorkingMode::AllErrors:
            workMode = MenuMessagePool::GetMenuMessage("WorkModeMenu", "AllErrors");
            break;
    }
    return workMode;
}

void CustomMenu::Init()
{
    switch (settings.language)
    {
        case Language::English:
        {
            MenuMessagePool::SwitchPoolToLanguage(Language::English);
            break;
        }
        case Language::Russian:
        {
            MenuMessagePool::SwitchPoolToLanguage(Language::Russian);
            break;
        }
    }

    mainMenuItemNumber = 0;
    optionsMenuItemNumber = 0;
    workModeMenuItemNumber = 0;
    choosingFileMenuItemNumber = 0;
    choosingLanguageMenuItemNumber = 0;
    isChanged = false;

    mainMenuController = MenuController();
    mainMenuController.AddMenuItem(MenuMessagePool::GetMenuMessage("MainMenu", "Start"));
    mainMenuController.AddMenuItem(MenuMessagePool::GetMenuMessage("MainMenu", "Options"));
    mainMenuController.AddMenuItem(MenuMessagePool::GetMenuMessage("MainMenu", "Exit"));

    optionsMenuController = MenuController();
    optionsMenuController.AddMenuDescription(MenuMessagePool::GetMenuMessage("OptionsMenu", "Settings"));
    optionsMenuController.AddMenuItem(MenuMessagePool::GetMenuMessage("OptionsMenu", "ChangeInputFilePath"));
    optionsMenuController.AddMenuItem(MenuMessagePool::GetMenuMessage("OptionsMenu", "ChangeOutputFilePath"));
    optionsMenuController.AddMenuItem(MenuMessagePool::GetMenuMessage("OptionsMenu", "ChangeWorkMode"));
    optionsMenuController.AddMenuItem(MenuMessagePool::GetMenuMessage("OptionsMenu", "ChangeLanguage"));
    optionsMenuController.AddMenuItem(MenuMessagePool::GetMenuMessage("OptionsMenu", "Exit"));

    workModeMenuController = MenuController();
    workModeMenuController.AddMenuItem(MenuMessagePool::GetMenuMessage("WorkModeMenu", "UntilFirstError"));
    workModeMenuController.AddMenuItem(MenuMessagePool::GetMenuMessage("WorkModeMenu", "AllErrorsWithoutInner"));
    workModeMenuController.AddMenuItem(MenuMessagePool::GetMenuMessage("WorkModeMenu", "AllErrors"));

    choosingFileMenuController = MenuController();
    choosingFileMenuController.AddMenuDescription(MenuMessagePool::GetMenuMessage("ChoosingFileMenu", "SelectionMode"));
    choosingFileMenuController.AddMenuItem(MenuMessagePool::GetMenuMessage("ChoosingFileMenu", "Manually"));
    choosingFileMenuController.AddMenuItem(MenuMessagePool::GetMenuMessage("ChoosingFileMenu", "FromFolder"));

    choosingLanguageMenuController = MenuController();
    choosingLanguageMenuController.AddMenuDescription(MenuMessagePool::GetMenuMessage("ChoosingLanguageMenu", "Language"));
    choosingLanguageMenuController.AddMenuItem(MenuMessagePool::GetMenuMessage("ChoosingLanguageMenu", "English"));
    choosingLanguageMenuController.AddMenuItem(MenuMessagePool::GetMenuMessage("ChoosingLanguageMenu", "Russian"));

    filesMenuController = MenuController();
}

void CustomMenu::ProcessMainMenuCommand(int menuItemNumber)
{
    switch(menuItemNumber)
    {
        case 1:
        {
            // запуск процесса main.exe
            STARTUPINFO si;
            PROCESS_INFORMATION pi;
            ZeroMemory(&si, sizeof(si));
            si.cb = sizeof(si);
            ZeroMemory(&pi, sizeof(pi));

            LPCTSTR lpApplicationName = TEXT("main.exe");
            if (!CreateProcess(lpApplicationName, NULL, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi))
            {
                std::cout << MenuMessagePool::GetMenuMessage("Other", "Error") + ": " << GetLastError() << std::endl;
            };

            // ожидание завершения процесса
            std::cout << MenuMessagePool::GetMenuMessage("Other", "Running") << std::endl;
            WaitForSingleObject(pi.hProcess, INFINITE);
            CloseHandle(pi.hProcess);
            CloseHandle(pi.hThread);
            break;
        }
        case 2:
            optionsMenuItemNumber = optionsMenuController.SelectMenuItemNumber();
            break;
        case 3:
            exit(0);
        default:
            break;
    }
}

void CustomMenu::ProcessOptionsMenuCommand(int menuItemNumber)
{
    switch(menuItemNumber)
    {
        case 1:
        case 2:
            choosingFileMenuItemNumber = choosingFileMenuController.SelectMenuItemNumber();
            break;
        case 3:
        {
            workModeMenuController.ClearMenuDescriptions();
            std::string workMode = GetErrorsMode(settings.errorsMode);
            workModeMenuController.AddMenuDescription(MenuMessagePool::GetMenuMessage("WorkModeMenu", "CurrentWorkMode") + " " + workMode);
            workModeMenuItemNumber = workModeMenuController.SelectMenuItemNumber();
            break;
        }
        case 4:
            choosingLanguageMenuItemNumber = choosingLanguageMenuController.SelectMenuItemNumber();
            break;
        case 5:
            break;
        default:
            break;
    }
}

void CustomMenu::ProcessWorkModeMenuCommand(int menuItemNumber)
{
    switch (menuItemNumber)
    {
        case 1:
        {
            SyntaxBlockWorkingMode errorsMode = SyntaxBlockWorkingMode::UntilFirstError;
            if (errorsMode != settings.errorsMode)
            {
                isChanged = true;
                settings.errorsMode = errorsMode;
            }
            break;
        }
        case 2:
        {
            SyntaxBlockWorkingMode errorsMode = SyntaxBlockWorkingMode::AllErrorsWithoutInner;
            if (errorsMode != settings.errorsMode)
            {
                isChanged = true;
                settings.errorsMode = errorsMode;
            }
            break;
        }
        case 3:
        {
            SyntaxBlockWorkingMode errorsMode = SyntaxBlockWorkingMode::AllErrors;
            if (errorsMode != settings.errorsMode)
            {
                isChanged = true;
                settings.errorsMode = errorsMode;
            }
            break;
        }
    }
}

void CustomMenu::ProcessChoosingInputFileMenuCommand(int menuItemNumber)
{
    switch(menuItemNumber)
    {
        case 1:
        {
            std::system("cls");
            std::string inputFilePath = "";
            inputFilePath = FileSystem::GetInputFile(MenuMessagePool::GetMenuMessage("ChoosingFileMenu", "InputFileName"));
            if (!inputFilePath.empty() && inputFilePath != settings.inputFilePath)
            {
                isChanged = true;
                settings.inputFilePath = inputFilePath;
            }
            break;
        }
        case 2:
        {
            std::string inputFilePath = "";
            filesMenuController.ClearMenuDescriptions();
            if (settings.inputFilePath.empty())
            {
                filesMenuController.AddMenuDescription(MenuMessagePool::GetMenuMessage("ChoosingFileMenu", "CurrentInputFile") + " " + MenuMessagePool::GetMenuMessage("Other", "None"));
            }
            else
            {
                filesMenuController.AddMenuDescription(MenuMessagePool::GetMenuMessage("ChoosingFileMenu", "CurrentInputFile") + " " + std::filesystem::absolute(settings.inputFilePath).string());
            }
            inputFilePath = MenuController::SelectFile(&filesMenuController);
            if (!inputFilePath.empty() && inputFilePath != settings.inputFilePath)
            {
                isChanged = true;
                settings.inputFilePath = inputFilePath;
            }
            break;
        }
        default:
            break;
    }
}

void CustomMenu::ProcessChoosingOutputFileMenuCommand(int menuItemNumber)
{
    switch(menuItemNumber)
    {
        case 1:
        {
            std::system("cls");
            std::string outputFilePath = "";
            outputFilePath = FileSystem::GetOutputFile(MenuMessagePool::GetMenuMessage("ChoosingFileMenu", "OutputFileName"));
            if (!outputFilePath.empty() && outputFilePath != settings.outputFilePath)
            {
                isChanged = true;
                settings.outputFilePath = outputFilePath;
            }
            break;
        }
        case 2:
        {
            std::string outputFilePath = "";
            filesMenuController.ClearMenuDescriptions();
            if (settings.outputFilePath.empty())
            {
                filesMenuController.AddMenuDescription(MenuMessagePool::GetMenuMessage("ChoosingFileMenu", "CurrentOutputFile") + " " + MenuMessagePool::GetMenuMessage("Other", "None"));
            }
            else
            {
                filesMenuController.AddMenuDescription(MenuMessagePool::GetMenuMessage("ChoosingFileMenu", "CurrentOutputFile") + " " + std::filesystem::absolute(settings.outputFilePath).string());
            }
            outputFilePath = MenuController::SelectFile(&filesMenuController);
            if (!outputFilePath.empty() && outputFilePath != settings.outputFilePath)
            {
                isChanged = true;
                settings.outputFilePath = outputFilePath;
            }
            break;
        }
        default:
            break;
    }
}

void CustomMenu::ProcessChoosingLanguageMenuCommand(int menuItemNumber)
{
    switch(menuItemNumber)
    {
        case 1:
        {
            if (settings.language != Language::English)
            {
                MenuMessagePool::SwitchPoolToLanguage(Language::English);
                settings.language = Language::English;
                isChanged = true;
            }            
            break;
        }
        case 2:
        {
            if (settings.language != Language::Russian)
            {
                MenuMessagePool::SwitchPoolToLanguage(Language::Russian);
                settings.language = Language::Russian;
                isChanged = true;
            }            
            break;
        }
        default:
            break;
    }
}

void CustomMenu::Launch()
{
    Init();

    mainMenuItemNumber = mainMenuController.SelectMenuItemNumber();
    
    ProcessMainMenuCommand(mainMenuItemNumber);

    ProcessOptionsMenuCommand(optionsMenuItemNumber);

    if (optionsMenuItemNumber == 1)
    {
        ProcessChoosingInputFileMenuCommand(choosingFileMenuItemNumber);
    }
    else if (optionsMenuItemNumber == 2)
    {
        ProcessChoosingOutputFileMenuCommand(choosingFileMenuItemNumber);
    }

    ProcessWorkModeMenuCommand(workModeMenuItemNumber);

    ProcessChoosingLanguageMenuCommand(choosingLanguageMenuItemNumber);
    
    if (isChanged)
    {
        settings.WriteSettings("config.json");
    }
}