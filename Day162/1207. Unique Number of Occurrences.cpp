class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;
        for( auto it : arr){
            mp[it]++;
        }
        unordered_set<int>set;
        for(auto it : mp){
            if(!set.insert(it.second).second) return false;
        }
        return true;
    }
};