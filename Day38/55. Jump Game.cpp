class Solution {
public:
    // bool canJump(vector<int>& nums) {
        // int p1 =0;
        // while(p1<nums.size()){
        //     int max_index=p1, local_max =-1;
        //     for(int i =p1 ; i < p1+ nums[p1]; i ++){
        //         if(local_max<nums[i]){
        //             max_index= i ;
        //         }
        //     }
        //     p1 = max_index;
        //     if(local_max ==0) return false;
        // }
        // return true;
    // }
    bool canJump(vector<int>& nums) {
    int farest = 0;
    for(int i = 0;i < nums.size(); i++){
        if(farest < i) return false;
        farest = max(i + nums[i], farest);
    }
    return true;
    }
};
