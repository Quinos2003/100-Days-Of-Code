// class Solution {
// public:
//     int minimumCost(vector<int>& nums) {
        
//         int min1 = INT_MAX;
//         int min2 = INT_MAX;
//         int min3 = INT_MAX;
        
//         int n = nums.size();
//         int index1=-1;
//         int index2=-1;
//         for(int i =0 ; i < n ; i++){
//             if(min1>nums[i]){
//                 min1=nums[i];
//                 index1 = i;
//             }
//         }
//         for(int i =0 ; i < n ; i++){
//             if(min2>nums[i] && i!=index1){
//                 min2=nums[i];
//                 index2 = i;
//             }
//         }
//         for(int i =0 ; i < n ; i++){
//             if(min3>nums[i]&& (i!=index1 && i!=index2)){
//                 min3=nums[i];
//             }
//         }
//         cout<<min1<<min2<<min3<<endl;
//         return min1+min2+min3;
        
//     }
// };

class Solution {
public:
    int minimumCost(vector<int>& nums) { 
        int totalCost = 0; 
        totalCost += nums[0]; 
        sort(nums.begin() + 1, nums.end()); 
        totalCost += nums[1]; 
        totalCost += nums[2]; 
        return totalCost; 
    }
};
