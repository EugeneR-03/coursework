#pragma once

#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <conio.h>
#include <windows.h>

#include "./../utils/FileSystem.hpp"

class MenuItem
{
private:
    int id;
    std::string text;
    static int currentId;
public:
    WORD color;
    bool isActive;

    MenuItem(const std::string& text, WORD color = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    ~MenuItem();
    void SetActive(bool isActive = true);
    std::string GetText();
    std::string GetRawText();
};

class MenuController
{
private:
    HANDLE hStdOut;
    int activeMenuItemNumber;
    std::vector<std::string> menuDescriptions;
    std::vector<MenuItem*> menuItems;
public:
    MenuController();
    ~MenuController();
    void GoToXY(short x, short y);
    void SetConsoleCursorVisible(bool isVisible, short size = 20);
    MenuItem* GetMenuItem(int menuItemNumber);
    void AddMenuDescription(const std::string& text);
    void AddMenuItem(MenuItem* menuItem);
    void AddMenuItem(const std::string& text, WORD color = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    void SetActiveMenuItem(int menuItemNumber, bool isActive = true);
    void SetActiveMenuItemOnTopOfOthers(int menuItemNumber);
    void PrintMenuItem(int menuItemNumber);
    void PrintMenu();
    int SelectMenuItemNumber();
    MenuItem* SelectMenuItem();
    void ClearMenuDescriptions();
    void ClearMenuItems();
    void ClearMenu();

    static std::string SelectFile(MenuController* menuController = nullptr);
};