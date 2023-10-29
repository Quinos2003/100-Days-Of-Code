class Solution {
public:

int countPainters(vector<int> &nums, int time) {
    int n = nums.size(); 
    int painters = 1;
    long long numsPainter = 0;
    for (int i = 0; i < n; i++) {
        if (numsPainter + nums[i] <= time) {
            //allocate board to current painter
            numsPainter += nums[i];
        }
        else {
            //allocate board to next painter
            painters++;
            numsPainter = nums[i];
        }
    }
    return painters;
}

    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());

        int high = accumulate(nums.begin(), nums.end(), 0);

        while (low <= high){
            int mid = low + (high-low)/2;

            int painters = countPainters(nums, mid);

            if (painters > k) low = mid + 1;

            else high = mid - 1;

        }
        return low;
    }

};