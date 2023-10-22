
class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n = nums.size();
       
        int s = INT_MAX;
        vector<int> min_left(n, INT_MAX);
        vector<int> min_right(n, INT_MAX);

        min_left[0] = nums[0];
        min_right[n - 1] = nums[n - 1];

        for (int i = 1; i < n; i++) {
            min_left[i] = min(min_left[i - 1], nums[i]);
        }

        for (int i = n - 2; i >= 0; i--) {
            min_right[i] = min(min_right[i + 1], nums[i]);
        }

        for (int j = 1; j < n - 1; j++) {
            int num_j = nums[j];
            int num_i = min_left[j - 1];
            int num_k = min_right[j + 1];

            if (num_i < num_j && num_k < num_j) {
                s = min(s, num_i + num_j + num_k);
            }
        }

        return (s != INT_MAX) ? s : -1;
    }
};
// class Solution {
// public:
//     int minimumSum(vector<int>& nums) {
//         const int n = nums.size();
//         vector<int> p(n, INT_MAX);
//         for (int i = 0; i < n; ++i) {
//             for (int j = i + 1; j < n; ++j) {
//                 if (nums[j] > nums[i]) {
//                     p[j] = min(p[j], nums[i]);
//                 }
//             }
//         }
//         int r = INT_MAX;
//         for (int i = 0; i < n; ++i) {
//             if (p[i] < INT_MAX) {
//                 for (int j = i + 1; j < n; ++j) {
//                     if (nums[j] < nums[i]) {
//                         r = min(r, p[i] + nums[j] + nums[i]);
//                     }
//                 }
//             }
//         }
//         return r == INT_MAX ? (-1) : r;
        
//     }
// };