class Solution {
public:
    int atMostK(vector<int>& nums, int k) {
        int i =0, j=0;
        int sum =0, count =0;
        while(j<nums.size()){
            sum+=nums[j++];
            while(i<j && sum>k ) sum-= nums[i++];
            count+= j-i;
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMostK(nums, goal)-atMostK(nums, goal-1);
    }
};
