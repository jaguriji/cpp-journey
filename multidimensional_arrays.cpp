#include<iostream>
using namespace std;

void displayMatrix(int mat[][4], int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++)
            cout << mat[i][j] << "\t";
        cout << endl;
    }
}

int diagonalSum(int mat[][4], int n) {
    int sum = 0;
    for(int i = 0; i < n; i++)
        sum += mat[i][i];
    return sum;
}

int rowSum(int mat[][4], int cols, int row) {
    int sum = 0;
    for(int j = 0; j < cols; j++)
        sum += mat[row][j];
    return sum;
}

int colSum(int mat[][4], int rows, int col) {
    int sum = 0;
    for(int i = 0; i < rows; i++)
        sum += mat[i][col];
    return sum;
}

int main() {
    int marks[3][4] = {
        {85, 90, 78, 92},
        {76, 88, 95, 70},
        {91, 83, 87, 89}
    };

    cout << "--- Marks Matrix ---" << endl;
    displayMatrix(marks, 3, 4);

    cout << "\n--- Row Totals ---" << endl;
    for(int i = 0; i < 3; i++)
        cout << "Row " << i+1 << " total: " << rowSum(marks, 4, i) << endl;

    cout << "\n--- Column Totals ---" << endl;
    for(int j = 0; j < 4; j++)
        cout << "Col " << j+1 << " total: " << colSum(marks, 3, j) << endl;

    int square[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    cout << "\n--- Square Matrix ---" << endl;
    displayMatrix(square, 4, 4);
    cout << "Diagonal Sum: " << diagonalSum(square, 4) << endl;

    return 0;
}