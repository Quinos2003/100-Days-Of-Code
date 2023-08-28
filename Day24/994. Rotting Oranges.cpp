class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        // {{r,c}t}
        for(int i =0; i < m ; i ++){
            for(int j=0 ; j < n ; j++){
                if(grid[i][j]==2)
                q.push({{i,j},0});
            }
        }
        int time =0;
        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            time = max(t,time);
            for(auto dir : dirs){
                int nrow = r+dir.first;
                int ncol = c+dir.second;
                if(nrow>=0 && nrow<m && ncol >=0 && ncol<n && grid[nrow][ncol]==1){
                    grid[nrow][ncol]=2;
                    q.push({{nrow,ncol},t+1});
                }
            }
        }
        for(int i =0; i < m ; i ++){
            for(int j =0 ; j < n ; j++){
                if(grid[i][j]==1) return -1;
            }
        }
        return time;
    }
};
