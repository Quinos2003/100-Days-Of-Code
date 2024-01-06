// class Solution {
// public:
//     int missingInteger(vector<int>& nums) {
//         int n = nums.size();
//         if (n == 0) {
//             return 1;
//         }

//         sort(nums.begin(), nums.end());
        
        
//     }
// };
class Solution {
public:
bool contains(vector<int>& nums, int value) {
    for (int num : nums) {
        if (num == value) {
            return true;
        }
    }
    return false;
}

    int missingInteger(std::vector<int>& nums) {
        int partialSum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1] + 1) {
                partialSum += nums[i];
            } else {
                break;
            }
        }

        int missingInteger = partialSum;
        while (contains(nums, missingInteger)) {
            missingInteger++;
        }
        return missingInteger;
    }
};
