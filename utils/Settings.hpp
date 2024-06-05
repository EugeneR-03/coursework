#pragma once

#include <string>
#include <fstream>

#include "json.hpp"
#include "./../main-blocks/SyntaxBlock.hpp"
#include "Debugger.hpp"
#include "Language.hpp"

struct Settings
{
    std::string inputFilePath;
    std::string outputFilePath;
    DebuggerWorkingMode debugMode;
    SyntaxBlockWorkingMode errorsMode;
    Language language;

    Settings();
    Settings(std::string configFilePath);
    void WriteSettings(std::string configFilePath);
};