#include<iostream>
using namespace std;

int knapsack(int weights[], int values[], int n, int capacity) {
    int dp[n+1][capacity+1];

    for(int i = 0; i <= n; i++) {
        for(int w = 0; w <= capacity; w++) {
            if(i == 0 || w == 0)
                dp[i][w] = 0;
            else if(weights[i-1] <= w)
                dp[i][w] = max(values[i-1] + dp[i-1][w-weights[i-1]], dp[i-1][w]);
            else
                dp[i][w] = dp[i-1][w];
        }
    }

    // backtrack to find selected items
    cout << "Selected items:" << endl;
    int w = capacity;
    for(int i = n; i > 0; i--) {
        if(dp[i][w] != dp[i-1][w]) {
            cout << "Item " << i << " (weight=" << weights[i-1] << ", value=" << values[i-1] << ")" << endl;
            w -= weights[i-1];
        }
    }

    return dp[n][capacity];
}

int main() {
    int n, capacity;
    cout << "Enter number of items: ";
    cin >> n;
    int weights[n], values[n];
    cout << "Enter weights: ";
    for(int i = 0; i < n; i++) cin >> weights[i];
    cout << "Enter values: ";
    for(int i = 0; i < n; i++) cin >> values[i];
    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    int maxVal = knapsack(weights, values, n, capacity);
    cout << "Maximum value: " << maxVal << endl;

    cout << "\n--- Example ---" << endl;
    int w[] = {2, 3, 4, 5};
    int v[] = {3, 4, 5, 6};
    cout << "Weights: 2 3 4 5 | Values: 3 4 5 6 | Capacity: 5" << endl;
    cout << "Maximum value: " << knapsack(w, v, 4, 5) << endl;

    return 0;
}
