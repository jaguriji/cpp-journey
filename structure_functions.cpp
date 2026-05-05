#include<iostream>
#include<string>
using namespace std;

struct Student {
    int id;
    string name;
    float marks[5];
    float average;
    char grade;
};

float calcAverage(float marks[], int n) {
    float sum = 0;
    for(int i = 0; i < n; i++)
        sum += marks[i];
    return sum / n;
}

char calcGrade(float avg) {
    if(avg >= 90) return 'A';
    else if(avg >= 80) return 'B';
    else if(avg >= 70) return 'C';
    else if(avg >= 60) return 'D';
    else return 'F';
}

void inputStudent(Student& s) {
    cout << "Enter ID: "; cin >> s.id;
    cout << "Enter Name: "; cin >> s.name;
    cout << "Enter 5 marks: ";
    for(int i = 0; i < 5; i++)
        cin >> s.marks[i];
    s.average = calcAverage(s.marks, 5);
    s.grade = calcGrade(s.average);
}

void displayStudent(Student s) {
    cout << "\nID: " << s.id << endl;
    cout << "Name: " << s.name << endl;
    cout << "Marks: ";
    for(int i = 0; i < 5; i++)
        cout << s.marks[i] << " ";
    cout << endl;
    cout << "Average: " << s.average << endl;
    cout << "Grade: " << s.grade << endl;
}

Student topStudent(Student arr[], int n) {
    Student top = arr[0];
    for(int i = 1; i < n; i++)
        if(arr[i].average > top.average)
            top = arr[i];
    return top;
}

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;
    Student arr[n];
    for(int i = 0; i < n; i++) {
        cout << "\nStudent " << i+1 << ":" << endl;
        inputStudent(arr[i]);
    }
    cout << "\n--- All Students ---";
    for(int i = 0; i < n; i++)
        displayStudent(arr[i]);

    cout << "\n--- Top Student ---";
    displayStudent(topStudent(arr, n));

    return 0;
}