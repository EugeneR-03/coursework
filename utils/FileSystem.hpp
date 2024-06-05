#pragma once

#include <conio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <filesystem>

enum class KeyCode
{
    ESC = 27,
    ESCAPE = 1,
    ENTER = 13,
    BACKSPACE = 8,
    UP = 72,
    LEFT = 75,
    RIGHT = 77,
    DOWN = 80,
};

class FileSystem
{
public:
    static std::vector<std::string> ReadStringsFromFile(std::string filename);
    static std::vector<std::string> GetFoldersListFromFolder(std::string folderPath);
    static std::vector<std::string> GetTXTFilesListFromFolder(std::string folderPath);
    static std::string GetInputFile(std::string text);
    static std::string GetOutputFile(std::string text);
};