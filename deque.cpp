#include<iostream>
using namespace std;

class Deque {
    int arr[100];
    int front;
    int rear;
    int size;
public:
    Deque(int s) {
        size = s;
        front = -1;
        rear = 0;
    }

    bool isFull() {
        return ((front == 0 && rear == size - 1) || front == rear + 1);
    }

    bool isEmpty() {
        return front == -1;
    }

    void insertFront(int val) {
        if(isFull()) { cout << "Deque is full" << endl; return; }
        if(front == -1) { front = 0; rear = 0; }
        else if(front == 0) front = size - 1;
        else front--;
        arr[front] = val;
        cout << "Inserted " << val << " at front" << endl;
    }

    void insertRear(int val) {
        if(isFull()) { cout << "Deque is full" << endl; return; }
        if(front == -1) { front = 0; rear = 0; }
        else if(rear == size - 1) rear = 0;
        else rear++;
        arr[rear] = val;
        cout << "Inserted " << val << " at rear" << endl;
    }

    void deleteFront() {
        if(isEmpty()) { cout << "Deque is empty" << endl; return; }
        cout << "Deleted from front: " << arr[front] << endl;
        if(front == rear) { front = -1; rear = -1; }
        else if(front == size - 1) front = 0;
        else front++;
    }

    void deleteRear() {
        if(isEmpty()) { cout << "Deque is empty" << endl; return; }
        cout << "Deleted from rear: " << arr[rear] << endl;
        if(front == rear) { front = -1; rear = -1; }
        else if(rear == 0) rear = size - 1;
        else rear--;
    }

    void peekFront() {
        if(isEmpty()) { cout << "Deque is empty" << endl; return; }
        cout << "Front: " << arr[front] << endl;
    }

    void peekRear() {
        if(isEmpty()) { cout << "Deque is empty" << endl; return; }
        cout << "Rear: " << arr[rear] << endl;
    }

    void display() {
        if(isEmpty()) { cout << "Deque is empty" << endl; return; }
        cout << "Deque: ";
        int i = front;
        while(i != rear) {
            cout << arr[i] << " ";
            i = (i + 1) % size;
        }
        cout << arr[rear] << endl;
    }
};

int main() {
    Deque dq(6);
    dq.insertRear(10);
    dq.insertRear(20);
    dq.insertRear(30);
    dq.insertFront(5);
    dq.insertFront(1);
    dq.display();
    dq.peekFront();
    dq.peekRear();
    dq.deleteFront();
    dq.deleteRear();
    dq.display();
    return 0;
}