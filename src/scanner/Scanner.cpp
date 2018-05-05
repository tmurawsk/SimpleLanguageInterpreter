#include <iostream>
#include "Scanner.h"

Scanner::Scanner(std::istream &istreamArg) : istream(istreamArg) {
    position = Position();
}

Scanner::~Scanner() = default;

char Scanner::nextChar() {
    char c = (char) istream.get();

    if(c == '\n') {
        position.charNr = 1;
        position.lineNr++;
    }else
        position.charNr++;

    return c;
}

char Scanner::peekChar() {
    return (char) istream.peek();
}

void Scanner::fallBack(int offset) {
    istream.seekg(-offset, std::ios_base::cur);

    if(istream.get() == '\n')
        position.lineNr--;

    istream.seekg(-1, std::ios_base::cur);
}

Position Scanner::getPosition() {
    return position;
}


