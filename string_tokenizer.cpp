#include<iostream>
#include<string>
using namespace std;

void tokenize(string s, char delim) {
    string token = "";
    int count = 0;
    cout << "Tokens:" << endl;
    for(int i = 0; i <= s.length(); i++) {
        if(i == s.length() || s[i] == delim) {
            if(token.length() > 0) {
                cout << ++count << ". " << token << endl;
                token = "";
            }
        } else {
            token += s[i];
        }
    }
    cout << "Total tokens: " << count << endl;
}

void splitByMultipleDelims(string s, string delims) {
    string token = "";
    int count = 0;
    cout << "\nSplit by multiple delimiters:" << endl;
    for(int i = 0; i <= s.length(); i++) {
        bool isDelim = false;
        for(char d : delims)
            if(s[i] == d) { isDelim = true; break; }

        if(i == s.length() || isDelim) {
            if(token.length() > 0) {
                cout << ++count << ". " << token << endl;
                token = "";
            }
        } else {
            token += s[i];
        }
    }
    cout << "Total tokens: " << count << endl;
}

void wordFrequency(string s) {
    string words[100];
    int freq[100] = {0};
    int wordCount = 0;

    string word = "";
    for(int i = 0; i <= s.length(); i++) {
        if(i == s.length() || s[i] == ' ') {
            if(word.length() > 0) {
                bool found = false;
                for(int j = 0; j < wordCount; j++) {
                    if(words[j] == word) { freq[j]++; found = true; break; }
                }
                if(!found) { words[wordCount] = word; freq[wordCount++] = 1; }
                word = "";
            }
        } else word += s[i];
    }

    cout << "\nWord Frequency:" << endl;
    for(int i = 0; i < wordCount; i++)
        cout << words[i] << ": " << freq[i] << endl;
}

int main() {
    string s;
    cout << "Enter a sentence: ";
    getline(cin, s);

    tokenize(s, ' ');
    wordFrequency(s);

    cout << "\n--- Example ---" << endl;
    string csv = "name,age,city,country";
    cout << "CSV: " << csv << endl;
    tokenize(csv, ',');

    string mixed = "hello world,foo;bar test";
    cout << "\nMixed: " << mixed << endl;
    splitByMultipleDelims(mixed, " ,;");

    return 0;
}