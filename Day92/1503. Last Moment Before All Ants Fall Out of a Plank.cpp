class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int res=0;
        for(int it : left) res = max (res,it);
        for(int it : right) res = max (res,n- it);
        return res;
    }
};