class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int p1 =0;
        int p2=1;
        int n=nums.size();
        if(n<=1)
        return 1;

        while(p2<n){
            if(nums[p1]==nums[p2]){
                p2++;
            }
            else{
                swap(nums[p2], nums[p1+1]);
                p1++;
                p2++;
            }
            // [0,1,0,1,1,2,2,3,3,4]
            // p1 = 1 , p2 = 3;
            // p1=1 p2= 5
            // [0,1,2,1,1,0,2,3,3,4]
            // p1 = 2 p2 = 7 // swap of these 2 positions now 
        }

        return p1+1;
    }
};