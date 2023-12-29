class Solution {
    const static int N = 127;

    // dp[left][k] means the minimal coding size for substring 
    // s[left:] and removing at most k chars
    int dp[N][N];

    string str;
    int n;

    // get length of digit
    inline int xs(int x) { return x == 1 ? 0 : x < 10 ? 1 : x < 100 ? 2 : 3; }

    int solve(int left, int k) {
        if(k < 0) return N;  // invalid, return INF
        if(left >= n or n - left <= k) return 0;  // empty

        int& res = dp[left][k];
        if(res != -1) return res;
        res = N;

        int cnt[26] = {0};
        // we try to make s[left:j] (both inculded) as one group,
        // and all chars in this group should be the same.
        // so we must keep the most chars in this range and remove others
        // the range length is (j - left + 1)
        // and the number of chars we need to remove is (j - left + 1 - most)
        for(int j = left, most = 0; j < n; j++) {
            most = max(most, ++cnt[str[j] - 'a']);  // most = max(count(s[left:j])
            res = min(res, 1 + xs(most) + solve(j + 1, k - (j - left + 1 - most)));
        }
        return res;
    }
public:
    int getLengthOfOptimalCompression(string s, int k) {
        memset(dp, -1, sizeof(dp));
        str = s;
        n = s.size();
        return solve(0, k);
    }
};

// Intuition
// suppose we have the original string s[0..n):

// _ _ _ _ _ ... _ _ _ _
// ↑                   ↑
// 0                  n-1
// after compression, we would have something like this:
// c1n1 c2n2 ... cmnm
// where ci is the letter, ni is the time it repeats.(ni possibly is 1, and it should be removed)

// key point: c1n1 must come from the prefix of the original string.

// But we don't know how long it is. So we must try to iterate every possible length:
// s[0..i], i ∈ [0, n)

// consider with the prefix string s[0..i], what the minimum size we can obtain after compression?
// the original string now become two parts: [0..i] and [i+1, n)

// _ _ _ _  | _ _ ... _ _ _ _
// ↑      ↑   ↑             ↑
// 0      i  i+1           n-1
// the first part [0..i] would result in c1n1 after compression.
// so how to delete?

// let's represent the first part [0..i] as follows:
// c1n1 c2n2 ... cmnm
// there are n1 number of c1 in this part;
// there are n2 number of c2 in this part;
// ...

// apparently, sum(n1 + n2 + ... + nm) == i+1
// again, suppose n1 <= n2 <= n3 ... <= nm.
// Now, how to delete?

// As far as we know, [0..i] will result in ONLY 1 group like cn, where c is one of letters in that part, n is the repeat times of c.(if n == 1, n can be removed)

// We can select a letter which appears maximum times among this part, this decision can lead to the optimal solution.

// Prove:
// assume we randomly selected a letter cj(j is in [1, m]), then sum(n1 + n2 + ... + nm - nj) should be minimum.
// because we should use as less as possible deletions so that we have more chances to delete for the second part [i+1, n), thus lead to optimal solution as much as possible.
// that is, we can take the maximum nj so that sum(i + 1 - nj) could be minimum.
// So, among all letters in first part [0..i], we select the letter which appears maximum times. In the meanwhile, remove all other letters.

// DP definition
// dp(i, k): the minimum size of compression by deleting at most k letters for the substring [i..n), which is the suffix string of original string s.
// where,
// 0 <= i < n
// 0 <= k <= n