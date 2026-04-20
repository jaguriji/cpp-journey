#include<iostream>
#include<string>
using namespace std;

int countWords(string s) {
    int count = 0;
    bool inWord = false;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] != ' ' && !inWord) {
            inWord = true;
            count++;
        } else if(s[i] == ' ') {
            inWord = false;
        }
    }
    return count;
}

void charFrequency(string s) {
    int freq[26] = {0};
    for(int i = 0; i < s.length(); i++) {
        if(s[i] >= 'a' && s[i] <= 'z') freq[s[i] - 'a']++;
        else if(s[i] >= 'A' && s[i] <= 'Z') freq[s[i] - 'A']++;
    }
    cout << "Character frequencies:" << endl;
    for(int i = 0; i < 26; i++) {
        if(freq[i] > 0) {
            cout << (char)('a' + i) << " : " << freq[i] << endl;
        }
    }
}

int main() {
    string s;
    cout << "Enter a sentence: ";
    getline(cin, s);

    cout << "Word count: " << countWords(s) << endl;
    charFrequency(s);

    return 0;
}