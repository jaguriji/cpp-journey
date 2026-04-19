#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string reverseString(string s) {
    int left = 0, right = s.length() - 1;
    while(left < right) {
        swap(s[left], s[right]);
        left++;
        right--;
    }
    return s;
}

bool isPalindrome(string s) {
    string rev = reverseString(s);
    return s == rev;
}

bool isAnagram(string s1, string s2) {
    if(s1.length() != s2.length()) return false;
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    return s1 == s2;
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    cout << "Reversed: " << reverseString(s) << endl;

    if(isPalindrome(s))
        cout << s << " is a Palindrome" << endl;
    else
        cout << s << " is not a Palindrome" << endl;

    string s2;
    cout << "Enter second string to check Anagram: ";
    cin >> s2;

    if(isAnagram(s, s2))
        cout << s << " and " << s2 << " are Anagrams" << endl;
    else
        cout << s << " and " << s2 << " are not Anagrams" << endl;

    return 0;
}