class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.length();
        char ch;
        int vowel1 =0;
        int vowel2 =0;
        for(int i =0 ; i < n/2 ; i++){
            ch = s[i];
            if(ch == 'a' || ch ==   'e'|| ch ==  'i'|| ch ==   'o' || ch == 'u'|| ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O'|| ch == 'U'){
                vowel1++;
            }
        }
        for(int i =n/2 ; i < n ; i++){
            ch = s[i];
            if(ch == 'a' || ch ==   'e'|| ch ==  'i'|| ch ==   'o' || ch == 'u'|| ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O'|| ch == 'U'){
                vowel2++;
            }
        }
        return vowel1==vowel2;
        
    }
};