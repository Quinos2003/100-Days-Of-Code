class Solution {
public:
    int searchInsert(vector<int>& nums, int k) {
        int n = nums.size();

        if(k>nums[n-1])
        return n;

        int l =0 ;
        int r = n-1;

        while (l<r){
            int m = l+(r-l)/2;
            if(nums[m]>=k){
                r=m;
            }
            else
            l=m+1;
        }
        return l;

        
    }
};