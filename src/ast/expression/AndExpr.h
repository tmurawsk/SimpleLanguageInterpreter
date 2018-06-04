#ifndef SIMPLELANGUAGEINTERPRETER_ANDEXPR_H
#define SIMPLELANGUAGEINTERPRETER_ANDEXPR_H

#include "LogicExpression.h"

class AndExpr : public LogicExpression{
public:
    AndExpr(LogicExpression *leftExpr, LogicExpression *rightExpr);

private:
    LogicExpression *leftExpr;
    LogicExpression *rightExpr;

public:
    bool evaluate() const override;

    std::string toString() const override;
};


#endif //SIMPLELANGUAGEINTERPRETER_ANDEXPR_H
