// class Solution {
// public:
//     int kthGrammar(int N, int K) {
//         int n;
//         for (n = 0, K -= 1; K ; K &= (K - 1)) n++;
//         return n & 1;
//     }
// };
class Solution {
public:
    int kthGrammar(int N, int K) {
        return __builtin_popcount(K - 1) & 1;
    }
};