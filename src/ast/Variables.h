#ifndef SIMPLELANGUAGEINTERPRETER_VARIABLES_H
#define SIMPLELANGUAGEINTERPRETER_VARIABLES_H

#include <map>
#include "Variable.h"

class Variables {
public:
    Variables() = default;

    static Variable& getVarByName(const std::string &name) {
        auto it = varMap.find(name);

        //TODO do sth with not exisitng variables
//        Variable var = Variable(VariableType::Invalid);
//
//        if(it == varMap.end())
//            return var;
//        else
            return it->second;
    }

    static void addVariable(std::string &name, Variable &variable) {
        auto it = varMap.find(name);

        if(it != varMap.end())
            return; //TODO throw exception

        varMap[name] = variable;
    }

private:
    static std::map<std::string, Variable> varMap;
};


#endif //SIMPLELANGUAGEINTERPRETER_VARIABLES_H
