#include<iostream>
#include<string>
using namespace std;

string ones[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};

string tens[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

string convert(int n) {
    if(n == 0) return "Zero";
    string result = "";
    if(n >= 100) {
        result += ones[n / 100] + " Hundred ";
        n %= 100;
    }
    if(n >= 20) {
        result += tens[n / 10] + " ";
        n %= 10;
    }
    if(n > 0) {
        result += ones[n] + " ";
    }
    return result;
}

int main() {
    int n;
    cout << "Enter a number (0-999): ";
    cin >> n;
    if(n < 0 || n > 999) {
        cout << "Out of range" << endl;
    } else {
        cout << "In words: " << convert(n) << endl;
    }
    return 0;
}