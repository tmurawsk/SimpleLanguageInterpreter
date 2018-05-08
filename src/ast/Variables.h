#ifndef SIMPLELANGUAGEINTERPRETER_VARIABLES_H
#define SIMPLELANGUAGEINTERPRETER_VARIABLES_H

#include <iostream>
#include <map>
#include "Variable.h"

static class Variables {
public:
    Variables() = default;

    static Variable getVarByName(const std::string &name){
        auto it = varMap.find(name);

        return it == varMap.end() ? Variable(VariableType::Invalid) : it->second;
    }

private:
    static std::map<std::string, Variable> varMap;
};


#endif //SIMPLELANGUAGEINTERPRETER_VARIABLES_H
