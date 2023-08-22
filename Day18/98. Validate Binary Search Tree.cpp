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

bool checkRange(TreeNode *root , long int max , long int min){
    if(root ==NULL) return true;

    if(root->val> min && root->val <max){
        return checkRange( root->left , root->val ,min) &&checkRange( root->right , max , root->val);
    }
    return false;
}
    bool isValidBST(TreeNode* root) {
        if(root ==NULL) return true;
        return checkRange(root,LONG_MAX , LONG_MIN);
    }
};
