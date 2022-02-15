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
  
    int maxPathSum(TreeNode* root) {
    int maxV=INT_MIN;
            maxVal(root,maxV);
        return maxV; 
    }
    
    int maxVal(TreeNode* root, int &maxV){
        if(!root)return 0;
        
        int left=maxVal(root->left,maxV);
        int right=maxVal(root->right,maxV);
        
        int currSum=max(root->val,max(root->val+left,root->val+right));
        maxV=max(maxV,max(currSum,root->val+left+right));
        
        
        return currSum;
    }
    
};