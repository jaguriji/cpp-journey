#include<iostream>
using namespace std;

class ClassB;

class ClassA {
    int numA;
public:
    ClassA(int n) { numA = n; }
    friend int addNumbers(ClassA, ClassB);
};

class ClassB {
    int numB;
public:
    ClassB(int n) { numB = n; }
    friend int addNumbers(ClassA, ClassB);
};

int addNumbers(ClassA a, ClassB b) {
    return a.numA + b.numB;
}

class Box {
    double length;
    double width;
public:
    Box(double l, double w) {
        length = l;
        width = w;
    }
    friend double area(Box b);
    friend bool isLarger(Box b1, Box b2);
};

double area(Box b) {
    return b.length * b.width;
}

bool isLarger(Box b1, Box b2) {
    return (b1.length * b1.width) > (b2.length * b2.width);
}

int main() {
    ClassA a(10);
    ClassB b(20);
    cout << "Sum: " << addNumbers(a, b) << endl;

    Box box1(5.0, 3.0), box2(4.0, 4.0);
    cout << "Area of Box1: " << area(box1) << endl;
    cout << "Area of Box2: " << area(box2) << endl;
    if(isLarger(box1, box2))
        cout << "Box1 is larger" << endl;
    else
        cout << "Box2 is larger" << endl;

    return 0;
}