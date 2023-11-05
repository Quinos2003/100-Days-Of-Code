class Solution {
public:
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool isValid(int i, int j ,int n , int m){
    if(i>=0 && j>=0 && i <= n-1 && j<=m-1) return true;
    return false;
}

void dfs(int i, int j, vector<vector<int>> &grid,vector<vector<int>> & vis){
    vis[i][j]=1;
    int n = grid.size();
    int m = grid[0].size();
    for(int z =0 ; z < 4 ; z++){
        int nrow = dx[z] +i;
        int ncol = dy[z] +j;
        if(isValid(nrow,ncol,n,m) && grid[nrow][ncol] && !vis[nrow][ncol]){
            dfs(nrow,ncol,grid,vis);
        }
    }
}

int count_islands(vector<vector<int>> & grid){
    int islands = 0;
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int> (m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && grid[i][j])
            {
                dfs(i, j, grid, vis);
                islands ++;
            }
        }
    }
    return islands;
}

    int minDays(vector<vector<int>>& grid) {
        int islands = count_islands(grid);
        int n = grid.size();
        int m = grid[0].size();


        if (islands > 1 || islands == 0) return 0;

        else{
            for (int i = 0 ; i < n; i ++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (grid[i][j])
                    {
                        grid[i][j] = 0;
                        islands = count_islands(grid);
                        grid[i][j] = 1;
                        if (islands > 1 || islands == 0) return 1;
                    }

                }
            }
        }
        return 2;
    }
};