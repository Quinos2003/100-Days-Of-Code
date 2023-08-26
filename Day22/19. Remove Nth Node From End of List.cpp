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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head || !head->next ) return NULL;
        ListNode *curr= head;
        int length = 0;
        while(curr){
            length++;
            curr=curr->next;
        }
        curr=head;
        for(int i =0 ; i < length -n -1 ; i++){
            curr=curr->next;
        }
        if(length==n)
        return head->next;
        curr->next=curr->next->next;
        return head;
    }
};