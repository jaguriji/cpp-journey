#include<iostream>
using namespace std;

void display(int arr[], int n) {
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void dutchFlag(int arr[], int n) {
    int low = 0, mid = 0, high = n-1;

    while(mid <= high) {
        if(arr[mid] == 0) {
            swap(arr[low], arr[mid]);
            low++; mid++;
        } else if(arr[mid] == 1) {
            mid++;
        } else {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

void countingMethod(int arr[], int n) {
    int count[3] = {0};
    for(int i = 0; i < n; i++) count[arr[i]]++;
    int k = 0;
    for(int i = 0; i < 3; i++)
        while(count[i]-- > 0)
            arr[k++] = i;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n], temp[n];
    cout << "Enter elements (only 0, 1, 2): ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        temp[i] = arr[i];
    }

    cout << "Original: ";
    display(arr, n);

    cout << "\n--- Dutch National Flag (One Pass) ---" << endl;
    dutchFlag(arr, n);
    cout << "Sorted: ";
    display(arr, n);

    cout << "\n--- Counting Method ---" << endl;
    countingMethod(temp, n);
    cout << "Sorted: ";
    display(temp, n);

    cout << "\n--- Example ---" << endl;
    int ex[] = {0, 1, 2, 0, 1, 2, 1, 0};
    cout << "Original: 0 1 2 0 1 2 1 0" << endl;
    dutchFlag(ex, 8);
    cout << "Sorted: ";
    display(ex, 8);

    return 0;
}