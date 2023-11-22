#include "TransliterationBlock.cpp"
#include "LexicalBlock.cpp"
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

    const char* combinedTokenTypes[] = {
        "Identifier",             // идентификатор
        "Integer",                // целое число
        "LogicalOperation",    // операция сравнения
        // ArithmeticOperation,
        // LogicalOperation,

        "OpeningCurlyBrace",      // открывающая фигурная скобка ('{')
        "ClosingCurlyBrace",      // закрывающая фигурная скобка ('}')
        "OpeningParenthesis",     // открывающая круглая скобка ('(')
        "ClosingParenthesis",     // закрывающая круглая скобка (')')
        "Comma",                  // запятая (',')
        "Colon",                  // двоеточие (':')
        "Semicolon",              // точка с запятой (';')
        "QuotationMark",          // кавычка ('"')
        "ArithmeticSign",         // знак арифметической операции ('+', '-', '*', '/')
        "Other",                  // другие символы
    };

    std::string str = "Hello, World{} 1 != 0; 2>=1";
    // std::string str1 = 
    // "Hello, World!\n"
    // "I'm glad to see you again!\n"
    // "2>1; 9<<2; 3>=8;\n"
    // "1+1=2; 3*3=9; 4/2=2;\n"
    // "1&1=1; 1&0=0; 1|1=1; 1|0=1;";
    std::string str1 = "R(1)={\"op\":\"!=\",\"fO\":\"A(1,2)\",\"sO\":\"0\"};0";
    std::string str2 = "R(2)={\"op\":\"!=\",\"fO\":\"A(1,2)\",\"sO\":\"0\"};A(1,2)";
    std::string str3 = "R(1)={\"op\":\"==\",\"fO\":\"A(1,2)\",\"sO\":\"0\"};0";
    std::string str4 = "R(2)={\"op\":\"==\",\"fO\":\"A(1,2)\",\"sO\":\"0\"};0";
    std::vector<SimpleToken> tokens = TransliterationBlock::TransliterateString(str1);

    int i = 0;
    for (SimpleToken token: tokens) {
        std::cout << str1[i++] << '\t' << tokenTypes[static_cast<std::underlying_type<SimpleToken>::type>(token)] << std::endl;
    }

    std::cout << "" << std::endl;
    std::vector<CombinedToken> combinedTokens = LexicalBlock::TransliterateSimpleTokenVector(tokens);
    for (CombinedToken combinedToken: combinedTokens) {
        std::cout << combinedTokenTypes[static_cast<std::underlying_type<CombinedToken>::type>(combinedToken)] << std::endl;
    }
    return 0;
}