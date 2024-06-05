#include "TransliterationBlock.hpp"
#include "LexicalBlock.hpp"
#include "SyntaxBlock.hpp"

class MainBlock
{
private:
    LexicalBlock lexicalBlock;
    SyntaxBlock syntaxBlock;

public:
    MainBlock();
    MainBlock(SyntaxBlockWorkingMode workingMode = SyntaxBlockWorkingMode::UntilFirstError);
    ~MainBlock();
    bool CheckString(const std::string& str, SyntaxBlockWorkingMode workingMode);
    bool CheckString(int stringIndex, const std::string& str, SyntaxBlockWorkingMode workingMode);
};