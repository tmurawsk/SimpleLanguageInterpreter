#ifndef SIMPLELANGUAGEINTERPRETER_SCANNER_H
#define SIMPLELANGUAGEINTERPRETER_SCANNER_H

#include "Position.h"
#include <fstream>

class Scanner {
public:
    explicit Scanner(std::string filename);
    ~Scanner();

private:
    std::string filename;
    std::fstream file;
    Position position;

public:
    char nextChar();
    char peekChar();
    void fallBack(int offset);
    Position getPosition();
};


#endif //SIMPLELANGUAGEINTERPRETER_SCANNER_H
