#include<iostream>
using namespace std;

void display(int arr[], int n) {
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void rotateLeft(int arr[], int n, int k) {
    k = k % n;
    int temp[k];
    for(int i = 0; i < k; i++) temp[i] = arr[i];
    for(int i = 0; i < n-k; i++) arr[i] = arr[i+k];
    for(int i = 0; i < k; i++) arr[n-k+i] = temp[i];
}

void rotateRight(int arr[], int n, int k) {
    k = k % n;
    int temp[k];
    for(int i = 0; i < k; i++) temp[i] = arr[n-k+i];
    for(int i = n-1; i >= k; i--) arr[i] = arr[i-k];
    for(int i = 0; i < k; i++) arr[i] = temp[i];
}

void reverse(int arr[], int start, int end) {
    while(start < end) {
        swap(arr[start], arr[end]);
        start++; end--;
    }
}

void rotateLeftOptimal(int arr[], int n, int k) {
    k = k % n;
    reverse(arr, 0, k-1);
    reverse(arr, k, n-1);
    reverse(arr, 0, n-1);
}

int main() {
    int n, k;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n], temp[n];
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        temp[i] = arr[i];
    }
    cout << "Enter k (positions to rotate): ";
    cin >> k;

    cout << "Original: ";
    display(arr, n);

    rotateLeft(arr, n, k);
    cout << "Left rotate by " << k << ": ";
    display(arr, n);

    for(int i = 0; i < n; i++) arr[i] = temp[i];
    rotateRight(arr, n, k);
    cout << "Right rotate by " << k << ": ";
    display(arr, n);

    for(int i = 0; i < n; i++) arr[i] = temp[i];
    rotateLeftOptimal(arr, n, k);
    cout << "Left rotate (optimal): ";
    display(arr, n);

    return 0;
} 