#include<iostream>
using namespace std;

struct Element {
    int data;
    int priority;
};

class PriorityQueue {
    Element arr[100];
    int size;
public:
    PriorityQueue() { size = 0; }

    void insert(int val, int pri) {
        if(size == 100) {
            cout << "Queue is full" << endl;
            return;
        }
        arr[size].data = val;
        arr[size].priority = pri;
        size++;
        cout << "Inserted " << val << " with priority " << pri << endl;
    }

    int getHighestPriority() {
        int idx = 0;
        for(int i = 1; i < size; i++)
            if(arr[i].priority > arr[idx].priority)
                idx = i;
        return idx;
    }

    void remove() {
        if(size == 0) {
            cout << "Queue is empty" << endl;
            return;
        }
        int idx = getHighestPriority();
        cout << "Removed: " << arr[idx].data << " (priority " << arr[idx].priority << ")" << endl;
        for(int i = idx; i < size - 1; i++)
            arr[i] = arr[i+1];
        size--;
    }

    void peek() {
        if(size == 0) {
            cout << "Queue is empty" << endl;
            return;
        }
        int idx = getHighestPriority();
        cout << "Highest priority: " << arr[idx].data << " (priority " << arr[idx].priority << ")" << endl;
    }

    void display() {
        if(size == 0) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Queue: " << endl;
        for(int i = 0; i < size; i++)
            cout << "  Data: " << arr[i].data << " | Priority: " << arr[i].priority << endl;
    }
};

int main() {
    PriorityQueue pq;
    pq.insert(10, 2);
    pq.insert(20, 5);
    pq.insert(30, 1);
    pq.insert(40, 4);
    pq.insert(50, 3);

    pq.display();
    cout << endl;
    pq.peek();
    cout << endl;
    pq.remove();
    pq.remove();
    cout << endl;
    pq.display();

    return 0;
}