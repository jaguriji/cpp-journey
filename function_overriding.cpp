#include <iostream>

using namespace std;

class Animal {
public:
    virtual void makeSound() {
        cout << "Animal makes a generic sound" << endl;
    }
};

class Dog : public Animal {
public:
    void makeSound() override {
        cout << "Dog barks: Woof! Woof!" << endl;
    }
};

class Cat : public Animal {
public:
    void makeSound() override {
        cout << "Cat meows: Meow!" << endl;
    }
};

int main() {
    cout << "--- FUNCTION OVERRIDING EXPECTATION ---" << endl;

    Animal genericAnimal;
    Dog myDog;
    Cat myCat;

    cout << "Calling methods directly from objects:" << endl;
    genericAnimal.makeSound();
    myDog.makeSound();
    myCat.makeSound();

    cout << "\n-----------------\n" << endl;

    cout << "Calling overridden methods using base class pointers:" << endl;
    Animal* ptrAnimal;

    ptrAnimal = &myDog;
    ptrAnimal->makeSound(); 

    ptrAnimal = &myCat;
    ptrAnimal->makeSound(); 

    return 0;
}
