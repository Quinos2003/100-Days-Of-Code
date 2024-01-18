class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> mp;
        for(auto it : tasks) mp[it]++;
        int count =0;
        for(auto it : mp){
            if(it.second <2) return -1;
            count+= ceil((float)(it.second)/3);
        }
        return count;
    }
};