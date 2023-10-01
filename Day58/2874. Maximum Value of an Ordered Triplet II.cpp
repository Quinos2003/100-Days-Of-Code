class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        multiset<int> st(nums.begin() + 1, nums.end()); // Create a multiset with elements from nums[1] to nums[n-1]
        int mx = nums[0]; // Initialize mx as the first element of the array
        long long ans = 0; // Initialize the result

        for (int i = 1; i < nums.size() - 1; i++) {
            st.erase(st.find(nums[i])); // Remove the current element from the multiset
            int end = (*(--st.end())); // Get the second maximum element from the multiset
            ans = max(ans, (mx - nums[i]) * 1LL * end); // Calculate the value of the triplet and update the result
            mx = max(mx, nums[i]); // Update mx if necessary
        }

        return ans; // Return the maximum value found
    }
};