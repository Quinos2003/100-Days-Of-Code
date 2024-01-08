class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int xorSum = 0;
        for (int num : nums) {
            xorSum ^= num;
        }
        
        int res = 0;
        k ^= xorSum;
        while (k > 0) {
            res += k & 1;
            k >>= 1;
        }
        
        return res;
    }
};