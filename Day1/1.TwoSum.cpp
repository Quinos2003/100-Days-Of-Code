// https://leetcode.com/problems/top-k-frequent-elements/

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         sort(nums.begin(), nums.end());
//         int st=0;
//         int ed = nums.size()-1;


//         while(st<ed){
//             if(nums[st]+nums[ed] == target){
//                 // int arr [2] = {nums[st],nums[ed]};
//                 return {st,ed};
//             }
//             // FOR THIS SOULTION U HAVE TO STORE THE ORIGINAL ARRAY THEN
//             // ITERATE THROUGH IT TO FIND THE INEX TO RETURN 
//             // DO THAT YOURSELF
//             else if (nums[st]+nums[ed]>target)
//                 ed--;
//             else
//                 st++;
//         }
        
//         return {};
//     }
// };

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;

        int n = nums.size();

        for( int i =0 ; i <n ; i ++){
            // if we don't get the difference, then add the index in map
            if(mp.find(target - nums[i])== mp.end()){
                mp[nums[i]] = i;
            }
            else
            return {mp[target-nums[i]], i};

        }
        return {};
    }
};