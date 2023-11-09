class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // unordered_set<int> set;

        // for(int num : nums) set.insert(num);

        unordered_set<int> set(nums.begin(), nums.end());

        int lcs =0;

        for(int num : nums ){
            if(set.find(num-1)==set.end()){
                int curr = num;
                int currLCS = 1;

                while(set.find(curr+1) != set.end()){
                    curr++;
                    currLCS++;
                }
                lcs = max(lcs , currLCS);
            }
        }
        return lcs;
    }
};