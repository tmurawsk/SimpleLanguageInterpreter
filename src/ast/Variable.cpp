#include <allegro/internal/aintern.h>
#include "Variable.h"

Variable::Variable(VariableType typeArg) : type(typeArg) {
    variables = std::vector<int>();
}

VariableType Variable::getType() const {
    return type;
}

const std::vector<int> &Variable::getVariables() const {
    return variables;
}

void Variable::addVariable(int var) {
    variables.push_back(var);
}

void Variable::eraseVariables() {
    variables.clear();
}

bool Variable::operator=(const Variable &var){
    if(type != var.getType())
        return false;

    (*this).eraseVariables();
    (*this).variables = var.getVariables();

    return true;
}

bool Variable::operator==(const Variable &var) const {

    if(type != var.getType())
        return false; //TODO throw exception
    else {
        const std::vector<int> &secVar = var.getVariables();

        for(int i = 0; i < variables.size(); i++)
            if(variables[i] != secVar[i])
                return false;
        return true;
    }
}

bool Variable::operator!=(const Variable &var) const {
    return !(*this == var);
}

bool Variable::operator<(const Variable &var) const {
    if(type != VariableType::Number || var.getType() != VariableType::Number)
        return false; //TODO throw exception


    return variables[0] < var.getVariables()[0];
}

bool Variable::operator>(const Variable &var) const {
    if(type != VariableType::Number || var.getType() != VariableType::Number)
        return false; //TODO throw exception


    return variables[0] > var.getVariables()[0];
}

bool Variable::operator<=(const Variable &var) const {
    return !(*this > var);
}

bool Variable::operator>=(const Variable &var) const {
    return !(*this < var);
}

Variable Variable::operator-() const{
    Variable newVar = *this;

    for(int i = 0; i < variables.size(); i++)
        newVar.addVariable(-variables[i]);

    return newVar;
}

Variable Variable::operator+(const Variable &var) const {
    if(type != var.getType())
        return Variable(VariableType::Invalid); //TODO throw exception

    Variable newVar = Variable(type);
    const std::vector<int> &secVar = var.getVariables();

    for(int i = 0; i < variables.size(); i++)
        newVar.addVariable(variables[i] + secVar[i]);

    return newVar;
}

Variable::operator bool() const {
    return !variables.empty();
}

bool Variable::operator&&(const Variable &var) const {
    return (*this).areValuesNotZeroes() && var.areValuesNotZeroes();
}

bool Variable::operator||(const Variable &var) const {
    return (*this).areValuesNotZeroes() || var.areValuesNotZeroes();
}

Variable Variable::operator-(const Variable &var) const {
    return (*this + (-var));
}

Variable Variable::operator*(const Variable &var) const {
    if(type == VariableType::Number){
        if(var.getType() == VariableType::Number)
            return numberNumberMultiply(*this, var);
        else
            return numberMatrixMultiply(*this, var);
    }
    else {
        if(var.getType() == VariableType::Number)
            return numberMatrixMultiply(var, *this);
        else {
            if(type == var.getType())
                return matrixMatrixMultiply(*this, var);
            else
                return Variable(VariableType::Invalid); //TODO throw exception
        }
    }
}

Variable Variable::numberNumberMultiply(const Variable &numberVar1, const Variable &numberVar2) const {
    Variable newVar = Variable(numberVar1.getType());
    newVar.addVariable(numberVar1.getVariables()[0] * numberVar2.getVariables()[0]);

    return newVar;
}

Variable Variable::numberMatrixMultiply(const Variable &numberVar, const Variable &matrixVar) const{
    int multNum = numberVar.getVariables()[0];
    const std::vector<int> &secVar = matrixVar.getVariables();
    Variable newVar = Variable(matrixVar.getType());

    for(int i = 0; i < secVar.size(); i++)
        newVar.addVariable(multNum * secVar[i]);

    return newVar;
}

Variable Variable::matrixMatrixMultiply(const Variable &matrixVar1, const Variable &matrixVar2) const {
    int dimension = matrixVar1.getType() == VariableType::Matrix2 ? 2 : 3;
    int nextElem;
    Variable newVar = Variable(matrixVar1.getType());
    const std::vector<int> &mat1 = matrixVar1.getVariables();
    const std::vector<int> &mat2 = matrixVar2.getVariables();

    for(int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++){
            nextElem = 0;
            for(int k = 0; k < dimension; k++)
                nextElem += mat1[i * dimension + k] * mat2[k * dimension + j];

            newVar.addVariable(nextElem);
        }
    }

    return newVar;
}

Variable Variable::operator/(const Variable &var) const {
    if(type == VariableType::Number && var.getType() == VariableType::Number){
        Variable newVar = Variable(type);
        newVar.addVariable(variables[0] / var.getVariables()[0]);
        return newVar;
    }
    else
        return Variable(VariableType::Invalid); //TODO throw exception
}

bool Variable::areValuesNotZeroes() const {
    if(variables.empty())
        return false;

    for(int i = 0; i < variables.size(); i++)
        if(variables[i] != 0)
            return true;

    return false;
}

Variable Variable::evaluate() const {
    return *this;
}

std::string Variable::toString() const {
    return std::__cxx11::string();
}

void Variable::setType(VariableType type) {
    Variable::type = type;
}
