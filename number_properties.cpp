#include<iostream>
using namespace std;

bool isArmstrong(int n) {
    int temp = n, sum = 0, digits = 0;
    while(temp != 0) { digits++; temp /= 10; }
    temp = n;
    while(temp != 0) {
        int d = temp % 10;
        int power = 1;
        for(int i = 0; i < digits; i++) power *= d;
        sum += power;
        temp /= 10;
    }
    return sum == n;
}

bool isPerfect(int n) {
    int sum = 0;
    for(int i = 1; i < n; i++)
        if(n % i == 0) sum += i;
    return sum == n;
}

int factorial(int n) {
    if(n == 0 || n == 1) return 1;
    return n * factorial(n - 1);
}

bool isStrong(int n) {
    int temp = n, sum = 0;
    while(temp != 0) {
        sum += factorial(temp % 10);
        temp /= 10;
    }
    return sum == n;
}

int main() {
    cout << "--- Armstrong Numbers (1-999) ---" << endl;
    for(int i = 1; i <= 999; i++)
        if(isArmstrong(i)) cout << i << " ";
    cout << endl;

    cout << "\n--- Perfect Numbers (1-1000) ---" << endl;
    for(int i = 1; i <= 1000; i++)
        if(isPerfect(i)) cout << i << " ";
    cout << endl;

    cout << "\n--- Strong Numbers (1-1000) ---" << endl;
    for(int i = 1; i <= 1000; i++)
        if(isStrong(i)) cout << i << " ";
    cout << endl;

    int n;
    cout << "\nEnter a number to check all properties: ";
    cin >> n;
    cout << n << " is" << (isArmstrong(n) ? "" : " not") << " Armstrong" << endl;
    cout << n << " is" << (isPerfect(n) ? "" : " not") << " Perfect" << endl;
    cout << n << " is" << (isStrong(n) ? "" : " not") << " Strong" << endl;

    return 0;
}