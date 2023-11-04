class Solution {
public:
    int trap(vector<int>& height) {
        int n= height.size();
        int left = 0; 
        int right =n-1;
        int sum=0;

        int leftmost =0 , rightmost =0;

        while(left<=right){

            if(height[left]<=height[right]){
                if(height[left]>= leftmost) leftmost = height[left];

                else sum+= leftmost- height[left];

                left++;
            }
            else{
                if(height[right]>= rightmost) rightmost = height[right];
                else sum+= rightmost - height[right];
                right--;
            }
        }
        return sum;
    }
};