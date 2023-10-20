/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution
{
    public:
    //Function to return a list of integers denoting the node 
    //values of both the BST in a sorted order.
    vector<int> merge(Node *root1, Node *root2)
    {
       //Your code here
       vector<int> ans;
       treeToArray(root1,ans);
       treeToArray(root2,ans);
       sort(ans.begin(), ans.end());
       return ans;
    }
    private:
    
    void treeToArray (Node * root , vector<int>& ans){
        if(!root) return;
        
        treeToArray(root->left, ans);
        ans.push_back(root->data);
        treeToArray(root->right, ans);
    }
};