#ifndef SIMPLELANGUAGEINTERPRETER_RELATIONEXPR_H
#define SIMPLELANGUAGEINTERPRETER_RELATIONEXPR_H

#include "MathExpression.h"
#include "LogicExpression.h"

class RelationExpr : public LogicExpression {
public:
    RelationExpr(MathExpression *leftExpr, MathExpression *rightExpr, Token op);

private:
    MathExpression *leftExpr;
    MathExpression *rightExpr;
    Token op;

public:
    bool evaluate() const override;

    std::string toString() const override;
};


#endif //SIMPLELANGUAGEINTERPRETER_RELATIONEXPR_H
