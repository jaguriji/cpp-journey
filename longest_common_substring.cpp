#include<iostream>
#include<string>
using namespace std;

string lcs(string s1, string s2) {
    int m = s1.length(), n = s2.length();
    int dp[m+1][n+1];
    int maxLen = 0, endIdx = 0;

    for(int i = 0; i <= m; i++)
        for(int j = 0; j <= n; j++)
            dp[i][j] = 0;

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
                if(dp[i][j] > maxLen) {
                    maxLen = dp[i][j];
                    endIdx = i;
                }
            } else {
                dp[i][j] = 0;
            }
        }
    }

    string result = s1.substr(endIdx - maxLen, maxLen);
    cout << "Longest Common Substring: " << result << endl;
    cout << "Length: " << maxLen << endl;
    return result;
}

void allCommonSubstrings(string s1, string s2) {
    cout << "\nAll common substrings:" << endl;
    int m = s1.length(), n = s2.length();
    for(int i = 0; i < m; i++) {
        for(int len = 1; len <= m-i; len++) {
            string sub = s1.substr(i, len);
            if(s2.find(sub) != string::npos)
                cout << sub << " ";
        }
    }
    cout << endl;
}

int main() {
    string s1, s2;
    cout << "Enter first string: ";
    cin >> s1;
    cout << "Enter second string: ";
    cin >> s2;

    lcs(s1, s2);
    allCommonSubstrings(s1, s2);

    cout << "\n--- Examples ---" << endl;
    cout << "ABCBDAB and BDCAB: ";
    lcs("ABCBDAB", "BDCAB");

    cout << "GeeksforGeeks and GeeksQuiz: ";
    lcs("GeeksforGeeks", "GeeksQuiz");

    return 0;
}