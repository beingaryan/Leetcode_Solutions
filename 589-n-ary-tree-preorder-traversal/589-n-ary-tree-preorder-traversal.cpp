/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};https://octave-online.net/#cmd=source(%22hist_equalizarion.m%22)
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> ans;
        
        if(!root)return ans;
        
        stack<Node*>s;
        s.push(root);
        
        while(!s.empty())
        {
            
        Node* currentNode=s.top();
        s.pop();            
        ans.push_back(currentNode->val);
        
        for (int it=(currentNode->children).size()-1;it>=0;it--)
        {
        s.push(currentNode->children[it]);
           }
            
 
        
        }
        
        return ans;
    }
};