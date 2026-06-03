#include<iostream>
#include<string>
using namespace std;

bool isRotation(string s1, string s2) {
    if(s1.length() != s2.length()) return false;
    string doubled = s1 + s1;
    int n = doubled.length(), m = s2.length();
    for(int i = 0; i <= n-m; i++) {
        int j;
        for(j = 0; j < m; j++)
            if(doubled[i+j] != s2[j]) break;
        if(j == m) return true;
    }
    return false;
}

void allRotations(string s) {
    int n = s.length();
    cout << "All rotations of \"" << s << "\":" << endl;
    for(int i = 0; i < n; i++) {
        string rotated = s.substr(i) + s.substr(0, i);
        cout << i << ": " << rotated << endl;
    }
}

string leftRotateByK(string s, int k) {
    int n = s.length();
    k = k % n;
    return s.substr(k) + s.substr(0, k);
}

string rightRotateByK(string s, int k) {
    int n = s.length();
    k = k % n;
    return s.substr(n-k) + s.substr(0, n-k);
}

bool isPalindromeRotation(string s) {
    int n = s.length();
    for(int i = 0; i < n; i++) {
        string rotated = s.substr(i) + s.substr(0, i);
        string rev = rotated;
        int l = 0, r = rev.length()-1;
        while(l < r) { swap(rev[l], rev[r]); l++; r--; }
        if(rotated == rev) {
            cout << "Palindrome rotation: " << rotated << endl;
            return true;
        }
    }
    return false;
}

int main() {
    string s1, s2;
    cout << "Enter first string: ";
    cin >> s1;
    cout << "Enter second string: ";
    cin >> s2;

    cout << (isRotation(s1, s2) ? s2 + " IS" : s2 + " is NOT") << " a rotation of " << s1 << endl;

    int k;
    cout << "Enter k for rotation: ";
    cin >> k;
    cout << "Left rotate by " << k << ": " << leftRotateByK(s1, k) << endl;
    cout << "Right rotate by " << k << ": " << rightRotateByK(s1, k) << endl;

    allRotations(s1);

    cout << "\nChecking palindrome rotation:" << endl;
    if(!isPalindromeRotation(s1))
        cout << "No palindrome rotation exists" << endl;

    cout << "\n--- Examples ---" << endl;
    cout << "abcde and cdeab: " << (isRotation("abcde","cdeab") ? "Yes" : "No") << endl;
    cout << "abcde and abced: " << (isRotation("abcde","abced") ? "Yes" : "No") << endl;
    allRotations("abc");

    return 0;
}