#include "Tokenizer.h"
#include "stdio.h"
#include <iostream>
#include <string>

LinkedQueue<Token> tokenize(const std::string& expression) {
    LinkedQueue<Token> tokens;
    int i = 0; // index for expression input

    while (i < expression.length()) {
        char c = expression[i];
        if (isspace(c)) {
            //will skip through if it is a whitespace
            i++;
            continue;
        } else if (isdigit(c)) {
            int val = 0;
            while (i < expression.length() && isdigit(expression[i])) {
                val = val * 10 + (expression[i] - '0');
                i++;
            }
            tokens.enqueue(Token(TokenType::INTEGER, val));
            continue;
        }
        
        switch (expression[i]) {
            case '+': 
                tokens.enqueue(Token(TokenType::PLUS));
                break;
            case '-': 
                tokens.enqueue(Token(TokenType::MINUS));
                break;
            case '*': 
                tokens.enqueue(Token(TokenType::MULTIPLY));
                break;
            case '/': 
                tokens.enqueue(Token(TokenType::DIVIDE));
                break;
            case '(': 
                tokens.enqueue(Token(TokenType::LEFT_PAREN));
                break;
            case ')': 
                tokens.enqueue(Token(TokenType::RIGHT_PAREN));
                break;

            default: 
                throw std::runtime_error("Tokenizer error at position " + std::to_string(i)
                                         + ": unexpected character '" + expression[i] + "'");
        }
        i++;
    }
    return tokens;
}

//template might be incorrect

LinkedQueue<Token> toPostfix(LinkedQueue<Token> infix) {
    //must use LinkedStack<Token> for operators
    //must use LinkedQueue <Token> for the postfix output
    LinkedStack<Token> operators;
    LinkedQueue<Token> postFixOutput;

    while(infix.isEmpty() == false) {
        Token token = infix.findFront(); 
        if (token.type == TokenType::INTEGER) {
            postFixOutput.enqueue(token);
        } else if (token.type == TokenType::LEFT_PAREN) {
            operators.push(token);
        } else if (token.type == TokenType::RIGHT_PAREN) {
            while (operators.isEmpty() == false && operators.findTop().type != TokenType::LEFT_PAREN) {
                postFixOutput.enqueue(operators.findTop());
                operators.pop();
            }
            if (operators.isEmpty())
            {
                throw std::runtime_error("Mismatched parentheses: missing '('");
            }
            operators.pop(); //pop the left parenthesis
        } else if (isOperator(token) == true) {
            while (operators.isEmpty() == false && isOperator(operators.findTop()) == true && precedence(operators.findTop()) >= precedence(token)) {
                postFixOutput.enqueue(operators.findTop());
                operators.pop();
            }
            operators.push(token);
        }
        infix.dequeue();
    }
    while (operators.isEmpty() == false) {
        if (operators.findTop().type == TokenType::LEFT_PAREN || operators.findTop().type == TokenType::RIGHT_PAREN) {
            throw std::runtime_error("Mismatched parentheses: missing ')'");
        }
        postFixOutput.enqueue(operators.findTop());
        operators.pop();
    }
    return postFixOutput;
}

int evaluatePostfix(LinkedQueue<Token> postfix) {
    //Use a LinkedStack<int> to store operands
    LinkedStack<int> storedOperands;
    while (postfix.isEmpty() == false) {
        Token token = postfix.findFront(); 
        postfix.dequeue(); //dequeue the token after storing it in the variable
        if (token.type == TokenType::INTEGER) {
            storedOperands.push(token.value); //will push the integer value of the token onto the operand stack
        } else if (isOperator(token) == true) {
            //1. verify that the stack contains at least two values, which means that we will find the count
            if (storedOperands.size() >= 2) {
                //pop the right operand
                //pop the left operand
                //apply the operator
                //push the result
                int rightOperand = storedOperands.findTop();
                storedOperands.pop(); //pops the right
                int leftOperand = storedOperands.findTop();
                storedOperands.pop(); //pops the left
                int result = 0;
                switch (token.type) {
                    case TokenType::PLUS:
                        result = leftOperand + rightOperand;
                        break;
                    case TokenType::MINUS: 
                        result = leftOperand - rightOperand;
                        break;
                    case TokenType::MULTIPLY: 
                        result = leftOperand * rightOperand;
                        break;
                    case TokenType::DIVIDE: 
                        //if division is 0 then there is an error
                        //right operand will determine if there is an error
                        if (rightOperand == 0) {
                            throw std::domain_error("Division by zero");
                        } else {
                            result = leftOperand / rightOperand;
                        }
                        break;

                    default: break;
                }
                storedOperands.push(result); //pushes the result
            } else {
                throw std::runtime_error("Syntax error: operator is missing an operand");
            }
        }
    }
    if (storedOperands.isEmpty()) {
        throw std::runtime_error("Syntax error: expression has no result");
    }
    if (storedOperands.size() > 1) {
        throw std::runtime_error("Syntax error: missing operator");
    }
    return storedOperands.findTop();
}


bool isOperator(const Token& token) {
    if (token.type == TokenType::PLUS || token.type == TokenType::MINUS || token.type == TokenType::MULTIPLY || token.type == TokenType::DIVIDE) {
        return true;
    }
    return false;
}
int precedence(const Token& token) {
    if (token.type == TokenType::PLUS || token.type == TokenType::MINUS) {
        return 1; //is the first precedence level
    } else if (token.type == TokenType::MULTIPLY || token.type == TokenType::DIVIDE) {
        return 2; //is the second precedence level
    } 
    return 0; //will return 0 if none of the token types fit the input
}

bool isNumber(const char c) {
    if (((c - '0') == 1) || ((c - '0') == 2) || ((c - '0') == 3) || ((c - '0') == 4) || ((c - '0') == 5) || ((c - '0') == 6) || ((c - '0') == 7) || ((c - '0') == 8) || ((c - '0') == 9) || ((c - '0') == 0)) {
        return true;
    }
    return false; 
}   

string QueueString(LinkedQueue<Token> tokens) {
    string result = "";
    bool first = true;
    while (tokens.isEmpty() == false) {
        if (!tokens.isEmpty()) {
            if (first == false) {
                result += " ";
            }
            result += tokens.findFront().expression();
            tokens.dequeue();
            
            
            result+= " ";
        }

        first = false;
    }
    return result;
}