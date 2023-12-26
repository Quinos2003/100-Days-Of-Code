/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
// int lengthOfLL(ListNode* head){
//     int n =1;
//     while(head->next){
//         n++;
//         head=head->next;
//     }
//     return n;
// }
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;
        ListNode *node = head, *currHead;
        int n =1;
        while(node->next){
            n++;
            node=node->next;
        }
        k=k%n;
        if(k==0) return head;
        node->next = head;
        int new_head_pos = n-k;
        for(int i =0 ; i < new_head_pos;i++){
            node=node->next;
        }
        currHead = node->next;
        node->next=NULL;
        return currHead;
    }
};