class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);

        for (char ch : s) freq1[ch - 'a']++;

        for (char ch : t) freq2[ch - 'a']++;
        int steps = 0;
        for (int i = 0; i < 26; i++) {
            steps += abs(freq1[i] - freq2[i]);
        }
        return steps / 2;  
    }
};