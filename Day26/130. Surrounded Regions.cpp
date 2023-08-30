class Solution {
public:
void dfs(int r , int c,vector<vector<int>>& vis,vector<vector<char>>& board ){
    int m = board.size();
    int n = board[0].size();
    vis[r][c]=1;
    vector<pair<int,int>> dirs = {{0,1}, {1,0}, { -1,0}, {0,-1}};
    for(auto it : dirs ){
        int nrow = r + it.first;
        int ncol = c + it.second;
        if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && vis[nrow][ncol]==0 && board[nrow][ncol]=='O' ){
            dfs(nrow, ncol , vis, board );
        }
    }
}
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        if(m<3 || n<3 ) return;
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int j=0; j < n ; j++){
            if(!vis[0][j] && board[0][j]=='O'){
                dfs(0,j,vis,board);
            }
            if(!vis[m-1][j] && board[m-1][j]=='O'){
                dfs(m-1,j,vis,board);
            }
        }
        for(int i=0; i < m ; i++){
            if(!vis[i][0] && board[i][0]=='O'){
                dfs(i,0,vis,board);
            }
            if(!vis[i][n-1] && board[i][n-1]=='O'){
                dfs(i,n-1,vis,board);
            }
        }
        for(int i =0 ; i < m ; i ++){
            for ( int j =0 ; j < n ; j++){
                if(board[i][j]=='O' && !vis[i][j])
                board[i][j]='X';
            }
        }
    }
};
// ALternate approach to go with Bfs of each cell while keeping count and visit array changing 'O' to B then check to change 
// class Solution {
// public:
// bool validPos(vector<vector<char>>& board,int r , int c ){
//     int m = board.size();
//     int n = board[0].size();
//     // int r = q.front().first.first;
//     // int c = q.front().first.second;
//     if(r>=1 && c>=1 &&r<m-1 && c<n-1) return true;
//     return false;
// }
//     void solve(vector<vector<char>>& board) {
//         int m = board.size();
//         int n = board[0].size();
//         if(m<3 || n<3 ) return;
//         queue<pair<pair<int,int>,int>>q;
//         vector<pair<int,int>> dirs = {{0,1}, {1,0}, { -1,0}, {0,-1}};
//         for(int i =0 ; i < m ; i ++){
//             for ( int j =0 ; j < n ; j++){
//                 if(board[i][j]=='O' && validPos(board,i,j))
//                 q.push({{i,j},0});
//             }
//         }
//         while(!q.empty()){
//             int r = q.front().first.first;
//             int c = q.front().first.second;
//             int d = q.front().second;
//             q.pop();
//             for(auto it : dirs){
//                 int nrow = r + it.first;
//                 int ncol = c + it.second;
//                 // if()
//             }
//         }
//     }
// };