class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int actual_sum = n * (n + 1) / 2;
        int unique_sum = 0;
        int duplicate = 0;
        
        unordered_set<int> s;

        for(auto it : nums){
            if(s.insert(it).second) unique_sum+=it;
            else duplicate =it;
        }
        return {duplicate,actual_sum-unique_sum};
    }
};