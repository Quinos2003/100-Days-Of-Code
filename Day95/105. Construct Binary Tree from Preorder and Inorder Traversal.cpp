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

// class Solution {
// public:
// int preInd=0;
//     TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
//         return createTree(preorder,inorder,0,inorder.size() - 1);
//     }
//     TreeNode* createTree(vector<int>& preorder, vector<int>& inorder,int start, int end){
//         if(start > end){
//             return NULL;
//         }
//         TreeNode* node=new TreeNode(preorder[preInd++]);
//         int pos;
//         for(int i=start;i<=end;i++){
//             if(inorder[i]==node->val){
//                 pos=i;
//                 break;
//             }
//         }
//         node->left =createTree(preorder, inorder,start,pos-1);
//         node->right =createTree(preorder, inorder, pos+1,end);
//         return node;
//     }
// };
class Solution {
public:
    int preIdx;
    unordered_map<int,int> inIndexOf;   // inorder index of a number

    TreeNode* helper (vector<int>& preorder, vector<int>& inorder, int left, int right) {
        if (left <= right) {
            int inIdx = inIndexOf[preorder[preIdx]];
            TreeNode *t = new TreeNode(inorder[inIdx]);
            preIdx ++;
            
            t->left = helper(preorder, inorder, left, inIdx-1);
            t->right = helper(preorder, inorder, inIdx+1, right);
            return t;
        }
        else return NULL;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        preIdx = 0;
        inIndexOf.clear();

        int n = preorder.size();
        for (int i=0 ; i<n ; i++)
            inIndexOf[inorder[i]] = i;
        return helper(preorder, inorder, 0, n-1);
    }
};