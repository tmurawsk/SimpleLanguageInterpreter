#include "AndExpr.h"

AndExpr::AndExpr(LogicExpression *leftExpr, LogicExpression *rightExpr)
        : leftExpr(leftExpr), rightExpr(rightExpr) {}

bool AndExpr::evaluate() const {
    return leftExpr->evaluate() && rightExpr->evaluate();
}

std::string AndExpr::toString() const {
    return std::__cxx11::string(); //TODO
}
