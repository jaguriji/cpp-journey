#include<iostream>
using namespace std;

int kadane(int arr[], int n) {
    int maxSum = arr[0];
    int currSum = arr[0];
    int start = 0, end = 0, tempStart = 0;

    for(int i = 1; i < n; i++) {
        if(arr[i] > currSum + arr[i]) {
            currSum = arr[i];
            tempStart = i;
        } else {
            currSum += arr[i];
        }
        if(currSum > maxSum) {
            maxSum = currSum;
            start = tempStart;
            end = i;
        }
    }

    cout << "Max subarray: ";
    for(int i = start; i <= end; i++)
        cout << arr[i] << " ";
    cout << endl;
    cout << "Max sum: " << maxSum << endl;
    return maxSum;
}

int kadaneCircular(int arr[], int n) {
    // max subarray sum normal
    int normalMax = kadane(arr, n);

    // min subarray sum
    int minSum = arr[0], currMin = arr[0];
    int totalSum = arr[0];
    for(int i = 1; i < n; i++) {
        currMin = min(arr[i], currMin + arr[i]);
        minSum = min(minSum, currMin);
        totalSum += arr[i];
    }

    int circularMax = totalSum - minSum;
    cout << "Circular max sum: " << max(normalMax, circularMax) << endl;
    return max(normalMax, circularMax);
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements (can be negative): ";
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "\n--- Kadane's Algorithm ---" << endl;
    kadane(arr, n);

    cout << "\n--- Circular Array ---" << endl;
    kadaneCircular(arr, n);

    cout << "\n--- Examples ---" << endl;
    int ex1[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Array: -2 1 -3 4 -1 2 1 -5 4" << endl;
    kadane(ex1, 9);

    return 0;
}
