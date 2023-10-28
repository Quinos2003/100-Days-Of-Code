class Solution{
public:

    int isValid(vector<vector<int>> mat){
        int row[9][9] = {0};
        int col[9][9] = {0};
        int grid[3][3][9] = {0};
        
        for(int i =0 ; i < 9 ; i++ ){
            for(int j=0 ; j < 9 ; j++){
                
                if(mat[i][j]==0) continue;
                
                int val = mat[i][j]-1;
                
                if(row[i][val]++ || col[val][j]++ || grid[i/3][j/3][val]++ ) return 0;
            }
        }
        return 1;
    }
};