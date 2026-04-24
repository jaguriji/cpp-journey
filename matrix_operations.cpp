#include<iostream>
using namespace std;

void inputMatrix(int mat[][3], int n) {
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> mat[i][j];
        }
}

void displayMatrix(int mat[][3], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
}

void addMatrix(int a[][3], int b[][3], int n) {
    int result[3][3];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            result[i][j] = a[i][j] + b[i][j];
    cout << "Addition Result:" << endl;
    displayMatrix(result, n);
}

void multiplyMatrix(int a[][3], int b[][3], int n) {
    int result[3][3] = {0};
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            for(int k = 0; k < n; k++)
                result[i][j] += a[i][k] * b[k][j];
    cout << "Multiplication Result:" << endl;
    displayMatrix(result, n);
}

int main() {
    int n;
    cout << "Enter matrix size (2 or 3): ";
    cin >> n;

    int a[3][3], b[3][3];
    cout << "Enter Matrix A:" << endl;
    inputMatrix(a, n);
    cout << "Enter Matrix B:" << endl;
    inputMatrix(b, n);

    addMatrix(a, b, n);
    multiplyMatrix(a, b, n);

    return 0;
}