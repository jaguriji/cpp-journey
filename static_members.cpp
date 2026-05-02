#include<iostream>
#include<string>
using namespace std;

class Student {
    string name;
    int marks;
    static int totalStudents;
    static int totalMarks;
public:
    Student(string n, int m) {
        name = n;
        marks = m;
        totalStudents++;
        totalMarks += m;
    }
    void display() {
        cout << "Name: " << name << " | Marks: " << marks << endl;
    }
    static void showStats() {
        cout << "Total Students: " << totalStudents << endl;
        cout << "Total Marks: " << totalMarks << endl;
        cout << "Average Marks: " << (double)totalMarks / totalStudents << endl;
    }
};

int Student::totalStudents = 0;
int Student::totalMarks = 0;

int main() {
    Student s1("Akhilesh", 85);
    Student s2("Rahul", 90);
    Student s3("Amit", 78);

    s1.display();
    s2.display();
    s3.display();

    cout << endl;
    Student::showStats();

    return 0;
}