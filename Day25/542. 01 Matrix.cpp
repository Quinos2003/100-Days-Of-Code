class Solution {
public:
// int dist=0;
// int bfs(vector<vector<int>>& mat, vector<pair<int,int>>&dirs , int i , int j  ){
//     int m = mat.size();
//     int n = mat[0].size();
//     // int dist =0;
//     if(mat[i][j]){
//         for(auto it : dirs){
//             int nrow = i+ it.first;
//             int ncol = j+ it.second;
//             if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && mat[nrow][ncol]==0){
//                 return dist+1;
//             }
//         }
//         for(auto it : dirs){
//             int nrow = i+ it.first;
//             int ncol = j+ it.second;
//             if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && mat[nrow][ncol]==1){
//                 dist =bfs(mat ,dirs , nrow , ncol );
//             }
//         }
//     }
//     return dist+1;
// }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        // vector<vector<int>> ans =mat; 
        // int count =0;

        // vector<pair<int,int>> dirs = {{0,1},{1,0}, {-1,0}, {0,-1}};
        // for(int i = 0 ; i < m ; i ++){
        //     for(int j =0 ; j < n ; j++){
        //         if(mat[i][j]==0){
        //             ans[i][j]=0;
        //         }
        //         else{
        //             ans[i][j] = bfs(mat ,dirs , i , j );
        //         }
        //     }
        // }
        queue<pair<pair<int , int >,int>> q;
        vector<vector<int>> vis(m, vector<int>(n,0));
        vector<vector<int>> dist(m, vector<int>(n,0));
        for(int i = 0 ; i < m ; i ++){
            for(int j =0 ; j < n ; j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                    // dist already initialised 0
                }
                else{
                    vis[i][j]=0; // already 0 had to do nothing
                }
            }
        }
        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int d = q.front().second;
            q.pop();
            dist[r][c]= d;
            for(auto it : dirs ){
                int nrow = r+ it.first;
                int ncol = c+ it.second;
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && vis[nrow][ncol]==0 ){
                    vis[nrow][ncol]= 1;
                    q.push({{nrow,ncol}, d+1});
                }
            }
        }

        return dist;
    }
};
