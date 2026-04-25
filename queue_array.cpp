#include<iostream>
using namespace std;

class Queue {
    int arr[100];
    int front;
    int rear;
    int size;
public:
    Queue(int s) {
        size = s;
        front = -1;
        rear = -1;
    }

    void enqueue(int val) {
        if(rear == size - 1) {
            cout << "Queue is full" << endl;
            return;
        }
        if(front == -1) front = 0;
        arr[++rear] = val;
        cout << "Enqueued: " << val << endl;
    }

    void dequeue() {
        if(front == -1 || front > rear) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Dequeued: " << arr[front] << endl;
        front++;
    }

    void peek() {
        if(front == -1 || front > rear) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Front: " << arr[front] << endl;
    }

    void display() {
        if(front == -1 || front > rear) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Queue: ";
        for(int i = front; i <= rear; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    Queue q(5);
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