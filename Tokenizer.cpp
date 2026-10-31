#include "Tokenizer.h"
#include "stdio.h"
#include <iostream>
#include <string>

LinkedQueue<Token> tokenize(const std::string& expression) {
    LinkedQueue<Token> tokens;
    int value = 0; //will hold the value of the integers
    for (int i = 0; i < expression.length(); i++) {
        if (expression[i] == ' ') {
            //will skip through if it is a whitespace
        } else {
            while (i < expression.length() && isNumber(expression[i] == true)) {
                value = value * 10 + (expression[i] - '0'); 
                i++;
            }
            Token token; //might be incorrect
            tokens.enqueue(token.numberToken(value));
                

            switch (expression[i]) {
                case '+': 
                    tokens.enqueue(token.operatorToken(TokenType::PLUS));
                    break;
                case '-': 
                    tokens.enqueue(token.operatorToken(TokenType::MINUS));
                    break;
                case '*': 
                    tokens.enqueue(token.operatorToken(TokenType::MULTIPLY));
                    break;
                case '/': 
                    tokens.enqueue(token.operatorToken(TokenType::DIVIDE));
                    break;
                case '(': 
                    tokens.enqueue(token.operatorToken(TokenType::LEFT_PAREN));
                    break;
                case ')': 
                    tokens.enqueue(token.operatorToken(TokenType::RIGHT_PAREN));
                    break;

                default: 
                    std::cout << "Tokenizer error at position" << i << ": unexpected character " << expression[i] << std::endl;
            }
        }

    }
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
            bool isLeftFound = false;
            while (operators.isEmpty() == false) {
                Token top = operators.findTop();
                operators.pop();
                if (top.type == TokenType::LEFT_PAREN) {
                    isLeftFound = true;
                }

                postFixOutput.enqueue(top); //idk if you should enqueue it
            }

            if (isLeftFound == false) {
                std::cout << "Mismatched-parenthesis error" << std::endl;
            }
        } else if (isOperator(token) == true) {
            Token top = operators.findTop();
            while (operators.isEmpty() == false && isOperator(token) == true && precedence(operators.findTop()) >= precedence(token)) {
                operators.pop();
                postFixOutput.enqueue(token);
            }
            operators.push(token);
        } else {
            while (operators.isEmpty() == false) {
                Token top = operators.findTop();
                operators.pop();
                postFixOutput.enqueue(top);
                if (top.type == TokenType::LEFT_PAREN || top.type == TokenType::RIGHT_PAREN) {
                    std::cout << "Mismatched-parenthesis error" << std::endl;
                }
            }
        }
    }
    
}

int evaluatePostfix(LinkedQueue<Token> postfix) {
    //Use a LinkedStack<int> to store operands
    LinkedStack<int> storedOperands;
    while (postfix.isEmpty() == false) {
        Token token = postfix.findFront(); 
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
                int result;
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
                            std::cout << "Division by zero error" << std::endl;
                        } else {
                            result = leftOperand / rightOperand;
                        }
                        break;
                }
                storedOperands.push(result); //pushes the result
            } else {
                std::cout << "The stack does not contain at least two values error" << std::endl;
            }
        } else {
            if (storedOperands.isEmpty() || storedOperands.size() > 1) {
                std::cout << "Expression is malformed error" << std::endl;
                return -1; //idk if this is correct or not
            }
            return storedOperands.findTop();
        }
    }
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