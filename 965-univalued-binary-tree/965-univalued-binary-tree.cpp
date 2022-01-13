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
    bool isUnivalTree(TreeNode* root) {
     if(!root)return true;
        return fun(root,root->val);
        
    }
    
    bool fun(TreeNode* root, int n){
        if(!root)return true;
        
        if(root->val!=n)return false;
        
        return fun(root->left,n)&&fun(root->right,n);
        
        // return true;
    }
};