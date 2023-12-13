class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> row(m);
        vector<int> col(n);
        int count =0;
        
        for(int i =0 ; i < m ; i++){
            for(int j =0 ; j < n ; j++){
                if(mat[i][j]){
                    row[i]++;
                    col[j]++;
                }
            }
        }
        for(int i =0 ; i < m ; i++){
            for(int j =0 ; j < n ; j++){
                if(mat[i][j] && row[i]==1 && col[i]==1){
                    count++;
                }
            }
        }
        return count;
    }
};