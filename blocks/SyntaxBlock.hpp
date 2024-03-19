#pragma once

#include <string>
#include <vector>
#include <stack>

#include "Tokens.hpp"

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
    static void LoadToken();
    static VariableToken GetCurrentToken();
    // static void RemoveTokenFromStack();
    // static VariableToken GetAndRemoveTokenFromStack();
    // static void ClearStack();
    static void CancelLoadToken();

    class CFG
    {
    public:
        class Symbol
        {
        public:
            class OpeningCurlyBrace
            {
                static int beginningIndex;
                static void Cancel();
            public:
                static bool Check();
            };
            class ClosingCurlyBrace
            {
                static int beginningIndex;
                static void Cancel();
            public:
                static bool Check();
            };
            class OpeningParenthesis 
            {
                static int beginningIndex;
                static void Cancel();
            public:
                static bool Check();
            };
            class ClosingParenthesis
            {
                static int beginningIndex;
                static void Cancel();
            public:
                static bool Check();
            };
            class Comma
            {
                static int beginningIndex;
                static void Cancel();
            public:
                static bool Check();
            };
            class Colon
            {
                static int beginningIndex;
                static void Cancel();
            public:
                static bool Check();
            };
            class Semicolon
            {
                static int beginningIndex;
                static void Cancel();
            public:
                static bool Check();
            };
            class QuotationMark
            {
                static int beginningIndex;
                static void Cancel();
            public:
                static bool Check();
            };
            class EqualSign
            {
                static int beginningIndex;
                static void Cancel();
            public:
                static bool Check();
            };
            class ComparisonSign
            {
                static int beginningIndex;
                static void Cancel();
            public:
                static bool Check();
            };
            class ExclamationMark
            {
                static int beginningIndex;
                static void Cancel();
            public:
                static bool Check();
            };
            class ArithmeticSign
            {
                static int beginningIndex;
                static void Cancel();
            public:
                static bool Check();
            };
            class LogicalSign
            {
                static int beginningIndex;
                static void Cancel();
            public:
                static bool Check();
            };
        };

        class SpecialIdentifier
        {
        public:
            class Operation
            {
                static int beginningIndex;
                static void Cancel();
            public:
                static bool Check();
            };
            class OperandOfUnaryOperation
            {
                static int beginningIndex;
                static void Cancel();
            public:
                static bool Check();
            };
            class FirstOperandOfBinaryOperation
            {
                static int beginningIndex;
                static void Cancel();
            public:
                static bool Check();
            };
            class SecondOperandOfBinaryOperation
            {
                static int beginningIndex;
                static void Cancel();
            public:
                static bool Check();
            };
            class V
            {
                static int beginningIndex;
                static void Cancel();
            public:
                static bool Check();
            };
            class No
            {
                static int beginningIndex;
                static void Cancel();
            public:
                static bool Check();
            };
            class Real
            {
                static int beginningIndex;
                static void Cancel();
            public:
                static bool Check();
            };
            class Solution
            {
                static int beginningIndex;
                static void Cancel();
            public:
                static bool Check();
            };
            class Modulus
            {
                static int beginningIndex;
                static void Cancel();
            public:
                static bool Check();
            };
            class SquareOfNumber
            {
                static int beginningIndex;
                static void Cancel();
            public:
                static bool Check();
            };
            class SquareRootOfNumber
            {
                static int beginningIndex;
                static void Cancel();
            public:
                static bool Check();
            };
        };

        class Variable
        {
            static int beginningIndex;
            static void Cancel();
        public:
            static bool Check();
            class Edge
            {
                static int beginningIndex;
                static void Cancel();
            public:
                static bool Check();
            };
            class Identifier
            {
                static int beginningIndex;
                static void Cancel();
            public:
                static bool Check();
            };
            class Integer
            {
                static int beginningIndex;
                static void Cancel();
            public:
                static bool Check();
            };
        };

        class Operation
        {
            static int beginningIndex;
            static void Cancel();
        public:
            static bool Check();
            class Logical
            {
                static int beginningIndex;
                static void Cancel();
            public:
                static bool Check();
            };
            class Arithmetic
            {
                static int beginningIndex;
                static void Cancel();
            public:
                static bool Check();
            };
        };

        class String
        {
            static int beginningIndex;
            static void Cancel();
        public:
            static bool Check();
            class Beginning
            {
                static int beginningIndex;
                static void Cancel();
            public:
                static bool Check();
            };
            class Logical
            {
                static int beginningIndex;
                static void Cancel();
            public:
                static bool Check();
            };
            class Arithmetic
            {
                static int beginningIndex;
                static void Cancel();
            public:
                static bool Check();

                class NoRealSolution
                {
                    static int beginningIndex;
                    static void Cancel();
                public:
                    static bool Check();
                };
            };
            class Inner
            {
                static int beginningIndex;
                static void Cancel();
            public:
                static bool Check();
                class Operation
                {
                    static int beginningIndex;
                    static void Cancel();
                public:
                    static bool Check();
                };
                class Operand
                {
                    static int beginningIndex;
                    static void Cancel();
                public:
                    static bool Check();
                    class Unary
                    {
                        static int beginningIndex;
                        static void Cancel();
                    public:
                        static bool Check();
                    };
                    class Binary
                    {
                        static int beginningIndex;
                        static void Cancel();
                    public:
                        static bool Check();
                        class First
                        {
                            static int beginningIndex;
                            static void Cancel();
                        public:
                            static bool Check();
                        };
                        class Second
                        {
                            static int beginningIndex;
                            static void Cancel();
                        public:
                            static bool Check();
                        };
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