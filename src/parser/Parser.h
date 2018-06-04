#ifndef SIMPLELANGUAGEINTERPRETER_PARSER_H
#define SIMPLELANGUAGEINTERPRETER_PARSER_H

#include <memory>
#include <lexer/Lexer.h>
#include "ast/Variable.h"
#include <ast/expression/MathExpression.h>

class Parser {
public:
    explicit Parser(Lexer lexer);

private:
    Lexer lexer;

    MathExpression *mathSumExprParse();

    MathExpression *mathMultExprParse();

    MathExpression *mathBaseExprParse();

    MathExpression *mathBracketExprParse();

    Variable *matrixLiteralParse();

    Token checkNextTokenThrow(TokenID tokenID);
//    string input;    // analizowany tekst
//    size_t position; // wskaźnik na aktualnie "oglądany" znak
//
//public:
//
//    Parser(string input);
//
//    // Pomija wszystkie białe znaki i przesuwa wskaźnik
//    // na pierwszy znak, który nie jest biały.
//    void skip_whitespace();
//
//    // Pomija białe znaki i informuje jaki znak "oglądamy".
//    char look_ahead();
//
//    MathExpression* parse_Expression(); // Parsuje wyrażanie.
//    MathExpression* parse_sum();        // Parsuje "sumę".
//    MathExpression* parse_mult();       // Parsuje składnik.
//    MathExpression* parse_term();       // Parsuje czynnik.
//    MathExpression* parse_Constant();   // Parsuje liczbę.
//    MathExpression* parse_Variable();   // Parsuje nazwę zmiennej.
//    MathExpression* parse_paren();      // Parsuje "sumę" w nawiasie.
};


#endif //SIMPLELANGUAGEINTERPRETER_PARSER_H
