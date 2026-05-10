#include<iostream>
using namespace std;

void countingSort(int arr[], int n) {
    int max = arr[0];
    for(int i = 1; i < n; i++)
        if(arr[i] > max) max = arr[i];

    int count[max + 1];
    for(int i = 0; i <= max; i++) count[i] = 0;

    for(int i = 0; i < n; i++)
        count[arr[i]]++;

    int k = 0;
    for(int i = 0; i <= max; i++)
        while(count[i]-- > 0)
            arr[k++] = i;
}

void display(int arr[], int n) {
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Before sorting: ";
    display(arr, n);
    countingSort(arr, n);
    cout << "After sorting: ";
    display(arr, n);

    return 0;
}