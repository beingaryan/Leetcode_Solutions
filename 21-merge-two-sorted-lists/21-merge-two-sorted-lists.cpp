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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
       
        if(!list1) return list2;
        
        if(!list2) return list1;
        
        ListNode* newNode=NULL;
        
        if(list1->val<=list2->val){
            newNode=list1;
            newNode->next=mergeTwoLists(list1->next,list2);
        }else{
            newNode=list2;
            newNode->next=mergeTwoLists(list1,list2->next);
        }
 
//       
        return newNode;
    }
};
    
    // ListNode* head=new ListNode(-101);
//         ListNode* dummy = new ListNode(-101);
//         head=dummy;
        
//         while(list1&&list2){
        
//             if(list1->val<=list2->val){
//             ListNode* curr=new ListNode(list1->val);
            
//             dummy->next=curr;
//             dummy=dummy->next;
//             list1=list1->next;
            
//         }
//         else{
//             ListNode* curr=new ListNode(list2->val);
//             dummy->next=curr;
//               dummy=dummy->next;
//             list2=list2->next;
//         }
//         }
        
//         if(!list1){
//             dummy->next=list2;
//         }
//         else if(!list2){
//             dummy->next=list1;
//         }
//     return head->next;
           //1 5 9
        //4 6 8
        
//        if(list1->val<=list2->val){
//            list1->next=list2;
//            list1=list->next;
//            return mergeTwoLists(list1,  list2)
//            // return list1;
//        } 
        
//         else{
            
//         }
        