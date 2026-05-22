#include<iostream>
using namespace std;

int lis(int arr[], int n) {
    int dp[n];
    for(int i = 0; i < n; i++) dp[i] = 1;

    for(int i = 1; i < n; i++)
        for(int j = 0; j < i; j++)
            if(arr[j] < arr[i] && dp[j]+1 > dp[i])
                dp[i] = dp[j]+1;

    int maxLen = dp[0];
    int maxIdx = 0;
    for(int i = 1; i < n; i++)
        if(dp[i] > maxLen) { maxLen = dp[i]; maxIdx = i; }

    // backtrack to print LIS
    int seq[maxLen];
    int k = maxLen-1;
    seq[k--] = arr[maxIdx];
    for(int i = maxIdx-1; i >= 0 && k >= 0; i--)
        if(arr[i] < arr[maxIdx] && dp[i] == dp[maxIdx]-1) {
            seq[k--] = arr[i];
            maxIdx = i;
        }

    cout << "LIS: ";
    for(int i = 0; i < maxLen; i++) cout << seq[i] << " ";
    cout << endl;
    cout << "LIS Length: " << maxLen << endl;
    return maxLen;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) cin >> arr[i];

    lis(arr, n);

    cout << "\n--- Examples ---" << endl;
    int ex1[] = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << "Array: 10 9 2 5 3 7 101 18" << endl;
    lis(ex1, 8);

    int ex2[] = {0, 1, 0, 3, 2, 3};
    cout << "Array: 0 1 0 3 2 3" << endl;
    lis(ex2, 6);

    return 0;
}
