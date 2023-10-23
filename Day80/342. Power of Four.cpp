// class Solution {
// public:
//     bool isPowerOfFour(int n) {
//         while(n>1){
//             if(n%4!=0) return false;
//             n/=4;
//         }
//         return n == 1;
//     }
// };
class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<0) return false;

        for(int i =0 ; i < 32 ; i +=2){
            if(n == 1<<i) return true; // basically checked all 4^1 to 4^32
        }
        return false;
    }
};
