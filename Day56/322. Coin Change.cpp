class Solution {
public:

    int coinChange(vector<int>& coins, int n) {
        // cout<<n<<n+1;
        // n=n+1;
        // int dp[n+1];
        int dp[++n];
        // cout<<n<<++n;
        dp[0]=0;
        sort(coins.begin(), coins.end());
        for( int i =1 ; i < n ; i++){
            dp[i]= INT_MAX;
            for(int c : coins){
                if(i-c<0) break; // as amount exceeded

                if(dp[i-c]!=INT_MAX) dp[i]= min(dp[i], 1+dp[i-c]);
            }
        }
        return dp[n-1] == INT_MAX ? -1 : dp[n-1];

        // if( dp[n-1] == INT_MAX ){
        //     return -1;
        // }
        // else return dp[n-1];
    }
};