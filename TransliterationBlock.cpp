#include "TransliterationBlock.h"

SimpleToken TransliterationBlock::TransliterateSymbol(char symbol)
{
    // проверка, является ли символ буквой
    if (std::isalpha(symbol)) {
        return SimpleToken::Letter;
    }

    // проверка, является ли символ цифрой
    else if (std::isdigit(symbol)) {
        return SimpleToken::Digit;
    }

    // проверка на уникальные символы (не буква, не цифра)
    switch (symbol)
    {
        case '{':
            return SimpleToken::OpeningCurlyBrace;
        case '}':
            return SimpleToken::ClosingCurlyBrace;
        case '(':
            return SimpleToken::OpeningParenthesis;
        case ')':
            return SimpleToken::ClosingParenthesis;
        case ',':
            return SimpleToken::Comma;
        case ':':
            return SimpleToken::Colon;
        case ';':
            return SimpleToken::Semicolon;
        case '\"':
            return SimpleToken::QuotationMark;
        case '=':
            return SimpleToken::EqualSign;
        case '>':
        case '<':
            return SimpleToken::ComparisonSign;
        case '!':
            return SimpleToken::ExclamationMark;
        case '+':
        case '-':
        case '*':
        case '/':
            return SimpleToken::ArithmeticSign;
        case '&':
        case '|':
            return SimpleToken::LogicalSign;
        case ' ':
            return SimpleToken::SpaceSign;
        default:
            return SimpleToken::Other;
    }
}

std::vector<SimpleToken> TransliterationBlock::TransliterateString(std::string str)
{
    std::vector<SimpleToken> tokens;
    for (char symbol : str) {
        tokens.push_back(TransliterateSymbol(symbol));
    }
    return tokens;
}