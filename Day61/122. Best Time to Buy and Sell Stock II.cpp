class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // int n = prices.size();
        // if(n<2) return 0; 
        int profit =0;
        // int prev = prices[0], curr=prices[1] ;
        for(int i=0 ; i < prices.size()-1 ; i++){
            if(prices[i]<prices[i+1]) profit+= prices[i+1]-prices[i];
        }
        return profit;
    }
};