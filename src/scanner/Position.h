#ifndef SIMPLELANGUAGEINTERPRETER_POSITION_H
#define SIMPLELANGUAGEINTERPRETER_POSITION_H

#include <fstream>
#include <ostream>

struct Position {
    Position() : lineNr(1), charNr(1) {};

    int lineNr;
    int charNr;
};


#endif //SIMPLELANGUAGEINTERPRETER_POSITION_H
