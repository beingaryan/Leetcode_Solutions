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
    vector<int> rightSideView(TreeNode* root) {
    
    vector<int>ans;
    set<int>s;
    
        rightView(root,1,ans,s);
    return ans;
        
        
    }
    
    
    void rightView(TreeNode* root, int level,vector<int>&ans, set<int>&s){
        if(!root)return;
        
        if(s.find(level)==s.end()){
            s.insert(level);
            ans.push_back(root->val);
        }
        rightView(root->right,level+1,ans,s);
        rightView(root->left,level+1,ans,s);
        
        return;
        
    }
};