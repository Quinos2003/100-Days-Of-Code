// class Solution {
// public:
//     int subarraySum(vector<int>& nums, int k) {
//         int sum=0;
//         int p1=0;
//         int ways =0;
//         int n = nums.size();

//         for(int i =0; i < n ; i++){
//             if(sum< k){
//                 sum+=nums[i];
//             }
//         }
        
//     }
// };

class Solution {
public:
int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int sum=0,ans=0;
        mp[sum] = 1;
        for(auto it:nums){
            sum += it;
            int find = sum - k;
            if(mp.find(find) != mp.end()){
                ans += mp[find];
            }
            mp[sum]++;
        }
        return ans;
    }
};