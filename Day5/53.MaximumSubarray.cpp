class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        // Brute Force Recursion not O(n)
        // Can use Memoization Table but I don't know yet 
        // -->>>>>> REVISIT when study Memoization
        // let's try to solve by 2 pointer storing local and global max 
        // and  dp array might be the second solution 
        // -->>>>>> REVISIT for dp approach
        // Divide and Conquer already told by leetcode
        // --> left sum right sum simple

        int local =0;
        int global = INT_MIN; // need this becoz if I set local as INT_MIN it will throw error
                              // as INT_MIN + -2 is not in int range
        for(int i=0;i<n ; i++){
            local = max(nums[i], local+ nums[i] );
            global = max(global,local);
        }
        return global;
    }
};