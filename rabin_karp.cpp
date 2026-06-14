#include<iostream>
#include<string>
using namespace std;

#define BASE 256
#define MOD 101

void rabinKarp(string text, string pattern) {
    int n = text.length(), m = pattern.length();
    int patHash = 0, textHash = 0, h = 1;
    bool found = false;

    for(int i = 0; i < m-1; i++)
        h = (h * BASE) % MOD;

    for(int i = 0; i < m; i++) {
        patHash = (BASE * patHash + pattern[i]) % MOD;
        textHash = (BASE * textHash + text[i]) % MOD;
    }

    cout << "Rabin Karp Search:" << endl;
    for(int i = 0; i <= n-m; i++) {
        if(patHash == textHash) {
            bool match = true;
            for(int j = 0; j < m; j++) {
                if(text[i+j] != pattern[j]) { match = false; break; }
            }
            if(match) {
                cout << "Pattern found at index " << i << endl;
                found = true;
            }
        }
        if(i < n-m) {
            textHash = (BASE*(textHash - text[i]*h) + text[i+m]) % MOD;
            if(textHash < 0) textHash += MOD;
        }
    }
    if(!found) cout << "Pattern not found" << endl;
}

void multiPatternSearch(string text, string patterns[], int k) {
    cout << "\nMultiple Pattern Search:" << endl;
    for(int i = 0; i < k; i++) {
        cout << "Searching \"" << patterns[i] << "\": ";
        int n = text.length(), m = patterns[i].length();
        int patHash = 0, textHash = 0, h = 1;
        bool found = false;

        for(int j = 0; j < m-1; j++) h = (h * BASE) % MOD;
        for(int j = 0; j < m; j++) {
            patHash = (BASE * patHash + patterns[i][j]) % MOD;
            textHash = (BASE * textHash + text[j]) % MOD;
        }

        for(int j = 0; j <= n-m; j++) {
            if(patHash == textHash) {
                if(text.substr(j, m) == patterns[i]) {
                    cout << "index " << j << " ";
                    found = true;
                }
            }
            if(j < n-m) {
                textHash = (BASE*(textHash - text[j]*h) + text[j+m]) % MOD;
                if(textHash < 0) textHash += MOD;
            }
        }
        if(!found) cout << "not found";
        cout << endl;
    }
}

int main() {
    string text, pattern;
    cout << "Enter text: ";
    getline(cin, text);
    cout << "Enter pattern: ";
    cin >> pattern;

    rabinKarp(text, pattern);

    cout << "\n--- Examples ---" << endl;
    rabinKarp("AABAACAADAABAABA", "AABA");
    rabinKarp("abcabcabc", "abc");

    string patterns[] = {"abc", "cab", "bca"};
    multiPatternSearch("abcabcabc", patterns, 3);

    return 0;
}