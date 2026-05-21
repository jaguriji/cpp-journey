#include<iostream>
using namespace std;

void subarraySum(int arr[], int n, int target) {
    int start = 0, currSum = arr[0];
    bool found = false;

    for(int end = 1; end <= n; end++) {
        while(currSum > target && start < end-1) {
            currSum -= arr[start];
            start++;
        }
        if(currSum == target) {
            cout << "Subarray found from index " << start << " to " << end-1 << ": ";
            for(int i = start; i < end; i++) cout << arr[i] << " ";
            cout << endl;
            found = true;
        }
        if(end < n) currSum += arr[end];
    }
    if(!found) cout << "No subarray found" << endl;
}

void subarraySumNegative(int arr[], int n, int target) {
    cout << "\nAll subarrays with sum " << target << " (brute force):" << endl;
    bool found = false;
    for(int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = i; j < n; j++) {
            sum += arr[j];
            if(sum == target) {
                cout << "Index " << i << " to " << j << ": ";
                for(int k = i; k <= j; k++) cout << arr[k] << " ";
                cout << endl;
                found = true;
            }
        }
    }
    if(!found) cout << "No subarray found" << endl;
}

int main() {
    int n, target;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) cin >> arr[i];
    cout << "Enter target sum: ";
    cin >> target;

    subarraySum(arr, n, target);
    subarraySumNegative(arr, n, target);

    return 0;
}