// class Solution {
// public:
//     int stringCount(int n) {
//         if(n<4) return 0;
        
//     }
// };

// class Solution {
// public:
// const int MOD = 1e9 + 7;

//     int stringCount(int n) {
//         if(n<4) return 0;
        
//     }
// };


class Solution {
    const int MOD = 1000000007;

    int multiply(long long x, long long y) {
        return x * y % MOD;
    }

    void update(int &x, int y) {
        // Update x with y, taking the result modulo MOD
        if ((x += y) >= MOD) {
            x -= MOD;
        }
    }

public:
    int stringCount(int n) {
        // dp[i][j][k]: Number of good strings of length i, ending with characters j and k
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(2, vector<int>(3, 0)));
        dp[0][0][0] = 1;

        for (int i = 0; i < n; ++i) {
            // Temporary vector to update dynamic programming state
            vector<vector<vector<int>>> temp(2, vector<vector<int>>(2, vector<int>(3, 0)));

            for (int j = 0; j < 2; ++j) {
                for (int k = 0; k < 2; ++k) {
                    for (int h = 0; h < 3; ++h) {
                        if (dp[j][k][h] == 0) continue;

                        // Update temp based on transitions
                        update(temp[j][k][h], multiply(dp[j][k][h], 23));
                        update(temp[1][k][h], dp[j][k][h]);
                        update(temp[j][1][h], dp[j][k][h]);
                        update(temp[j][k][min(h + 1, 2)], dp[j][k][h]);
                    }
                }
            }

            // Update dp with temp
            dp = temp;
        }

        // Final result is the count of good strings of length n, ending with characters 1 and 2
        return dp[1][1][2];
    }
};



// class Solution {
// const int M = 1000000007;

// int mul(long long x, long long y) {
//     return x * y % M;
// }

// void add(int &x, int y) {
//     if ((x += y) >= M) {
//         x -= M;
//     }
// }
// public:
//     int stringCount(int n) {
//         vector<vector<vector<int>>> dp(2, vector<vector<int>>(2, vector<int>(3)));
//         dp[0][0][0] = 1;

//         for (int i = 0; i < n; ++i) {
//             vector<vector<vector<int>>> temp(2, vector<vector<int>>(2, vector<int>(3)));

//             for (int j = 0; j < 2; ++j) {
//                 for (int k = 0; k < 2; ++k) {
//                     for (int h = 0; h < 3; ++h) {
//                         if (dp[j][k][h] == 0) continue;
//                         add(temp[j][k][h], mul(dp[j][k][h], 23));
//                         add(temp[1][k][h], dp[j][k][h]);
//                         add(temp[j][1][h], dp[j][k][h]);
//                         add(temp[j][k][min(h + 1, 2)], dp[j][k][h]);
//                     }
//                 }
//             }

//             dp = temp;
//         }

//         return dp[1][1][2];
//     }
// };