
class Solution {
public:

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool isValid(int i, int j ,int n , int m){
    if(i>=0 && j>=0 && i <= n-1 && j<=m-1) return true;
    return false;
}

void dfs(int i, int j, vector<vector<int>> &grid){
    grid[i][j]=2;
    int n = grid.size();
    int m = grid[0].size();
    for(int z =0 ; z < 4 ; z++){
        int nrow = dx[z] +i;
        int ncol = dy[z] +j;
        if(isValid(nrow,ncol,n,m) && grid[nrow][ncol]== 1){
            dfs(nrow,ncol,grid);
        }
    }
}

bool isBoundary(int i, int j ,int n , int m){
    if(i==0 || j==0 || i == n-1 || j==m-1) return true;
    return false;
}

    int closedIslands(vector<vector<int>>& grid, int n, int m) {
        // // Code here
        // int n = grid.size();
        // int m = grid[0].size();
        
        for(int i =0 ; i < n ; i ++){
            for( int j = 0 ; j < m ; j++){
                if(isBoundary(i,j,n,m) && grid[i][j]==1)
                    dfs(i,j,grid);
            }
        }
        
        
        int count =0;
        for(int i =0 ; i < n ; i ++){
            for( int j = 0 ; j < m ; j++){
                if(grid[i][j]==1){
                    count++;
                    dfs(i,j,grid);
                }
            }
        }
        return count;
    }
};