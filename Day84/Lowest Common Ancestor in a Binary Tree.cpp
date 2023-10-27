/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution
{

    
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2 )
    {
       //Your code here
       if(root ==NULL ) return NULL;
       
       if(root->data == n1 || root->data == n2) return root;
       
       Node* leftNode = lca(root->left, n1 ,n2);
       Node* rightNode = lca(root->right, n1 , n2);
       
       if(leftNode!=NULL && rightNode!=NULL) return root;
       
       else if(leftNode!=NULL) return leftNode;
       
       else return rightNode;
       
    }
};