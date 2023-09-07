
class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> mp;
        int i =0 , j=0 , ans =0;
        int maxC=0;
        
        while(j < s.length()){
            mp[s[j]]++;
            maxC = max( maxC , mp[s[j]]);

            int window = j-i+1;

            if( window - maxC > k ){ // meaning window size shrink i++
                mp[s[i]]--;
                i++;
            }
            window =j-i+1;
            ans = max ( ans , window);
            j++;
        }
        return ans;
    }
};