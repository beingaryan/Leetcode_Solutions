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
        if(head==NULL)return NULL;
     ListNode* first=head;
     ListNode* last=head;  
     ListNode* prev=first;
        n--;
           while(n--){
               if(last->next)last=last->next;
           }
        while(last->next){
            last=last->next;
            prev=first;
            first=first->next;
        }
        prev->next=first->next;
        if(first==head){
           if(head->next) {head=head->next;
                           delete first;
                            first=NULL;
            return head;}
            else{
                return NULL;
            }
        }
        
        delete first;
        first=NULL;
        return head;
        
        
        
    }
};