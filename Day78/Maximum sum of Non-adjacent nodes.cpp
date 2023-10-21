
class Solution{
  public:
  
  unordered_map<Node*,int> dp;
    //Function to return the maximum sum of non-adjacent nodes.
    int getMaxSum(Node *root) 
    {
        if(!root) return 0;
        
        if(dp[root]) return dp[root];
        
        int in = root->data;
        if(root->left){
            in = in+ getMaxSum(root->left->left) + getMaxSum(root->left->right);
        }
        if(root->right){
            in = in+ getMaxSum(root->right->left) + getMaxSum(root->right->right);
        }
        
        int ex = getMaxSum(root->left) + getMaxSum(root->right);
        
        dp[root] = max(in , ex);
        
        return dp[root];
    }
};