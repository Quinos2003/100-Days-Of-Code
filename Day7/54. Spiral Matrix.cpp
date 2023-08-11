class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();

        if(r < 1 || c< 1){
            return {};
        }

        vector<int> ans;

        int top =0;
        int bottom = r-1;
        int right = c-1;
        int left =0;

        while(left <=right && top<= bottom){
            for(int i =left ; i<= right; i++ ){
                ans.push_back(matrix[top][i]);
            }
            top++;
            
            for(int i = top ; i<= bottom ; i++){
                ans.push_back(matrix[i][right]);
            }
            right--;

            if(top<= bottom){
            for( int i = right ; i>= left ; i--){
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
            }

            if(left<=right){
            for(int i = bottom ; i>= top ; i-- ){
                ans.push_back(matrix[i][left]);
            }
            left++;
            }
        }
        return ans;

    }
};