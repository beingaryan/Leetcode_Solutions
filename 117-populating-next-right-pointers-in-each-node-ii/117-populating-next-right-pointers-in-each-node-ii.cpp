/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root)return NULL;
        queue<Node*>parent;
       queue<Node*>child;
       
       parent.push(root);
       
       Node* prev=NULL;
       while(!parent.empty()){
           Node* temp=parent.front();
           parent.pop();
           
           temp->next=prev;
           
           if(parent.empty())
           {
               prev=NULL;
           }else{
               prev=temp;
           }
           
           if(temp->right)
           child.push(temp->right);
           
           if(temp->left)
           child.push(temp->left);
           
           if(parent.empty()){
               swap(parent,child);
           }
           
       }       
        return root; 
    }
};