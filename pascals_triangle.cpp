#include<iostream>
using namespace std;

int binomial(int n, int k) {
    if(k == 0 || k == n) return 1;
    return binomial(n-1, k-1) + binomial(n-1, k);
}

void printPascal(int rows) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < rows-i; j++)
            cout << "  ";
        for(int j = 0; j <= i; j++)
            cout << binomial(i, j) << "   ";
        cout << endl;
    }
}

void printFlat(int rows) {
    int triangle[20][20];
    for(int i = 0; i < rows; i++) {
        triangle[i][0] = 1;
        triangle[i][i] = 1;
        for(int j = 1; j < i; j++)
            triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j];
    }
    cout << "Pascal's Triangle:" << endl;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j <= i; j++)
            cout << triangle[i][j] << " ";
        cout << endl;
    }

    cout << "\nRow sums (powers of 2):" << endl;
    for(int i = 0; i < rows; i++) {
        int sum = 0;
        for(int j = 0; j <= i; j++)
            sum += triangle[i][j];
        cout << "Row " << i << ": " << sum << endl;
    }
}

int main() {
    int rows;
    cout << "Enter number of rows: ";
    cin >> rows;

    cout << "\n--- Pyramid Shape ---" << endl;
    printPascal(rows);

    cout << endl;
    printFlat(rows);

    return 0;
}
