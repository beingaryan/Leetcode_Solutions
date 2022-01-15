/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        
           vector<int>ans;
        
        stack<TreeNode*> s;
        if(!root)return ans;
        
       addLeftSubTreeToStack(root,s);        
        
        while(!s.empty()){
           TreeNode* currentNode=s.top();
           s.pop();
            ans.push_back(currentNode->val);
           if(currentNode->right)
       addLeftSubTreeToStack(currentNode->right,s);
     }
     
        return ans;
    }
    
    void addLeftSubTreeToStack(TreeNode* root, stack<TreeNode*>&s){
        while(root!=NULL){
            s.push(root);
            root=root->left;
        }
        return;        
    }
};