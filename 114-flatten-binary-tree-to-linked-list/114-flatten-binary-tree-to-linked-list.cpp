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
    // TreeNode* prev=NULL;
    void flatten(TreeNode* root) 
    {
        
//         RECURSIVE
//         if(root==NULL)return;
        
//         flatten(root->right);
//         flatten(root->left);
//         root->right=prev;
//         root->left=NULL;
//         prev=root;
//         return;
        
       TreeNode* curr=root;
        
        while(curr){
            if(curr->left){
                TreeNode*temp=curr->left;
                while(temp->right){
                    temp=temp->right;
                }
                temp->right=curr->right;
                curr->right=curr->left;
                curr->left=NULL;
                // curr=curr->left;
            }
            curr=curr->right;
        }
        
        
    }
};