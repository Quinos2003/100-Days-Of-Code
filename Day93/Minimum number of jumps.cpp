class Solution{
  public:
    int minJumps(int arr[], int n){
        // Your code here
        if(n==1&& arr[0]!=0) return 0;
        int coverage=0, jump=0, lastJumpIndex=0;
        
        for(int i=0;i<n;i++){
            coverage = max(coverage, i+arr[i]);
            
            if(i==lastJumpIndex){
                jump++;
                lastJumpIndex = coverage;
                
                if(coverage>=n-1) return jump;
                
                if(i>=n-1) return -1;
            }
        }
        
        return -1;
    }
};