// class Solution {
// public:
//     bool backspaceCompare(string s, string t) {
        
//         int i = s.length()-1, j = t.length()-1;
//         int count1 =0 , count2 =0;

//         while(i>= 0 || j>=0 ){
//             while(i>=0 && (s[i]== '#' || count1>0)) s[i--]=='#' ? count1++ : --count1;
//             while(j>=0 && (t[j]== '#' || count2>0)) t[j--]=='#' ? count2++ : count2--;
//             if(i<0 || j<0) return i==j;
//             if(s[i--] != t[j--]) return false;
            
//         }
//         return i==j;
//     }
// };
class Solution {
public:
    void stringDiscardBackspace(string& str) {
        string tmp;

        for (int i = 0; i < str.length(); i++) {
            if (str[i] == '#') {
                if (tmp.length()) {
                    tmp.pop_back();
                }
                
            } else {
                tmp.push_back(str[i]);
            }
        }

        str = tmp;
    }

    bool backspaceCompare(string s, string t) {
        stringDiscardBackspace(s);
        stringDiscardBackspace(t);

        return (s == t);
    }
};