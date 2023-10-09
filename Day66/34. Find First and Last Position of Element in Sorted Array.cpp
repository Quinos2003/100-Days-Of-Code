class Solution {
public:
    int lower_bound(vector<int>& nums , int low , int high , int target){
        while(low<= high){
            int mid = (low+high)>>1;
            if(nums[mid]<target) low = mid+1;
            else high = mid-1;
        }
        return low;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int low =0 , high = n-1;
        int startingPos = lower_bound(nums, low, high , target);
        int endingPos = lower_bound(nums , low , high , target +1 )-1;

        if(startingPos < nums.size() && nums[startingPos]==target) return {startingPos,endingPos};
        return{-1,-1};
    }
};