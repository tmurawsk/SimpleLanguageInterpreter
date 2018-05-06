#include <iostream>

#include "lexer/Lexer.h"
#include "token/Token.h"

int main() {

    std::filebuf fb;
    if(!fb.open("../inputFiles/inputData.txt", std::ios::in)){
        std::cerr << "ERROR OPENING FILE!" << std::endl;
        exit(1);
    }

    std::istream is(&fb);
    Lexer *lexer = new Lexer(is);
    Token token;

    do {
        token = lexer->nextToken();
        std::cout << token.getValue() << std::endl;
    }while(token.getId() != TokenID::Eof);

    delete lexer;

    // TODO: blok powinien mieć listę zmiennych (zasięg zmiennych)

    return 0;
}