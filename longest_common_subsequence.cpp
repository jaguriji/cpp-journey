#include<iostream>
#include<string>
using namespace std;

int lcs(string s1, string s2) {
    int m = s1.length(), n = s2.length();
    int dp[m+1][n+1];

    for(int i = 0; i <= m; i++)
        for(int j = 0; j <= n; j++)
            dp[i][j] = 0;

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(s1[i-1] == s2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    // backtrack to find the actual LCS
    string result = "";
    int i = m, j = n;
    while(i > 0 && j > 0) {
        if(s1[i-1] == s2[j-1]) {
            result = s1[i-1] + result;
            i--; j--;
        } else if(dp[i-1][j] > dp[i][j-1]) i--;
        else j--;
    }

    cout << "LCS: " << result << endl;
    cout << "LCS Length: " << dp[m][n] << endl;
    return dp[m][n];
}

int main() {
    string s1, s2;
    cout << "Enter first string: ";
    cin >> s1;
    cout << "Enter second string: ";
    cin >> s2;

    lcs(s1, s2);

    cout << "\n--- Examples ---" << endl;
    cout << "ABCBDAB and BDCAB: ";
    lcs("ABCBDAB", "BDCAB");

    cout << "AGGTAB and GXTXAYB: ";
    lcs("AGGTAB", "GXTXAYB");

    return 0;
}