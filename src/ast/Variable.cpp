#include "Variable.h"

Variable::Variable(VariableType typeArg) : type(typeArg) {
    values = std::vector<int>();
}

VariableType Variable::getType() const {
    return type;
}

const std::vector<int> &Variable::getValues() const {
    return values;
}

void Variable::addValue(int var) {
    values.push_back(var);
}

void Variable::eraseValues() {
    values.clear();
}

bool Variable::operator=(const Variable &var){
    if(type != var.getType())
        return false;

    (*this).eraseValues();
    (*this).values = var.getValues();

    return true;
}

bool Variable::operator==(const Variable &var) const {

    if(type != var.getType())
        return false; //TODO throw exception
    else {
        const std::vector<int> &secVar = var.getValues();

        for(int i = 0; i < values.size(); i++)
            if(values[i] != secVar[i])
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


    return values[0] < var.getValues()[0];
}

bool Variable::operator>(const Variable &var) const {
    if(type != VariableType::Number || var.getType() != VariableType::Number)
        return false; //TODO throw exception


    return values[0] > var.getValues()[0];
}

bool Variable::operator<=(const Variable &var) const {
    return !(*this > var);
}

bool Variable::operator>=(const Variable &var) const {
    return !(*this < var);
}

Variable Variable::operator-() const{
    Variable newVar = *this;

    for(int i = 0; i < values.size(); i++)
        newVar.addValue(-values[i]);

    return newVar;
}

Variable Variable::operator+(const Variable &var) const {
    if(type != var.getType())
        return Variable(VariableType::Invalid); //TODO throw exception

    Variable newVar = Variable(type);
    const std::vector<int> &secVar = var.getValues();

    for(int i = 0; i < values.size(); i++)
        newVar.addValue(values[i] + secVar[i]);

    return newVar;
}

Variable::operator bool() const {
    return !values.empty();
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
    newVar.addValue(numberVar1.getValues()[0] * numberVar2.getValues()[0]);

    return newVar;
}

Variable Variable::numberMatrixMultiply(const Variable &numberVar, const Variable &matrixVar) const{
    int multNum = numberVar.getValues()[0];
    const std::vector<int> &secVar = matrixVar.getValues();
    Variable newVar = Variable(matrixVar.getType());

    for(int i = 0; i < secVar.size(); i++)
        newVar.addValue(multNum * secVar[i]);

    return newVar;
}

Variable Variable::matrixMatrixMultiply(const Variable &matrixVar1, const Variable &matrixVar2) const {
    int dimension = matrixVar1.getType() == VariableType::Matrix2 ? 2 : 3;
    int nextElem;
    Variable newVar = Variable(matrixVar1.getType());
    const std::vector<int> &mat1 = matrixVar1.getValues();
    const std::vector<int> &mat2 = matrixVar2.getValues();

    for(int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++){
            nextElem = 0;
            for(int k = 0; k < dimension; k++)
                nextElem += mat1[i * dimension + k] * mat2[k * dimension + j];

            newVar.addValue(nextElem);
        }
    }

    return newVar;
}

Variable Variable::operator/(const Variable &var) const {
    if(type == VariableType::Number && var.getType() == VariableType::Number){
        Variable newVar = Variable(type);
        newVar.addValue(values[0] / var.getValues()[0]);
        return newVar;
    }
    else
        return Variable(VariableType::Invalid); //TODO throw exception
}

bool Variable::areValuesNotZeroes() const {
    if(values.empty())
        return false;

    for(int i = 0; i < values.size(); i++)
        if(values[i] != 0)
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
