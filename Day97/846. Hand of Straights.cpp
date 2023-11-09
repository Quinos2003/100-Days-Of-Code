class Solution {
public:
    bool isNStraightHand(vector<int> hand, int groupSize) {
        map<int, int> mp;
        for(int it : hand) mp[it]++;
        queue<int> start;

        int last_checked = -1;
        int opened = 0;
        for (auto it : mp) {
            int i = it.first;
            if (opened > 0 && i > last_checked + 1 || opened > mp[i]) return false;
            start.push(mp[i] - opened);
            last_checked = i, opened = mp[i];
            if (start.size() == groupSize) {
                opened -= start.front();
                start.pop();
            }
        }
        return opened == 0;
    }
};