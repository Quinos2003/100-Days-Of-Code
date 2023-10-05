
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& prices, int n, int ind, int buy, int cap, vector<vector<vector<int>>>& dp) {
    // Base case
    if (ind == n || cap == 0) return 0;

    // Check if the result is already computed
    if (dp[ind][buy][cap] != -1)
        return dp[ind][buy][cap];

    int profit;

    if (buy == 0) { // We can buy the stock
        profit = max(0 + solve(prices, n, ind + 1, 0, cap, dp),
                     -prices[ind] + solve(prices, n, ind + 1, 1, cap, dp));
    }

    if (buy == 1) { // We can sell the stock
        profit = max(0 + solve(prices, n, ind + 1, 1, cap, dp),
                     prices[ind] + solve(prices, n, ind + 1, 0, cap - 1, dp));
    }

    // Store the result in the DP pricesay and return
    return dp[ind][buy][cap] = profit;
}

int maximumProfit(vector<int>& prices, int n, int k) {
    // Creating a 3D DP pricesay of size [n][2][k+1]
    vector<vector<vector<int>>> dp(n,
                                    vector<vector<int>>(2, vector<int>(k + 1, -1)));

    return solve(prices, n, 0, 0, k, dp);
}

int main() {
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    int n = prices.size();
    int k = 2;

    cout << "The maximum profit that can be generated is " << maximumProfit(prices, n, k) << endl;
    return 0;
}
