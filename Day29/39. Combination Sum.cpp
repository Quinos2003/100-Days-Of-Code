class Solution {
public:
void call(vector<int>& candidates,int next , vector<int>& tsol, int target , vector<vector<int>>& ans){
    if(target==0){
        ans.push_back(tsol);
        return;
    }
    if(next == candidates.size() || target - candidates[next]<0) return;
    tsol.push_back(candidates[next]);
    call(candidates , next , tsol , target-candidates[next] , ans);
    tsol.pop_back();
    call(candidates , next+1 , tsol , target , ans);
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        vector<int> tsol;
        call(candidates , 0 , tsol , target , ans);
        return ans;
    }
};