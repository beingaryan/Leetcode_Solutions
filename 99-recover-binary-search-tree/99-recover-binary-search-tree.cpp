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
    int c=0;
    void recoverTree(TreeNode* root) {
        vector<int>swapped;
        vector<int>vec;
        inorder(root,vec,swapped);
        
        correctBST(root,swapped[0],swapped[1]);
    }
    
    void correctBST(TreeNode* root, int val1, int val2){
        
        if(!root)return;
        stack<TreeNode*>st;
        st.push(root);
        
        while(!st.empty()){
            TreeNode* temp=st.top();
            st.pop();
            
            if(temp->val==val1)
                temp->val=val2;
            else if(temp->val==val2)
                temp->val=val1;
            
            if(temp->right){
                st.push(temp->right);
            }
            
            if(temp->left){
                st.push(temp->left);
            }
        }
    }
    
    void inorder(TreeNode* root, vector<int>&vec,vector<int>&swapped)
    {
        if(!root)return;
        
        inorder(root->left,vec,swapped);
        
        if(vec.size()>0&&vec.back()>root->val)
        {
            c++;
        if(c==1){    
        swapped.push_back(vec.back());
        swapped.push_back(root->val);     
        }
            
        if(c==2){
            swapped.pop_back();
            swapped.push_back(root->val);
        }   
        }
        
        vec.push_back(root->val);
        inorder(root->right,vec,swapped);
    }
    //3 2 1
    //1 2 3
    //1 3 2 4
    
    //1 2 4 3 7 6
    
};