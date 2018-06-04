#ifndef SIMPLELANGUAGEINTERPRETER_MATHEXPR_H
#define SIMPLELANGUAGEINTERPRETER_MATHEXPR_H

#include "ast/Variable.h"
#include "MathExpression.h"

class MathExpr : public MathExpression {
public:
    explicit MathExpr(MathExpression *leftExprArg, MathExpression *rightExprArg, Token opArg);

private:
    MathExpression *leftExpr;
    MathExpression *rightExpr;
    Token op;

public:
    Variable evaluate() const override;

    std::string toString() const override;
};


#endif //SIMPLELANGUAGEINTERPRETER_MATHEXPR_H
