// // Function to find the minimum absolute difference between two subset sums
// int minSubsetSumDifference(vector<int>& nums, int n) {
//     int totSum = 0;

//     // Calculate the total sum of the numsay
//     for (int i = 0; i < n; i++) {
//         totSum += nums[i];
//     }

//     // Initialize a DP table to store the results of the subset sum problem
//     vector<vector<bool>> dp(n, vector<bool>(totSum + 1, false));

//     // Base case: If no elements are selected (sum is 0), it's a valid subset
//     for (int i = 0; i < n; i++) {
//         dp[i][0] = true;
//     }

//     // Initialize the first row based on the first element of the numsay
//     if (nums[0] <= totSum)
//         dp[0][totSum] = true;

//     // Fill in the DP table using a bottom-up approach
//     for (int ind = 1; ind < n; ind++) {
//         for (int target = 1; target <= totSum; target++) {
//             // Exclude the current element
//             bool notTaken = dp[ind - 1][target];

//             // Include the current element if it doesn't exceed the target
//             bool taken = false;
//             if (nums[ind] <= target)
//                 taken = dp[ind - 1][target - nums[ind]];

//             dp[ind][target] = notTaken || taken;
//         }
//     }

//     int mini = 1e9;
//     for (int i = 0; i <= totSum; i++) {
//         if (dp[n - 1][i] == true) {
//             // Calculate the absolute difference between two subset sums
//             int diff = abs(i - (totSum - i));
//             mini = min(mini, diff);
//         }
//     }
//     return mini;
// }
// // Tabulation apporach above 
#include <bits/stdc++.h>
using namespace std;

// Function to find the minimum absolute difference between two subset sums
int minSubsetSumDifference(vector<int>& nums, int n) {
    int totSum = 0;

    // Calculate the total sum of the numsay
    for (int i = 0; i < n; i++) {
        totSum += nums[i];
    }

    // Initialize a boolean vector 'prev' to represent the previous row of the DP table
    vector<bool> prev(totSum + 1, false);

    // Base case: If no elements are selected (sum is 0), it's a valid subset
    prev[0] = true;

    // Initialize the first row based on the first element of the numsay
    if (nums[0] <= totSum)
        prev[nums[0]] = true;

    // Fill in the DP table using a bottom-up approach
    for (int ind = 1; ind < n; ind++) {
        // Create a boolean vector 'cur' to represent the current row of the DP table
        vector<bool> cur(totSum + 1, false);
        cur[0] = true;

        for (int target = 1; target <= totSum; target++) {
            // Exclude the current element
            bool notTaken = prev[target];

            // Include the current element if it doesn't exceed the target
            bool taken = false;
            if (nums[ind] <= target)
                taken = prev[target - nums[ind]];

            cur[target] = notTaken || taken;
        }

        // Set 'cur' as the 'prev' for the next iteration
        prev = cur;
    }

    int mini = 1e9;
    for (int i = 0; i <= totSum; i++) {
        if (prev[i] == true) {
            // Calculate the absolute difference between two subset sums
            int diff = abs(i - (totSum - i));
            mini = min(mini, diff);
        }
    }
    return mini;
}

int main() {
    vector<int> nums = {1, 2, 3, 4};
    int n = nums.size();

    cout << "The minimum absolute difference is: " << minSubsetSumDifference(nums, n);

    return 0;
}
// SPACE OPTIMIZATION