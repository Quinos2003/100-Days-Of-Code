// class Solution {
// public:
//     string longestPalindrome(string s) {
//         int n = s.size();
//         int table[n][n];
//         memset(table,-1,sizeof(table));
//         for(int i =0 ; i < n; i++) table[i][i]=1;

//         int maxLen =1;
//         int start =0 ;
//         for(int i =0 ; i < n-1; i ++){
//             if(s[i]==s[i+1]){
//                 table[i][i+1]=1;
//                 start = i;
//                 maxLen=2;
//             }
//         }

//         for(int k=3; k <=n;k++){ // k= length of substring
//             for(int i =0 ; i < n-k+1;i++){
//                 int j = i+k-1; // end index
//                 if(table[i+1][j-1]==1 && s[i]==s[j]){
//                     table[i][j]=1;
//                     if(k>maxLen){
//                         start = i; 
//                         maxLen=k;
//                     }
//                 } 
//             }

//         }
//         return s.substr(start,maxLen);
//     }
// };
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if (n <= 1) {
            return s;
        }

        int start = 0;  // Start index of the longest palindrome
        int maxLen = 1; // Length of the longest palindrome

        for (int i = 0; i < n; ) {
            int left = i;
            int right = i;

            // Skip identical characters at the center
            while (right < n - 1 && s[right] == s[right + 1]) {
                right++;
            }

            i = right + 1; // Move i to the next different character

            // Expand around the center
            while (left > 0 && right < n - 1 && s[left - 1] == s[right + 1]) {
                left--;
                right++;
            }

            // Calculate the length of the current palindrome
            int len = right - left + 1;

            // Update start and maxLen if the current palindrome is longer
            if (len > maxLen) {
                start = left;
                maxLen = len;
            }
        }

        return s.substr(start, maxLen);
    }
};