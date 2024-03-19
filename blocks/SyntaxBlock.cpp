#include "SyntaxBlock.hpp"

using VariableToken = std::variant<SimpleToken, ComplexToken>;

std::stack<VariableToken> SyntaxBlock::tokenStack;
std::vector<VariableToken> SyntaxBlock::tokenVector;
int SyntaxBlock::currentTokenIndexInVector = 0;

int SyntaxBlock::CFG::Symbol::OpeningCurlyBrace::beginningIndex = -1;
int SyntaxBlock::CFG::Symbol::ClosingCurlyBrace::beginningIndex = -1;
int SyntaxBlock::CFG::Symbol::OpeningParenthesis::beginningIndex = -1;
int SyntaxBlock::CFG::Symbol::ClosingParenthesis::beginningIndex = -1;
int SyntaxBlock::CFG::Symbol::Comma::beginningIndex = -1;
int SyntaxBlock::CFG::Symbol::Colon::beginningIndex = -1;
int SyntaxBlock::CFG::Symbol::Semicolon::beginningIndex = -1;
int SyntaxBlock::CFG::Symbol::QuotationMark::beginningIndex = -1;
int SyntaxBlock::CFG::Symbol::EqualSign::beginningIndex = -1;
int SyntaxBlock::CFG::Symbol::ComparisonSign::beginningIndex = -1;
int SyntaxBlock::CFG::Symbol::ExclamationMark::beginningIndex = -1;
int SyntaxBlock::CFG::Symbol::ArithmeticSign::beginningIndex = -1;
int SyntaxBlock::CFG::Symbol::LogicalSign::beginningIndex = -1;

int SyntaxBlock::CFG::SpecialIdentifier::Operation::beginningIndex = -1;
int SyntaxBlock::CFG::SpecialIdentifier::OperandOfUnaryOperation::beginningIndex = -1;
int SyntaxBlock::CFG::SpecialIdentifier::FirstOperandOfBinaryOperation::beginningIndex = -1;
int SyntaxBlock::CFG::SpecialIdentifier::SecondOperandOfBinaryOperation::beginningIndex = -1;
int SyntaxBlock::CFG::SpecialIdentifier::V::beginningIndex = -1;
int SyntaxBlock::CFG::SpecialIdentifier::No::beginningIndex = -1;
int SyntaxBlock::CFG::SpecialIdentifier::Real::beginningIndex = -1;
int SyntaxBlock::CFG::SpecialIdentifier::Solution::beginningIndex = -1;
int SyntaxBlock::CFG::SpecialIdentifier::Modulus::beginningIndex = -1;
int SyntaxBlock::CFG::SpecialIdentifier::SquareOfNumber::beginningIndex = -1;
int SyntaxBlock::CFG::SpecialIdentifier::SquareRootOfNumber::beginningIndex = -1;

int SyntaxBlock::CFG::Variable::beginningIndex = -1;
int SyntaxBlock::CFG::Variable::Edge::beginningIndex = -1;
int SyntaxBlock::CFG::Variable::Identifier::beginningIndex = -1;
int SyntaxBlock::CFG::Variable::Integer::beginningIndex = -1;

int SyntaxBlock::CFG::Operation::beginningIndex = -1;
int SyntaxBlock::CFG::Operation::Logical::beginningIndex = -1;
int SyntaxBlock::CFG::Operation::Arithmetic::beginningIndex = -1;

int SyntaxBlock::CFG::String::beginningIndex = -1;
int SyntaxBlock::CFG::String::Beginning::beginningIndex = -1;
int SyntaxBlock::CFG::String::Logical::beginningIndex = -1;
int SyntaxBlock::CFG::String::Arithmetic::beginningIndex = -1;
int SyntaxBlock::CFG::String::Arithmetic::NoRealSolution::beginningIndex = -1;
int SyntaxBlock::CFG::String::Inner::beginningIndex = -1;
int SyntaxBlock::CFG::String::Inner::Operation::beginningIndex = -1;
int SyntaxBlock::CFG::String::Inner::Operand::beginningIndex = -1;
int SyntaxBlock::CFG::String::Inner::Operand::Unary::beginningIndex = -1;
int SyntaxBlock::CFG::String::Inner::Operand::Binary::beginningIndex = -1;
int SyntaxBlock::CFG::String::Inner::Operand::Binary::First::beginningIndex = -1;
int SyntaxBlock::CFG::String::Inner::Operand::Binary::Second::beginningIndex = -1;

void SyntaxBlock::LoadTokenVector(std::vector<VariableToken> tokenVector)
{
    SyntaxBlock::tokenStack = std::stack<VariableToken>();
    SyntaxBlock::tokenVector = tokenVector;
    SyntaxBlock::currentTokenIndexInVector = 0;
}

void SyntaxBlock::LoadToken()
{
    // SyntaxBlock::tokenStack.push(SyntaxBlock::tokenVector[SyntaxBlock::currentTokenIndexInVector++]);
    SyntaxBlock::currentTokenIndexInVector++;
}

VariableToken SyntaxBlock::GetCurrentToken()
{
    // VariableToken token = SyntaxBlock::tokenStack.top();
    // return token;
    return SyntaxBlock::tokenVector[SyntaxBlock::currentTokenIndexInVector];
}

// void SyntaxBlock::RemoveTokenFromStack()
// {
//     if (SyntaxBlock::tokenStack.empty())
//     {
//         return;
//     }
//     SyntaxBlock::tokenStack.pop();
// }

// VariableToken SyntaxBlock::GetAndRemoveTokenFromStack()
// {
//     VariableToken token = SyntaxBlock::tokenStack.top();
//     SyntaxBlock::tokenStack.pop();
//     return token;
// }

// void SyntaxBlock::ClearStack()
// {
//     SyntaxBlock::tokenStack = std::stack<VariableToken>();
// }

void SyntaxBlock::CancelLoadToken()
{
    // SyntaxBlock::RemoveTokenFromStack();
    SyntaxBlock::currentTokenIndexInVector--;
}


// Symbol
void SyntaxBlock::CFG::Symbol::OpeningCurlyBrace::Cancel()
{
    SyntaxBlock::currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::Symbol::OpeningCurlyBrace::Check()
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
    Cancel();
    return false;
}

void SyntaxBlock::CFG::Symbol::ClosingCurlyBrace::Cancel()
{
    SyntaxBlock::currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::Symbol::ClosingCurlyBrace::Check()
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
    Cancel();
    return false;
}

void SyntaxBlock::CFG::Symbol::OpeningParenthesis::Cancel()
{
    SyntaxBlock::currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::Symbol::OpeningParenthesis::Check()
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
    Cancel();
    return false;
}

void SyntaxBlock::CFG::Symbol::ClosingParenthesis::Cancel()
{
    SyntaxBlock::currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::Symbol::ClosingParenthesis::Check()
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
    Cancel();
    return false;
}

void SyntaxBlock::CFG::Symbol::Comma::Cancel()
{
    SyntaxBlock::currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::Symbol::Comma::Check()
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
    Cancel();
    return false;
}

void SyntaxBlock::CFG::Symbol::Colon::Cancel()
{
    SyntaxBlock::currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::Symbol::Colon::Check()
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
    Cancel();
    return false;
}

void SyntaxBlock::CFG::Symbol::Semicolon::Cancel()
{
    SyntaxBlock::currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::Symbol::Semicolon::Check()
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
    Cancel();
    return false;
}

void SyntaxBlock::CFG::Symbol::QuotationMark::Cancel()
{
    SyntaxBlock::currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::Symbol::QuotationMark::Check()
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
    Cancel();
    return false;
}

void SyntaxBlock::CFG::Symbol::EqualSign::Cancel()
{
    SyntaxBlock::currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::Symbol::EqualSign::Check()
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
    Cancel();
    return false;
}

void SyntaxBlock::CFG::Symbol::ComparisonSign::Cancel()
{
    SyntaxBlock::currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::Symbol::ComparisonSign::Check()
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
    Cancel();
    return false;
}

void SyntaxBlock::CFG::Symbol::ExclamationMark::Cancel()
{
    SyntaxBlock::currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::Symbol::ExclamationMark::Check()
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
    Cancel();
    return false;
}

void SyntaxBlock::CFG::Symbol::ArithmeticSign::Cancel()
{
    SyntaxBlock::currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::Symbol::ArithmeticSign::Check()
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
    Cancel();
    return false;
}

void SyntaxBlock::CFG::Symbol::LogicalSign::Cancel()
{
    SyntaxBlock::currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::Symbol::LogicalSign::Check()
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
    Cancel();
    return false;
}

void SyntaxBlock::CFG::SpecialIdentifier::Operation::Cancel()
{
    SyntaxBlock::currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::SpecialIdentifier::Operation::Check()
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
    Cancel();
    return false;
}

void SyntaxBlock::CFG::SpecialIdentifier::OperandOfUnaryOperation::Cancel()
{
    SyntaxBlock::currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::SpecialIdentifier::OperandOfUnaryOperation::Check()
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
    Cancel();
    return false;
}

void SyntaxBlock::CFG::SpecialIdentifier::FirstOperandOfBinaryOperation::Cancel()
{
    SyntaxBlock::currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::SpecialIdentifier::FirstOperandOfBinaryOperation::Check()
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
    Cancel();
    return false;
}

void SyntaxBlock::CFG::SpecialIdentifier::SecondOperandOfBinaryOperation::Cancel()
{
    SyntaxBlock::currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::SpecialIdentifier::SecondOperandOfBinaryOperation::Check()
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
    Cancel();
    return false;
}

void SyntaxBlock::CFG::SpecialIdentifier::V::Cancel()
{
    SyntaxBlock::currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::SpecialIdentifier::V::Check()
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
    Cancel();
    return false;
}

void SyntaxBlock::CFG::SpecialIdentifier::No::Cancel()
{
    SyntaxBlock::currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::SpecialIdentifier::No::Check()
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
    Cancel();
    return false;
}

void SyntaxBlock::CFG::SpecialIdentifier::Real::Cancel()
{
    SyntaxBlock::currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::SpecialIdentifier::Real::Check()
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
    Cancel();
    return false;
}

void SyntaxBlock::CFG::SpecialIdentifier::Solution::Cancel()
{
    SyntaxBlock::currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::SpecialIdentifier::Solution::Check()
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
    Cancel();
    return false;
}

void SyntaxBlock::CFG::SpecialIdentifier::Modulus::Cancel()
{
    SyntaxBlock::currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::SpecialIdentifier::Modulus::Check()
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
    Cancel();
    return false;
}

void SyntaxBlock::CFG::SpecialIdentifier::SquareOfNumber::Cancel()
{
    SyntaxBlock::currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::SpecialIdentifier::SquareOfNumber::Check()
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
    Cancel();
    return false;
}

void SyntaxBlock::CFG::SpecialIdentifier::SquareRootOfNumber::Cancel()
{
    SyntaxBlock::currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::SpecialIdentifier::SquareRootOfNumber::Check()
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
    Cancel();
    return false;
}

void SyntaxBlock::CFG::Variable::Identifier::Cancel()
{
    SyntaxBlock::currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::Variable::Identifier::Check()
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
                Cancel();
                return false;
            }
        }
        SyntaxBlock::LoadToken();
        return true;
    }
    Cancel();
    return false;
}

void SyntaxBlock::CFG::Variable::Integer::Cancel()
{
    SyntaxBlock::currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::Variable::Integer::Check()
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
                Cancel();
                return false;
            }
            SyntaxBlock::LoadToken();
            return true;
        }
    }
    Cancel();
    return false;
}

void SyntaxBlock::CFG::Variable::Edge::Cancel()
{
    SyntaxBlock::currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::Variable::Edge::Check()
{
    beginningIndex = SyntaxBlock::currentTokenIndexInVector;

    if (!SyntaxBlock::CFG::Variable::Identifier::Check())
    {
        Cancel();
        return false;
    }

    if (!SyntaxBlock::CFG::Symbol::OpeningParenthesis::Check())
    {
        Cancel();
        return false;
    }

    if (!SyntaxBlock::CFG::Variable::Integer::Check())
    {
        Cancel();
        return false;
    }

    if (!SyntaxBlock::CFG::Symbol::Comma::Check())
    {
        if (!SyntaxBlock::CFG::Symbol::ClosingParenthesis::Check())
        {
            Cancel();
            return false;
        }

        return true;
    }
    else
    {
        if (!SyntaxBlock::CFG::Variable::Integer::Check())
        {
            Cancel();
            return false;
        }

        if (!SyntaxBlock::CFG::Symbol::ClosingParenthesis::Check())
        {
            Cancel();
            return false;
        }

        return true;
    }
}

void SyntaxBlock::CFG::Variable::Cancel()
{
    SyntaxBlock::currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::Variable::Check()
{
    beginningIndex = SyntaxBlock::currentTokenIndexInVector;

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
    Cancel();
    return false;
}

void SyntaxBlock::CFG::Operation::Logical::Cancel()
{
    SyntaxBlock::currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::Operation::Logical::Check()
{
    beginningIndex = SyntaxBlock::currentTokenIndexInVector;

    if (SyntaxBlock::CFG::Symbol::ExclamationMark::Check())
    {
        if (SyntaxBlock::CFG::Symbol::EqualSign::Check())
        {
            return true;
        }
        Cancel();
        return false;
    }
    else if (SyntaxBlock::CFG::Symbol::EqualSign::Check())
    {
        if (SyntaxBlock::CFG::Symbol::EqualSign::Check())
        {
            return true;
        }
        Cancel();
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
    else if (SyntaxBlock::CFG::Symbol::LogicalSign::Check())
    {
        return true;
    }
    Cancel();
    return false;
}

void SyntaxBlock::CFG::Operation::Arithmetic::Cancel()
{
    SyntaxBlock::currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::Operation::Arithmetic::Check()
{
    beginningIndex = SyntaxBlock::currentTokenIndexInVector;

    if (SyntaxBlock::CFG::Symbol::ArithmeticSign::Check())
    {
        return true;
    }
    if (SyntaxBlock::CFG::SpecialIdentifier::Modulus::Check())
    {
        return true;
    }
    if (SyntaxBlock::CFG::SpecialIdentifier::SquareOfNumber::Check())
    {
        return true;
    }
    if (SyntaxBlock::CFG::SpecialIdentifier::SquareRootOfNumber::Check())
    {
        return true;
    }
    Cancel();
    return false;
}

void SyntaxBlock::CFG::Operation::Cancel()
{
    SyntaxBlock::currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::Operation::Check()
{
    beginningIndex = SyntaxBlock::currentTokenIndexInVector;

    if (SyntaxBlock::CFG::Operation::Logical::Check())
    {
        return true;
    }
    else if (SyntaxBlock::CFG::Operation::Arithmetic::Check())
    {
        return true;
    }
    Cancel();
    return false;
}

void SyntaxBlock::CFG::String::Beginning::Cancel()
{
    SyntaxBlock::currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::String::Beginning::Check()
{
    beginningIndex = SyntaxBlock::currentTokenIndexInVector;

    if (SyntaxBlock::CFG::Variable::Edge::Check())
    {
        return true;
    }
    else if (SyntaxBlock::CFG::Variable::Identifier::Check())
    {
        return true;
    }
    Cancel();
    return false;
}

void SyntaxBlock::CFG::String::Inner::Operation::Cancel()
{
    SyntaxBlock::currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::String::Inner::Operation::Check()
{
    beginningIndex = SyntaxBlock::currentTokenIndexInVector;

    if (!SyntaxBlock::CFG::Symbol::QuotationMark::Check())
    {
        Cancel();
        return false;
    }
    if (!SyntaxBlock::CFG::SpecialIdentifier::Operation::Check())
    {
        Cancel();
        return false;
    }
    if (!SyntaxBlock::CFG::Symbol::QuotationMark::Check())
    {
        Cancel();
        return false;
    }
    if (!SyntaxBlock::CFG::Symbol::Colon::Check())
    {
        Cancel();
        return false;
    }
    if (!SyntaxBlock::CFG::Symbol::QuotationMark::Check())
    {
        Cancel();
        return false;
    }
    if (!SyntaxBlock::CFG::Operation::Check())
    {
        Cancel();
        return false;
    }
    if (!SyntaxBlock::CFG::Symbol::QuotationMark::Check())
    {
        Cancel();
        return false;
    }
    return true;
}

void SyntaxBlock::CFG::String::Inner::Operand::Unary::Cancel()
{
    SyntaxBlock::currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::String::Inner::Operand::Unary::Check()
{
    beginningIndex = SyntaxBlock::currentTokenIndexInVector;

    if (!SyntaxBlock::CFG::Symbol::QuotationMark::Check())
    {
        Cancel();
        return false;
    }
    if (!SyntaxBlock::CFG::SpecialIdentifier::OperandOfUnaryOperation::Check())
    {
        Cancel();
        return false;
    }
    if (!SyntaxBlock::CFG::Symbol::QuotationMark::Check())
    {
        Cancel();
        return false;
    }
    if (!SyntaxBlock::CFG::Symbol::Colon::Check())
    {
        Cancel();
        return false;
    }
    if (SyntaxBlock::CFG::String::Inner::Check())
    {
        // Cancel();
        return true;
    }
    if (!SyntaxBlock::CFG::Symbol::QuotationMark::Check())
    {
        Cancel();
        return false;
    }
    if (!SyntaxBlock::CFG::Variable::Check())
    {
        Cancel();
        return false;
    }
    if (!SyntaxBlock::CFG::Symbol::QuotationMark::Check())
    {
        Cancel();
        return false;
    }
    // if (SyntaxBlock::CFG::Symbol::QuotationMark::Check())
    // {
    //     if (!SyntaxBlock::CFG::Variable::Check())
    //     {
    //         Cancel();
    //         return false;
    //     }
    //     if (!SyntaxBlock::CFG::Symbol::QuotationMark::Check())
    //     {
    //         Cancel();
    //         return false;
    //     }
    // }
    // else
    // {
    //     if (!SyntaxBlock::CFG::String::Inner::Check())
    //     {
    //         Cancel();
    //         return false;
    //     }
    // }
    return true;
}

void SyntaxBlock::CFG::String::Inner::Operand::Binary::First::Cancel()
{
    SyntaxBlock::currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::String::Inner::Operand::Binary::First::Check()
{
    beginningIndex = SyntaxBlock::currentTokenIndexInVector;

    if (!SyntaxBlock::CFG::Symbol::QuotationMark::Check())
    {
        Cancel();
        return false;
    }
    if (!SyntaxBlock::CFG::SpecialIdentifier::FirstOperandOfBinaryOperation::Check())
    {
        Cancel();
        return false;
    }
    if (!SyntaxBlock::CFG::Symbol::QuotationMark::Check())
    {
        Cancel();
        return false;
    }
    if (!SyntaxBlock::CFG::Symbol::Colon::Check())
    {
        Cancel();
        return false;
    }
    auto bb = SyntaxBlock::currentTokenIndexInVector;
    if (SyntaxBlock::CFG::String::Inner::Check())
    {
        // Cancel();
        return true;
    }
    if (!SyntaxBlock::CFG::Symbol::QuotationMark::Check())
    {
        Cancel();
        return false;
    }
    if (!SyntaxBlock::CFG::Variable::Check())
    {
        Cancel();
        return false;
    }
    if (!SyntaxBlock::CFG::Symbol::QuotationMark::Check())
    {
        Cancel();
        return false;
    }
    // else
    // {
    //     if (!SyntaxBlock::CFG::String::Inner::Check())
    //     {
    //         Cancel();
    //         return false;
    //     }
    // }
    return true;
}

void SyntaxBlock::CFG::String::Inner::Operand::Binary::Second::Cancel()
{
    SyntaxBlock::currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::String::Inner::Operand::Binary::Second::Check()
{
    beginningIndex = SyntaxBlock::currentTokenIndexInVector;

    if (!SyntaxBlock::CFG::Symbol::QuotationMark::Check())
    {
        Cancel();
        return false;
    }
    if (!SyntaxBlock::CFG::SpecialIdentifier::SecondOperandOfBinaryOperation::Check())
    {
        Cancel();
        return false;
    }
    if (!SyntaxBlock::CFG::Symbol::QuotationMark::Check())
    {
        Cancel();
        return false;
    }
    if (!SyntaxBlock::CFG::Symbol::Colon::Check())
    {
        Cancel();
        return false;
    }
    // if (SyntaxBlock::CFG::Symbol::QuotationMark::Check())
    // {
    //     if (!SyntaxBlock::CFG::Variable::Check())
    //     {
    //         Cancel();
    //         return false;
    //     }
    //     if (!SyntaxBlock::CFG::Symbol::QuotationMark::Check())
    //     {
    //         Cancel();
    //         return false;
    //     }
    // }
    // else
    // {
    //     if (!SyntaxBlock::CFG::String::Inner::Check())
    //     {
    //         Cancel();
    //         return false;
    //     }
    // }

    if (SyntaxBlock::CFG::String::Inner::Check())
    {
        // Cancel();
        return true;
    }
    if (!SyntaxBlock::CFG::Symbol::QuotationMark::Check())
    {
        Cancel();
        return false;
    }
    if (!SyntaxBlock::CFG::Variable::Check())
    {
        Cancel();
        return false;
    }
    if (!SyntaxBlock::CFG::Symbol::QuotationMark::Check())
    {
        Cancel();
        return false;
    }
    return true;
}

void SyntaxBlock::CFG::String::Inner::Operand::Binary::Cancel()
{
    SyntaxBlock::currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::String::Inner::Operand::Binary::Check()
{
    beginningIndex = SyntaxBlock::currentTokenIndexInVector;

    if (!SyntaxBlock::CFG::String::Inner::Operand::Binary::First::Check())
    {
        Cancel();
        return false;
    }
    if (!SyntaxBlock::CFG::Symbol::Comma::Check())
    {
        Cancel();
        return false;
    }
    if (!SyntaxBlock::CFG::String::Inner::Operand::Binary::Second::Check())
    {
        Cancel();
        return false;
    }
    return true;
}

void SyntaxBlock::CFG::String::Inner::Operand::Cancel()
{
    SyntaxBlock::currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::String::Inner::Operand::Check()
{
    beginningIndex = SyntaxBlock::currentTokenIndexInVector;

    if (SyntaxBlock::CFG::String::Inner::Operand::Unary::Check())
    {
        return true;
    }
    if (SyntaxBlock::CFG::String::Inner::Operand::Binary::Check())
    {
        return true;
    }
    Cancel();
    return false;
}

void SyntaxBlock::CFG::String::Inner::Cancel()
{
    SyntaxBlock::currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::String::Inner::Check()
{
    beginningIndex = SyntaxBlock::currentTokenIndexInVector;

    if (!SyntaxBlock::CFG::Symbol::OpeningCurlyBrace::Check())
    {
        Cancel();
        return false;
    }
    auto buf1 = SyntaxBlock::currentTokenIndexInVector;
    if (!SyntaxBlock::CFG::String::Inner::Operation::Check())
    {
        Cancel();
        return false;
    }
    auto buf2 = SyntaxBlock::currentTokenIndexInVector;
    if (!SyntaxBlock::CFG::Symbol::Comma::Check())
    {
        Cancel();
        return false;
    }
    auto buf3 = SyntaxBlock::currentTokenIndexInVector;
    if (!SyntaxBlock::CFG::String::Inner::Operand::Check())
    {
        Cancel();
        return false;
    }
    auto buf4 = SyntaxBlock::currentTokenIndexInVector;
    if (!SyntaxBlock::CFG::Symbol::ClosingCurlyBrace::Check())
    {
        Cancel();
        return false;
    }
    return true;
}

void SyntaxBlock::CFG::String::Logical::Cancel()
{
    SyntaxBlock::currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::String::Logical::Check()
{
    beginningIndex = SyntaxBlock::currentTokenIndexInVector;

    if (SyntaxBlock::CFG::String::Inner::Check())
    {
        return true;
    }

    // если нет логической части (то есть вид `[...]=;[...]`), проверяем, есть ли впереди знак `;` и возвращаемся обратно
    if (SyntaxBlock::CFG::Symbol::Semicolon::Check())
    {
        Cancel();
        return true;
    }
    Cancel();
    return false;
}

void SyntaxBlock::CFG::String::Arithmetic::Cancel()
{
    SyntaxBlock::currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::String::Arithmetic::Check()
{
    beginningIndex = SyntaxBlock::currentTokenIndexInVector;

    if (SyntaxBlock::CFG::String::Arithmetic::NoRealSolution::Check())
    {
        return true;
    }
    
    if (SyntaxBlock::CFG::String::Inner::Check())
    {
        return true;
    }
    if (SyntaxBlock::CFG::Variable::Integer::Check())
    {
        return true;
    }
    if (SyntaxBlock::CFG::Variable::Edge::Check())
    {
        return true;
    }
    Cancel();
    return false;
}

void SyntaxBlock::CFG::String::Arithmetic::NoRealSolution::Cancel()
{
    SyntaxBlock::currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::String::Arithmetic::NoRealSolution::Check()
{
    beginningIndex = SyntaxBlock::currentTokenIndexInVector;
    auto buf = beginningIndex;

    if (!SyntaxBlock::CFG::Symbol::OpeningCurlyBrace::Check())
    {
        Cancel();
        return false;
    }
    if (!SyntaxBlock::CFG::Symbol::QuotationMark::Check())
    {
        Cancel();
        return false;
    }
    if (!SyntaxBlock::CFG::SpecialIdentifier::V::Check())
    {
        Cancel();
        return false;
    }
    if (!SyntaxBlock::CFG::Symbol::QuotationMark::Check())
    {
        Cancel();
        return false;
    }
    if (!SyntaxBlock::CFG::Symbol::Colon::Check())
    {
        Cancel();
        return false;
    }
    if (!SyntaxBlock::CFG::Symbol::QuotationMark::Check())
    {
        Cancel();
        return false;
    }
    if (!SyntaxBlock::CFG::SpecialIdentifier::No::Check())
    {
        Cancel();
        return false;
    }
    if (!SyntaxBlock::CFG::SpecialIdentifier::Real::Check())
    {
        Cancel();
        return false;
    }
    if (!SyntaxBlock::CFG::SpecialIdentifier::Solution::Check())
    {
        Cancel();
        return false;
    }
    if (!SyntaxBlock::CFG::Symbol::QuotationMark::Check())
    {
        Cancel();
        return false;
    }
    if (!SyntaxBlock::CFG::Symbol::ClosingCurlyBrace::Check())
    {
        Cancel();
        return false;
    }
    
    return true;
}

void SyntaxBlock::CFG::String::Cancel()
{
    SyntaxBlock::currentTokenIndexInVector = beginningIndex;
}

bool SyntaxBlock::CFG::String::Check()
{
    beginningIndex = SyntaxBlock::currentTokenIndexInVector;

    if (!SyntaxBlock::CFG::String::Beginning::Check())
    {
        Cancel();
        return false;
    }
    if (!SyntaxBlock::CFG::Symbol::EqualSign::Check())
    {
        Cancel();
        return false;
    }
    if (!SyntaxBlock::CFG::String::Logical::Check())
    {
        Cancel();
        return false;
    }
    auto buf1 = SyntaxBlock::currentTokenIndexInVector;
    if (!SyntaxBlock::CFG::Symbol::Semicolon::Check())
    {
        Cancel();
        return false;
    }
    if (!SyntaxBlock::CFG::String::Arithmetic::Check())
    {
        Cancel();
        return false;
    }
    auto buf2 = SyntaxBlock::currentTokenIndexInVector;

    // if (!SyntaxBlock::CFG::String::Arithmetic::NoRealSolution::Check())
    // {
    //     // return true;
    //     Cancel();
    //     return false;
    // }
    return true;
}