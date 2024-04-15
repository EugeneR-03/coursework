#pragma once

#include <string>
#include <vector>
#include <boost/format.hpp>
#include <boost/signals2.hpp>
#include <boost/bind/bind.hpp>
#include <iostream>

#include "Tokens.hpp"
#include "Messages.hpp"

using VariableToken = std::variant<SimpleToken, ComplexToken>;

enum class SyntaxBlockWorkingMode
{
    UntilFirstError,
    AllErrorsWithoutInner,
    AllErrors,
};

// class CFGHighLevelToken
// {
// public:
//     static bool Identifier();
//     static bool Operation();
//     static bool LogicalOperation();
//     static bool ArithmeticOperation();
// };


// class CFGTemplate
// {
// private:
//     int beginningIndex;
//     virtual void Cancel(bool isSendingSignal) const = 0;
// public:
//     boost::signals2::signal<void (int)> onErrorOccurs;
//     virtual bool Check(bool isSendingSignals = true) = 0;
// };

class SyntaxBlock
{
private:
    static SyntaxBlockWorkingMode workingMode;
    static std::vector<VariableToken> tokenVector;
    static int currentTokenIndexInVector;
    static int stringIndex;
public:
    static SyntaxBlockWorkingMode GetWorkingMode();
    static void SetWorkingMode(SyntaxBlockWorkingMode workingMode);
    static int GetStringIndex();
    static void SetStringIndex(int index);
    static void LoadTokenVector(std::vector<VariableToken> tokenVector);
    static void LoadToken();
    static VariableToken GetCurrentToken();
    static int GetCurrentTokenIndex();
    static void CancelLoadToken();
    static Message MakeMessage(VariableToken token, std::string message);

    class CFG
    {
    public:
        class Symbol
        {
        public:
            class OpeningCurlyBrace
            {
                static int beginningIndex;
            public:
                static boost::signals2::signal<void (Message)> onErrorOccurs;
                static bool Check(bool isSendingSignals = true);
                static void Cancel(bool isSendingSignal = true);
            };
            class ClosingCurlyBrace
            {
                static int beginningIndex;
            public:
                static boost::signals2::signal<void (Message)> onErrorOccurs;
                static bool Check(bool isSendingSignals = true);
                static void Cancel(bool isSendingSignal = true);
            };
            class OpeningParenthesis 
            {
                static int beginningIndex;
            public:
                static boost::signals2::signal<void (Message)> onErrorOccurs;
                static bool Check(bool isSendingSignals = true);
                static void Cancel(bool isSendingSignal = true);
            };
            class ClosingParenthesis
            {
                static int beginningIndex;
            public:
                static boost::signals2::signal<void (Message)> onErrorOccurs;
                static bool Check(bool isSendingSignals = true);
                static void Cancel(bool isSendingSignal = true);
            };
            class Comma
            {
                static int beginningIndex;
            public:
                static boost::signals2::signal<void (Message)> onErrorOccurs;
                static bool Check(bool isSendingSignals = true);
                static void Cancel(bool isSendingSignal = true);
            };
            class Colon
            {
                static int beginningIndex;
            public:
                static boost::signals2::signal<void (Message)> onErrorOccurs;
                static bool Check(bool isSendingSignals = true);
                static void Cancel(bool isSendingSignal = true);
            };
            class Semicolon
            {
                static int beginningIndex;
            public:
                static boost::signals2::signal<void (Message)> onErrorOccurs;
                static bool Check(bool isSendingSignals = true);
                static void Cancel(bool isSendingSignal = true);
            };
            class QuotationMark
            {
                static int beginningIndex;
            public:
                static boost::signals2::signal<void (Message)> onErrorOccurs;
                static bool Check(bool isSendingSignals = true);
                static void Cancel(bool isSendingSignal = true);
            };
            class EqualSign
            {
                static int beginningIndex;
            public:
                static boost::signals2::signal<void (Message)> onErrorOccurs;
                static bool Check(bool isSendingSignals = true);
                static void Cancel(bool isSendingSignal = true);
            };
            class ComparisonSign
            {
                static int beginningIndex;
            public:
                static boost::signals2::signal<void (Message)> onErrorOccurs;
                static bool Check(bool isSendingSignals = true);
                static void Cancel(bool isSendingSignal = true);
            };
            class ExclamationMark
            {
                static int beginningIndex;
            public:
                static boost::signals2::signal<void (Message)> onErrorOccurs;
                static bool Check(bool isSendingSignals = true);
                static void Cancel(bool isSendingSignal = true);
            };
            class ArithmeticSign
            {
                static int beginningIndex;
            public:
                static boost::signals2::signal<void (Message)> onErrorOccurs;
                static bool Check(bool isSendingSignals = true);
                static void Cancel(bool isSendingSignal = true);
            };
            class LogicalSign
            {
                static int beginningIndex;
            public:
                static boost::signals2::signal<void (Message)> onErrorOccurs;
                static bool Check(bool isSendingSignals = true);
                static void Cancel(bool isSendingSignal = true);
            };
        };

        class SpecialIdentifier
        {
        public:
            class Operation
            {
                static int beginningIndex;
            public:
                static boost::signals2::signal<void (Message)> onErrorOccurs;
                static bool Check(bool isSendingSignals = true);
                static void Cancel(bool isSendingSignal = true);
            };
            class OperandOfUnaryOperation
            {
                static int beginningIndex;
            public:
                static boost::signals2::signal<void (Message)> onErrorOccurs;
                static bool Check(bool isSendingSignals = true);
                static void Cancel(bool isSendingSignal = true);
            };
            class FirstOperandOfBinaryOperation
            {
                static int beginningIndex;
            public:
                static boost::signals2::signal<void (Message)> onErrorOccurs;
                static bool Check(bool isSendingSignals = true);
                static void Cancel(bool isSendingSignal = true);
            };
            class SecondOperandOfBinaryOperation
            {
                static int beginningIndex;
            public:
                static boost::signals2::signal<void (Message)> onErrorOccurs;
                static bool Check(bool isSendingSignals = true);
                static void Cancel(bool isSendingSignal = true);
            };
            class V
            {
                static int beginningIndex;
            public:
                static boost::signals2::signal<void (Message)> onErrorOccurs;
                static bool Check(bool isSendingSignals = true);
                static void Cancel(bool isSendingSignal = true);
            };
            class No
            {
                static int beginningIndex;
            public:
                static boost::signals2::signal<void (Message)> onErrorOccurs;
                static bool Check(bool isSendingSignals = true);
                static void Cancel(bool isSendingSignal = true);
            };
            class Real
            {
                static int beginningIndex;
            public:
                static boost::signals2::signal<void (Message)> onErrorOccurs;
                static bool Check(bool isSendingSignals = true);
                static void Cancel(bool isSendingSignal = true);
            };
            class Solution
            {
                static int beginningIndex;
            public:
                static boost::signals2::signal<void (Message)> onErrorOccurs;
                static bool Check(bool isSendingSignals = true);
                static void Cancel(bool isSendingSignal = true);
            };
            class Modulus
            {
                static int beginningIndex;
            public:
                static boost::signals2::signal<void (Message)> onErrorOccurs;
                static bool Check(bool isSendingSignals = true);
                static void Cancel(bool isSendingSignal = true);
            };
            class SquareOfNumber
            {
                static int beginningIndex;
            public:
                static boost::signals2::signal<void (Message)> onErrorOccurs;
                static bool Check(bool isSendingSignals = true);
                static void Cancel(bool isSendingSignal = true);
            };
            class SquareRootOfNumber
            {
                static int beginningIndex;
            public:
                static boost::signals2::signal<void (Message)> onErrorOccurs;
                static bool Check(bool isSendingSignals = true);
                static void Cancel(bool isSendingSignal = true);
            };
        };

        class Variable
        {
            static int beginningIndex;
        public:
            static boost::signals2::signal<void (Message)> onErrorOccurs;
            static bool Check(bool isSendingSignals = true);
            static void Cancel(bool isSendingSignal = true);
            class Edge
            {
                static int beginningIndex;
            public:
                static boost::signals2::signal<void (Message)> onErrorOccurs;
                static bool Check(bool isSendingSignals = true);
                static void Cancel(bool isSendingSignal = true);
            };
            class Identifier
            {
                static int beginningIndex;
            public:
                static boost::signals2::signal<void (Message)> onErrorOccurs;
                static bool Check(bool isSendingSignals = true);
                static void Cancel(bool isSendingSignal = true);
            };
            class Integer
            {
                static int beginningIndex;
            public:
                static boost::signals2::signal<void (Message)> onErrorOccurs;
                static bool Check(bool isSendingSignals = true);
                static void Cancel(bool isSendingSignal = true);
            };
        };

        class Operation
        {
            static int beginningIndex;
        public:
            static boost::signals2::signal<void (Message)> onErrorOccurs;
            static bool Check(bool isSendingSignals = true);
            static void Cancel(bool isSendingSignal = true);
            class Logical
            {
                static int beginningIndex;
            public:
                static boost::signals2::signal<void (Message)> onErrorOccurs;
                static bool Check(bool isSendingSignals = true);
                static void Cancel(bool isSendingSignal = true);
            };
            class Arithmetic
            {
                static int beginningIndex;
            public:
                static boost::signals2::signal<void (Message)> onErrorOccurs;
                static bool Check(bool isSendingSignals = true);
                static void Cancel(bool isSendingSignal = true);
            };
        };

        class String
        {
            static int beginningIndex;
        public:
            static boost::signals2::signal<void (Message)> onErrorOccurs;
            static bool Check(bool isSendingSignals = true);
            static void Cancel(bool isSendingSignal = true);
            static void CheckAllInnerParts(bool isSendingSignals = true, bool isCheckingInner = false);

            class Beginning
            {
                static int beginningIndex;
            public:
                static boost::signals2::signal<void (Message)> onErrorOccurs;
                static bool Check(bool isSendingSignals = true);
                static void Cancel(bool isSendingSignal = true);
            };
            class Logical
            {
                static int beginningIndex;
            public:
                static boost::signals2::signal<void (Message)> onErrorOccurs;
                static bool Check(bool isSendingSignals = true, bool isCheckingInner = true);
                static void Cancel(bool isSendingSignal = true);
            };
            class Arithmetic
            {
                static int beginningIndex;
            public:
                static boost::signals2::signal<void (Message)> onErrorOccurs;
                static bool Check(bool isSendingSignals = true, bool isCheckingInner = true);
                static void Cancel(bool isSendingSignal = true);

                class NoRealSolution
                {
                    static int beginningIndex;
                public:
                    static boost::signals2::signal<void (Message)> onErrorOccurs;
                    static bool Check(bool isSendingSignals = true);
                    static void Cancel(bool isSendingSignal = true);
                };
            };
            class Inner
            {
                static int beginningIndex;
            public:
                static boost::signals2::signal<void (Message)> onErrorOccurs;
                static bool Check(bool isSendingSignals = true);
                static void Cancel(bool isSendingSignal = true);
                class Operation
                {
                    static int beginningIndex;
                public:
                    static boost::signals2::signal<void (Message)> onErrorOccurs;
                    static bool Check(bool isSendingSignals = true);
                    static void Cancel(bool isSendingSignal = true);
                };
                class Operand
                {
                    static int beginningIndex;
                public:
                    static boost::signals2::signal<void (Message)> onErrorOccurs;
                    static bool Check(bool isSendingSignals = true, bool isCheckingInner = true);
                    static void Cancel(bool isSendingSignal = true);

                    class Variable
                    {
                        static int beginningIndex;
                    public:
                        static boost::signals2::signal<void (Message)> onErrorOccurs;
                        static bool Check(bool isSendingSignals = true, bool isCheckingInner = true);
                        static void Cancel(bool isSendingSignal = true);
                    };
                    class Unary
                    {
                        static int beginningIndex;
                    public:
                        static boost::signals2::signal<void (Message)> onErrorOccurs;
                        static bool Check(bool isSendingSignals = true, bool isCheckingInner = true);
                        static void Cancel(bool isSendingSignal = true);
                    };
                    class Binary
                    {
                        static int beginningIndex;
                    public:
                        static boost::signals2::signal<void (Message)> onErrorOccurs;
                        static bool Check(bool isSendingSignals = true, bool isCheckingInner = true);
                        static void Cancel(bool isSendingSignal = true);
                        class First
                        {
                            static int beginningIndex;
                        public:
                            static boost::signals2::signal<void (Message)> onErrorOccurs;
                            static bool Check(bool isSendingSignals = true, bool isCheckingInner = true);
                            static void Cancel(bool isSendingSignal = true);
                        };
                        class Second
                        {
                            static int beginningIndex;
                        public:
                            static boost::signals2::signal<void (Message)> onErrorOccurs;
                            static bool Check(bool isSendingSignals = true, bool isCheckingInner = true);
                            static void Cancel(bool isSendingSignal = true);
                        };
                    };
                };
            };
        };
    };    
};