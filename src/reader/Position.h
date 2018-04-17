#ifndef SIMPLELANGUAGEINTERPRETER_POSITION_H
#define SIMPLELANGUAGEINTERPRETER_POSITION_H

#include <fstream>
#include <ostream>

class Position {
public:
    Position();

private:
    int lineNr;
    int charNr;
    std::streampos linePos;
    std::streampos charPos;
};


#endif //SIMPLELANGUAGEINTERPRETER_POSITION_H
