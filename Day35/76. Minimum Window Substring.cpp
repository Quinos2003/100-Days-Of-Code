/*
    Given 2 strings s & t, return min window substring
    of s such that all chars in t are included in window
    Ex. s = "ADOBECODEBANC" t = "ABC" -> "BANC"

    Sliding window + hash map {char -> count}
    Move j until valid, move i to find smaller

    Time: O(m + n)
    Space: O(m + n)
*/
// My solution 
class Solution {
public:
    string minWindow(string s, string t) {
        int n1 = s.length() , n2 = t.length();
        // if(n2>n1 || n2==0) return "";
        // string ans = "";
        unordered_map<char,int> mp;
        
        for(int i =0 ; i < n2 ; i ++){
            mp[t[i]]++;
        }
        // int uniqueCharsNeeded = mp.size();
        int i = 0;
        int j = 0;
        int ansIndexSt = 0;
        int ansLength = INT_MAX;
        int totalChars = n2;

        while(j<n1){
            if(mp[s[j]]>0) totalChars--;
            mp[s[j]]--;
            j++;
            // if a char is part of t then totalChars-- and count-- in map

            while(totalChars ==0){
                if(j-i < ansLength){
                    ansIndexSt = i;
                    ansLength = j-i;
                }
                // updated shorter window size
                mp[s[i]]++;
                if (mp[s[i]] > 0) {
                    totalChars++;
                }
                i++;
            }
        }
        if (ansLength != INT_MAX) {
            return s.substr(ansIndexSt, ansLength);
        }
        return "";
    }
};

// class Solution {
// public:
//     string minWindow(string s, string t) {
//         // count of char in t
//         unordered_map<char, int> m;
//         for (int i = 0; i < t.size(); i++) {
//             m[t[i]]++;
//         }
        
//         int i = 0;
//         int j = 0;
        
//         // # of chars in t that must be in s
//         int counter = t.size();
        
//         int minStart = 0;
//         int minLength = INT_MAX;
        
//         while (j < s.size()) {
//             // if char in s exists in t, decrease
//             if (m[s[j]] > 0) {
//                 counter--;
//             }
//             // if char doesn't exist in t, will be -'ve
//             m[s[j]]--;
//             // move j to find valid window
//             j++;
            
//             // when window found, move i to find smaller
//             while (counter == 0) {
//                 if (j - i < minLength) {
//                     minStart = i;
//                     minLength = j - i;
//                 }
                
//                 m[s[i]]++;
//                 // when char exists in t, increase
//                 if (m[s[i]] > 0) {
//                     counter++;
//                 }
//                 i++;
//             }
//         }
        
//         if (minLength != INT_MAX) {
//             return s.substr(minStart, minLength);
//         }
//         return "";
//     }
// };
