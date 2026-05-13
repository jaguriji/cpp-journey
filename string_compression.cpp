#include<iostream>
#include<string>
using namespace std;

string compress(string s) {
    string result = "";
    int i = 0;
    while(i < s.length()) {
        char c = s[i];
        int count = 0;
        while(i < s.length() && s[i] == c) {
            count++;
            i++;
        }
        result += c;
        if(count > 1) result += to_string(count);
    }
    return result.length() < s.length() ? result : s;
}

string decompress(string s) {
    string result = "";
    int i = 0;
    while(i < s.length()) {
        char c = s[i++];
        string numStr = "";
        while(i < s.length() && s[i] >= '0' && s[i] <= '9') {
            numStr += s[i++];
        }
        int count = numStr.empty() ? 1 : stoi(numStr);
        for(int j = 0; j < count; j++)
            result += c;
    }
    return result;
}

void runLengthEncoding(string s) {
    cout << "RLE Encoding:" << endl;
    int i = 0;
    while(i < s.length()) {
        char c = s[i];
        int count = 0;
        while(i < s.length() && s[i] == c) { count++; i++; }
        cout << count << c << " ";
    }
    cout << endl;
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    string compressed = compress(s);
    cout << "Original:    " << s << " (length " << s.length() << ")" << endl;
    cout << "Compressed:  " << compressed << " (length " << compressed.length() << ")" << endl;
    cout << "Decompressed: " << decompress(compressed) << endl;

    cout << endl;
    runLengthEncoding(s);

    cout << "\n--- Examples ---" << endl;
    string examples[] = {"aabbbcccc", "abcdef", "aaabbaaa"};
    for(string ex : examples)
        cout << ex << " -> " << compress(ex) << endl;

    return 0;
}