class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {

        int global_cnt =0;
        int local = 0;

        for ( int i =0 ; i < nums.size(); i ++){
            if(nums[i]!=1){
                global_cnt= max(global_cnt,local);
                local=0;
            }
            else 
            local++;
        }
        return max(global_cnt,local);
    }
};