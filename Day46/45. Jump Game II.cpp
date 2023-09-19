class Solution {
public:
    int jump(vector<int>& nums) {
        for(int i =1 ; i < nums.size(); i ++) 
        nums[i]= max(nums[i]+i, nums[i-1]);
        
        int x =0, ans =0;
        while(x< nums.size()-1){
            x = nums[x];
            ans++;
        }
        return ans;
    }
};