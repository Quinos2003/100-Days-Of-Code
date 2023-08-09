// class Solution {
// public:
//     void nextPermutation(vector<int>& nums) {
//         int n = nums.size();
        
        
//         // Can use hashmap so maps numbers with positions but extra constant space mentioned
//         // Can run pointer from right to scan bigger number
//         if(n==1){} else{
//         int cmp = nums[n-1];

//         int reverseNeed=1;

//         for(int i =n-2 ; i >= 0 ; i-- ){
//             if(cmp > nums[i]){
//                 reverseNeed =0;
//                 swap(nums[i],nums[i+1]);
//                 return;
//             }
//             else{
//                 cmp=nums[i];
//             }
//         }
//         if(reverseNeed==1){
//             reverse(nums.begin(),nums.end());
//         }
//         // Commented reverseNeed by puting return ; above

//         }
//     }
// };
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), index = -1;
        for(int i=n-2; i>=0; i--){
            if(nums[i] < nums[i+1]){
                index = i;
                break;
            }
        }
        for(int i=n-1; i>=index && index != -1; i--){
            if(nums[i] > nums[index]){
                swap(nums[i], nums[index]);
                break;
            }
        }
        reverse(nums.begin() + index + 1, nums.end());
    }
};