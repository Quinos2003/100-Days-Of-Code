//Function to count number of nodes in BST that lie in the given range.
class Solution{
public:
int count =0;
    void inorder(Node *root, int l, int h){
        if(!root) return ;
        inorder(root->left,l,h);
        inorder(root->right,l,h);
        if(root->data <=h && root->data >=l) count++;
    }
    int getCount(Node *root, int l, int h)
    {
        inorder(root,l,h);
        return count;
    }
};