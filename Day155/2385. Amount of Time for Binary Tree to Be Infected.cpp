/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
int time =0;

int traverse(TreeNode* root, int start){
    if(!root) return 0;
    int dfs =0;

    int leftdfs = traverse(root->left, start);
    int rightdfs= traverse(root->right, start);

    if(root->val == start){
        dfs =-1; // start point
        time = max(leftdfs,rightdfs);
    }
    else if(leftdfs >=0 && rightdfs>=0){
        dfs = max(leftdfs,rightdfs)+1; 
    }
    else{
        int dist = abs(leftdfs) + abs(rightdfs);
        time = max(time,dist);
        dfs = min(leftdfs,rightdfs)-1;
    }
    return dfs;
}
    int amountOfTime(TreeNode* root, int start) {
        traverse(root, start);
        return time;
    }
};