#ifndef LEXICALBLOCK_H
#define LEXICALBLOCK_H

#include <string>
#include <vector>
#include "TransliterationBlock.h"

enum class ComplexToken
{
    Identifier,             // идентификатор
    Integer,                // целое число
    ComparisonOperation,       // операция сравнения
    // ArithmeticOperation,
    // LogicalOperation,
};

enum class CombinedToken
{
    Identifier,             // идентификатор
    Integer,                // целое число
    ComparisonOperation,    // операция сравнения
    // ArithmeticOperation,
    // LogicalOperation,

    OpeningCurlyBrace,      // открывающая фигурная скобка ('{')
    ClosingCurlyBrace,      // закрывающая фигурная скобка ('}')
    OpeningParenthesis,     // открывающая круглая скобка ('(')
    ClosingParenthesis,     // закрывающая круглая скобка (')')
    Comma,                  // запятая (',')
    Colon,                  // двоеточие (':')
    Semicolon,              // точка с запятой (';')
    QuotationMark,          // кавычка ('"')
    ArithmeticSign,         // знак арифметической операции ('+', '-', '*', '/')
    LogicalSign,            // знак логической операции ('&' или '|')
    Other,                  // другие символы
};

enum class LexicalBlockState
{
    SPACE_STATE,
    IDENTIFIER_BEGIN,
    IDENTIFIER_END,
    INTEGER,
    ARITHMETIC_OPERATION,
    LOGICAL_OPERATION,
    COMPARISON_OPERATION_BEGIN,
    COMPARISON_OPERATION_END,
};

// класс реализует алгоритм работы ДКА
class LexicalBlock
{
public:
    static std::vector<CombinedToken> TransliterateSimpleTokenVector(std::vector<SimpleToken> tokens);
private:
    static std::vector<CombinedToken> combinedTokenVector;      // итоговый список лексем

    static LexicalBlockState state;     // состояние автомата
    static void Process(SimpleToken token);
    // сложные (составные) лексемы
    static void StartIdentifier(SimpleToken token);
    static void StartInteger(SimpleToken token);
    static void StartComparisonOperation(SimpleToken token);
    // простые (односимвольные) лексемы
    static void StartOpeningCurlyBrace(SimpleToken token);
    static void StartClosingCurlyBrace(SimpleToken token);
    static void StartOpeningParenthesis(SimpleToken token);
    static void StartClosingParenthesis(SimpleToken token);
    static void StartComma(SimpleToken token);
    static void StartColon(SimpleToken token);
    static void StartSemicolon(SimpleToken token);
    static void StartQuotationMark(SimpleToken token);
    static void StartArithmeticSign(SimpleToken token);
    static void StartLogicalSign(SimpleToken token);
    
    static void ProcessSimpleTokenDependingOnState(SimpleToken token);
};

#endif