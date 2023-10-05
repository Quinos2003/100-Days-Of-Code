
#include <bits/stdc++.h>
using namespace std;
// SPACE OPTIMIZATION 
int maxProfit( int k, vector<int>& prices) {
    int n = prices.size();
    // Create two prices aRRays, 'ahead' and 'cur', to track the maximum profit at each step
    vector<vector<int>> ahead(2, vector<int>(k + 1, 0));
    vector<vector<int>> cur(2, vector<int>(k + 1, 0));

    for (int ind = n - 1; ind >= 0; ind--) {
        for (int buy = 0; buy <= 1; buy++) {
            for (int cap = 1; cap <= k; cap++) {
                if (buy == 0) { // We can buy the stock
                    cur[buy][cap] = max(0 + ahead[0][cap],-prices[ind] + ahead[1][cap]);
                }

                if (buy == 1) { // We can sell the stock
                    cur[buy][cap] = max(0 + ahead[1][cap],prices[ind] + ahead[0][cap - 1]);
                }
            }
        }
        // Update the 'ahead' pricesay with the current values
        ahead = cur;
    }

    return ahead[0][k];
}

// TABULATION APPROACH
// int maxProfit(int k, vector<int>& prices) {
//     int n = prices.size();
//     // Creating a 3D DP prices arr of size [n+1][2][k+1] initialized to 0
//     vector<vector<vector<int>>> dp(n + 1,
//                                     vector<vector<int>>(2, vector<int>(k + 1, 0)));

//     // Loop through the stock prices from the end to the beginning
//     for (int ind = n - 1; ind >= 0; ind--) {
//         for (int buy = 0; buy <= 1; buy++) {
//             for (int cap = 1; cap <= k; cap++) {
//                 if (buy == 0) { // We can buy the stock
//                     dp[ind][buy][cap] = max(0 + dp[ind + 1][0][cap],
//                                 -prices[ind] + dp[ind + 1][1][cap]);
//                 }

//                 if (buy == 1) { // We can sell the stock
//                     dp[ind][buy][cap] = max(0 + dp[ind + 1][1][cap],
//                                 prices[ind] + dp[ind + 1][0][cap - 1]);
//                 }
//             }
//         }
//     }

//     return dp[0][0][k];
// }

// MEMOIZATION APPROACH
// int solve(vector<int>& prices, int n, int ind, int buy, int cap, vector<vector<vector<int>>>& dp) {
//     // Base case
//     if (ind == n || cap == 0) return 0;

//     // Check if the result is already computed
//     if (dp[ind][buy][cap] != -1)
//         return dp[ind][buy][cap];

//     int profit;

//     if (buy == 0) { // We can buy the stock
//         profit = max(0 + solve(prices, n, ind + 1, 0, cap, dp),
//                      -prices[ind] + solve(prices, n, ind + 1, 1, cap, dp));
//     }

//     if (buy == 1) { // We can sell the stock
//         profit = max(0 + solve(prices, n, ind + 1, 1, cap, dp),
//                      prices[ind] + solve(prices, n, ind + 1, 0, cap - 1, dp));
//     }

//     // Store the result in the DP pricesay and return
//     return dp[ind][buy][cap] = profit;
// }

//     int maxProfit(int k, vector<int>& prices) {
//         int n = prices.size();
//         // Creating a 3D DP pricesay of size [n][2][k+1]
//         vector<vector<vector<int>>> dp(n,vector<vector<int>>(2, vector<int>(k + 1, -1)));

//         return solve(prices, n, 0, 0, k, dp);
//     }

int main() {
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    int n = prices.size();
    int k = 2;

    cout << "The maximum profit that can be generated is " << maxProfit(prices, n, k) << endl;
    return 0;
}
