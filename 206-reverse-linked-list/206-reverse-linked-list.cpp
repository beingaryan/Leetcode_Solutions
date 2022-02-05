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
    ListNode* reverseList(ListNode* head) 
{
    ListNode* p=head;
    ListNode*q=NULL;
        ListNode*r=NULL;
        
        while(p){
            r=q;
            q=p;
            p=p->next;
            q->next=r;
        }
        
        return q;
        
        
        
        
        
        
        
        
        
        
        
//     ListNode* curr=head;
//     ListNode* prev=NULL;
//     ListNode* prior_to_prev=NULL;
    
//     //1 2 3
//    // PP P <-C(1)      
        
//         while(curr)
//         {
//             prior_to_prev=prev;
//             prev=curr;
//             curr=curr->next;
//             prev->next=prior_to_prev;    
//         }
        
//         return prev;
       // return fun(head,NULL,head);
        // return temp;
}
    
//     ListNode* fun(ListNode*&head, ListNode*prev,ListNode*current)
//     {//p=current
//         // ListNode* temp; 
        
//         if(current)
//         {
//             fun(head,current,current->next);
//             current->next=prev;
//         }
//         else
//         {
//             head=prev;
//         }
//         return head;
//     }
    
};