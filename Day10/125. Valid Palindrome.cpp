class Solution {
public:
    bool inRange (char ch){
        if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z')|| (ch>='0' && ch<='9'))
        return true;
        return false;
    }

    char Lowercase(char ch){
        if((ch>='a' && ch<='z') || (ch>='0' && ch<='9'))
        return ch;
        else
        return('a'+ (ch-'A'));
    }
    bool checkPalin(string temp){
        int s =0;
        int e = temp.length()-1;
        while(s<e){
            if(temp[s]!= temp[e])
            return false;
            else{
                s++;
                e--;
            }
        }
        return true;
    }

    bool isPalindrome(string s) {
        string temp="";
        int p=0;
        for(int i =0 ; i < s.length();i++){
            if( inRange(s[i])){
                temp.push_back(s[i]);
                temp[p]= Lowercase(temp[p]);
                p++;
            }
        }
        return checkPalin(temp);
    }
};
// Inbuilt functions can be used but I made them for practice
// read up on isalnum()