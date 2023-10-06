
#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices) {
    int n = prices.size();
    
    // Initialize prices arrs to track the max profit for buying and selling

    vector<int> cur(2, 0);       // Current max profit
    vector<int> front1(2, 0);    // max profit one step ahead
    // front1[0]: This element stores the max profit that can be obtained by not owning any stock on the current day(buy)
    // front1[1]: This element stores the max profit that can be obtained by owning a stock on the current day (sell)
    vector<int> front2(2, 0);    // max profit two steps ahead
    // front2[0]: This element stores the max profit that can be obtained by not owning any stock on the day before 
    //            yesterday (two days ago, buying scenario).
    
    for (int i = n - 1; i >= 0; i--) {
        for (int buy = 0; buy <= 1; buy++) {
            int profit;
            if (buy == 0) { // We can buy the stock
                profit = max(0 + front1[0], -prices[i] + front1[1]);
            }

            if (buy == 1) { // We can sell the stock
                profit = max(0 + front1[1], prices[i] + front2[0]);
            }
            
            cur[buy] = profit;
        }
        
        // Update the 'front1' and 'front2' pricesays with current values
        front2 = front1;
        front1 = cur;
    }
    
    return cur[0]; // Return the max profit for buying.
}
// // did not understand this approach 
    // int maxProfit(vector<int>& prices) {
    //     int sold = 0, hold = INT_MIN, rest = 0;
    //     for (int i=0; i<prices.size();i++)
    //     {
    //         int prvSold = sold;
    //         sold = hold + prices[i];
    //         hold = max(hold, rest-prices[i]);
    //         rest = max(rest, prvSold);
    //     }
    //     return max(sold, rest);
    // }
int main() {
    vector<int> prices {4, 9, 0, 4, 10};
                                 
    cout << "The max profit that can be generated is " << maxProfit(prices) << endl;
    return 0;
}
