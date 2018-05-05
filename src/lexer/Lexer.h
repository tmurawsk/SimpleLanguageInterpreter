#ifndef SIMPLELANGUAGEINTERPRETER_LEXER_H
#define SIMPLELANGUAGEINTERPRETER_LEXER_H
#define NAMEMAXLENGTH 100

#include "scanner/Scanner.h"
#include "token/Token.h"

class Lexer {
public:
    explicit Lexer(std::istream &istream);
    ~Lexer();

private:
    Scanner scanner;
    std::string token;

public:
    Token nextToken();
    void lexError(std::string msg);

private:
    Token nameTokenHandler(char c);
    Token numberTokenHandler(char c);
    Token otherTokenHandler(char c);
    Token ifNextIsEqual(char expectedChar, TokenID tokenIfTrue, TokenID tokenIfFalse);
};


#endif //SIMPLELANGUAGEINTERPRETER_LEXER_H
