// arr: input array
// n: size of array
class Solution
{
    public:
    int peakElement(int arr[], int n)
    {
        int mx =INT_MIN;
        int max_element =-1;
        
       for(int i =0 ; i < n ; i ++){
           if(arr[i]>mx){
               mx = arr[i];
               max_element = i;
           }
       }
       return max_element;
    }
};