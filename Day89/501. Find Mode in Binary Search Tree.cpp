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
int maxFreq = 0, currFreq = 0, precursor = INT_MIN;
    vector<int> res;


void traverse(TreeNode* root){

    if(!root) return;
    traverse(root->left);
    if (precursor == root->val) currFreq++;
    else currFreq = 1;
    if (currFreq > maxFreq){
        res.clear();
        maxFreq = currFreq;
        res.push_back(root->val);
    }
    else if (currFreq == maxFreq) res.push_back(root->val);
    precursor = root->val;
    traverse(root->right);
}
    vector<int> findMode(TreeNode* root) {
        traverse(root);
        return res;
    }
};