/* Tree node structure  used in the program
 struct Node
 {
     int data;
     Node* left, *right;
}; */

/*You are required to complete below method */

void traverse(Node *root, int sum, long long &ans){
    if(root==NULL) return ;
    
    if(!root->left && !root->right){
        sum = sum*10+ root->data;
        ans+=sum;
        return;
    }
    sum=sum*10+root->data;
    traverse(root->left,sum,ans);
    traverse(root->right,sum,ans);
     
}
long long treePathsSum(Node *root)
{
    //Your code here
    long long ans =0;
    traverse (root,0,ans);
    
    return ans;
}
