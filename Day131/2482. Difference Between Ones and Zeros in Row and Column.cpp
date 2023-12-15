class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> row(m);
        vector<int> col(n);
        vector<vector<int>> ans(m,vector<int>(n));

        for(int i =0 ; i < m ; i++){
            for(int j =0; j < n ; j++){
                if(grid[i][j]){
                    row[i]++;
                    col[j]++;
                }
                
            }
        }

        for(int i =0 ; i < m ; i++){
            for(int j =0; j < n ; j++){
                // cout<<i<<" "<<j<<endl;
                // cout<<"rowcolval "<<row[i]<<" "<<col[i]<<endl;
                ans[i][j]=row[i]+col[j]-(m-row[i])-(n-col[j]);
            }
        }
        return ans;
    }
};