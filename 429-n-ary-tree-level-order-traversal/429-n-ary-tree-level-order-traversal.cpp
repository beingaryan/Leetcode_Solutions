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
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*>parent;
        queue<Node*>child;
        vector<vector<int>>vec;
        vector<int>ans;
        if(!root)return vec;
        
        parent.push(root);
        
        while(!parent.empty()){
            Node* top=parent.front();
            parent.pop();
            ans.push_back(top->val);
            
            for(auto childr:top->children){
                child.push(childr);
            }
            if(parent.empty()){
                vec.push_back(ans);
                ans.clear();
                swap(parent,child);
            }
            
        }
        
        return vec;
        
    }
};