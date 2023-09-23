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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> result;
        queue<TreeNode*> q;
        q.push(root);
        int level =0;

        while(!q.empty()){
            int n = q.size();
            vector<int> curr(n);
            for( int i =0 ; i < n ; i++){
                TreeNode * temp = q.front();
                q.pop();
                if(level%2==0) curr[i] = temp->val;
                else curr[ n-1 -i]= temp ->val;

                if(temp-> left ) q.push(temp->left);
                if(temp->right ) q.push(temp->right);
            }
            result.push_back(curr);
            level++;
        }
        return result;
    }
};
