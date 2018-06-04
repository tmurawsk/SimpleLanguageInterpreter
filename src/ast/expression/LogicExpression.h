#ifndef SIMPLELANGUAGEINTERPRETER_LOGICEXPRESSION_H
#define SIMPLELANGUAGEINTERPRETER_LOGICEXPRESSION_H

#include <string>

class LogicExpression {
public:
    virtual ~LogicExpression() = default;
    virtual bool evaluate() const = 0;
    virtual std::string toString() const = 0;
};


#endif //SIMPLELANGUAGEINTERPRETER_LOGICEXPRESSION_H
