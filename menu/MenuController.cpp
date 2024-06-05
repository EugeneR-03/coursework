#include "MenuController.hpp"

int MenuItem::currentId = 0;

MenuItem::MenuItem(const std::string& text, WORD color)
{
    this->id = currentId++;
    this->text = text;
    this->text.insert(0, "   ");
    this->isActive = false;
    this->color = color;
}

MenuItem::~MenuItem() {}

void MenuItem::SetActive(bool isActive)
{
    this->isActive = isActive;
    if (isActive)
    {
        this->text.erase(0, 3);
        this->text.insert(0, ">> ");
    }
    else
    {
        this->text.erase(0, 3);
        this->text.insert(0, "   ");
    }
}

std::string MenuItem::GetText()
{
    std::string result = this->text;
    result.erase(0, 3);
    return result;
}

std::string MenuItem::GetRawText()
{
    return this->text;
}

MenuController::MenuController()
{
    this->hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    this->activeMenuItemNumber = 0;
}

MenuController::~MenuController()
{
    for (MenuItem* menuItem : this->menuItems)
    {
        delete menuItem;
    }
    this->menuItems.clear();
    this->menuDescriptions.clear();
}

void MenuController::GoToXY(short x, short y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(hStdOut, coord);
}

void MenuController::SetConsoleCursorVisible(bool isVisible, short size)
{
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hStdOut, &cursorInfo);
    cursorInfo.bVisible = isVisible;
    cursorInfo.dwSize = size;
    SetConsoleCursorInfo(hStdOut, &cursorInfo);
}

MenuItem* MenuController::GetMenuItem(int menuItemNumber)
{
    if (menuItemNumber < 1 || menuItemNumber > this->menuItems.size())
    {
        return nullptr;
    }
    return this->menuItems[menuItemNumber - 1];
}

void MenuController::AddMenuDescription(const std::string& text)
{
    this->menuDescriptions.push_back(text);
}

void MenuController::AddMenuItem(MenuItem* menuItem)
{
    this->menuItems.push_back(menuItem);
}

void MenuController::AddMenuItem(const std::string& text, WORD color)
{
    this->menuItems.push_back(new MenuItem(text, color));
}

void MenuController::SetActiveMenuItem(int menuItemNumber, bool isActive)
{
    this->menuItems[menuItemNumber-1]->SetActive(isActive);
}

void MenuController::SetActiveMenuItemOnTopOfOthers(int menuItemNumber)
{
    for (size_t i = 0; i < this->menuItems.size(); i++)
    {
        MenuItem* menuItem = this->menuItems[i];
        int currentNumber = i + 1;
        if (currentNumber == menuItemNumber)
        {
            menuItem->SetActive(true);
        }
        else
        {
            menuItem->SetActive(false);
        }
    }
}

void MenuController::PrintMenuItem(int menuItemNumber)
{
    MenuItem* menuItem = this->menuItems[menuItemNumber - 1];
    if (menuItem->isActive)
    {
        SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    }
    else
    {
        SetConsoleTextAttribute(hStdOut, menuItem->color);
    }
    std::cout << menuItem->GetRawText() << std::endl;
    SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void MenuController::PrintMenu()
{
    for (size_t i = 0; i < this->menuDescriptions.size(); i++)
    {
        std::cout << this->menuDescriptions[i] << std::endl;
    }
    for (size_t i = 0; i < this->menuItems.size(); i++)
    {
        this->PrintMenuItem(i + 1);
    }
}

int MenuController::SelectMenuItemNumber()
{
    SetConsoleCursorVisible(false);
    int key = 0;
    int menuItemNumber = 0;
    int code;
    do {
        std::system("cls");
        int menuItemsCount = this->menuItems.size();
        key = (key + menuItemsCount) % menuItemsCount;
        menuItemNumber = key + 1;
        this->SetActiveMenuItemOnTopOfOthers(menuItemNumber);
        this->PrintMenu();

        code = _getch();
        if (code == 224)
        {
            code = _getch();
            if (code == (int)KeyCode::DOWN)
                key++;
            else if (code == (int)KeyCode::UP)
                key--;
        }
    } while (code != (int)KeyCode::ENTER);    
    SetConsoleCursorVisible(true);
    return menuItemNumber;
}

MenuItem* MenuController::SelectMenuItem()
{
    int menuItemNumber = this->SelectMenuItemNumber();
    return this->GetMenuItem(menuItemNumber);
}

void MenuController::ClearMenuDescriptions()
{
    this->menuDescriptions.clear();
}

void MenuController::ClearMenuItems()
{
    this->menuItems.clear();
}

void MenuController::ClearMenu()
{
    this->ClearMenuDescriptions();
    this->ClearMenuItems();
}

std::string MenuController::SelectFile(MenuController* menuController)
{
    MenuController filesMenuController;
    if (menuController == nullptr)
    {
        filesMenuController = MenuController();
    }
    else
    {
        filesMenuController = *menuController;
    }
    std::string inputPath = "";
    std::string currentFolder = ".\\";

    while (inputPath.empty())
    {
        std::vector<std::string> folders = FileSystem::GetFoldersListFromFolder(currentFolder);
        std::vector<std::string> files = FileSystem::GetTXTFilesListFromFolder(currentFolder);

        int menuItemsCount = folders.size() + files.size() + 2;
        filesMenuController.AddMenuItem("..");
        for (size_t i = 0; i < folders.size(); i++)
        {
            filesMenuController.AddMenuItem(folders[i]);
        }
        for (size_t i = 0; i < files.size(); i++)
        {
            filesMenuController.AddMenuItem(files[i], FOREGROUND_RED | FOREGROUND_GREEN);
        }
        filesMenuController.AddMenuItem("Выход");

        int fileMenuItem = filesMenuController.SelectMenuItemNumber();
        MenuItem* item = filesMenuController.GetMenuItem(fileMenuItem);

        if (fileMenuItem == menuItemsCount)
        {
            break;
        }

        if (item != nullptr)
        {
            std::string text = item->GetText();
            std::cout << currentFolder << std::endl;
            // проверка, является ли результат папкой
            if (std::filesystem::is_directory(text))
            {
                if (text == "..")
                {
                    currentFolder = std::filesystem::path(currentFolder).parent_path().string();
                    if (currentFolder == ".")
                    {
                        currentFolder = ".\\";
                    }
                }
                else
                {
                    currentFolder = text;
                }
                std::cout << currentFolder << std::endl;
                filesMenuController.ClearMenuItems();
            }
            else
            {
                inputPath = text;
            }
        }
    }
    return inputPath;
}