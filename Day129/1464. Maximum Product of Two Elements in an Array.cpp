class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int x1=nums[0];
        int x2=nums[1];

        for(int i =2 ; i<n; i++){
            if(nums[i]> x1 || nums[i]>x2){
                if(nums[i]>x1){
                    x2= max(x2,x1);
                    x1=nums[i];
                }
                else{
                    x2=nums[i];
                }
            }
        }
        return(x1-1)*(x2-1);
    }
};
