#include "SyntaxBlock.hpp"

using VariableToken = std::variant<SimpleToken, ComplexToken>;

CFGTemplate::CFGTemplate(SyntaxBlock* syntaxBlock) : syntaxBlock(syntaxBlock) {}

CFGTemplateInner::CFGTemplateInner(SyntaxBlock* syntaxBlock) : syntaxBlock(syntaxBlock) {}

// CFGTemplateInner::CFGTemplateInner(SyntaxBlock* syntaxBlock) : syntaxBlock(syntaxBlock) {}

// SyntaxBlockWorkingMode SyntaxBlock::workingMode = SyntaxBlockWorkingMode::UntilFirstError;
// std::vector<VariableToken> SyntaxBlock::tokenVector;
// int SyntaxBlock::currentTokenIndexInVector = 0;
// int SyntaxBlock::stringIndex = 0;

// int SyntaxBlock::CFG::Symbol::OpeningCurlyBrace::beginningIndex;
boost::signals2::signal<void (Message)> SyntaxBlock::CFG::Symbol::OpeningCurlyBrace::onErrorOccurs;

// int SyntaxBlock::CFG::Symbol::ClosingCurlyBrace::beginningIndex;
boost::signals2::signal<void (Message)> SyntaxBlock::CFG::Symbol::ClosingCurlyBrace::onErrorOccurs;

// int SyntaxBlock::CFG::Symbol::OpeningParenthesis::beginningIndex;
boost::signals2::signal<void (Message)> SyntaxBlock::CFG::Symbol::OpeningParenthesis::onErrorOccurs;

// int SyntaxBlock::CFG::Symbol::ClosingParenthesis::beginningIndex;
boost::signals2::signal<void (Message)> SyntaxBlock::CFG::Symbol::ClosingParenthesis::onErrorOccurs;

// int SyntaxBlock::CFG::Symbol::Comma::beginningIndex;
boost::signals2::signal<void (Message)> SyntaxBlock::CFG::Symbol::Comma::onErrorOccurs;

// int SyntaxBlock::CFG::Symbol::Colon::beginningIndex;
boost::signals2::signal<void (Message)> SyntaxBlock::CFG::Symbol::Colon::onErrorOccurs;

// int SyntaxBlock::CFG::Symbol::Semicolon::beginningIndex;
boost::signals2::signal<void (Message)> SyntaxBlock::CFG::Symbol::Semicolon::onErrorOccurs;

// int SyntaxBlock::CFG::Symbol::QuotationMark::beginningIndex;
boost::signals2::signal<void (Message)> SyntaxBlock::CFG::Symbol::QuotationMark::onErrorOccurs;

// int SyntaxBlock::CFG::Symbol::EqualSign::beginningIndex;
boost::signals2::signal<void (Message)> SyntaxBlock::CFG::Symbol::EqualSign::onErrorOccurs;

// int SyntaxBlock::CFG::Symbol::ComparisonSign::beginningIndex;
boost::signals2::signal<void (Message)> SyntaxBlock::CFG::Symbol::ComparisonSign::onErrorOccurs;

// int SyntaxBlock::CFG::Symbol::ExclamationMark::beginningIndex;
boost::signals2::signal<void (Message)> SyntaxBlock::CFG::Symbol::ExclamationMark::onErrorOccurs;

// int SyntaxBlock::CFG::Symbol::ArithmeticSign::beginningIndex;
boost::signals2::signal<void (Message)> SyntaxBlock::CFG::Symbol::ArithmeticSign::onErrorOccurs;

// int SyntaxBlock::CFG::Symbol::LogicalSign::beginningIndex;
boost::signals2::signal<void (Message)> SyntaxBlock::CFG::Symbol::LogicalSign::onErrorOccurs;

// int SyntaxBlock::CFG::SpecialIdentifier::Operation::beginningIndex;
boost::signals2::signal<void (Message)> SyntaxBlock::CFG::SpecialIdentifier::Operation::onErrorOccurs;

// int SyntaxBlock::CFG::SpecialIdentifier::OperandOfUnaryOperation::beginningIndex;
boost::signals2::signal<void (Message)> SyntaxBlock::CFG::SpecialIdentifier::OperandOfUnaryOperation::onErrorOccurs;

// int SyntaxBlock::CFG::SpecialIdentifier::FirstOperandOfBinaryOperation::beginningIndex;
boost::signals2::signal<void (Message)> SyntaxBlock::CFG::SpecialIdentifier::FirstOperandOfBinaryOperation::onErrorOccurs;

// int SyntaxBlock::CFG::SpecialIdentifier::SecondOperandOfBinaryOperation::beginningIndex;
boost::signals2::signal<void (Message)> SyntaxBlock::CFG::SpecialIdentifier::SecondOperandOfBinaryOperation::onErrorOccurs;

// int SyntaxBlock::CFG::SpecialIdentifier::V::beginningIndex;
boost::signals2::signal<void (Message)> SyntaxBlock::CFG::SpecialIdentifier::V::onErrorOccurs;

// int SyntaxBlock::CFG::SpecialIdentifier::No::beginningIndex;
boost::signals2::signal<void (Message)> SyntaxBlock::CFG::SpecialIdentifier::No::onErrorOccurs;

// int SyntaxBlock::CFG::SpecialIdentifier::Real::beginningIndex;
boost::signals2::signal<void (Message)> SyntaxBlock::CFG::SpecialIdentifier::Real::onErrorOccurs;

// int SyntaxBlock::CFG::SpecialIdentifier::Solution::beginningIndex;
boost::signals2::signal<void (Message)> SyntaxBlock::CFG::SpecialIdentifier::Solution::onErrorOccurs;

// int SyntaxBlock::CFG::SpecialIdentifier::Modulus::beginningIndex;
boost::signals2::signal<void (Message)> SyntaxBlock::CFG::SpecialIdentifier::Modulus::onErrorOccurs;

// int SyntaxBlock::CFG::SpecialIdentifier::SquareOfNumber::beginningIndex;
boost::signals2::signal<void (Message)> SyntaxBlock::CFG::SpecialIdentifier::SquareOfNumber::onErrorOccurs;

// int SyntaxBlock::CFG::SpecialIdentifier::SquareRootOfNumber::beginningIndex;
boost::signals2::signal<void (Message)> SyntaxBlock::CFG::SpecialIdentifier::SquareRootOfNumber::onErrorOccurs;


// int SyntaxBlock::CFG::Variable::beginningIndex;
boost::signals2::signal<void (Message)> SyntaxBlock::CFG::Variable::onErrorOccurs;

// int SyntaxBlock::CFG::Variable::Edge::beginningIndex;
boost::signals2::signal<void (Message)> SyntaxBlock::CFG::Variable::Edge::onErrorOccurs;

// int SyntaxBlock::CFG::Variable::Identifier::beginningIndex;
boost::signals2::signal<void (Message)> SyntaxBlock::CFG::Variable::Identifier::onErrorOccurs;

// int SyntaxBlock::CFG::Variable::Integer::beginningIndex;
boost::signals2::signal<void (Message)> SyntaxBlock::CFG::Variable::Integer::onErrorOccurs;

// int SyntaxBlock::CFG::Operation::beginningIndex;
boost::signals2::signal<void (Message)> SyntaxBlock::CFG::Operation::onErrorOccurs;

// int SyntaxBlock::CFG::Operation::Logical::beginningIndex;
boost::signals2::signal<void (Message)> SyntaxBlock::CFG::Operation::Logical::onErrorOccurs;

// int SyntaxBlock::CFG::Operation::Arithmetic::beginningIndex;
boost::signals2::signal<void (Message)> SyntaxBlock::CFG::Operation::Arithmetic::onErrorOccurs;

// int SyntaxBlock::CFG::String::beginningIndex;
boost::signals2::signal<void (Message)> SyntaxBlock::CFG::String::onErrorOccurs;

// int SyntaxBlock::CFG::String::Beginning::beginningIndex;
boost::signals2::signal<void (Message)> SyntaxBlock::CFG::String::Beginning::onErrorOccurs;

// int SyntaxBlock::CFG::String::Logical::beginningIndex;
boost::signals2::signal<void (Message)> SyntaxBlock::CFG::String::Logical::onErrorOccurs;

// int SyntaxBlock::CFG::String::Arithmetic::beginningIndex;
boost::signals2::signal<void (Message)> SyntaxBlock::CFG::String::Arithmetic::onErrorOccurs;

// int SyntaxBlock::CFG::String::Arithmetic::NoRealSolution::beginningIndex;
boost::signals2::signal<void (Message)> SyntaxBlock::CFG::String::Arithmetic::NoRealSolution::onErrorOccurs;

// int SyntaxBlock::CFG::String::Inner::beginningIndex;
boost::signals2::signal<void (Message)> SyntaxBlock::CFG::String::Inner::onErrorOccurs;

// int SyntaxBlock::CFG::String::Inner::Operation::beginningIndex;
boost::signals2::signal<void (Message)> SyntaxBlock::CFG::String::Inner::Operation::onErrorOccurs;

// int SyntaxBlock::CFG::String::Inner::Operand::beginningIndex;
boost::signals2::signal<void (Message)> SyntaxBlock::CFG::String::Inner::Operand::onErrorOccurs;

// int SyntaxBlock::CFG::String::Inner::Operand::Variable::beginningIndex;
boost::signals2::signal<void (Message)> SyntaxBlock::CFG::String::Inner::Operand::Variable::onErrorOccurs;

// int SyntaxBlock::CFG::String::Inner::Operand::Unary::beginningIndex;
boost::signals2::signal<void (Message)> SyntaxBlock::CFG::String::Inner::Operand::Unary::onErrorOccurs;

// int SyntaxBlock::CFG::String::Inner::Operand::Binary::beginningIndex;
boost::signals2::signal<void (Message)> SyntaxBlock::CFG::String::Inner::Operand::Binary::onErrorOccurs;

// int SyntaxBlock::CFG::String::Inner::Operand::Binary::First::beginningIndex;
boost::signals2::signal<void (Message)> SyntaxBlock::CFG::String::Inner::Operand::Binary::First::onErrorOccurs;

// int SyntaxBlock::CFG::String::Inner::Operand::Binary::Second::beginningIndex;
boost::signals2::signal<void (Message)> SyntaxBlock::CFG::String::Inner::Operand::Binary::Second::onErrorOccurs;

SyntaxBlock::SyntaxBlock(SyntaxBlockWorkingMode workingMode)
{
    this->workingMode = workingMode;
    this->stringIndex = 0;
    this->currentTokenIndexInVector = 0;
}

SyntaxBlock::~SyntaxBlock()
{
    this->tokenVector.clear();
}

SyntaxBlockWorkingMode SyntaxBlock::GetWorkingMode()
{
    return this->workingMode;
}

void SyntaxBlock::SetWorkingMode(SyntaxBlockWorkingMode workingMode)
{
    this->workingMode = workingMode;
}

int SyntaxBlock::GetStringIndex()
{
    return this->stringIndex;
}

void SyntaxBlock::SetStringIndex(int index)
{
    this->stringIndex = index;
}

void SyntaxBlock::LoadTokenVector(const std::vector<VariableToken>& tokenVector)
{
    this->tokenVector = tokenVector;
    this->currentTokenIndexInVector = 0;
}

void SyntaxBlock::LoadToken()
{
    this->currentTokenIndexInVector++;
}

VariableToken SyntaxBlock::GetCurrentToken()
{
    return this->tokenVector[this->currentTokenIndexInVector];
}

int SyntaxBlock::GetCurrentTokenIndex()
{
    auto token = this->GetCurrentToken();
    if (std::holds_alternative<SimpleToken>(token))
    {
        return std::get<SimpleToken>(token).index;
    }
    else
    {
        return std::get<ComplexToken>(token).index;
    }
}

void SyntaxBlock::CancelLoadToken()
{
    this->currentTokenIndexInVector--;
}

Message SyntaxBlock::MakeMessage(const VariableToken& token, const std::string& message)
{
    Message fullMessage;
    // #pragma omp critical
    // {
    if (std::holds_alternative<SimpleToken>(token))
    {
        fullMessage = Message(this->GetStringIndex(), std::get<SimpleToken>(token).index, message);
    }
    else
    {
        fullMessage = Message(this->GetStringIndex(), std::get<ComplexToken>(token).index, std::get<ComplexToken>(token).value, message);
    }
    // }
    return fullMessage;
}

bool SyntaxBlock::CheckTokenVector(const std::vector<std::variant<SimpleToken, ComplexToken>>& combinedTokens, SyntaxBlockWorkingMode workingMode)
{
    this->LoadTokenVector(combinedTokens);
    
    if (this->GetWorkingMode() != workingMode)
    {
        this->SetWorkingMode(workingMode);
    }
    if (workingMode == SyntaxBlockWorkingMode::AllErrorsWithoutInner)
    {
        SyntaxBlock::CFG::String(this).CheckAllInnerParts(true, false);
    }
    else if (workingMode == SyntaxBlockWorkingMode::AllErrors)
    {
        SyntaxBlock::CFG::String(this).CheckAllInnerParts(true, true);
    }
    if (workingMode == SyntaxBlockWorkingMode::UntilFirstError)
    {
        return SyntaxBlock::CFG::String(this).Check(true);
    }
    else
    {
        return SyntaxBlock::CFG::String(this).Check(false);
    }
    return false;
}


// Symbol
void SyntaxBlock::CFG::Symbol::OpeningCurlyBrace::Cancel(bool isSendingSignal)
{
    if (isSendingSignal)
    {
        onErrorOccurs(syntaxBlock->MakeMessage(syntaxBlock->GetCurrentToken(), MessagePool::Symbol["OpeningCurlyBrace"]));
    }
    syntaxBlock->currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::Symbol::OpeningCurlyBrace::Check(bool isSendingSignal)
{
    beginningIndex = syntaxBlock->currentTokenIndexInVector;

    VariableToken token = syntaxBlock->GetCurrentToken();
    if (std::holds_alternative<SimpleToken>(token))
    {
        SimpleToken tokenOpeningCurlyBrace = std::get<SimpleToken>(token);
        if (tokenOpeningCurlyBrace.type == SimpleTokenType::OpeningCurlyBrace)
        {
            syntaxBlock->LoadToken();
            return true;
        }
    }
    Cancel(isSendingSignal);
    return false;
}

void SyntaxBlock::CFG::Symbol::ClosingCurlyBrace::Cancel(bool isSendingSignal)
{
    if (isSendingSignal)
    {
        onErrorOccurs(syntaxBlock->MakeMessage(syntaxBlock->GetCurrentToken(), MessagePool::Symbol["ClosingCurlyBrace"]));
    }
    syntaxBlock->currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::Symbol::ClosingCurlyBrace::Check(bool isSendingSignal)
{
    beginningIndex = syntaxBlock->currentTokenIndexInVector;

    VariableToken token = syntaxBlock->GetCurrentToken();
    if (std::holds_alternative<SimpleToken>(token))
    {
        SimpleToken tokenClosingCurlyBrace = std::get<SimpleToken>(token);
        if (tokenClosingCurlyBrace.type == SimpleTokenType::ClosingCurlyBrace)
        {
            syntaxBlock->LoadToken();
            return true;
        }
    }
    Cancel(isSendingSignal);
    return false;
}

void SyntaxBlock::CFG::Symbol::OpeningParenthesis::Cancel(bool isSendingSignal)
{
    if (isSendingSignal)
    {
        // #pragma omp critical
        // {
        onErrorOccurs(syntaxBlock->MakeMessage(syntaxBlock->GetCurrentToken(), MessagePool::Symbol["OpeningParenthesis"]));
        // }
    }
    syntaxBlock->currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::Symbol::OpeningParenthesis::Check(bool isSendingSignal)
{
    beginningIndex = syntaxBlock->currentTokenIndexInVector;

    VariableToken token = syntaxBlock->GetCurrentToken();
    if (std::holds_alternative<SimpleToken>(token))
    {
        SimpleToken tokenOpeningParenthesis = std::get<SimpleToken>(token);
        if (tokenOpeningParenthesis.type == SimpleTokenType::OpeningParenthesis)
        {
            syntaxBlock->LoadToken();
            return true;
        }
    }
    Cancel(isSendingSignal);
    return false;
}

void SyntaxBlock::CFG::Symbol::ClosingParenthesis::Cancel(bool isSendingSignal)
{
    if (isSendingSignal)
    {
        // #pragma omp critical
        // {
        onErrorOccurs(syntaxBlock->MakeMessage(syntaxBlock->GetCurrentToken(), MessagePool::Symbol["ClosingParenthesis"]));
        // }
    }
    syntaxBlock->currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::Symbol::ClosingParenthesis::Check(bool isSendingSignal)
{
    beginningIndex = syntaxBlock->currentTokenIndexInVector;

    VariableToken token = syntaxBlock->GetCurrentToken();
    if (std::holds_alternative<SimpleToken>(token))
    {
        SimpleToken tokenClosingParenthesis = std::get<SimpleToken>(token);
        if (tokenClosingParenthesis.type == SimpleTokenType::ClosingParenthesis)
        {
            syntaxBlock->LoadToken();
            return true;
        }
    }
    Cancel(isSendingSignal);
    return false;
}

void SyntaxBlock::CFG::Symbol::Comma::Cancel(bool isSendingSignal)
{
    if (isSendingSignal)
    {
        // #pragma omp critical
        // {
        onErrorOccurs(syntaxBlock->MakeMessage(syntaxBlock->GetCurrentToken(), MessagePool::Symbol["Comma"]));
        // }
    }
    syntaxBlock->currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::Symbol::Comma::Check(bool isSendingSignal)
{
    beginningIndex = syntaxBlock->currentTokenIndexInVector;

    VariableToken token = syntaxBlock->GetCurrentToken();
    if (std::holds_alternative<SimpleToken>(token))
    {
        SimpleToken tokenComma = std::get<SimpleToken>(token);
        if (tokenComma.type == SimpleTokenType::Comma)
        {
            syntaxBlock->LoadToken();
            return true;
        }
    }
    Cancel(isSendingSignal);
    return false;
}

void SyntaxBlock::CFG::Symbol::Colon::Cancel(bool isSendingSignal)
{
    if (isSendingSignal)
    {
        // #pragma omp critical
        // {
        onErrorOccurs(syntaxBlock->MakeMessage(syntaxBlock->GetCurrentToken(), MessagePool::Symbol["Colon"]));
        // }
    }
    syntaxBlock->currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::Symbol::Colon::Check(bool isSendingSignal)
{
    beginningIndex = syntaxBlock->currentTokenIndexInVector;

    VariableToken token = syntaxBlock->GetCurrentToken();
    if (std::holds_alternative<SimpleToken>(token))
    {
        SimpleToken tokenColon = std::get<SimpleToken>(token);
        if (tokenColon.type == SimpleTokenType::Colon)
        {
            syntaxBlock->LoadToken();
            return true;
        }
    }
    Cancel(isSendingSignal);
    return false;
}

void SyntaxBlock::CFG::Symbol::Semicolon::Cancel(bool isSendingSignal)
{
    if (isSendingSignal)
    {
        // #pragma omp critical
        // {
        onErrorOccurs(syntaxBlock->MakeMessage(syntaxBlock->GetCurrentToken(), MessagePool::Symbol["Semicolon"]));
        // }
    }
    syntaxBlock->currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::Symbol::Semicolon::Check(bool isSendingSignal)
{
    beginningIndex = syntaxBlock->currentTokenIndexInVector;

    VariableToken token = syntaxBlock->GetCurrentToken();
    if (std::holds_alternative<SimpleToken>(token))
    {
        SimpleToken tokenSemicolon = std::get<SimpleToken>(token);
        if (tokenSemicolon.type == SimpleTokenType::Semicolon)
        {
            syntaxBlock->LoadToken();
            return true;
        }
    }
    Cancel(isSendingSignal);
    return false;
}

void SyntaxBlock::CFG::Symbol::QuotationMark::Cancel(bool isSendingSignal)
{
    if (isSendingSignal)
    {
        // #pragma omp critical
        // {
        onErrorOccurs(syntaxBlock->MakeMessage(syntaxBlock->GetCurrentToken(), MessagePool::Symbol["QuotationMark"]));
        // }
    }
    syntaxBlock->currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::Symbol::QuotationMark::Check(bool isSendingSignal)
{
    beginningIndex = syntaxBlock->currentTokenIndexInVector;

    VariableToken token = syntaxBlock->GetCurrentToken();
    if (std::holds_alternative<SimpleToken>(token))
    {
        SimpleToken tokenQuotationMark = std::get<SimpleToken>(token);
        if (tokenQuotationMark.type == SimpleTokenType::QuotationMark)
        {
            syntaxBlock->LoadToken();
            return true;
        }
    }
    Cancel(isSendingSignal);
    return false;
}

void SyntaxBlock::CFG::Symbol::EqualSign::Cancel(bool isSendingSignal)
{
    if (isSendingSignal)
    {
        // #pragma omp critical
        // {
        onErrorOccurs(syntaxBlock->MakeMessage(syntaxBlock->GetCurrentToken(), MessagePool::Symbol["EqualSign"]));
        // }
    }
    syntaxBlock->currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::Symbol::EqualSign::Check(bool isSendingSignal)
{
    beginningIndex = syntaxBlock->currentTokenIndexInVector;

    VariableToken token = syntaxBlock->GetCurrentToken();
    if (std::holds_alternative<SimpleToken>(token))
    {
        SimpleToken tokenEqualSign = std::get<SimpleToken>(token);
        if (tokenEqualSign.type == SimpleTokenType::EqualSign)
        {
            syntaxBlock->LoadToken();
            return true;
        }
    }
    Cancel(isSendingSignal);
    return false;
}

void SyntaxBlock::CFG::Symbol::ComparisonSign::Cancel(bool isSendingSignal)
{
    if (isSendingSignal)
    {
        // #pragma omp critical
        // {
        onErrorOccurs(syntaxBlock->MakeMessage(syntaxBlock->GetCurrentToken(), MessagePool::Symbol["ComparisonSign"]));
        // }
    }
    syntaxBlock->currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::Symbol::ComparisonSign::Check(bool isSendingSignal)
{
    beginningIndex = syntaxBlock->currentTokenIndexInVector;

    VariableToken token = syntaxBlock->GetCurrentToken();
    if (std::holds_alternative<SimpleToken>(token))
    {
        SimpleToken tokenComparisonSign = std::get<SimpleToken>(token);
        if (tokenComparisonSign.type == SimpleTokenType::ComparisonSign)
        {
            syntaxBlock->LoadToken();
            return true;
        }
    }
    Cancel(isSendingSignal);
    return false;
}

void SyntaxBlock::CFG::Symbol::ExclamationMark::Cancel(bool isSendingSignal)
{
    if (isSendingSignal)
    {
        // #pragma omp critical
        // {
        onErrorOccurs(syntaxBlock->MakeMessage(syntaxBlock->GetCurrentToken(), MessagePool::Symbol["ExclamationMark"]));
        // }
    }
    syntaxBlock->currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::Symbol::ExclamationMark::Check(bool isSendingSignal)
{
    beginningIndex = syntaxBlock->currentTokenIndexInVector;

    VariableToken token = syntaxBlock->GetCurrentToken();
    if (std::holds_alternative<SimpleToken>(token))
    {
        SimpleToken tokenExclamationMark = std::get<SimpleToken>(token);
        if (tokenExclamationMark.type == SimpleTokenType::ExclamationMark)
        {
            syntaxBlock->LoadToken();
            return true;
        }
    }
    Cancel(isSendingSignal);
    return false;
}

void SyntaxBlock::CFG::Symbol::ArithmeticSign::Cancel(bool isSendingSignal)
{
    if (isSendingSignal)
    {
        // #pragma omp critical
        // {
        onErrorOccurs(syntaxBlock->MakeMessage(syntaxBlock->GetCurrentToken(), MessagePool::Symbol["ArithmeticSign"]));
        // }
    }
    syntaxBlock->currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::Symbol::ArithmeticSign::Check(bool isSendingSignal)
{
    beginningIndex = syntaxBlock->currentTokenIndexInVector;

    VariableToken token = syntaxBlock->GetCurrentToken();
    if (std::holds_alternative<SimpleToken>(token))
    {
        SimpleToken tokenArithmeticSign = std::get<SimpleToken>(token);
        if (tokenArithmeticSign.type == SimpleTokenType::ArithmeticSign)
        {
            syntaxBlock->LoadToken();
            return true;
        }
    }
    Cancel(isSendingSignal);
    return false;
}

void SyntaxBlock::CFG::Symbol::LogicalSign::Cancel(bool isSendingSignal)
{
    if (isSendingSignal)
    {
        // #pragma omp critical
        // {
        onErrorOccurs(syntaxBlock->MakeMessage(syntaxBlock->GetCurrentToken(), MessagePool::Symbol["LogicalSign"]));
        // }
    }
    syntaxBlock->currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::Symbol::LogicalSign::Check(bool isSendingSignal)
{
    beginningIndex = syntaxBlock->currentTokenIndexInVector;

    VariableToken token = syntaxBlock->GetCurrentToken();
    if (std::holds_alternative<SimpleToken>(token))
    {
        SimpleToken tokenLogicalSign = std::get<SimpleToken>(token);
        if (tokenLogicalSign.type == SimpleTokenType::LogicalSign)
        {
            syntaxBlock->LoadToken();
            return true;
        }
    }
    Cancel(isSendingSignal);
    return false;
}

void SyntaxBlock::CFG::SpecialIdentifier::Operation::Cancel(bool isSendingSignal)
{
    if (isSendingSignal)
    {
        // #pragma omp critical
        // {
        onErrorOccurs(syntaxBlock->MakeMessage(syntaxBlock->GetCurrentToken(), MessagePool::SpecialIdentifier["Operation"]));
        // }
    }
    syntaxBlock->currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::SpecialIdentifier::Operation::Check(bool isSendingSignal)
{
    beginningIndex = syntaxBlock->currentTokenIndexInVector;

    VariableToken token = syntaxBlock->GetCurrentToken();
    if (std::holds_alternative<ComplexToken>(token))
    {
        ComplexToken tokenOperationSpecialIdentifier = std::get<ComplexToken>(token);
        if (std::holds_alternative<SpecialIdentifierType>(tokenOperationSpecialIdentifier.type))
        {
            SpecialIdentifierType tokenOperationSpecialIdentifierType = std::get<SpecialIdentifierType>(tokenOperationSpecialIdentifier.type);
            if (tokenOperationSpecialIdentifierType == SpecialIdentifierType::Operation)
            {
                syntaxBlock->LoadToken();
                return true;
            }
        }
    }
    Cancel(isSendingSignal);
    return false;
}

void SyntaxBlock::CFG::SpecialIdentifier::OperandOfUnaryOperation::Cancel(bool isSendingSignal)
{
    if (isSendingSignal)
    {
        // #pragma omp critical
        // {
        onErrorOccurs(syntaxBlock->MakeMessage(syntaxBlock->GetCurrentToken(), MessagePool::SpecialIdentifier["OperandOfUnaryOperation"]));
        // }
    }
    syntaxBlock->currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::SpecialIdentifier::OperandOfUnaryOperation::Check(bool isSendingSignal)
{
    beginningIndex = syntaxBlock->currentTokenIndexInVector;

    VariableToken token = syntaxBlock->GetCurrentToken();
    if (std::holds_alternative<ComplexToken>(token))
    {
        ComplexToken tokenOperandOfUnaryOperationSpecialIdentifier = std::get<ComplexToken>(token);
        if (std::holds_alternative<SpecialIdentifierType>(tokenOperandOfUnaryOperationSpecialIdentifier.type))
        {
            SpecialIdentifierType tokenOperandOfUnaryOperationSpecialIdentifierType = std::get<SpecialIdentifierType>(tokenOperandOfUnaryOperationSpecialIdentifier.type);
            if (tokenOperandOfUnaryOperationSpecialIdentifierType == SpecialIdentifierType::OperandOfUnaryOperation)
            {
                syntaxBlock->LoadToken();
                return true;
            }
        }
    }
    Cancel(isSendingSignal);
    return false;
}

void SyntaxBlock::CFG::SpecialIdentifier::FirstOperandOfBinaryOperation::Cancel(bool isSendingSignal)
{
    if (isSendingSignal)
    {
        // #pragma omp critical
        // {
        onErrorOccurs(syntaxBlock->MakeMessage(syntaxBlock->GetCurrentToken(), MessagePool::SpecialIdentifier["FirstOperandOfBinaryOperation"]));
        // }
    }
    syntaxBlock->currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::SpecialIdentifier::FirstOperandOfBinaryOperation::Check(bool isSendingSignal)
{
    beginningIndex = syntaxBlock->currentTokenIndexInVector;

    VariableToken token = syntaxBlock->GetCurrentToken();
    if (std::holds_alternative<ComplexToken>(token))
    {
        ComplexToken tokenFirstOperandOfBinaryOperationSpecialIdentifier = std::get<ComplexToken>(token);
        if (std::holds_alternative<SpecialIdentifierType>(tokenFirstOperandOfBinaryOperationSpecialIdentifier.type))
        {
            SpecialIdentifierType tokenFirstOperandOfBinaryOperationSpecialIdentifierType = std::get<SpecialIdentifierType>(tokenFirstOperandOfBinaryOperationSpecialIdentifier.type);
            if (tokenFirstOperandOfBinaryOperationSpecialIdentifierType == SpecialIdentifierType::FirstOperandOfBinaryOperation)
            {
                syntaxBlock->LoadToken();
                return true;
            }
        }
    }
    Cancel(isSendingSignal);
    return false;
}

void SyntaxBlock::CFG::SpecialIdentifier::SecondOperandOfBinaryOperation::Cancel(bool isSendingSignal)
{
    if (isSendingSignal)
    {
        // #pragma omp critical
        // {
        onErrorOccurs(syntaxBlock->MakeMessage(syntaxBlock->GetCurrentToken(), MessagePool::SpecialIdentifier["SecondOperandOfBinaryOperation"]));
        // }
    }
    syntaxBlock->currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::SpecialIdentifier::SecondOperandOfBinaryOperation::Check(bool isSendingSignal)
{
    beginningIndex = syntaxBlock->currentTokenIndexInVector;

    VariableToken token = syntaxBlock->GetCurrentToken();
    if (std::holds_alternative<ComplexToken>(token))
    {
        ComplexToken tokenSecondOperandOfBinaryOperationSpecialIdentifier = std::get<ComplexToken>(token);
        if (std::holds_alternative<SpecialIdentifierType>(tokenSecondOperandOfBinaryOperationSpecialIdentifier.type))
        {
            SpecialIdentifierType tokenSecondOperandOfBinaryOperationSpecialIdentifierType = std::get<SpecialIdentifierType>(tokenSecondOperandOfBinaryOperationSpecialIdentifier.type);
            if (tokenSecondOperandOfBinaryOperationSpecialIdentifierType == SpecialIdentifierType::SecondOperandOfBinaryOperation)
            {
                syntaxBlock->LoadToken();
                return true;
            }
        }
    }
    Cancel(isSendingSignal);
    return false;
}

void SyntaxBlock::CFG::SpecialIdentifier::V::Cancel(bool isSendingSignal)
{
    if (isSendingSignal)
    {
        // #pragma omp critical
        // {
        onErrorOccurs(syntaxBlock->MakeMessage(syntaxBlock->GetCurrentToken(), MessagePool::SpecialIdentifier["V"]));
        // }
    }
    syntaxBlock->currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::SpecialIdentifier::V::Check(bool isSendingSignal)
{
    beginningIndex = syntaxBlock->currentTokenIndexInVector;

    VariableToken token = syntaxBlock->GetCurrentToken();
    if (std::holds_alternative<ComplexToken>(token))
    {
        ComplexToken tokenVSpecialIdentifier = std::get<ComplexToken>(token);
        if (std::holds_alternative<SpecialIdentifierType>(tokenVSpecialIdentifier.type))
        {
            SpecialIdentifierType tokenVSpecialIdentifierType = std::get<SpecialIdentifierType>(tokenVSpecialIdentifier.type);
            if (tokenVSpecialIdentifierType == SpecialIdentifierType::V)
            {
                syntaxBlock->LoadToken();
                return true;
            }
        }
    }
    Cancel(isSendingSignal);
    return false;
}

void SyntaxBlock::CFG::SpecialIdentifier::No::Cancel(bool isSendingSignal)
{
    if (isSendingSignal)
    {
        // #pragma omp critical
        // {
        onErrorOccurs(syntaxBlock->MakeMessage(syntaxBlock->GetCurrentToken(), MessagePool::SpecialIdentifier["No"]));
        // }
    }
    syntaxBlock->currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::SpecialIdentifier::No::Check(bool isSendingSignal)
{
    beginningIndex = syntaxBlock->currentTokenIndexInVector;

    VariableToken token = syntaxBlock->GetCurrentToken();
    if (std::holds_alternative<ComplexToken>(token))
    {
        ComplexToken tokenNoSpecialIdentifier = std::get<ComplexToken>(token);
        if (std::holds_alternative<SpecialIdentifierType>(tokenNoSpecialIdentifier.type))
        {
            SpecialIdentifierType tokenNoSpecialIdentifierType = std::get<SpecialIdentifierType>(tokenNoSpecialIdentifier.type);
            if (tokenNoSpecialIdentifierType == SpecialIdentifierType::No)
            {
                syntaxBlock->LoadToken();
                return true;
            }
        }
    }
    Cancel(isSendingSignal);
    return false;
}

void SyntaxBlock::CFG::SpecialIdentifier::Real::Cancel(bool isSendingSignal)
{
    if (isSendingSignal)
    {
        // #pragma omp critical
        // {
        onErrorOccurs(syntaxBlock->MakeMessage(syntaxBlock->GetCurrentToken(), MessagePool::SpecialIdentifier["Real"]));
        // }
    }
    syntaxBlock->currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::SpecialIdentifier::Real::Check(bool isSendingSignal)
{
    beginningIndex = syntaxBlock->currentTokenIndexInVector;

    VariableToken token = syntaxBlock->GetCurrentToken();
    if (std::holds_alternative<ComplexToken>(token))
    {
        ComplexToken tokenRealSpecialIdentifier = std::get<ComplexToken>(token);
        if (std::holds_alternative<SpecialIdentifierType>(tokenRealSpecialIdentifier.type))
        {
            SpecialIdentifierType tokenRealSpecialIdentifierType = std::get<SpecialIdentifierType>(tokenRealSpecialIdentifier.type);
            if (tokenRealSpecialIdentifierType == SpecialIdentifierType::Real)
            {
                syntaxBlock->LoadToken();
                return true;
            }
        }
    }
    Cancel(isSendingSignal);
    return false;
}

void SyntaxBlock::CFG::SpecialIdentifier::Solution::Cancel(bool isSendingSignal)
{
    if (isSendingSignal)
    {
        // #pragma omp critical
        // {
        onErrorOccurs(syntaxBlock->MakeMessage(syntaxBlock->GetCurrentToken(), MessagePool::SpecialIdentifier["Solution"]));
        // }
    }
    syntaxBlock->currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::SpecialIdentifier::Solution::Check(bool isSendingSignal)
{
    beginningIndex = syntaxBlock->currentTokenIndexInVector;

    VariableToken token = syntaxBlock->GetCurrentToken();
    if (std::holds_alternative<ComplexToken>(token))
    {
        ComplexToken tokenSolutionSpecialIdentifier = std::get<ComplexToken>(token);
        if (std::holds_alternative<SpecialIdentifierType>(tokenSolutionSpecialIdentifier.type))
        {
            SpecialIdentifierType tokenSolutionSpecialIdentifierType = std::get<SpecialIdentifierType>(tokenSolutionSpecialIdentifier.type);
            if (tokenSolutionSpecialIdentifierType == SpecialIdentifierType::Solution)
            {
                syntaxBlock->LoadToken();
                return true;
            }
        }
    }
    Cancel(isSendingSignal);
    return false;
}

void SyntaxBlock::CFG::SpecialIdentifier::Modulus::Cancel(bool isSendingSignal)
{
    if (isSendingSignal)
    {
        // #pragma omp critical
        // {
        onErrorOccurs(syntaxBlock->MakeMessage(syntaxBlock->GetCurrentToken(), MessagePool::SpecialIdentifier["Modulus"]));
        // }
    }
    syntaxBlock->currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::SpecialIdentifier::Modulus::Check(bool isSendingSignal)
{
    beginningIndex = syntaxBlock->currentTokenIndexInVector;

    VariableToken token = syntaxBlock->GetCurrentToken();
    if (std::holds_alternative<ComplexToken>(token))
    {
        ComplexToken tokenModulusSpecialIdentifier = std::get<ComplexToken>(token);
        if (std::holds_alternative<SpecialIdentifierType>(tokenModulusSpecialIdentifier.type))
        {
            SpecialIdentifierType tokenModulusSpecialIdentifierType = std::get<SpecialIdentifierType>(tokenModulusSpecialIdentifier.type);
            if (tokenModulusSpecialIdentifierType == SpecialIdentifierType::Modulus)
            {
                syntaxBlock->LoadToken();
                return true;
            }
        }
    }
    Cancel(isSendingSignal);
    return false;
}

void SyntaxBlock::CFG::SpecialIdentifier::SquareOfNumber::Cancel(bool isSendingSignal)
{
    if (isSendingSignal)
    {
        // #pragma omp critical
        // {
        onErrorOccurs(syntaxBlock->MakeMessage(syntaxBlock->GetCurrentToken(), MessagePool::SpecialIdentifier["SquareOfNumber"]));
        // }
    }
    syntaxBlock->currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::SpecialIdentifier::SquareOfNumber::Check(bool isSendingSignal)
{
    beginningIndex = syntaxBlock->currentTokenIndexInVector;

    VariableToken token = syntaxBlock->GetCurrentToken();
    if (std::holds_alternative<ComplexToken>(token))
    {
        ComplexToken tokenSquareOfNumberSpecialIdentifier = std::get<ComplexToken>(token);
        if (std::holds_alternative<SpecialIdentifierType>(tokenSquareOfNumberSpecialIdentifier.type))
        {
            SpecialIdentifierType tokenSquareOfNumberSpecialIdentifierType = std::get<SpecialIdentifierType>(tokenSquareOfNumberSpecialIdentifier.type);
            if (tokenSquareOfNumberSpecialIdentifierType == SpecialIdentifierType::SquareOfNumber)
            {
                syntaxBlock->LoadToken();
                return true;
            }
        }
    }
    Cancel(isSendingSignal);
    return false;
}

void SyntaxBlock::CFG::SpecialIdentifier::SquareRootOfNumber::Cancel(bool isSendingSignal)
{
    if (isSendingSignal)
    {
        // #pragma omp critical
        // {
        onErrorOccurs(syntaxBlock->MakeMessage(syntaxBlock->GetCurrentToken(), MessagePool::SpecialIdentifier["SquareRootOfNumber"]));
        // }
    }
    syntaxBlock->currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::SpecialIdentifier::SquareRootOfNumber::Check(bool isSendingSignal)
{
    beginningIndex = syntaxBlock->currentTokenIndexInVector;

    VariableToken token = syntaxBlock->GetCurrentToken();
    if (std::holds_alternative<ComplexToken>(token))
    {
        ComplexToken tokenSquareRootOfNumberSpecialIdentifier = std::get<ComplexToken>(token);
        if (std::holds_alternative<SpecialIdentifierType>(tokenSquareRootOfNumberSpecialIdentifier.type))
        {
            SpecialIdentifierType tokenSquareRootOfNumberSpecialIdentifierType = std::get<SpecialIdentifierType>(tokenSquareRootOfNumberSpecialIdentifier.type);
            if (tokenSquareRootOfNumberSpecialIdentifierType == SpecialIdentifierType::SquareRootOfNumber)
            {
                syntaxBlock->LoadToken();
                return true;
            }
        }
    }
    Cancel(isSendingSignal);
    return false;
}

void SyntaxBlock::CFG::Variable::Identifier::Cancel(bool isSendingSignal)
{
    if (isSendingSignal)
    {
        // #pragma omp critical
        // {
        onErrorOccurs(syntaxBlock->MakeMessage(syntaxBlock->GetCurrentToken(), MessagePool::Variable["Identifier"]));
        // }
    }
    syntaxBlock->currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::Variable::Identifier::Check(bool isSendingSignal)
{
    beginningIndex = syntaxBlock->currentTokenIndexInVector;
    
    VariableToken token = syntaxBlock->GetCurrentToken();
    if (std::holds_alternative<ComplexToken>(token))
    {
        ComplexToken tokenIdentifier = std::get<ComplexToken>(token);
        if (std::holds_alternative<ComplexTokenType>(tokenIdentifier.type))
        {
            ComplexTokenType tokenIdentifierType = std::get<ComplexTokenType>(tokenIdentifier.type);
            if (tokenIdentifierType != ComplexTokenType::Identifier)
            {
                Cancel(isSendingSignal);
                return false;
            }
        }
        syntaxBlock->LoadToken();
        return true;
    }
    Cancel(isSendingSignal);
    return false;
}

void SyntaxBlock::CFG::Variable::Integer::Cancel(bool isSendingSignal)
{
    if (isSendingSignal)
    {
        // #pragma omp critical
        // {
        onErrorOccurs(syntaxBlock->MakeMessage(syntaxBlock->GetCurrentToken(), MessagePool::Variable["Integer"]));
        // }
    }
    syntaxBlock->currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::Variable::Integer::Check(bool isSendingSignal)
{
    beginningIndex = syntaxBlock->currentTokenIndexInVector;

    VariableToken token = syntaxBlock->GetCurrentToken();
    if (std::holds_alternative<ComplexToken>(token))
    {
        ComplexToken tokenInteger = std::get<ComplexToken>(token);
        if (std::holds_alternative<ComplexTokenType>(tokenInteger.type))
        {
            ComplexTokenType tokenIntegerType = std::get<ComplexTokenType>(tokenInteger.type);
            if (tokenIntegerType != ComplexTokenType::Integer)
            {
                Cancel(isSendingSignal);
                return false;
            }
            syntaxBlock->LoadToken();
            return true;
        }
    }
    Cancel(isSendingSignal);
    return false;
}

void SyntaxBlock::CFG::Variable::Edge::Cancel(bool isSendingSignal)
{
    if (isSendingSignal)
    {
        // #pragma omp critical
        // {
        onErrorOccurs(syntaxBlock->MakeMessage(syntaxBlock->GetCurrentToken(), MessagePool::Variable["Edge"]));
        // }
    }
    syntaxBlock->currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::Variable::Edge::Check(bool isSendingSignal)
{
    beginningIndex = syntaxBlock->currentTokenIndexInVector;

    if (!SyntaxBlock::CFG::Variable::Identifier(syntaxBlock).Check(isSendingSignal))
    {
        Cancel(isSendingSignal);
        return false;
    }

    if (!SyntaxBlock::CFG::Symbol::OpeningParenthesis(syntaxBlock).Check(isSendingSignal))
    {
        Cancel(isSendingSignal);
        return false;
    }

    if (!SyntaxBlock::CFG::Variable::Integer(syntaxBlock).Check(isSendingSignal))
    {
        Cancel(isSendingSignal);
        return false;
    }

    if (!SyntaxBlock::CFG::Symbol::Comma(syntaxBlock).Check(false))
    {
        if (!SyntaxBlock::CFG::Symbol::ClosingParenthesis(syntaxBlock).Check(isSendingSignal))
        {
            Cancel(isSendingSignal);
            return false;
        }

        return true;
    }
    else
    {
        if (!SyntaxBlock::CFG::Variable::Integer(syntaxBlock).Check(isSendingSignal))
        {
            Cancel(isSendingSignal);
            return false;
        }

        if (!SyntaxBlock::CFG::Symbol::ClosingParenthesis(syntaxBlock).Check(isSendingSignal))
        {
            Cancel(isSendingSignal);
            return false;
        }

        return true;
    }
}

void SyntaxBlock::CFG::Variable::Cancel(bool isSendingSignal)
{
    if (isSendingSignal)
    {
        // #pragma omp critical
        // {
        onErrorOccurs(syntaxBlock->MakeMessage(syntaxBlock->GetCurrentToken(), MessagePool::Variable["Variable"]));
        // }
    }
    syntaxBlock->currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::Variable::Check(bool isSendingSignal)
{
    beginningIndex = syntaxBlock->currentTokenIndexInVector;

    if (SyntaxBlock::CFG::Variable::Edge(syntaxBlock).Check(false))
    {
        return true;
    }
    else if (SyntaxBlock::CFG::Variable::Identifier(syntaxBlock).Check(false))
    {
        return true;
    }
    else if (SyntaxBlock::CFG::Variable::Integer(syntaxBlock).Check(false))
    {
        return true;
    }
    Cancel(isSendingSignal);
    return false;
}

void SyntaxBlock::CFG::Operation::Logical::Cancel(bool isSendingSignal)
{
    if (isSendingSignal)
    {
        // #pragma omp critical
        // {
        onErrorOccurs(syntaxBlock->MakeMessage(syntaxBlock->GetCurrentToken(), MessagePool::Operation["Logical"]));
        // }
    }
    syntaxBlock->currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::Operation::Logical::Check(bool isSendingSignal)
{
    beginningIndex = syntaxBlock->currentTokenIndexInVector;

    if (SyntaxBlock::CFG::Symbol::ExclamationMark(syntaxBlock).Check(false))
    {
        if (SyntaxBlock::CFG::Symbol::EqualSign(syntaxBlock).Check(false))
        {
            return true;
        }
        Cancel(isSendingSignal);
        return false;
    }
    else if (SyntaxBlock::CFG::Symbol::EqualSign(syntaxBlock).Check(false))
    {
        if (SyntaxBlock::CFG::Symbol::EqualSign(syntaxBlock).Check(false))
        {
            return true;
        }
        Cancel(isSendingSignal);
        return false;
    }
    else if (SyntaxBlock::CFG::Symbol::ComparisonSign(syntaxBlock).Check(false))
    {
        if (SyntaxBlock::CFG::Symbol::EqualSign(syntaxBlock).Check(false))
        {
            return true;
        }
        return true;
    }
    else if (SyntaxBlock::CFG::Symbol::LogicalSign(syntaxBlock).Check(false))
    {
        return true;
    }
    Cancel(isSendingSignal);
    return false;
}

void SyntaxBlock::CFG::Operation::Arithmetic::Cancel(bool isSendingSignal)
{
    if (isSendingSignal)
    {
        // #pragma omp critical
        // {
        onErrorOccurs(syntaxBlock->MakeMessage(syntaxBlock->GetCurrentToken(), MessagePool::Operation["Arithmetic"]));
        // }
    }
    syntaxBlock->currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::Operation::Arithmetic::Check(bool isSendingSignal)
{
    beginningIndex = syntaxBlock->currentTokenIndexInVector;

    if (SyntaxBlock::CFG::Symbol::ArithmeticSign(syntaxBlock).Check(false))
    {
        return true;
    }
    if (SyntaxBlock::CFG::SpecialIdentifier::Modulus(syntaxBlock).Check(false))
    {
        return true;
    }
    if (SyntaxBlock::CFG::SpecialIdentifier::SquareOfNumber(syntaxBlock).Check(false))
    {
        return true;
    }
    if (SyntaxBlock::CFG::SpecialIdentifier::SquareRootOfNumber(syntaxBlock).Check(false))
    {
        return true;
    }
    Cancel(isSendingSignal);
    return false;
}

void SyntaxBlock::CFG::Operation::Cancel(bool isSendingSignal)
{
    if (isSendingSignal)
    {
        // #pragma omp critical
        // {
        onErrorOccurs(syntaxBlock->MakeMessage(syntaxBlock->GetCurrentToken(), MessagePool::Operation["Operation"]));
        // }
    }
    syntaxBlock->currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::Operation::Check(bool isSendingSignal)
{
    beginningIndex = syntaxBlock->currentTokenIndexInVector;

    if (SyntaxBlock::CFG::Operation::Logical(syntaxBlock).Check(false))
    {
        return true;
    }
    if (SyntaxBlock::CFG::Operation::Arithmetic(syntaxBlock).Check(false))
    {
        return true;
    }
    Cancel(isSendingSignal);
    return false;
}

void SyntaxBlock::CFG::String::Beginning::Cancel(bool isSendingSignal)
{
    if (isSendingSignal)
    {
        // #pragma omp critical
        // {
        onErrorOccurs(syntaxBlock->MakeMessage(syntaxBlock->GetCurrentToken(), MessagePool::String["Beginning"]));
        // }
    }
    syntaxBlock->currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::String::Beginning::Check(bool isSendingSignal)
{
    beginningIndex = syntaxBlock->currentTokenIndexInVector;

    if (SyntaxBlock::CFG::Variable::Edge(syntaxBlock).Check(false))
    {
        return true;
    }
    if (SyntaxBlock::CFG::Variable::Identifier(syntaxBlock).Check(false))
    {
        return true;
    }
    Cancel(isSendingSignal);
    return false;
}

void SyntaxBlock::CFG::String::Inner::Operation::Cancel(bool isSendingSignal)
{
    if (isSendingSignal)
    {
        // #pragma omp critical
        // {
        onErrorOccurs(syntaxBlock->MakeMessage(syntaxBlock->GetCurrentToken(), MessagePool::StringInner["Operation"]));
        // }
    }
    syntaxBlock->currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::String::Inner::Operation::Check(bool isSendingSignal)
{
    beginningIndex = syntaxBlock->currentTokenIndexInVector;

    if (!SyntaxBlock::CFG::Symbol::QuotationMark(syntaxBlock).Check(isSendingSignal))
    {
        Cancel(isSendingSignal);
        return false;
    }
    if (!SyntaxBlock::CFG::SpecialIdentifier::Operation(syntaxBlock).Check(isSendingSignal))
    {
        Cancel(isSendingSignal);
        return false;
    }
    if (!SyntaxBlock::CFG::Symbol::QuotationMark(syntaxBlock).Check(isSendingSignal))
    {
        Cancel(isSendingSignal);
        return false;
    }
    if (!SyntaxBlock::CFG::Symbol::Colon(syntaxBlock).Check(isSendingSignal))
    {
        Cancel(isSendingSignal);
        return false;
    }
    if (!SyntaxBlock::CFG::Symbol::QuotationMark(syntaxBlock).Check(isSendingSignal))
    {
        Cancel(isSendingSignal);
        return false;
    }
    if (!SyntaxBlock::CFG::Operation(syntaxBlock).Check(isSendingSignal))
    {
        Cancel(isSendingSignal);
        return false;
    }
    if (!SyntaxBlock::CFG::Symbol::QuotationMark(syntaxBlock).Check(isSendingSignal))
    {
        Cancel(isSendingSignal);
        return false;
    }
    return true;
}

void SyntaxBlock::CFG::String::Inner::Operand::Unary::Cancel(bool isSendingSignal)
{
    if (isSendingSignal)
    {
        // #pragma omp critical
        // {
        onErrorOccurs(syntaxBlock->MakeMessage(syntaxBlock->GetCurrentToken(), MessagePool::StringInner["OperandUnary"]));
        // }
    }
    syntaxBlock->currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::String::Inner::Operand::Unary::Check(bool isSendingSignal, bool isCheckingInner)
{
    beginningIndex = syntaxBlock->currentTokenIndexInVector;

    if (!SyntaxBlock::CFG::Symbol::QuotationMark(syntaxBlock).Check(isSendingSignal))
    {
        Cancel(isSendingSignal);
        return false;
    }
    if (!SyntaxBlock::CFG::SpecialIdentifier::OperandOfUnaryOperation(syntaxBlock).Check(isSendingSignal))
    {
        Cancel(isSendingSignal);
        return false;
    }
    if (!SyntaxBlock::CFG::Symbol::QuotationMark(syntaxBlock).Check(isSendingSignal))
    {
        Cancel(isSendingSignal);
        return false;
    }
    if (!SyntaxBlock::CFG::Symbol::Colon(syntaxBlock).Check(isSendingSignal))
    {
        Cancel(isSendingSignal);
        return false;
    }
    auto openingCurlyBrace = SyntaxBlock::CFG::Symbol::OpeningCurlyBrace(syntaxBlock);
    if (openingCurlyBrace.Check(false))
    {
        openingCurlyBrace.Cancel(false);
        if (!isCheckingInner)
        {
            return true;
        }
        if (!SyntaxBlock::CFG::String::Inner(syntaxBlock).Check(isSendingSignal))
        {
            Cancel(isSendingSignal);
            return false;
        }
        return true;
    }
    if (!SyntaxBlock::CFG::Symbol::QuotationMark(syntaxBlock).Check(isSendingSignal))
    {
        Cancel(isSendingSignal);
        return false;
    }
    if (!SyntaxBlock::CFG::Variable(syntaxBlock).Check(isSendingSignal))
    {
        Cancel(isSendingSignal);
        return false;
    }
    if (!SyntaxBlock::CFG::Symbol::QuotationMark(syntaxBlock).Check(isSendingSignal))
    {
        Cancel(isSendingSignal);
        return false;
    }
    return true;
}

void SyntaxBlock::CFG::String::Inner::Operand::Binary::First::Cancel(bool isSendingSignal)
{
    if (isSendingSignal)
    {
        // #pragma omp critical
        // {
        onErrorOccurs(syntaxBlock->MakeMessage(syntaxBlock->GetCurrentToken(), MessagePool::StringInner["FirstOperandOfBinaryOperation"]));
        // }
    }
    syntaxBlock->currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::String::Inner::Operand::Binary::First::Check(bool isSendingSignal, bool isCheckingInner)
{
    beginningIndex = syntaxBlock->currentTokenIndexInVector;

    if (!SyntaxBlock::CFG::Symbol::QuotationMark(syntaxBlock).Check(isSendingSignal))
    {
        Cancel(isSendingSignal);
        return false;
    }
    if (!SyntaxBlock::CFG::SpecialIdentifier::FirstOperandOfBinaryOperation(syntaxBlock).Check(isSendingSignal))
    {
        Cancel(isSendingSignal);
        return false;
    }
    if (!SyntaxBlock::CFG::Symbol::QuotationMark(syntaxBlock).Check(isSendingSignal))
    {
        Cancel(isSendingSignal);
        return false;
    }
    if (!SyntaxBlock::CFG::Symbol::Colon(syntaxBlock).Check(isSendingSignal))
    {
        Cancel(isSendingSignal);
        return false;
    }
    auto openingCurlyBrace = SyntaxBlock::CFG::Symbol::OpeningCurlyBrace(syntaxBlock);
    if (openingCurlyBrace.Check(false))
    {
        openingCurlyBrace.Cancel(false);
        if (!isCheckingInner)
        {
            return true;
        }
        if (!SyntaxBlock::CFG::String::Inner(syntaxBlock).Check(isSendingSignal))
        {
            Cancel(isSendingSignal);
            return false;
        }
        return true;
    }
    if (!SyntaxBlock::CFG::Symbol::QuotationMark(syntaxBlock).Check(isSendingSignal))
    {
        Cancel(isSendingSignal);
        return false;
    }
    if (!SyntaxBlock::CFG::Variable(syntaxBlock).Check(isSendingSignal))
    {
        Cancel(isSendingSignal);
        return false;
    }
    if (!SyntaxBlock::CFG::Symbol::QuotationMark(syntaxBlock).Check(isSendingSignal))
    {
        Cancel(isSendingSignal);
        return false;
    }
    return true;
}

void SyntaxBlock::CFG::String::Inner::Operand::Binary::Second::Cancel(bool isSendingSignal)
{
    if (isSendingSignal)
    {
        // #pragma omp critical
        // {
        onErrorOccurs(syntaxBlock->MakeMessage(syntaxBlock->GetCurrentToken(), MessagePool::StringInner["SecondOperandOfBinaryOperation"]));
        // }
    }
    syntaxBlock->currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::String::Inner::Operand::Binary::Second::Check(bool isSendingSignal, bool isCheckingInner)
{
    beginningIndex = syntaxBlock->currentTokenIndexInVector;

    if (!SyntaxBlock::CFG::Symbol::QuotationMark(syntaxBlock).Check(isSendingSignal))
    {
        Cancel(isSendingSignal);
        return false;
    }
    if (!SyntaxBlock::CFG::SpecialIdentifier::SecondOperandOfBinaryOperation(syntaxBlock).Check(isSendingSignal))
    {
        Cancel(isSendingSignal);
        return false;
    }
    if (!SyntaxBlock::CFG::Symbol::QuotationMark(syntaxBlock).Check(isSendingSignal))
    {
        Cancel(isSendingSignal);
        return false;
    }
    if (!SyntaxBlock::CFG::Symbol::Colon(syntaxBlock).Check(isSendingSignal))
    {
        Cancel(isSendingSignal);
        return false;
    }
    auto openingCurlyBrace = SyntaxBlock::CFG::Symbol::OpeningCurlyBrace(syntaxBlock);
    if (openingCurlyBrace.Check(false))
    {
        openingCurlyBrace.Cancel(false);
        if (!isCheckingInner)
        {
            return true;
        }
        if (!SyntaxBlock::CFG::String::Inner(syntaxBlock).Check(isSendingSignal))
        {
            Cancel(isSendingSignal);
            return false;
        }
        return true;
    }
    if (!SyntaxBlock::CFG::Symbol::QuotationMark(syntaxBlock).Check(isSendingSignal))
    {
        Cancel(isSendingSignal);
        return false;
    }
    if (!SyntaxBlock::CFG::Variable(syntaxBlock).Check(isSendingSignal))
    {
        Cancel(isSendingSignal);
        return false;
    }
    if (!SyntaxBlock::CFG::Symbol::QuotationMark(syntaxBlock).Check(isSendingSignal))
    {
        Cancel(isSendingSignal);
        return false;
    }
    return true;
}

void SyntaxBlock::CFG::String::Inner::Operand::Binary::Cancel(bool isSendingSignal)
{
    if (isSendingSignal)
    {
        // #pragma omp critical
        // {
        onErrorOccurs(syntaxBlock->MakeMessage(syntaxBlock->GetCurrentToken(), MessagePool::StringInner["OperandBinary"]));
        // }
    }
    syntaxBlock->currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::String::Inner::Operand::Binary::Check(bool isSendingSignal, bool isCheckingInner)
{
    beginningIndex = syntaxBlock->currentTokenIndexInVector;

    if (!SyntaxBlock::CFG::String::Inner::Operand::Binary::First(syntaxBlock).Check(isSendingSignal, isCheckingInner))
    {
        Cancel(isSendingSignal);
        return false;
    }
    if (!SyntaxBlock::CFG::Symbol::Comma(syntaxBlock).Check(isSendingSignal))
    {
        Cancel(isSendingSignal);
        return false;
    }
    if (!SyntaxBlock::CFG::String::Inner::Operand::Binary::Second(syntaxBlock).Check(isSendingSignal, isCheckingInner))
    {
        Cancel(isSendingSignal);
        return false;
    }
    return true;
}

void SyntaxBlock::CFG::String::Inner::Operand::Variable::Cancel(bool isSendingSignal)
{
    if (isSendingSignal)
    {
        // #pragma omp critical
        // {
        onErrorOccurs(syntaxBlock->MakeMessage(syntaxBlock->GetCurrentToken(), MessagePool::StringInner["OperandVariable"]));
        // }
    }
    syntaxBlock->currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::String::Inner::Operand::Variable::Check(bool isSendingSignal, bool isCheckingInner)
{
    beginningIndex = syntaxBlock->currentTokenIndexInVector;

    if (SyntaxBlock::CFG::String::Inner::Operand::Unary(syntaxBlock).Check(false, isCheckingInner))
    {
        return true;
    }
    if (SyntaxBlock::CFG::String::Inner::Operand::Binary::First(syntaxBlock).Check(false, isCheckingInner))
    {
        return true;
    }
    if (SyntaxBlock::CFG::String::Inner::Operand::Binary::Second(syntaxBlock).Check(false, isCheckingInner))
    {
        return true;
    }
    Cancel(isSendingSignal);
    return false;
}

void SyntaxBlock::CFG::String::Inner::Operand::Cancel(bool isSendingSignal)
{
    if (isSendingSignal)
    {
        // #pragma omp critical
        // {
        onErrorOccurs(syntaxBlock->MakeMessage(syntaxBlock->GetCurrentToken(), MessagePool::StringInner["Operand"]));
        // }
    }
    syntaxBlock->currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::String::Inner::Operand::Check(bool isSendingSignal, bool isCheckingInner)
{
    beginningIndex = syntaxBlock->currentTokenIndexInVector;

    if (SyntaxBlock::CFG::String::Inner::Operand::Unary(syntaxBlock).Check(false, isCheckingInner))
    {
        return true;
    }
    if (SyntaxBlock::CFG::String::Inner::Operand::Binary(syntaxBlock).Check(false, isCheckingInner))
    {
        return true;
    }
    Cancel(isSendingSignal);
    return false;
}

void SyntaxBlock::CFG::String::Inner::Cancel(bool isSendingSignal)
{
    if (isSendingSignal)
    {
        // #pragma omp critical
        // {
        onErrorOccurs(syntaxBlock->MakeMessage(syntaxBlock->GetCurrentToken(), MessagePool::StringInner["Inner"]));
        // }
    }
    syntaxBlock->currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::String::Inner::Check(bool isSendingSignal)
{
    beginningIndex = syntaxBlock->currentTokenIndexInVector;

    if (!SyntaxBlock::CFG::Symbol::OpeningCurlyBrace(syntaxBlock).Check(isSendingSignal))
    {
        Cancel(isSendingSignal);
        return false;
    }
    if (!SyntaxBlock::CFG::String::Inner::Operation(syntaxBlock).Check(isSendingSignal))
    {
        Cancel(isSendingSignal);
        return false;
    }
    if (!SyntaxBlock::CFG::Symbol::Comma(syntaxBlock).Check(isSendingSignal))
    {
        Cancel(isSendingSignal);
        return false;
    }
    if (!SyntaxBlock::CFG::String::Inner::Operand(syntaxBlock).Check(isSendingSignal))
    {
        Cancel(isSendingSignal);
        return false;
    }
    if (!SyntaxBlock::CFG::Symbol::ClosingCurlyBrace(syntaxBlock).Check(isSendingSignal))
    {
        Cancel(isSendingSignal);
        return false;
    }
    return true;
}

void SyntaxBlock::CFG::String::Logical::Cancel(bool isSendingSignal)
{
    if (isSendingSignal)
    {
        // #pragma omp critical
        // {
        onErrorOccurs(syntaxBlock->MakeMessage(syntaxBlock->GetCurrentToken(), MessagePool::String["Logical"]));
        // }
    }
    syntaxBlock->currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::String::Logical::Check(bool isSendingSignal, bool isCheckingInner)
{
    beginningIndex = syntaxBlock->currentTokenIndexInVector;

    auto openingCurlyBrace = SyntaxBlock::CFG::Symbol::OpeningCurlyBrace(syntaxBlock);
    if (openingCurlyBrace.Check(false))
    {
        openingCurlyBrace.Cancel(false);
        if (!isCheckingInner)
        {
            return true;
        }
        if (!SyntaxBlock::CFG::String::Inner(syntaxBlock).Check(isSendingSignal))
        {
            Cancel(isSendingSignal);
            return false;
        }
        return true;
    }

    // если нет логической части (то есть вид `[...]=;[...]`), проверяем, есть ли впереди знак `;` и возвращаемся обратно
    if (SyntaxBlock::CFG::Symbol::Semicolon(syntaxBlock).Check(false))
    {
        Cancel(false);
        return true;
    }
    Cancel(isSendingSignal);
    return false;
}

void SyntaxBlock::CFG::String::Arithmetic::Cancel(bool isSendingSignal)
{
    if (isSendingSignal)
    {
        // #pragma omp critical
        // {
        onErrorOccurs(syntaxBlock->MakeMessage(syntaxBlock->GetCurrentToken(), MessagePool::String["Arithmetic"]));
        // }
    }
    syntaxBlock->currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::String::Arithmetic::Check(bool isSendingSignal, bool isCheckingInner)
{
    beginningIndex = syntaxBlock->currentTokenIndexInVector;

    if (SyntaxBlock::CFG::String::Arithmetic::NoRealSolution(syntaxBlock).Check(false))
    {
        return true;
    }
    
    auto openingCurlyBrace = SyntaxBlock::CFG::Symbol::OpeningCurlyBrace(syntaxBlock);
    if (openingCurlyBrace.Check(false))
    {
        openingCurlyBrace.Cancel(false);
        if (!isCheckingInner)
        {
            return true;
        }
        if (!SyntaxBlock::CFG::String::Inner(syntaxBlock).Check(isSendingSignal))
        {
            Cancel(isSendingSignal);
            return false;
        }
        return true;
    }
    if (SyntaxBlock::CFG::Variable::Integer(syntaxBlock).Check(false))
    {
        return true;
    }
    if (SyntaxBlock::CFG::Variable::Edge(syntaxBlock).Check(false))
    {
        return true;
    }
    Cancel(isSendingSignal);
    return false;
}

void SyntaxBlock::CFG::String::Arithmetic::NoRealSolution::Cancel(bool isSendingSignal)
{
    if (isSendingSignal)
    {
        // #pragma omp critical
        // {
        onErrorOccurs(syntaxBlock->MakeMessage(syntaxBlock->GetCurrentToken(), MessagePool::String["ArithmeticNoRealSolution"]));
        // }
    }
    syntaxBlock->currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::String::Arithmetic::NoRealSolution::Check(bool isSendingSignal)
{
    beginningIndex = syntaxBlock->currentTokenIndexInVector;

    if (!SyntaxBlock::CFG::Symbol::OpeningCurlyBrace(syntaxBlock).Check(isSendingSignal))
    {
        Cancel(isSendingSignal);
        return false;
    }
    if (!SyntaxBlock::CFG::Symbol::QuotationMark(syntaxBlock).Check(isSendingSignal))
    {
        Cancel(isSendingSignal);
        return false;
    }
    if (!SyntaxBlock::CFG::SpecialIdentifier::V(syntaxBlock).Check(isSendingSignal))
    {
        Cancel(isSendingSignal);
        return false;
    }
    if (!SyntaxBlock::CFG::Symbol::QuotationMark(syntaxBlock).Check(isSendingSignal))
    {
        Cancel(isSendingSignal);
        return false;
    }
    if (!SyntaxBlock::CFG::Symbol::Colon(syntaxBlock).Check(isSendingSignal))
    {
        Cancel(isSendingSignal);
        return false;
    }
    if (!SyntaxBlock::CFG::Symbol::QuotationMark(syntaxBlock).Check(isSendingSignal))
    {
        Cancel(isSendingSignal);
        return false;
    }
    if (!SyntaxBlock::CFG::SpecialIdentifier::No(syntaxBlock).Check(isSendingSignal))
    {
        Cancel(isSendingSignal);
        return false;
    }
    if (!SyntaxBlock::CFG::SpecialIdentifier::Real(syntaxBlock).Check(isSendingSignal))
    {
        Cancel(isSendingSignal);
        return false;
    }
    if (!SyntaxBlock::CFG::SpecialIdentifier::Solution(syntaxBlock).Check(isSendingSignal))
    {
        Cancel(isSendingSignal);
        return false;
    }
    if (!SyntaxBlock::CFG::Symbol::QuotationMark(syntaxBlock).Check(isSendingSignal))
    {
        Cancel(isSendingSignal);
        return false;
    }
    if (!SyntaxBlock::CFG::Symbol::ClosingCurlyBrace(syntaxBlock).Check(isSendingSignal))
    {
        Cancel(isSendingSignal);
        return false;
    }
    
    return true;
}

void SyntaxBlock::CFG::String::Cancel(bool isSendingSignal)
{
    if (isSendingSignal)
    {
        // #pragma omp critical
        // {
        onErrorOccurs(syntaxBlock->MakeMessage(syntaxBlock->GetCurrentToken(), MessagePool::String["String"]));
        // }
    }
    syntaxBlock->currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::String::Check(bool isSendingSignal)
{
    beginningIndex = syntaxBlock->currentTokenIndexInVector;

    if (!SyntaxBlock::CFG::String::Beginning(syntaxBlock).Check(isSendingSignal))
    {
        Cancel(isSendingSignal);
        return false;
    }
    if (!SyntaxBlock::CFG::Symbol::EqualSign(syntaxBlock).Check(isSendingSignal))
    {
        Cancel(isSendingSignal);
        return false;
    }
    if (!SyntaxBlock::CFG::String::Logical(syntaxBlock).Check(isSendingSignal))
    {
        Cancel(isSendingSignal);
        return false;
    }
    if (!SyntaxBlock::CFG::Symbol::Semicolon(syntaxBlock).Check(isSendingSignal))
    {
        Cancel(isSendingSignal);
        return false;
    }
    if (!SyntaxBlock::CFG::String::Arithmetic(syntaxBlock).Check(isSendingSignal))
    {
        Cancel(isSendingSignal);
        return false;
    }
    if (syntaxBlock->currentTokenIndexInVector != syntaxBlock->tokenVector.size())
    {
        Cancel(isSendingSignal);
        return false;
    }

    return true;
}

void SyntaxBlock::CFG::String::CheckAllInnerParts(bool isSendingSignal, bool isCheckingInner)
{
    beginningIndex = syntaxBlock->currentTokenIndexInVector;
    for (int currentIndex = beginningIndex; currentIndex < syntaxBlock->tokenVector.size(); currentIndex++)
    {
        syntaxBlock->currentTokenIndexInVector = currentIndex;
        auto identifier = SyntaxBlock::CFG::Variable::Identifier(syntaxBlock);
        if (SyntaxBlock::CFG::Symbol::EqualSign(syntaxBlock).Check(false))
        {
            auto openingCurlyBrace = SyntaxBlock::CFG::Symbol::OpeningCurlyBrace(syntaxBlock);
            if (openingCurlyBrace.Check(false))
            {
                openingCurlyBrace.Cancel(false);
                SyntaxBlock::CFG::String::Logical(syntaxBlock).Check(isSendingSignal, isCheckingInner);
            }
        }
        else if (SyntaxBlock::CFG::Symbol::Semicolon(syntaxBlock).Check(false))
        {
            SyntaxBlock::CFG::String::Arithmetic(syntaxBlock).Check(isSendingSignal, isCheckingInner);
        }
        // проверка граней (Edge)
        else if (identifier.Check(false))
        {
            auto openingParenthesis = SyntaxBlock::CFG::Symbol::OpeningParenthesis(syntaxBlock);
            if (openingParenthesis.Check(false))
            {
                openingParenthesis.Cancel(false);
                identifier.Cancel(false);
                
                if (SyntaxBlock::CFG::Variable::Edge(syntaxBlock).Check(isSendingSignal))
                {
                    currentIndex = syntaxBlock->currentTokenIndexInVector-1;
                }
            }
        }
        // проверка операций (Operation)
        else if (SyntaxBlock::CFG::Symbol::OpeningCurlyBrace(syntaxBlock).Check(false))
        {
            if (SyntaxBlock::CFG::String::Inner::Operation(syntaxBlock).Check(isSendingSignal))
            {
                currentIndex = syntaxBlock->currentTokenIndexInVector-1;
            }
        }
        // проверка операндов (Operand)
        else if (SyntaxBlock::CFG::Symbol::Comma(syntaxBlock).Check(false))
        {
            auto quotationMark = SyntaxBlock::CFG::Symbol::QuotationMark(syntaxBlock);
            // проверяем на кавычки, т. к. запятые могут встречаться в гранях (Edge)
            if (quotationMark.Check(false))
            {
                quotationMark.Cancel(false);

                if (SyntaxBlock::CFG::String::Inner::Operand::Variable(syntaxBlock).Check(isSendingSignal, isCheckingInner))
                {
                    currentIndex = syntaxBlock->currentTokenIndexInVector-1;
                }
            }
        }
        
    }
    syntaxBlock->currentTokenIndexInVector = beginningIndex;
}