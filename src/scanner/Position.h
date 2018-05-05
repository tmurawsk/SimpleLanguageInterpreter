#ifndef SIMPLELANGUAGEINTERPRETER_POSITION_H
#define SIMPLELANGUAGEINTERPRETER_POSITION_H

#include <fstream>
#include <ostream>

struct Position {
    Position(int lNo = 1, int cNo = 1) : lineNr(lNo), charNr(cNo) {};

    int lineNr;
    int charNr;
};


#endif //SIMPLELANGUAGEINTERPRETER_POSITION_H
