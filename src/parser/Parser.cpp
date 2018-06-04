#include <set>
#include <ast/Variables.h>
#include <ast/expression/MathExpr.h>
#include <ast/expression/AndExpr.h>
#include <ast/expression/LogicExpr.h>
#include <ast/expression/RelationExpr.h>
#include "Parser.h"

Parser::Parser(Lexer *lexer) : lexer(lexer) {
    currToken = Token(TokenID::Invalid);
}

MathExpression *Parser::mathSumExprParse() {
    MathExpression *multExpr = mathMultExprParse();
    Token token = lexer->nextToken();

    while (token.getId() == TokenID::Plus || token.getId() == TokenID::Minus) {
        MathExpression *nextMultExpr = mathMultExprParse();
        multExpr = new MathExpr(multExpr, nextMultExpr, token);
        token = lexer->nextToken();
    }

    return multExpr;
}

MathExpression *Parser::mathMultExprParse() {
    MathExpression *baseExpr = mathBaseExprParse();
    Token token = lexer->nextToken();

    while (token.getId() == TokenID::Multiply || token.getId() == TokenID::Divide) {
        MathExpression *nextBaseExpr = mathBaseExprParse();
        baseExpr = new MathExpr(baseExpr, nextBaseExpr, token);
        token = lexer->nextToken();
    }

    return baseExpr;
}

MathExpression *Parser::mathBaseExprParse() {
    Token token = lexer->nextToken();
    //TODO minus

    if (token.getId() == TokenID::RoundBracketOpen)
        return mathBracketExprParse();
    if (token.getId() == TokenID::SquareBracketOpen)
        return matrixLiteralParse();
    if (token.getId() == TokenID::Number) {
        Variable *newVar = new Variable(VariableType::Number);
        newVar->addValue(std::stoi(token.getValue()));
        return newVar;
    }
    if (token.getId() == TokenID::Name) {
        Variable var = Variables::getVarByName(token.getValue());
        if (var.getType() == VariableType::Invalid)
            return nullptr; //TODO throw exception

        return &var;
    }
    //TODO functionCall
}

MathExpression *Parser::mathBracketExprParse() {
    MathExpression *expr = mathSumExprParse();
    checkNextTokenThrow(TokenID::RoundBracketClose);
    return expr;
}

Variable *Parser::matrixLiteralParse() {
//    checkNextTokenThrow(TokenID::SquareBracketOpen);
    int dim = 0;
    Token token1, token2;
    Variable *newVar = new Variable();

    do {
        token1 = checkNextTokenThrow(TokenID::Number);
        token2 = lexer->nextToken();
        dim++;

        newVar->addValue(std::stoi(token1.getValue()));

    } while (token2.getId() == TokenID::Comma);

    if (token2.getId() != TokenID::Semicolon) {
        std::cout << "ERROR! INVALID TOKEN!" << std::endl;
        exit(1); //TODO throw exception
    }

    if (dim == 2) {
        newVar->setType(VariableType::Matrix2);
        token1 = checkNextTokenThrow(TokenID::Number);
        checkNextTokenThrow(TokenID::Comma);
        token2 = checkNextTokenThrow(TokenID::Number);
        newVar->addValue(std::stoi(token1.getValue()));
        newVar->addValue(std::stoi(token2.getValue()));
    } else if (dim == 3) {
        newVar->setType(VariableType::Matrix3);

        for (int i = 0; i < 2; i++) {
            token1 = checkNextTokenThrow(TokenID::Number);
            checkNextTokenThrow(TokenID::Comma);
            newVar->addValue(std::stoi(token1.getValue()));
        }
        checkNextTokenThrow(TokenID::Semicolon);
        for (int i = 0; i < 2; i++) {
            token1 = checkNextTokenThrow(TokenID::Number);
            checkNextTokenThrow(TokenID::Comma);
            newVar->addValue(std::stoi(token1.getValue()));
        }
        token1 = checkNextTokenThrow(TokenID::Number);
        newVar->addValue(std::stoi(token1.getValue()));
    } else {
        std::cout << "ERROR! INVALID TOKEN!" << std::endl;
        exit(1); //TODO throw exception
    }
    checkNextTokenThrow(TokenID::SquareBracketClose);

    return newVar;
}

Token Parser::checkNextTokenThrow(TokenID tokenID) {
    Token token = lexer->nextToken();

    if (token.getId() != tokenID) {
        std::cout << "ERROR! UNEXPECTED TOKEN!" << std::endl;
        exit(1); //TODO throw exception
    }

    return token;
}

LogicExpression *Parser::logicOrExprParse() {
    LogicExpression *andExpr = logicAndExprParse();
    Token token = lexer->nextToken();

    while (token.getId() == TokenID::Or) {
        LogicExpression *nextAndExpr = logicAndExprParse();
        andExpr = new LogicExpr(andExpr, nextAndExpr);
        token = lexer->nextToken();
        //TODO czy ja dobrze czytam te tokeny?
    }

    return andExpr;
}

LogicExpression *Parser::logicAndExprParse() {
    LogicExpression *relationExpr = logicRelationExprParse();
    Token token = lexer->nextToken();

    while (token.getId() == TokenID::And) {
        LogicExpression *nextRelationExpr = logicRelationExprParse();
        relationExpr = new AndExpr(relationExpr, nextRelationExpr);
        token = lexer->nextToken();
    }

    return relationExpr;
}

LogicExpression *Parser::logicRelationExprParse() {
    Token token = lexer->nextToken();
    //TODO negation

    TokenID tokenID = token.getId();

    if (tokenID == TokenID::RoundBracketOpen)
        return logicBracketExprParse();

//    MathExpression *leftMathExpr = mathSumExprParse();
//
//    Token op = lexer.nextToken();
//
//    MathExpression *rightMathExpr = mathSumExprParse();

    return nullptr;
}

LogicExpression *Parser::logicBaseExprParse() {
    LogicExpression *expr = logicOrExprParse();
    checkNextTokenThrow(TokenID::RoundBracketClose);

    return expr;
}

LogicExpression *Parser::logicBracketExprParse() {
    return nullptr;
}
