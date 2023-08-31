class Solution {
public:
void dfs(vector<vector<int>>& grid,int i , int j){
    if(i<0 || j < 0 || i>= grid.size() || j>=grid[0].size() || grid[i][j]!=1) return;
    grid[i][j]=0;
    dfs(grid, i + 1, j), dfs(grid, i - 1, j), dfs(grid, i, j + 1), dfs(grid, i, j - 1);
}
    int numEnclaves(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        for (int c = 0; c < cols; c++) {
            dfs(grid, 0, c);
            dfs(grid, rows - 1, c);
        }
        for (int r = 0; r < rows; r++) {
            dfs(grid, r, 0);
            dfs(grid, r, cols - 1); 
        }
        int cnt = 0;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == 1)
                cnt++;
            }
        }
        return cnt;
    }
};
