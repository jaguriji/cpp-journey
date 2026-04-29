#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void writeFile() {
    ofstream file("data.txt");
    if(!file) {
        cout << "Error creating file" << endl;
        return;
    }
    file << "Name: Akhilesh" << endl;
    file << "Course: B.Tech CSE" << endl;
    file << "Subject: C++ Programming" << endl;
    file.close();
    cout << "Data written to file successfully" << endl;
}

void readFile() {
    ifstream file("data.txt");
    if(!file) {
        cout << "Error opening file" << endl;
        return;
    }
    string line;
    cout << "\nFile contents:" << endl;
    while(getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}

void appendFile() {
    ofstream file("data.txt", ios::app);
    if(!file) {
        cout << "Error opening file" << endl;
        return;
    }
    file << "Semester: 3" << endl;
    file.close();
    cout << "Data appended successfully" << endl;
}

int main() {
    writeFile();
    readFile();
    appendFile();
    readFile();
    return 0;
}