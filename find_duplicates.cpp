#include<iostream>
using namespace std;

void display(int arr[], int n) {
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

void findDuplicatesBrute(int arr[], int n) {
    cout << "Duplicates (brute force): ";
    bool found = false;
    for(int i = 0; i < n; i++)
        for(int j = i+1; j < n; j++)
            if(arr[i] == arr[j]) {
                cout << arr[i] << " ";
                found = true;
                break;
            }
    if(!found) cout << "None";
    cout << endl;
}

void findDuplicatesSorting(int arr[], int n) {
    int temp[n];
    for(int i = 0; i < n; i++) temp[i] = arr[i];
    for(int i = 0; i < n-1; i++)
        for(int j = 0; j < n-i-1; j++)
            if(temp[j] > temp[j+1]) swap(temp[j], temp[j+1]);

    cout << "Duplicates (sorting): ";
    bool found = false;
    for(int i = 1; i < n; i++)
        if(temp[i] == temp[i-1]) {
            cout << temp[i] << " ";
            found = true;
        }
    if(!found) cout << "None";
    cout << endl;
}

void findDuplicatesFrequency(int arr[], int n, int maxVal) {
    int freq[maxVal+1] = {0};
    for(int i = 0; i < n; i++) freq[arr[i]]++;

    cout << "Duplicates (frequency): ";
    bool found = false;
    for(int i = 0; i <= maxVal; i++)
        if(freq[i] > 1) { cout << i << "(x" << freq[i] << ") "; found = true; }
    if(!found) cout << "None";
    cout << endl;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) cin >> arr[i];

    findDuplicatesBrute(arr, n);
    findDuplicatesSorting(arr, n);

    int maxVal = arr[0];
    for(int i = 1; i < n; i++) if(arr[i] > maxVal) maxVal = arr[i];
    findDuplicatesFrequency(arr, n, maxVal);

    cout << "\n--- Example ---" << endl;
    int ex[] = {4, 3, 2, 7, 8, 2, 3, 1};
    cout << "Array: 4 3 2 7 8 2 3 1" << endl;
    findDuplicatesBrute(ex, 8);
    findDuplicatesSorting(ex, 8);
    findDuplicatesFrequency(ex, 8, 8);

    return 0;
}
