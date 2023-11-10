class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        int n = adjacentPairs.size();
        unordered_map<int, vector<int>> mp;
        
        for(auto &num : adjacentPairs ){
            mp[num[0]].push_back(num[1]);
            mp[num[1]].push_back(num[0]);
        }

        vector<int>res;

        for(auto &entry : mp){
            if (entry.second.size() == 1) {
                res = {entry.first, entry.second[0]};
                break;
            }
        }

        while(res.size()<= n){
            int last = res[res.size()-1];
            int prev = res[res.size()-2];
            vector<int> candidates = mp[last];

            int next = (candidates[0]!=prev)? candidates[0] : candidates[1];
            res.push_back(next);
        }
        return res;
    }
};