#include "./blocks/TransliterationBlock.h"
#include "./blocks/LexicalBlock.h"
#include "./blocks/SyntaxBlock.h"
#include <iostream>

// #define NDEBUG
#include <string>
#include <vector>
#include <fstream>
#include <codecvt>

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


int main(int argc, char* argv[])
{
    // doctest::Context context;
    // context.setOption("no-breaks", true);
    // int res = context.run();
    // if (context.shouldExit())
    //     return res;

    const char* tokenTypes[] = {
        "Letter", 
        "Digit", 
        "OpeningCurlyBrace", 
        "ClosingCurlyBrace", 
        "OpeningParenthesis", 
        "ClosingParenthesis", 
        "Comma", 
        "Colon", 
        "Semicolon", 
        "QuotationMark", 
        "EqualSign", 
        "ComparisonSign", 
        "ExclamationMark", 
        "ArithmeticSign", 
        "LogicalSign", 
        "SpaceSign", 
        "Other",
    };

    const char* complexTokenTypes[] = {
        "Identifier",             // идентификатор
        "Integer",                // целое число
    };

    const char* specialIdentifierTypes[] = {
        "Operation",
        "OperandOfUnaryOperation",
        "FirstOperandOfBinaryOperation",
        "SecondOperandOfBinaryOperation",
        "V",
        "No",
        "Real",
        "Solution",
        "Modulus",
        "SquareOfNumber",
        "SquareRootOfNumber",
    };

    std::string inputFilePath = "./data/input.txt";
    std::vector<std::string> strings = ReadStringsFromFile(inputFilePath);
    // for(const auto& str : strings) {
    //     std::cout << str << std::endl;
    // }

    std::string outputFilePath = "./data/output.txt";
    std::ofstream outputFile(outputFilePath);

    if (!outputFile.is_open()) {
        std::cerr << "Failed to open output file" << std::endl;
        return 1;
    }

    std::string targetString = strings[9];
    outputFile << targetString << std::endl;
    outputFile << std::endl;

    std::vector<std::variant<SimpleToken, ComplexToken>> combinedTokens = LexicalBlock::TransliterateString(targetString);
    for (int i = 0; i < combinedTokens.size(); i++) {
        std::variant<SimpleToken, ComplexToken> combinedToken = combinedTokens[i];
        if (std::holds_alternative<SimpleToken>(combinedToken)) {
            SimpleToken token = std::get<SimpleToken>(combinedToken);
            char symbol = targetString[token.index];
            // std::cout << typeid(token.tokenType).name() << std::endl;
            outputFile << symbol << '\t' << token.index << "\t" << tokenTypes[static_cast<std::underlying_type<SimpleTokenType>::type>(token.type)] << std::endl;
        }
        else {
            ComplexToken token = std::get<ComplexToken>(combinedToken);
            std::string bufStr = targetString.substr(token.index, token.value.length());
            if (std::holds_alternative<ComplexTokenType>(token.type)) {
                outputFile << bufStr << '\t' << token.index << "\t" << complexTokenTypes[static_cast<std::underlying_type<ComplexTokenType>::type>(std::get<ComplexTokenType>(token.type))] << std::endl;
            }
            else if (std::holds_alternative<SpecialIdentifierType>(token.type)) {
                outputFile << bufStr << '\t' << token.index << "\t" << specialIdentifierTypes[static_cast<std::underlying_type<SpecialIdentifierType>::type>(std::get<SpecialIdentifierType>(token.type))] << std::endl;
            }
        }
    }
    
    SyntaxBlock::LoadTokenVector(combinedTokens);
    outputFile << std::endl;
    outputFile << SyntaxBlock::CFG::String::Check() << std::endl;

    outputFile.close();
    // return res + 0;



    

    // std::string targetString = strings[0];
    // std::cout << targetString << std::endl;

    // std::vector<std::variant<SimpleToken, ComplexToken>> combinedTokens = LexicalBlock::TransliterateString(targetString);
    // for (int i = 0; i < combinedTokens.size(); i++) {
    //     std::variant<SimpleToken, ComplexToken> combinedToken = combinedTokens[i];
    //     if (std::holds_alternative<SimpleToken>(combinedToken)) {
    //         SimpleToken token = std::get<SimpleToken>(combinedToken);
    //         char symbol = targetString[token.index];
    //         // std::cout << typeid(token.tokenType).name() << std::endl;
    //         std::cout << symbol << '\t' << token.index << "\t" << tokenTypes[static_cast<std::underlying_type<SimpleTokenType>::type>(token.type)] << std::endl;
    //     }
    //     else {
    //         ComplexToken token = std::get<ComplexToken>(combinedToken);
    //         std::string bufStr = targetString.substr(token.index, token.value.length());
    //         if (std::holds_alternative<ComplexTokenType>(token.type)) {
    //             std::cout << bufStr << '\t' << token.index << "\t" << complexTokenTypes[static_cast<std::underlying_type<ComplexTokenType>::type>(std::get<ComplexTokenType>(token.type))] << std::endl;
    //         }
    //         else if (std::holds_alternative<SpecialIdentifierType>(token.type)) {
    //             std::cout << bufStr << '\t' << token.index << "\t" << specialIdentifierTypes[static_cast<std::underlying_type<SpecialIdentifierType>::type>(std::get<SpecialIdentifierType>(token.type))] << std::endl;
    //         }
    //     }
    // }
    
    // SyntaxBlock::LoadTokenVector(combinedTokens);
    // std::cout << '\n' << std::endl;
    // std::cout << SyntaxBlock::CFG::String::Check() << std::endl;
    // return 0;
}