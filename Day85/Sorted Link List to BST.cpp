/* 
//Linked List
struct LNode
{
    int data;
    struct LNode* next;
    
    LNode(int x){
        data = x;
        next = NULL;
    }
};

//Tree
struct TNode  
{  
    
    int data;  
    struct TNode* left;  
    struct TNode* right; 
    TNode(int x)
    {
        data=x;
        left=right=NULL;
    }
}; */

void linked_list_to_array(LNode *head, vector<int> &arr){
    
    
    while(head!=NULL){
        arr.push_back(head->data);
        head= head->next;
    }
    
}

TNode* array_to_tree_node(vector<int> &arr , int s , int e){
    if(s<=e){
        int m = s+ (e-s+1)/2;
        
        TNode* node = new TNode(arr[m]);
        node->left = array_to_tree_node(arr,s,m-1 );
        node->right = array_to_tree_node(arr,m+1,e );
        return node;
    }
        
    return NULL;
}

class Solution{
  public:
    TNode* sortedListToBST(LNode *head) {
        //code here
        vector<int> arr;
        linked_list_to_array(head , arr);
                                                                                                                                                                                         
        int n = arr.size();
        
        TNode* root = array_to_tree_node(arr,0,n-1 );
        return root;
    }
};