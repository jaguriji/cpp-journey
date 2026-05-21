#include<iostream>
#include<string>
using namespace std;

string expandAroundCenter(string s, int left, int right) {
    while(left >= 0 && right < s.length() && s[left] == s[right]) {
        left--;
        right++;
    }
    return s.substr(left+1, right-left-1);
}

string longestPalindrome(string s) {
    if(s.length() == 0) return "";
    string longest = "";

    for(int i = 0; i < s.length(); i++) {
        string odd = expandAroundCenter(s, i, i);
        string even = expandAroundCenter(s, i, i+1);

        if(odd.length() > longest.length()) longest = odd;
        if(even.length() > longest.length()) longest = even;
    }
    return longest;
}

bool isPalindrome(string s) {
    int left = 0, right = s.length()-1;
    while(left < right) {
        if(s[left] != s[right]) return false;
        left++; right--;
    }
    return true;
}

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;

    string result = longestPalindrome(s);
    cout << "Longest palindromic substring: " << result << endl;
    cout << "Length: " << result.length() << endl;

    cout << "\n--- Examples ---" << endl;
    string tests[] = {"babad", "cbbd", "racecar", "abcba", "abacaba"};
    for(string t : tests)
        cout << t << " -> " << longestPalindrome(t) << endl;

    return 0;
}
