class Solution {
public:
    
int sqDistinct(vector<int>& nums, int a , int b){
    unordered_set<int> set;
    int count=0;
    for(int i =a ; i <=b ; i++){
        if(set.insert(nums[i]).second) count++;
    }
    return count*count;
}
    
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int sum =0;
        for(int i =0 ; i < n ; i++){
            for(int j =i ; j< n ; j++){
                sum+= sqDistinct(nums,i,j);
            }
        }
        return sum;
    }
};