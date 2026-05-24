#include<iostream>
using namespace std;

int minCoins(int coins[], int n, int amount) {
    int dp[amount+1];
    dp[0] = 0;
    for(int i = 1; i <= amount; i++) dp[i] = amount + 1;

    for(int i = 1; i <= amount; i++)
        for(int j = 0; j < n; j++)
            if(coins[j] <= i && dp[i-coins[j]] + 1 < dp[i])
                dp[i] = dp[i-coins[j]] + 1;

    if(dp[amount] > amount) {
        cout << "Not possible with given coins" << endl;
        return -1;
    }

    // backtrack to find coins used
    cout << "Coins used: ";
    int rem = amount;
    while(rem > 0) {
        for(int j = 0; j < n; j++) {
            if(coins[j] <= rem && dp[rem-coins[j]] == dp[rem]-1) {
                cout << coins[j] << " ";
                rem -= coins[j];
                break;
            }
        }
    }
    cout << endl;
    cout << "Minimum coins: " << dp[amount] << endl;
    return dp[amount];
}

int countCombinations(int coins[], int n, int amount) {
    int dp[amount+1];
    dp[0] = 1;
    for(int i = 1; i <= amount; i++) dp[i] = 0;

    for(int i = 0; i < n; i++)
        for(int j = coins[i]; j <= amount; j++)
            dp[j] += dp[j-coins[i]];

    cout << "Total combinations: " << dp[amount] << endl;
    return dp[amount];
}

int main() {
    int n, amount;
    cout << "Enter number of coin types: ";
    cin >> n;
    int coins[n];
    cout << "Enter coin values: ";
    for(int i = 0; i < n; i++) cin >> coins[i];
    cout << "Enter target amount: ";
    cin >> amount;

    minCoins(coins, n, amount);
    countCombinations(coins, n, amount);

    cout << "\n--- Examples ---" << endl;
    int c1[] = {1, 5, 6, 9};
    cout << "Coins: 1 5 6 9 | Amount: 11" << endl;
    minCoins(c1, 4, 11);
    countCombinations(c1, 4, 11);

    int c2[] = {2};
    cout << "\nCoins: 2 | Amount: 3" << endl;
    minCoins(c2, 1, 3);

    return 0;
}
