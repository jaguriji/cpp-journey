#include<iostream>
using namespace std;

class Stack {
    int arr[100];
    int top;
    int size;
public:
    Stack(int s) {
        size = s;
        top = -1;
    }

    void push(int val) {
        if(top == size - 1) {
            cout << "Stack overflow" << endl;
            return;
        }
        arr[++top] = val;
        cout << "Pushed: " << val << endl;
    }

    void pop() {
        if(top == -1) {
            cout << "Stack underflow" << endl;
            return;
        }
        cout << "Popped: " << arr[top] << endl;
        top--;
    }

    void peek() {
        if(top == -1) {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Top: " << arr[top] << endl;
    }

    void display() {
        if(top == -1) {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Stack: ";
        for(int i = top; i >= 0; i--)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    Stack s(5);
    s.push(10);
    s.push(20);
    s.push(30);
    s.peek();
    s.display();
    s.pop();
    s.display();
    s.pop();
    s.peek();
    return 0;
}