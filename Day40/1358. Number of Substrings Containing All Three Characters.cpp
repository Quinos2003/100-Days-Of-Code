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
// class Solution {
// public:
//     int numberOfSubstrings(string s) {

//         int start = 0;
//         unordered_map<char,int> mp;
//         int cnt = 0;
//         int end = 0;
//         int ans = 0;
//         while (end < s.length()) {
//             mp[s[end++]]++;

//             while (start < s.length() && mp['a'] >= 1 && mp['b'] >= 1 && mp['c'] >= 1) {
//             mp[s[start++]]--;
//             cnt++;
//             }

//             ans += cnt;
//         }
//         return ans;
//     }
// };