// 231. Power of Two
class Solution {
public:
    // bool isPowerOfTwo(int n) {
    //     if(n==0) return false;
    //     while(n%2==0) n/=2;
    //     return n==1;
    // }
    bool isPowerOfTwo(int n) {
        if(n<=0) return false;
        return (n&n-1)==0;
    }
    // bool isPowerOfTwo(int n) {
    //     if(n==0) return false;
    //     return (n>0)&&(1073741824%n==0);
    // }
};

// https://leetcode.com/problems/power-of-two/solutions/1638704/c-easy-to-solve-all-interview-approaches-with-detailed-explanations/