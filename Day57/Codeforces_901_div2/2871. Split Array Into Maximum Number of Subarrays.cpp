class Solution {
public:
    bool check(vector<int>& arr){
        int x=INT_MAX;
        for( auto it : arr){
            x&=it;
        }
        return x==0;
    }
    int maxSubarrays(vector<int>& nums) {
        int count=0;
        vector<int> arr;
        for(auto it : nums){
            arr.push_back(it);
            if(check(arr)){
                count++;
                arr.clear();
            }
        }
        if(count ==0) return 1;
        return count;
    }
};