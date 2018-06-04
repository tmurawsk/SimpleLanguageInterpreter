#ifndef SIMPLELANGUAGEINTERPRETER_LOGICEXPR_H
#define SIMPLELANGUAGEINTERPRETER_LOGICEXPR_H

#include "LogicExpression.h"

class LogicExpr : public LogicExpression {
public:
    LogicExpr(LogicExpression *leftExpr, LogicExpression *rightExpr);

private:
    LogicExpression *leftExpr;
    LogicExpression *rightExpr;

public:
    bool evaluate() const override;

    std::string toString() const override;
};


#endif //SIMPLELANGUAGEINTERPRETER_LOGICEXPR_H
