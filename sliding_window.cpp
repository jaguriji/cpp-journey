#include<iostream>
using namespace std;

int maxSumWindow(int arr[], int n, int k) {
    if(k > n) { cout << "k larger than array" << endl; return -1; }

    int windowSum = 0;
    for(int i = 0; i < k; i++)
        windowSum += arr[i];

    int maxSum = windowSum;
    int start = 0;

    for(int i = k; i < n; i++) {
        windowSum += arr[i] - arr[i-k];
        if(windowSum > maxSum) {
            maxSum = windowSum;
            start = i - k + 1;
        }
    }

    cout << "Max sum subarray of size " << k << ": ";
    for(int i = start; i < start+k; i++)
        cout << arr[i] << " ";
    cout << endl;
    cout << "Max sum: " << maxSum << endl;
    return maxSum;
}

int minSumWindow(int arr[], int n, int k) {
    int windowSum = 0;
    for(int i = 0; i < k; i++)
        windowSum += arr[i];

    int minSum = windowSum;
    for(int i = k; i < n; i++) {
        windowSum += arr[i] - arr[i-k];
        if(windowSum < minSum) minSum = windowSum;
    }
    cout << "Min sum: " << minSum << endl;
    return minSum;
}

double maxAvgWindow(int arr[], int n, int k) {
    int windowSum = 0;
    for(int i = 0; i < k; i++)
        windowSum += arr[i];

    int maxSum = windowSum;
    for(int i = k; i < n; i++) {
        windowSum += arr[i] - arr[i-k];
        if(windowSum > maxSum) maxSum = windowSum;
    }
    double avg = (double)maxSum / k;
    cout << "Max average: " << avg << endl;
    return avg;
}

int main() {
    int n, k;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Enter window size k: ";
    cin >> k;

    cout << endl;
    maxSumWindow(arr, n, k);
    minSumWindow(arr, n, k);
    maxAvgWindow(arr, n, k);

    cout << "\n--- Example ---" << endl;
    int ex[] = {2, 1, 5, 1, 3, 2};
    cout << "Array: 2 1 5 1 3 2, k=3" << endl;
    maxSumWindow(ex, 6, 3);

    return 0;
}
