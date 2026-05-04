#include<iostream>
using namespace std;

void increment(int* ptr) {
    (*ptr)++;
}

void swapPointers(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int largest(int* arr, int n) {
    int max = *arr;
    for(int i = 1; i < n; i++) {
        if(*(arr + i) > max)
            max = *(arr + i);
    }
    return max;
}

int main() {
    int x = 10;
    int* ptr = &x;
    cout << "Value: " << x << endl;
    cout << "Address: " << ptr << endl;
    cout << "Value via pointer: " << *ptr << endl;

    increment(ptr);
    cout << "After increment: " << x << endl;

    int a = 5, b = 20;
    cout << "\nBefore swap: a=" << a << " b=" << b << endl;
    swapPointers(&a, &b);
    cout << "After swap: a=" << a << " b=" << b << endl;

    int arr[] = {3, 7, 1, 9, 4};
    int n = 5;
    cout << "\nArray using pointer arithmetic: ";
    for(int i = 0; i < n; i++)
        cout << *(arr + i) << " ";
    cout << endl;
    cout << "Largest: " << largest(arr, n) << endl;

    return 0;
}