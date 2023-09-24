class Solution {
public:
    int robber1(vector<int>& nums) {
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
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n<2) return nums[0];
        vector<int> temp1(n-1), temp2(n-1);
        for(int i =0; i < n-1;i++){
            temp1[i]= nums[i];
            temp2[i]= nums[i+1];
        }
        return max(robber1(temp1),robber1(temp2));
    }
};