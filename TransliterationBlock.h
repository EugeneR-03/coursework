#ifndef TRANSLITERATIONBLOCK_H
#define TRANSLITERATIONBLOCK_H

#include <string>
#include <vector>

enum class SimpleToken {
    Letter,                 // буква ('A'..'Z', 'a'..'z')
    Digit,                  // цифра ('0'..'9')
    OpeningCurlyBrace,      // открывающая фигурная скобка ('{')
    ClosingCurlyBrace,      // закрывающая фигурная скобка ('}')
    OpeningParenthesis,     // открывающая круглая скобка ('(')
    ClosingParenthesis,     // закрывающая круглая скобка (')')
    Comma,                  // запятая (',')
    Colon,                  // двоеточие (':')
    Semicolon,              // точка с запятой (';')
    QuotationMark,          // кавычка ('"')
    EqualSign,              // равно ('=')
    ComparisonSign,         // знак сравнения ('>', '<') 
    ExclamationMark,        // восклицательная знак ('!')
    ArithmeticSign,         // знак арифметическое операции ('+', '-', '*', '/')
    LogicalSign,            // знак логической операции ('&' или '|')
    SpaceSign,              // пробел (' ')
    Other,                  // другие символы
};

class TransliterationBlock
{
public:
    static SimpleToken TransliterateSymbol(char symbol);
    static std::vector<SimpleToken> TransliterateString(std::string str);
};


#endif