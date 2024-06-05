#include "FileSystem.hpp"

std::vector<std::string> FileSystem::ReadStringsFromFile(std::string filename)
{
    std::vector<std::string> result;

    std::ifstream file;
    file.open(filename);

    if (file.is_open())
    {
        std::string line;
        while (std::getline(file, line))
        {
            result.push_back(line);
        }
        file.close();
    }

    return result;
}

std::vector<std::string> FileSystem::GetFoldersListFromFolder(std::string folderPath)
{
    if (!std::filesystem::exists(folderPath))
    {
        throw std::runtime_error("Директория не существует");
    }

    std::vector<std::string> result;

    for (const auto& entry : std::filesystem::directory_iterator(folderPath))
    {
        if (entry.is_directory())
        {
            result.push_back(entry.path().string());
        }
    }

    return result;
}

std::vector<std::string> FileSystem::GetTXTFilesListFromFolder(std::string folderPath)
{
    if (!std::filesystem::exists(folderPath))
    {
        throw std::runtime_error("Директория не существует");
    }

    std::vector<std::string> result;

    for (const auto& entry : std::filesystem::directory_iterator(folderPath))
    {
        if (entry.path().extension() == ".txt")
        {
            result.push_back(entry.path().string());
        }
    }

    return result;
}

std::string FileSystem::GetInputFile(std::string text)
{
    std::string filePath;
    
    while (true)
    {
        std::cout << "Текущая директория: " << std::filesystem::current_path() << std::endl;
        std::cout << "Нажмите Esc для выхода." << std::endl;
        std::cout << text << std::endl;

        char ch = _getch();
        while (ch != (int)KeyCode::ENTER && ch != (int)KeyCode::ESC)
        {
            if (ch == (int)KeyCode::BACKSPACE)
            {
                filePath.resize(0, filePath.length() - 1);
                std::cout << "\b \b";
            }
            else
            {
                filePath += ch;
                std::cout << ch;
            }
            ch = _getch();
        }

        if (ch == (int)KeyCode::ESC)
        {
            filePath = "";
            break;
        }
        
        if (std::filesystem::exists(filePath) && filePath.ends_with(".txt"))
        {
            break;
        }
        else
        {
            std::cout << std::endl;
            std::cout << "Файл не существует или некорректного формата (должен быть .txt). Попробуйте ещё раз." << std::endl;
            std::cout << "Для продолжения нажмите любую клавишу." << std::endl;
            _getch();
            filePath = "";
            std::system("cls");
        }
    }
    return filePath;
}

std::string FileSystem::GetOutputFile(std::string text)
{
    std::string filePath;
    
    while (true)
    {
        std::cout << "Текущая директория: " << std::filesystem::current_path() << std::endl;
        std::cout << "Нажмите Esc для выхода." << std::endl;
        std::cout << text << std::endl;

        char ch = _getch();
        while (ch != (int)KeyCode::ENTER && ch != (int)KeyCode::ESC)
        {
            if (ch == (int)KeyCode::BACKSPACE)
            {
                filePath = filePath.substr(0, filePath.length() - 1);
                std::cout << "\b \b";
            }
            else
            {
                filePath += ch;
                std::cout << ch;
            }
            ch = _getch();
        }

        if (ch == (int)KeyCode::ESC)
        {
            filePath = "";
            break;
        }
        
        if (filePath.ends_with(".txt"))
        {
            break;
        }
        else
        {
            std::cout << std::endl;
            std::cout << "Файл некорректного формата (должен быть .txt). Попробуйте ещё раз." << std::endl;
            std::cout << "Для продолжения нажмите любую клавишу." << std::endl;
            _getch();
            filePath = "";
            std::system("cls");
        }
    }
    return filePath;
}