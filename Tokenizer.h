#ifndef TOKENIZER_H
#define TOKENIZER_H

#include "Token.h"
#include "LinkedStack.h"
#include "LinkedQueue.h"
using namespace std;
#include <sstream>
 
LinkedQueue<Token> tokenize(const std::string& expression);
LinkedQueue<Token> toPostfix(LinkedQueue<Token> infix);
int evaluatePostfix(LinkedQueue<Token> postfix);
bool isOperator(const Token& token);
int precedence(const Token& token);
bool isNumber(const char c);
string QueueString(LinkedQueue<Token> tokens);






#endif