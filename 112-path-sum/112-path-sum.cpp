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
    bool hasPathSum(TreeNode* root, int targetSum) {
       int sum=0;
        return fun(root,targetSum,sum);
    }
    
    bool fun(TreeNode* root, int targetSum, int sum){
        if(root==NULL)return false;
        
        if(root->left==NULL&&root->right==NULL)
            return sum+root->val==targetSum;
        
        // sum=si
        return fun(root->left,targetSum,sum+root->val)||fun(root->right,targetSum,sum+root->val);
        
    }
};