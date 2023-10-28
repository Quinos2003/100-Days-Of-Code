// class Solution {
// public:
    
    

//     int lengthOfLongestSubsequence(vector<int>& nums, int target) {
//         int n = nums.size();
//         int maxLength =-1;
//         int currentSum = 0;
//         unordered_map<int,int> mp;
//         mp[0] =0;
        
//         for(int num : nums){
//             unordered_map<int,int> temp= mp;
//             for( auto it : mp){
//                 int sum = num + it.first;
//                 if(sum<=target){
//                     temp[sum] = max(temp[sum], mp[it.first]+1);
//                 }
//             }
//             mp=temp;
//         }
//         if(mp.find(target)!= mp.end()) return mp[target];
//         return -1;
//     }
// };

// class Solution {
// public:
//     int lengthOfLongestSubsequence(vector<int>& nums, int target) {
//         int n = nums.size();
//         unordered_map<int, int> prefixSum; // Maps prefix sums to their counts
//         int maxLength = 0;
//         int currentSum = 0;

//         for (int i = 0; i < n; i++) {
//             currentSum += nums[i];
//             int diff = currentSum - target;

//             if (diff == 0) {
//                 maxLength = i + 1; // The entire subsequence sums to the target.
//             } else if (prefixSum.count(diff) > 0) {
//                 maxLength = max(maxLength, i - prefixSum[diff]);
//             }

//             if (prefixSum.count(currentSum) == 0) {
//                 prefixSum[currentSum] = i;
//             }
//         }

//         return maxLength;
//     }
// };
class Solution { 
public: 
    int lengthOfLongestSubsequence(vector<int>& nums, int target) { 
        vector<int> dp(target + 1, -1); 
        dp[0] = 0; 

        for (int num : nums) { 
            for (int i = target; i >= num; i--) { 
                if (dp[i - num] != -1) { 
                    dp[i] = max(dp[i], dp[i - num] + 1); 
                } 
            } 
        } 

        return dp[target]; 
         
    } 
};
