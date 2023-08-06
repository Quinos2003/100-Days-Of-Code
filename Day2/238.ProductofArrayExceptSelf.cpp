class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod_all=1;
        int zero_array_check=0;
        int n = nums.size();
        vector<int> ans(nums.size(),0);
        for(int i = 0 ; i <n; i++){
            if(nums[i]==0)
            zero_array_check++;

            else
            prod_all *= nums[i];
        }

        if(zero_array_check>1){

        }

        else if(zero_array_check==1){

            for(int i = 0 ; i <n; i++){
                if(nums[i]==0)
                ans[i]= prod_all;
            }
        }
        else{
            for(int i = 0 ; i <n; i++){
                ans[i]= prod_all / nums[i];
            }
        }
        return ans;

        
    }
};