class Solution {
public:
    // int minimumOneBitOperations(int n, int res = 0) {
    //     if (n == 0) return res;
    //     int b = 1;
    //     while ((b << 1) <= n)
    //         b = b << 1;
    //     return minimumOneBitOperations((b >> 1) ^ b ^ n, res + b);
    // }

    int minimumOneBitOperations(int n) {
        int res;
        for (res = 0; n > 0; n &= n - 1)
            res = -(res + (n ^ (n - 1)));
        return abs(res);
    }
};