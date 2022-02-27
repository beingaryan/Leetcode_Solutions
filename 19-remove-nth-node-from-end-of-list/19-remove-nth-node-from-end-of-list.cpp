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
public://1 2 3 4 5
    //2
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {

      ListNode*fast=head;
      ListNode*slow=head;
      
        for(int i=0;i<n;i++)
            fast=fast->next;
        
        if(!fast)return head->next;
        
        while(fast->next)
        {
        fast=fast->next;
        slow=slow->next;
        }
        
        slow->next=slow->next->next;
        
        return head;
        
        
        
       
    }
    
    
     // return head;
        
        
        
        
        
        
        
        
        
        
        
        
        
     /*
       
        if(head==NULL)return NULL;
        
        
    ListNode* first=head;
            ListNode* last=head;
            ListNode* prev=first;
        
        
        n--;
        
        while(n--){
            if(last->next)last=last->next;
        }
        
   
        
        if(last->next==NULL){
            if(head->next){
                head=head->next;
                delete first;
                first=NULL;
                return head;
            }
            else{
                return NULL;
            }
            
        }

        while(last->next!=NULL){
         last=last->next;
            prev=first;
            first=first->next;
        }
        
        prev->next=first->next;
         delete first;
        first=NULL;
        return head;
        
     */
        
        
//                 if(head==NULL)return NULL;
//      ListNode* first=head;
//      ListNode* last=head;  
//      ListNode* prev=first;
//         n--;
//            while(n--){
//                if(last->next)last=last->next;
//            }
//         while(last->next){
//             last=last->next;
//             prev=first;
//             first=first->next;
//         }
//         prev->next=first->next;
//         if(first==head){
//            if(head->next) {head=head->next;
//                            delete first;
//                             first=NULL;
//             return head;}
//             else{
//                 return NULL;
//             }
//         }
        
//         delete first;
//         first=NULL;
//         return head;
        
        
        
};