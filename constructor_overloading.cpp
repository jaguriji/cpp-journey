#include <iostream>
#include <string>

using namespace std;

class Person {
private:
    string name;
    int age;

public:
    Person() {
        name = "Unknown";
        age = 0;
        cout << "Default constructor called." << endl;
    }

    Person(string pName) {
        name = pName;
        age = 0;
        cout << "Parameterized constructor with one argument called." << endl;
    }

    Person(string pName, int pAge) {
        name = pName;
        age = pAge;
        cout << "Parameterized constructor with two arguments called." << endl;
    }

    void display() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

int main() {
    cout << "--- CONSTRUCTOR OVERLOADING EXPECTATION ---" << endl;

    Person person1;
    person1.display();

    cout << "-----------------" << endl;

    Person person2("Alice");
    person2.display();

    cout << "-----------------" << endl;

    Person person3("Bob", 25);
    person3.display();

    return 0;
}
