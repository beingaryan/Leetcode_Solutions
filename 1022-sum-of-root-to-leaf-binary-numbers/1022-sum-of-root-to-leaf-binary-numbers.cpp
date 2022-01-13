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
    int sumRootToLeaf(TreeNode* root) {
        string ans="";
        int res=0;
        fun(root,ans,res);
        
        return res;
        
    }
    
    void fun(TreeNode* root, string ans, int &res){
        if(!root)return;
        
        if(root->left==NULL && root->right==NULL){
            ans+=(char)(root->val+'0');//root->val;
            int x=stoull(ans,0,2);
            res+=x;
            return;
        }
        
        
        // ans.push_back(root->val);
        // string sol=(char)(root->val+'0');
        fun(root->left,ans+(char)(root->val+'0'),res);
        // ans.pop_back();
        
        // ans.push_back(root->val);
        fun(root->right,ans+(char)(root->val+'0'),res);
        // ans.pop_back();
        
        return ;
    }
};

int sumRootToLeaffun(TreeNode* root, int sum){
        if(root==NULL) 
            return 0;
        sum = (2 * sum) + root->val;
    
        if(root->left==NULL && root->right==NULL) 
            return sum;
        return sumRootToLeaffun(root->left, sum) + sumRootToLeaffun(root->right, sum);
    }

    int sumRootToLeaf(TreeNode* root) {
        return sumRootToLeaffun(root, 0);
    }
