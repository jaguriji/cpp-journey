#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class CircularLinkedList {
    Node* head;
public:
    CircularLinkedList() {
        head = NULL;
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = NULL;
        if(head == NULL) {
            head = newNode;
            newNode->next = head;
            cout << "Inserted " << val << endl;
            return;
        }
        Node* temp = head;
        while(temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
        cout << "Inserted " << val << endl;
    }

    void deleteNode(int val) {
        if(head == NULL) {
            cout << "List is empty" << endl;
            return;
        }
        if(head->data == val) {
            if(head->next == head) {
                delete head;
                head = NULL;
                cout << "Deleted " << val << endl;
                return;
            }
            Node* temp = head;
            while(temp->next != head) {
                temp = temp->next;
            }
            temp->next = head->next;
            delete head;
            head = temp->next;
            cout << "Deleted " << val << endl;
            return;
        }
        Node* temp = head;
        while(temp->next != head && temp->next->data != val) {
            temp = temp->next;
        }
        if(temp->next == head) {
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
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while(temp != head);
        cout << "(back to head)" << endl;
    }
};

int main() {
    CircularLinkedList cll;
    cll.insertAtEnd(10);
    cll.insertAtEnd(20);
    cll.insertAtEnd(30);
    cll.insertAtEnd(40);
    cll.display();
    cll.deleteNode(20);
    cll.display();
    cll.deleteNode(10);
    cll.display();
    return 0;
}