#include "LexicalBlock.h"

// начальное значение
LexicalBlockState LexicalBlock::state = LexicalBlockState::SPACE_STATE;

std::vector<CombinedToken> LexicalBlock::combinedTokenVector;

void LexicalBlock::Process(SimpleToken token)
{
    return;
}

void LexicalBlock::StartIdentifier(SimpleToken token)
{
    LexicalBlock::combinedTokenVector.push_back(CombinedToken::Identifier);
    LexicalBlock::Process(token);
}

void LexicalBlock::StartInteger(SimpleToken token)
{
    LexicalBlock::combinedTokenVector.push_back(CombinedToken::Integer);
    LexicalBlock::Process(token);
}

void LexicalBlock::StartComparisonOperation(SimpleToken token)
{
    LexicalBlock::combinedTokenVector.push_back(CombinedToken::ComparisonOperation);
    LexicalBlock::Process(token);
}

void LexicalBlock::StartOpeningCurlyBrace(SimpleToken token)
{
    LexicalBlock::combinedTokenVector.push_back(CombinedToken::OpeningCurlyBrace);
    LexicalBlock::Process(token);
}

void LexicalBlock::StartClosingCurlyBrace(SimpleToken token)
{
    LexicalBlock::combinedTokenVector.push_back(CombinedToken::ClosingCurlyBrace);
    LexicalBlock::Process(token);
}

void LexicalBlock::StartOpeningParenthesis(SimpleToken token)
{
    LexicalBlock::combinedTokenVector.push_back(CombinedToken::OpeningParenthesis);
    LexicalBlock::Process(token);
}

void LexicalBlock::StartClosingParenthesis(SimpleToken token)
{
    LexicalBlock::combinedTokenVector.push_back(CombinedToken::ClosingParenthesis);
    LexicalBlock::Process(token);
}

void LexicalBlock::StartComma(SimpleToken token)
{
    LexicalBlock::combinedTokenVector.push_back(CombinedToken::Comma);
    LexicalBlock::Process(token);
}

void LexicalBlock::StartColon(SimpleToken token)
{
    LexicalBlock::combinedTokenVector.push_back(CombinedToken::Colon);
    LexicalBlock::Process(token);
}

void LexicalBlock::StartSemicolon(SimpleToken token)
{
    LexicalBlock::combinedTokenVector.push_back(CombinedToken::Semicolon);
    LexicalBlock::Process(token);
}

void LexicalBlock::StartQuotationMark(SimpleToken token)
{
    LexicalBlock::combinedTokenVector.push_back(CombinedToken::QuotationMark);
    LexicalBlock::Process(token);
}

void LexicalBlock::StartArithmeticSign(SimpleToken token)
{
    LexicalBlock::combinedTokenVector.push_back(CombinedToken::ArithmeticSign);
    LexicalBlock::Process(token);
}

void LexicalBlock::StartLogicalSign(SimpleToken token)
{
    LexicalBlock::combinedTokenVector.push_back(CombinedToken::LogicalSign);
    LexicalBlock::Process(token);
}

void LexicalBlock::ProcessSimpleTokenDependingOnState(SimpleToken token)
{
    switch (LexicalBlock::state)
        {
            case LexicalBlockState::SPACE_STATE:
                switch (token)
                {
                    case SimpleToken::Letter:
                        LexicalBlock::StartIdentifier(token);
                        LexicalBlock::state = LexicalBlockState::IDENTIFIER_BEGIN;
                        return;
                    case SimpleToken::Digit:
                        LexicalBlock::StartInteger(token);
                        LexicalBlock::state = LexicalBlockState::INTEGER;
                        return;
                    case SimpleToken::OpeningCurlyBrace:
                        LexicalBlock::StartOpeningCurlyBrace(token);
                        return;
                    case SimpleToken::ClosingCurlyBrace:
                        LexicalBlock::StartClosingCurlyBrace(token);
                        return;
                    case SimpleToken::OpeningParenthesis:
                        LexicalBlock::StartOpeningParenthesis(token);
                        return;
                    case SimpleToken::ClosingParenthesis:
                        LexicalBlock::StartClosingParenthesis(token);
                        return;
                    case SimpleToken::Comma:
                        LexicalBlock::StartComma(token);
                        return;
                    case SimpleToken::Colon:
                        LexicalBlock::StartColon(token);
                        return;
                    case SimpleToken::Semicolon:
                        LexicalBlock::StartSemicolon(token);
                        return;
                    case SimpleToken::QuotationMark:
                        LexicalBlock::StartQuotationMark(token);
                        return;
                    case SimpleToken::EqualSign:
                        LexicalBlock::StartComparisonOperation(token);
                        LexicalBlock::state = LexicalBlockState::COMPARISON_OPERATION_BEGIN;
                        return;
                    case SimpleToken::ExclamationMark:
                        LexicalBlock::StartComparisonOperation(token);
                        LexicalBlock::state = LexicalBlockState::COMPARISON_OPERATION_BEGIN;
                        return;
                    case SimpleToken::ComparisonSign:
                        LexicalBlock::StartComparisonOperation(token);
                        LexicalBlock::state = LexicalBlockState::COMPARISON_OPERATION_BEGIN;
                        return;
                    case SimpleToken::ArithmeticSign:
                        LexicalBlock::StartArithmeticSign(token);
                        LexicalBlock::state = LexicalBlockState::ARITHMETIC_OPERATION;
                        return;
                    case SimpleToken::LogicalSign:
                        LexicalBlock::StartLogicalSign(token);
                        LexicalBlock::state = LexicalBlockState::LOGICAL_OPERATION;
                        return;
                    case SimpleToken::SpaceSign:
                        return;
                }
            
            case LexicalBlockState::IDENTIFIER_BEGIN:
                switch (token)
                {
                    case SimpleToken::Letter:
                        LexicalBlock::Process(token);
                        return;
                    case SimpleToken::Digit:
                        LexicalBlock::Process(token);
                        LexicalBlock::state = LexicalBlockState::IDENTIFIER_END;
                        return;
                    case SimpleToken::OpeningCurlyBrace:
                        LexicalBlock::StartOpeningCurlyBrace(token);
                        LexicalBlock::state = LexicalBlockState::SPACE_STATE;
                        return;
                    case SimpleToken::ClosingCurlyBrace:
                        LexicalBlock::StartClosingCurlyBrace(token);
                        LexicalBlock::state = LexicalBlockState::SPACE_STATE;
                        return;
                    case SimpleToken::OpeningParenthesis:
                        LexicalBlock::StartOpeningParenthesis(token);
                        LexicalBlock::state = LexicalBlockState::SPACE_STATE;
                        return;
                    case SimpleToken::ClosingParenthesis:
                        LexicalBlock::StartClosingParenthesis(token);
                        LexicalBlock::state = LexicalBlockState::SPACE_STATE;
                        return;
                    case SimpleToken::Comma:
                        LexicalBlock::StartComma(token);
                        LexicalBlock::state = LexicalBlockState::SPACE_STATE;
                        return;
                    case SimpleToken::Colon:
                        LexicalBlock::StartColon(token);
                        LexicalBlock::state = LexicalBlockState::SPACE_STATE;
                        return;
                    case SimpleToken::Semicolon:
                        LexicalBlock::StartSemicolon(token);
                        LexicalBlock::state = LexicalBlockState::SPACE_STATE;
                        return;
                    case SimpleToken::QuotationMark:
                        LexicalBlock::StartQuotationMark(token);
                        LexicalBlock::state = LexicalBlockState::SPACE_STATE;
                        return;
                    case SimpleToken::EqualSign:
                        LexicalBlock::StartComparisonOperation(token);
                        LexicalBlock::state = LexicalBlockState::COMPARISON_OPERATION_BEGIN;
                        return;
                    case SimpleToken::ExclamationMark:
                        LexicalBlock::StartComparisonOperation(token);
                        LexicalBlock::state = LexicalBlockState::COMPARISON_OPERATION_BEGIN;
                        return;
                    case SimpleToken::ComparisonSign:
                        LexicalBlock::StartComparisonOperation(token);
                        LexicalBlock::state = LexicalBlockState::COMPARISON_OPERATION_BEGIN;
                        return;
                    case SimpleToken::ArithmeticSign:
                        LexicalBlock::StartArithmeticSign(token);
                        LexicalBlock::state = LexicalBlockState::ARITHMETIC_OPERATION;
                        return;
                    case SimpleToken::LogicalSign:
                        LexicalBlock::StartLogicalSign(token);
                        LexicalBlock::state = LexicalBlockState::LOGICAL_OPERATION;
                        return;
                    case SimpleToken::SpaceSign:
                        LexicalBlock::state = LexicalBlockState::SPACE_STATE;
                        return;
                }

            case LexicalBlockState::IDENTIFIER_END:
                switch (token)
                {
                    case SimpleToken::Letter:
                        LexicalBlock::StartIdentifier(token);
                        LexicalBlock::state = LexicalBlockState::IDENTIFIER_BEGIN;
                        return;
                    case SimpleToken::Digit:
                        LexicalBlock::Process(token);
                        return;
                    case SimpleToken::OpeningCurlyBrace:
                        LexicalBlock::StartOpeningCurlyBrace(token);
                        LexicalBlock::state = LexicalBlockState::SPACE_STATE;
                        return;
                    case SimpleToken::ClosingCurlyBrace:
                        LexicalBlock::StartClosingCurlyBrace(token);
                        LexicalBlock::state = LexicalBlockState::SPACE_STATE;
                        return;
                    case SimpleToken::OpeningParenthesis:
                        LexicalBlock::StartOpeningParenthesis(token);
                        LexicalBlock::state = LexicalBlockState::SPACE_STATE;
                        return;
                    case SimpleToken::ClosingParenthesis:
                        LexicalBlock::StartClosingParenthesis(token);
                        LexicalBlock::state = LexicalBlockState::SPACE_STATE;
                        return;
                    case SimpleToken::Comma:
                        LexicalBlock::StartComma(token);
                        LexicalBlock::state = LexicalBlockState::SPACE_STATE;
                        return;
                    case SimpleToken::Colon:
                        LexicalBlock::StartColon(token);
                        LexicalBlock::state = LexicalBlockState::SPACE_STATE;
                        return;
                    case SimpleToken::Semicolon:
                        LexicalBlock::StartSemicolon(token);
                        LexicalBlock::state = LexicalBlockState::SPACE_STATE;
                        return;
                    case SimpleToken::QuotationMark:
                        LexicalBlock::StartQuotationMark(token);
                        LexicalBlock::state = LexicalBlockState::SPACE_STATE;
                        return;
                    case SimpleToken::EqualSign:
                        LexicalBlock::StartComparisonOperation(token);
                        LexicalBlock::state = LexicalBlockState::COMPARISON_OPERATION_BEGIN;
                        return;
                    case SimpleToken::ExclamationMark:
                        LexicalBlock::StartComparisonOperation(token);
                        LexicalBlock::state = LexicalBlockState::COMPARISON_OPERATION_BEGIN;
                        return;
                    case SimpleToken::ComparisonSign:
                        LexicalBlock::StartComparisonOperation(token);
                        LexicalBlock::state = LexicalBlockState::COMPARISON_OPERATION_BEGIN;
                        return;
                    case SimpleToken::ArithmeticSign:
                        LexicalBlock::StartArithmeticSign(token);
                        LexicalBlock::state = LexicalBlockState::ARITHMETIC_OPERATION;
                        return;
                    case SimpleToken::LogicalSign:
                        LexicalBlock::StartLogicalSign(token);
                        LexicalBlock::state = LexicalBlockState::LOGICAL_OPERATION;
                        return;
                    case SimpleToken::SpaceSign:
                        LexicalBlock::state = LexicalBlockState::SPACE_STATE;
                        return;
                }

            case LexicalBlockState::INTEGER:
                switch (token)
                {
                    case SimpleToken::Letter:
                        LexicalBlock::StartIdentifier(token);
                        LexicalBlock::state = LexicalBlockState::IDENTIFIER_BEGIN;
                        return;
                    case SimpleToken::Digit:
                        LexicalBlock::Process(token);
                        return;
                    case SimpleToken::OpeningCurlyBrace:
                        LexicalBlock::StartOpeningCurlyBrace(token);
                        LexicalBlock::state = LexicalBlockState::SPACE_STATE;
                        return;
                    case SimpleToken::ClosingCurlyBrace:
                        LexicalBlock::StartClosingCurlyBrace(token);
                        LexicalBlock::state = LexicalBlockState::SPACE_STATE;
                        return;
                    case SimpleToken::OpeningParenthesis:
                        LexicalBlock::StartOpeningParenthesis(token);
                        LexicalBlock::state = LexicalBlockState::SPACE_STATE;
                        return;
                    case SimpleToken::ClosingParenthesis:
                        LexicalBlock::StartClosingParenthesis(token);
                        LexicalBlock::state = LexicalBlockState::SPACE_STATE;
                        return;
                    case SimpleToken::Comma:
                        LexicalBlock::Process(token);
                        return;
                    case SimpleToken::Colon:
                        LexicalBlock::StartColon(token);
                        LexicalBlock::state = LexicalBlockState::SPACE_STATE;
                        return;
                    case SimpleToken::Semicolon:
                        LexicalBlock::StartSemicolon(token);
                        LexicalBlock::state = LexicalBlockState::SPACE_STATE;
                        return;
                    case SimpleToken::QuotationMark:
                        LexicalBlock::StartQuotationMark(token);
                        LexicalBlock::state = LexicalBlockState::SPACE_STATE;
                        return;
                    case SimpleToken::EqualSign:
                        LexicalBlock::StartComparisonOperation(token);
                        LexicalBlock::state = LexicalBlockState::COMPARISON_OPERATION_BEGIN;
                        return;
                    case SimpleToken::ExclamationMark:
                        LexicalBlock::StartComparisonOperation(token);
                        LexicalBlock::state = LexicalBlockState::COMPARISON_OPERATION_BEGIN;
                        return;
                    case SimpleToken::ComparisonSign:
                        LexicalBlock::StartComparisonOperation(token);
                        LexicalBlock::state = LexicalBlockState::COMPARISON_OPERATION_BEGIN;
                        return;
                    case SimpleToken::ArithmeticSign:
                        LexicalBlock::StartArithmeticSign(token);
                        LexicalBlock::state = LexicalBlockState::ARITHMETIC_OPERATION;
                        return;
                    case SimpleToken::LogicalSign:
                        LexicalBlock::StartLogicalSign(token);
                        LexicalBlock::state = LexicalBlockState::LOGICAL_OPERATION;
                        return;
                    case SimpleToken::SpaceSign:
                        LexicalBlock::state = LexicalBlockState::SPACE_STATE;
                        return;
                }

            case LexicalBlockState::ARITHMETIC_OPERATION:
                switch (token)
                {
                    case SimpleToken::Letter:
                        LexicalBlock::StartIdentifier(token);
                        LexicalBlock::state = LexicalBlockState::IDENTIFIER_BEGIN;
                        return;
                    case SimpleToken::Digit:
                        LexicalBlock::StartInteger(token);
                        LexicalBlock::state = LexicalBlockState::INTEGER;
                        return;
                    case SimpleToken::OpeningCurlyBrace:
                        LexicalBlock::StartOpeningCurlyBrace(token);
                        LexicalBlock::state = LexicalBlockState::SPACE_STATE;
                        return;
                    case SimpleToken::ClosingCurlyBrace:
                        LexicalBlock::StartClosingCurlyBrace(token);
                        LexicalBlock::state = LexicalBlockState::SPACE_STATE;
                        return;
                    case SimpleToken::OpeningParenthesis:
                        LexicalBlock::StartOpeningParenthesis(token);
                        LexicalBlock::state = LexicalBlockState::SPACE_STATE;
                        return;
                    case SimpleToken::ClosingParenthesis:
                        LexicalBlock::StartClosingParenthesis(token);
                        LexicalBlock::state = LexicalBlockState::SPACE_STATE;
                        return;
                    case SimpleToken::Comma:
                        LexicalBlock::Process(token);
                        return;
                    case SimpleToken::Colon:
                        LexicalBlock::StartColon(token);
                        LexicalBlock::state = LexicalBlockState::SPACE_STATE;
                        return;
                    case SimpleToken::Semicolon:
                        LexicalBlock::StartSemicolon(token);
                        LexicalBlock::state = LexicalBlockState::SPACE_STATE;
                        return;
                    case SimpleToken::QuotationMark:
                        LexicalBlock::StartQuotationMark(token);
                        LexicalBlock::state = LexicalBlockState::SPACE_STATE;
                        return;
                    case SimpleToken::EqualSign:
                        LexicalBlock::StartComparisonOperation(token);
                        LexicalBlock::state = LexicalBlockState::COMPARISON_OPERATION_BEGIN;
                        return;
                    case SimpleToken::ExclamationMark:
                        LexicalBlock::StartComparisonOperation(token);
                        LexicalBlock::state = LexicalBlockState::COMPARISON_OPERATION_BEGIN;
                        return;
                    case SimpleToken::ComparisonSign:
                        LexicalBlock::StartComparisonOperation(token);
                        LexicalBlock::state = LexicalBlockState::COMPARISON_OPERATION_BEGIN;
                        return;
                    case SimpleToken::ArithmeticSign:
                        LexicalBlock::StartArithmeticSign(token);
                        LexicalBlock::state = LexicalBlockState::ARITHMETIC_OPERATION;
                        return;
                    case SimpleToken::LogicalSign:
                        LexicalBlock::StartLogicalSign(token);
                        LexicalBlock::state = LexicalBlockState::LOGICAL_OPERATION;
                        return;
                    case SimpleToken::SpaceSign:
                        LexicalBlock::state = LexicalBlockState::SPACE_STATE;
                        return;
                }

            case LexicalBlockState::LOGICAL_OPERATION:
                switch (token)
                {
                    case SimpleToken::Letter:
                        LexicalBlock::StartIdentifier(token);
                        LexicalBlock::state = LexicalBlockState::IDENTIFIER_BEGIN;
                        return;
                    case SimpleToken::Digit:
                        LexicalBlock::StartInteger(token);
                        LexicalBlock::state = LexicalBlockState::INTEGER;
                        return;
                    case SimpleToken::OpeningCurlyBrace:
                        LexicalBlock::StartOpeningCurlyBrace(token);
                        LexicalBlock::state = LexicalBlockState::SPACE_STATE;
                        return;
                    case SimpleToken::ClosingCurlyBrace:
                        LexicalBlock::StartClosingCurlyBrace(token);
                        LexicalBlock::state = LexicalBlockState::SPACE_STATE;
                        return;
                    case SimpleToken::OpeningParenthesis:
                        LexicalBlock::StartOpeningParenthesis(token);
                        LexicalBlock::state = LexicalBlockState::SPACE_STATE;
                        return;
                    case SimpleToken::ClosingParenthesis:
                        LexicalBlock::StartClosingParenthesis(token);
                        LexicalBlock::state = LexicalBlockState::SPACE_STATE;
                        return;
                    case SimpleToken::Comma:
                        LexicalBlock::Process(token);
                        return;
                    case SimpleToken::Colon:
                        LexicalBlock::StartColon(token);
                        LexicalBlock::state = LexicalBlockState::SPACE_STATE;
                        return;
                    case SimpleToken::Semicolon:
                        LexicalBlock::StartSemicolon(token);
                        LexicalBlock::state = LexicalBlockState::SPACE_STATE;
                        return;
                    case SimpleToken::QuotationMark:
                        LexicalBlock::StartQuotationMark(token);
                        LexicalBlock::state = LexicalBlockState::SPACE_STATE;
                        return;
                    case SimpleToken::EqualSign:
                        LexicalBlock::StartComparisonOperation(token);
                        LexicalBlock::state = LexicalBlockState::COMPARISON_OPERATION_BEGIN;
                        return;
                    case SimpleToken::ExclamationMark:
                        LexicalBlock::StartComparisonOperation(token);
                        LexicalBlock::state = LexicalBlockState::COMPARISON_OPERATION_BEGIN;
                        return;
                    case SimpleToken::ComparisonSign:
                        LexicalBlock::StartComparisonOperation(token);
                        LexicalBlock::state = LexicalBlockState::COMPARISON_OPERATION_BEGIN;
                        return;
                    case SimpleToken::ArithmeticSign:
                        LexicalBlock::StartArithmeticSign(token);
                        LexicalBlock::state = LexicalBlockState::ARITHMETIC_OPERATION;
                        return;
                    case SimpleToken::LogicalSign:
                        LexicalBlock::StartLogicalSign(token);
                        LexicalBlock::state = LexicalBlockState::LOGICAL_OPERATION;
                        return;
                    case SimpleToken::SpaceSign:
                        LexicalBlock::state = LexicalBlockState::SPACE_STATE;
                        return;
                }

            case LexicalBlockState::COMPARISON_OPERATION_BEGIN:
                switch (token)
                {
                    case SimpleToken::Letter:
                        LexicalBlock::StartIdentifier(token);
                        LexicalBlock::state = LexicalBlockState::IDENTIFIER_BEGIN;
                        return;
                    case SimpleToken::Digit:
                        LexicalBlock::StartInteger(token);
                        LexicalBlock::state = LexicalBlockState::INTEGER;
                        return;
                    case SimpleToken::OpeningCurlyBrace:
                        LexicalBlock::StartOpeningCurlyBrace(token);
                        LexicalBlock::state = LexicalBlockState::SPACE_STATE;
                        return;
                    case SimpleToken::ClosingCurlyBrace:
                        LexicalBlock::StartClosingCurlyBrace(token);
                        LexicalBlock::state = LexicalBlockState::SPACE_STATE;
                        return;
                    case SimpleToken::OpeningParenthesis:
                        LexicalBlock::StartOpeningParenthesis(token);
                        LexicalBlock::state = LexicalBlockState::SPACE_STATE;
                        return;
                    case SimpleToken::ClosingParenthesis:
                        LexicalBlock::StartClosingParenthesis(token);
                        LexicalBlock::state = LexicalBlockState::SPACE_STATE;
                        return;
                    case SimpleToken::Comma:
                        LexicalBlock::Process(token);
                        return;
                    case SimpleToken::Colon:
                        LexicalBlock::StartColon(token);
                        LexicalBlock::state = LexicalBlockState::SPACE_STATE;
                        return;
                    case SimpleToken::Semicolon:
                        LexicalBlock::StartSemicolon(token);
                        LexicalBlock::state = LexicalBlockState::SPACE_STATE;
                        return;
                    case SimpleToken::QuotationMark:
                        LexicalBlock::StartQuotationMark(token);
                        LexicalBlock::state = LexicalBlockState::SPACE_STATE;
                        return;
                    case SimpleToken::EqualSign:
                        LexicalBlock::Process(token);
                        LexicalBlock::state = LexicalBlockState::COMPARISON_OPERATION_END;
                        return;
                    // case SimpleToken::ExclamationMark:
                    //     LexicalBlock::StartComparisonOperation(token);
                    //     LexicalBlock::state = LexicalBlockState::COMPARISON_OPERATION_BEGIN;
                    //     return;
                    case SimpleToken::ComparisonSign:
                        LexicalBlock::StartComparisonOperation(token);
                        LexicalBlock::state = LexicalBlockState::COMPARISON_OPERATION_BEGIN;
                        return;
                    case SimpleToken::ArithmeticSign:
                        LexicalBlock::StartArithmeticSign(token);
                        LexicalBlock::state = LexicalBlockState::ARITHMETIC_OPERATION;
                        return;
                    case SimpleToken::LogicalSign:
                        LexicalBlock::StartLogicalSign(token);
                        LexicalBlock::state = LexicalBlockState::LOGICAL_OPERATION;
                        return;
                    case SimpleToken::SpaceSign:
                        LexicalBlock::state = LexicalBlockState::SPACE_STATE;
                        return;
                }

            case LexicalBlockState::COMPARISON_OPERATION_END:
                switch (token)
                {
                    case SimpleToken::Letter:
                        LexicalBlock::StartIdentifier(token);
                        LexicalBlock::state = LexicalBlockState::IDENTIFIER_BEGIN;
                        return;
                    case SimpleToken::Digit:
                        LexicalBlock::StartInteger(token);
                        LexicalBlock::state = LexicalBlockState::INTEGER;
                        return;
                    case SimpleToken::OpeningCurlyBrace:
                        LexicalBlock::StartOpeningCurlyBrace(token);
                        LexicalBlock::state = LexicalBlockState::SPACE_STATE;
                        return;
                    case SimpleToken::ClosingCurlyBrace:
                        LexicalBlock::StartClosingCurlyBrace(token);
                        LexicalBlock::state = LexicalBlockState::SPACE_STATE;
                        return;
                    case SimpleToken::OpeningParenthesis:
                        LexicalBlock::StartOpeningParenthesis(token);
                        LexicalBlock::state = LexicalBlockState::SPACE_STATE;
                        return;
                    case SimpleToken::ClosingParenthesis:
                        LexicalBlock::StartClosingParenthesis(token);
                        LexicalBlock::state = LexicalBlockState::SPACE_STATE;
                        return;
                    case SimpleToken::Comma:
                        LexicalBlock::Process(token);
                        return;
                    case SimpleToken::Colon:
                        LexicalBlock::StartColon(token);
                        LexicalBlock::state = LexicalBlockState::SPACE_STATE;
                        return;
                    case SimpleToken::Semicolon:
                        LexicalBlock::StartSemicolon(token);
                        LexicalBlock::state = LexicalBlockState::SPACE_STATE;
                        return;
                    case SimpleToken::QuotationMark:
                        LexicalBlock::StartQuotationMark(token);
                        LexicalBlock::state = LexicalBlockState::SPACE_STATE;
                        return;
                    case SimpleToken::EqualSign:
                        LexicalBlock::StartComparisonOperation(token);
                        LexicalBlock::state = LexicalBlockState::COMPARISON_OPERATION_BEGIN;
                        return;
                    case SimpleToken::ExclamationMark:
                        LexicalBlock::StartComparisonOperation(token);
                        LexicalBlock::state = LexicalBlockState::COMPARISON_OPERATION_BEGIN;
                        return;
                    case SimpleToken::ComparisonSign:
                        LexicalBlock::StartComparisonOperation(token);
                        LexicalBlock::state = LexicalBlockState::COMPARISON_OPERATION_BEGIN;
                        return;
                    case SimpleToken::ArithmeticSign:
                        LexicalBlock::StartArithmeticSign(token);
                        LexicalBlock::state = LexicalBlockState::ARITHMETIC_OPERATION;
                        return;
                    case SimpleToken::LogicalSign:
                        LexicalBlock::StartLogicalSign(token);
                        LexicalBlock::state = LexicalBlockState::LOGICAL_OPERATION;
                        return;
                    case SimpleToken::SpaceSign:
                        LexicalBlock::state = LexicalBlockState::SPACE_STATE;
                        return;
                }
    }
}
std::vector<CombinedToken> LexicalBlock::TransliterateSimpleTokenVector(std::vector<SimpleToken> tokens)
{
    for (SimpleToken token : tokens) {
        LexicalBlock::ProcessSimpleTokenDependingOnState(token);
    }
    return LexicalBlock::combinedTokenVector;
}