#ifndef SIMPLELANGUAGEINTERPRETER_POSITION_H
#define SIMPLELANGUAGEINTERPRETER_POSITION_H

#include <fstream>
#include <ostream>

struct Position {
    Position();

    int lineNr;
    int charNr;
    std::streampos linePos;
    std::streampos charPos;
};


#endif //SIMPLELANGUAGEINTERPRETER_POSITION_H
