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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        
        queue<TreeNode*>levelNodes;
        if(!root)return ans;
        levelNodes.push(root);
        
        while(levelNodes.empty()==false){
            int currSize=levelNodes.size();
            vector<int>level;
            
            while(currSize>0){
            TreeNode* currNode=levelNodes.front();
            levelNodes.pop();
                currSize--;
            level.push_back(currNode->val);
            if(currNode->left)levelNodes.push(currNode->left);
            if(currNode->right)levelNodes.push(currNode->right);
            }
            ans.push_back(level);
        }
        
        return ans;
    }
};