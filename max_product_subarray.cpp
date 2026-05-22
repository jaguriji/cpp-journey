#include<iostream>
using namespace std;

int maxProduct(int arr[], int n) {
    int maxProd = arr[0];
    int minProd = arr[0];
    int result = arr[0];
    int start = 0, end = 0, tempStart = 0;

    for(int i = 1; i < n; i++) {
        if(arr[i] < 0) swap(maxProd, minProd);

        maxProd = max(arr[i], maxProd * arr[i]);
        minProd = min(arr[i], minProd * arr[i]);

        if(maxProd > result) {
            result = maxProd;
            end = i;
        }
    }

    cout << "Max product: " << result << endl;
    return result;
}

void allSubarrayProducts(int arr[], int n) {
    cout << "\nAll subarray products:" << endl;
    for(int i = 0; i < n; i++) {
        int prod = 1;
        for(int j = i; j < n; j++) {
            prod *= arr[j];
            cout << "[";
            for(int k = i; k <= j; k++) {
                cout << arr[k];
                if(k < j) cout << ",";
            }
            cout << "] = " << prod << endl;
        }
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements (can be negative): ";
    for(int i = 0; i < n; i++) cin >> arr[i];

    maxProduct(arr, n);

    cout << "\n--- Examples ---" << endl;
    int ex1[] = {2, 3, -2, 4};
    cout << "Array: 2 3 -2 4" << endl;
    maxProduct(ex1, 4);

    int ex2[] = {-2, 0, -1};
    cout << "Array: -2 0 -1" << endl;
    maxProduct(ex2, 3);

    int ex3[] = {-2, 3, -4};
    cout << "Array: -2 3 -4" << endl;
    maxProduct(ex3, 3);

    return 0;
}
