#include<iostream>
#include<cmath>
using namespace std;

double factorial(int n) {
    if(n == 0) return 1;
    double f = 1;
    for(int i = 1; i <= n; i++) f *= i;
    return f;
}

double sineSum(double x, int terms) {
    double sum = 0;
    for(int i = 0; i < terms; i++) {
        int power = 2 * i + 1;
        double term = pow(x, power) / factorial(power);
        sum += (i % 2 == 0) ? term : -term;
    }
    return sum;
}

double cosineSum(double x, int terms) {
    double sum = 0;
    for(int i = 0; i < terms; i++) {
        int power = 2 * i;
        double term = pow(x, power) / factorial(power);
        sum += (i % 2 == 0) ? term : -term;
    }
    return sum;
}

double expSum(double x, int terms) {
    double sum = 0;
    for(int i = 0; i < terms; i++)
        sum += pow(x, i) / factorial(i);
    return sum;
}

int main() {
    double x;
    int terms;
    cout << "Enter value of x (in radians): ";
    cin >> x;
    cout << "Enter number of terms: ";
    cin >> terms;

    cout << "\nSine(" << x << ")   = " << sineSum(x, terms) << endl;
    cout << "Actual sin(" << x << ") = " << sin(x) << endl;

    cout << "\nCosine(" << x << ")   = " << cosineSum(x, terms) << endl;
    cout << "Actual cos(" << x << ") = " << cos(x) << endl;

    cout << "\nExp(" << x << ")   = " << expSum(x, terms) << endl;
    cout << "Actual e^(" << x << ") = " << exp(x) << endl;

    return 0;
}