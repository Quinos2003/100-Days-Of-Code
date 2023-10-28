/*
Structure of a node is as following
struct Node
{
     int data;
     struct Node* left;
     struct Node* right;
};
*/

class Solution{
  public:
  
 bool traverse(Node * root , int target  , vector<int> & ans){
      if(root==NULL) return false;
      
      
      if(root->data ==target ){
          return true;
      }
      
      
      bool l =traverse(root->left , target ,ans);
      bool r = traverse(root->right , target, ans);
      
      
      if(l || r){
         ans.push_back(root->data);
         return true;
      }
      return false;
      
    //   if(!found && !ans.empty()) ans.pop_back(); 
      
  }
    // Function should return all the ancestor of the target node
    vector<int> Ancestors(struct Node *root, int target)
    {
         // Code here
        //  int found =0;
         vector<int> ans;
         
         traverse(root , target , ans);
        //  ans.push_back(root->data);
        //  reverse(ans.begin(), ans.end());
         return ans;
        
    }
};