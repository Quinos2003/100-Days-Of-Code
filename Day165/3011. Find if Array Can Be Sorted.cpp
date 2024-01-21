// class Solution {
// public:
//     int countSetBits(int num) {
//         int count = 0;
//         while (num > 0) {
//             count += (num & 1);
//             num >>= 1;
//         }
//         return count;
//     }

//     bool canSortArray(std::vector<int>& nums) {
//         int n = nums.size();
        
//         for (int i = 1; i < n; i++) {
//             if (nums[i - 1] > nums[i]) {
//                 int bits1 = countSetBits(nums[i - 1]);
//                 int bits2 = countSetBits(nums[i]);
                
//                 if (bits1 == bits2) {
//                     std::swap(nums[i - 1], nums[i]);
//                 } else {
//                     return false; // If bits are not equal, sorting is not possible
//                 }
//             }
//         }
        
//         return true;
//     }
// };

class Solution {
public:
    int setBits(int num) {
        int count = 0;
        for (int i = 31; i >= 0; i--) {
            if (((num >> i) & 1) == 1) {
                count++;
            }
        }
        return count;
    }

    bool check(const std::vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                return false;
            }
        }
        return true;
    }

    bool canSortArray(std::vector<int>& nums) {
        int count[101];
        int j = 0, n = nums.size(), k = 0;

        for (int i : nums) {
            count[j++] = setBits(i);
        }

        while (k < nums.size()) {
            for (int i = 1; i < n; i++) {
                if (count[i] == count[i - 1] && nums[i] < nums[i - 1]) {
                    int temp = nums[i];
                    nums[i] = nums[i - 1];
                    nums[i - 1] = temp;
                }
            }
            if (check(nums)) {
                return true;
            }
            k++;
        }

        return false;
    }
};

