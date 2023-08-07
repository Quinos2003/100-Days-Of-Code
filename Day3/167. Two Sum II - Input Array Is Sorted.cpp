class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> arr(2);

    int st=0;
    int ed=nums.size()-1;
    while(st<ed){
        if(nums[st]+nums[ed]==target)
        break;
        else if(nums[st]+nums[ed]<target)
        st++;
        else
        ed--;
    }
    arr[0]=st+1;
    arr[1]=ed+1;
    return arr;
        
    }
};