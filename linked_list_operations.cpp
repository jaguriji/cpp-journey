#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
    Node* head;
public:
    LinkedList() {
        head = NULL;
    }

    void insertAtFront(int val) {
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = head;
        head = newNode;
        cout << "Inserted " << val << " at front" << endl;
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = NULL;
        if(head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        cout << "Inserted " << val << " at end" << endl;
    }

    void deleteNode(int val) {
        if(head == NULL) {
            cout << "List is empty" << endl;
            return;
        }
        if(head->data == val) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Deleted " << val << endl;
            return;
        }
        Node* temp = head;
        while(temp->next != NULL && temp->next->data != val) {
            temp = temp->next;
        }
        if(temp->next == NULL) {
            cout << "Value not found" << endl;
            return;
        }
        Node* toDelete = temp->next;
        temp->next = toDelete->next;
        delete toDelete;
        cout << "Deleted " << val << endl;
    }

    void display() {
        if(head == NULL) {
            cout << "List is empty" << endl;
            return;
        }
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
    ll.insertAtEnd(10);
    ll.insertAtEnd(20);
    ll.insertAtEnd(30);
    ll.insertAtFront(5);
    ll.display();
    ll.deleteNode(20);
    ll.display();
    ll.deleteNode(5);
    ll.display();
    return 0;
}