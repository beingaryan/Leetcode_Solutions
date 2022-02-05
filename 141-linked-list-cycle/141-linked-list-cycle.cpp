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
    bool hasCycle(ListNode *head) {
     ListNode* slow=head;
        ListNode* fast=head;
        if(!head)return false;
        while(fast->next&&fast->next->next){
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow)return true;
        }
        return false;
//         if(!fast || !fast->next)return NULL;
        
//         slow=head;
//         while(slow!=fast){
//             slow=slow->next;
//             fast=fast->next;
//         }
        
//         return slow;
    }
};