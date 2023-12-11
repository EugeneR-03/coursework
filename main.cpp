#include "TransliterationBlock.h"
#include "LexicalBlock.h"
#include "SyntaxBlock.h"
#include <iostream>

int main(int argc, char* argv[])
{
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
        "Modulus",
        "SquareOfNumber",
        "SquareRootOfNumber",
    };

    std::string str = "Hello, World{} 1 != 0; 2>=1";
    std::string str1 = "Raw3(1235)={\"op\":\"!=\",\"fO\":\"A(1,2)\",\"sO\":\"0\"};0";
    std::string str2 = "R(2)={\"op\":\"!=\",\"fO\":\"A(1,2)\",\"sO\":\"0\"};A(1,2)";
    std::string str3 = "R(1)={\"op\":\"==\",\"fO\":\"A(1,2)\",\"sO\":\"0\"};0";
    std::string str4 = "R(2)={\"op\":\"==\",\"fO\":\"A(1,2)\",\"sO\":\"0\"};0";

    std::vector<std::variant<SimpleToken, ComplexToken>> combinedTokens = LexicalBlock::TransliterateString(str1);
    for (int i = 0; i < combinedTokens.size(); i++) {
        std::variant<SimpleToken, ComplexToken> combinedToken = combinedTokens[i];
        if (std::holds_alternative<SimpleToken>(combinedToken)) {
            SimpleToken token = std::get<SimpleToken>(combinedToken);
            char symbol = str1[token.index];
            // std::cout << typeid(token.tokenType).name() << std::endl;
            std::cout << symbol << '\t' << token.index << "\t" << tokenTypes[static_cast<std::underlying_type<SimpleTokenType>::type>(token.type)] << std::endl;
        }
        else {
            ComplexToken token = std::get<ComplexToken>(combinedToken);
            std::string bufStr = str1.substr(token.index, token.value.length());
            if (std::holds_alternative<ComplexTokenType>(token.type)) {
                std::cout << bufStr << '\t' << token.index << "\t" << complexTokenTypes[static_cast<std::underlying_type<ComplexTokenType>::type>(std::get<ComplexTokenType>(token.type))] << std::endl;
            }
            else if (std::holds_alternative<SpecialIdentifierType>(token.type)) {
                std::cout << bufStr << '\t' << token.index << "\t" << specialIdentifierTypes[static_cast<std::underlying_type<SpecialIdentifierType>::type>(std::get<SpecialIdentifierType>(token.type))] << std::endl;
            }
        }
    }
    
    SyntaxBlock::LoadTokenVector(combinedTokens);
    std::cout << SyntaxBlock::CFG::String::Check() << std::endl;
    return 0;
}