#include<iostream>
using namespace std;

enum Day {
    MONDAY = 1, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY
};

enum Grade {
    A, B, C, D, F
};

string getDayName(Day d) {
    switch(d) {
        case MONDAY: return "Monday";
        case TUESDAY: return "Tuesday";
        case WEDNESDAY: return "Wednesday";
        case THURSDAY: return "Thursday";
        case FRIDAY: return "Friday";
        case SATURDAY: return "Saturday";
        case SUNDAY: return "Sunday";
        default: return "Invalid";
    }
}

string getGrade(int marks) {
    Grade g;
    if(marks >= 90) g = A;
    else if(marks >= 80) g = B;
    else if(marks >= 70) g = C;
    else if(marks >= 60) g = D;
    else g = F;

    switch(g) {
        case A: return "A - Excellent";
        case B: return "B - Good";
        case C: return "C - Average";
        case D: return "D - Below Average";
        case F: return "F - Fail";
        default: return "Invalid";
    }
}

bool isWeekend(Day d) {
    return d == SATURDAY || d == SUNDAY;
}

int main() {
    for(int i = 1; i <= 7; i++) {
        Day d = (Day)i;
        cout << getDayName(d);
        if(isWeekend(d)) cout << " (Weekend)";
        cout << endl;
    }

    cout << endl;
    int marks[] = {95, 83, 72, 61, 45};
    for(int i = 0; i < 5; i++) {
        cout << "Marks " << marks[i] << " -> Grade: " << getGrade(marks[i]) << endl;
    }

    return 0;
}