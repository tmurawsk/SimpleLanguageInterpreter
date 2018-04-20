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
    }while (c == ' ' || c == '\t' || c == '\n');

    if(c == EOF)
        return TokenID::Eof;

    if(isalpha(c)) { //name or keyword
        do {
            token += c;
            if(token.length() >= NAMEMAXLENGTH) {
                lexError("ERROR: NAME TOO LONG!");

                while(isalnum(c) || c == '_')
                    c = scanner.nextChar();

                break;
            }

            c = scanner.nextChar();
        }while (isalnum(c) || c == '_');

        scanner.fallBack(1);

        TokenID tokenID = Token::getKeywordByName(token);

        if(tokenID != TokenID::Invalid)
            return tokenID;
        else
            return TokenID::Name;
    }
    else if(isdigit(c)) { //number
        int num = 0;

        do {
            num = num * 10 + (c - '0');
            if(num > INT_MAX || num < 0) {
                lexError("ERROR: NUMBER OUT OF LIMITS!");

                while(isdigit(c))
                    c = scanner.nextChar();

                break;
            }
            c = scanner.nextChar();
        } while (isdigit(c));

        scanner.fallBack(1);

        return TokenID::Number;
    }
    else { //char other than digit and letter
        switch(c){
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
                c = scanner.nextChar();
                if(c == '=')
                    return TokenID::Equal;
                else {
                    scanner.fallBack(1);
                    return TokenID::Assign;
                }
            case '!':
                c = scanner.nextChar();
                if(c == '=')
                    return TokenID::Unequal;
                else {
                    scanner.fallBack(1);
                    return TokenID::Negation;
                }
            case '<':
                c = scanner.nextChar();
                if (c == '=')
                    return TokenID::LessOrEqual;
                else {
                    scanner.fallBack(1);
                    return TokenID::Less;
                }
            case '>':
                c = scanner.nextChar();
                if (c == '=')
                    return TokenID::GreaterOrEqual;
                else {
                    scanner.fallBack(1);
                    return TokenID::Greater;
                }
            case '&':
                c = scanner.nextChar();
                if(c == '&')
                    return TokenID::And;
                else {
                    scanner.fallBack(1);
                    return TokenID::Invalid;
                }
            case '|':
                c = scanner.nextChar();
                if(c == '|')
                    return TokenID::Or;
                else {
                    scanner.fallBack(1);
                    return TokenID::Invalid;
                }
            default:
                return TokenID::Invalid;
        }
    }
}

void Lexer::lexError(std::string msg) {
    std::cerr << msg << std::endl;
}
