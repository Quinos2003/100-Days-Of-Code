// class Solution {
// public:

// int f(int i , int j , vector<vector<int>> & grid , vector<vector<int>>& dp){
//     if(i==0 && j==0) return  grid[i][j];
//     if(i<0 || j<0) return 1e9;
//     if(dp[i][j]!=-1) return dp[i][j];
//     int up = grid[i][j] + f(i-1,j,grid,dp);
//     int left = grid[i][j] + f(i,j-1,grid,dp);
//     return dp[i][j] = min(left, up);



// }
//     int minPathSum(vector<vector<int>>& grid) {
//         int n = grid.size();
//         int m = grid[0].size();
//         vector<vector<int>> dp(n, vector<int>(m,-1));
//         return f(n-1,m-1,grid,dp);
//     }
// };
class Solution {
public:
    int minPathSum( vector<vector<int>>&matrix ) {
        int n = matrix.size();
        int m = matrix[0].size();
    vector<int> prev(m, 0); // Initialize a vector to store the previous row's minimum path sums
    for (int i = 0; i < n; i++) {
        vector<int> temp(m, 0); // Initialize a temporary vector for the current row
        for (int j = 0; j < m; j++) {
            if (i == 0 && j == 0)
                temp[j] = matrix[i][j]; // If we are at the top-left corner, the minimum path sum is the value at (0, 0)
            else {
                // Calculate the minimum path sum considering moving up and moving left
                int up = matrix[i][j];
                if (i > 0)
                    up += prev[j]; // Include the minimum path sum from above (previous row)
                else
                    up += 1e9; // A large value if moving up is not possible (out of bounds)
                int left = matrix[i][j];
                if (j > 0)
                    left += temp[j - 1]; // Include the minimum path sum from the left (current row)
                else
                    left += 1e9; // A large value if moving left is not possible (out of bounds)

                // Store the minimum path sum in temp[j]
                temp[j] = min(up, left);
            }
        }
        prev = temp; // Update the previous row with the current row
    }
    // The final result is stored in prev[m-1], which represents the destination in the last column
    return prev[m - 1];
    }
};