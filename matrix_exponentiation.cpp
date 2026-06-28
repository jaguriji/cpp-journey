#include<iostream>
using namespace std;

#define MOD 1000000007

struct Matrix {
    long long a[2][2];
    Matrix() { a[0][0]=a[0][1]=a[1][0]=a[1][1]=0; }
};

Matrix multiply(Matrix A, Matrix B) {
    Matrix C;
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            for(int k = 0; k < 2; k++)
                C.a[i][j] = (C.a[i][j] + A.a[i][k] * B.a[k][j]) % MOD;
    return C;
}

Matrix matPow(Matrix M, long long p) {
    Matrix result;
    result.a[0][0] = result.a[1][1] = 1;
    while(p > 0) {
        if(p & 1) result = multiply(result, M);
        M = multiply(M, M);
        p >>= 1;
    }
    return result;
}

long long fibonacci(long long n) {
    if(n <= 1) return n;
    Matrix M;
    M.a[0][0]=1; M.a[0][1]=1;
    M.a[1][0]=1; M.a[1][1]=0;
    Matrix result = matPow(M, n-1);
    return result.a[0][0];
}

long long fastPower(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;
    while(exp > 0) {
        if(exp & 1) result = result * base % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    return result;
}

int main() {
    cout << "--- Fibonacci using Matrix Exponentiation ---" << endl;
    long long n;
    cout << "Enter n: ";
    cin >> n;
    cout << "Fibonacci(" << n << ") = " << fibonacci(n) << endl;

    cout << "\nFibonacci series (first 15):" << endl;
    for(int i = 0; i <= 15; i++)
        cout << "F(" << i << ") = " << fibonacci(i) << endl;

    cout << "\n--- Fast Power ---" << endl;
    long long base, exp, mod;
    cout << "Enter base exp mod: ";
    cin >> base >> exp >> mod;
    cout << base << "^" << exp << " mod " << mod << " = " << fastPower(base, exp, mod) << endl;

    cout << "\n--- Examples ---" << endl;
    cout << "2^10 mod 1000 = " << fastPower(2, 10, 1000) << endl;
    cout << "3^100 mod 1e9+7 = " << fastPower(3, 100, MOD) << endl;

    return 0;
}