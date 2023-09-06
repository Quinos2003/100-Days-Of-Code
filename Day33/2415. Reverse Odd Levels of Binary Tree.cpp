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
    void reverseSwap(TreeNode* lroot, TreeNode* rroot, int level) {
        if(lroot == NULL && rroot == NULL) return;
        if(level % 2 == 0)
        swap(lroot->val, rroot->val);
        reverseSwap(lroot->left, rroot->right, level + 1);
        reverseSwap(lroot->right, rroot->left, level + 1);
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(!root) return NULL;
        reverseSwap(root->left, root->right, 0);
        return root;
    }
};