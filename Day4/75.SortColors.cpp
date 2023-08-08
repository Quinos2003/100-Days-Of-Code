class Solution {
public:
    void sortColors(vector<int>& nums) {

        int s =0; // start
        int p=0 ; // iterating ptr
        int e = nums.size()-1; // end

        while(p<=e){
            if(nums[p]==0){
                swap(nums[p],nums[s]);
                p++;
                s++;
            }
            else if(nums[p]== 1){
                p++;
            }
            else{
                swap(nums[p], nums[e]);
                e--;
                // now check position p again
            }
        }
    }
};