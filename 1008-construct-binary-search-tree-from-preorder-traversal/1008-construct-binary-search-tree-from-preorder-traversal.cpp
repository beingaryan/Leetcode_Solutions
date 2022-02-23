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
    TreeNode* bstFromPreorder(vector<int> &preorder) {
        
        int preIndex=0;
        return tree(preIndex,preorder,1001);
        
        
        
        
    }
    
    TreeNode* tree(int &preIndex,vector<int>&preorder,int boundVal){
        if(preIndex>=preorder.size()||preorder[preIndex]>boundVal)
            return NULL;
        
        TreeNode* newNode=new TreeNode(preorder[preIndex]);
        preIndex++;
        newNode->left=tree(preIndex,preorder,newNode->val);
        newNode->right=tree(preIndex,preorder,boundVal);
        return newNode;
    }
};