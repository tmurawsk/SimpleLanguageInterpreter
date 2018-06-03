#include "MathExpr.h"

MathExpr::MathExpr(MathExpression* leftExprArg, MathExpression* rightExprArg, Token opArg)
    : leftExpr(leftExprArg), rightExpr(rightExprArg), op(opArg){
}

Variable MathExpr::evaluate() const {
    switch(op.getId()){
        case TokenID::Multiply:
            return leftExpr->evaluate() * rightExpr->evaluate();
        case TokenID::Plus:
            return leftExpr->evaluate() + rightExpr->evaluate();
        case TokenID::Minus:
            return leftExpr->evaluate() - rightExpr->evaluate();
        case TokenID::Divide:
            return leftExpr->evaluate() / rightExpr->evaluate();
        default:
            return Variable(VariableType::Invalid); //TODO throw exception
    }
}

std::string MathExpr::toString() const {
    return std::__cxx11::string();
}
