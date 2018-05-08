#include "AssignStatement.h"

AssignStatement::AssignStatement(Variable &var, MathExpression expr)
    : variable(var), expression(expr) {
}

void AssignStatement::evaluate() {
    Variable result = expression.evaluate();

    if(variable.getType() != result.getType())
        return; //TODO throw exception

    variable = result;
}
