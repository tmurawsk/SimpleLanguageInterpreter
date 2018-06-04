#include "LogicExpr.h"

LogicExpr::LogicExpr(LogicExpression *leftExpr, LogicExpression *rightExpr)
        : leftExpr(leftExpr), rightExpr(rightExpr) {}

bool LogicExpr::evaluate() const {
    return leftExpr->evaluate() || rightExpr->evaluate();
}

std::string LogicExpr::toString() const {
    return std::__cxx11::string(); //TODO
}
