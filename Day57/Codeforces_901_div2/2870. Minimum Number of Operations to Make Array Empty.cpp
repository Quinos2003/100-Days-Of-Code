class Solution {
public:
    
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> mp;
        int ans=0;
        for(int it : nums) mp[it]++;
        for( auto it : mp){
            if (it.second ==1) return -1;
            // int rem = it.second%3;
            ans+= ceil(float(it.second)/3);
            // if(rem==1 || rem==2) ans++;
        }
        return ans;
    }
};