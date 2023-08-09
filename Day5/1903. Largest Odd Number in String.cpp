class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.length();
        int end = n-1;

        if(num[end]%2==1)
        return num;
        else{
            while((num[end]%2)==0){

                end--;
            }
            if(end<=0)
            return "";
            return num.substr(0,end);

        }
    }
};