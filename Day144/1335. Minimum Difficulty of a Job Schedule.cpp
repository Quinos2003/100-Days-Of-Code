class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int D) {
        int n = jobDifficulty.size();
        if( n<D) return -1;

        vector<int> dp(n,1e9) ,dp2(n);
        dp2[0]=jobDifficulty[0];
        
        for(int d=0 ; d< D; d++){
            stack<int> st;
            for(int i =d ; i<n ;i++){
                if(i) dp2[i]= dp[i-1] + jobDifficulty[i];

                while(st.size() && jobDifficulty[st.top()]<= jobDifficulty[i]){
                    int j = st.top(); st.pop();
                    dp2[i]=min(dp2[i], dp2[j]-jobDifficulty[j]+jobDifficulty[i]);
                }
                if(st.size()){
                    dp2[i]= min(dp2[i], dp2[st.top()]);
                }
                st.push(i);
            }
            swap(dp,dp2);
        }
        return dp[n-1];
    }
};