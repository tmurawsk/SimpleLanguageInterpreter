#ifndef SIMPLELANGUAGEINTERPRETER_EXPRESSION_H
#define SIMPLELANGUAGEINTERPRETER_EXPRESSION_H

#include <iostream>
#include <ast/Variable.h>
#include <token/Token.h>

class MathExpression {
public:
//    MathExpression();
    virtual ~MathExpression() = default;
    virtual Variable evaluate() const = 0;
    virtual std::string toString() const = 0;
};


#endif //SIMPLELANGUAGEINTERPRETER_EXPRESSION_H
