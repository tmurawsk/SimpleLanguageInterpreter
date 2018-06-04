#include <ast/Variable.h>
#include "RelationExpr.h"

RelationExpr::RelationExpr(MathExpression *leftExpr, MathExpression *rightExpr, Token op)
        : leftExpr(leftExpr), rightExpr(rightExpr), op(op) {}

bool RelationExpr::evaluate() const {
    switch (op.getId()){
        case TokenID::Equal:
            return leftExpr->evaluate() == rightExpr->evaluate();
        case TokenID::Unequal:
            return leftExpr->evaluate() != rightExpr->evaluate();
        case TokenID::Less:
            return leftExpr->evaluate() < rightExpr->evaluate();
        case TokenID::Greater:
            return leftExpr->evaluate() > rightExpr->evaluate();
        case TokenID::LessOrEqual:
            return leftExpr->evaluate() <= rightExpr->evaluate();
        case TokenID::GreaterOrEqual:
            return leftExpr->evaluate() >= rightExpr->evaluate();
        default:
            return false; //TODO throw exception
    }
}

std::string RelationExpr::toString() const {
    return std::__cxx11::string(); //TODO
}
