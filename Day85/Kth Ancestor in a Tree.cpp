/*
Structure of the node of the binary tree is as
struct Node
{
	int data;
	struct Node *left, *right;
};
*/
// your task is to complete this function


int findNode(Node *root, int &k, int node,int &nodeFound, int & ans){
    
    
    if(!root) return -1;
    
    if(root->data==node){
        nodeFound = 1;
    }
    if(nodeFound==0)
    findNode(root->left,k, node,nodeFound,ans);
    if(nodeFound==0)
    findNode(root->right,k, node,nodeFound,ans);
    
    if(k==0) ans = root->data;
    if(nodeFound) k--;
    return ans;
}

int kthAncestor(Node *root, int k, int node)
{
    // Code here
    int ans =-1;
    int nodeFound =0;
    findNode(root,k, node,nodeFound, ans);
    
    return ans;
}