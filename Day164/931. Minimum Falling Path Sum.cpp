class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int r = 1; r < n; ++r){
            for (int c = 0; c < n; ++c){
                int left, middle, right;
                if(c == 0){
                    right = matrix[r-1][c+1];
                    middle = matrix[r-1][c];
                    matrix[r][c] += min(right, middle);
                }
                else if(c == n-1){
                    left = matrix[r-1][c-1];
                    middle = matrix[r-1][c];
                    matrix[r][c] += min(left, middle);
                }
                else{
                    left = matrix[r-1][c-1];
                    right = matrix[r-1][c+1];
                    middle = matrix[r-1][c];
                    matrix[r][c] += min(middle, min(left, right));
                }
            }
        }
        int res = *min_element(begin(matrix[n-1]), end(matrix[n-1]));
        return res;
    }
};