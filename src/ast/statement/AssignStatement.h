#ifndef SIMPLELANGUAGEINTERPRETER_ASSIGNSTATEMENT_H
#define SIMPLELANGUAGEINTERPRETER_ASSIGNSTATEMENT_H

#include <string>
#include <ast/Variable.h>
#include "Statement.h"

class AssignStatement : public Statement{
public:
    AssignStatement(Variable &var, MathExpression* expr);

    void evaluate() override;

private:
    Variable &variable;
    MathExpression* expression;
};


#endif //SIMPLELANGUAGEINTERPRETER_ASSIGNSTATEMENT_H
