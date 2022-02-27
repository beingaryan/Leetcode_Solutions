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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) 
    {
        if(!root)return false;
        if(root->val==subRoot->val){
            if(checkSame(root,subRoot))
                return true;
        }
        
        return isSubtree(root->left,subRoot)||isSubtree(root->right,subRoot);
    }
    
    bool checkSame(TreeNode* root, TreeNode*subRoot){
        if(!root&&!subRoot)
            return true;
        
        if(!root||!subRoot||root->val!=subRoot->val)
            return false;
        
        return checkSame(root->left,subRoot->left)&&checkSame(root->right,subRoot->right);
    }
    
};