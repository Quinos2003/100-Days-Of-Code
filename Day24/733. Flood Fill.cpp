class Solution {
public:
void dfs(vector<vector<int>>& image,int sr,int sc,int color,int initial,vector<pair<int, int>>&dirs ){
    int m = image.size();
    int n = image[0].size();
    image[sr][sc]=color;
    for ( auto it : dirs){
        int nrow = sr+ it.first;
        int ncol = sc+ it.second ;
        if(nrow>=0 && nrow<m && ncol >=0 && ncol<n && image[nrow][ncol]!=color &&image[nrow][ncol]==initial )
        dfs (image ,nrow , ncol, color , initial , dirs);
    }
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initial = image[sr][sc];
        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        dfs(image , sr , sc , color , initial , dirs);
        return image;
    }
};