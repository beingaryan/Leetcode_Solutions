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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
      unordered_map<int,int>inorderMap;
        
        for(int i=0;i<inorder.size();i++)
            inorderMap[inorder[i]]=i;
        int postIndex=postorder.size()-1;
        return construct(postorder,postIndex,0,inorder.size()-1,inorderMap);
        
    }
    
    TreeNode* construct(vector<int>& postorder,int &postIndex,int start,int end,unordered_map<int,int>&inorderMap)
    {
        if(start>end)return NULL;
        
        TreeNode* node=new TreeNode(postorder[postIndex]);
        int index=inorderMap[postorder[postIndex]];
        postIndex--;
        node->right=construct(postorder,postIndex,index+1,end,inorderMap);
        
        node->left=construct(postorder,postIndex,start,index-1,inorderMap);
         return node;
    }
    
    };