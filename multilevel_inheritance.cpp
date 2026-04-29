#include<iostream>
#include<string>
using namespace std;

class Person {
protected:
    string name;
    int age;
public:
    Person(string n, int a) {
        name = n;
        age = a;
    }
    virtual void display() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class Student : public Person {
protected:
    string course;
    int semester;
public:
    Student(string n, int a, string c, int s) : Person(n, a) {
        course = c;
        semester = s;
    }
    void display() override {
        Person::display();
        cout << "Course: " << course << endl;
        cout << "Semester: " << semester << endl;
    }
};

class Graduate : public Student {
    string thesis;
    double gpa;
public:
    Graduate(string n, int a, string c, int s, string t, double g) : Student(n, a, c, s) {
        thesis = t;
        gpa = g;
    }
    void display() override {
        Student::display();
        cout << "Thesis: " << thesis << endl;
        cout << "GPA: " << gpa << endl;
    }
};

int main() {
    Person p("Rahul", 22);
    cout << "--- Person ---" << endl;
    p.display();

    cout << "\n--- Student ---" << endl;
    Student s("Akhilesh", 20, "B.Tech CSE", 3);
    s.display();

    cout << "\n--- Graduate ---" << endl;
    Graduate g("Amit", 24, "M.Tech AI", 2, "Deep Learning in NLP", 9.1);
    g.display();

    return 0;
}