class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int> mp;
        int count=0;
        for(auto it : nums){
            mp[it]++;
            count = max(count,mp[it]);
        }
        vector<vector<int>> ans(count);

        for(auto it : mp ){
            for(int i =0 ; i< it.second;i++){
                ans[i].push_back(it.first);
            }
        }
        return ans;
    }
};