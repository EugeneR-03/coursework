#include "Messages.hpp"

// Message

Message::Message()
{
    this->stringIndex = -1;
    this->tokenIndex = -1;
    this->tokenValue = "";
    this->message = "";
}

Message::Message(int stringIndex, int tokenIndex, const std::string& message)
{
    this->stringIndex = stringIndex;
    this->tokenIndex = tokenIndex;
    this->tokenValue = "";
    this->message = message;
}

Message::Message(int stringIndex, int tokenIndex, const std::string& tokenValue, const std::string& message)
{
    this->stringIndex = stringIndex;
    this->tokenIndex = tokenIndex;
    this->tokenValue = tokenValue;
    this->message = message;
}

bool Message::operator<(const Message& other) const
{
    return tokenIndex < other.tokenIndex;
}

bool Message::operator>(const Message& other) const
{
    return tokenIndex > other.tokenIndex;
}

bool Message::operator==(const Message& other) const
{
    return stringIndex == other.stringIndex && 
        tokenIndex == other.tokenIndex && 
        tokenValue == other.tokenValue && 
        message == other.message;
}


// MessagePool

// инициализация по умолчанию
Language MessagePool::language = Language::English;
std::map<std::string, std::string>* MessagePool::other = &MessagePoolEng::other;
std::map<std::string, std::string>* MessagePool::symbol = &MessagePoolRus::symbol;
std::map<std::string, std::string>* MessagePool::specialIdentifier = &MessagePoolRus::specialIdentifier;
std::map<std::string, std::string>* MessagePool::variable = &MessagePoolRus::variable;
std::map<std::string, std::string>* MessagePool::operation = &MessagePoolRus::operation;
std::map<std::string, std::string>* MessagePool::string = &MessagePoolRus::string;
std::map<std::string, std::string>* MessagePool::stringInner = &MessagePoolRus::stringInner;

std::string MessagePool::GetMessage(std::string poolType, std::string message)
{
    if (poolType == "Other")
    {
        return (*MessagePool::other)[message];
    }
    if (poolType == "Symbol")
    {
        return (*MessagePool::symbol)[message];
    }
    else if (poolType == "SpecialIdentifier")
    {
        return (*MessagePool::specialIdentifier)[message];
    }
    else if (poolType == "Variable")
    {
        return (*MessagePool::variable)[message];
    }
    else if (poolType == "Operation")
    {
        return (*MessagePool::operation)[message];
    }
    else if (poolType == "String")
    {
        return (*MessagePool::string)[message];
    }
    else if (poolType == "StringInner")
    {
        return (*MessagePool::stringInner)[message];
    }
    return "";
}

void MessagePool::SwitchPoolToLanguage(Language language)
{
    switch (language)
    {
        case Language::English:
            MessagePool::other = &MessagePoolEng::other;
            MessagePool::symbol = &MessagePoolEng::symbol;
            MessagePool::specialIdentifier = &MessagePoolEng::specialIdentifier;
            MessagePool::variable = &MessagePoolEng::variable;
            MessagePool::operation = &MessagePoolEng::operation;
            MessagePool::string = &MessagePoolEng::string;
            MessagePool::stringInner = &MessagePoolEng::stringInner;
            break;
        case Language::Russian:
            MessagePool::other = &MessagePoolRus::other;
            MessagePool::symbol = &MessagePoolRus::symbol;
            MessagePool::specialIdentifier = &MessagePoolRus::specialIdentifier;
            MessagePool::variable = &MessagePoolRus::variable;
            MessagePool::operation = &MessagePoolRus::operation;
            MessagePool::string = &MessagePoolRus::string;
            MessagePool::stringInner = &MessagePoolRus::stringInner;
            break;
    }
}

// MessagePoolEng

std::map<std::string, std::string> MessagePoolEng::other
{
    {"String", "String"},
    {"Position", "Position"},
    {"Result", "Result"},
    {"Success", "✓ No errors"},
    {"Fail", "☓ There are errors"},
};

std::map<std::string, std::string> MessagePoolEng::symbol
{
    {"OpeningCurlyBrace", "Error: invalid character sequence"},
    {"ClosingCurlyBrace", "Error: invalid character sequence"},
    {"OpeningParenthesis", "Error: invalid character sequence"},
    {"ClosingParenthesis", "Error: invalid character sequence"},
    {"Comma", "Error: invalid character sequence"},
    {"Colon", "Error: invalid character sequence"},
    {"Semicolon", "Error: invalid character sequence"},
    {"QuotationMark", "Error: invalid character sequence"},
    {"EqualSign", "Error: invalid character sequence"},
    {"ComparisonSign", "Error: invalid character sequence"},
    {"ExclamationMark", "Error: invalid character sequence"},
    {"ArithmeticSign", "Error: invalid character sequence"},
    {"LogicalSign", "Error: invalid character sequence"},
};

std::map<std::string, std::string> MessagePoolEng::specialIdentifier
{
    {"Operation", "Error: invalid keyword (operation, 'op')"},
    {"OperandOfUnaryOperation", "Error: invalid keyword (operand of unary operation, 'od')"},
    {"FirstOperandOfBinaryOperation", "Error: invalid keyword (first operand of binary operation, 'fO')"},
    {"SecondOperandOfBinaryOperation", "Error: invalid keyword (second operand of binary operation, 'sO')"},
    {"V", "Error: invalid keyword (v, 'v')"},
    {"No", "Error: invalid keyword (no, 'no')"},
    {"Real", "Error: invalid keyword (real, 'real')"},
    {"Solution", "Error: invalid keyword (solution, 'solution')"},
    {"Modulus", "Error: invalid keyword (modulus, 'abs')"},
    {"SquareOfNumber", "Error: invalid keyword (squaring, 'sqr')"},
    {"SquareRootOfNumber", "Error: invalid keyword (taking the square root, 'sqrt')"},
};

std::map<std::string, std::string> MessagePoolEng::variable
{
    {"Edge", "Error: invalid form of edge (edge examples: 'A(1,2)', 'A(1)')"},
    {"Identifier", "Error: invalid form of identifier"},
    {"Integer", "Error: invalid form of integer"},
    {"Variable", "Error: invalid form of variable"},
};

std::map<std::string, std::string> MessagePoolEng::operation
{
    {"Logical", "Error: invalid form of logical operation"},
    {"Arithmetic", "Error: invalid form of arithmetic operation"},
    {"Operation", "Error: invalid form of operation"},
};

std::map<std::string, std::string> MessagePoolEng::string
{
    {"String", "Error: invalid structure of string"},
    {"Beginning", "Error: invalid start of string beginning"},
    {"Logical", "Error: invalid structure of logical part of string"},
    {"Arithmetic", "Error: invalid structure of arithmetic part of string"},
    {"ArithmeticNoRealSolution", "Error: invalid form of 'no real solution'"},
};

std::map<std::string, std::string> MessagePoolEng::stringInner
{
    {"Operation", "Error: invalid form of operation in string"},
    {"FirstOperandOfBinaryOperation", "Error: invalid form of first operand of binary operation in string"},
    {"SecondOperandOfBinaryOperation", "Error: invalid form of second operand of binary operation in string"},
    {"OperandBinary", "Error: invalid form of operand of binary operation in string"},
    {"OperandUnary", "Error: invalid form of operand of unary operation in string"},
    {"OperandVariable", "Error: invalid form of operand in string"},
    {"Operand", "Error: invalid form of operand in string"},
    {"Inner", "Error: invalid form of inner part of string"},
};

// MessagePoolRus

std::map<std::string, std::string> MessagePoolRus::other
{
    {"String", "Строка"},
    {"Position", "Позиция"},
    {"Result", "Результат"},
    {"Success", "✓ Нет ошибок"},
    {"Fail", "☓ Есть ошибки"},
};

std::map<std::string, std::string> MessagePoolRus::symbol
{
    {"OpeningCurlyBrace", "Ошибка: неверная последовательность символов"},
    {"ClosingCurlyBrace", "Ошибка: неверная последовательность символов"},
    {"OpeningParenthesis", "Ошибка: неверная последовательность символов"},
    {"ClosingParenthesis", "Ошибка: неверная последовательность символов"},
    {"Comma", "Ошибка: неверная последовательность символов"},
    {"Colon", "Ошибка: неверная последовательность символов"},
    {"Semicolon", "Ошибка: неверная последовательность символов"},
    {"QuotationMark", "Ошибка: неверная последовательность символов"},
    {"EqualSign", "Ошибка: неверная последовательность символов"},
    {"ComparisonSign", "Ошибка: неверная последовательность символов"},
    {"ExclamationMark", "Ошибка: неверная последовательность символов"},
    {"ArithmeticSign", "Ошибка: неверная последовательность символов"},
    {"LogicalSign", "Ошибка: неверная последовательность символов"},
};

std::map<std::string, std::string> MessagePoolRus::specialIdentifier
{
    {"Operation", "Ошибка: неверное ключевое слово (операция, 'op')"},
    {"OperandOfUnaryOperation", "Ошибка: неверное ключевое слово (операнд унарной операции, 'od')"},
    {"FirstOperandOfBinaryOperation", "Ошибка: неверное ключевое слово (первый операнд бинарной операции, 'fO')"},
    {"SecondOperandOfBinaryOperation", "Ошибка: неверное ключевое слово (второй операнд бинарной операции, 'sO')"},
    {"V", "Ошибка: неверное ключевое слово (значение, 'v')"},
    {"No", "Ошибка: неверное ключевое слово (нет, 'no')"},
    {"Real", "Ошибка: неверное ключевое слово (реальный, 'real')"},
    {"Solution", "Ошибка: неверное ключевое слово (решение, 'solution')"},
    {"Modulus", "Ошибка: неверное ключевое слово (модуль, 'abs')"},
    {"SquareOfNumber", "Ошибка: неверное ключевое слово (квадрат числа, 'sqr')"},
    {"SquareRootOfNumber", "Ошибка: неверное ключевое слово (квадратный корень числа, 'sqrt')"},
};

std::map<std::string, std::string> MessagePoolRus::variable
{
    {"Edge", "Ошибка: неверный формат грани (примеры граней: 'A(1,2)', 'A(1)')"},
    {"Identifier", "Ошибка: неверный формат идентификатора (примеры идентификаторов: 'x1', 'R124')"},
    {"Integer", "Ошибка: неверный формат целого числа"},
    {"Variable", "Ошибка: неверный формат переменной (переменная - идентификатор, число или грань)"},
};

std::map<std::string, std::string> MessagePoolRus::operation
{
    {"Logical", "Ошибка: неверный формат логической операции"},
    {"Arithmetic", "Ошибка: неверный формат арифметической операции"},
    {"Operation", "Ошибка: неверный формат операции"},
};

std::map<std::string, std::string> MessagePoolRus::string
{
    {"String", "Ошибка: неверный формат строки"},
    {"Beginning", "Ошибка: неверный формат начала строки"},
    {"Logical", "Ошибка: неверный формат логической части строки"},
    {"Arithmetic", "Ошибка: неверный формат арифметической части строки"},
    {"ArithmeticNoRealSolution", "Ошибка: неверный формат арифметической части строки (должно быть: 'no real solution')"},
};

std::map<std::string, std::string> MessagePoolRus::stringInner
{
    {"Operation", "Ошибка: неверный формат операции внутри строки"},
    {"FirstOperandOfBinaryOperation", "Ошибка: неверный формат первого операнда бинарной операции внутри строки"},
    {"SecondOperandOfBinaryOperation", "Ошибка: неверный формат второго операнда бинарной операции внутри строки"},
    {"OperandBinary", "Ошибка: неверный формат операнда бинарной операции внутри строки"},
    {"OperandUnary", "Ошибка: неверный формат операнда унарной операции внутри строки"},
    {"OperandVariable", "Ошибка: неверный формат операнда внутри строки"},
    {"Operand", "Ошибка: неверный формат операнда внутри строки"},
    {"Inner", "Ошибка: неверный формат внутренней части строки"},
};