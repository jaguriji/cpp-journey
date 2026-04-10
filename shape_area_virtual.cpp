#include<iostream>
using namespace std;

class Shape {
protected:
    string color;
public:
    Shape(string c) {
        color = c;
    }
    virtual double area() = 0;
    virtual void display() {
        cout << "Color: " << color << "\nArea: " << area() << endl;
    }
};

class Circle : public Shape {
    double radius;
public:
    Circle(string c, double r) : Shape(c) {
        radius = r;
    }
    double area() override {
        return 3.14159 * radius * radius;
    }
    void display() override {
        cout << "Circle\n";
        Shape::display();
    }
};

class Rectangle : public Shape {
    double length, width;
public:
    Rectangle(string c, double l, double w) : Shape(c) {
        length = l;
        width = w;
    }
    double area() override {
        return length * width;
    }
    void display() override {
        cout << "Rectangle\n";
        Shape::display();
    }
};

class Triangle : public Shape {
    double base, height;
public:
    Triangle(string c, double b, double h) : Shape(c) {
        base = b;
        height = h;
    }
    double area() override {
        return 0.5 * base * height;
    }
    void display() override {
        cout << "Triangle\n";
        Shape::display();
    }
};

int main() {
    Circle c("Red", 7);
    Rectangle r("Blue", 10, 5);
    Triangle t("Green", 8, 6);

    c.display();
    cout << endl;
    r.display();
    cout << endl;
    t.display();

    return 0;
}