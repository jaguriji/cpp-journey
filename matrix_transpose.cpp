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

void transpose(int mat[][3], int result[][3], int n) {
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            result[j][i] = mat[i][j];
}

bool isSymmetric(int mat[][3], int n) {
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(mat[i][j] != mat[j][i]) return false;
    return true;
}

int main() {
    int n;
    cout << "Enter matrix size (2 or 3): ";
    cin >> n;

    int mat[3][3], result[3][3];
    cout << "Enter Matrix:" << endl;
    inputMatrix(mat, n);

    cout << "\nOriginal Matrix:" << endl;
    displayMatrix(mat, n);

    transpose(mat, result, n);
    cout << "\nTransposed Matrix:" << endl;
    displayMatrix(result, n);

    if(isSymmetric(mat, n))
        cout << "\nMatrix is Symmetric" << endl;
    else
        cout << "\nMatrix is not Symmetric" << endl;

    return 0;
}