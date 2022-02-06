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
    vector<string> binaryTreePaths(TreeNode* root) {
  vector<string>ans;
        RootToLeaf(root,"",ans);
        return ans;
    }
    void RootToLeaf(TreeNode* root, string currpath,vector<string>&ans)
    {
        if(root == NULL) return;
        if(root->left ==NULL && root->right ==NULL)
        {
            currpath+= to_string(root->val);  
            ans.push_back(currpath);
            return;
        }
        // currpath+= ;
       RootToLeaf(root->left,currpath+to_string(root->val)+"->",ans); 
       RootToLeaf(root->right,currpath+to_string(root->val)+"->",ans);  
    }
};