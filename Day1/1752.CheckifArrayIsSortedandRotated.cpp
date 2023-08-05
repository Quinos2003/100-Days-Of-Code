class Solution {
public:
    bool check(vector<int>& nums) {
        int counter=0;
        int n=nums.size();

        for(int i =0; i<n-1 ; i++ ){
            if(nums[i]<=nums[i+1]){

            }
            else{
                counter++;
            }
            if(counter>1)
            return false;

        }
        if(nums[n-1]>nums[0])
            counter++;

        if(counter>1)
        return false;

        return true;
        
    }
};