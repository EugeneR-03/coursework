#include <iostream>
#include <filesystem>
#include <fstream>

#include "./main-blocks/SyntaxBlock.hpp"
#include "./menu/CustomMenu.hpp"
#include "./utils/Debugger.hpp"

int main()
{
    Settings settings = Settings("config.json");

    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    CustomMenu menu = CustomMenu(settings);

    while (true)
    {
        menu.Launch();
    }    

    return 0;
}