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
    bool isValidBST(TreeNode* root) {
      long prevVal=-99999999999;
    return isBST(root,prevVal);
    }
bool isBST(TreeNode*root,long &prevVal){

    if(!root)return true;
    
    bool left=isBST(root->left,prevVal);
    if(root->val<=prevVal)return false;
        
        prevVal=root->val;
    
    bool right=isBST(root->right,prevVal);
    
    return left&&right;}


};