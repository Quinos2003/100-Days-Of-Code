class Solution {
public:
    bool isPalindrome(int l, int r, string s){
        while (r > l){
            if(s[l] == s[r]){
                l++;
                r--;
            } else {
                return false;
            }
        }
        return true;
    }

    bool validPalindrome(string s) {
        int l=0;
        int r=s.size()-1;
        while(l<r){
            if(s[l] == s[r]){
                l++;
                r--;
            }
            else{
                return isPalindrome(l+1,r,s) || isPalindrome(l,r-1,s);
            }
        }
        return true;
    }
};
