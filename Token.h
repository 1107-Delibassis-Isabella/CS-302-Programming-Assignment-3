#ifndef TOKEN_H
#define TOKEN_H
#include <string>
#include "stdio.h"
#include <iostream>

enum class TokenType {
    INTEGER, 
    PLUS, 
    MINUS, 
    MULTIPLY, 
    DIVIDE, 
    LEFT_PAREN, 
    RIGHT_PAREN
};

struct Token {
    TokenType type;
    int value;

    Token();
    Token(TokenType t, int v = 0) : type(t), value(v) {} //idk if this is correct

    Token numberToken(int v) {
        return Token(TokenType::INTEGER, v);
    }

    Token operatorToken(TokenType t) {
        return Token(t, 0);
    }
    
    std::string expression() const{
        switch (type) {
            case TokenType::INTEGER: 
                return std::to_string(value);
                break;
            case TokenType::PLUS: 
                return "+";
                break;
            case TokenType::MINUS: 
                return "-";
                break;
            case TokenType::MULTIPLY: 
                return "*";
                break;
            case TokenType::DIVIDE: 
                return "/";
                break;
            case TokenType::LEFT_PAREN: 
                return "(";
                break;
            case TokenType::RIGHT_PAREN: 
                return ")";
                break;
        }
        return "";
    }
};

#endif
