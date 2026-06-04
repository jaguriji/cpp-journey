#include<iostream>
#include<string>
using namespace std;

int permCount = 0;

void permutations(string s, int left, int right) {
    if(left == right) {
        cout << ++permCount << ". " << s << endl;
        return;
    }
    for(int i = left; i <= right; i++) {
        swap(s[left], s[i]);
        permutations(s, left+1, right);
        swap(s[left], s[i]);
    }
}

void uniquePermutations(string s, int left, int right) {
    if(left == right) {
        cout << s << endl;
        return;
    }
    bool used[256] = {false};
    for(int i = left; i <= right; i++) {
        if(!used[(int)s[i]]) {
            used[(int)s[i]] = true;
            swap(s[left], s[i]);
            uniquePermutations(s, left+1, right);
            swap(s[left], s[i]);
        }
    }
}

bool isPermutation(string s1, string s2) {
    if(s1.length() != s2.length()) return false;
    int freq[256] = {0};
    for(char c : s1) freq[(int)c]++;
    for(char c : s2) freq[(int)c]--;
    for(int i = 0; i < 256; i++)
        if(freq[i] != 0) return false;
    return true;
}

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;

    cout << "\nAll permutations of \"" << s << "\":" << endl;
    permutations(s, 0, s.length()-1);
    cout << "Total: " << permCount << endl;

    cout << "\nUnique permutations:" << endl;
    uniquePermutations(s, 0, s.length()-1);

    string s2;
    cout << "\nEnter second string to check permutation: ";
    cin >> s2;
    cout << s1 << " and " << s2 << " are " << (isPermutation(s, s2) ? "" : "not ") << "permutations" << endl;

    cout << "\n--- Examples ---" << endl;
    cout << "Permutations of abc:" << endl;
    permCount = 0;
    permutations("abc", 0, 2);

    cout << "\nUnique permutations of aab:" << endl;
    uniquePermutations("aab", 0, 2);

    return 0;
}
