// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         if(n<2) return 0;
//         int profit1=0 , profit2=0;
//         int prev = prices[0], curr=prices[1] ;
//         int chance = 0; // 0 means profit1 , 1 means profit 2 chance
//         int i =0;
//         bool profit=false;
//         while(i < n-1){
//             if(prices[i]<prices[i+1]){
//                 if(chance ==0){
//                     if(profit == true) {
//                         profit2 += prices[i+1]-prices[i];
//                     }
//                     else{
//                         profit1 =max (profit1 ,prices[i+1]-prices[i]);
//                         chance =1;
//                     }   
//                     profit = true;
//                 }
//                 else{
//                     if(profit == true) {
//                         profit1 += prices[i+1]-prices[i];
//                     }
//                     else {
//                         profit2 = max (profit2 ,prices[i+1]-prices[i]);
//                         chance =0;
//                     }
//                     profit = true;
//                 }
//             }
//             else profit = false;
//             i++;
//         }
//         return profit1+profit2;
//     }
// };
// // passed 200/250 test cases does not deal with certain kind

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy1    = INT_MAX;
        int profit1 = INT_MIN;
        int buy2    = INT_MAX;
        int profit2 = INT_MIN;
        for(int i = 0; i < prices.size(); i++){
            buy1    = min(buy1, prices[i]);
            profit1 = max(profit1, prices[i] - buy1);
            buy2    = min(buy2, prices[i] - profit1);
            profit2 = max(profit2, prices[i] - buy2);
        }
        return profit2;
    }
};