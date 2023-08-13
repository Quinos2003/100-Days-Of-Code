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
// class Solution {
// public:
//     ListNode* doubleIt(ListNode* head) {
//         ListNode* curr = head;
//         string myStr = "";
        
//         while(curr != nullptr){
//             myStr += to_string(curr->val);
//             curr = curr->next;
//         }
        
//         int num = stoi(myStr);
//         num *= 2;
//         string numStr = to_string(num);
//         curr = head;
//         int ptr = 0;
//         while(curr !=nullptr){
//                 curr->val = numStr[ptr] - '0';
//                 ptr++;
//                 curr = curr->next;
//         }
//         return head;
//     }
// };

class Solution {
public:
    int multiply(ListNode* head){
        if(!head) return 0;
        int t = head->val*2 + multiply(head->next);
        head->val = t%10;
        return t/10;
    }
    ListNode* doubleIt(ListNode* head) {
        int t = multiply(head);
        if(t) head = new ListNode(t, head);
        return head;
    }
};

// Participated in my first leetcode contest