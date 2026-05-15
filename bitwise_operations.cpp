#include<iostream>
using namespace std;

void printBinary(int n) {
    if(n == 0) { cout << "0"; return; }
    string result = "";
    int temp = n;
    while(temp > 0) {
        result = to_string(temp % 2) + result;
        temp /= 2;
    }
    cout << result;
}

bool isEven(int n) { return (n & 1) == 0; }
bool isPowerOfTwo(int n) { return n > 0 && (n & (n-1)) == 0; }
int countSetBits(int n) {
    int count = 0;
    while(n) { count += n & 1; n >>= 1; }
    return count;
}
int swapBits(int a, int b) { a ^= b; b ^= a; a ^= b; return a; }

int main() {
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;

    cout << "\na = " << a << " ("; printBinary(a); cout << ")" << endl;
    cout << "b = " << b << " ("; printBinary(b); cout << ")" << endl;

    cout << "\n--- Basic Operations ---" << endl;
    cout << "a & b  = " << (a & b) << endl;
    cout << "a | b  = " << (a | b) << endl;
    cout << "a ^ b  = " << (a ^ b) << endl;
    cout << "~a     = " << (~a) << endl;
    cout << "a << 1 = " << (a << 1) << endl;
    cout << "a >> 1 = " << (a >> 1) << endl;

    cout << "\n--- Bit Tricks ---" << endl;
    cout << a << " is " << (isEven(a) ? "Even" : "Odd") << endl;
    cout << a << " is " << (isPowerOfTwo(a) ? "" : "not ") << "power of 2" << endl;
    cout << "Set bits in " << a << ": " << countSetBits(a) << endl;

    cout << "\n--- Swap without temp ---" << endl;
    cout << "Before: a=" << a << " b=" << b << endl;
    a ^= b; b ^= a; a ^= b;
    cout << "After:  a=" << a << " b=" << b << endl;

    return 0;
}