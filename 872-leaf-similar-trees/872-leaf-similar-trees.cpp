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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
     string leftv="";
     string rightv="";
        funOne(root1,leftv);
        funTwo(root2,rightv);
        // ,rightv);
        // cout<<"leftv "<<leftv<<endl;
        // cout<<"rightv "<<rightv<<endl;
        
        if(leftv==rightv)return true;
        
        return false;
    }
    
    
  void funOne(TreeNode* root1,string &leftv){//, string &rightv) { 
    if(!root1)return;
        
        if((root1->left==NULL&&root1->right==NULL)){
            leftv+=(char)(root1->val+'0');
            return;     
        }
        
        
            
        // if(root2->left==NULL&&root2->right==NULL){
        //     rightv+=(char)(root2->val+'0');
        //     return;
        // }
            
    
        
               funOne(root1->left,leftv);//,rightv);
               funOne(root1->right,leftv);//;/,rightv);
        return;
  }
    
    
      void funTwo(TreeNode* root2,string &rightv){
          //, string &rightv) { 
    if(!root2)return;
        
        if((root2->left==NULL&&root2->right==NULL)){
            rightv+=(char)(root2->val+'0');
            return;     
        }
     
        // if(root2->left==NULL&&root2->right==NULL){
        //     rightv+=(char)(root2->val+'0');
        //     return;
        // }

               funTwo(root2->left,rightv);//,rightv);
               funTwo(root2->right,rightv);///;/,rightv);
        return;
  }
    
    
    
    
    
};