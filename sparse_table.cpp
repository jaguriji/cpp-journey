#include<iostream>
#include<cmath>
using namespace std;

#define MAXN 100
#define LOG 17

int sparse[MAXN][LOG];
int log2_[MAXN];

void build(int arr[], int n) {
    for(int i = 0; i < n; i++) sparse[i][0] = arr[i];

    for(int j = 1; (1 << j) <= n; j++)
        for(int i = 0; i + (1 << j) - 1 < n; i++)
            sparse[i][j] = min(sparse[i][j-1], sparse[i + (1 << (j-1))][j-1]);

    log2_[1] = 0;
    for(int i = 2; i <= n; i++)
        log2_[i] = log2_[i/2] + 1;
}

int queryMin(int l, int r) {
    int k = log2_[r - l + 1];
    return min(sparse[l][k], sparse[r - (1 << k) + 1][k]);
}

int queryMax(int arr[], int l, int r, int n) {
    int maxVal = arr[l];
    for(int i = l+1; i <= r; i++)
        if(arr[i] > maxVal) maxVal = arr[i];
    return maxVal;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) cin >> arr[i];

    build(arr, n);

    int q;
    cout << "Enter number of queries: ";
    cin >> q;
    while(q--) {
        int l, r;
        cout << "Enter range (l r): ";
        cin >> l >> r;
        cout << "Min [" << l << "," << r << "]: " << queryMin(l, r) << endl;
        cout << "Max [" << l << "," << r << "]: " << queryMax(arr, l, r, n) << endl;
    }

    cout << "\n--- Example ---" << endl;
    int ex[] = {2, 4, 3, 1, 6, 7, 8, 9, 1, 7};
    build(ex, 10);
    cout << "Array: 2 4 3 1 6 7 8 9 1 7" << endl;
    cout << "Min [0,4]: " << queryMin(0, 4) << endl;
    cout << "Min [4,9]: " << queryMin(4, 9) << endl;
    cout << "Min [0,9]: " << queryMin(0, 9) << endl;

    return 0;
}