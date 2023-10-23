
class Solution{
public:

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};


bool isValid(int i, int j ,int n , int m){
    if(i>=0 && j>=0 && i <= n-1 && j<=m-1) return true;
    return false;
}

void dfs(int i, int j, vector<vector<char>> &mat){
    mat[i][j]='N';
    int n = mat.size();
    int m = mat[0].size();
    for(int z =0 ; z < 4 ; z++){
        int nrow = dx[z] +i;
        int ncol = dy[z] +j;
        if(isValid(nrow,ncol,n,m) && mat[nrow][ncol]== 'O'){
            dfs(nrow,ncol,mat);
        }
    }
}

bool isBoundary(int i, int j ,int n , int m){
    if(i==0 || j==0 || i == n-1 || j==m-1) return true;
    return false;
}
    vector<vector<char>> fill(int n, int m, vector<vector<char>> &mat)
    {
        // code here
        for(int i =0 ; i < n ; i ++){
            for( int j = 0 ; j < m ; j++){
                if(isBoundary(i,j,n,m) && mat[i][j]=='O')
                    dfs(i,j,mat);
                    
            }
        }
        for(int i =0 ; i < n ; i ++){
            for( int j = 0 ; j < m ; j++){
                
                if( mat[i][j]=='N') mat[i][j]= 'O';
                
                else mat[i][j]='X';
            }
        }
        return mat;
    }
};