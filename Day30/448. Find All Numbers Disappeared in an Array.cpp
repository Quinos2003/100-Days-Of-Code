class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        for(auto c : nums)
            nums[abs(c)-1] = -abs(nums[abs(c)-1]);   // mark c is present by negating nums[c-1]
        for(int i = 0; i < size(nums); i++) 
            if(nums[i] > 0) ans.push_back(i+1);      // nums[i] > 0 means i+1 isnt present in nums
        return ans;
    }
};
// class Solution {
// public:
//     vector<int> findDisappearedNumbers(vector<int>& nums) {
//         unordered_set<int> s(begin(nums), end(nums));   // insert every nums[i] in hashset
//         vector<int> ans(size(nums) - size(s));
//         for(int i = 1, j = 0; i <= size(nums); i++)  
//             if(!s.count(i)) ans[j++] = i;               // add all elements not found in hashset to ans
//         return ans;
//     }
// };
// class Solution {
// public:
//     vector<int> findDisappearedNumbers(vector<int>& nums) {
//         sort(begin(nums), end(nums));
//         vector<int> ans;
//         for(int i = 1; i <= size(nums); i++) 
//             if(!binary_search(begin(nums), end(nums), i))   // binary search in nums for each i
//                 ans.push_back(i);
//         return ans;
//     }
// };