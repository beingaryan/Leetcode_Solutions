/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
    
        Node* dummyNode=new Node(-1);
        
        Node* current=head;
        Node* runner=dummyNode;
        
        unordered_map<Node*,Node*>mp;
        while(current!=NULL){
            
        Node* newNode=new Node(current->val);
        mp[current]=newNode;
        runner->next=newNode;
        runner=runner->next;
        current=current->next;
            
            
        }
        
        current=head;
        runner=dummyNode->next;
        
        while(current!=NULL){
            runner->random=mp[current->random];
            runner=runner->next;
            current=current->next;
        }
        
        return dummyNode->next;
        
         
    }
};




//  Node* dummyNode=new Node(-1);
//      Node* current=head;//old
//      Node* runner=dummyNode;//new
        
//         unordered_map<Node*,Node*> memo;
        
//         while(current!=NULL){
//             Node* newNode=new Node(current->val);
//             memo[current]= newNode;
//             runner->next=newNode;
//             runner=runner->next;
//             current=current->next;
            
//         }
        
//         current=head;
//         runner=dummyNode->next;
        
//         while(current!=NULL){
            
//             // if(current->random!=NULL)
//             runner->random=memo[current->random];
//             runner=runner->next;
//             current=current->next;
//         }
        
//         return dummyNode->next;