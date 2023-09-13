class Solution {
public:
    int numberOfSubstrings(string s) {
        int a=0,b=0,c=0;
        int count =0;
        int i=0,j=0;
        int n = s.length();
        bool isValid=0;
        while( j < n ){
            if(s[j]=='a') a++;
            else if(s[j]=='b') b++;
            else c++;

            isValid = a && b && c;

            while(isValid){
                if(s[i]=='a') a--;
                else if(s[i]=='b') b--;
                else c--;
                count += n - j;
                i++;
                isValid = a && b && c;
            }
            j++;
        }
        return count;
    }
};