#include <iostream>
#include <climits>
#include "Lexer.h"

Lexer::Lexer(std::istream &istream) : scanner(istream) {
    token = "";
}

Lexer::~Lexer() = default;

Token Lexer::nextToken() {
    char c;
    token = "";

    do {
        c = scanner.nextChar();
    } while (c == ' ' || c == '\t' || c == '\n');

    if (c == EOF)
        return Token(TokenID::Eof, scanner.getPosition());

    if (isalpha(c)) { //name or keyword
        return nameTokenHandler(c);

    } else if (isdigit(c)) { //number
        return numberTokenHandler(c);

    } else { //char other than digit and letter
        return otherTokenHandler(c);
    }
}

void Lexer::lexError(std::string msg) {
    std::cout << "In line: " << scanner.getPosition().lineNr << ":\n\t";
    std::cout << msg << std::endl;
}

Token Lexer::nameTokenHandler(char c) {
    do {
        token += c;
        if (token.length() >= NAMEMAXLENGTH) {
            lexError("ERROR: NAME TOO LONG!");

            while (isalnum(c) || c == '_')
                c = scanner.nextChar();

            scanner.fallBack(1);
            return Token(TokenID::Invalid, scanner.getPosition());
        }

        c = scanner.nextChar();
    } while (isalnum(c) || c == '_');

    scanner.fallBack(1);

    TokenID tokenID = Token::getKeywordByName(token);

    if (tokenID != TokenID::Invalid)
        return Token(tokenID, scanner.getPosition());
    else
        return Token(TokenID::Name, scanner.getPosition());
}

Token Lexer::numberTokenHandler(char c) {
    int num = 0;

    do {
        num = num * 10 + (c - '0');
        if (num > INT_MAX || num < 0) {
            lexError("ERROR: NUMBER OUT OF LIMITS!");

            while (isdigit(c))
                c = scanner.nextChar();

            scanner.fallBack(1);
            return Token(TokenID::Invalid, scanner.getPosition());
        }

        c = scanner.nextChar();
    } while (isdigit(c));

    if (isalpha(c)) {
        lexError("ERROR: INVALID TOKEN");

        while(isalnum(c))
            c = scanner.nextChar();

        scanner.fallBack(1);
        return Token(TokenID::Invalid, scanner.getPosition());
    }

    scanner.fallBack(1);

    return Token(TokenID::Number, scanner.getPosition());
}

Token Lexer::otherTokenHandler(char c) {
    switch (c) {
        case ';':
            return Token(TokenID::Semicolon, scanner.getPosition());
        case ',':
            return Token(TokenID::Comma, scanner.getPosition());
        case '(':
            return Token(TokenID::RoundBracketOpen, scanner.getPosition());
        case ')':
            return Token(TokenID::RoundBracketClose, scanner.getPosition());
        case '{':
            return Token(TokenID::CurlyBracketOpen, scanner.getPosition());
        case '}':
            return Token(TokenID::CurlyBracketClose, scanner.getPosition());
        case '[':
            return Token(TokenID::SquareBracketOpen, scanner.getPosition());
        case ']':
            return Token(TokenID::SquareBracketClose, scanner.getPosition());
        case '+':
            return Token(TokenID::Plus, scanner.getPosition());
        case '-':
            return Token(TokenID::Minus, scanner.getPosition());
        case '*':
            return Token(TokenID::Multiply, scanner.getPosition());
        case '/':
            return Token(TokenID::Divide, scanner.getPosition());
        case '=':
            return ifNextIsEqual('=', TokenID::Equal, TokenID::Assign);
        case '!':
            return ifNextIsEqual('=', TokenID::Unequal, TokenID::Negation);
        case '<':
            return ifNextIsEqual('=', TokenID::LessOrEqual, TokenID::Less);
        case '>':
            return ifNextIsEqual('=', TokenID::GreaterOrEqual, TokenID::Greater);
        case '&':
            return ifNextIsEqual('&', TokenID::And, TokenID::Invalid);
        case '|':
            return ifNextIsEqual('|', TokenID::Or, TokenID::Invalid);
        case '"':
            do {
                c = scanner.nextChar();
            } while (c != '"' && c != EOF);

            if (c == EOF) {
                lexError("ERROR: INVALID TOKEN");
                return Token(TokenID::Invalid, scanner.getPosition());
            }
            else
                return Token(TokenID::String, scanner.getPosition());
        default:
            lexError("ERROR: INVALID TOKEN");
            return Token(TokenID::Invalid, scanner.getPosition());
    }
}

Token Lexer::ifNextIsEqual(char expectedChar, TokenID tokenIfTrue, TokenID tokenIfFalse) {
    char c = scanner.peekChar();
    if (c == expectedChar) {
        scanner.nextChar();
        return Token(tokenIfTrue, scanner.getPosition());
    }
    else {
        if(tokenIfFalse == TokenID::Invalid)
            lexError("ERROR: INVALID TOKEN");
        return Token(tokenIfFalse, scanner.getPosition());
    }
}
