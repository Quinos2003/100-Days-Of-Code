class Solution {
public:
    bool canReach(vector<int>& arr, int i) {
        return i>=0 && i<arr.size() && arr[i]>=0 && (!(arr[i]= -arr[i]) || canReach(arr,i+arr[i]) || canReach(arr,i-arr[i]));
        
    }
};