class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int temp = prices[0];
        int ans = 0;
        int local=0;

        for(int i =0 ; i < prices.size(); i++){
            if(prices[i]< temp){
                temp = prices[i];
            }
            local = prices[i] - temp;
            ans = max ( ans , local);
        }
        return ans ;

        
    }
};