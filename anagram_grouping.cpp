#include<iostream>
#include<string>
using namespace std;

void sortString(string& s) {
    for(int i = 0; i < s.length()-1; i++)
        for(int j = 0; j < s.length()-i-1; j++)
            if(s[j] > s[j+1]) swap(s[j], s[j+1]);
}

bool isAnagram(string s1, string s2) {
    if(s1.length() != s2.length()) return false;
    string t1 = s1, t2 = s2;
    sortString(t1); sortString(t2);
    return t1 == t2;
}

void groupAnagrams(string arr[], int n) {
    bool visited[n];
    for(int i = 0; i < n; i++) visited[i] = false;

    cout << "Anagram Groups:" << endl;
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            cout << "[ " << arr[i];
            visited[i] = true;
            for(int j = i+1; j < n; j++) {
                if(!visited[j] && isAnagram(arr[i], arr[j])) {
                    cout << ", " << arr[j];
                    visited[j] = true;
                }
            }
            cout << " ]" << endl;
        }
    }
}

int main() {
    int n;
    cout << "Enter number of strings: ";
    cin >> n;
    string arr[n];
    cout << "Enter strings: ";
    for(int i = 0; i < n; i++) cin >> arr[i];

    groupAnagrams(arr, n);

    cout << "\n--- Example ---" << endl;
    string ex[] = {"eat", "tea", "tan", "ate", "nat", "bat"};
    groupAnagrams(ex, 6);

    return 0;
}