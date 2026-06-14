#include<iostream>
#include<string>
using namespace std;

void buildZArray(string s, int z[]) {
    int n = s.length();
    int l = 0, r = 0;
    z[0] = n;

    for(int i = 1; i < n; i++) {
        if(i < r) z[i] = min(r-i, z[i-l]);
        else z[i] = 0;

        while(i + z[i] < n && s[z[i]] == s[i + z[i]])
            z[i]++;

        if(i + z[i] > r) { l = i; r = i + z[i]; }
    }
}

void zSearch(string text, string pattern) {
    string concat = pattern + "$" + text;
    int n = concat.length(), m = pattern.length();
    int z[n];
    buildZArray(concat, z);

    bool found = false;
    cout << "Z Algorithm Search:" << endl;
    for(int i = m+1; i < n; i++) {
        if(z[i] == m) {
            cout << "Pattern found at index " << i-m-1 << endl;
            found = true;
        }
    }
    if(!found) cout << "Pattern not found" << endl;
}

void printZArray(string s) {
    int n = s.length();
    int z[n];
    buildZArray(s, z);
    cout << "Z Array for \"" << s << "\":" << endl;
    for(int i = 0; i < n; i++)
        cout << "z[" << i << "] = " << z[i] << endl;
}

int longestPrefixSuffix(string s) {
    int n = s.length();
    int z[n];
    buildZArray(s, z);
    int longest = 0;
    for(int i = 1; i < n; i++)
        if(z[i] + i == n && z[i] > longest)
            longest = z[i];
    return longest;
}

int main() {
    string text, pattern;
    cout << "Enter text: ";
    getline(cin, text);
    cout << "Enter pattern: ";
    cin >> pattern;

    zSearch(text, pattern);

    cout << "\n--- Examples ---" << endl;
    zSearch("AABAACAADAABAABA", "AABA");
    zSearch("abcabcabc", "abc");

    cout << "\n--- Z Arrays ---" << endl;
    printZArray("aabxaa");
    printZArray("abcabc");

    cout << "\n--- Longest Prefix that is also Suffix ---" << endl;
    string words[] = {"abcab", "aaaa", "abcabc"};
    for(string w : words)
        cout << w << ": length " << longestPrefixSuffix(w) << endl;

    return 0;
}