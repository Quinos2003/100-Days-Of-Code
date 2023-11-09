class Solution {
public:
    int countHomogenous(string s) {
        int mod = 1e9+7;
        int currCount =1;
        int sum =1;
        for(int i =1 ; i < s.length() ; i++){
            if(s[i]==s[i-1]) currCount++;
            else currCount =1;

            sum = (sum+currCount)%mod;
        }
        return sum;
    }
};