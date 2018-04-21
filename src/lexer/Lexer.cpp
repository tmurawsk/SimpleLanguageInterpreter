#include <iostream>
#include <climits>
#include "Lexer.h"

Lexer::Lexer(std::string filename) : scanner(filename) {
    errorCount = 0;
    token = "";
}

Lexer::~Lexer() = default;

TokenID Lexer::nextToken() {
    char c;
    token = "";

    do {
        c = scanner.nextChar();
    } while (c == ' ' || c == '\t' || c == '\n');

    if (c == EOF)
        return TokenID::Eof;

    if (isalpha(c)) { //name or keyword
        do {
            token += c;
            if (token.length() >= NAMEMAXLENGTH) {
                lexError("ERROR: NAME TOO LONG!");

                while (isalnum(c) || c == '_')
                    c = scanner.nextChar();

                scanner.fallBack(1);
                return TokenID::Invalid;
            }

            c = scanner.nextChar();
        } while (isalnum(c) || c == '_');

        scanner.fallBack(1);

        TokenID tokenID = Token::getKeywordByName(token);

        if (tokenID != TokenID::Invalid)
            return tokenID;
        else
            return TokenID::Name;

    } else if (isdigit(c)) { //number
        int num = 0;

        do {
            num = num * 10 + (c - '0');
            if (num > INT_MAX || num < 0) {
                lexError("ERROR: NUMBER OUT OF LIMITS!");

                while (isdigit(c))
                    c = scanner.nextChar();

                scanner.fallBack(1);
                return TokenID::Invalid;
            }

            c = scanner.nextChar();
        } while (isdigit(c));

        if (isalpha(c)) {
            lexError("ERROR: INVALID TOKEN");

            while(isalnum(c))
                c = scanner.nextChar();

            scanner.fallBack(1);
            return TokenID::Invalid;
        }

        scanner.fallBack(1);

        return TokenID::Number;

    } else { //char other than digit and letter
        switch (c) {
            case ';':
                return TokenID::Semicolon;
            case ',':
                return TokenID::Comma;
            case '(':
                return TokenID::RoundBracketOpen;
            case ')':
                return TokenID::RoundBracketClose;
            case '{':
                return TokenID::CurlyBracketOpen;
            case '}':
                return TokenID::CurlyBracketClose;
            case '[':
                return TokenID::SquareBracketOpen;
            case ']':
                return TokenID::SquareBracketClose;
            case '+':
                return TokenID::Plus;
            case '-':
                return TokenID::Minus;
            case '*':
                return TokenID::Multiply;
            case '/':
                return TokenID::Divide;
            case '=':
                c = scanner.peekChar();
                if (c == '=') {
                    scanner.nextChar();
                    return TokenID::Equal;
                }
                else
                    return TokenID::Assign;
            case '!':
                c = scanner.peekChar();
                if (c == '=') {
                    scanner.nextChar();
                    return TokenID::Unequal;
                }
                else
                    return TokenID::Negation;
            case '<':
                c = scanner.peekChar();
                if (c == '=') {
                    scanner.nextChar();
                    return TokenID::LessOrEqual;
                }
                else
                    return TokenID::Less;
            case '>':
                c = scanner.peekChar();
                if (c == '=') {
                    scanner.nextChar();
                    return TokenID::GreaterOrEqual;
                }
                else
                    return TokenID::Greater;
            case '&':
                c = scanner.peekChar();
                if (c == '&') {
                    scanner.nextChar();
                    return TokenID::And;
                }
                else {
                    lexError("ERROR: INVALID TOKEN");
                    return TokenID::Invalid;
                }
            case '|':
                c = scanner.peekChar();
                if (c == '|') {
                    scanner.nextChar();
                    return TokenID::Or;
                }
                else {
                    lexError("ERROR: INVALID TOKEN");
                    return TokenID::Invalid;
                }
            case '"':
                do {
                    c = scanner.nextChar();
                } while (c != '"' && c != EOF);

                if (c == EOF) {
                    lexError("ERROR: INVALID TOKEN");
                    return TokenID::Invalid;
                }
                else
                    return TokenID::String;
            default:
                lexError("ERROR: INVALID TOKEN");
                return TokenID::Invalid;
        }
    }
}

void Lexer::lexError(std::string msg) {
    std::cout << "In line: " << scanner.getPosition().lineNr << ":\n\t";
    std::cout << msg << std::endl;
}
