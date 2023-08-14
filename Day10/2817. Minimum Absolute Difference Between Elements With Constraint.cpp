class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        // Approach
        // 1. Add elements less than x to the multi set
        // 2. find the upper bound of the current element in the multi set.
        // 3. As we get the next larger number, check the diff with it and also 
        // with the previous element and take the min.

        // https://youtu.be/fCMNwd5rGc0 <-- understood by this video 

        int ans = INT_MAX;
        set<int> s;
        for(int i = x; i < nums.size(); ++i){
            s.insert(nums[i-x]);
            auto it = s.upper_bound(nums[i]);
            if(it != s.end()) ans = min(ans, abs(nums[i] - *it));
            if(it != s.begin()) ans = min(ans, abs(nums[i] - *prev(it)));
        }
        return ans;
    }
};