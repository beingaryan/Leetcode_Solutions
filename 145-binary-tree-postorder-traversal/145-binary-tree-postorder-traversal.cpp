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
    vector<int> postorderTraversal(TreeNode* root) {
       vector<int>ans;
        
        stack<TreeNode*> s;
        if(!root)return ans;
        s.push(root);
        
        while(!s.empty()){
            TreeNode* currentNode=s.top();
            s.pop();            
            ans.push_back(currentNode->val);
       
            
            
             if(currentNode->left){
            TreeNode* leftNode=currentNode->left;
            s.push(leftNode);
             }
            
              if(currentNode->right){
            TreeNode* rightNode=currentNode->right;
            s.push(rightNode);
                
            }
            
        }
        reverse(ans.begin(),ans.end());
        return ans; 
    }
};