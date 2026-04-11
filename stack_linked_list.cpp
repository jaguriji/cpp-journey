#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
    Node* top;
public:
    Stack() {
        top = NULL;
    }

    void push(int val) {
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = top;
        top = newNode;
        cout << "Pushed: " << val << endl;
    }

    void pop() {
        if(top == NULL) {
            cout << "Stack underflow" << endl;
            return;
        }
        Node* temp = top;
        cout << "Popped: " << top->data << endl;
        top = top->next;
        delete temp;
    }

    void peek() {
        if(top == NULL) {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Top: " << top->data << endl;
    }

    bool isEmpty() {
        return top == NULL;
    }

    void display() {
        if(top == NULL) {
            cout << "Stack is empty" << endl;
            return;
        }
        Node* temp = top;
        while(temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    Stack s;
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