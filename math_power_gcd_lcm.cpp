#include<iostream>
using namespace std;

int power(int base, int exp) {
    if(exp == 0) return 1;
    return base * power(base, exp - 1);
}

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main() {
    int base, exp;
    cout << "Enter base and exponent: ";
    cin >> base >> exp;
    cout << base << "^" << exp << " = " << power(base, exp) << endl;

    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    cout << "GCD of " << a << " and " << b << " = " << gcd(a, b) << endl;
    cout << "LCM of " << a << " and " << b << " = " << lcm(a, b) << endl;

    return 0;
}