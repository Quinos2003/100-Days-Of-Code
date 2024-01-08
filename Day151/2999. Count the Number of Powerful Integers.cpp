class Solution {
public:
    using ll = long long;  

    ll dp[16][2][2];
    string startStr, finishStr, targetStr;
    ll limit, size, length;

    ll countPowerfulIntegers(ll level, bool lowerBound, bool upperBound) {
        if (level == size) return 1;
        if (dp[level][lowerBound][upperBound] != -1) return dp[level][lowerBound][upperBound];

        ll count = 0;
        ll lower = 0, upper = limit;

        if (lowerBound) lower = startStr[level] - '0';
        if (upperBound) upper = min(upper, 1LL * (finishStr[level] - '0'));

        for (int i = lower; i <= upper; i++) {
            bool newLowerBound = lowerBound, newUpperBound = upperBound;

            if (i != (startStr[level] - '0')) newLowerBound = false;
            if (i != (finishStr[level] - '0')) newUpperBound = false;

            if (level < length) {
                count += countPowerfulIntegers(level + 1, newLowerBound, newUpperBound);
            } else {
                if ((targetStr[level - length] - '0') == i) {
                    count += countPowerfulIntegers(level + 1, newLowerBound, newUpperBound);
                }
            }
        }
        return dp[level][lowerBound][upperBound] = count;
    }

    ll numberOfPowerfulInt(ll start, ll finish, int limit, string s) {
        startStr = to_string(start);
        finishStr = to_string(finish);
        string padding = "";
        int difference = finishStr.size() - startStr.size();
        while (difference--) padding += '0';
        startStr = padding + startStr;
        memset(dp, -1, sizeof(dp));
        this->limit = limit;
        size = finishStr.size();
        targetStr = s;
        length = finishStr.size() - targetStr.size();
        return countPowerfulIntegers(0, 1, 1);
    }
};