#include<iostream>
using namespace std;

int sumDigits(int n) {
    if(n == 0) return 0;
    return n % 10 + sumDigits(n / 10);
}

int power(int base, int exp) {
    if(exp == 0) return 1;
    return base * power(base, exp - 1);
}

void towerOfHanoi(int n, char from, char to, char aux) {
    if(n == 1) {
        cout << "Move disk 1 from " << from << " to " << to << endl;
        return;
    }
    towerOfHanoi(n - 1, from, aux, to);
    cout << "Move disk " << n << " from " << from << " to " << to << endl;
    towerOfHanoi(n - 1, aux, to, from);
}

int fibonacci(int n) {
    if(n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    cout << "--- Sum of Digits ---" << endl;
    cout << "Sum of digits of 1234: " << sumDigits(1234) << endl;

    cout << "\n--- Power ---" << endl;
    cout << "2^8 = " << power(2, 8) << endl;

    cout << "\n--- Fibonacci ---" << endl;
    cout << "Fibonacci series: ";
    for(int i = 0; i < 8; i++)
        cout << fibonacci(i) << " ";
    cout << endl;

    cout << "\n--- Tower of Hanoi (3 disks) ---" << endl;
    towerOfHanoi(3, 'A', 'C', 'B');

    return 0;
}