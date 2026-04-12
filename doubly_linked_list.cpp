#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
    Node* head;
public:
    DoublyLinkedList() {
        head = NULL;
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = NULL;
        newNode->prev = NULL;
        if(head == NULL) {
            head = newNode;
            cout << "Inserted " << val << endl;
            return;
        }
        Node* temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
        cout << "Inserted " << val << endl;
    }

    void deleteNode(int val) {
        if(head == NULL) {
            cout << "List is empty" << endl;
            return;
        }
        Node* temp = head;
        while(temp != NULL && temp->data != val) {
            temp = temp->next;
        }
        if(temp == NULL) {
            cout << "Value not found" << endl;
            return;
        }
        if(temp->prev != NULL) temp->prev->next = temp->next;
        else head = temp->next;
        if(temp->next != NULL) temp->next->prev = temp->prev;
        delete temp;
        cout << "Deleted " << val << endl;
    }

    void display() {
        if(head == NULL) {
            cout << "List is empty" << endl;
            return;
        }
        Node* temp = head;
        while(temp != NULL) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void reverseDisplay() {
        if(head == NULL) {
            cout << "List is empty" << endl;
            return;
        }
        Node* temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        while(temp != NULL) {
            cout << temp->data << " <-> ";
            temp = temp->prev;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    DoublyLinkedList dll;
    dll.insertAtEnd(10);
    dll.insertAtEnd(20);
    dll.insertAtEnd(30);
    dll.insertAtEnd(40);
    dll.display();
    dll.reverseDisplay();
    dll.deleteNode(20);
    dll.display();
    return 0;
}