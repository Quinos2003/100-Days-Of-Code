// class Solution {
// public:
//     int minimumArrayLength(vector<int>& nums) {
//         int n = nums.size();
//         while (true) {
//             int minIndex1 = -1, minIndex2 = -1;
//             for (int i = 0; i < n; ++i) {
//                 for (int j = i + 1; j < n; ++j) {
//                     if (nums[i] > 0 && nums[j] > 0 && (minIndex1 == -1 || nums[i] % nums[j] < nums[minIndex1] % nums[minIndex2])) {
//                         minIndex1 = i;
//                         minIndex2 = j;
//                     }
//                 }
//             }
//             if (minIndex1 == -1) {
//                 break;
//             }
//             nums.push_back(nums[minIndex1] % nums[minIndex2]);
//             nums.erase(nums.begin() + minIndex1);
//             nums.erase(nums.begin() + minIndex2 - 1);
//         }
//         return nums.size();
//     }
// };
class Solution {
public:
    int gcd(int x, int y) {
        while (y != 0) {
            int temp = y;
            y = x % y;
            x = temp;
        }
        return x;
    }

    int minimumArrayLength(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        if (n > 2 && nums[0] != nums[1])
            return 1;

        int d = nums[0]; // greatest common divisor

        for (int it : nums) {
            d = gcd(d, it);
        }

        int count = 0;

        for (int it : nums) {
            if (it == d)
                count++;
        }

        return max(1, (count + 1) / 2);
    }
};