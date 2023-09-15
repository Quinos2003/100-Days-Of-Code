class Solution {
public:

    string frequencySort(string s) {
        unordered_map<char,int> mp;
        priority_queue<pair<int,char>> maxheap;
        for(auto x : s)   mp[x]++;
    
        for(auto it : mp )  maxheap.push({it.second , it.first});

        s="";
        while(!maxheap.empty()){
            s+=string(maxheap.top().first,maxheap.top().second);
            maxheap.pop();
        }
        return s;
    }
};