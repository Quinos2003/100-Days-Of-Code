class Solution {
public:
    bool checkValidString(string s) {
        int balance =0;
        for (auto it : s){
            if(it==')') balance --;
            else balance ++;

            if(balance<0) return false;
        }
        if(balance==0) return true; // meaning all * used 

        balance =0;

        for(int i =s.length() -1; i >=0; i--){
            if(s[i]=='(') balance --;
            else balance ++;

            if(balance<0) return false;
        }
        return true;
    }
};