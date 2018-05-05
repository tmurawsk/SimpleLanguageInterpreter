#ifndef SIMPLELANGUAGEINTERPRETER_SCANNER_H
#define SIMPLELANGUAGEINTERPRETER_SCANNER_H

#include "Position.h"
#include <fstream>

class Scanner {
public:
    explicit Scanner(std::istream &istreamArg);
    ~Scanner();

private:
    std::istream &istream;
    Position position;

public:
    char nextChar();
    char peekChar();
    void fallBack(int offset);
    Position getPosition();
};


#endif //SIMPLELANGUAGEINTERPRETER_SCANNER_H
