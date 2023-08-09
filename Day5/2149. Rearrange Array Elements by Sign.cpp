class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        int p1=0; // positive ptr
        int p2=0; // negative ptr
        vector<int>ans(n);
        int turn =0; // for positive turn =0 , neg turn = 1

        for(int i =0 ; i < n ; i++){
            if(turn==0){
                if(nums[p1]>0){

                }
                else {
                    do{
                        p1++;
                    } while(nums[p1]<0);
                }
                ans[i]= nums[p1];
                turn =1; // now next negative to be appended
                p1++;
            }
            else{
                if(nums[p2]<0){

                }
                else{
                    do{
                        p2++;
                    } while(nums[p2]>0);
                }
                ans[i]= nums[p2];
                turn =0; // now next positive to be appended
                p2++;
            }
        }
        return ans;

        // int n=nums.size();
        // int pos=0;int neg=1;
        // vector<int> ans(n);
        // for(int i=0;i<n;i++){
        //     if(nums[i]<0){
        //      ans[neg]=nums[i];
        //      neg+=2;
        //     }else{
        //      ans[pos]=nums[i];
        //      pos+=2;
        //     }
        // }
        // return ans;
    }
};

// https://leetcode.com/problems/rearrange-array-elements-by-sign/