class Solution {
public:
    int myAtoi(string s) {
        int result = 0, n = s.size(), i = 0, check = 1;
        while (i < n && s[i] == ' ')i++;
        // Checking sign 
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            check = (s[i] == '-') ? -1 : 1;
            i++;
        }

        while (i < n &&  (s[i]>='0' && s[i]<='9')) {
            int k = s[i] - '0';
            if (result > (INT_MAX - k) / 10){
            return check == -1 ? INT_MIN : INT_MAX;
            }
            result = result * 10 + k;
            i++;
        }
        return result * check ;
    }
};