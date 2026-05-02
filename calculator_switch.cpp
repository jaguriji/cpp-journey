#include<iostream>
using namespace std;

double calculate(double a, double b, char op) {
    switch(op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/':
            if(b == 0) {
                cout << "Error: Division by zero" << endl;
                return 0;
            }
            return a / b;
        case '%':
            return (int)a % (int)b;
        default:
            cout << "Invalid operator" << endl;
            return 0;
    }
}

int main() {
    double a, b;
    char op, choice;

    do {
        cout << "Enter first number: ";
        cin >> a;
        cout << "Enter operator (+, -, *, /, %): ";
        cin >> op;
        cout << "Enter second number: ";
        cin >> b;

        cout << "Result: " << calculate(a, b, op) << endl;

        cout << "Continue? (y/n): ";
        cin >> choice;
    } while(choice == 'y' || choice == 'Y');

    return 0;
}