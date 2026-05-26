#include<iostream>
using namespace std;

void shellSort(int arr[], int n) {
    for(int gap = n/2; gap > 0; gap /= 2) {
        for(int i = gap; i < n; i++) {
            int temp = arr[i];
            int j = i;
            while(j >= gap && arr[j-gap] > temp) {
                arr[j] = arr[j-gap];
                j -= gap;
            }
            arr[j] = temp;
        }
        cout << "Gap " << gap << ": ";
        for(int i = 0; i < n; i++) cout << arr[i] << " ";
        cout << endl;
    }
}

void display(int arr[], int n) {
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) cin >> arr[i];

    cout << "Before: ";
    display(arr, n);
    cout << "\nStep by step:" << endl;
    shellSort(arr, n);
    cout << "\nAfter: ";
    display(arr, n);

    cout << "\n--- Example ---" << endl;
    int ex[] = {12, 34, 54, 2, 3, 45, 23};
    cout << "Array: 12 34 54 2 3 45 23" << endl;
    cout << "Before: "; display(ex, 7);
    shellSort(ex, 7);
    cout << "After: "; display(ex, 7);

    return 0;
}