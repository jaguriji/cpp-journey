#include<iostream>
using namespace std;

void display(int arr[], int n) {
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

void mergeWithSpace(int a[], int m, int b[], int n) {
    int result[m+n];
    int i = 0, j = 0, k = 0;
    while(i < m && j < n) {
        if(a[i] <= b[j]) result[k++] = a[i++];
        else result[k++] = b[j++];
    }
    while(i < m) result[k++] = a[i++];
    while(j < n) result[k++] = b[j++];

    cout << "Merged array: ";
    display(result, m+n);
}

void mergeWithoutSpace(int a[], int m, int b[], int n) {
    for(int i = m-1; i >= 0; i--) {
        int last = b[n-1];
        if(a[i] > b[n-1]) {
            int j = n-2;
            while(j >= 0 && b[j] > a[i]) {
                b[j+1] = b[j];
                j--;
            }
            b[j+1] = a[i];
            a[i] = last;
        }
    }
    cout << "Array 1: "; display(a, m);
    cout << "Array 2: "; display(b, n);
}

int main() {
    int m, n;
    cout << "Enter size of first sorted array: ";
    cin >> m;
    int a[m];
    cout << "Enter elements: ";
    for(int i = 0; i < m; i++) cin >> a[i];

    cout << "Enter size of second sorted array: ";
    cin >> n;
    int b[n], temp[n];
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) { cin >> b[i]; temp[i] = b[i]; }

    cout << "\n--- With Extra Space ---" << endl;
    mergeWithSpace(a, m, temp, n);

    cout << "\n--- Without Extra Space ---" << endl;
    mergeWithoutSpace(a, m, b, n);

    return 0;
}
