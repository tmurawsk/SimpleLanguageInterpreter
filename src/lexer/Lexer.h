#ifndef SIMPLELANGUAGEINTERPRETER_LEXER_H
#define SIMPLELANGUAGEINTERPRETER_LEXER_H
#define NAMEMAXLENGTH 100

#include "scanner/Scanner.h"
#include "token/Token.h"

class Lexer {
public:
    explicit Lexer(std::string filename);
    ~Lexer();

private:
    Scanner scanner;
    int errorCount;
    std::string token;

public:
    TokenID nextToken();
    void lexError(std::string msg);
};


#endif //SIMPLELANGUAGEINTERPRETER_LEXER_H
