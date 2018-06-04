#ifndef SIMPLELANGUAGEINTERPRETER_ANDEXPR_H
#define SIMPLELANGUAGEINTERPRETER_ANDEXPR_H

#include "LogicExpr.h"

class AndExpr : public LogicExpression{
public:
    AndExpr(LogicExpr *leftExpr, LogicExpr *rightExpr);

private:
    LogicExpr *leftExpr;
    LogicExpr *rightExpr;

public:
    bool evaluate() const override;

    std::string toString() const override;
};


#endif //SIMPLELANGUAGEINTERPRETER_ANDEXPR_H
