#include "./blocks/MainBlock.hpp"
#include "Debugger.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "json.hpp"

#include <chrono>
#include <thread>
#include <future>

// using namespace std::string_literals;

template<typename T>
std::vector<std::string> ReadStringsFromFile(T filename)
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

struct Settings
{
    std::string inputFilePath;
    std::string outputFilePath;
    DebuggerWorkingMode debugMode;
    SyntaxBlockWorkingMode errorsMode;

    Settings(std::string configFilePath)
    {
        std::ifstream configFile(configFilePath);
        nlohmann::json config;
        configFile >> config;
        configFile.close();

        this->inputFilePath = config["Settings"]["InputFilePath"];
        this->outputFilePath = config["Settings"]["OutputFilePath"];
        std::string debugMode = config["Settings"]["DebugMode"];
        std::string errorsMode = config["Settings"]["Errors"];
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
    }
};

void ConnectEvents(std::vector<std::vector<Message>>& messages)
{
    SyntaxBlock::CFG::Symbol::OpeningCurlyBrace::onErrorOccurs.connect(boost::bind(Debugger::AddMessageToVector, boost::placeholders::_1, boost::ref(messages)));
    SyntaxBlock::CFG::Symbol::ClosingCurlyBrace::onErrorOccurs.connect(boost::bind(Debugger::AddMessageToVector, boost::placeholders::_1, boost::ref(messages)));
    SyntaxBlock::CFG::Symbol::OpeningParenthesis::onErrorOccurs.connect(boost::bind(Debugger::AddMessageToVector, boost::placeholders::_1, boost::ref(messages)));
    SyntaxBlock::CFG::Symbol::ClosingParenthesis::onErrorOccurs.connect(boost::bind(Debugger::AddMessageToVector, boost::placeholders::_1, boost::ref(messages)));
    SyntaxBlock::CFG::Symbol::Comma::onErrorOccurs.connect(boost::bind(Debugger::AddMessageToVector, boost::placeholders::_1, boost::ref(messages)));
    SyntaxBlock::CFG::Symbol::Colon::onErrorOccurs.connect(boost::bind(Debugger::AddMessageToVector, boost::placeholders::_1, boost::ref(messages)));
    SyntaxBlock::CFG::Symbol::Semicolon::onErrorOccurs.connect(boost::bind(Debugger::AddMessageToVector, boost::placeholders::_1, boost::ref(messages)));
    SyntaxBlock::CFG::Symbol::QuotationMark::onErrorOccurs.connect(boost::bind(Debugger::AddMessageToVector, boost::placeholders::_1, boost::ref(messages)));
    SyntaxBlock::CFG::Symbol::EqualSign::onErrorOccurs.connect(boost::bind(Debugger::AddMessageToVector, boost::placeholders::_1, boost::ref(messages)));
    SyntaxBlock::CFG::Symbol::ComparisonSign::onErrorOccurs.connect(boost::bind(Debugger::AddMessageToVector, boost::placeholders::_1, boost::ref(messages)));
    SyntaxBlock::CFG::Symbol::ExclamationMark::onErrorOccurs.connect(boost::bind(Debugger::AddMessageToVector, boost::placeholders::_1, boost::ref(messages)));
    SyntaxBlock::CFG::Symbol::ArithmeticSign::onErrorOccurs.connect(boost::bind(Debugger::AddMessageToVector, boost::placeholders::_1, boost::ref(messages)));
    SyntaxBlock::CFG::Symbol::LogicalSign::onErrorOccurs.connect(boost::bind(Debugger::AddMessageToVector, boost::placeholders::_1, boost::ref(messages)));
    
    SyntaxBlock::CFG::SpecialIdentifier::Operation::onErrorOccurs.connect(boost::bind(Debugger::AddMessageToVector, boost::placeholders::_1, boost::ref(messages)));
    SyntaxBlock::CFG::SpecialIdentifier::OperandOfUnaryOperation::onErrorOccurs.connect(boost::bind(Debugger::AddMessageToVector, boost::placeholders::_1, boost::ref(messages)));
    SyntaxBlock::CFG::SpecialIdentifier::FirstOperandOfBinaryOperation::onErrorOccurs.connect(boost::bind(Debugger::AddMessageToVector, boost::placeholders::_1, boost::ref(messages)));
    SyntaxBlock::CFG::SpecialIdentifier::SecondOperandOfBinaryOperation::onErrorOccurs.connect(boost::bind(Debugger::AddMessageToVector, boost::placeholders::_1, boost::ref(messages)));
    SyntaxBlock::CFG::SpecialIdentifier::Modulus::onErrorOccurs.connect(boost::bind(Debugger::AddMessageToVector, boost::placeholders::_1, boost::ref(messages)));
    SyntaxBlock::CFG::SpecialIdentifier::SquareOfNumber::onErrorOccurs.connect(boost::bind(Debugger::AddMessageToVector, boost::placeholders::_1, boost::ref(messages)));
    SyntaxBlock::CFG::SpecialIdentifier::SquareRootOfNumber::onErrorOccurs.connect(boost::bind(Debugger::AddMessageToVector, boost::placeholders::_1, boost::ref(messages)));

    SyntaxBlock::CFG::Variable::Edge::onErrorOccurs.connect(boost::bind(Debugger::AddMessageToVector, boost::placeholders::_1, boost::ref(messages)));
    SyntaxBlock::CFG::Variable::Identifier::onErrorOccurs.connect(boost::bind(Debugger::AddMessageToVector, boost::placeholders::_1, boost::ref(messages)));
    SyntaxBlock::CFG::Variable::Integer::onErrorOccurs.connect(boost::bind(Debugger::AddMessageToVector, boost::placeholders::_1, boost::ref(messages)));
    
    SyntaxBlock::CFG::Operation::Logical::onErrorOccurs.connect(boost::bind(Debugger::AddMessageToVector, boost::placeholders::_1, boost::ref(messages)));
    SyntaxBlock::CFG::Operation::Arithmetic::onErrorOccurs.connect(boost::bind(Debugger::AddMessageToVector, boost::placeholders::_1, boost::ref(messages)));

    SyntaxBlock::CFG::String::onErrorOccurs.connect(boost::bind(Debugger::AddMessageToVector, boost::placeholders::_1, boost::ref(messages)));
    SyntaxBlock::CFG::String::Beginning::onErrorOccurs.connect(boost::bind(Debugger::AddMessageToVector, boost::placeholders::_1, boost::ref(messages)));
    SyntaxBlock::CFG::String::Logical::onErrorOccurs.connect(boost::bind(Debugger::AddMessageToVector, boost::placeholders::_1, boost::ref(messages)));
    SyntaxBlock::CFG::String::Arithmetic::onErrorOccurs.connect(boost::bind(Debugger::AddMessageToVector, boost::placeholders::_1, boost::ref(messages)));
    SyntaxBlock::CFG::String::Inner::Operation::onErrorOccurs.connect(boost::bind(Debugger::AddMessageToVector, boost::placeholders::_1, boost::ref(messages)));
    SyntaxBlock::CFG::String::Inner::Operand::Variable::onErrorOccurs.connect(boost::bind(Debugger::AddMessageToVector, boost::placeholders::_1, boost::ref(messages)));
    SyntaxBlock::CFG::String::Inner::Operand::onErrorOccurs.connect(boost::bind(Debugger::AddMessageToVector, boost::placeholders::_1, boost::ref(messages)));
}

int main(int argc, char* argv[])
{
    Settings settings("config.json");

    std::vector<std::string> strings = ReadStringsFromFile(settings.inputFilePath);
    int stringsCount = strings.size();

    if (settings.debugMode == DebuggerWorkingMode::None)
    {
        return 0;
    }

    std::vector<std::vector<Message>> messages = std::vector<std::vector<Message>>(stringsCount);
    std::vector<bool> results = std::vector<bool>(stringsCount);

    ConnectEvents(messages);
    
    auto start = std::chrono::steady_clock::now();
    
    #pragma omp parallel for
    for (int stringIndex = 0; stringIndex < stringsCount; stringIndex++)
    {
        MainBlock mainBlock = MainBlock(settings.errorsMode);
        bool result = mainBlock.CheckString(stringIndex, strings[stringIndex], settings.errorsMode);
        #pragma omp critical
        {
        results[stringIndex] = result;
        }
    }

    for (int i = 0; i < messages.size(); i++)
    {
        std::sort(messages[i].begin(), messages[i].end(),
            [](const Message& a, const Message& b) -> bool
            {
                return a.tokenIndex < b.tokenIndex;
            });
    }

    auto end = std::chrono::steady_clock::now();

    std::cout << "Time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms" << std::endl;

    std::ofstream outputFile;
    outputFile.open(settings.outputFilePath);
    if (!outputFile.is_open()) {
        std::cerr << "Failed to open output file" << std::endl;
        return 1;
    }

    Debugger::PrintMessagesAndResults(outputFile, messages, results);

    outputFile.close();
}