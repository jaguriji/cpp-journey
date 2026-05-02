#include<iostream>
using namespace std;

class Complex {
    double real;
    double imag;
public:
    Complex(double r = 0, double i = 0) {
        real = r;
        imag = i;
    }
    Complex operator+(Complex c) {
        return Complex(real + c.real, imag + c.imag);
    }
    Complex operator-(Complex c) {
        return Complex(real - c.real, imag - c.imag);
    }
    Complex operator*(Complex c) {
        return Complex(real * c.real - imag * c.imag,
                       real * c.imag + imag * c.real);
    }
    bool operator==(Complex c) {
        return real == c.real && imag == c.imag;
    }
    void display() {
        if(imag >= 0)
            cout << real << " + " << imag << "i" << endl;
        else
            cout << real << " - " << -imag << "i" << endl;
    }
};

int main() {
    Complex c1(3, 4), c2(1, -2);

    cout << "C1: "; c1.display();
    cout << "C2: "; c2.display();

    Complex c3 = c1 + c2;
    cout << "C1 + C2: "; c3.display();

    Complex c4 = c1 - c2;
    cout << "C1 - C2: "; c4.display();

    Complex c5 = c1 * c2;
    cout << "C1 * C2: "; c5.display();

    if(c1 == c2)
        cout << "C1 and C2 are equal" << endl;
    else
        cout << "C1 and C2 are not equal" << endl;

    return 0;
}