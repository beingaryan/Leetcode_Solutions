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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>inorderMap=populateMap(inorder);
        int preIndex[1]={0};
        return preorderfill(preIndex,preorder,inorderMap,0,inorder.size()-1);
        
        
        
    }
    
    unordered_map<int,int> populateMap(vector<int> &inorder){
        unordered_map<int,int>inorderMap;
        for(int i=0;i<inorder.size();i++)
        {
            
            inorderMap[inorder[i]]=i;
            
        }
        
        return inorderMap;
    }
    
      TreeNode* preorderfill(int preIndex[1],vector<int>&preorder,unordered_map<int,int>&inorderMap,int start,int end){
          if(start>end)return NULL;
          
          TreeNode* node=new TreeNode(preorder[preIndex[0]]);
          
          int index=inorderMap[preorder[preIndex[0]]];
          preIndex[0]++;
          node->left=preorderfill(preIndex,preorder,inorderMap,start,index-1);
          node->right=preorderfill(preIndex,preorder,inorderMap,index+1,end);
          return node;
          
          
      }
};