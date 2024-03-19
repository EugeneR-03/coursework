#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../blocks/Tokens.h"
#include "../blocks/TransliterationBlock.h"
#include "../blocks/LexicalBlock.h"
#include "../blocks/SyntaxBlock.h"

TEST_SUITE_BEGIN("TransliterationBlock");
TEST_CASE("a == Letter")
{
    CHECK(TransliterationBlock::TransliterateSymbol('a', 0) == SimpleToken(SimpleTokenType::Letter, 0));
}
TEST_CASE("a == Digit")
{
    CHECK(TransliterationBlock::TransliterateSymbol('1', 0) == SimpleToken(SimpleTokenType::Digit, 0));
}
TEST_SUITE_END();

TEST_SUITE_BEGIN("LexicalBlock");
TEST_SUITE_END();

using VariableToken = std::variant<SimpleToken, ComplexToken>;
TEST_SUITE_BEGIN("SyntaxBlock");
TEST_CASE("CFG")
{
    SUBCASE("Symbol")
    {
        SUBCASE("OpeningCurlyBrace")
        {
            auto token = SimpleToken(SimpleTokenType::OpeningCurlyBrace, 0);
            auto tokens = std::vector<VariableToken>{token};
            SyntaxBlock::LoadTokenVector(tokens);
            CHECK(SyntaxBlock::CFG::Symbol::OpeningCurlyBrace::Check());
        }

        SUBCASE("ClosingCurlyBrace")
        {
            auto token = SimpleToken(SimpleTokenType::ClosingCurlyBrace, 0);
            auto tokens = std::vector<VariableToken>{token};
            SyntaxBlock::LoadTokenVector(tokens);
            CHECK(SyntaxBlock::CFG::Symbol::ClosingCurlyBrace::Check());
        }

        SUBCASE("OpeningParenthesis")
        {
            auto token = SimpleToken(SimpleTokenType::OpeningParenthesis, 0);
            auto tokens = std::vector<VariableToken>{token};
            SyntaxBlock::LoadTokenVector(tokens);
            CHECK(SyntaxBlock::CFG::Symbol::OpeningParenthesis::Check());
        }

        SUBCASE("ClosingParenthesis")
        {
            auto token = SimpleToken(SimpleTokenType::ClosingParenthesis, 0);
            auto tokens = std::vector<VariableToken>{token};
            SyntaxBlock::LoadTokenVector(tokens);
            CHECK(SyntaxBlock::CFG::Symbol::ClosingParenthesis::Check());
        }

        SUBCASE("Comma")
        {
            auto token = SimpleToken(SimpleTokenType::Comma, 0);
            auto tokens = std::vector<VariableToken>{token};
            SyntaxBlock::LoadTokenVector(tokens);
            CHECK(SyntaxBlock::CFG::Symbol::Comma::Check());
        }

        SUBCASE("Colon")
        {
            auto token = SimpleToken(SimpleTokenType::Colon, 0);
            auto tokens = std::vector<VariableToken>{token};
            SyntaxBlock::LoadTokenVector(tokens);
            CHECK(SyntaxBlock::CFG::Symbol::Colon::Check());
        }

        SUBCASE("Semicolon")
        {
            auto token = SimpleToken(SimpleTokenType::Semicolon, 0);
            auto tokens = std::vector<VariableToken>{token};
            SyntaxBlock::LoadTokenVector(tokens);
            CHECK(SyntaxBlock::CFG::Symbol::Semicolon::Check());
        }

        SUBCASE("QuotationMark")
        {
            auto token = SimpleToken(SimpleTokenType::QuotationMark, 0);
            auto tokens = std::vector<VariableToken>{token};
            SyntaxBlock::LoadTokenVector(tokens);
            CHECK(SyntaxBlock::CFG::Symbol::QuotationMark::Check());
        }

        SUBCASE("EqualSign")
        {
            auto token = SimpleToken(SimpleTokenType::EqualSign, 0);
            auto tokens = std::vector<VariableToken>{token};
            SyntaxBlock::LoadTokenVector(tokens);
            CHECK(SyntaxBlock::CFG::Symbol::EqualSign::Check());
        }

        SUBCASE("ComparisonSign")
        {
            auto token = SimpleToken(SimpleTokenType::ComparisonSign, 0);
            auto tokens = std::vector<VariableToken>{token};
            SyntaxBlock::LoadTokenVector(tokens);
            CHECK(SyntaxBlock::CFG::Symbol::ComparisonSign::Check());
        }

        SUBCASE("ExclamationMark")
        {
            auto token = SimpleToken(SimpleTokenType::ExclamationMark, 0);
            auto tokens = std::vector<VariableToken>{token};
            SyntaxBlock::LoadTokenVector(tokens);
            CHECK(SyntaxBlock::CFG::Symbol::ExclamationMark::Check());
        }

        SUBCASE("ArithmeticSign")
        {
            auto token = SimpleToken(SimpleTokenType::ArithmeticSign, 0);
            auto tokens = std::vector<VariableToken>{token};
            SyntaxBlock::LoadTokenVector(tokens);
            CHECK(SyntaxBlock::CFG::Symbol::ArithmeticSign::Check());
        }

        SUBCASE("LogicalSign")
        {
            auto token = SimpleToken(SimpleTokenType::LogicalSign, 0);
            auto tokens = std::vector<VariableToken>{token};
            SyntaxBlock::LoadTokenVector(tokens);
            CHECK(SyntaxBlock::CFG::Symbol::LogicalSign::Check());
        }
    }

    SUBCASE("SpecialIdentifier")
    {
        SUBCASE("Operation")
        {
            auto token = ComplexToken(SpecialIdentifierType::Operation, "op", 0);
            auto tokens = std::vector<VariableToken>{token};
            SyntaxBlock::LoadTokenVector(tokens);
            CHECK(SyntaxBlock::CFG::SpecialIdentifier::Operation::Check());
        }

        SUBCASE("OperandOfUnaryOperation")
        {
            auto token = ComplexToken(SpecialIdentifierType::OperandOfUnaryOperation, "od", 0);
            auto tokens = std::vector<VariableToken>{token};
            SyntaxBlock::LoadTokenVector(tokens);
            CHECK(SyntaxBlock::CFG::SpecialIdentifier::OperandOfUnaryOperation::Check());
        }

        SUBCASE("FirstOperandOfBinaryOperation")
        {
            auto token = ComplexToken(SpecialIdentifierType::FirstOperandOfBinaryOperation, "fO", 0);
            auto tokens = std::vector<VariableToken>{token};
            SyntaxBlock::LoadTokenVector(tokens);
            CHECK(SyntaxBlock::CFG::SpecialIdentifier::FirstOperandOfBinaryOperation::Check());
        }

        SUBCASE("SecondOperandOfBinaryOperation")
        {
            auto token = ComplexToken(SpecialIdentifierType::SecondOperandOfBinaryOperation, "sO", 0);
            auto tokens = std::vector<VariableToken>{token};
            SyntaxBlock::LoadTokenVector(tokens);
            CHECK(SyntaxBlock::CFG::SpecialIdentifier::SecondOperandOfBinaryOperation::Check());
        }

        SUBCASE("V")
        {
            auto token = ComplexToken(SpecialIdentifierType::V, "v", 0);
            auto tokens = std::vector<VariableToken>{token};
            SyntaxBlock::LoadTokenVector(tokens);
            CHECK(SyntaxBlock::CFG::SpecialIdentifier::V::Check());
        }

        SUBCASE("No")
        {
            auto token = ComplexToken(SpecialIdentifierType::No, "no", 0);
            auto tokens = std::vector<VariableToken>{token};
            SyntaxBlock::LoadTokenVector(tokens);
            CHECK(SyntaxBlock::CFG::SpecialIdentifier::No::Check());
        }

        SUBCASE("Real")
        {
            auto token = ComplexToken(SpecialIdentifierType::Real, "real", 0);
            auto tokens = std::vector<VariableToken>{token};
            SyntaxBlock::LoadTokenVector(tokens);
            CHECK(SyntaxBlock::CFG::SpecialIdentifier::Real::Check());
        }

        SUBCASE("Solution")
        {
            auto token = ComplexToken(SpecialIdentifierType::Solution, "sol", 0);
            auto tokens = std::vector<VariableToken>{token};
            SyntaxBlock::LoadTokenVector(tokens);
            CHECK(SyntaxBlock::CFG::SpecialIdentifier::Solution::Check());
        }

        SUBCASE("Modulus")
        {
            auto token = ComplexToken(SpecialIdentifierType::Modulus, "abs", 0);
            auto tokens = std::vector<VariableToken>{token};
            SyntaxBlock::LoadTokenVector(tokens);
            CHECK(SyntaxBlock::CFG::SpecialIdentifier::Modulus::Check());
        }

        SUBCASE("SquareOfNumber")
        {
            auto token = ComplexToken(SpecialIdentifierType::SquareOfNumber, "sqr", 0);
            auto tokens = std::vector<VariableToken>{token};
            SyntaxBlock::LoadTokenVector(tokens);
            CHECK(SyntaxBlock::CFG::SpecialIdentifier::SquareOfNumber::Check());
        }

        SUBCASE("SquareRootOfNumber")
        {
            auto token = ComplexToken(SpecialIdentifierType::SquareRootOfNumber, "sqrt", 0);
            auto tokens = std::vector<VariableToken>{token};
            SyntaxBlock::LoadTokenVector(tokens);
            CHECK(SyntaxBlock::CFG::SpecialIdentifier::SquareRootOfNumber::Check());
        }
    }

    SUBCASE("Variable")
    {
        SUBCASE("Identifier")
        {
            auto tokens = std::vector<VariableToken>{
                ComplexToken(ComplexTokenType::Identifier, "x1", 0)
            };
            SyntaxBlock::LoadTokenVector(tokens);
            CHECK(SyntaxBlock::CFG::Variable::Identifier::Check());
        }

        SUBCASE("Integer")
        {
            auto tokens = std::vector<VariableToken>{
                ComplexToken(ComplexTokenType::Integer, "1", 0)
            };
            SyntaxBlock::LoadTokenVector(tokens);
            CHECK(SyntaxBlock::CFG::Variable::Integer::Check());
        }

        SUBCASE("Edge")
        {
            SUBCASE("with one Integer")
            {
                auto tokens = std::vector<VariableToken>{
                    ComplexToken(ComplexTokenType::Identifier, "x1", 0),
                    SimpleToken(SimpleTokenType::OpeningParenthesis, 1),
                    ComplexToken(ComplexTokenType::Integer, "1", 2),
                    SimpleToken(SimpleTokenType::ClosingParenthesis, 3)
                };
                SyntaxBlock::LoadTokenVector(tokens);
                CHECK(SyntaxBlock::CFG::Variable::Edge::Check());
            }
            SUBCASE("with two Integers")
            {
                auto tokens = std::vector<VariableToken>{
                    ComplexToken(ComplexTokenType::Identifier, "x1", 0),
                    SimpleToken(SimpleTokenType::OpeningParenthesis, 1),
                    ComplexToken(ComplexTokenType::Integer, "1", 2),
                    SimpleToken(SimpleTokenType::Comma, 3),
                    ComplexToken(ComplexTokenType::Integer, "2", 4),
                    SimpleToken(SimpleTokenType::ClosingParenthesis, 5)
                };
                SyntaxBlock::LoadTokenVector(tokens);
                CHECK(SyntaxBlock::CFG::Variable::Edge::Check());
            }
        }        
    
        SUBCASE("Variable Identifier")
        {
            auto tokens = std::vector<VariableToken>{
                ComplexToken(ComplexTokenType::Identifier, "x1", 0)
            };
            SyntaxBlock::LoadTokenVector(tokens);
            CHECK(SyntaxBlock::CFG::Variable::Check());
        }

        SUBCASE("Variable Integer")
        {
            auto tokens = std::vector<VariableToken>{
                ComplexToken(ComplexTokenType::Integer, "1", 0)
            };
            SyntaxBlock::LoadTokenVector(tokens);
            CHECK(SyntaxBlock::CFG::Variable::Check());
        }

        SUBCASE("Variable Edge")
        {
            SUBCASE("with one Integer")
            {
                auto tokens = std::vector<VariableToken>{
                    ComplexToken(ComplexTokenType::Identifier, "x1", 0),
                    SimpleToken(SimpleTokenType::OpeningParenthesis, 1),
                    ComplexToken(ComplexTokenType::Integer, "1", 2),
                    SimpleToken(SimpleTokenType::ClosingParenthesis, 3)
                };
                SyntaxBlock::LoadTokenVector(tokens);
                CHECK(SyntaxBlock::CFG::Variable::Check());
            }

            SUBCASE("with two Integers")
            {
                auto tokens = std::vector<VariableToken>{
                    ComplexToken(ComplexTokenType::Identifier, "x1", 0),
                    SimpleToken(SimpleTokenType::OpeningParenthesis, 1),
                    ComplexToken(ComplexTokenType::Integer, "1", 2),
                    SimpleToken(SimpleTokenType::Comma, 3),
                    ComplexToken(ComplexTokenType::Integer, "2", 4),
                    SimpleToken(SimpleTokenType::ClosingParenthesis, 5)
                };
                SyntaxBlock::LoadTokenVector(tokens);
                CHECK(SyntaxBlock::CFG::Variable::Check());
            }
        }
    }

    SUBCASE("Operation")
    {
        SUBCASE("Logical")
        {
            SUBCASE("!= (not equal)")
            {
                auto tokens = std::vector<VariableToken>{
                    SimpleToken(SimpleTokenType::ExclamationMark, 0),
                    SimpleToken(SimpleTokenType::EqualSign, 1),
                };
                SyntaxBlock::LoadTokenVector(tokens);
                CHECK(SyntaxBlock::CFG::Operation::Logical::Check());
            }
            SUBCASE("== (equal sign)")
            {
                auto tokens = std::vector<VariableToken>{
                    SimpleToken(SimpleTokenType::EqualSign, 0),
                    SimpleToken(SimpleTokenType::EqualSign, 1),
                };
                SyntaxBlock::LoadTokenVector(tokens);
                CHECK(SyntaxBlock::CFG::Operation::Logical::Check());
            }
            SUBCASE(">= or <= (comparison sign)")
            {
                auto tokens = std::vector<VariableToken>{
                    SimpleToken(SimpleTokenType::ComparisonSign, 0),
                    SimpleToken(SimpleTokenType::EqualSign, 1),
                };
                SyntaxBlock::LoadTokenVector(tokens);
                CHECK(SyntaxBlock::CFG::Operation::Logical::Check());
            }
            SUBCASE("& or | (logical sign)")
            {
                auto tokens = std::vector<VariableToken>{
                    SimpleToken(SimpleTokenType::LogicalSign, 0),
                };
                SyntaxBlock::LoadTokenVector(tokens);
                CHECK(SyntaxBlock::CFG::Operation::Logical::Check());
            }
        }

        SUBCASE("Arithmetic")
        {
            SUBCASE("+ or - or * or / (arithmetic sign)")
            {
                auto tokens = std::vector<VariableToken>{
                    SimpleToken(SimpleTokenType::ArithmeticSign, 0),
                };
                SyntaxBlock::LoadTokenVector(tokens);
                CHECK(SyntaxBlock::CFG::Operation::Arithmetic::Check());
            }
        }
    }

    SUBCASE("String")
    {        
        SUBCASE("Beginning")
        {
            SUBCASE("Identifier in the beginning")
            {
                auto tokens = std::vector<VariableToken>{
                    ComplexToken(ComplexTokenType::Identifier, "x1", 0),
                };
                SyntaxBlock::LoadTokenVector(tokens);
                CHECK(SyntaxBlock::CFG::String::Beginning::Check());
            }
            SUBCASE("Edge in the beginning")
            {
                SUBCASE("with one Integer")
                {
                    auto tokens = std::vector<VariableToken>{
                        ComplexToken(ComplexTokenType::Identifier, "x1", 0),
                        SimpleToken(SimpleTokenType::OpeningParenthesis, 1),
                        ComplexToken(ComplexTokenType::Integer, "1", 2),
                        SimpleToken(SimpleTokenType::ClosingParenthesis, 3)
                    };
                    SyntaxBlock::LoadTokenVector(tokens);
                    CHECK(SyntaxBlock::CFG::String::Beginning::Check());
                }
                SUBCASE("with two Integers")
                {
                    auto tokens = std::vector<VariableToken>{
                        ComplexToken(ComplexTokenType::Identifier, "x1", 0),
                        SimpleToken(SimpleTokenType::OpeningParenthesis, 1),
                        ComplexToken(ComplexTokenType::Integer, "1", 2),
                        SimpleToken(SimpleTokenType::Comma, 3),
                        ComplexToken(ComplexTokenType::Integer, "2", 4),
                        SimpleToken(SimpleTokenType::ClosingParenthesis, 5)
                    };
                    SyntaxBlock::LoadTokenVector(tokens);
                    CHECK(SyntaxBlock::CFG::String::Beginning::Check());
                }
            }
        }

        SUBCASE("Inner")
        {
            SUBCASE("Operation")
            {
                // "op":"!="
                auto tokens = std::vector<VariableToken>{
                    SimpleToken(SimpleTokenType::QuotationMark, 0),
                    ComplexToken(SpecialIdentifierType::Operation, "op", 1),
                    SimpleToken(SimpleTokenType::QuotationMark, 2),
                    SimpleToken(SimpleTokenType::Colon, 3),
                    SimpleToken(SimpleTokenType::QuotationMark, 4),
                    SimpleToken(SimpleTokenType::ExclamationMark, 5),
                    SimpleToken(SimpleTokenType::EqualSign, 6),
                    SimpleToken(SimpleTokenType::QuotationMark, 7),
                };
                SyntaxBlock::LoadTokenVector(tokens);
                CHECK(SyntaxBlock::CFG::String::Inner::Operation::Check());
            }

            SUBCASE("Operand")
            {
                SUBCASE("Unary")
                {
                    auto tokens = std::vector<VariableToken>{
                        SimpleToken(SimpleTokenType::QuotationMark, 0),
                        ComplexToken(SpecialIdentifierType::OperandOfUnaryOperation, "od", 1),
                        SimpleToken(SimpleTokenType::QuotationMark, 2),
                        SimpleToken(SimpleTokenType::Colon, 3),
                        SimpleToken(SimpleTokenType::QuotationMark, 4),
                        ComplexToken(ComplexTokenType::Identifier, "x1", 5),
                        SimpleToken(SimpleTokenType::QuotationMark, 6),
                    };
                    SyntaxBlock::LoadTokenVector(tokens);
                    CHECK(SyntaxBlock::CFG::String::Inner::Operand::Unary::Check());
                }

                SUBCASE("Binary")
                {
                    SUBCASE("First")
                    {
                        // "fO":"x1"
                        auto tokens = std::vector<VariableToken>{
                            SimpleToken(SimpleTokenType::QuotationMark, 0),
                            ComplexToken(SpecialIdentifierType::FirstOperandOfBinaryOperation, "fO", 1),
                            SimpleToken(SimpleTokenType::QuotationMark, 2),
                            SimpleToken(SimpleTokenType::Colon, 3),
                            SimpleToken(SimpleTokenType::QuotationMark, 4),
                            ComplexToken(ComplexTokenType::Identifier, "x1", 5),
                            SimpleToken(SimpleTokenType::QuotationMark, 6),
                        };
                        SyntaxBlock::LoadTokenVector(tokens);
                        CHECK(SyntaxBlock::CFG::String::Inner::Operand::Binary::First::Check());
                    }

                    SUBCASE("Second")
                    {
                        // "sO":"x1"
                        auto tokens = std::vector<VariableToken>{
                            SimpleToken(SimpleTokenType::QuotationMark, 0),
                            ComplexToken(SpecialIdentifierType::SecondOperandOfBinaryOperation, "sO", 1),
                            SimpleToken(SimpleTokenType::QuotationMark, 2),
                            SimpleToken(SimpleTokenType::Colon, 3),
                            SimpleToken(SimpleTokenType::QuotationMark, 4),
                            ComplexToken(ComplexTokenType::Identifier, "x1", 5),
                            SimpleToken(SimpleTokenType::QuotationMark, 6),
                        };
                        SyntaxBlock::LoadTokenVector(tokens);
                        CHECK(SyntaxBlock::CFG::String::Inner::Operand::Binary::Second::Check());
                    }

                    SUBCASE("Binary full")
                    {
                        // "fO":"x1","sO":"x1"
                        auto tokens = std::vector<VariableToken>{
                            SimpleToken(SimpleTokenType::QuotationMark, 0),
                            ComplexToken(SpecialIdentifierType::FirstOperandOfBinaryOperation, "fO", 1),
                            SimpleToken(SimpleTokenType::QuotationMark, 2),
                            SimpleToken(SimpleTokenType::Colon, 3),
                            SimpleToken(SimpleTokenType::QuotationMark, 4),
                            ComplexToken(ComplexTokenType::Identifier, "x1", 5),
                            SimpleToken(SimpleTokenType::QuotationMark, 6),
                            SimpleToken(SimpleTokenType::Comma, 7),
                            SimpleToken(SimpleTokenType::QuotationMark, 8),
                            ComplexToken(SpecialIdentifierType::SecondOperandOfBinaryOperation, "sO", 9),
                            SimpleToken(SimpleTokenType::QuotationMark, 10),
                            SimpleToken(SimpleTokenType::Colon, 11),
                            SimpleToken(SimpleTokenType::QuotationMark, 12),
                            ComplexToken(ComplexTokenType::Identifier, "x1", 13),
                            SimpleToken(SimpleTokenType::QuotationMark, 14),
                        };
                        SyntaxBlock::LoadTokenVector(tokens);
                        CHECK(SyntaxBlock::CFG::String::Inner::Operand::Binary::Check());
                    }
                }

                SUBCASE("Operand full Binary")
                {
                    // "fO":"x1","sO":"0"
                    auto tokens = std::vector<VariableToken>{
                        SimpleToken(SimpleTokenType::QuotationMark, 0),
                        ComplexToken(SpecialIdentifierType::FirstOperandOfBinaryOperation, "fO", 1),
                        SimpleToken(SimpleTokenType::QuotationMark, 2),
                        SimpleToken(SimpleTokenType::Colon, 3),
                        SimpleToken(SimpleTokenType::QuotationMark, 4),
                        ComplexToken(ComplexTokenType::Identifier, "x1", 5),
                        SimpleToken(SimpleTokenType::QuotationMark, 6),
                        SimpleToken(SimpleTokenType::Comma, 7),
                        SimpleToken(SimpleTokenType::QuotationMark, 8),
                        ComplexToken(SpecialIdentifierType::SecondOperandOfBinaryOperation, "sO", 9),
                        SimpleToken(SimpleTokenType::QuotationMark, 10),
                        SimpleToken(SimpleTokenType::Colon, 11),
                        SimpleToken(SimpleTokenType::QuotationMark, 12),
                        ComplexToken(ComplexTokenType::Integer, "0", 13),
                        SimpleToken(SimpleTokenType::QuotationMark, 14),
                    };
                    SyntaxBlock::LoadTokenVector(tokens);
                    CHECK(SyntaxBlock::CFG::String::Inner::Operand::Check());
                }
            }

            SUBCASE("Inner full (Identifier)")
            {
                // {"op":"!=","fO":"x1","sO":"0"}
                auto tokens = std::vector<VariableToken>{
                    SimpleToken(SimpleTokenType::OpeningCurlyBrace, 0),
                    SimpleToken(SimpleTokenType::QuotationMark, 1),
                    ComplexToken(SpecialIdentifierType::Operation, "op", 2),
                    SimpleToken(SimpleTokenType::QuotationMark, 3),
                    SimpleToken(SimpleTokenType::Colon, 4),
                    SimpleToken(SimpleTokenType::QuotationMark, 5),
                    SimpleToken(SimpleTokenType::ExclamationMark, 6),
                    SimpleToken(SimpleTokenType::EqualSign, 7),
                    SimpleToken(SimpleTokenType::QuotationMark, 8),
                    SimpleToken(SimpleTokenType::Comma, 9),
                    SimpleToken(SimpleTokenType::QuotationMark, 10),
                    ComplexToken(SpecialIdentifierType::FirstOperandOfBinaryOperation, "fO", 11),
                    SimpleToken(SimpleTokenType::QuotationMark, 12),
                    SimpleToken(SimpleTokenType::Colon, 13),
                    SimpleToken(SimpleTokenType::QuotationMark, 14),
                    ComplexToken(ComplexTokenType::Identifier, "x1", 15),
                    SimpleToken(SimpleTokenType::QuotationMark, 16),
                    SimpleToken(SimpleTokenType::Comma, 17),
                    SimpleToken(SimpleTokenType::QuotationMark, 18),
                    ComplexToken(SpecialIdentifierType::SecondOperandOfBinaryOperation, "sO", 19),
                    SimpleToken(SimpleTokenType::QuotationMark, 20),
                    SimpleToken(SimpleTokenType::Colon, 21),
                    SimpleToken(SimpleTokenType::QuotationMark, 22),
                    ComplexToken(ComplexTokenType::Integer, "0", 23),
                    SimpleToken(SimpleTokenType::QuotationMark, 24),
                    SimpleToken(SimpleTokenType::ClosingCurlyBrace, 25),
                };
                SyntaxBlock::LoadTokenVector(tokens);
                CHECK(SyntaxBlock::CFG::String::Inner::Check());
            }

            SUBCASE("Inner full (Edge)")
            {
                // {"op":"!=","fO":"A(1,2)","sO":"0"}
                auto tokens = std::vector<VariableToken>{
                    SimpleToken(SimpleTokenType::OpeningCurlyBrace, 0),
                    SimpleToken(SimpleTokenType::QuotationMark, 1),
                    ComplexToken(SpecialIdentifierType::Operation, "op", 2),
                    SimpleToken(SimpleTokenType::QuotationMark, 3),
                    SimpleToken(SimpleTokenType::Colon, 4),
                    SimpleToken(SimpleTokenType::QuotationMark, 5),
                    SimpleToken(SimpleTokenType::ExclamationMark, 6),
                    SimpleToken(SimpleTokenType::EqualSign, 7),
                    SimpleToken(SimpleTokenType::QuotationMark, 8),
                    SimpleToken(SimpleTokenType::Comma, 9),
                    SimpleToken(SimpleTokenType::QuotationMark, 10),
                    ComplexToken(SpecialIdentifierType::FirstOperandOfBinaryOperation, "fO", 11),
                    SimpleToken(SimpleTokenType::QuotationMark, 12),
                    SimpleToken(SimpleTokenType::Colon, 13),
                    SimpleToken(SimpleTokenType::QuotationMark, 14),
                    ComplexToken(ComplexTokenType::Identifier, "A", 15),
                    SimpleToken(SimpleTokenType::OpeningParenthesis, 16),
                    ComplexToken(ComplexTokenType::Integer, "1", 17),
                    SimpleToken(SimpleTokenType::Comma, 18),
                    ComplexToken(ComplexTokenType::Integer, "2", 19),
                    SimpleToken(SimpleTokenType::ClosingParenthesis, 20),
                    SimpleToken(SimpleTokenType::QuotationMark, 21),
                    SimpleToken(SimpleTokenType::Comma, 22),
                    SimpleToken(SimpleTokenType::QuotationMark, 23),
                    ComplexToken(SpecialIdentifierType::SecondOperandOfBinaryOperation, "sO", 24),
                    SimpleToken(SimpleTokenType::QuotationMark, 25),
                    SimpleToken(SimpleTokenType::Colon, 26),
                    SimpleToken(SimpleTokenType::QuotationMark, 27),
                    ComplexToken(ComplexTokenType::Integer, "0", 28),
                    SimpleToken(SimpleTokenType::QuotationMark, 29),
                    SimpleToken(SimpleTokenType::ClosingCurlyBrace, 30),
                };
                SyntaxBlock::LoadTokenVector(tokens);
                CHECK(SyntaxBlock::CFG::String::Inner::Check());
            }
        }

        SUBCASE("Logical")
        {
            SUBCASE("inner with edge")
            {
                // {"op":"!=","fO":"A(1,2)","sO":"0"}
                auto tokens = std::vector<VariableToken>{
                    SimpleToken(SimpleTokenType::OpeningCurlyBrace, 0),
                    SimpleToken(SimpleTokenType::QuotationMark, 1),
                    ComplexToken(SpecialIdentifierType::Operation, "op", 2),
                    SimpleToken(SimpleTokenType::QuotationMark, 3),
                    SimpleToken(SimpleTokenType::Colon, 4),
                    SimpleToken(SimpleTokenType::QuotationMark, 5),
                    SimpleToken(SimpleTokenType::ExclamationMark, 6),
                    SimpleToken(SimpleTokenType::EqualSign, 7),
                    SimpleToken(SimpleTokenType::QuotationMark, 8),
                    SimpleToken(SimpleTokenType::Comma, 9),
                    SimpleToken(SimpleTokenType::QuotationMark, 10),
                    ComplexToken(SpecialIdentifierType::FirstOperandOfBinaryOperation, "fO", 11),
                    SimpleToken(SimpleTokenType::QuotationMark, 12),
                    SimpleToken(SimpleTokenType::Colon, 13),
                    SimpleToken(SimpleTokenType::QuotationMark, 14),
                    ComplexToken(ComplexTokenType::Identifier, "A", 15),
                    SimpleToken(SimpleTokenType::OpeningParenthesis, 16),
                    ComplexToken(ComplexTokenType::Integer, "1", 17),
                    SimpleToken(SimpleTokenType::Comma, 18),
                    ComplexToken(ComplexTokenType::Integer, "2", 19),
                    SimpleToken(SimpleTokenType::ClosingParenthesis, 20),
                    SimpleToken(SimpleTokenType::QuotationMark, 21),
                    SimpleToken(SimpleTokenType::Comma, 22),
                    SimpleToken(SimpleTokenType::QuotationMark, 23),
                    ComplexToken(SpecialIdentifierType::SecondOperandOfBinaryOperation, "sO", 24),
                    SimpleToken(SimpleTokenType::QuotationMark, 25),
                    SimpleToken(SimpleTokenType::Colon, 26),
                    SimpleToken(SimpleTokenType::QuotationMark, 27),
                    ComplexToken(ComplexTokenType::Integer, "0", 28),
                    SimpleToken(SimpleTokenType::QuotationMark, 29),
                    SimpleToken(SimpleTokenType::ClosingCurlyBrace, 30),
                };
                SyntaxBlock::LoadTokenVector(tokens);
                CHECK(SyntaxBlock::CFG::String::Logical::Check());
            }
            
            SUBCASE("empty")
            {
                // ;
                auto tokens = std::vector<VariableToken>{
                    SimpleToken(SimpleTokenType::Semicolon, 0),
                };
                SyntaxBlock::LoadTokenVector(tokens);
                CHECK(SyntaxBlock::CFG::String::Logical::Check());
            }
        }

        SUBCASE("Arithmetic")
        {
            SUBCASE("inner with edge")
            {
                // {"op":"!=","fO":"A(1,2)","sO":"0"}
                auto tokens = std::vector<VariableToken>{
                    SimpleToken(SimpleTokenType::OpeningCurlyBrace, 0),
                    SimpleToken(SimpleTokenType::QuotationMark, 1),
                    ComplexToken(SpecialIdentifierType::Operation, "op", 2),
                    SimpleToken(SimpleTokenType::QuotationMark, 3),
                    SimpleToken(SimpleTokenType::Colon, 4),
                    SimpleToken(SimpleTokenType::QuotationMark, 5),
                    SimpleToken(SimpleTokenType::ExclamationMark, 6),
                    SimpleToken(SimpleTokenType::EqualSign, 7),
                    SimpleToken(SimpleTokenType::QuotationMark, 8),
                    SimpleToken(SimpleTokenType::Comma, 9),
                    SimpleToken(SimpleTokenType::QuotationMark, 10),
                    ComplexToken(SpecialIdentifierType::FirstOperandOfBinaryOperation, "fO", 11),
                    SimpleToken(SimpleTokenType::QuotationMark, 12),
                    SimpleToken(SimpleTokenType::Colon, 13),
                    SimpleToken(SimpleTokenType::QuotationMark, 14),
                    ComplexToken(ComplexTokenType::Identifier, "A", 15),
                    SimpleToken(SimpleTokenType::OpeningParenthesis, 16),
                    ComplexToken(ComplexTokenType::Integer, "1", 17),
                    SimpleToken(SimpleTokenType::Comma, 18),
                    ComplexToken(ComplexTokenType::Integer, "2", 19),
                    SimpleToken(SimpleTokenType::ClosingParenthesis, 20),
                    SimpleToken(SimpleTokenType::QuotationMark, 21),
                    SimpleToken(SimpleTokenType::Comma, 22),
                    SimpleToken(SimpleTokenType::QuotationMark, 23),
                    ComplexToken(SpecialIdentifierType::SecondOperandOfBinaryOperation, "sO", 24),
                    SimpleToken(SimpleTokenType::QuotationMark, 25),
                    SimpleToken(SimpleTokenType::Colon, 26),
                    SimpleToken(SimpleTokenType::QuotationMark, 27),
                    ComplexToken(ComplexTokenType::Integer, "0", 28),
                    SimpleToken(SimpleTokenType::QuotationMark, 29),
                    SimpleToken(SimpleTokenType::ClosingCurlyBrace, 30),
                };
                SyntaxBlock::LoadTokenVector(tokens);
                CHECK(SyntaxBlock::CFG::String::Logical::Check());
            }

            SUBCASE("no real solution")
            {
                // {"v":"no real solution"}
                auto tokens = std::vector<VariableToken>{
                    SimpleToken(SimpleTokenType::OpeningCurlyBrace, 0),
                    SimpleToken(SimpleTokenType::QuotationMark, 1),
                    ComplexToken(SpecialIdentifierType::V, "v", 2),
                    SimpleToken(SimpleTokenType::QuotationMark, 3),
                    SimpleToken(SimpleTokenType::Colon, 4),
                    SimpleToken(SimpleTokenType::QuotationMark, 5),
                    ComplexToken(SpecialIdentifierType::No, "no", 6),
                    ComplexToken(SpecialIdentifierType::Real, "real", 7),
                    ComplexToken(SpecialIdentifierType::Solution, "solution", 8),
                    SimpleToken(SimpleTokenType::QuotationMark, 9),
                    SimpleToken(SimpleTokenType::ClosingCurlyBrace, 10),
                };
                SyntaxBlock::LoadTokenVector(tokens);
                CHECK(SyntaxBlock::CFG::String::Arithmetic::NoRealSolution::Check());
            }
        }
    }

    SUBCASE("Full String Tests")
    {
        SUBCASE("Empty logical part")
        {
            // R(2)= ;A(1,2)
            auto tokens = std::vector<VariableToken>{
                ComplexToken(ComplexTokenType::Identifier, "R", 0),
                SimpleToken(SimpleTokenType::OpeningParenthesis, 1),
                ComplexToken(ComplexTokenType::Integer, "2", 2),
                SimpleToken(SimpleTokenType::ClosingParenthesis, 3),
                SimpleToken(SimpleTokenType::EqualSign, 4),
                SimpleToken(SimpleTokenType::Semicolon, 5),
                ComplexToken(ComplexTokenType::Identifier, "A", 6),
                SimpleToken(SimpleTokenType::OpeningParenthesis, 7),
                ComplexToken(ComplexTokenType::Integer, "1", 8),
                SimpleToken(SimpleTokenType::Comma, 9),
                ComplexToken(ComplexTokenType::Integer, "2", 10),
                SimpleToken(SimpleTokenType::ClosingParenthesis, 11),
            };
            SyntaxBlock::LoadTokenVector(tokens);
            CHECK(SyntaxBlock::CFG::String::Check());
        }

        SUBCASE("No real solution in arithmetic part")
        {
            // R(2)={"op":"!=","od":"A(1,2)"};{"v":"no real solution"}
            auto tokens = std::vector<VariableToken>{
                ComplexToken(ComplexTokenType::Identifier, "R", 0),
                SimpleToken(SimpleTokenType::OpeningParenthesis, 1),
                ComplexToken(ComplexTokenType::Integer, "2", 2),
                SimpleToken(SimpleTokenType::ClosingParenthesis, 3),
                SimpleToken(SimpleTokenType::EqualSign, 4),
                SimpleToken(SimpleTokenType::OpeningCurlyBrace, 5),
                SimpleToken(SimpleTokenType::QuotationMark, 6),
                ComplexToken(SpecialIdentifierType::Operation, "op", 7),
                SimpleToken(SimpleTokenType::QuotationMark, 8),
                SimpleToken(SimpleTokenType::Colon, 9),
                SimpleToken(SimpleTokenType::QuotationMark, 10),
                SimpleToken(SimpleTokenType::ExclamationMark, 11),
                SimpleToken(SimpleTokenType::EqualSign, 12),
                SimpleToken(SimpleTokenType::QuotationMark, 13),
                SimpleToken(SimpleTokenType::Comma, 14),
                SimpleToken(SimpleTokenType::QuotationMark, 15),
                ComplexToken(SpecialIdentifierType::OperandOfUnaryOperation, "od", 16),
                SimpleToken(SimpleTokenType::QuotationMark, 17),
                SimpleToken(SimpleTokenType::Colon, 18),
                SimpleToken(SimpleTokenType::QuotationMark, 19),
                ComplexToken(ComplexTokenType::Identifier, "A", 20),
                SimpleToken(SimpleTokenType::OpeningParenthesis, 21),
                ComplexToken(ComplexTokenType::Integer, "1", 22),
                SimpleToken(SimpleTokenType::Comma, 23),
                ComplexToken(ComplexTokenType::Integer, "2", 24),
                SimpleToken(SimpleTokenType::ClosingParenthesis, 25),
                SimpleToken(SimpleTokenType::QuotationMark, 26),
                SimpleToken(SimpleTokenType::ClosingCurlyBrace, 27),
                SimpleToken(SimpleTokenType::Semicolon, 28),
                SimpleToken(SimpleTokenType::OpeningCurlyBrace, 29),
                SimpleToken(SimpleTokenType::QuotationMark, 30),
                ComplexToken(SpecialIdentifierType::V, "v", 31),
                SimpleToken(SimpleTokenType::QuotationMark, 32),
                SimpleToken(SimpleTokenType::Colon, 33),
                SimpleToken(SimpleTokenType::QuotationMark, 34),
                ComplexToken(SpecialIdentifierType::No, "no", 35),
                ComplexToken(SpecialIdentifierType::Real, "real", 36),
                ComplexToken(SpecialIdentifierType::Solution, "solution", 37),
                SimpleToken(SimpleTokenType::QuotationMark, 38),
                SimpleToken(SimpleTokenType::ClosingCurlyBrace, 39),
            };
            SyntaxBlock::LoadTokenVector(tokens);
            CHECK(SyntaxBlock::CFG::String::Check());
        }

        SUBCASE("Nesting level 1")
        {
            SUBCASE("Case 1")
            {
                // R(2)={"op":"!=","fO":"A(1,2)","sO":"0"};A(1,2)
                auto tokens = std::vector<VariableToken>{
                    ComplexToken(ComplexTokenType::Identifier, "R", 0),
                    SimpleToken(SimpleTokenType::OpeningParenthesis, 1),
                    ComplexToken(ComplexTokenType::Integer, "2", 2),
                    SimpleToken(SimpleTokenType::ClosingParenthesis, 3),
                    SimpleToken(SimpleTokenType::EqualSign, 4),
                    SimpleToken(SimpleTokenType::OpeningCurlyBrace, 5),
                    SimpleToken(SimpleTokenType::QuotationMark, 6),
                    ComplexToken(SpecialIdentifierType::Operation, "op", 7),
                    SimpleToken(SimpleTokenType::QuotationMark, 8),
                    SimpleToken(SimpleTokenType::Colon, 9),
                    SimpleToken(SimpleTokenType::QuotationMark, 10),
                    SimpleToken(SimpleTokenType::ExclamationMark, 11),
                    SimpleToken(SimpleTokenType::EqualSign, 12),
                    SimpleToken(SimpleTokenType::QuotationMark, 13),
                    SimpleToken(SimpleTokenType::Comma, 14),
                    SimpleToken(SimpleTokenType::QuotationMark, 15),
                    ComplexToken(SpecialIdentifierType::FirstOperandOfBinaryOperation, "fO", 16),
                    SimpleToken(SimpleTokenType::QuotationMark, 17),
                    SimpleToken(SimpleTokenType::Colon, 18),
                    SimpleToken(SimpleTokenType::QuotationMark, 19),
                    ComplexToken(ComplexTokenType::Identifier, "A", 20),
                    SimpleToken(SimpleTokenType::OpeningParenthesis, 21),
                    ComplexToken(ComplexTokenType::Integer, "1", 22),
                    SimpleToken(SimpleTokenType::Comma, 23),
                    ComplexToken(ComplexTokenType::Integer, "2", 24),
                    SimpleToken(SimpleTokenType::ClosingParenthesis, 25),
                    SimpleToken(SimpleTokenType::QuotationMark, 26),
                    SimpleToken(SimpleTokenType::Comma, 27),
                    SimpleToken(SimpleTokenType::QuotationMark, 28),
                    ComplexToken(SpecialIdentifierType::SecondOperandOfBinaryOperation, "sO", 29),
                    SimpleToken(SimpleTokenType::QuotationMark, 30),
                    SimpleToken(SimpleTokenType::Colon, 31),
                    SimpleToken(SimpleTokenType::QuotationMark, 32),
                    ComplexToken(ComplexTokenType::Integer, "0", 33),
                    SimpleToken(SimpleTokenType::QuotationMark, 34),
                    SimpleToken(SimpleTokenType::ClosingCurlyBrace, 35),
                    SimpleToken(SimpleTokenType::Semicolon, 36),
                    ComplexToken(ComplexTokenType::Identifier, "A", 37),
                    SimpleToken(SimpleTokenType::OpeningParenthesis, 38),
                    ComplexToken(ComplexTokenType::Integer, "1", 39),
                    SimpleToken(SimpleTokenType::Comma, 40),
                    ComplexToken(ComplexTokenType::Integer, "2", 41),
                    SimpleToken(SimpleTokenType::ClosingParenthesis, 42),
                };
                SyntaxBlock::LoadTokenVector(tokens);
                CHECK(SyntaxBlock::CFG::String::Check());
            }

            SUBCASE("Case 2")
            {
                // R(2)={"op":"!=","fO":"A(1,2)","sO":"0"};{"op":"/","fO":"B(3,1)","sO":"2"}
                auto tokens = std::vector<VariableToken>{
                    ComplexToken(ComplexTokenType::Identifier, "R", 0),
                    SimpleToken(SimpleTokenType::OpeningParenthesis, 1),
                    ComplexToken(ComplexTokenType::Integer, "2", 2),
                    SimpleToken(SimpleTokenType::ClosingParenthesis, 3),
                    SimpleToken(SimpleTokenType::EqualSign, 4),
                    SimpleToken(SimpleTokenType::OpeningCurlyBrace, 5),
                    SimpleToken(SimpleTokenType::QuotationMark, 6),
                    ComplexToken(SpecialIdentifierType::Operation, "op", 7),
                    SimpleToken(SimpleTokenType::QuotationMark, 8),
                    SimpleToken(SimpleTokenType::Colon, 9),
                    SimpleToken(SimpleTokenType::QuotationMark, 10),
                    SimpleToken(SimpleTokenType::ExclamationMark, 11),
                    SimpleToken(SimpleTokenType::EqualSign, 12),
                    SimpleToken(SimpleTokenType::QuotationMark, 13),
                    SimpleToken(SimpleTokenType::Comma, 14),
                    SimpleToken(SimpleTokenType::QuotationMark, 15),
                    ComplexToken(SpecialIdentifierType::FirstOperandOfBinaryOperation, "fO", 16),
                    SimpleToken(SimpleTokenType::QuotationMark, 17),
                    SimpleToken(SimpleTokenType::Colon, 18),
                    SimpleToken(SimpleTokenType::QuotationMark, 19),
                    ComplexToken(ComplexTokenType::Identifier, "A", 20),
                    SimpleToken(SimpleTokenType::OpeningParenthesis, 21),
                    ComplexToken(ComplexTokenType::Integer, "1", 22),
                    SimpleToken(SimpleTokenType::Comma, 23),
                    ComplexToken(ComplexTokenType::Integer, "2", 24),
                    SimpleToken(SimpleTokenType::ClosingParenthesis, 25),
                    SimpleToken(SimpleTokenType::QuotationMark, 26),
                    SimpleToken(SimpleTokenType::Comma, 27),
                    SimpleToken(SimpleTokenType::QuotationMark, 28),
                    ComplexToken(SpecialIdentifierType::SecondOperandOfBinaryOperation, "sO", 29),
                    SimpleToken(SimpleTokenType::QuotationMark, 30),
                    SimpleToken(SimpleTokenType::Colon, 31),
                    SimpleToken(SimpleTokenType::QuotationMark, 32),
                    ComplexToken(ComplexTokenType::Integer, "0", 33),
                    SimpleToken(SimpleTokenType::QuotationMark, 34),
                    SimpleToken(SimpleTokenType::ClosingCurlyBrace, 35),
                    SimpleToken(SimpleTokenType::Semicolon, 36),
                    SimpleToken(SimpleTokenType::OpeningCurlyBrace, 37),
                    SimpleToken(SimpleTokenType::QuotationMark, 38),
                    ComplexToken(SpecialIdentifierType::Operation, "op", 39),
                    SimpleToken(SimpleTokenType::QuotationMark, 40),
                    SimpleToken(SimpleTokenType::Colon, 41),
                    SimpleToken(SimpleTokenType::QuotationMark, 42),
                    SimpleToken(SimpleTokenType::ArithmeticSign, 43),
                    SimpleToken(SimpleTokenType::QuotationMark, 44),
                    SimpleToken(SimpleTokenType::Comma, 45),
                    SimpleToken(SimpleTokenType::QuotationMark, 46),
                    ComplexToken(SpecialIdentifierType::FirstOperandOfBinaryOperation, "fO", 47),
                    SimpleToken(SimpleTokenType::QuotationMark, 48),
                    SimpleToken(SimpleTokenType::Colon, 49),
                    SimpleToken(SimpleTokenType::QuotationMark, 50),
                    ComplexToken(ComplexTokenType::Identifier, "B", 51),
                    SimpleToken(SimpleTokenType::OpeningParenthesis, 52),
                    ComplexToken(ComplexTokenType::Integer, "3", 53),
                    SimpleToken(SimpleTokenType::Comma, 54),
                    ComplexToken(ComplexTokenType::Integer, "1", 55),
                    SimpleToken(SimpleTokenType::ClosingParenthesis, 56),
                    SimpleToken(SimpleTokenType::QuotationMark, 57),
                    SimpleToken(SimpleTokenType::Comma, 58),
                    SimpleToken(SimpleTokenType::QuotationMark, 59),
                    ComplexToken(SpecialIdentifierType::SecondOperandOfBinaryOperation, "sO", 60),
                    SimpleToken(SimpleTokenType::QuotationMark, 61),
                    SimpleToken(SimpleTokenType::Colon, 62),
                    SimpleToken(SimpleTokenType::QuotationMark, 63),
                    ComplexToken(ComplexTokenType::Integer, "2", 64),
                    SimpleToken(SimpleTokenType::QuotationMark, 65),
                    SimpleToken(SimpleTokenType::ClosingCurlyBrace, 66),
                };
                SyntaxBlock::LoadTokenVector(tokens);
                CHECK(SyntaxBlock::CFG::String::Check());
            }
        }

        SUBCASE("Nesting level 2")
        {
            // R(2)={"op":"!=","fO":{"op":"+","fO":"A(1,3)","sO":"B(3,1)"},"sO":"0"};A(1,2)
            auto tokens = std::vector<VariableToken>{
                ComplexToken(ComplexTokenType::Identifier, "R", 0),
                SimpleToken(SimpleTokenType::OpeningParenthesis, 1),
                ComplexToken(ComplexTokenType::Integer, "2", 2),
                SimpleToken(SimpleTokenType::ClosingParenthesis, 3),
                SimpleToken(SimpleTokenType::EqualSign, 4),
                SimpleToken(SimpleTokenType::OpeningCurlyBrace, 5),
                SimpleToken(SimpleTokenType::QuotationMark, 6),
                ComplexToken(SpecialIdentifierType::Operation, "op", 7),
                SimpleToken(SimpleTokenType::QuotationMark, 8),
                SimpleToken(SimpleTokenType::Colon, 9),
                SimpleToken(SimpleTokenType::QuotationMark, 10),
                SimpleToken(SimpleTokenType::ExclamationMark, 11),
                SimpleToken(SimpleTokenType::EqualSign, 12),
                SimpleToken(SimpleTokenType::QuotationMark, 13),
                SimpleToken(SimpleTokenType::Comma, 14),
                SimpleToken(SimpleTokenType::QuotationMark, 15),
                ComplexToken(SpecialIdentifierType::FirstOperandOfBinaryOperation, "fO", 16),
                SimpleToken(SimpleTokenType::QuotationMark, 17),
                SimpleToken(SimpleTokenType::Colon, 18),
                SimpleToken(SimpleTokenType::OpeningCurlyBrace, 19),
                SimpleToken(SimpleTokenType::QuotationMark, 20),
                ComplexToken(SpecialIdentifierType::Operation, "op", 21),
                SimpleToken(SimpleTokenType::QuotationMark, 22),
                SimpleToken(SimpleTokenType::Colon, 23),
                SimpleToken(SimpleTokenType::QuotationMark, 24),
                SimpleToken(SimpleTokenType::ArithmeticSign, 25),
                SimpleToken(SimpleTokenType::QuotationMark, 26),
                SimpleToken(SimpleTokenType::Comma, 27),
                SimpleToken(SimpleTokenType::QuotationMark, 28),
                ComplexToken(SpecialIdentifierType::FirstOperandOfBinaryOperation, "fO", 29),
                SimpleToken(SimpleTokenType::QuotationMark, 30),
                SimpleToken(SimpleTokenType::Colon, 31),
                SimpleToken(SimpleTokenType::QuotationMark, 32),
                ComplexToken(ComplexTokenType::Identifier, "A", 33),
                SimpleToken(SimpleTokenType::OpeningParenthesis, 34),
                ComplexToken(ComplexTokenType::Integer, "1", 35),
                SimpleToken(SimpleTokenType::Comma, 36),
                ComplexToken(ComplexTokenType::Integer, "3", 37),
                SimpleToken(SimpleTokenType::ClosingParenthesis, 38),
                SimpleToken(SimpleTokenType::QuotationMark, 39),
                SimpleToken(SimpleTokenType::Comma, 40),
                SimpleToken(SimpleTokenType::QuotationMark, 41),
                ComplexToken(SpecialIdentifierType::SecondOperandOfBinaryOperation, "sO", 42),
                SimpleToken(SimpleTokenType::QuotationMark, 43),
                SimpleToken(SimpleTokenType::Colon, 44),
                SimpleToken(SimpleTokenType::QuotationMark, 45),
                ComplexToken(ComplexTokenType::Identifier, "B", 46),
                SimpleToken(SimpleTokenType::OpeningParenthesis, 47),
                ComplexToken(ComplexTokenType::Integer, "3", 48),
                SimpleToken(SimpleTokenType::Comma, 49),
                ComplexToken(ComplexTokenType::Integer, "1", 50),
                SimpleToken(SimpleTokenType::ClosingParenthesis, 51),
                SimpleToken(SimpleTokenType::QuotationMark, 52),
                SimpleToken(SimpleTokenType::ClosingCurlyBrace, 53),
                SimpleToken(SimpleTokenType::Comma, 54),
                SimpleToken(SimpleTokenType::QuotationMark, 55),            
                ComplexToken(SpecialIdentifierType::SecondOperandOfBinaryOperation, "sO", 56),
                SimpleToken(SimpleTokenType::QuotationMark, 57),
                SimpleToken(SimpleTokenType::Colon, 58),
                SimpleToken(SimpleTokenType::QuotationMark, 59),
                ComplexToken(ComplexTokenType::Integer, "0", 60),
                SimpleToken(SimpleTokenType::QuotationMark, 61),
                SimpleToken(SimpleTokenType::ClosingCurlyBrace, 62),
                SimpleToken(SimpleTokenType::Semicolon, 63),
                ComplexToken(ComplexTokenType::Identifier, "A", 64),
                SimpleToken(SimpleTokenType::OpeningParenthesis, 65),
                ComplexToken(ComplexTokenType::Integer, "1", 66),
                SimpleToken(SimpleTokenType::Comma, 67),
                ComplexToken(ComplexTokenType::Integer, "2", 68),
                SimpleToken(SimpleTokenType::ClosingParenthesis, 69),
            };
            SyntaxBlock::LoadTokenVector(tokens);
            CHECK(SyntaxBlock::CFG::String::Check());
        }

        SUBCASE("Nesting level 3")
        {
            // C(1,1)= ;{"op":"+","fO":{"op":"+","fO":{"op":"*","fO":"A(1,1)","sO":"B(1,1)"},"sO":{"op":"*","fO":"A(1,2)","sO":"B(2,1)"}},"sO":{"op":"*","fO":"A(1,3)","sO":"B(3,1)"}}
            CHECK(false);
        }

        SUBCASE("Nesting level 4")
        {
            CHECK(false);
        }
    }
}


TEST_SUITE_END();