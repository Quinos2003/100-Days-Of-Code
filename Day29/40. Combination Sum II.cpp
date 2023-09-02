class Solution {
public:
void call(vector<int>& candidates,int next , vector<int>& tsol, int target , vector<vector<int>>& ans){
    if(target ==0){
        ans.push_back(tsol);
        return;
    }
    for(int i =next ; i<candidates.size(); i ++ ){
        if(candidates[i]>target) break; 
        if(i > next && candidates[i] == candidates[i-1]) continue;

        tsol.push_back(candidates[i]);
        call(candidates , i+1 , tsol , target-candidates[i] , ans);
        tsol.pop_back();
    }
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> tsol;
        call(candidates , 0 , tsol , target , ans);
        return ans;
    }
};