class Solution {
public:
    
long long helper(int x){
    long long X = (long long) x;
    return (X*(X-1))/2;
}
    long long distributeCandies(int n, int limit) {
        if (n > 3 * limit ) return 0;
        
        long long ans = helper(n + 2);
        
        if (n > limit) {
            ans -= 3 * helper(n - limit + 1);
        }

        if (n - 2 >= 2 * limit) {
            ans += 3 * helper(n - 2 * limit);
        }
        return ans;
    }
};