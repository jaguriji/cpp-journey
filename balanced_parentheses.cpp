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

bool isOpening(char c) {
    return c == '(' || c == '[' || c == '{';
}

bool isMatching(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

bool isBalanced(string expr) {
    Stack s;
    for(int i = 0; i < expr.length(); i++) {
        char c = expr[i];
        if(isOpening(c)) {
            s.push(c);
        } else if(c == ')' || c == ']' || c == '}') {
            if(s.isEmpty()) return false;
            if(!isMatching(s.pop(), c)) return false;
        }
    }
    return s.isEmpty();
}

int main() {
    string expr;
    cout << "Enter expression: ";
    cin >> expr;

    if(isBalanced(expr))
        cout << expr << " is Balanced" << endl;
    else
        cout << expr << " is Not Balanced" << endl;

    cout << "\n--- Examples ---" << endl;
    string tests[] = {"(())", "{[()]}", "(()", "{[}]", "((()))"};
    for(string t : tests)
        cout << t << " -> " << (isBalanced(t) ? "Balanced" : "Not Balanced") << endl;

    return 0;
}