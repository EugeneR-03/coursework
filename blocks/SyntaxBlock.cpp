#include "SyntaxBlock.hpp"

using VariableToken = std::variant<SimpleToken, ComplexToken>;

SyntaxBlockWorkingMode SyntaxBlock::workingMode = SyntaxBlockWorkingMode::UntilFirstError;
std::vector<VariableToken> SyntaxBlock::tokenVector;
int SyntaxBlock::currentTokenIndexInVector = 0;
int SyntaxBlock::stringIndex = 0;

int SyntaxBlock::CFG::Symbol::OpeningCurlyBrace::beginningIndex;
boost::signals2::signal<void (Message)> SyntaxBlock::CFG::Symbol::OpeningCurlyBrace::onErrorOccurs;

int SyntaxBlock::CFG::Symbol::ClosingCurlyBrace::beginningIndex;
boost::signals2::signal<void (Message)> SyntaxBlock::CFG::Symbol::ClosingCurlyBrace::onErrorOccurs;

int SyntaxBlock::CFG::Symbol::OpeningParenthesis::beginningIndex;
boost::signals2::signal<void (Message)> SyntaxBlock::CFG::Symbol::OpeningParenthesis::onErrorOccurs;

int SyntaxBlock::CFG::Symbol::ClosingParenthesis::beginningIndex;
boost::signals2::signal<void (Message)> SyntaxBlock::CFG::Symbol::ClosingParenthesis::onErrorOccurs;

int SyntaxBlock::CFG::Symbol::Comma::beginningIndex;
boost::signals2::signal<void (Message)> SyntaxBlock::CFG::Symbol::Comma::onErrorOccurs;

int SyntaxBlock::CFG::Symbol::Colon::beginningIndex;
boost::signals2::signal<void (Message)> SyntaxBlock::CFG::Symbol::Colon::onErrorOccurs;

int SyntaxBlock::CFG::Symbol::Semicolon::beginningIndex;
boost::signals2::signal<void (Message)> SyntaxBlock::CFG::Symbol::Semicolon::onErrorOccurs;

int SyntaxBlock::CFG::Symbol::QuotationMark::beginningIndex;
boost::signals2::signal<void (Message)> SyntaxBlock::CFG::Symbol::QuotationMark::onErrorOccurs;

int SyntaxBlock::CFG::Symbol::EqualSign::beginningIndex;
boost::signals2::signal<void (Message)> SyntaxBlock::CFG::Symbol::EqualSign::onErrorOccurs;

int SyntaxBlock::CFG::Symbol::ComparisonSign::beginningIndex;
boost::signals2::signal<void (Message)> SyntaxBlock::CFG::Symbol::ComparisonSign::onErrorOccurs;

int SyntaxBlock::CFG::Symbol::ExclamationMark::beginningIndex;
boost::signals2::signal<void (Message)> SyntaxBlock::CFG::Symbol::ExclamationMark::onErrorOccurs;

int SyntaxBlock::CFG::Symbol::ArithmeticSign::beginningIndex;
boost::signals2::signal<void (Message)> SyntaxBlock::CFG::Symbol::ArithmeticSign::onErrorOccurs;

int SyntaxBlock::CFG::Symbol::LogicalSign::beginningIndex;
boost::signals2::signal<void (Message)> SyntaxBlock::CFG::Symbol::LogicalSign::onErrorOccurs;

int SyntaxBlock::CFG::SpecialIdentifier::Operation::beginningIndex;
boost::signals2::signal<void (Message)> SyntaxBlock::CFG::SpecialIdentifier::Operation::onErrorOccurs;

int SyntaxBlock::CFG::SpecialIdentifier::OperandOfUnaryOperation::beginningIndex;
boost::signals2::signal<void (Message)> SyntaxBlock::CFG::SpecialIdentifier::OperandOfUnaryOperation::onErrorOccurs;

int SyntaxBlock::CFG::SpecialIdentifier::FirstOperandOfBinaryOperation::beginningIndex;
boost::signals2::signal<void (Message)> SyntaxBlock::CFG::SpecialIdentifier::FirstOperandOfBinaryOperation::onErrorOccurs;

int SyntaxBlock::CFG::SpecialIdentifier::SecondOperandOfBinaryOperation::beginningIndex;
boost::signals2::signal<void (Message)> SyntaxBlock::CFG::SpecialIdentifier::SecondOperandOfBinaryOperation::onErrorOccurs;

int SyntaxBlock::CFG::SpecialIdentifier::V::beginningIndex;
boost::signals2::signal<void (Message)> SyntaxBlock::CFG::SpecialIdentifier::V::onErrorOccurs;

int SyntaxBlock::CFG::SpecialIdentifier::No::beginningIndex;
boost::signals2::signal<void (Message)> SyntaxBlock::CFG::SpecialIdentifier::No::onErrorOccurs;

int SyntaxBlock::CFG::SpecialIdentifier::Real::beginningIndex;
boost::signals2::signal<void (Message)> SyntaxBlock::CFG::SpecialIdentifier::Real::onErrorOccurs;

int SyntaxBlock::CFG::SpecialIdentifier::Solution::beginningIndex;
boost::signals2::signal<void (Message)> SyntaxBlock::CFG::SpecialIdentifier::Solution::onErrorOccurs;

int SyntaxBlock::CFG::SpecialIdentifier::Modulus::beginningIndex;
boost::signals2::signal<void (Message)> SyntaxBlock::CFG::SpecialIdentifier::Modulus::onErrorOccurs;

int SyntaxBlock::CFG::SpecialIdentifier::SquareOfNumber::beginningIndex;
boost::signals2::signal<void (Message)> SyntaxBlock::CFG::SpecialIdentifier::SquareOfNumber::onErrorOccurs;

int SyntaxBlock::CFG::SpecialIdentifier::SquareRootOfNumber::beginningIndex;
boost::signals2::signal<void (Message)> SyntaxBlock::CFG::SpecialIdentifier::SquareRootOfNumber::onErrorOccurs;


int SyntaxBlock::CFG::Variable::beginningIndex;
boost::signals2::signal<void (Message)> SyntaxBlock::CFG::Variable::onErrorOccurs;

int SyntaxBlock::CFG::Variable::Edge::beginningIndex;
boost::signals2::signal<void (Message)> SyntaxBlock::CFG::Variable::Edge::onErrorOccurs;

int SyntaxBlock::CFG::Variable::Identifier::beginningIndex;
boost::signals2::signal<void (Message)> SyntaxBlock::CFG::Variable::Identifier::onErrorOccurs;

int SyntaxBlock::CFG::Variable::Integer::beginningIndex;
boost::signals2::signal<void (Message)> SyntaxBlock::CFG::Variable::Integer::onErrorOccurs;

int SyntaxBlock::CFG::Operation::beginningIndex;
boost::signals2::signal<void (Message)> SyntaxBlock::CFG::Operation::onErrorOccurs;

int SyntaxBlock::CFG::Operation::Logical::beginningIndex;
boost::signals2::signal<void (Message)> SyntaxBlock::CFG::Operation::Logical::onErrorOccurs;

int SyntaxBlock::CFG::Operation::Arithmetic::beginningIndex;
boost::signals2::signal<void (Message)> SyntaxBlock::CFG::Operation::Arithmetic::onErrorOccurs;

int SyntaxBlock::CFG::String::beginningIndex;
boost::signals2::signal<void (Message)> SyntaxBlock::CFG::String::onErrorOccurs;

int SyntaxBlock::CFG::String::Beginning::beginningIndex;
boost::signals2::signal<void (Message)> SyntaxBlock::CFG::String::Beginning::onErrorOccurs;

int SyntaxBlock::CFG::String::Logical::beginningIndex;
boost::signals2::signal<void (Message)> SyntaxBlock::CFG::String::Logical::onErrorOccurs;

int SyntaxBlock::CFG::String::Arithmetic::beginningIndex;
boost::signals2::signal<void (Message)> SyntaxBlock::CFG::String::Arithmetic::onErrorOccurs;

int SyntaxBlock::CFG::String::Arithmetic::NoRealSolution::beginningIndex;
boost::signals2::signal<void (Message)> SyntaxBlock::CFG::String::Arithmetic::NoRealSolution::onErrorOccurs;

int SyntaxBlock::CFG::String::Inner::beginningIndex;
boost::signals2::signal<void (Message)> SyntaxBlock::CFG::String::Inner::onErrorOccurs;

int SyntaxBlock::CFG::String::Inner::Operation::beginningIndex;
boost::signals2::signal<void (Message)> SyntaxBlock::CFG::String::Inner::Operation::onErrorOccurs;

int SyntaxBlock::CFG::String::Inner::Operand::beginningIndex;
boost::signals2::signal<void (Message)> SyntaxBlock::CFG::String::Inner::Operand::onErrorOccurs;

int SyntaxBlock::CFG::String::Inner::Operand::Variable::beginningIndex;
boost::signals2::signal<void (Message)> SyntaxBlock::CFG::String::Inner::Operand::Variable::onErrorOccurs;

int SyntaxBlock::CFG::String::Inner::Operand::Unary::beginningIndex;
boost::signals2::signal<void (Message)> SyntaxBlock::CFG::String::Inner::Operand::Unary::onErrorOccurs;

int SyntaxBlock::CFG::String::Inner::Operand::Binary::beginningIndex;
boost::signals2::signal<void (Message)> SyntaxBlock::CFG::String::Inner::Operand::Binary::onErrorOccurs;

int SyntaxBlock::CFG::String::Inner::Operand::Binary::First::beginningIndex;
boost::signals2::signal<void (Message)> SyntaxBlock::CFG::String::Inner::Operand::Binary::First::onErrorOccurs;

int SyntaxBlock::CFG::String::Inner::Operand::Binary::Second::beginningIndex;
boost::signals2::signal<void (Message)> SyntaxBlock::CFG::String::Inner::Operand::Binary::Second::onErrorOccurs;

SyntaxBlockWorkingMode SyntaxBlock::GetWorkingMode()
{
    return SyntaxBlock::workingMode;
}

void SyntaxBlock::SetWorkingMode(SyntaxBlockWorkingMode workingMode)
{
    SyntaxBlock::workingMode = workingMode;
}

int SyntaxBlock::GetStringIndex()
{
    return SyntaxBlock::stringIndex;
}

void SyntaxBlock::SetStringIndex(int index)
{
    SyntaxBlock::stringIndex = index;
}

void SyntaxBlock::LoadTokenVector(std::vector<VariableToken> tokenVector)
{
    SyntaxBlock::tokenVector = tokenVector;
    SyntaxBlock::currentTokenIndexInVector = 0;
}

void SyntaxBlock::LoadToken()
{
    SyntaxBlock::currentTokenIndexInVector++;
}

VariableToken SyntaxBlock::GetCurrentToken()
{
    return SyntaxBlock::tokenVector[SyntaxBlock::currentTokenIndexInVector];
}

int SyntaxBlock::GetCurrentTokenIndex()
{
    auto token = SyntaxBlock::GetCurrentToken();
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
    SyntaxBlock::currentTokenIndexInVector--;
}

Message SyntaxBlock::MakeMessage(VariableToken token, std::string message)
{
    Message fullMessage;
    if (std::holds_alternative<SimpleToken>(token))
    {
        fullMessage = Message(SyntaxBlock::GetStringIndex(), std::get<SimpleToken>(token).index, message);
    }
    else
    {
        fullMessage = Message(SyntaxBlock::GetStringIndex(), std::get<ComplexToken>(token).index, std::get<ComplexToken>(token).value, message);
    }
    return fullMessage;
}


// Symbol
void SyntaxBlock::CFG::Symbol::OpeningCurlyBrace::Cancel(bool isSendingSignal)
{
    if (isSendingSignal)
    {
        onErrorOccurs(SyntaxBlock::MakeMessage(SyntaxBlock::GetCurrentToken(), MessagePool::Symbol["OpeningCurlyBrace"]));
    }
    SyntaxBlock::currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::Symbol::OpeningCurlyBrace::Check(bool isSendingSignal)
{
    beginningIndex = SyntaxBlock::currentTokenIndexInVector;

    VariableToken token = SyntaxBlock::GetCurrentToken();
    if (std::holds_alternative<SimpleToken>(token))
    {
        SimpleToken tokenOpeningCurlyBrace = std::get<SimpleToken>(token);
        if (tokenOpeningCurlyBrace.type == SimpleTokenType::OpeningCurlyBrace)
        {
            SyntaxBlock::LoadToken();
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
        onErrorOccurs(SyntaxBlock::MakeMessage(SyntaxBlock::GetCurrentToken(), MessagePool::Symbol["ClosingCurlyBrace"]));
    }
    SyntaxBlock::currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::Symbol::ClosingCurlyBrace::Check(bool isSendingSignal)
{
    beginningIndex = SyntaxBlock::currentTokenIndexInVector;

    VariableToken token = SyntaxBlock::GetCurrentToken();
    if (std::holds_alternative<SimpleToken>(token))
    {
        SimpleToken tokenClosingCurlyBrace = std::get<SimpleToken>(token);
        if (tokenClosingCurlyBrace.type == SimpleTokenType::ClosingCurlyBrace)
        {
            SyntaxBlock::LoadToken();
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
        onErrorOccurs(SyntaxBlock::MakeMessage(SyntaxBlock::GetCurrentToken(), MessagePool::Symbol["OpeningParenthesis"]));
    }
    SyntaxBlock::currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::Symbol::OpeningParenthesis::Check(bool isSendingSignal)
{
    beginningIndex = SyntaxBlock::currentTokenIndexInVector;

    VariableToken token = SyntaxBlock::GetCurrentToken();
    if (std::holds_alternative<SimpleToken>(token))
    {
        SimpleToken tokenOpeningParenthesis = std::get<SimpleToken>(token);
        if (tokenOpeningParenthesis.type == SimpleTokenType::OpeningParenthesis)
        {
            SyntaxBlock::LoadToken();
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
        onErrorOccurs(SyntaxBlock::MakeMessage(SyntaxBlock::GetCurrentToken(), MessagePool::Symbol["ClosingParenthesis"]));
    }
    SyntaxBlock::currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::Symbol::ClosingParenthesis::Check(bool isSendingSignal)
{
    beginningIndex = SyntaxBlock::currentTokenIndexInVector;

    VariableToken token = SyntaxBlock::GetCurrentToken();
    if (std::holds_alternative<SimpleToken>(token))
    {
        SimpleToken tokenClosingParenthesis = std::get<SimpleToken>(token);
        if (tokenClosingParenthesis.type == SimpleTokenType::ClosingParenthesis)
        {
            SyntaxBlock::LoadToken();
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
        onErrorOccurs(SyntaxBlock::MakeMessage(SyntaxBlock::GetCurrentToken(), MessagePool::Symbol["Comma"]));
    }
    SyntaxBlock::currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::Symbol::Comma::Check(bool isSendingSignal)
{
    beginningIndex = SyntaxBlock::currentTokenIndexInVector;

    VariableToken token = SyntaxBlock::GetCurrentToken();
    if (std::holds_alternative<SimpleToken>(token))
    {
        SimpleToken tokenComma = std::get<SimpleToken>(token);
        if (tokenComma.type == SimpleTokenType::Comma)
        {
            SyntaxBlock::LoadToken();
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
        onErrorOccurs(SyntaxBlock::MakeMessage(SyntaxBlock::GetCurrentToken(), MessagePool::Symbol["Colon"]));
    }
    SyntaxBlock::currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::Symbol::Colon::Check(bool isSendingSignal)
{
    beginningIndex = SyntaxBlock::currentTokenIndexInVector;

    VariableToken token = SyntaxBlock::GetCurrentToken();
    if (std::holds_alternative<SimpleToken>(token))
    {
        SimpleToken tokenColon = std::get<SimpleToken>(token);
        if (tokenColon.type == SimpleTokenType::Colon)
        {
            SyntaxBlock::LoadToken();
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
        onErrorOccurs(SyntaxBlock::MakeMessage(SyntaxBlock::GetCurrentToken(), MessagePool::Symbol["Semicolon"]));
    }
    SyntaxBlock::currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::Symbol::Semicolon::Check(bool isSendingSignal)
{
    beginningIndex = SyntaxBlock::currentTokenIndexInVector;

    VariableToken token = SyntaxBlock::GetCurrentToken();
    if (std::holds_alternative<SimpleToken>(token))
    {
        SimpleToken tokenSemicolon = std::get<SimpleToken>(token);
        if (tokenSemicolon.type == SimpleTokenType::Semicolon)
        {
            SyntaxBlock::LoadToken();
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
        onErrorOccurs(SyntaxBlock::MakeMessage(SyntaxBlock::GetCurrentToken(), MessagePool::Symbol["QuotationMark"]));
    }
    SyntaxBlock::currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::Symbol::QuotationMark::Check(bool isSendingSignal)
{
    beginningIndex = SyntaxBlock::currentTokenIndexInVector;

    VariableToken token = SyntaxBlock::GetCurrentToken();
    if (std::holds_alternative<SimpleToken>(token))
    {
        SimpleToken tokenQuotationMark = std::get<SimpleToken>(token);
        if (tokenQuotationMark.type == SimpleTokenType::QuotationMark)
        {
            SyntaxBlock::LoadToken();
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
        onErrorOccurs(SyntaxBlock::MakeMessage(SyntaxBlock::GetCurrentToken(), MessagePool::Symbol["EqualSign"]));
    }
    SyntaxBlock::currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::Symbol::EqualSign::Check(bool isSendingSignal)
{
    beginningIndex = SyntaxBlock::currentTokenIndexInVector;

    VariableToken token = SyntaxBlock::GetCurrentToken();
    if (std::holds_alternative<SimpleToken>(token))
    {
        SimpleToken tokenEqualSign = std::get<SimpleToken>(token);
        if (tokenEqualSign.type == SimpleTokenType::EqualSign)
        {
            SyntaxBlock::LoadToken();
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
        onErrorOccurs(SyntaxBlock::MakeMessage(SyntaxBlock::GetCurrentToken(), MessagePool::Symbol["ComparisonSign"]));
    }
    SyntaxBlock::currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::Symbol::ComparisonSign::Check(bool isSendingSignal)
{
    beginningIndex = SyntaxBlock::currentTokenIndexInVector;

    VariableToken token = SyntaxBlock::GetCurrentToken();
    if (std::holds_alternative<SimpleToken>(token))
    {
        SimpleToken tokenComparisonSign = std::get<SimpleToken>(token);
        if (tokenComparisonSign.type == SimpleTokenType::ComparisonSign)
        {
            SyntaxBlock::LoadToken();
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
        onErrorOccurs(SyntaxBlock::MakeMessage(SyntaxBlock::GetCurrentToken(), MessagePool::Symbol["ExclamationMark"]));
    }
    SyntaxBlock::currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::Symbol::ExclamationMark::Check(bool isSendingSignal)
{
    beginningIndex = SyntaxBlock::currentTokenIndexInVector;

    VariableToken token = SyntaxBlock::GetCurrentToken();
    if (std::holds_alternative<SimpleToken>(token))
    {
        SimpleToken tokenExclamationMark = std::get<SimpleToken>(token);
        if (tokenExclamationMark.type == SimpleTokenType::ExclamationMark)
        {
            SyntaxBlock::LoadToken();
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
        onErrorOccurs(SyntaxBlock::MakeMessage(SyntaxBlock::GetCurrentToken(), MessagePool::Symbol["ArithmeticSign"]));
    }
    SyntaxBlock::currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::Symbol::ArithmeticSign::Check(bool isSendingSignal)
{
    beginningIndex = SyntaxBlock::currentTokenIndexInVector;

    VariableToken token = SyntaxBlock::GetCurrentToken();
    if (std::holds_alternative<SimpleToken>(token))
    {
        SimpleToken tokenArithmeticSign = std::get<SimpleToken>(token);
        if (tokenArithmeticSign.type == SimpleTokenType::ArithmeticSign)
        {
            SyntaxBlock::LoadToken();
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
        onErrorOccurs(SyntaxBlock::MakeMessage(SyntaxBlock::GetCurrentToken(), MessagePool::Symbol["LogicalSign"]));
    }
    SyntaxBlock::currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::Symbol::LogicalSign::Check(bool isSendingSignal)
{
    beginningIndex = SyntaxBlock::currentTokenIndexInVector;

    VariableToken token = SyntaxBlock::GetCurrentToken();
    if (std::holds_alternative<SimpleToken>(token))
    {
        SimpleToken tokenLogicalSign = std::get<SimpleToken>(token);
        if (tokenLogicalSign.type == SimpleTokenType::LogicalSign)
        {
            SyntaxBlock::LoadToken();
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
        onErrorOccurs(SyntaxBlock::MakeMessage(SyntaxBlock::GetCurrentToken(), MessagePool::SpecialIdentifier["Operation"]));
    }
    SyntaxBlock::currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::SpecialIdentifier::Operation::Check(bool isSendingSignal)
{
    beginningIndex = SyntaxBlock::currentTokenIndexInVector;

    VariableToken token = SyntaxBlock::GetCurrentToken();
    if (std::holds_alternative<ComplexToken>(token))
    {
        ComplexToken tokenOperationSpecialIdentifier = std::get<ComplexToken>(token);
        if (std::holds_alternative<SpecialIdentifierType>(tokenOperationSpecialIdentifier.type))
        {
            SpecialIdentifierType tokenOperationSpecialIdentifierType = std::get<SpecialIdentifierType>(tokenOperationSpecialIdentifier.type);
            if (tokenOperationSpecialIdentifierType == SpecialIdentifierType::Operation)
            {
                SyntaxBlock::LoadToken();
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
        onErrorOccurs(SyntaxBlock::MakeMessage(SyntaxBlock::GetCurrentToken(), MessagePool::SpecialIdentifier["OperandOfUnaryOperation"]));
    }
    SyntaxBlock::currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::SpecialIdentifier::OperandOfUnaryOperation::Check(bool isSendingSignal)
{
    beginningIndex = SyntaxBlock::currentTokenIndexInVector;

    VariableToken token = SyntaxBlock::GetCurrentToken();
    if (std::holds_alternative<ComplexToken>(token))
    {
        ComplexToken tokenOperandOfUnaryOperationSpecialIdentifier = std::get<ComplexToken>(token);
        if (std::holds_alternative<SpecialIdentifierType>(tokenOperandOfUnaryOperationSpecialIdentifier.type))
        {
            SpecialIdentifierType tokenOperandOfUnaryOperationSpecialIdentifierType = std::get<SpecialIdentifierType>(tokenOperandOfUnaryOperationSpecialIdentifier.type);
            if (tokenOperandOfUnaryOperationSpecialIdentifierType == SpecialIdentifierType::OperandOfUnaryOperation)
            {
                SyntaxBlock::LoadToken();
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
        onErrorOccurs(SyntaxBlock::MakeMessage(SyntaxBlock::GetCurrentToken(), MessagePool::SpecialIdentifier["FirstOperandOfBinaryOperation"]));
    }
    SyntaxBlock::currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::SpecialIdentifier::FirstOperandOfBinaryOperation::Check(bool isSendingSignal)
{
    beginningIndex = SyntaxBlock::currentTokenIndexInVector;

    VariableToken token = SyntaxBlock::GetCurrentToken();
    if (std::holds_alternative<ComplexToken>(token))
    {
        ComplexToken tokenFirstOperandOfBinaryOperationSpecialIdentifier = std::get<ComplexToken>(token);
        if (std::holds_alternative<SpecialIdentifierType>(tokenFirstOperandOfBinaryOperationSpecialIdentifier.type))
        {
            SpecialIdentifierType tokenFirstOperandOfBinaryOperationSpecialIdentifierType = std::get<SpecialIdentifierType>(tokenFirstOperandOfBinaryOperationSpecialIdentifier.type);
            if (tokenFirstOperandOfBinaryOperationSpecialIdentifierType == SpecialIdentifierType::FirstOperandOfBinaryOperation)
            {
                SyntaxBlock::LoadToken();
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
        onErrorOccurs(SyntaxBlock::MakeMessage(SyntaxBlock::GetCurrentToken(), MessagePool::SpecialIdentifier["SecondOperandOfBinaryOperation"]));
    }
    SyntaxBlock::currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::SpecialIdentifier::SecondOperandOfBinaryOperation::Check(bool isSendingSignal)
{
    beginningIndex = SyntaxBlock::currentTokenIndexInVector;

    VariableToken token = SyntaxBlock::GetCurrentToken();
    if (std::holds_alternative<ComplexToken>(token))
    {
        ComplexToken tokenSecondOperandOfBinaryOperationSpecialIdentifier = std::get<ComplexToken>(token);
        if (std::holds_alternative<SpecialIdentifierType>(tokenSecondOperandOfBinaryOperationSpecialIdentifier.type))
        {
            SpecialIdentifierType tokenSecondOperandOfBinaryOperationSpecialIdentifierType = std::get<SpecialIdentifierType>(tokenSecondOperandOfBinaryOperationSpecialIdentifier.type);
            if (tokenSecondOperandOfBinaryOperationSpecialIdentifierType == SpecialIdentifierType::SecondOperandOfBinaryOperation)
            {
                SyntaxBlock::LoadToken();
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
        onErrorOccurs(SyntaxBlock::MakeMessage(SyntaxBlock::GetCurrentToken(), MessagePool::SpecialIdentifier["V"]));
    }
    SyntaxBlock::currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::SpecialIdentifier::V::Check(bool isSendingSignal)
{
    beginningIndex = SyntaxBlock::currentTokenIndexInVector;

    VariableToken token = SyntaxBlock::GetCurrentToken();
    if (std::holds_alternative<ComplexToken>(token))
    {
        ComplexToken tokenVSpecialIdentifier = std::get<ComplexToken>(token);
        if (std::holds_alternative<SpecialIdentifierType>(tokenVSpecialIdentifier.type))
        {
            SpecialIdentifierType tokenVSpecialIdentifierType = std::get<SpecialIdentifierType>(tokenVSpecialIdentifier.type);
            if (tokenVSpecialIdentifierType == SpecialIdentifierType::V)
            {
                SyntaxBlock::LoadToken();
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
        onErrorOccurs(SyntaxBlock::MakeMessage(SyntaxBlock::GetCurrentToken(), MessagePool::SpecialIdentifier["No"]));
    }
    SyntaxBlock::currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::SpecialIdentifier::No::Check(bool isSendingSignal)
{
    beginningIndex = SyntaxBlock::currentTokenIndexInVector;

    VariableToken token = SyntaxBlock::GetCurrentToken();
    if (std::holds_alternative<ComplexToken>(token))
    {
        ComplexToken tokenNoSpecialIdentifier = std::get<ComplexToken>(token);
        if (std::holds_alternative<SpecialIdentifierType>(tokenNoSpecialIdentifier.type))
        {
            SpecialIdentifierType tokenNoSpecialIdentifierType = std::get<SpecialIdentifierType>(tokenNoSpecialIdentifier.type);
            if (tokenNoSpecialIdentifierType == SpecialIdentifierType::No)
            {
                SyntaxBlock::LoadToken();
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
        onErrorOccurs(SyntaxBlock::MakeMessage(SyntaxBlock::GetCurrentToken(), MessagePool::SpecialIdentifier["Real"]));
    }
    SyntaxBlock::currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::SpecialIdentifier::Real::Check(bool isSendingSignal)
{
    beginningIndex = SyntaxBlock::currentTokenIndexInVector;

    VariableToken token = SyntaxBlock::GetCurrentToken();
    if (std::holds_alternative<ComplexToken>(token))
    {
        ComplexToken tokenRealSpecialIdentifier = std::get<ComplexToken>(token);
        if (std::holds_alternative<SpecialIdentifierType>(tokenRealSpecialIdentifier.type))
        {
            SpecialIdentifierType tokenRealSpecialIdentifierType = std::get<SpecialIdentifierType>(tokenRealSpecialIdentifier.type);
            if (tokenRealSpecialIdentifierType == SpecialIdentifierType::Real)
            {
                SyntaxBlock::LoadToken();
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
        onErrorOccurs(SyntaxBlock::MakeMessage(SyntaxBlock::GetCurrentToken(), MessagePool::SpecialIdentifier["Solution"]));
    }
    SyntaxBlock::currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::SpecialIdentifier::Solution::Check(bool isSendingSignal)
{
    beginningIndex = SyntaxBlock::currentTokenIndexInVector;

    VariableToken token = SyntaxBlock::GetCurrentToken();
    if (std::holds_alternative<ComplexToken>(token))
    {
        ComplexToken tokenSolutionSpecialIdentifier = std::get<ComplexToken>(token);
        if (std::holds_alternative<SpecialIdentifierType>(tokenSolutionSpecialIdentifier.type))
        {
            SpecialIdentifierType tokenSolutionSpecialIdentifierType = std::get<SpecialIdentifierType>(tokenSolutionSpecialIdentifier.type);
            if (tokenSolutionSpecialIdentifierType == SpecialIdentifierType::Solution)
            {
                SyntaxBlock::LoadToken();
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
        onErrorOccurs(SyntaxBlock::MakeMessage(SyntaxBlock::GetCurrentToken(), MessagePool::SpecialIdentifier["Modulus"]));
    }
    SyntaxBlock::currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::SpecialIdentifier::Modulus::Check(bool isSendingSignal)
{
    beginningIndex = SyntaxBlock::currentTokenIndexInVector;

    VariableToken token = SyntaxBlock::GetCurrentToken();
    if (std::holds_alternative<ComplexToken>(token))
    {
        ComplexToken tokenModulusSpecialIdentifier = std::get<ComplexToken>(token);
        if (std::holds_alternative<SpecialIdentifierType>(tokenModulusSpecialIdentifier.type))
        {
            SpecialIdentifierType tokenModulusSpecialIdentifierType = std::get<SpecialIdentifierType>(tokenModulusSpecialIdentifier.type);
            if (tokenModulusSpecialIdentifierType == SpecialIdentifierType::Modulus)
            {
                SyntaxBlock::LoadToken();
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
        onErrorOccurs(SyntaxBlock::MakeMessage(SyntaxBlock::GetCurrentToken(), MessagePool::SpecialIdentifier["SquareOfNumber"]));
    }
    SyntaxBlock::currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::SpecialIdentifier::SquareOfNumber::Check(bool isSendingSignal)
{
    beginningIndex = SyntaxBlock::currentTokenIndexInVector;

    VariableToken token = SyntaxBlock::GetCurrentToken();
    if (std::holds_alternative<ComplexToken>(token))
    {
        ComplexToken tokenSquareOfNumberSpecialIdentifier = std::get<ComplexToken>(token);
        if (std::holds_alternative<SpecialIdentifierType>(tokenSquareOfNumberSpecialIdentifier.type))
        {
            SpecialIdentifierType tokenSquareOfNumberSpecialIdentifierType = std::get<SpecialIdentifierType>(tokenSquareOfNumberSpecialIdentifier.type);
            if (tokenSquareOfNumberSpecialIdentifierType == SpecialIdentifierType::SquareOfNumber)
            {
                SyntaxBlock::LoadToken();
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
        onErrorOccurs(SyntaxBlock::MakeMessage(SyntaxBlock::GetCurrentToken(), MessagePool::SpecialIdentifier["SquareRootOfNumber"]));
    }
    SyntaxBlock::currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::SpecialIdentifier::SquareRootOfNumber::Check(bool isSendingSignal)
{
    beginningIndex = SyntaxBlock::currentTokenIndexInVector;

    VariableToken token = SyntaxBlock::GetCurrentToken();
    if (std::holds_alternative<ComplexToken>(token))
    {
        ComplexToken tokenSquareRootOfNumberSpecialIdentifier = std::get<ComplexToken>(token);
        if (std::holds_alternative<SpecialIdentifierType>(tokenSquareRootOfNumberSpecialIdentifier.type))
        {
            SpecialIdentifierType tokenSquareRootOfNumberSpecialIdentifierType = std::get<SpecialIdentifierType>(tokenSquareRootOfNumberSpecialIdentifier.type);
            if (tokenSquareRootOfNumberSpecialIdentifierType == SpecialIdentifierType::SquareRootOfNumber)
            {
                SyntaxBlock::LoadToken();
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
        onErrorOccurs(SyntaxBlock::MakeMessage(SyntaxBlock::GetCurrentToken(), MessagePool::Variable["Identifier"]));
    }
    SyntaxBlock::currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::Variable::Identifier::Check(bool isSendingSignal)
{
    beginningIndex = SyntaxBlock::currentTokenIndexInVector;
    
    VariableToken token = SyntaxBlock::GetCurrentToken();
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
        SyntaxBlock::LoadToken();
        return true;
    }
    Cancel(isSendingSignal);
    return false;
}

void SyntaxBlock::CFG::Variable::Integer::Cancel(bool isSendingSignal)
{
    if (isSendingSignal)
    {
        onErrorOccurs(SyntaxBlock::MakeMessage(SyntaxBlock::GetCurrentToken(), MessagePool::Variable["Integer"]));
    }
    SyntaxBlock::currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::Variable::Integer::Check(bool isSendingSignal)
{
    beginningIndex = SyntaxBlock::currentTokenIndexInVector;

    VariableToken token = SyntaxBlock::GetCurrentToken();
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
            SyntaxBlock::LoadToken();
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
        onErrorOccurs(SyntaxBlock::MakeMessage(SyntaxBlock::GetCurrentToken(), MessagePool::Variable["Edge"]));
    }
    SyntaxBlock::currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::Variable::Edge::Check(bool isSendingSignal)
{
    beginningIndex = SyntaxBlock::currentTokenIndexInVector;

    if (!SyntaxBlock::CFG::Variable::Identifier::Check(isSendingSignal))
    {
        Cancel(isSendingSignal);
        return false;
    }

    if (!SyntaxBlock::CFG::Symbol::OpeningParenthesis::Check(isSendingSignal))
    {
        Cancel(isSendingSignal);
        return false;
    }

    if (!SyntaxBlock::CFG::Variable::Integer::Check(isSendingSignal))
    {
        Cancel(isSendingSignal);
        return false;
    }

    if (!SyntaxBlock::CFG::Symbol::Comma::Check(false))
    {
        if (!SyntaxBlock::CFG::Symbol::ClosingParenthesis::Check(isSendingSignal))
        {
            Cancel(isSendingSignal);
            return false;
        }

        return true;
    }
    else
    {
        if (!SyntaxBlock::CFG::Variable::Integer::Check(isSendingSignal))
        {
            Cancel(isSendingSignal);
            return false;
        }

        if (!SyntaxBlock::CFG::Symbol::ClosingParenthesis::Check(isSendingSignal))
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
        onErrorOccurs(SyntaxBlock::MakeMessage(SyntaxBlock::GetCurrentToken(), MessagePool::Variable["Variable"]));
    }
    SyntaxBlock::currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::Variable::Check(bool isSendingSignal)
{
    beginningIndex = SyntaxBlock::currentTokenIndexInVector;

    if (SyntaxBlock::CFG::Variable::Edge::Check(false))
    {
        return true;
    }
    else if (SyntaxBlock::CFG::Variable::Identifier::Check(false))
    {
        return true;
    }
    else if (SyntaxBlock::CFG::Variable::Integer::Check(false))
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
        onErrorOccurs(SyntaxBlock::MakeMessage(SyntaxBlock::GetCurrentToken(), MessagePool::Operation["Logical"]));
    }
    SyntaxBlock::currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::Operation::Logical::Check(bool isSendingSignal)
{
    beginningIndex = SyntaxBlock::currentTokenIndexInVector;

    if (SyntaxBlock::CFG::Symbol::ExclamationMark::Check(false))
    {
        if (SyntaxBlock::CFG::Symbol::EqualSign::Check(false))
        {
            return true;
        }
        Cancel(isSendingSignal);
        return false;
    }
    else if (SyntaxBlock::CFG::Symbol::EqualSign::Check(false))
    {
        if (SyntaxBlock::CFG::Symbol::EqualSign::Check(false))
        {
            return true;
        }
        Cancel(isSendingSignal);
        return false;
    }
    else if (SyntaxBlock::CFG::Symbol::ComparisonSign::Check(false))
    {
        if (SyntaxBlock::CFG::Symbol::EqualSign::Check(false))
        {
            return true;
        }
        return true;
    }
    else if (SyntaxBlock::CFG::Symbol::LogicalSign::Check(false))
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
        onErrorOccurs(SyntaxBlock::MakeMessage(SyntaxBlock::GetCurrentToken(), MessagePool::Operation["Arithmetic"]));
    }
    SyntaxBlock::currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::Operation::Arithmetic::Check(bool isSendingSignal)
{
    beginningIndex = SyntaxBlock::currentTokenIndexInVector;

    if (SyntaxBlock::CFG::Symbol::ArithmeticSign::Check(false))
    {
        return true;
    }
    if (SyntaxBlock::CFG::SpecialIdentifier::Modulus::Check(false))
    {
        return true;
    }
    if (SyntaxBlock::CFG::SpecialIdentifier::SquareOfNumber::Check(false))
    {
        return true;
    }
    if (SyntaxBlock::CFG::SpecialIdentifier::SquareRootOfNumber::Check(false))
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
        onErrorOccurs(SyntaxBlock::MakeMessage(SyntaxBlock::GetCurrentToken(), MessagePool::Operation["Operation"]));
    }
    SyntaxBlock::currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::Operation::Check(bool isSendingSignal)
{
    beginningIndex = SyntaxBlock::currentTokenIndexInVector;

    if (SyntaxBlock::CFG::Operation::Logical::Check(false))
    {
        return true;
    }
    if (SyntaxBlock::CFG::Operation::Arithmetic::Check(false))
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
        onErrorOccurs(SyntaxBlock::MakeMessage(SyntaxBlock::GetCurrentToken(), MessagePool::String["Beginning"]));
    }
    SyntaxBlock::currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::String::Beginning::Check(bool isSendingSignal)
{
    beginningIndex = SyntaxBlock::currentTokenIndexInVector;

    if (SyntaxBlock::CFG::Variable::Edge::Check(false))
    {
        return true;
    }
    if (SyntaxBlock::CFG::Variable::Identifier::Check(false))
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
        onErrorOccurs(SyntaxBlock::MakeMessage(SyntaxBlock::GetCurrentToken(), MessagePool::StringInner["Operation"]));
    }
    SyntaxBlock::currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::String::Inner::Operation::Check(bool isSendingSignal)
{
    beginningIndex = SyntaxBlock::currentTokenIndexInVector;

    if (!SyntaxBlock::CFG::Symbol::QuotationMark::Check(isSendingSignal))
    {
        Cancel(isSendingSignal);
        return false;
    }
    if (!SyntaxBlock::CFG::SpecialIdentifier::Operation::Check(isSendingSignal))
    {
        Cancel(isSendingSignal);
        return false;
    }
    if (!SyntaxBlock::CFG::Symbol::QuotationMark::Check(isSendingSignal))
    {
        Cancel(isSendingSignal);
        return false;
    }
    if (!SyntaxBlock::CFG::Symbol::Colon::Check(isSendingSignal))
    {
        Cancel(isSendingSignal);
        return false;
    }
    if (!SyntaxBlock::CFG::Symbol::QuotationMark::Check(isSendingSignal))
    {
        Cancel(isSendingSignal);
        return false;
    }
    if (!SyntaxBlock::CFG::Operation::Check(isSendingSignal))
    {
        Cancel(isSendingSignal);
        return false;
    }
    if (!SyntaxBlock::CFG::Symbol::QuotationMark::Check(isSendingSignal))
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
        onErrorOccurs(SyntaxBlock::MakeMessage(SyntaxBlock::GetCurrentToken(), MessagePool::StringInner["OperandUnary"]));
    }
    SyntaxBlock::currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::String::Inner::Operand::Unary::Check(bool isSendingSignal, bool isCheckingInner)
{
    beginningIndex = SyntaxBlock::currentTokenIndexInVector;

    if (!SyntaxBlock::CFG::Symbol::QuotationMark::Check(isSendingSignal))
    {
        Cancel(isSendingSignal);
        return false;
    }
    if (!SyntaxBlock::CFG::SpecialIdentifier::OperandOfUnaryOperation::Check(isSendingSignal))
    {
        Cancel(isSendingSignal);
        return false;
    }
    if (!SyntaxBlock::CFG::Symbol::QuotationMark::Check(isSendingSignal))
    {
        Cancel(isSendingSignal);
        return false;
    }
    if (!SyntaxBlock::CFG::Symbol::Colon::Check(isSendingSignal))
    {
        Cancel(isSendingSignal);
        return false;
    }
    if (SyntaxBlock::CFG::Symbol::OpeningCurlyBrace::Check(false))
    {
        SyntaxBlock::CFG::Symbol::OpeningCurlyBrace::Cancel(false);
        if (!isCheckingInner)
        {
            return true;
        }
        if (!SyntaxBlock::CFG::String::Inner::Check(isSendingSignal))
        {
            Cancel(isSendingSignal);
            return false;
        }
        return true;
    }
    if (!SyntaxBlock::CFG::Symbol::QuotationMark::Check(isSendingSignal))
    {
        Cancel(isSendingSignal);
        return false;
    }
    if (!SyntaxBlock::CFG::Variable::Check(isSendingSignal))
    {
        Cancel(isSendingSignal);
        return false;
    }
    if (!SyntaxBlock::CFG::Symbol::QuotationMark::Check(isSendingSignal))
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
        onErrorOccurs(SyntaxBlock::MakeMessage(SyntaxBlock::GetCurrentToken(), MessagePool::StringInner["FirstOperandOfBinaryOperation"]));
    }
    SyntaxBlock::currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::String::Inner::Operand::Binary::First::Check(bool isSendingSignal, bool isCheckingInner)
{
    beginningIndex = SyntaxBlock::currentTokenIndexInVector;

    if (!SyntaxBlock::CFG::Symbol::QuotationMark::Check(isSendingSignal))
    {
        Cancel(isSendingSignal);
        return false;
    }
    if (!SyntaxBlock::CFG::SpecialIdentifier::FirstOperandOfBinaryOperation::Check(isSendingSignal))
    {
        Cancel(isSendingSignal);
        return false;
    }
    if (!SyntaxBlock::CFG::Symbol::QuotationMark::Check(isSendingSignal))
    {
        Cancel(isSendingSignal);
        return false;
    }
    if (!SyntaxBlock::CFG::Symbol::Colon::Check(isSendingSignal))
    {
        Cancel(isSendingSignal);
        return false;
    }
    if (SyntaxBlock::CFG::Symbol::OpeningCurlyBrace::Check(false))
    {
        SyntaxBlock::CFG::Symbol::OpeningCurlyBrace::Cancel(false);
        if (!isCheckingInner)
        {
            return true;
        }
        if (!SyntaxBlock::CFG::String::Inner::Check(isSendingSignal))
        {
            Cancel(isSendingSignal);
            return false;
        }
        return true;
    }
    if (!SyntaxBlock::CFG::Symbol::QuotationMark::Check(isSendingSignal))
    {
        Cancel(isSendingSignal);
        return false;
    }
    if (!SyntaxBlock::CFG::Variable::Check(isSendingSignal))
    {
        Cancel(isSendingSignal);
        return false;
    }
    if (!SyntaxBlock::CFG::Symbol::QuotationMark::Check(isSendingSignal))
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
        onErrorOccurs(SyntaxBlock::MakeMessage(SyntaxBlock::GetCurrentToken(), MessagePool::StringInner["SecondOperandOfBinaryOperation"]));
    }
    SyntaxBlock::currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::String::Inner::Operand::Binary::Second::Check(bool isSendingSignal, bool isCheckingInner)
{
    beginningIndex = SyntaxBlock::currentTokenIndexInVector;

    if (!SyntaxBlock::CFG::Symbol::QuotationMark::Check(isSendingSignal))
    {
        Cancel(isSendingSignal);
        return false;
    }
    if (!SyntaxBlock::CFG::SpecialIdentifier::SecondOperandOfBinaryOperation::Check(isSendingSignal))
    {
        Cancel(isSendingSignal);
        return false;
    }
    if (!SyntaxBlock::CFG::Symbol::QuotationMark::Check(isSendingSignal))
    {
        Cancel(isSendingSignal);
        return false;
    }
    if (!SyntaxBlock::CFG::Symbol::Colon::Check(isSendingSignal))
    {
        Cancel(isSendingSignal);
        return false;
    }
    if (SyntaxBlock::CFG::Symbol::OpeningCurlyBrace::Check(false))
    {
        SyntaxBlock::CFG::Symbol::OpeningCurlyBrace::Cancel(false);
        if (!isCheckingInner)
        {
            return true;
        }
        if (!SyntaxBlock::CFG::String::Inner::Check(isSendingSignal))
        {
            Cancel(isSendingSignal);
            return false;
        }
        return true;
    }
    if (!SyntaxBlock::CFG::Symbol::QuotationMark::Check(isSendingSignal))
    {
        Cancel(isSendingSignal);
        return false;
    }
    if (!SyntaxBlock::CFG::Variable::Check(isSendingSignal))
    {
        Cancel(isSendingSignal);
        return false;
    }
    if (!SyntaxBlock::CFG::Symbol::QuotationMark::Check(isSendingSignal))
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
        onErrorOccurs(SyntaxBlock::MakeMessage(SyntaxBlock::GetCurrentToken(), MessagePool::StringInner["OperandBinary"]));
    }
    SyntaxBlock::currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::String::Inner::Operand::Binary::Check(bool isSendingSignal, bool isCheckingInner)
{
    beginningIndex = SyntaxBlock::currentTokenIndexInVector;

    if (!SyntaxBlock::CFG::String::Inner::Operand::Binary::First::Check(isSendingSignal, isCheckingInner))
    {
        Cancel(isSendingSignal);
        return false;
    }
    if (!SyntaxBlock::CFG::Symbol::Comma::Check(isSendingSignal))
    {
        Cancel(isSendingSignal);
        return false;
    }
    if (!SyntaxBlock::CFG::String::Inner::Operand::Binary::Second::Check(isSendingSignal, isCheckingInner))
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
        onErrorOccurs(SyntaxBlock::MakeMessage(SyntaxBlock::GetCurrentToken(), MessagePool::StringInner["OperandVariable"]));
    }
    SyntaxBlock::currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::String::Inner::Operand::Variable::Check(bool isSendingSignal, bool isCheckingInner)
{
    beginningIndex = SyntaxBlock::currentTokenIndexInVector;

    if (SyntaxBlock::CFG::String::Inner::Operand::Unary::Check(false, isCheckingInner))
    {
        return true;
    }
    if (SyntaxBlock::CFG::String::Inner::Operand::Binary::First::Check(false, isCheckingInner))
    {
        return true;
    }
    if (SyntaxBlock::CFG::String::Inner::Operand::Binary::Second::Check(false, isCheckingInner))
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
        onErrorOccurs(SyntaxBlock::MakeMessage(SyntaxBlock::GetCurrentToken(), MessagePool::StringInner["Operand"]));
    }
    SyntaxBlock::currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::String::Inner::Operand::Check(bool isSendingSignal, bool isCheckingInner)
{
    beginningIndex = SyntaxBlock::currentTokenIndexInVector;

    if (SyntaxBlock::CFG::String::Inner::Operand::Unary::Check(false, isCheckingInner))
    {
        return true;
    }
    if (SyntaxBlock::CFG::String::Inner::Operand::Binary::Check(false, isCheckingInner))
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
        onErrorOccurs(SyntaxBlock::MakeMessage(SyntaxBlock::GetCurrentToken(), MessagePool::StringInner["Inner"]));
    }
    SyntaxBlock::currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::String::Inner::Check(bool isSendingSignal)
{
    beginningIndex = SyntaxBlock::currentTokenIndexInVector;

    if (!SyntaxBlock::CFG::Symbol::OpeningCurlyBrace::Check(isSendingSignal))
    {
        Cancel(isSendingSignal);
        return false;
    }
    if (!SyntaxBlock::CFG::String::Inner::Operation::Check(isSendingSignal))
    {
        Cancel(isSendingSignal);
        return false;
    }
    if (!SyntaxBlock::CFG::Symbol::Comma::Check(isSendingSignal))
    {
        Cancel(isSendingSignal);
        return false;
    }
    if (!SyntaxBlock::CFG::String::Inner::Operand::Check(isSendingSignal))
    {
        Cancel(isSendingSignal);
        return false;
    }
    if (!SyntaxBlock::CFG::Symbol::ClosingCurlyBrace::Check(isSendingSignal))
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
        onErrorOccurs(SyntaxBlock::MakeMessage(SyntaxBlock::GetCurrentToken(), MessagePool::String["Logical"]));
    }
    SyntaxBlock::currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::String::Logical::Check(bool isSendingSignal, bool isCheckingInner)
{
    beginningIndex = SyntaxBlock::currentTokenIndexInVector;

    if (SyntaxBlock::CFG::Symbol::OpeningCurlyBrace::Check(false))
    {
        SyntaxBlock::CFG::Symbol::OpeningCurlyBrace::Cancel(false);
        if (!isCheckingInner)
        {
            return true;
        }
        if (!SyntaxBlock::CFG::String::Inner::Check(isSendingSignal))
        {
            Cancel(isSendingSignal);
            return false;
        }
        return true;
    }

    // если нет логической части (то есть вид `[...]=;[...]`), проверяем, есть ли впереди знак `;` и возвращаемся обратно
    if (SyntaxBlock::CFG::Symbol::Semicolon::Check(false))
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
        onErrorOccurs(SyntaxBlock::MakeMessage(SyntaxBlock::GetCurrentToken(), MessagePool::String["Arithmetic"]));
    }
    SyntaxBlock::currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::String::Arithmetic::Check(bool isSendingSignal, bool isCheckingInner)
{
    beginningIndex = SyntaxBlock::currentTokenIndexInVector;

    if (SyntaxBlock::CFG::String::Arithmetic::NoRealSolution::Check(false))
    {
        return true;
    }
    
    if (SyntaxBlock::CFG::Symbol::OpeningCurlyBrace::Check(false))
    {
        SyntaxBlock::CFG::Symbol::OpeningCurlyBrace::Cancel(false);
        if (!isCheckingInner)
        {
            return true;
        }
        if (!SyntaxBlock::CFG::String::Inner::Check(isSendingSignal))
        {
            Cancel(isSendingSignal);
            return false;
        }
        return true;
    }
    if (SyntaxBlock::CFG::Variable::Integer::Check(false))
    {
        return true;
    }
    if (SyntaxBlock::CFG::Variable::Edge::Check(false))
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
        onErrorOccurs(SyntaxBlock::MakeMessage(SyntaxBlock::GetCurrentToken(), MessagePool::String["ArithmeticNoRealSolution"]));
    }
    SyntaxBlock::currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::String::Arithmetic::NoRealSolution::Check(bool isSendingSignal)
{
    beginningIndex = SyntaxBlock::currentTokenIndexInVector;

    if (!SyntaxBlock::CFG::Symbol::OpeningCurlyBrace::Check(isSendingSignal))
    {
        Cancel(isSendingSignal);
        return false;
    }
    if (!SyntaxBlock::CFG::Symbol::QuotationMark::Check(isSendingSignal))
    {
        Cancel(isSendingSignal);
        return false;
    }
    if (!SyntaxBlock::CFG::SpecialIdentifier::V::Check(isSendingSignal))
    {
        Cancel(isSendingSignal);
        return false;
    }
    if (!SyntaxBlock::CFG::Symbol::QuotationMark::Check(isSendingSignal))
    {
        Cancel(isSendingSignal);
        return false;
    }
    if (!SyntaxBlock::CFG::Symbol::Colon::Check(isSendingSignal))
    {
        Cancel(isSendingSignal);
        return false;
    }
    if (!SyntaxBlock::CFG::Symbol::QuotationMark::Check(isSendingSignal))
    {
        Cancel(isSendingSignal);
        return false;
    }
    if (!SyntaxBlock::CFG::SpecialIdentifier::No::Check(isSendingSignal))
    {
        Cancel(isSendingSignal);
        return false;
    }
    if (!SyntaxBlock::CFG::SpecialIdentifier::Real::Check(isSendingSignal))
    {
        Cancel(isSendingSignal);
        return false;
    }
    if (!SyntaxBlock::CFG::SpecialIdentifier::Solution::Check(isSendingSignal))
    {
        Cancel(isSendingSignal);
        return false;
    }
    if (!SyntaxBlock::CFG::Symbol::QuotationMark::Check(isSendingSignal))
    {
        Cancel(isSendingSignal);
        return false;
    }
    if (!SyntaxBlock::CFG::Symbol::ClosingCurlyBrace::Check(isSendingSignal))
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
        onErrorOccurs(SyntaxBlock::MakeMessage(SyntaxBlock::GetCurrentToken(), MessagePool::String["String"]));
    }
    SyntaxBlock::currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::String::Check(bool isSendingSignal)
{
    beginningIndex = SyntaxBlock::currentTokenIndexInVector;

    if (!SyntaxBlock::CFG::String::Beginning::Check(isSendingSignal))
    {
        Cancel(isSendingSignal);
        return false;
    }
    if (!SyntaxBlock::CFG::Symbol::EqualSign::Check(isSendingSignal))
    {
        Cancel(isSendingSignal);
        return false;
    }
    if (!SyntaxBlock::CFG::String::Logical::Check(isSendingSignal))
    {
        Cancel(isSendingSignal);
        return false;
    }
    if (!SyntaxBlock::CFG::Symbol::Semicolon::Check(isSendingSignal))
    {
        Cancel(isSendingSignal);
        return false;
    }
    if (!SyntaxBlock::CFG::String::Arithmetic::Check(isSendingSignal))
    {
        Cancel(isSendingSignal);
        return false;
    }
    if (SyntaxBlock::currentTokenIndexInVector != SyntaxBlock::tokenVector.size())
    {
        Cancel(isSendingSignal);
        return false;
    }

    return true;
}

void SyntaxBlock::CFG::String::CheckAllInnerParts(bool isSendingSignal, bool isCheckingInner)
{
    beginningIndex = SyntaxBlock::currentTokenIndexInVector;
    for (int currentIndex = beginningIndex; currentIndex < SyntaxBlock::tokenVector.size(); currentIndex++)
    {
        SyntaxBlock::currentTokenIndexInVector = currentIndex;
        if (SyntaxBlock::CFG::Symbol::EqualSign::Check(false))
        {
            if (SyntaxBlock::CFG::Symbol::OpeningCurlyBrace::Check(false))
            {
                SyntaxBlock::CFG::Symbol::OpeningCurlyBrace::Cancel(false);
                SyntaxBlock::CFG::String::Logical::Check(isSendingSignal, isCheckingInner);
            }
        }
        else if (SyntaxBlock::CFG::Symbol::Semicolon::Check(false))
        {
            SyntaxBlock::CFG::String::Arithmetic::Check(isSendingSignal, isCheckingInner);
        }
        // проверка граней (Edge)
        else if (SyntaxBlock::CFG::Variable::Identifier::Check(false))
        {
            if (SyntaxBlock::CFG::Symbol::OpeningParenthesis::Check(false))
            {
                SyntaxBlock::CFG::Symbol::OpeningParenthesis::Cancel(false);
                SyntaxBlock::CFG::Variable::Identifier::Cancel(false);
                
                if (SyntaxBlock::CFG::Variable::Edge::Check(isSendingSignal))
                {
                    currentIndex = SyntaxBlock::currentTokenIndexInVector-1;
                }
            }
        }
        // проверка операций (Operation)
        else if (SyntaxBlock::CFG::Symbol::OpeningCurlyBrace::Check(false))
        {
            if (SyntaxBlock::CFG::String::Inner::Operation::Check(isSendingSignal))
            {
                currentIndex = SyntaxBlock::currentTokenIndexInVector-1;
            }
        }
        // проверка операндов (Operand)
        else if (SyntaxBlock::CFG::Symbol::Comma::Check(false))
        {
            
            // проверяем на кавычки, т. к. запятые могут встречаться в гранях (Edge)
            if (SyntaxBlock::CFG::Symbol::QuotationMark::Check(false))
            {
                SyntaxBlock::CFG::Symbol::QuotationMark::Cancel(false);

                if (SyntaxBlock::CFG::String::Inner::Operand::Variable::Check(isSendingSignal, isCheckingInner))
                {
                    currentIndex = SyntaxBlock::currentTokenIndexInVector-1;
                }
            }
        }
        
    }
    SyntaxBlock::currentTokenIndexInVector = beginningIndex;
}