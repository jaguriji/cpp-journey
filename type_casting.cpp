#include<iostream>
using namespace std;

class Animal {
public:
    virtual void sound() {
        cout << "Animal sound" << endl;
    }
};

class Dog : public Animal {
public:
    void sound() override {
        cout << "Woof!" << endl;
    }
    void fetch() {
        cout << "Dog is fetching!" << endl;
    }
};

int main() {
    // C-style casting
    cout << "--- C-Style Cast ---" << endl;
    double d = 9.99;
    int i = (int)d;
    cout << "double " << d << " to int: " << i << endl;

    // static_cast
    cout << "\n--- Static Cast ---" << endl;
    float f = 3.14f;
    int x = static_cast<int>(f);
    cout << "float " << f << " to int: " << x << endl;

    char ch = 'A';
    int ascii = static_cast<int>(ch);
    cout << "char '" << ch << "' to int: " << ascii << endl;

    int num = 66;
    char c = static_cast<char>(num);
    cout << "int " << num << " to char: " << c << endl;

    // dynamic_cast
    cout << "\n--- Dynamic Cast ---" << endl;
    Animal* a = new Dog();
    Dog* dog = dynamic_cast<Dog*>(a);
    if(dog) {
        dog->sound();
        dog->fetch();
    } else {
        cout << "Cast failed" << endl;
    }

    // reinterpret_cast
    cout << "\n--- Reinterpret Cast ---" << endl;
    int val = 65;
    int* ptr = &val;
    char* cptr = reinterpret_cast<char*>(ptr);
    cout << "int value: " << val << endl;
    cout << "reinterpreted as char: " << *cptr << endl;

    delete a;
    return 0;
}