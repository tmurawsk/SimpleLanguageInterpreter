#ifndef SIMPLELANGUAGEINTERPRETER_TOKEN_H
#define SIMPLELANGUAGEINTERPRETER_TOKEN_H

#include <string>
#include <unordered_map>
#include "reader/Position.h"

enum class TokenID {
    Main, Func, If, Else, While, Print, Return, Num, Mat2, Mat3,
    Semicolon, Comma, RoundBracketOpen, RoundBracketClose, CurlyBracketOpen, CurlyBracketClose, SquareBracketOpen, SquareBracketClose,
    Plus, Minus, Multiply, Divide, Assign,
    Negation, Or, And,
    Equal, Unequal, Less, Greater, LessOrEqual, GreaterOrEqual,
    Name, Number, String,
    Invalid, Eof
};

class Token {
public:
    explicit Token(TokenID &id);

private:
    TokenID id;
    std::string value;
    Position position;

    static std::unordered_map <TokenID, std::string> nameMap;
    static std::unordered_map <std::string, TokenID> keywordMap;
    static std::unordered_map <char, TokenID> charMap;
};

#endif //SIMPLELANGUAGEINTERPRETER_TOKEN_H
