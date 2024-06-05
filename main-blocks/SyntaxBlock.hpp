#pragma once

#include <string>
#include <vector>
#include <boost/format.hpp>
#include <boost/signals2.hpp>
#include <boost/bind/bind.hpp>
#include <iostream>
#include <omp.h>

#include "./../base-blocks/Tokens.hpp"
#include "./../base-blocks/Messages.hpp"
#include "LexicalBlock.hpp"

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

class SyntaxBlock;

class CFGTemplate
{
protected:
    SyntaxBlock* syntaxBlock;
    int beginningIndex = 0;
public:
    CFGTemplate(SyntaxBlock* syntaxBlock);
    virtual void Cancel(bool isSendingSignal = true) = 0;
    virtual bool Check(bool isSendingSignals = true) = 0;
};

class CFGTemplateInner
{
protected:
    SyntaxBlock* syntaxBlock;
    int beginningIndex = 0;
public:
    CFGTemplateInner(SyntaxBlock* syntaxBlock);
    virtual void Cancel(bool isSendingSignal = true) = 0;
    virtual bool Check(bool isSendingSignals = true, bool isCheckingInner = true) = 0;
};

// class CFGTemplateInner : public CFGTemplate
// {
// public:
//     using CFGTemplate::CFGTemplate;
//     virtual bool Check(bool isSendingSignals = true, bool isCheckingInner = true) = 0;
// };

class SyntaxBlock
{
private:
    static omp_lock_t lock;
    SyntaxBlockWorkingMode workingMode;
    std::vector<VariableToken> tokenVector;
    int currentTokenIndexInVector;
    int stringIndex;
public:
    SyntaxBlock(SyntaxBlockWorkingMode workingMode = SyntaxBlockWorkingMode::UntilFirstError);
    ~SyntaxBlock();
    static void InitLock();
    SyntaxBlockWorkingMode GetWorkingMode();
    void SetWorkingMode(SyntaxBlockWorkingMode workingMode);
    int GetStringIndex();
    void SetStringIndex(int index);
    void LoadTokenVector(const std::vector<VariableToken>& tokenVector);
    void LoadToken();
    VariableToken GetCurrentToken();
    int GetCurrentTokenIndex();
    void CancelLoadToken();
    Message MakeMessage(const VariableToken& token, const std::string& message);
    bool CheckTokenVector(const std::vector<std::variant<SimpleToken, ComplexToken>>& combinedTokens, SyntaxBlockWorkingMode workingMode);

    class CFG
    {
    public:
        class Symbol
        {
        public:
            class OpeningCurlyBrace : public CFGTemplate
            {
            public:
                static boost::signals2::signal<void (const Message&)> onErrorOccurs;
                using CFGTemplate::CFGTemplate;
                bool Check(bool isSendingSignals = true) override;
                void Cancel(bool isSendingSignal = true) override;
            };
            class ClosingCurlyBrace : public CFGTemplate
            {
            public:
                static boost::signals2::signal<void (const Message&)> onErrorOccurs;
                using CFGTemplate::CFGTemplate;
                bool Check(bool isSendingSignals = true) override;
                void Cancel(bool isSendingSignal = true) override;
            };
            class OpeningParenthesis : public CFGTemplate
            {
            public:
                static boost::signals2::signal<void (const Message&)> onErrorOccurs;
                using CFGTemplate::CFGTemplate;
                bool Check(bool isSendingSignals = true) override;
                void Cancel(bool isSendingSignal = true) override;
            };
            class ClosingParenthesis : public CFGTemplate
            {
            public:
                static boost::signals2::signal<void (const Message&)> onErrorOccurs;
                using CFGTemplate::CFGTemplate;
                bool Check(bool isSendingSignals = true) override;
                void Cancel(bool isSendingSignal = true) override;
            };
            class Comma : public CFGTemplate
            {
            public:
                static boost::signals2::signal<void (const Message&)> onErrorOccurs;
                using CFGTemplate::CFGTemplate;
                bool Check(bool isSendingSignals = true) override;
                void Cancel(bool isSendingSignal = true) override;
            };
            class Colon : public CFGTemplate
            {
            public:
                static boost::signals2::signal<void (const Message&)> onErrorOccurs;
                using CFGTemplate::CFGTemplate;
                bool Check(bool isSendingSignals = true) override;
                void Cancel(bool isSendingSignal = true) override;
            };
            class Semicolon : public CFGTemplate
            {
            public:
                static boost::signals2::signal<void (const Message&)> onErrorOccurs;
                using CFGTemplate::CFGTemplate;
                bool Check(bool isSendingSignals = true) override;
                void Cancel(bool isSendingSignal = true) override;
            };
            class QuotationMark : public CFGTemplate
            {
            public:
                static boost::signals2::signal<void (const Message&)> onErrorOccurs;
                using CFGTemplate::CFGTemplate;
                bool Check(bool isSendingSignals = true) override;
                void Cancel(bool isSendingSignal = true) override;
            };
            class EqualSign : public CFGTemplate
            {
            public:
                static boost::signals2::signal<void (const Message&)> onErrorOccurs;
                using CFGTemplate::CFGTemplate;
                bool Check(bool isSendingSignals = true) override;
                void Cancel(bool isSendingSignal = true) override;
            };
            class ComparisonSign : public CFGTemplate
            {
            public:
                static boost::signals2::signal<void (const Message&)> onErrorOccurs;
                using CFGTemplate::CFGTemplate;
                bool Check(bool isSendingSignals = true) override;
                void Cancel(bool isSendingSignal = true) override;
            };
            class ExclamationMark : public CFGTemplate
            {
            public:
                static boost::signals2::signal<void (const Message&)> onErrorOccurs;
                using CFGTemplate::CFGTemplate;
                bool Check(bool isSendingSignals = true) override;
                void Cancel(bool isSendingSignal = true) override;
            };
            class ArithmeticSign : public CFGTemplate
            {
            public:
                static boost::signals2::signal<void (const Message&)> onErrorOccurs;
                using CFGTemplate::CFGTemplate;
                bool Check(bool isSendingSignals = true) override;
                void Cancel(bool isSendingSignal = true) override;
            };
            class LogicalSign : public CFGTemplate
            {
            public:
                static boost::signals2::signal<void (const Message&)> onErrorOccurs;
                using CFGTemplate::CFGTemplate;
                bool Check(bool isSendingSignals = true) override;
                void Cancel(bool isSendingSignal = true) override;
            };
        };

        class SpecialIdentifier
        {
        public:
            class Operation : public CFGTemplate
            {
            public:
                static boost::signals2::signal<void (const Message&)> onErrorOccurs;
                using CFGTemplate::CFGTemplate;
                bool Check(bool isSendingSignals = true) override;
                void Cancel(bool isSendingSignal = true) override;
            };
            class OperandOfUnaryOperation : public CFGTemplate
            {
            public:
                static boost::signals2::signal<void (const Message&)> onErrorOccurs;
                using CFGTemplate::CFGTemplate;
                bool Check(bool isSendingSignals = true) override;
                void Cancel(bool isSendingSignal = true) override;
            };
            class FirstOperandOfBinaryOperation : public CFGTemplate
            {
            public:
                static boost::signals2::signal<void (const Message&)> onErrorOccurs;
                using CFGTemplate::CFGTemplate;
                bool Check(bool isSendingSignals = true) override;
                void Cancel(bool isSendingSignal = true) override;
            };
            class SecondOperandOfBinaryOperation : public CFGTemplate
            {
            public:
                static boost::signals2::signal<void (const Message&)> onErrorOccurs;
                using CFGTemplate::CFGTemplate;
                bool Check(bool isSendingSignals = true) override;
                void Cancel(bool isSendingSignal = true) override;
            };
            class V : public CFGTemplate
            {
            public:
                static boost::signals2::signal<void (const Message&)> onErrorOccurs;
                using CFGTemplate::CFGTemplate;
                bool Check(bool isSendingSignals = true) override;
                void Cancel(bool isSendingSignal = true) override;
            };
            class No : public CFGTemplate
            {
            public:
                static boost::signals2::signal<void (const Message&)> onErrorOccurs;
                using CFGTemplate::CFGTemplate;
                bool Check(bool isSendingSignals = true) override;
                void Cancel(bool isSendingSignal = true) override;
            };
            class Real : public CFGTemplate
            {
            public:
                static boost::signals2::signal<void (const Message&)> onErrorOccurs;
                using CFGTemplate::CFGTemplate;
                bool Check(bool isSendingSignals = true) override;
                void Cancel(bool isSendingSignal = true) override;
            };
            class Solution : public CFGTemplate
            {
            public:
                static boost::signals2::signal<void (const Message&)> onErrorOccurs;
                using CFGTemplate::CFGTemplate;
                bool Check(bool isSendingSignals = true) override;
                void Cancel(bool isSendingSignal = true) override;
            };
            class Modulus : public CFGTemplate
            {
            public:
                static boost::signals2::signal<void (const Message&)> onErrorOccurs;
                using CFGTemplate::CFGTemplate;
                bool Check(bool isSendingSignals = true) override;
                void Cancel(bool isSendingSignal = true) override;
            };
            class SquareOfNumber : public CFGTemplate
            {
            public:
                static boost::signals2::signal<void (const Message&)> onErrorOccurs;
                using CFGTemplate::CFGTemplate;
                bool Check(bool isSendingSignals = true) override;
                void Cancel(bool isSendingSignal = true) override;
            };
            class SquareRootOfNumber : public CFGTemplate
            {
            public:
                static boost::signals2::signal<void (const Message&)> onErrorOccurs;
                using CFGTemplate::CFGTemplate;
                bool Check(bool isSendingSignals = true) override;
                void Cancel(bool isSendingSignal = true) override;
            };
        };

        class Variable : public CFGTemplate
        {
        public:
            static boost::signals2::signal<void (const Message&)> onErrorOccurs;
            using CFGTemplate::CFGTemplate;
            bool Check(bool isSendingSignals = true) override;
            void Cancel(bool isSendingSignal = true) override;
            class Edge : public CFGTemplate
            {
            public:
                static boost::signals2::signal<void (const Message&)> onErrorOccurs;
                using CFGTemplate::CFGTemplate;
                bool Check(bool isSendingSignals = true) override;
                void Cancel(bool isSendingSignal = true) override;
            };
            class Identifier : public CFGTemplate
            {
            public:
                static boost::signals2::signal<void (const Message&)> onErrorOccurs;
                using CFGTemplate::CFGTemplate;
                bool Check(bool isSendingSignals = true) override;
                void Cancel(bool isSendingSignal = true) override;
            };
            class Integer : public CFGTemplate
            {
            public:
                static boost::signals2::signal<void (const Message&)> onErrorOccurs;
                using CFGTemplate::CFGTemplate;
                bool Check(bool isSendingSignals = true) override;
                void Cancel(bool isSendingSignal = true) override;
            };
        };

        class Operation : public CFGTemplate
        {
        public:
            static boost::signals2::signal<void (const Message&)> onErrorOccurs;
            using CFGTemplate::CFGTemplate;
            bool Check(bool isSendingSignals = true) override;
            void Cancel(bool isSendingSignal = true) override;
            class Logical : public CFGTemplate
            {
            public:
                static boost::signals2::signal<void (const Message&)> onErrorOccurs;
                using CFGTemplate::CFGTemplate;
                bool Check(bool isSendingSignals = true) override;
                void Cancel(bool isSendingSignal = true) override;
            };
            class Arithmetic : public CFGTemplate
            {
            public:
                static boost::signals2::signal<void (const Message&)> onErrorOccurs;
                using CFGTemplate::CFGTemplate;
                bool Check(bool isSendingSignals = true) override;
                void Cancel(bool isSendingSignal = true) override;
            };
        };

        class String : public CFGTemplate
        {
        public:
            static boost::signals2::signal<void (const Message&)> onErrorOccurs;
            using CFGTemplate::CFGTemplate;
            bool Check(bool isSendingSignals = true) override;
            void Cancel(bool isSendingSignal = true) override;
            void CheckAllInnerParts(bool isSendingSignals = true, bool isCheckingInner = false);

            class Beginning : public CFGTemplate
            {
            public:
                static boost::signals2::signal<void (const Message&)> onErrorOccurs;
                using CFGTemplate::CFGTemplate;
                bool Check(bool isSendingSignals = true) override;
                void Cancel(bool isSendingSignal = true) override;
            };
            class Logical : public CFGTemplateInner
            {
            public:
                static boost::signals2::signal<void (const Message&)> onErrorOccurs;
                using CFGTemplateInner::CFGTemplateInner;
                bool Check(bool isSendingSignals = true, bool isCheckingInner = true) override;
                void Cancel(bool isSendingSignal = true) override;
            };
            class Arithmetic : public CFGTemplateInner
            {
            public:
                static boost::signals2::signal<void (const Message&)> onErrorOccurs;
                using CFGTemplateInner::CFGTemplateInner;
                bool Check(bool isSendingSignals = true, bool isCheckingInner = true) override;
                void Cancel(bool isSendingSignal = true) override;

                class NoRealSolution : public CFGTemplate
                {
                public:
                    static boost::signals2::signal<void (const Message&)> onErrorOccurs;
                    using CFGTemplate::CFGTemplate;
                    bool Check(bool isSendingSignals = true) override;
                    void Cancel(bool isSendingSignal = true) override;
                };
            };
            class Inner : public CFGTemplate
            {
            public:
                static boost::signals2::signal<void (const Message&)> onErrorOccurs;
                using CFGTemplate::CFGTemplate;
                bool Check(bool isSendingSignals = true) override;
                void Cancel(bool isSendingSignal = true) override;
                class Operation : public CFGTemplate
                {
                public:
                    static boost::signals2::signal<void (const Message&)> onErrorOccurs;
                    using CFGTemplate::CFGTemplate;
                    bool Check(bool isSendingSignals = true) override;
                    void Cancel(bool isSendingSignal = true) override;
                };
                class Operand : public CFGTemplateInner
                {
                public:
                    static boost::signals2::signal<void (const Message&)> onErrorOccurs;
                    using CFGTemplateInner::CFGTemplateInner;
                    bool Check(bool isSendingSignals = true, bool isCheckingInner = true) override;
                    void Cancel(bool isSendingSignal = true) override;

                    class Variable : public CFGTemplateInner
                    {
                    public:
                        static boost::signals2::signal<void (const Message&)> onErrorOccurs;
                        using CFGTemplateInner::CFGTemplateInner;
                        bool Check(bool isSendingSignals = true, bool isCheckingInner = true) override;
                        void Cancel(bool isSendingSignal = true) override;
                    };
                    class Unary : public CFGTemplateInner
                    {
                    public:
                        static boost::signals2::signal<void (const Message&)> onErrorOccurs;
                        using CFGTemplateInner::CFGTemplateInner;
                        bool Check(bool isSendingSignals = true, bool isCheckingInner = true) override;
                        void Cancel(bool isSendingSignal = true) override;
                    };
                    class Binary : public CFGTemplateInner
                    {
                    public:
                        static boost::signals2::signal<void (const Message&)> onErrorOccurs;
                        using CFGTemplateInner::CFGTemplateInner;
                        bool Check(bool isSendingSignals = true, bool isCheckingInner = true) override;
                        void Cancel(bool isSendingSignal = true) override;
                        class First : public CFGTemplateInner
                        {
                        public:
                            static boost::signals2::signal<void (const Message&)> onErrorOccurs;
                            using CFGTemplateInner::CFGTemplateInner;
                            bool Check(bool isSendingSignals = true, bool isCheckingInner = true) override;
                            void Cancel(bool isSendingSignal = true) override;
                        };
                        class Second : public CFGTemplateInner
                        {
                        public:
                            static boost::signals2::signal<void (const Message&)> onErrorOccurs;
                            using CFGTemplateInner::CFGTemplateInner;
                            bool Check(bool isSendingSignals = true, bool isCheckingInner = true) override;
                            void Cancel(bool isSendingSignal = true) override;
                        };
                    };
                };
            };
        };
    };    
};