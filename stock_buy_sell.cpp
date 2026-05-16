#include<iostream>
using namespace std;

int maxProfitOnce(int prices[], int n) {
    int minPrice = prices[0];
    int maxProfit = 0;
    int buyDay = 0, sellDay = 0, tempBuy = 0;

    for(int i = 1; i < n; i++) {
        if(prices[i] < minPrice) {
            minPrice = prices[i];
            tempBuy = i;
        }
        if(prices[i] - minPrice > maxProfit) {
            maxProfit = prices[i] - minPrice;
            buyDay = tempBuy;
            sellDay = i;
        }
    }

    if(maxProfit == 0) {
        cout << "No profit possible" << endl;
    } else {
        cout << "Buy on day " << buyDay+1 << " at price " << prices[buyDay] << endl;
        cout << "Sell on day " << sellDay+1 << " at price " << prices[sellDay] << endl;
        cout << "Max Profit: " << maxProfit << endl;
    }
    return maxProfit;
}

int maxProfitMultiple(int prices[], int n) {
    int profit = 0;
    for(int i = 1; i < n; i++)
        if(prices[i] > prices[i-1])
            profit += prices[i] - prices[i-1];
    return profit;
}

int main() {
    int n;
    cout << "Enter number of days: ";
    cin >> n;
    int prices[n];
    cout << "Enter prices: ";
    for(int i = 0; i < n; i++)
        cin >> prices[i];

    cout << "\n--- Buy Once Sell Once ---" << endl;
    maxProfitOnce(prices, n);

    cout << "\n--- Multiple Transactions ---" << endl;
    cout << "Max Profit: " << maxProfitMultiple(prices, n) << endl;

    cout << "\n--- Example ---" << endl;
    int ex[] = {7, 1, 5, 3, 6, 4};
    int m = 6;
    cout << "Prices: 7 1 5 3 6 4" << endl;
    maxProfitOnce(ex, m);
    cout << "Multiple transactions profit: " << maxProfitMultiple(ex, m) << endl;

    return 0;
}