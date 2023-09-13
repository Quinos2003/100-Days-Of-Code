class Solution {
public:
    int minBitFlips(int start, int goal) {
        return __builtin_popcount(start^goal);
    }
};

// class Solution {
// public:
//     int minBitFlips(int start, int goal) {
//         int value = start^goal , count=0;
//         // now value has 1's that are different in both
//         while(value!=0)
//         {
//             value&=value-1;
//             count++;
//         }
//         return count;
//     }
// };