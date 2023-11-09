class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        if(n < 3)return {};

        sort(nums.begin(),nums.end());

        if(nums[0]>0) return {};

        unordered_map<int,int> mp;

        for(int i =0 ; i < n ; i++) mp[nums[i]]=i;

        vector<vector<int>> res;

        for(int i=0;i<n-2;i++){

            if(nums[i]>0) break;

            for(int j=i+1;j<n-1;j++){
                int need = -1 * (nums[i]+ nums[j]);

                if(mp.count(need) && mp.find(need)->second > j)
                    res.push_back({nums[i],nums[j],need});
                
                j= mp.find(nums[j])->second;
            }
            i= mp.find(nums[i])->second;

        }
        return res;
    }
};