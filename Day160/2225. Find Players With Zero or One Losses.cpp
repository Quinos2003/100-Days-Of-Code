class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> res;
        vector<int> oneLoss;
        unordered_set<int>zeroLoss;
        unordered_map<int,int>loss;
        for(auto match : matches) loss[match[1]]++;
        for(auto match : matches) zeroLoss.insert(match[0]);
        for(auto match : matches) zeroLoss.erase(match[1]);
        res.push_back(vector<int>(zeroLoss.begin(), zeroLoss.end()));
        for(auto it : loss){
            if(it.second==1) oneLoss.push_back(it.first);
        }
        res.push_back(oneLoss);
        sort(res[1].begin(),res[1].end());
        sort(res[0].begin(),res[0].end());
        return res;
    }
};