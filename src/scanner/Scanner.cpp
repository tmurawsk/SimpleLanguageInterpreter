#include <iostream>
#include "Scanner.h"

Scanner::Scanner(std::string filename) {
    this->filename = filename;
    position = Position();
    file.open(this->filename, std::ios::in);

    if(!file.good()){
        std::cerr << "FATAL ERROR! CANNOT OPEN SOURCE FILE!" << std::endl;
        exit(1);
    }
}

Scanner::~Scanner() {
    file.close();
}

char Scanner::nextChar() {
    char c = (char) file.get();

    if(c == '\n') {
        position.charNr = 1;
        position.lineNr++;
    }else
        position.charNr++;

    return c;
}

void Scanner::fallBack(int offset) {
    file.seekg(-offset, std::ios_base::cur);
}

Position Scanner::getPosition() {
    return position;
}


