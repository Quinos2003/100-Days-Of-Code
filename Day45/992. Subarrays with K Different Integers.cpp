class Solution {
public:
    int subArray(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int count =0, start=0,end=0;
        int n = nums.size();
        while(end<n){
            mp[nums[end]]++;
            while(mp.size()>k){  // num of disticnt> k
                mp[nums[start]]--; // remove distinct from left 
                if(mp[nums[start]]==0) mp.erase(nums[start]); // erase from map if 0
                start++;
            }
            count+= end-start+1;
            end++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subArray(nums, k) - subArray(nums, k - 1);
    }
};