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
    ListNode* reverseKGroup(ListNode* head, int k) {
      
    return reverseKGroups(head,k);
 
    // return head;
        
    }
    
    ListNode* reverseKGroups(ListNode* head,int k)
   
    {
        
        ListNode* runner=head;
        
        for(int i=0;i<k;i++){
            if(runner==NULL)return head;
            runner=runner->next;
        }
        
        //Reversing K Groups
        ListNode* curr=head;
         ListNode* prev=NULL;
         ListNode* prevToPrev=NULL;
        for(int i=0;i<k;i++){
            prevToPrev=prev;
            prev=curr;
            curr=curr->next;
            prev->next=prevToPrev;
        }
        
        head->next=reverseKGroups(curr,k);
        
        return prev;
        
    }
  
    
    
};

// ListNode* p=head;
//     ListNode* q=NULL;
//     ListNode* r=NULL;
//     ListNode* temp;int count=0;int flag=0;
//     while(p!=NULL){
//         r=q;
//         q=p;
//         p=p->next;
//         q->next=r;
//         count++;
        
//         // ||(p==NULL && flag==0)
        
//         if((count==k && flag==0) ||(p==NULL && flag==0)){
//             temp=head;
//             head=q;
//             flag=1;
//             count=0;
//             q=NULL;
//             r=NULL;
//         }
        
//         //1 2 3 4 5 6
        
//         else if((count==k && flag==1)||(p==NULL && flag==1)){
//             temp->next=q;
//             count=0;
//             for(int i=0;i<k;i++){
//                 if(temp->next){
//                     temp=temp->next;
//                 }
                
//             }
//             q=NULL;
//             r=NULL;
//         }
//     }
 
//         //INITIALIZATION
//         ListNode* current=head;
//         ListNode* prev=NULL;
//         ListNode* prior_to_prev=NULL;
        
//         int count =0;
//         int flag=0;
        
//         ListNode* temp=head;
        
        
//         while(current!=NULL){
            
//         //Reverse the Linked List upto Node Count of K
//         prior_to_prev=prev;
//         prev=current;
//         current=current->next;
//         prev->next=prior_to_prev;
//         count++;

//          if(count==k && flag==0){
//         // First batch of K Nodes 
//         //At K == COUNT         
//         //Prev will be at Kth Node
//         // Current will be at K+1th Node
//              temp=head;
//              head=prev;
//              count=0;
//              flag=1;
//              prev=NULL;
//              prior_to_prev=NULL;
             
//          }
            
//             else if((count==k && flag==1)||(current==NULL && flag ==1)){
                
//                 //Temp always points to the first node in every batch of K Node initially
//                 // 1 2 3 4 5 6 7 8 9
//                 //K= 3
//                 // Temp will be at '4' at 2nd batch of K Nodes (after flag =1 has been set for the first time)
//                 temp->next=prev;
//                 //prev always point to Kth Node in every batch
//                 count=0;
//                 for(int i=0;i<k;i++){
//                     //shift temp k times so that 
//                     //temp is at the last node of the reversed LL
//                     if(temp->next)
//                         temp=temp->next;
//                 }
                
//                 prev=NULL;
//                 prior_to_prev=NULL;
                
//             }
            
//         }
        
//         return head;
        
        








         // if(head==NULL || head->next==NULL)return head;
//         ListNode* start=head;
//         ListNode * end=head;
        
//         for(int i=0;i<k-1;i++){
//             end=end->next;
//         }
//         // ListNode* temp=end->next;
//         // end->next=NULL;
        
//         ListNode*tempList=reverseKGroup(end->next, k);
//         start->next=tempList;
//         end->next=start;
//         return end;