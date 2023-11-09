class Solution {
private:
    void dfs(unordered_map<string, multiset<string>>& mp,string airport,vector<string>& res) {
        
        while (!mp[airport].empty()) {
            string next = *mp[airport].begin();
            mp[airport].erase(mp[airport].begin());
            dfs(mp, next, res);
        }
        res.push_back(airport);
    }

public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, multiset<string>> mp;
        for (int i = 0; i < tickets.size(); i++) {
            mp[tickets[i][0]].insert(tickets[i][1]);
        }
        vector<string> res;
        dfs(mp, "JFK", res);
        reverse(res.begin(), res.end());
        return res;
    }
};