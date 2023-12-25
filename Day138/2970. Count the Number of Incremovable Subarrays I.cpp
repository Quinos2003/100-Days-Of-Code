class Solution {
public:
bool checkIncreasing(vector<int>& arr){
    if(arr.size()<=1) return true;
    int x =arr[0];
    for(int i =1 ; i < arr.size() ; i++){
        if(arr[i]<=arr[i-1]) return false;
    }
    return true;
}
    int incremovableSubarrayCount(vector<int>& nums) {
        int n = nums.size();
        int count =0;
        for(int i =0 ; i < n ; i++){
            for(int j =i+1 ; j<=n ; j++){
                vector<int> subarray(nums.begin(), nums.begin() + i);
                subarray.insert(subarray.end(), nums.begin() + j, nums.end());
                if(checkIncreasing(subarray)) count++; // i need to send subarrays from index i to j
            }
        }
        return count;
    }
};