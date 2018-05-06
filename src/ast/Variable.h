#ifndef SIMPLELANGUAGEINTERPRETER_VARIABLE_H
#define SIMPLELANGUAGEINTERPRETER_VARIABLE_H

#include <vector>

enum class VariableType {
    Number,
    Matrix2,
    Matrix3,
    Invalid
};

class Variable {
public:
    explicit Variable(VariableType typeArg);

    VariableType getType() const;
    const std::vector<int> &getVariables() const;
    void addVariable(int var);

    bool operator==(const Variable &var) const;
    bool operator!=(const Variable &var) const;

    bool operator<(const Variable &var) const;
    bool operator>(const Variable &var) const;
    bool operator<=(const Variable &var) const;
    bool operator>=(const Variable &var) const;

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
};

#endif //SIMPLELANGUAGEINTERPRETER_VARIABLE_H
