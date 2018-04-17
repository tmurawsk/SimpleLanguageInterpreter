#include "Token.h"

Token::Token(TokenID &id) : id(id), value(""), position() {
}

std::unordered_map <TokenID, std::string> Token::nameMap = {
        {TokenID::Main, "Main"},        {TokenID::Func, "Func"},
        {TokenID::If, "If"},            {TokenID::Else, "Else"},
        {TokenID::While, "While"},      {TokenID::Print, "Print"},
        {TokenID::Return, "Return"},    {TokenID::Num, "Num"},
        {TokenID::Mat2, "Mat2"},        {TokenID::Mat3, "Mat3"},

        {TokenID::Semicolon, "Semicolon"},
        {TokenID::Comma, "Comma"},
        {TokenID::RoundBracketOpen, "RoundBracketOpen"},
        {TokenID::RoundBracketClose, "RoundBracketClose"},
        {TokenID::CurlyBracketOpen, "CurlyBracketOpen"},
        {TokenID::CurlyBracketClose, "CurlyBracketClose"},
        {TokenID::SquareBracketOpen, "SquareBracketOpen"},
        {TokenID::SquareBracketClose, "SquareBracketClose"},

        {TokenID::Plus, "Plus"},        {TokenID::Minus, "Minus"},
        {TokenID::Multiply, "Multiply"},{TokenID::Divide, "Divide"},
        {TokenID::Assign, "Assign"},

        {TokenID::Negation, "Negation"},
        {TokenID::Or, "Or"},            {TokenID::And, "And"},

        {TokenID::Equal, "Equal"},      {TokenID::Unequal, "Unequal"},
        {TokenID::Less, "Less"},        {TokenID::Greater, "Greater"},
        {TokenID::LessOrEqual, "LessOrEqual"},
        {TokenID::GreaterOrEqual, "GreaterOrEqual"},

        {TokenID::Name, "Name"},        {TokenID::Number, "Number"},
        {TokenID::String, "String"},

        {TokenID::Invalid, "Invalid"},  {TokenID::Eof, "Eof"}
};

std::unordered_map <std::string, TokenID> Token::keywordMap = {
        {"main", TokenID::Main},    {"func", TokenID::Func},
        {"if", TokenID::If},        {"else", TokenID::Else},
        {"while", TokenID::While},  {"print", TokenID::Print},
        {"return", TokenID::Return},{"num", TokenID::Num},
        {"mat2", TokenID::Mat2},    {"mat3", TokenID::Mat3}
};

std::unordered_map <char, TokenID> Token::charMap = {
        {';', TokenID::Semicolon},          {',', TokenID::Comma},
        {'(', TokenID::RoundBracketOpen},   {')', TokenID::RoundBracketClose},
        {'{', TokenID::CurlyBracketOpen},   {'}', TokenID::CurlyBracketClose},
        {'[', TokenID::SquareBracketOpen},  {']', TokenID::SquareBracketClose},
        {'+', TokenID::Plus},               {'-', TokenID::Minus},
        {'*', TokenID::Multiply},           {'/', TokenID::Divide},
        {'=', TokenID::Equal},              {'!', TokenID::Negation}
};
