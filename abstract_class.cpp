#include<iostream>
#include<string>
using namespace std;

class Animal {
protected:
    string name;
    int age;
public:
    Animal(string n, int a) {
        name = n;
        age = a;
    }
    virtual void sound() = 0;
    virtual void move() = 0;
    virtual void display() {
        cout << "Name: " << name << " | Age: " << age << endl;
    }
};

class Dog : public Animal {
    string breed;
public:
    Dog(string n, int a, string b) : Animal(n, a) {
        breed = b;
    }
    void sound() override {
        cout << name << " says: Woof Woof!" << endl;
    }
    void move() override {
        cout << name << " runs on four legs" << endl;
    }
    void display() override {
        Animal::display();
        cout << "Breed: " << breed << endl;
    }
};

class Bird : public Animal {
    double wingspan;
public:
    Bird(string n, int a, double w) : Animal(n, a) {
        wingspan = w;
    }
    void sound() override {
        cout << name << " says: Tweet Tweet!" << endl;
    }
    void move() override {
        cout << name << " flies with wingspan " << wingspan << "cm" << endl;
    }
    void display() override {
        Animal::display();
        cout << "Wingspan: " << wingspan << "cm" << endl;
    }
};

class Fish : public Animal {
    string type;
public:
    Fish(string n, int a, string t) : Animal(n, a) {
        type = t;
    }
    void sound() override {
        cout << name << " makes no sound" << endl;
    }
    void move() override {
        cout << name << " swims underwater" << endl;
    }
    void display() override {
        Animal::display();
        cout << "Type: " << type << endl;
    }
};

int main() {
    Animal* animals[3];
    animals[0] = new Dog("Bruno", 3, "Labrador");
    animals[1] = new Bird("Tweety", 1, 25.5);
    animals[2] = new Fish("Nemo", 2, "Clownfish");

    for(int i = 0; i < 3; i++) {
        animals[i]->display();
        animals[i]->sound();
        animals[i]->move();
        cout << endl;
    }

    for(int i = 0; i < 3; i++)
        delete animals[i];

    return 0;
}