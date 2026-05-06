#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
    Node* head;
public:
    LinkedList() { head = NULL; }

    void insert(int val) {
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = NULL;
        if(head == NULL) { head = newNode; return; }
        Node* temp = head;
        while(temp->next != NULL) temp = temp->next;
        temp->next = newNode;
    }

    bool search(int val) {
        Node* temp = head;
        while(temp != NULL) {
            if(temp->data == val) return true;
            temp = temp->next;
        }
        return false;
    }

    int count() {
        int c = 0;
        Node* temp = head;
        while(temp != NULL) { c++; temp = temp->next; }
        return c;
    }

    void reverse() {
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;
        while(curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    void display() {
        Node* temp = head;
        while(temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    LinkedList ll;
    ll.insert(10);
    ll.insert(20);
    ll.insert(30);
    ll.insert(40);
    ll.insert(50);

    cout << "Original: ";
    ll.display();
    cout << "Count: " << ll.count() << endl;

    cout << "Search 30: " << (ll.search(30) ? "Found" : "Not Found") << endl;
    cout << "Search 99: " << (ll.search(99) ? "Found" : "Not Found") << endl;

    ll.reverse();
    cout << "Reversed: ";
    ll.display();

    return 0;
}