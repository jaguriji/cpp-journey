#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class CircularList {
    Node* head;
public:
    CircularList() { head = NULL; }

    void insert(int val) {
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = NULL;
        if(head == NULL) {
            head = newNode;
            newNode->next = head;
            return;
        }
        Node* temp = head;
        while(temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }

    int josephus(int k) {
        Node* curr = head;
        Node* prev = NULL;

        while(head->next != head) {
            for(int i = 1; i < k; i++) {
                prev = curr;
                curr = curr->next;
            }
            cout << "Eliminated: " << curr->data << endl;

            if(curr == head) head = curr->next;
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        }
        return head->data;
    }
};

int main() {
    int n, k;
    cout << "Enter number of people: ";
    cin >> n;
    cout << "Enter step count k: ";
    cin >> k;

    CircularList cl;
    for(int i = 1; i <= n; i++)
        cl.insert(i);

    cout << "\nElimination order:" << endl;
    int winner = cl.josephus(k);
    cout << "Winner: " << winner << endl;

    return 0;
}