#include "Settings.hpp"

Settings::Settings() {}

Settings::Settings(std::string configFilePath)
{
    std::ifstream configFile(configFilePath);
    nlohmann::json config;
    configFile >> config;
    configFile.close();

    this->inputFilePath = config["Settings"]["InputFilePath"];
    this->outputFilePath = config["Settings"]["OutputFilePath"];
    std::string debugMode = config["Settings"]["DebugMode"];
    std::string errorsMode = config["Settings"]["Errors"];
    std::string language = config["Settings"]["Language"];

    if (debugMode == "None")
    {
        this->debugMode = DebuggerWorkingMode::None;
    }
    else if (debugMode == "Normal")
    {
        this->debugMode = DebuggerWorkingMode::Normal;
    }
    else if (debugMode == "Verbose")
    {
        this->debugMode = DebuggerWorkingMode::Verbose;
    }

    if (errorsMode == "UntilFirst")
    {
        this->errorsMode = SyntaxBlockWorkingMode::UntilFirstError;
    }
    else if (errorsMode == "AllWithoutInner")
    {
        this->errorsMode = SyntaxBlockWorkingMode::AllErrorsWithoutInner;
    }
    else if (errorsMode == "All")
    {
        this->errorsMode = SyntaxBlockWorkingMode::AllErrors;
    }

    if (language == "English")
    {
        this->language = Language::English;
    }
    else if (language == "Russian")
    {
        this->language = Language::Russian;
    }
}

void Settings::WriteSettings(std::string configFilePath)
{
    nlohmann::json config;
    config["Settings"]["InputFilePath"] = this->inputFilePath;
    config["Settings"]["OutputFilePath"] = this->outputFilePath;
    switch (this->debugMode)
    {
        case DebuggerWorkingMode::None:
            config["Settings"]["DebugMode"] = "None";
            break;
        case DebuggerWorkingMode::Normal:
            config["Settings"]["DebugMode"] = "Normal";
            break;
        case DebuggerWorkingMode::Verbose:
            config["Settings"]["DebugMode"] = "Verbose";
            break;
    }
    switch (this->errorsMode)
    {
        case SyntaxBlockWorkingMode::UntilFirstError:
            config["Settings"]["Errors"] = "UntilFirst";
            break;
        case SyntaxBlockWorkingMode::AllErrorsWithoutInner:
            config["Settings"]["Errors"] = "AllWithoutInner";
            break;
        case SyntaxBlockWorkingMode::AllErrors:
            config["Settings"]["Errors"] = "All";
            break;
    }
    switch (this->language)
    {
        case Language::English:
            config["Settings"]["Language"] = "English";
            break;
        case Language::Russian:
            config["Settings"]["Language"] = "Russian";
            break;
    }
    std::ofstream configFile(configFilePath);
    configFile << config.dump(4);
    configFile.close();
}