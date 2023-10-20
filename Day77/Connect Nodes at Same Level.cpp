/* struct Node {
    int data;
    Node* left;
    Node* right;
    Node* nextRight;
};*/

class Solution{
    public:
    void connect(Node *root)
    {
       queue<Node*> q;
       q.push(root);
       Node* curr = root;
       Node* prev = NULL;
       
       while(!q.empty()){
           int levelSize = q.size();
           Node* prev = NULL;
           for (int i = 0; i < levelSize; i++) {
               curr=q.front(); q.pop();
               
               if(prev)prev->nextRight= curr;
               prev=curr;
               
               if(curr->left!=NULL) q.push(curr->left);
               if(curr->right!=NULL) q.push(curr->right);
           }
               
       }
    }    
};


//{ Driver Code Starts.