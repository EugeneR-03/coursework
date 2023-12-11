#include "SyntaxBlock.h"

using VariableToken = std::variant<SimpleToken, ComplexToken>;

std::stack<VariableToken> SyntaxBlock::tokenStack;
std::vector<VariableToken> SyntaxBlock::tokenVector;
int SyntaxBlock::currentTokenIndexInVector;

void SyntaxBlock::LoadTokenVector(std::vector<VariableToken> tokenVector)
{
    SyntaxBlock::tokenStack = std::stack<VariableToken>();
    SyntaxBlock::tokenVector = tokenVector;
    SyntaxBlock::currentTokenIndexInVector = 0;
}

void SyntaxBlock::LoadTokenIntoStack()
{
    SyntaxBlock::tokenStack.push(SyntaxBlock::tokenVector[SyntaxBlock::currentTokenIndexInVector++]);
}

VariableToken SyntaxBlock::GetTokenFromStack()
{
    VariableToken token = SyntaxBlock::tokenStack.top();
    return token;
}

void SyntaxBlock::RemoveTokenFromStack()
{
    if (SyntaxBlock::tokenStack.empty())
    {
        return;
    }
    SyntaxBlock::tokenStack.pop();
}

VariableToken SyntaxBlock::GetAndRemoveTokenFromStack()
{
    VariableToken token = SyntaxBlock::tokenStack.top();
    SyntaxBlock::tokenStack.pop();
    return token;
}

void SyntaxBlock::ClearStack()
{
    SyntaxBlock::tokenStack = std::stack<VariableToken>();
}

void SyntaxBlock::CancelLoadTokenIntoStack()
{
    SyntaxBlock::RemoveTokenFromStack();
    SyntaxBlock::currentTokenIndexInVector--;
}


// Symbol
bool SyntaxBlock::CFG::Symbol::OpeningCurlyBrace::Check()
{
    SyntaxBlock::LoadTokenIntoStack();
    VariableToken token = SyntaxBlock::GetTokenFromStack();
    if (std::holds_alternative<SimpleToken>(token))
    {
        SimpleToken tokenOpeningCurlyBrace = std::get<SimpleToken>(token);
        if (tokenOpeningCurlyBrace.type == SimpleTokenType::OpeningCurlyBrace)
        {
            SyntaxBlock::RemoveTokenFromStack();
            return true;
        }
    }
    SyntaxBlock::CancelLoadTokenIntoStack();
    return false;
}

bool SyntaxBlock::CFG::Symbol::ClosingCurlyBrace::Check()
{
    SyntaxBlock::LoadTokenIntoStack();
    VariableToken token = SyntaxBlock::GetTokenFromStack();
    if (std::holds_alternative<SimpleToken>(token))
    {
        SimpleToken tokenClosingCurlyBrace = std::get<SimpleToken>(token);
        if (tokenClosingCurlyBrace.type == SimpleTokenType::ClosingCurlyBrace)
        {
            SyntaxBlock::RemoveTokenFromStack();
            return true;
        }
    }
    SyntaxBlock::CancelLoadTokenIntoStack();
    return false;
}

bool SyntaxBlock::CFG::Symbol::OpeningParenthesis::Check()
{
    SyntaxBlock::LoadTokenIntoStack();
    VariableToken token = SyntaxBlock::GetTokenFromStack();
    if (std::holds_alternative<SimpleToken>(token))
    {
        SimpleToken tokenOpeningParenthesis = std::get<SimpleToken>(token);
        if (tokenOpeningParenthesis.type == SimpleTokenType::OpeningParenthesis)
        {
            SyntaxBlock::RemoveTokenFromStack();
            return true;
        }
    }
    SyntaxBlock::CancelLoadTokenIntoStack();
    return false;
}

bool SyntaxBlock::CFG::Symbol::ClosingParenthesis::Check()
{
    SyntaxBlock::LoadTokenIntoStack();
    VariableToken token = SyntaxBlock::GetTokenFromStack();
    if (std::holds_alternative<SimpleToken>(token))
    {
        SimpleToken tokenClosingParenthesis = std::get<SimpleToken>(token);
        if (tokenClosingParenthesis.type == SimpleTokenType::ClosingParenthesis)
        {
            SyntaxBlock::RemoveTokenFromStack();
            return true;
        }
    }
    SyntaxBlock::CancelLoadTokenIntoStack();
    return false;
}

bool SyntaxBlock::CFG::Symbol::Comma::Check()
{
    SyntaxBlock::LoadTokenIntoStack();
    VariableToken token = SyntaxBlock::GetTokenFromStack();
    if (std::holds_alternative<SimpleToken>(token))
    {
        SimpleToken tokenComma = std::get<SimpleToken>(token);
        if (tokenComma.type == SimpleTokenType::Comma)
        {
            SyntaxBlock::RemoveTokenFromStack();
            return true;
        }
    }
    SyntaxBlock::CancelLoadTokenIntoStack();
    return false;
}

bool SyntaxBlock::CFG::Symbol::Colon::Check()
{
    SyntaxBlock::LoadTokenIntoStack();
    VariableToken token = SyntaxBlock::GetTokenFromStack();
    if (std::holds_alternative<SimpleToken>(token))
    {
        SimpleToken tokenColon = std::get<SimpleToken>(token);
        if (tokenColon.type == SimpleTokenType::Colon)
        {
            SyntaxBlock::RemoveTokenFromStack();
            return true;
        }
    }
    SyntaxBlock::CancelLoadTokenIntoStack();
    return false;
}

bool SyntaxBlock::CFG::Symbol::Semicolon::Check()
{
    SyntaxBlock::LoadTokenIntoStack();
    VariableToken token = SyntaxBlock::GetTokenFromStack();
    if (std::holds_alternative<SimpleToken>(token))
    {
        SimpleToken tokenSemicolon = std::get<SimpleToken>(token);
        if (tokenSemicolon.type == SimpleTokenType::Semicolon)
        {
            SyntaxBlock::RemoveTokenFromStack();
            return true;
        }
    }
    SyntaxBlock::CancelLoadTokenIntoStack();
    return false;
}

bool SyntaxBlock::CFG::Symbol::QuotationMark::Check()
{
    SyntaxBlock::LoadTokenIntoStack();
    VariableToken token = SyntaxBlock::GetTokenFromStack();
    if (std::holds_alternative<SimpleToken>(token))
    {
        SimpleToken tokenQuotationMark = std::get<SimpleToken>(token);
        if (tokenQuotationMark.type == SimpleTokenType::QuotationMark)
        {
            SyntaxBlock::RemoveTokenFromStack();
            return true;
        }
    }
    SyntaxBlock::CancelLoadTokenIntoStack();
    return false;
}

bool SyntaxBlock::CFG::Symbol::EqualSign::Check()
{
    SyntaxBlock::LoadTokenIntoStack();
    VariableToken token = SyntaxBlock::GetTokenFromStack();
    if (std::holds_alternative<SimpleToken>(token))
    {
        SimpleToken tokenEqualSign = std::get<SimpleToken>(token);
        if (tokenEqualSign.type == SimpleTokenType::EqualSign)
        {
            SyntaxBlock::RemoveTokenFromStack();
            return true;
        }
    }
    SyntaxBlock::CancelLoadTokenIntoStack();
    return false;
}

bool SyntaxBlock::CFG::Symbol::ComparisonSign::Check()
{
    SyntaxBlock::LoadTokenIntoStack();
    VariableToken token = SyntaxBlock::GetTokenFromStack();
    if (std::holds_alternative<SimpleToken>(token))
    {
        SimpleToken tokenComparisonSign = std::get<SimpleToken>(token);
        if (tokenComparisonSign.type == SimpleTokenType::ComparisonSign)
        {
            SyntaxBlock::RemoveTokenFromStack();
            return true;
        }
    }
    SyntaxBlock::CancelLoadTokenIntoStack();
    return false;
}

bool SyntaxBlock::CFG::Symbol::ExclamationMark::Check()
{
    SyntaxBlock::LoadTokenIntoStack();
    VariableToken token = SyntaxBlock::GetTokenFromStack();
    if (std::holds_alternative<SimpleToken>(token))
    {
        SimpleToken tokenExclamationMark = std::get<SimpleToken>(token);
        if (tokenExclamationMark.type == SimpleTokenType::ExclamationMark)
        {
            SyntaxBlock::RemoveTokenFromStack();
            return true;
        }
    }
    SyntaxBlock::CancelLoadTokenIntoStack();
    return false;
}

bool SyntaxBlock::CFG::Symbol::ArithmeticSign::Check()
{
    SyntaxBlock::LoadTokenIntoStack();
    VariableToken token = SyntaxBlock::GetTokenFromStack();
    if (std::holds_alternative<SimpleToken>(token))
    {
        SimpleToken tokenArithmeticSign = std::get<SimpleToken>(token);
        if (tokenArithmeticSign.type == SimpleTokenType::ArithmeticSign)
        {
            SyntaxBlock::RemoveTokenFromStack();
            return true;
        }
    }
    SyntaxBlock::CancelLoadTokenIntoStack();
    return false;
}

bool SyntaxBlock::CFG::Symbol::LogicalSign::Check()
{
    SyntaxBlock::LoadTokenIntoStack();
    VariableToken token = SyntaxBlock::GetTokenFromStack();
    if (std::holds_alternative<SimpleToken>(token))
    {
        SimpleToken tokenLogicalSign = std::get<SimpleToken>(token);
        if (tokenLogicalSign.type == SimpleTokenType::LogicalSign)
        {
            SyntaxBlock::RemoveTokenFromStack();
            return true;
        }
    }
    SyntaxBlock::CancelLoadTokenIntoStack();
    return false;
}

bool SyntaxBlock::CFG::SpecialIdentifier::Operation::Check()
{
    SyntaxBlock::LoadTokenIntoStack();
    VariableToken token = SyntaxBlock::GetTokenFromStack();
    if (std::holds_alternative<ComplexToken>(token))
    {
        ComplexToken tokenOperationSpecialIdentifier = std::get<ComplexToken>(token);
        if (std::holds_alternative<SpecialIdentifierType>(tokenOperationSpecialIdentifier.type))
        {
            SpecialIdentifierType tokenOperationSpecialIdentifierType = std::get<SpecialIdentifierType>(tokenOperationSpecialIdentifier.type);
            if (tokenOperationSpecialIdentifierType == SpecialIdentifierType::Operation)
            {
                SyntaxBlock::RemoveTokenFromStack();
                return true;
            }
        }
    }
    SyntaxBlock::CancelLoadTokenIntoStack();
    return false;
}

bool SyntaxBlock::CFG::SpecialIdentifier::OperandOfUnaryOperation::Check()
{
    SyntaxBlock::LoadTokenIntoStack();
    VariableToken token = SyntaxBlock::GetTokenFromStack();
    if (std::holds_alternative<ComplexToken>(token))
    {
        ComplexToken tokenOperandOfUnaryOperationSpecialIdentifier = std::get<ComplexToken>(token);
        if (std::holds_alternative<SpecialIdentifierType>(tokenOperandOfUnaryOperationSpecialIdentifier.type))
        {
            SpecialIdentifierType tokenOperandOfUnaryOperationSpecialIdentifierType = std::get<SpecialIdentifierType>(tokenOperandOfUnaryOperationSpecialIdentifier.type);
            if (tokenOperandOfUnaryOperationSpecialIdentifierType == SpecialIdentifierType::OperandOfUnaryOperation)
            {
                SyntaxBlock::RemoveTokenFromStack();
                return true;
            }
        }
    }
    SyntaxBlock::CancelLoadTokenIntoStack();
    return false;
}

bool SyntaxBlock::CFG::SpecialIdentifier::FirstOperandOfBinaryOperation::Check()
{
    SyntaxBlock::LoadTokenIntoStack();
    VariableToken token = SyntaxBlock::GetTokenFromStack();
    if (std::holds_alternative<ComplexToken>(token))
    {
        ComplexToken tokenFirstOperandOfBinaryOperationSpecialIdentifier = std::get<ComplexToken>(token);
        if (std::holds_alternative<SpecialIdentifierType>(tokenFirstOperandOfBinaryOperationSpecialIdentifier.type))
        {
            SpecialIdentifierType tokenFirstOperandOfBinaryOperationSpecialIdentifierType = std::get<SpecialIdentifierType>(tokenFirstOperandOfBinaryOperationSpecialIdentifier.type);
            if (tokenFirstOperandOfBinaryOperationSpecialIdentifierType == SpecialIdentifierType::FirstOperandOfBinaryOperation)
            {
                SyntaxBlock::RemoveTokenFromStack();
                return true;
            }
        }
    }
    SyntaxBlock::CancelLoadTokenIntoStack();
    return false;
}

bool SyntaxBlock::CFG::SpecialIdentifier::SecondOperandOfBinaryOperation::Check()
{
    SyntaxBlock::LoadTokenIntoStack();
    VariableToken token = SyntaxBlock::GetTokenFromStack();
    if (std::holds_alternative<ComplexToken>(token))
    {
        ComplexToken tokenSecondOperandOfBinaryOperationSpecialIdentifier = std::get<ComplexToken>(token);
        if (std::holds_alternative<SpecialIdentifierType>(tokenSecondOperandOfBinaryOperationSpecialIdentifier.type))
        {
            SpecialIdentifierType tokenSecondOperandOfBinaryOperationSpecialIdentifierType = std::get<SpecialIdentifierType>(tokenSecondOperandOfBinaryOperationSpecialIdentifier.type);
            if (tokenSecondOperandOfBinaryOperationSpecialIdentifierType == SpecialIdentifierType::SecondOperandOfBinaryOperation)
            {
                SyntaxBlock::RemoveTokenFromStack();
                return true;
            }
        }
    }
    SyntaxBlock::CancelLoadTokenIntoStack();
    return false;
}

bool SyntaxBlock::CFG::SpecialIdentifier::Modulus::Check()
{
    SyntaxBlock::LoadTokenIntoStack();
    VariableToken token = SyntaxBlock::GetTokenFromStack();
    if (std::holds_alternative<ComplexToken>(token))
    {
        ComplexToken tokenModulusSpecialIdentifier = std::get<ComplexToken>(token);
        if (std::holds_alternative<SpecialIdentifierType>(tokenModulusSpecialIdentifier.type))
        {
            SpecialIdentifierType tokenModulusSpecialIdentifierType = std::get<SpecialIdentifierType>(tokenModulusSpecialIdentifier.type);
            if (tokenModulusSpecialIdentifierType == SpecialIdentifierType::Modulus)
            {
                SyntaxBlock::RemoveTokenFromStack();
                return true;
            }
        }
    }
    SyntaxBlock::CancelLoadTokenIntoStack();
    return false;
}

bool SyntaxBlock::CFG::SpecialIdentifier::SquareOfNumber::Check()
{
    SyntaxBlock::LoadTokenIntoStack();
    VariableToken token = SyntaxBlock::GetTokenFromStack();
    if (std::holds_alternative<ComplexToken>(token))
    {
        ComplexToken tokenSquareOfNumberSpecialIdentifier = std::get<ComplexToken>(token);
        if (std::holds_alternative<SpecialIdentifierType>(tokenSquareOfNumberSpecialIdentifier.type))
        {
            SpecialIdentifierType tokenSquareOfNumberSpecialIdentifierType = std::get<SpecialIdentifierType>(tokenSquareOfNumberSpecialIdentifier.type);
            if (tokenSquareOfNumberSpecialIdentifierType == SpecialIdentifierType::SquareOfNumber)
            {
                SyntaxBlock::RemoveTokenFromStack();
                return true;
            }
        }
    }
    SyntaxBlock::CancelLoadTokenIntoStack();
    return false;
}

bool SyntaxBlock::CFG::SpecialIdentifier::SquareRootOfNumber::Check()
{
    SyntaxBlock::LoadTokenIntoStack();
    VariableToken token = SyntaxBlock::GetTokenFromStack();
    if (std::holds_alternative<ComplexToken>(token))
    {
        ComplexToken tokenSquareRootOfNumberSpecialIdentifier = std::get<ComplexToken>(token);
        if (std::holds_alternative<SpecialIdentifierType>(tokenSquareRootOfNumberSpecialIdentifier.type))
        {
            SpecialIdentifierType tokenSquareRootOfNumberSpecialIdentifierType = std::get<SpecialIdentifierType>(tokenSquareRootOfNumberSpecialIdentifier.type);
            if (tokenSquareRootOfNumberSpecialIdentifierType == SpecialIdentifierType::SquareRootOfNumber)
            {
                SyntaxBlock::RemoveTokenFromStack();
                return true;
            }
        }
    }
    SyntaxBlock::CancelLoadTokenIntoStack();
    return false;
}


bool SyntaxBlock::CFG::Variable::Identifier::Check()
{
    SyntaxBlock::LoadTokenIntoStack();
    VariableToken token = SyntaxBlock::GetTokenFromStack();
    if (std::holds_alternative<ComplexToken>(token))
    {
        ComplexToken tokenIdentifier = std::get<ComplexToken>(token);
        if (std::holds_alternative<ComplexTokenType>(tokenIdentifier.type))
        {
            ComplexTokenType tokenIdentifierType = std::get<ComplexTokenType>(tokenIdentifier.type);
            if (tokenIdentifierType != ComplexTokenType::Identifier)
            {
                SyntaxBlock::CancelLoadTokenIntoStack();
                return false;
            }
        }
        SyntaxBlock::RemoveTokenFromStack();
        return true;
    }
    SyntaxBlock::CancelLoadTokenIntoStack();
    return false;
}

bool SyntaxBlock::CFG::Variable::Integer::Check()
{
    SyntaxBlock::LoadTokenIntoStack();
    VariableToken token = SyntaxBlock::GetTokenFromStack();
    if (std::holds_alternative<ComplexToken>(token))
    {
        ComplexToken tokenInteger = std::get<ComplexToken>(token);
        if (std::holds_alternative<ComplexTokenType>(tokenInteger.type))
        {
            ComplexTokenType tokenIntegerType = std::get<ComplexTokenType>(tokenInteger.type);
            if (tokenIntegerType != ComplexTokenType::Integer)
            {
                SyntaxBlock::CancelLoadTokenIntoStack();
                return false;
            }
            SyntaxBlock::RemoveTokenFromStack();
            return true;
        }
    }
    SyntaxBlock::CancelLoadTokenIntoStack();
    return false;
}

bool SyntaxBlock::CFG::Variable::Edge::Check()
{
    if (!SyntaxBlock::CFG::Variable::Identifier::Check())
    {
        return false;
    }

    if (!SyntaxBlock::CFG::Symbol::OpeningParenthesis::Check())
    {
        return false;
    }

    if (!SyntaxBlock::CFG::Variable::Integer::Check())
    {
        return false;
    }

    if (!SyntaxBlock::CFG::Symbol::Comma::Check())
    {
        if (!SyntaxBlock::CFG::Symbol::ClosingParenthesis::Check())
        {
            return false;
        }

        return true;
    }
    else
    {
        if (!SyntaxBlock::CFG::Variable::Integer::Check())
        {
            return false;
        }

        if (!SyntaxBlock::CFG::Symbol::ClosingParenthesis::Check())
        {
            return false;
        }

        return true;
    }
}

bool SyntaxBlock::CFG::Variable::Check()
{
    if (SyntaxBlock::CFG::Variable::Edge::Check())
    {
        return true;
    }
    else if (SyntaxBlock::CFG::Variable::Identifier::Check())
    {
        return true;
    }
    else if (SyntaxBlock::CFG::Variable::Integer::Check())
    {
        return true;
    }
    
    return false;
}


bool SyntaxBlock::CFG::Operation::Logical::Check()
{
    if (SyntaxBlock::CFG::Symbol::ExclamationMark::Check())
    {
        if (SyntaxBlock::CFG::Symbol::EqualSign::Check())
        {
            return true;
        }
        return false;
    }
    else if (SyntaxBlock::CFG::Symbol::EqualSign::Check())
    {
        if (SyntaxBlock::CFG::Symbol::EqualSign::Check())
        {
            return true;
        }
        return false;
    }
    else if (SyntaxBlock::CFG::Symbol::ComparisonSign::Check())
    {
        if (SyntaxBlock::CFG::Symbol::EqualSign::Check())
        {
            return true;
        }
        return true;
    }
    return false;
}

bool SyntaxBlock::CFG::Operation::Arithmetic::Check()
{
    if (SyntaxBlock::CFG::Symbol::ArithmeticSign::Check())
    {
        return true;
    }
    return false;
}

bool SyntaxBlock::CFG::Operation::Check()
{
    if (SyntaxBlock::CFG::Operation::Logical::Check())
    {
        return true;
    }
    else if (SyntaxBlock::CFG::Operation::Arithmetic::Check())
    {
        return true;
    }
    return false;
}

bool SyntaxBlock::CFG::String::Beginning::Check()
{
    if (SyntaxBlock::CFG::Variable::Edge::Check())
    {
        return true;
    }
    else if (SyntaxBlock::CFG::Variable::Identifier::Check())
    {
        return true;
    }
    
    return false;
}

bool SyntaxBlock::CFG::String::Inner::Operation::Check()
{
    if (!SyntaxBlock::CFG::Symbol::QuotationMark::Check())
    {
        return false;
    }
    if (!SyntaxBlock::CFG::SpecialIdentifier::Operation::Check())
    {
        return false;
    }
    if (!SyntaxBlock::CFG::Symbol::QuotationMark::Check())
    {
        return false;
    }
    if (!SyntaxBlock::CFG::Symbol::Colon::Check())
    {
        return false;
    }
    if (!SyntaxBlock::CFG::Symbol::QuotationMark::Check())
    {
        return false;
    }
    if (!SyntaxBlock::CFG::Operation::Check())
    {
        return false;
    }
    if (!SyntaxBlock::CFG::Symbol::QuotationMark::Check())
    {
        return false;
    }
    return true;
}

bool SyntaxBlock::CFG::String::Inner::Operand::Unary::Check()
{
    if (!SyntaxBlock::CFG::Symbol::QuotationMark::Check())
    {
        return false;
    }
    if (!SyntaxBlock::CFG::SpecialIdentifier::OperandOfUnaryOperation::Check())
    {
        return false;
    }
    if (!SyntaxBlock::CFG::Symbol::QuotationMark::Check())
    {
        return false;
    }
    if (!SyntaxBlock::CFG::Symbol::Colon::Check())
    {
        return false;
    }
    if (SyntaxBlock::CFG::Symbol::QuotationMark::Check())
    {
        if (!SyntaxBlock::CFG::Variable::Check())
        {
            return false;
        }
        if (!SyntaxBlock::CFG::Symbol::QuotationMark::Check())
        {
            return false;
        }
    }
    else
    {
        if (!SyntaxBlock::CFG::String::Inner::Check())
        {
            return false;
        }
    }
    return true;
}

bool SyntaxBlock::CFG::String::Inner::Operand::Binary::First::Check()
{
    if (!SyntaxBlock::CFG::Symbol::QuotationMark::Check())
    {
        return false;
    }
    if (!SyntaxBlock::CFG::SpecialIdentifier::FirstOperandOfBinaryOperation::Check())
    {
        return false;
    }
    if (!SyntaxBlock::CFG::Symbol::QuotationMark::Check())
    {
        return false;
    }
    if (!SyntaxBlock::CFG::Symbol::Colon::Check())
    {
        return false;
    }
    if (SyntaxBlock::CFG::Symbol::QuotationMark::Check())
    {
        if (!SyntaxBlock::CFG::Variable::Check())
        {
            return false;
        }
        if (!SyntaxBlock::CFG::Symbol::QuotationMark::Check())
        {
            return false;
        }
    }
    else
    {
        if (!SyntaxBlock::CFG::String::Inner::Check())
        {
            return false;
        }
    }
    return true;
}

bool SyntaxBlock::CFG::String::Inner::Operand::Binary::Second::Check()
{
    if (!SyntaxBlock::CFG::Symbol::QuotationMark::Check())
    {
        return false;
    }
    if (!SyntaxBlock::CFG::SpecialIdentifier::SecondOperandOfBinaryOperation::Check())
    {
        return false;
    }
    if (!SyntaxBlock::CFG::Symbol::QuotationMark::Check())
    {
        return false;
    }
    if (!SyntaxBlock::CFG::Symbol::Colon::Check())
    {
        return false;
    }
    if (SyntaxBlock::CFG::Symbol::QuotationMark::Check())
    {
        if (!SyntaxBlock::CFG::Variable::Check())
        {
            return false;
        }
        if (!SyntaxBlock::CFG::Symbol::QuotationMark::Check())
        {
            return false;
        }
    }
    else
    {
        if (!SyntaxBlock::CFG::String::Inner::Check())
        {
            return false;
        }
    }
    return true;
}

bool SyntaxBlock::CFG::String::Inner::Operand::Binary::Check()
{
    if (!SyntaxBlock::CFG::String::Inner::Operand::Binary::First::Check())
    {
        return false;
    }
    if (!SyntaxBlock::CFG::Symbol::Comma::Check())
    {
        return false;
    }
    if (!SyntaxBlock::CFG::String::Inner::Operand::Binary::Second::Check())
    {
        return false;
    }
    return true;
}

bool SyntaxBlock::CFG::String::Inner::Operand::Check()
{
    if (SyntaxBlock::CFG::String::Inner::Operand::Unary::Check())
    {
        return true;
    }
    else if (SyntaxBlock::CFG::String::Inner::Operand::Binary::Check())
    {
        return true;
    }
    return false;
}

bool SyntaxBlock::CFG::String::Inner::Check()
{
    if (!SyntaxBlock::CFG::Symbol::OpeningCurlyBrace::Check())
    {
        return false;
    }
    if (!SyntaxBlock::CFG::String::Inner::Operation::Check())
    {
        return false;
    }
    if (!SyntaxBlock::CFG::Symbol::Comma::Check())
    {
        return false;
    }
    if (!SyntaxBlock::CFG::String::Inner::Operand::Check())
    {
        return false;
    }
    if (!SyntaxBlock::CFG::Symbol::ClosingCurlyBrace::Check())
    {
        return false;
    }
    return true;
}

bool SyntaxBlock::CFG::String::Logical::Check()
{
    if (SyntaxBlock::CFG::String::Inner::Check())
    {
        return true;
    }
    
    SyntaxBlock::LoadTokenIntoStack();
    VariableToken token = SyntaxBlock::GetTokenFromStack();
    if (std::holds_alternative<SimpleToken>(token))
    {
        SimpleToken tokenSemicolon = std::get<SimpleToken>(token);
        if (tokenSemicolon.type == SimpleTokenType::Semicolon)
        {
            SyntaxBlock::CancelLoadTokenIntoStack();
            return true;
        }
    }
    SyntaxBlock::CancelLoadTokenIntoStack();
    return false;

    // return false;
}

bool SyntaxBlock::CFG::String::Arithmetic::Check()
{
    if (SyntaxBlock::CFG::String::Inner::Check())
    {
        return true;
    }
    // 
    return false;
}

bool SyntaxBlock::CFG::String::Check()
{
    if (!SyntaxBlock::CFG::String::Beginning::Check())
    {
        return false;
    }
    if (!SyntaxBlock::CFG::Symbol::EqualSign::Check())
    {
        return false;
    }
    if (!SyntaxBlock::CFG::String::Logical::Check())
    {
        return false;
    }
    if (!SyntaxBlock::CFG::Symbol::Semicolon::Check())
    {
        return false;
    }
    if (!SyntaxBlock::CFG::String::Arithmetic::Check())
    {
        return false;
    }
    return true;
}