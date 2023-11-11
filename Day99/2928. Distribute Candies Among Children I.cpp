class Solution {
public:
    int distributeCandies(int n, int limit) {
        // int maxRange = limit;
        // for(int i =0;i<3 ;i++){
        //     for(int )
        // }
        
//         if(limit>=n) return comb(n+r-1,r-1);
        
//         else{
            
//         }

        int res=0;
        for(int i =0 ; i <= n ; i++){
            for(int j=0; j <= n ; j++){
                for(int k =0; k <= n;k++){
                    if(i+j+k==n && i<=limit && j<=limit && k<=limit) res++;
                }
            }
        }
        return res;
    }
};