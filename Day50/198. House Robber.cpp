class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int prev = nums[0];
        int prev2 = 0;

        for(int i =1 ; i < n ; i++){
            int take = nums[i];
            if(i>1) take += prev2;
            int curi = max(take, prev);

            prev2=prev;
            prev = curi;
        }
        return prev;
    }
};
// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         if(n<2) return nums[0];
//         vector<int> dp(n+1);
//         dp[0]=0;
//         dp[1]= nums[0];
//         dp[2]= max(nums[0],nums[1]);
//         for(int i =3 ; i < n+1; i ++){
//             dp[i] =  max(dp[i-3]+ nums[i-1],dp[i-2] + nums[i-1]) ;
//         }
//         return max(dp[n],dp[n-1]);
//     }
// };