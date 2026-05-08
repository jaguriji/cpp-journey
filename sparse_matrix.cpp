#include<iostream>
using namespace std;

void displaySparse(int sparse[][3], int size) {
    cout << "Row\tCol\tValue" << endl;
    for(int i = 0; i < size; i++)
        cout << sparse[i][0] << "\t" << sparse[i][1] << "\t" << sparse[i][2] << endl;
}

void transposeSparse(int sparse[][3], int size, int result[][3]) {
    result[0][0] = sparse[0][1];
    result[0][1] = sparse[0][0];
    result[0][2] = sparse[0][2];

    for(int i = 1; i < size; i++) {
        result[i][0] = sparse[i][1];
        result[i][1] = sparse[i][0];
        result[i][2] = sparse[i][2];
    }
}

int main() {
    int matrix[4][4] = {
        {0, 0, 3, 0},
        {0, 0, 0, 0},
        {5, 0, 0, 2},
        {0, 0, 0, 0}
    };

    cout << "Original Matrix:" << endl;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }

    int nonZero = 0;
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            if(matrix[i][j] != 0) nonZero++;

    int sparse[nonZero + 1][3];
    sparse[0][0] = 4;
    sparse[0][1] = 4;
    sparse[0][2] = nonZero;

    int k = 1;
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            if(matrix[i][j] != 0) {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = matrix[i][j];
                k++;
            }

    cout << "\nSparse Representation:" << endl;
    displaySparse(sparse, nonZero + 1);

    int result[nonZero + 1][3];
    transposeSparse(sparse, nonZero + 1, result);
    cout << "\nTransposed Sparse:" << endl;
    displaySparse(result, nonZero + 1);

    return 0;
}