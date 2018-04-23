#include <iostream>

#include "lexer/Lexer.h"
#include "token/Token.h"

int main() {

    Lexer *lexer = new Lexer("../inputFiles/inputData.txt");
    TokenID tokenID;

    do {
        tokenID = lexer->nextToken();
        std::cout << Token::getTokenByID(tokenID) << std::endl;
    }while(tokenID != TokenID::Eof);

    delete lexer;

    return 0;
}