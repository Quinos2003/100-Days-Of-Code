// class Solution {
// public:
//     int minDistance(string word1, string word2) {
//         int m = word1.size(), n = word2.size();

//         vector<vector<int>> dp(m+1, vector<int>(n+1,0));

//         for(int i =1 ;i<=m ; i++) dp[i][0] =i;
//         for(int j =1; j<=n ; j++) dp[0][j] =j;

//         for(int i =1; i<=m ; i++){
//             for(int j =1; j<=n ; j++){
//                 if(word1[i-1]==word2[j-1]) dp[i][j]= dp[i-1][j-1];
//                 else
//                 dp[i][j]= min(dp[i-1][j-1], min(dp[i][j-1],dp[i-1][j]))+1;

//             }
//         }
//         return dp[m][n];
//     }
// };


class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();

        vector<int> prev(n+1,0) , curr(n+1,0);

        for(int i = 1; i<=n ; i++) prev[i]=i;

        for(int i =1; i<=m ; i++){
            curr[0] = i;
            for(int j =1; j<=n ; j++){
                if(word1[i-1]==word2[j-1]) curr[j] = prev[j-1];
                else
                curr[j]= min(prev[j-1], min(curr[j-1],prev[j]))+1;
            }
            swap(prev, curr);
        }
        return prev[n];
    }
};