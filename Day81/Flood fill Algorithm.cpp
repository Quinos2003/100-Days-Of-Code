class Solution {
public:

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

bool isValid(int i, int j ,int n , int m){
    if(i>=0 && j>=0 && i <= n-1 && j<=m-1) return true;
    return false;
}

void dfs(vector<vector<int>>& image, int sr, int sc, int newColor, int startColor){
    image[sr][sc]= newColor;
    int n = image.size();
    int m = image[0].size();
    
    for(int z =0 ; z < 4 ; z++){
        int nrow = sr + dx[z];
        int ncol = sc + dy[z];
        if ( isValid( nrow,  ncol , n, m) && image[nrow][ncol]==startColor) {
            dfs(image, nrow,  ncol,  newColor, startColor);
        }
    }
    
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        int startColor = image[sr][sc];
        if(startColor==newColor) return image;
        dfs( image, sr,  sc,  newColor, startColor);
        return image;
    }
};