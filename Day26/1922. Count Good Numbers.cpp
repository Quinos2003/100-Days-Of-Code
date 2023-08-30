class Solution {
public:
    long long power(long long x, long long y, int mod) {
        if(y == 0)
            return 1;
        
       long long ans = power(x, y/2, mod);
        
        if(y % 2 == 0)
            // when y is even
            return (ans * ans) % mod;
        
        else
            // whwn y is odd
            return (((ans * ans) % mod) * x) % mod;
        
    }
    
    int countGoodNumbers(long long n) {
        // long long total=1;
       
//         // // But this apprach gave TLE for large value of n
//         // for(int i=0;i<n;i++){
//         //     if(i%2==0){
//         //         total*=5;
//         //         total=(total%mod);
//         //     }
//         //     else{
//         //         total*=4;
//         //         total=(total%mod);
//         //     }
//         // }
//         // return total%mod;
//         // return (pow(4,n/2))*pow(5,(n/2+n%2));
        // optimal Approach
        int mod = 1e9+7;
        long long even=(n/2)+(n%2);
        long long odd=(n/2);
        return (power(5, even, mod) * power(4, odd, mod)) % mod;
    }
};