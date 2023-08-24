/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast= head;
        ListNode *slow= head;
        ListNode *entry= head;

        while(fast && fast->next){
            fast=fast->next->next;
            slow = slow->next;
            if(slow==fast){
                while(entry!=slow){
                    entry= entry->next;
                    slow= slow->next;
                }
                return entry;
            }
        }
        return NULL;
    }
};