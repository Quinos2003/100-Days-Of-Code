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
vector<int> leaf1;
vector<int> leaf2;

void getLeafArr(TreeNode* root, vector<int>& arr){
    if(!root) return;
    getLeafArr(root->left,arr);
    getLeafArr(root->right,arr);
    if(!root->left && !root->right){
        arr.push_back(root->val);
    }

}
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        getLeafArr(root1,leaf1);
        getLeafArr(root2,leaf2);
        return leaf1==leaf2;
    }
};