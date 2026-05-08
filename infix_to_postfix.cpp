#include<iostream>
#include<string>
using namespace std;

struct Stack {
    char arr[100];
    int top;
    Stack() { top = -1; }
    void push(char c) { arr[++top] = c; }
    char pop() { return arr[top--]; }
    char peek() { return arr[top]; }
    bool isEmpty() { return top == -1; }
};

int precedence(char c) {
    if(c == '^') return 3;
    if(c == '*' || c == '/') return 2;
    if(c == '+' || c == '-') return 1;
    return 0;
}

bool isOperand(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}

string infixToPostfix(string expr) {
    Stack s;
    string result = "";

    for(int i = 0; i < expr.length(); i++) {
        char c = expr[i];

        if(isOperand(c)) {
            result += c;
        } else if(c == '(') {
            s.push(c);
        } else if(c == ')') {
            while(!s.isEmpty() && s.peek() != '(')
                result += s.pop();
            s.pop();
        } else {
            while(!s.isEmpty() && precedence(s.peek()) >= precedence(c))
                result += s.pop();
            s.push(c);
        }
    }
    while(!s.isEmpty())
        result += s.pop();

    return result;
}

int main() {
    string expr;
    cout << "Enter infix expression: ";
    cin >> expr;
    cout << "Postfix: " << infixToPostfix(expr) << endl;

    cout << "\n--- Examples ---" << endl;
    cout << "a+b*c -> " << infixToPostfix("a+b*c") << endl;
    cout << "(a+b)*c -> " << infixToPostfix("(a+b)*c") << endl;
    cout << "a+b*c-d -> " << infixToPostfix("a+b*c-d") << endl;

    return 0;
}