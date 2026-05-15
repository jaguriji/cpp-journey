#include<iostream>
using namespace std;

struct Stack {
    int arr[100];
    int top;
    Stack() { top = -1; }
    void push(int n) { arr[++top] = n; }
    int pop() { return arr[top--]; }
    int peek() { return arr[top]; }
    bool isEmpty() { return top == -1; }
};

void nextGreater(int arr[], int n) {
    int result[n];
    Stack s;

    for(int i = n-1; i >= 0; i--) {
        while(!s.isEmpty() && s.peek() <= arr[i])
            s.pop();
        result[i] = s.isEmpty() ? -1 : s.peek();
        s.push(arr[i]);
    }

    cout << "Element\tNext Greater" << endl;
    for(int i = 0; i < n; i++)
        cout << arr[i] << "\t" << result[i] << endl;
}

void nextGreaterCircular(int arr[], int n) {
    int result[n];
    for(int i = 0; i < n; i++) result[i] = -1;
    Stack s;

    for(int i = 2*n-1; i >= 0; i--) {
        while(!s.isEmpty() && s.peek() <= arr[i % n])
            s.pop();
        if(i < n) result[i] = s.isEmpty() ? -1 : s.peek();
        s.push(arr[i % n]);
    }

    cout << "\nCircular Next Greater:" << endl;
    cout << "Element\tNext Greater" << endl;
    for(int i = 0; i < n; i++)
        cout << arr[i] << "\t" << result[i] << endl;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    nextGreater(arr, n);
    nextGreaterCircular(arr, n);

    return 0;
}