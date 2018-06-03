#include <ast/expression/MathExpr.h>
#include "Parser.h"

Parser::Parser(Lexer lexer) : lexer(lexer) {
}

MathExpression* Parser::mathSumExprParse() {
    MathExpression* multExpr = mathMultExprParse();
    Token token = lexer.nextToken();

    while (token.getId() == TokenID::Plus || token.getId() == TokenID::Minus){
        MathExpression* nextMultExpr = mathMultExprParse();
        multExpr = new MathExpr(multExpr, nextMultExpr, token);
        token = lexer.nextToken();
    }

    return multExpr;
}

MathExpression* Parser::mathMultExprParse() {
    MathExpression* baseExpr = mathBaseExprParse();
    Token token = lexer.nextToken();

    while (token.getId() == TokenID::Multiply || token.getId() == TokenID::Divide){
        MathExpression* nextBaseExpr = mathBaseExprParse();
        baseExpr = new MathExpr(baseExpr, nextBaseExpr, token);
        token = lexer.nextToken();
    }

    return baseExpr;
}

MathExpression* Parser::mathBaseExprParse() {
    Token token = lexer.nextToken();
    //TODO minus

    if(token.getId() == TokenID::RoundBracketOpen)
        return mathBracketExprParse();
    if(token.getId() == TokenID::SquareBracketOpen)
        return matrixLiteralParse();
    if(token.getId() == TokenID::Number){
        Variable* newVar = new Variable(VariableType::Number);
        newVar->addVariable(std::stoi(token.getValue()));
        return newVar;
    }
    //TODO functionCall
}

MathExpression* Parser::mathBracketExprParse() {
    MathExpression* expr = mathSumExprParse();
    checkNextTokenThrow(TokenID::RoundBracketClose);
    return expr;
}

Variable* Parser::matrixLiteralParse() {
//    checkNextTokenThrow(TokenID::SquareBracketOpen);
    int dim = 0;
    Token token1, token2;
    Variable* newVar = new Variable();

    do{
        token1 = checkNextTokenThrow(TokenID::Number);
        token2 = lexer.nextToken();
        dim++;

        newVar->addVariable(std::stoi(token1.getValue()));

    }while(token2.getId() == TokenID::Comma);

    if(token2.getId() != TokenID::Semicolon){
        std::cout << "ERROR! INVALID TOKEN!" << std::endl;
        exit(1); //TODO throw exception
    }

    if(dim == 2){
        newVar->setType(VariableType::Matrix2);
        token1 = checkNextTokenThrow(TokenID::Number);
        checkNextTokenThrow(TokenID::Comma);
        token2 = checkNextTokenThrow(TokenID::Number);
        newVar->addVariable(std::stoi(token1.getValue()));
        newVar->addVariable(std::stoi(token2.getValue()));
    }
    else if(dim == 3){
        newVar->setType(VariableType::Matrix3);

        for(int i = 0; i < 2; i++){
            token1 = checkNextTokenThrow(TokenID::Number);
            checkNextTokenThrow(TokenID::Comma);
            newVar->addVariable(std::stoi(token1.getValue()));
        }
        checkNextTokenThrow(TokenID::Semicolon);
        for(int i = 0; i < 2; i++){
            token1 = checkNextTokenThrow(TokenID::Number);
            checkNextTokenThrow(TokenID::Comma);
            newVar->addVariable(std::stoi(token1.getValue()));
        }
        token1 = checkNextTokenThrow(TokenID::Number);
        newVar->addVariable(std::stoi(token1.getValue()));
    }
    else{
        std::cout << "ERROR! INVALID TOKEN!" << std::endl;
        exit(1); //TODO throw exception
    }
    checkNextTokenThrow(TokenID::SquareBracketClose);

    return newVar;
}

Token Parser::checkNextTokenThrow(TokenID tokenID) {
    Token token = lexer.nextToken();

    if(token.getId() != tokenID){
        std::cout << "ERROR! INVALID TOKEN!" << std::endl;
        exit(1); //TODO throw exception
    }

    return token;
}
