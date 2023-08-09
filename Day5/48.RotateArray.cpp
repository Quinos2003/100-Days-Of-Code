class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // i0 j0 at in-1 jn-1 
        // j = i 
        // can do for all by 2 operations 
        // swap i,j then reverse all i or basically reverse all coloums
        for(int i =0; i< n ; i++){
            for(int j=0; j<=i;j++){
                swap(matrix[i][j] , matrix[j][i]); 
            }
        }
            
        for(int i =0 ; i<n ; i++){
            reverse(matrix[i].begin(), matrix[i].end()); // swapping coloumn
        }
    }
};