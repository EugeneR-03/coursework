#include "./main-blocks/MainBlock.hpp"
#include "./utils/Debugger.hpp"
#include "./utils/Settings.hpp"
#include "./utils/FileSystem.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <set>

#include <chrono>

void ConnectEvents(Debugger& debugger, std::vector<std::set<Message>>& messages)
{
    SyntaxBlock::CFG::Symbol::OpeningCurlyBrace::onErrorOccurs.connect(boost::bind(Debugger::AddMessageToVector, &debugger, boost::placeholders::_1, boost::ref(messages)));
    SyntaxBlock::CFG::Symbol::ClosingCurlyBrace::onErrorOccurs.connect(boost::bind(Debugger::AddMessageToVector, &debugger, boost::placeholders::_1, boost::ref(messages)));
    SyntaxBlock::CFG::Symbol::OpeningParenthesis::onErrorOccurs.connect(boost::bind(Debugger::AddMessageToVector, &debugger, boost::placeholders::_1, boost::ref(messages)));
    SyntaxBlock::CFG::Symbol::ClosingParenthesis::onErrorOccurs.connect(boost::bind(Debugger::AddMessageToVector, &debugger, boost::placeholders::_1, boost::ref(messages)));
    SyntaxBlock::CFG::Symbol::Comma::onErrorOccurs.connect(boost::bind(Debugger::AddMessageToVector, &debugger, boost::placeholders::_1, boost::ref(messages)));
    SyntaxBlock::CFG::Symbol::Colon::onErrorOccurs.connect(boost::bind(Debugger::AddMessageToVector, &debugger, boost::placeholders::_1, boost::ref(messages)));
    SyntaxBlock::CFG::Symbol::Semicolon::onErrorOccurs.connect(boost::bind(Debugger::AddMessageToVector, &debugger, boost::placeholders::_1, boost::ref(messages)));
    SyntaxBlock::CFG::Symbol::QuotationMark::onErrorOccurs.connect(boost::bind(Debugger::AddMessageToVector, &debugger, boost::placeholders::_1, boost::ref(messages)));
    SyntaxBlock::CFG::Symbol::EqualSign::onErrorOccurs.connect(boost::bind(Debugger::AddMessageToVector, &debugger, boost::placeholders::_1, boost::ref(messages)));
    SyntaxBlock::CFG::Symbol::ComparisonSign::onErrorOccurs.connect(boost::bind(Debugger::AddMessageToVector, &debugger, boost::placeholders::_1, boost::ref(messages)));
    SyntaxBlock::CFG::Symbol::ExclamationMark::onErrorOccurs.connect(boost::bind(Debugger::AddMessageToVector, &debugger, boost::placeholders::_1, boost::ref(messages)));
    SyntaxBlock::CFG::Symbol::ArithmeticSign::onErrorOccurs.connect(boost::bind(Debugger::AddMessageToVector, &debugger, boost::placeholders::_1, boost::ref(messages)));
    SyntaxBlock::CFG::Symbol::LogicalSign::onErrorOccurs.connect(boost::bind(Debugger::AddMessageToVector, &debugger, boost::placeholders::_1, boost::ref(messages)));
    
    SyntaxBlock::CFG::SpecialIdentifier::Operation::onErrorOccurs.connect(boost::bind(Debugger::AddMessageToVector, &debugger, boost::placeholders::_1, boost::ref(messages)));
    SyntaxBlock::CFG::SpecialIdentifier::OperandOfUnaryOperation::onErrorOccurs.connect(boost::bind(Debugger::AddMessageToVector, &debugger, boost::placeholders::_1, boost::ref(messages)));
    SyntaxBlock::CFG::SpecialIdentifier::FirstOperandOfBinaryOperation::onErrorOccurs.connect(boost::bind(Debugger::AddMessageToVector, &debugger, boost::placeholders::_1, boost::ref(messages)));
    SyntaxBlock::CFG::SpecialIdentifier::SecondOperandOfBinaryOperation::onErrorOccurs.connect(boost::bind(Debugger::AddMessageToVector, &debugger, boost::placeholders::_1, boost::ref(messages)));
    SyntaxBlock::CFG::SpecialIdentifier::Modulus::onErrorOccurs.connect(boost::bind(Debugger::AddMessageToVector, &debugger, boost::placeholders::_1, boost::ref(messages)));
    SyntaxBlock::CFG::SpecialIdentifier::SquareOfNumber::onErrorOccurs.connect(boost::bind(Debugger::AddMessageToVector, &debugger, boost::placeholders::_1, boost::ref(messages)));
    SyntaxBlock::CFG::SpecialIdentifier::SquareRootOfNumber::onErrorOccurs.connect(boost::bind(Debugger::AddMessageToVector, &debugger, boost::placeholders::_1, boost::ref(messages)));

    SyntaxBlock::CFG::Variable::Edge::onErrorOccurs.connect(boost::bind(Debugger::AddMessageToVector, &debugger, boost::placeholders::_1, boost::ref(messages)));
    SyntaxBlock::CFG::Variable::Identifier::onErrorOccurs.connect(boost::bind(Debugger::AddMessageToVector, &debugger, boost::placeholders::_1, boost::ref(messages)));
    SyntaxBlock::CFG::Variable::Integer::onErrorOccurs.connect(boost::bind(Debugger::AddMessageToVector, &debugger, boost::placeholders::_1, boost::ref(messages)));
    
    SyntaxBlock::CFG::Operation::Logical::onErrorOccurs.connect(boost::bind(Debugger::AddMessageToVector, &debugger, boost::placeholders::_1, boost::ref(messages)));
    SyntaxBlock::CFG::Operation::Arithmetic::onErrorOccurs.connect(boost::bind(Debugger::AddMessageToVector, &debugger, boost::placeholders::_1, boost::ref(messages)));

    SyntaxBlock::CFG::String::onErrorOccurs.connect(boost::bind(Debugger::AddMessageToVector, &debugger, boost::placeholders::_1, boost::ref(messages)));
    SyntaxBlock::CFG::String::Beginning::onErrorOccurs.connect(boost::bind(Debugger::AddMessageToVector, &debugger, boost::placeholders::_1, boost::ref(messages)));
    SyntaxBlock::CFG::String::Logical::onErrorOccurs.connect(boost::bind(Debugger::AddMessageToVector, &debugger, boost::placeholders::_1, boost::ref(messages)));
    SyntaxBlock::CFG::String::Arithmetic::onErrorOccurs.connect(boost::bind(Debugger::AddMessageToVector, &debugger, boost::placeholders::_1, boost::ref(messages)));
    SyntaxBlock::CFG::String::Inner::Operation::onErrorOccurs.connect(boost::bind(Debugger::AddMessageToVector, &debugger, boost::placeholders::_1, boost::ref(messages)));
    SyntaxBlock::CFG::String::Inner::Operand::Variable::onErrorOccurs.connect(boost::bind(Debugger::AddMessageToVector, &debugger, boost::placeholders::_1, boost::ref(messages)));
    SyntaxBlock::CFG::String::Inner::Operand::onErrorOccurs.connect(boost::bind(Debugger::AddMessageToVector, &debugger, boost::placeholders::_1, boost::ref(messages)));
}

int main(int argc, char* argv[])
{
    Settings settings("config.json");

    switch (settings.language)
    {
        case Language::English:
            MessagePool::SwitchPoolToLanguage(Language::English);
            break;
        case Language::Russian:
            MessagePool::SwitchPoolToLanguage(Language::Russian);
            break;
    }

    std::vector<std::string> strings = FileSystem::ReadStringsFromFile(settings.inputFilePath);
    int stringsCount = strings.size();

    if (settings.debugMode == DebuggerWorkingMode::None)
    {
        return 0;
    }

    std::vector<std::set<Message>> messages = std::vector<std::set<Message>>(stringsCount);
    std::vector<bool> results = std::vector<bool>(stringsCount);

    SyntaxBlock::InitLock();
    Debugger debugger = Debugger();
    ConnectEvents(debugger, messages);
    
    auto start = std::chrono::steady_clock::now();

    #pragma omp parallel for
    for (int stringIndex = 0; stringIndex < stringsCount; stringIndex++)
    {
        MainBlock mainBlock = MainBlock(settings.errorsMode);
        bool result = mainBlock.CheckString(stringIndex, strings[stringIndex], settings.errorsMode);
        results[stringIndex] = result;
    }

    auto end = std::chrono::steady_clock::now();

    std::cout << "Time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms" << std::endl;

    std::ofstream outputFile;
    outputFile.open(settings.outputFilePath);
    if (!outputFile.is_open()) {
        std::cerr << "Failed to open output file" << std::endl;
        return 1;
    }

    debugger.PrintMessagesAndResults(outputFile, messages, results);

    outputFile.close();
}