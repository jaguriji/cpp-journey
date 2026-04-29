#include<iostream>
#include<stdexcept>
using namespace std;

double divide(double a, double b) {
    if(b == 0)
        throw runtime_error("Division by zero is not allowed");
    return a / b;
}

int getPositive(int n) {
    if(n < 0)
        throw invalid_argument("Number must be positive");
    return n;
}

int arrayAccess(int arr[], int size, int index) {
    if(index < 0 || index >= size)
        throw out_of_range("Index out of bounds");
    return arr[index];
}

int main() {
    // Division
    try {
        cout << "10 / 2 = " << divide(10, 2) << endl;
        cout << "10 / 0 = " << divide(10, 0) << endl;
    } catch(runtime_error& e) {
        cout << "Error: " << e.what() << endl;
    }

    // Positive check
    try {
        cout << "Positive check (5): " << getPositive(5) << endl;
        cout << "Positive check (-3): " << getPositive(-3) << endl;
    } catch(invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }

    // Array access
    int arr[] = {10, 20, 30, 40, 50};
    try {
        cout << "arr[2] = " << arrayAccess(arr, 5, 2) << endl;
        cout << "arr[10] = " << arrayAccess(arr, 5, 10) << endl;
    } catch(out_of_range& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}