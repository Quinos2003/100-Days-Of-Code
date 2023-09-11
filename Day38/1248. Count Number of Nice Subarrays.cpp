class Solution {
public:

int atMost(vector<int>& nums , int k ){
    int ans =0, i =0 , j =0 ;
    while(j<nums.size()){
        k-= nums[j]%2;
        while(k<0){
            k+= nums[i++]%2;
        }
        ans += j-i+1;
        j++;
    }
    return ans;
}
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};