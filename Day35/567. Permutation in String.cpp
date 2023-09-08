class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length(),n2 = s2.length();
        if(n1>n2) return false;
        unordered_map<char,int> mp,window;
        for(int i =0 ; i < n1; i++){
            mp[s1[i]]++;
            window[s2[i]]++;
        }
        if(mp == window) return true;
        int left =0 , right = n1;
        while(right < n2){
            if(window[s2[left]]==1) window.erase(s2[left]); // moving window to right remove if 0
            else window[s2[left]]--;                        // updating count of chars
            window[s2[right]]++;                            // adding right to window
            left++;
            right++;
            if(mp == window) return true;
        }
        return false;
    }
};