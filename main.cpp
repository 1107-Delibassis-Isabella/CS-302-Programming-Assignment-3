#include "Tokenizer.h"
using namespace std;

int main() {
    cout << "Mini Expression Interpreter" << endl;
    cout << "Enter an arithmetic expression or type quit" << endl;

    string userInput;
    getline(cin, userInput);
    while (userInput != "quit") {
        cout << "Expression: " << userInput << endl;

        LinkedQueue<Token> tokens = tokenize(userInput);

        LinkedQueue<Token> postfix = toPostfix(tokens);
        int result = evaluatePostfix(postfix);
        string tokensString = QueueString(tokens);
        cout << "Tokens: " << tokensString << endl;
        cout << "Postfix: " << QueueString(postfix) << endl;
        cout << "Result: " << result << endl;




        getline(cin, userInput);
        if (userInput == "quit") {
            cout << "Expression: " << userInput << endl;
            cout << "Goodbye." << endl;
        }
    }
    return 0;
}