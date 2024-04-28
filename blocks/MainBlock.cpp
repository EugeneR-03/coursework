#include "MainBlock.hpp"

MainBlock::MainBlock()
{
    this->lexicalBlock = LexicalBlock();
    this->syntaxBlock = SyntaxBlock();
}

MainBlock::MainBlock(SyntaxBlockWorkingMode workingMode)
{
    this->lexicalBlock = LexicalBlock();
    this->syntaxBlock = SyntaxBlock(workingMode);
}

MainBlock::~MainBlock() {}

bool MainBlock::CheckString(const std::string& str, SyntaxBlockWorkingMode workingMode)
{
    std::vector<std::variant<SimpleToken, ComplexToken>> combinedTokens = this->lexicalBlock.TransliterateString(str);
    this->syntaxBlock.LoadTokenVector(combinedTokens);
    
    return this->syntaxBlock.CheckTokenVector(combinedTokens, workingMode);
}

bool MainBlock::CheckString(int stringIndex, const std::string& str, SyntaxBlockWorkingMode workingMode)
{
    this->syntaxBlock.SetStringIndex(stringIndex);
    return this->CheckString(str, workingMode);
}