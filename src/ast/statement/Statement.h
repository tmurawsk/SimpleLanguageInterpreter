#ifndef SIMPLELANGUAGEINTERPRETER_STATEMENT_H
#define SIMPLELANGUAGEINTERPRETER_STATEMENT_H


class Statement {
public:
    virtual ~Statement() = default;

    virtual void evaluate() = 0;
};


#endif //SIMPLELANGUAGEINTERPRETER_STATEMENT_H
