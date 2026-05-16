#include<iostream>
using namespace std;

void twoSumBrute(int arr[], int n, int target) {
    bool found = false;
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if(arr[i] + arr[j] == target) {
                cout << "Pair found: " << arr[i] << " + " << arr[j] << " = " << target << endl;
                found = true;
            }
        }
    }
    if(!found) cout << "No pair found" << endl;
}

void twoSumTwoPointer(int arr[], int n, int target) {
    int left = 0, right = n-1;
    bool found = false;

    // sort first
    for(int i = 0; i < n-1; i++)
        for(int j = 0; j < n-i-1; j++)
            if(arr[j] > arr[j+1]) swap(arr[j], arr[j+1]);

    while(left < right) {
        int sum = arr[left] + arr[right];
        if(sum == target) {
            cout << "Pair found: " << arr[left] << " + " << arr[right] << " = " << target << endl;
            found = true;
            left++; right--;
        } else if(sum < target) left++;
        else right--;
    }
    if(!found) cout << "No pair found" << endl;
}

int main() {
    int n, target;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n], temp[n];
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        temp[i] = arr[i];
    }
    cout << "Enter target sum: ";
    cin >> target;

    cout << "\n--- Brute Force ---" << endl;
    twoSumBrute(temp, n, target);

    cout << "\n--- Two Pointer ---" << endl;
    twoSumTwoPointer(arr, n, target);

    return 0;
}