#include<iostream>
#include<string>
using namespace std;

struct Stack {
    int arr[100];
    int top;
    Stack() { top = -1; }
    void push(int n) { arr[++top] = n; }
    int pop() { return arr[top--]; }
    bool isEmpty() { return top == -1; }
};

int evaluate(string expr) {
    Stack s;
    for(int i = 0; i < expr.length(); i++) {
        char c = expr[i];
        if(c == ' ') continue;
        if(c >= '0' && c <= '9') {
            s.push(c - '0');
        } else {
            int b = s.pop();
            int a = s.pop();
            switch(c) {
                case '+': s.push(a + b); break;
                case '-': s.push(a - b); break;
                case '*': s.push(a * b); break;
                case '/': s.push(a / b); break;
                case '^':
                    int res = 1;
                    for(int j = 0; j < b; j++) res *= a;
                    s.push(res);
                    break;
            }
        }
    }
    return s.pop();
}

int main() {
    string expr;
    cout << "Enter postfix expression (space separated): ";
    getline(cin, expr);
    cout << "Result: " << evaluate(expr) << endl;

    cout << "\n--- Examples ---" << endl;
    cout << "2 3 + = " << evaluate("2 3 +") << endl;
    cout << "5 3 2 * + = " << evaluate("5 3 2 * +") << endl;
    cout << "8 2 / 3 - = " << evaluate("8 2 / 3 -") << endl;

    return 0;
}