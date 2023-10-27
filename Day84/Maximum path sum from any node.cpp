class Solution {
  public:
    //Function to return maximum path sum from any node in a tree.
int traverse(Node *root,int & sum){
    if(!root) return 0;
    
    int takeLeft = traverse (root->left,sum);
    int takeRight = traverse (root->right,sum);
    
    int max_single = max(max(takeLeft,takeRight)+root->data, root->data);
    
    int max_top = max(max_single , takeLeft+takeRight + root->data);
    sum = max(sum,max_top);
    
    return max_single;
}
    
    int findMaxSum(Node* root)
    {
        // Your code goes here
        int sum = INT_MIN;
        traverse(root, sum);
        return sum;
    }
};