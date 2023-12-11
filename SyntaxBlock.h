#pragma once

#include <string>
#include <vector>
#include <stack>

#include "Tokens.h"

using VariableToken = std::variant<SimpleToken, ComplexToken>;

class CFGHighLevelToken
{
public:
    static bool Identifier();
    static bool Operation();
    static bool LogicalOperation();
    static bool ArithmeticOperation();
};

class SyntaxBlock
{
public:
    static void LoadTokenVector(std::vector<VariableToken> tokenVector);
    static void LoadTokenIntoStack();
    static VariableToken GetTokenFromStack();
    static void RemoveTokenFromStack();
    static VariableToken GetAndRemoveTokenFromStack();
    static void ClearStack();
    static void CancelLoadTokenIntoStack();

    class CFG
    {
    public:
        struct Symbol
        {
            struct OpeningCurlyBrace { static bool Check(); };
            struct ClosingCurlyBrace { static bool Check(); };
            struct OpeningParenthesis { static bool Check(); };
            struct ClosingParenthesis { static bool Check(); };
            struct Comma { static bool Check(); };
            struct Colon { static bool Check(); };
            struct Semicolon { static bool Check(); };
            struct QuotationMark { static bool Check(); };
            struct EqualSign { static bool Check(); };
            struct ComparisonSign { static bool Check(); };
            struct ExclamationMark { static bool Check(); };
            struct ArithmeticSign { static bool Check(); };
            struct LogicalSign { static bool Check(); };
        };

        struct SpecialIdentifier
        {
            struct Operation { static bool Check(); };
            struct OperandOfUnaryOperation { static bool Check(); };
            struct FirstOperandOfBinaryOperation { static bool Check(); };
            struct SecondOperandOfBinaryOperation { static bool Check(); };
            struct Modulus { static bool Check(); };
            struct SquareOfNumber { static bool Check(); };
            struct SquareRootOfNumber { static bool Check(); };
        };

        struct Variable
        {
            static bool Check();
            struct Edge { static bool Check(); };
            struct Identifier { static bool Check(); };
            struct Integer { static bool Check(); };
        };

        struct Operation
        {
            static bool Check();
            struct Logical { static bool Check(); };
            struct Arithmetic { static bool Check(); };
        };

        struct String
        {
            static bool Check();
            struct Beginning { static bool Check(); };
            struct Logical { static bool Check(); };
            struct Arithmetic { static bool Check(); };
            struct Inner
            {
                static bool Check();
                struct Operation { static bool Check(); };
                struct Operand
                {
                    static bool Check();
                    struct Unary { static bool Check(); };
                    struct Binary
                    {
                        static bool Check();
                        struct First { static bool Check(); };
                        struct Second { static bool Check(); };
                    };
                };
            };
        };
    };    

private:
    static std::stack<VariableToken> tokenStack;
    static std::vector<VariableToken> tokenVector;
    static int currentTokenIndexInVector;
};