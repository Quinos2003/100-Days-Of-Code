class Solution {
public:
    bool isIsomorphic(string s, string t){
        unordered_map<char,char> mp;
        unordered_map<char,bool> vis;
        for(int i  =0 ; i < s.length() ; i++){
            if(mp.count(s[i])){
                if(mp[s[i]]!=t[i]) return false;
            }
            else{
                if(vis[t[i]]) return false;

                mp[s[i]] = t[i];
                vis[t[i]] = true;
            }
        }
        return true;
    }
};