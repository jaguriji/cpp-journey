#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Queue {
    Node* front;
    Node* rear;
public:
    Queue() {
        front = NULL;
        rear = NULL;
    }

    void enqueue(int val) {
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = NULL;
        if(rear == NULL) {
            front = rear = newNode;
            cout << "Enqueued: " << val << endl;
            return;
        }
        rear->next = newNode;
        rear = newNode;
        cout << "Enqueued: " << val << endl;
    }

    void dequeue() {
        if(front == NULL) {
            cout << "Queue is empty" << endl;
            return;
        }
        Node* temp = front;
        cout << "Dequeued: " << front->data << endl;
        front = front->next;
        if(front == NULL) rear = NULL;
        delete temp;
    }

    void peek() {
        if(front == NULL) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Front: " << front->data << endl;
    }

    void display() {
        if(front == NULL) {
            cout << "Queue is empty" << endl;
            return;
        }
        Node* temp = front;
        while(temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.peek();
    q.display();
    q.dequeue();
    q.display();
    q.dequeue();
    q.peek();
    return 0;
}