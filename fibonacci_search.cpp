#include<iostream>
using namespace std;

int fibonacciSearch(int arr[], int n, int target) {
    int fib2 = 0, fib1 = 1, fib = 1;

    while(fib < n) {
        fib2 = fib1;
        fib1 = fib;
        fib = fib1 + fib2;
    }

    int offset = -1;

    while(fib > 1) {
        int i = min(offset + fib2, n-1);

        if(arr[i] < target) {
            fib = fib1;
            fib1 = fib2;
            fib2 = fib - fib1;
            offset = i;
        } else if(arr[i] > target) {
            fib = fib2;
            fib1 = fib1 - fib2;
            fib2 = fib - fib1;
        } else {
            return i;
        }
    }

    if(fib1 && arr[offset+1] == target)
        return offset + 1;

    return -1;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements in sorted order: ";
    for(int i = 0; i < n; i++) cin >> arr[i];

    int target;
    cout << "Enter element to search: ";
    cin >> target;

    int result = fibonacciSearch(arr, n, target);
    if(result != -1)
        cout << "Found at index " << result << " (position " << result+1 << ")" << endl;
    else
        cout << "Element not found" << endl;

    cout << "\n--- Example ---" << endl;
    int ex[] = {10, 22, 35, 40, 45, 50, 80, 82, 85, 90, 100};
    int m = 11;
    cout << "Array: 10 22 35 40 45 50 80 82 85 90 100" << endl;
    int targets[] = {40, 85, 99};
    for(int t : targets) {
        int r = fibonacciSearch(ex, m, t);
        cout << "Search " << t << ": ";
        if(r != -1) cout << "Found at index " << r << endl;
        else cout << "Not found" << endl;
    }

    return 0;
}