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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        if(root->val == key){
            if(!root->right){
                return root->left;
            }
            else{
                TreeNode* nroot = root->right;
                while(nroot->left){
                    nroot = nroot -> left;
                }
                swap(nroot->val , root->val);
                root->right = deleteNode(root->right, key );
                return root;
            }
        }
        if(root->val > key){
            root->left = deleteNode(root->left , key);
        }
        if(root->val < key){
            root->right = deleteNode(root->right , key);
        }
        return root;
    }
};
