#include<iostream>
#include<string>
using namespace std;

string encrypt(string text, int shift) {
    string result = "";
    shift = shift % 26;
    for(char c : text) {
        if(c >= 'a' && c <= 'z')
            result += (char)((c - 'a' + shift) % 26 + 'a');
        else if(c >= 'A' && c <= 'Z')
            result += (char)((c - 'A' + shift) % 26 + 'A');
        else
            result += c;
    }
    return result;
}

string decrypt(string text, int shift) {
    return encrypt(text, 26 - shift % 26);
}

void bruteForce(string text) {
    cout << "Brute force all shifts:" << endl;
    for(int i = 1; i <= 25; i++)
        cout << "Shift " << i << ": " << decrypt(text, i) << endl;
}

int main() {
    string text;
    int shift;
    cout << "Enter text: ";
    getline(cin, text);
    cout << "Enter shift: ";
    cin >> shift;

    string encrypted = encrypt(text, shift);
    string decrypted = decrypt(encrypted, shift);

    cout << "\nOriginal:  " << text << endl;
    cout << "Encrypted: " << encrypted << endl;
    cout << "Decrypted: " << decrypted << endl;

    cout << "\n--- Examples ---" << endl;
    cout << "Hello World, shift 3:" << endl;
    string enc = encrypt("Hello World", 3);
    cout << "Encrypted: " << enc << endl;
    cout << "Decrypted: " << decrypt(enc, 3) << endl;

    cout << "\nBrute force on \"Khoor\":" << endl;
    bruteForce("Khoor");

    return 0;
}