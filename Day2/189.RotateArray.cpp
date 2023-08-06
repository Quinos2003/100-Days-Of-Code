class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        int n = nums.size();
        int p1= n-(k%n);
        int t=p1;
        vector<int> ans;

        while(p1<n){
            ans.push_back(nums[p1]);
            p1++;
        }

        for(int i =0 ; i <t; i++){
            ans.push_back(nums[i]);
        }
        
        for(int i = 0 ; i <n ; i++){
            nums[i]= ans[i];
        }
    }
};