// APPROACH 1 - TLE

// class Solution {
// public:
//     double myPow(double x, int n) {
//         double temp=x;
//         if(n>0){
//         for(int i =0; i< n-1 ; i++){
//             x*= temp;
//         }
//         }
//         else{
//         long long a=n;
//         for(int i =0; i< -a+1 ; i++){
//             x/= temp;
//         }
//         }
//         return x;
//     }
// };


class Solution {
public:
 double solve(double x,int n){
          if(n==0){
            return 1; //power of 0 is 1;
        }
       double temp=myPow(x,n/2);
        temp=temp*temp;
        if(n%2==0){ // if even  return  just without doing nothing
            return temp;
        }
        else{
            return temp*x;//if odd multiple  return by multipling once more with given number
        }
    }
    double myPow(double x, int n) {
        double ans=solve(x,abs(n));
        if(n<0)
            return 1/ans;
            return ans;
    }
};