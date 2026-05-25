#include<iostream>
using namespace std;

int matrixChain(int dims[], int n) {
    int dp[n][n];
    for(int i = 0; i < n; i++) dp[i][i] = 0;

    for(int len = 2; len < n; len++) {
        for(int i = 1; i < n-len+1; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for(int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k+1][j] + dims[i-1]*dims[k]*dims[j];
                if(cost < dp[i][j]) dp[i][j] = cost;
            }
        }
    }

    cout << "Minimum multiplications: " << dp[1][n-1] << endl;
    return dp[1][n-1];
}

void printOrder(int split[][10], int i, int j) {
    if(i == j) { cout << "M" << i; return; }
    cout << "(";
    printOrder(split, i, split[i][j]);
    printOrder(split, split[i][j]+1, j);
    cout << ")";
}

int matrixChainOrder(int dims[], int n) {
    int dp[10][10] = {0};
    int split[10][10] = {0};

    for(int len = 2; len < n; len++) {
        for(int i = 1; i < n-len+1; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for(int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k+1][j] + dims[i-1]*dims[k]*dims[j];
                if(cost < dp[i][j]) {
                    dp[i][j] = cost;
                    split[i][j] = k;
                }
            }
        }
    }

    cout << "Optimal order: ";
    printOrder(split, 1, n-1);
    cout << endl;
    return dp[1][n-1];
}

int main() {
    int n;
    cout << "Enter number of matrices: ";
    cin >> n;
    int dims[n+1];
    cout << "Enter dimensions (" << n+1 << " values): ";
    for(int i = 0; i <= n; i++) cin >> dims[i];

    matrixChain(dims, n+1);
    matrixChainOrder(dims, n+1);

    cout << "\n--- Example ---" << endl;
    int d[] = {1, 2, 3, 4};
    cout << "Matrices: 1x2, 2x3, 3x4" << endl;
    matrixChain(d, 4);
    matrixChainOrder(d, 4);

    return 0;
}