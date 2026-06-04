#include<iostream>
#include<string>
using namespace std;

string addStrings(string a, string b) {
    string result = "";
    int carry = 0;
    int i = a.length()-1, j = b.length()-1;

    while(i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if(i >= 0) { sum += a[i--] - '0'; }
        if(j >= 0) { sum += b[j--] - '0'; }
        carry = sum / 10;
        result = (char)(sum % 10 + '0') + result;
    }
    return result;
}

string multiplyStrings(string a, string b) {
    int m = a.length(), n = b.length();
    int result[m+n] = {0};

    for(int i = m-1; i >= 0; i--) {
        for(int j = n-1; j >= 0; j--) {
            int mul = (a[i]-'0') * (b[j]-'0');
            int p1 = i+j, p2 = i+j+1;
            int sum = mul + result[p2];
            result[p2] = sum % 10;
            result[p1] += sum / 10;
        }
    }

    string str = "";
    for(int r : result)
        if(!(str.empty() && r == 0))
            str += to_string(r);
    return str.empty() ? "0" : str;
}

int compareStrings(string a, string b) {
    if(a.length() != b.length())
        return a.length() > b.length() ? 1 : -1;
    return a.compare(b);
}

int main() {
    string a, b;
    cout << "Enter first large number: ";
    cin >> a;
    cout << "Enter second large number: ";
    cin >> b;

    cout << "\nAddition: " << addStrings(a, b) << endl;
    cout << "Multiplication: " << multiplyStrings(a, b) << endl;

    int cmp = compareStrings(a, b);
    if(cmp > 0) cout << a << " > " << b << endl;
    else if(cmp < 0) cout << a << " < " << b << endl;
    else cout << a << " == " << b << endl;

    cout << "\n--- Examples ---" << endl;
    cout << "123 + 456 = " << addStrings("123", "456") << endl;
    cout << "999 + 1 = " << addStrings("999", "1") << endl;
    cout << "12 * 34 = " << multiplyStrings("12", "34") << endl;
    cout << "99 * 99 = " << multiplyStrings("99", "99") << endl;

    return 0;
}
