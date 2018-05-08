#ifndef SIMPLELANGUAGEINTERPRETER_VARIABLE_H
#define SIMPLELANGUAGEINTERPRETER_VARIABLE_H

#include <vector>
#include <ast/expression/MathExpression.h>

enum class VariableType {
    Number,
    Matrix2,
    Matrix3,
    Invalid
};

class Variable : public MathExpression{
public:
    explicit Variable(VariableType typeArg = VariableType::Invalid);

    VariableType getType() const;

    void setType(VariableType type);

    const std::vector<int> &getVariables() const;
    void addVariable(int var);
    void eraseVariables();

    Variable evaluate() const override;

    std::string toString() const override;

    bool operator=(const Variable &var);

    bool operator==(const Variable &var) const;
    bool operator!=(const Variable &var) const;

    bool operator<(const Variable &var) const;
    bool operator>(const Variable &var) const;
    bool operator<=(const Variable &var) const;
    bool operator>=(const Variable &var) const;

    explicit operator bool() const;

    bool operator&&(const Variable &var) const;
    bool operator||(const Variable &var) const;

    Variable operator-() const;

    Variable operator+(const Variable &var) const;
    Variable operator-(const Variable &var) const;
    Variable operator*(const Variable &var) const;
    Variable operator/(const Variable &var) const;


private:
    VariableType type;
    std::vector<int> variables;

    Variable numberNumberMultiply(const Variable &numberVar1, const Variable &numberVar2) const;
    Variable numberMatrixMultiply(const Variable &numberVar, const Variable &matrixVar) const;
    Variable matrixMatrixMultiply(const Variable &matrixVar1, const Variable &matrixVar2) const;
    bool areValuesNotZeroes() const;
};

#endif //SIMPLELANGUAGEINTERPRETER_VARIABLE_H
