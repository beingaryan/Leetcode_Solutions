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
    ListNode* sortList(ListNode* head) {
        
         mergeSort(head);//,&firstHead,&secondHead);
         return head;
    }
    
     void mergeSort(ListNode*&head){
         // ListNode* headNew=*head;
         ListNode* firstHead; 
         ListNode* secondHead;
         
         if(head==NULL||head->next==NULL)return;// NULL;
         
             divideInTwoList(head,firstHead,secondHead);
             mergeSort(firstHead);
             mergeSort(secondHead);
             head=merge(firstHead,secondHead);
        
     }
    
    ListNode* merge(ListNode* firstHead, ListNode* secondHead)
    {
        ListNode* result;
        
        if(!firstHead)return secondHead;
        if(!secondHead)return firstHead;
        
        if(firstHead->val<=secondHead->val){
            result=firstHead;
            result->next=merge(firstHead->next,secondHead);
            
        }else{
            result=secondHead;
            result->next=merge(firstHead,secondHead->next);
        }
        return result;
        
    }
    
    void divideInTwoList(ListNode*head, ListNode*&firstHead, ListNode*&secondHead){
        ListNode* fast=head;
        ListNode* slow=head;
        //1 2 4 5 3 0
        while(fast->next&&fast->next->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        
        secondHead=slow->next;
        slow->next=NULL;
        firstHead=head;
    }
};