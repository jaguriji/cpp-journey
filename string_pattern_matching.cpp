#include<iostream>
#include<string>
using namespace std;

void naiveSearch(string text, string pattern) {
    int n = text.length(), m = pattern.length();
    bool found = false;
    cout << "Naive Search:" << endl;
    for(int i = 0; i <= n-m; i++) {
        int j;
        for(j = 0; j < m; j++)
            if(text[i+j] != pattern[j]) break;
        if(j == m) {
            cout << "Pattern found at index " << i << endl;
            found = true;
        }
    }
    if(!found) cout << "Pattern not found" << endl;
}

void computeLPS(string pattern, int lps[]) {
    int m = pattern.length();
    int len = 0, i = 1;
    lps[0] = 0;
    while(i < m) {
        if(pattern[i] == pattern[len]) {
            lps[i++] = ++len;
        } else {
            if(len != 0) len = lps[len-1];
            else lps[i++] = 0;
        }
    }
}

void kmpSearch(string text, string pattern) {
    int n = text.length(), m = pattern.length();
    int lps[m];
    computeLPS(pattern, lps);

    bool found = false;
    int i = 0, j = 0;
    cout << "\nKMP Search:" << endl;
    while(i < n) {
        if(text[i] == pattern[j]) { i++; j++; }
        if(j == m) {
            cout << "Pattern found at index " << i-j << endl;
            found = true;
            j = lps[j-1];
        } else if(i < n && text[i] != pattern[j]) {
            if(j != 0) j = lps[j-1];
            else i++;
        }
    }
    if(!found) cout << "Pattern not found" << endl;
}

int main() {
    string text, pattern;
    cout << "Enter text: ";
    getline(cin, text);
    cout << "Enter pattern: ";
    cin >> pattern;

    naiveSearch(text, pattern);
    kmpSearch(text, pattern);

    cout << "\n--- Examples ---" << endl;
    string t1 = "AABAACAADAABAABA";
    string p1 = "AABA";
    cout << "Text: " << t1 << "\nPattern: " << p1 << endl;
    naiveSearch(t1, p1);
    kmpSearch(t1, p1);

    cout << "\nText: abcabcabc\nPattern: abc" << endl;
    naiveSearch("abcabcabc", "abc");
    kmpSearch("abcabcabc", "abc");

    return 0;
}