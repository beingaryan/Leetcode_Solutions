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
  
    int maxPathSum(TreeNode* root) {
    int maxV=INT_MIN;
            maxVal(root,maxV);
        return maxV; 
    }
//     What does a path look like according to this description?

//  a path is always expressed as left nodes(if any) -> root -> right nodes(if any).
// We can see that there are four cases for this node's sum:

// Include both the left and the right nodes' results (i.e the maximum sum which passes through those respective children).
// Include only the left result.
// Include only the right result.
// Include only the root node, i.e include none of the children in the result. (this is also the base case for a leaf node).
    
    
// This way, we calculate the maximum of all four of these and update the global maximum, if required. 
// But to return we have three choices, not four. 
// The case where we include both the left and right subtrees cannot be returned to upper levels,
// since a path cannot go from the right subtree to the parent of the current root. Hence for returning, 
// we only consider the cases 2, 3 and 4.
    
    
    int maxVal(TreeNode* root, int &maxV){
        if(!root)return 0;
        
        int left=maxVal(root->left,maxV);
        int right=maxVal(root->right,maxV);
        
        int currSum=max(root->val,max(root->val+left,root->val+right));//Check for root and root+left, root+right
        //Didnt added in currSum root+left+right as it will return all the values to upper call as we are returing currSum
        //All value means left+right+root. But for maxPathSum, we don't need root value to be added and return to upper calls.
        //Only it should be updated into global maximum
        //So, update in Global Maximum into maxV
        //TestCase:[5,4,8,11,null,13,4,7,2,null,null,null,1]
        //Expected:48
        //If all added, it will return 55(Sum of all nodes(left+right+root))
        
        maxV=max(maxV,max(currSum,root->val+left+right));
        
        
        return currSum;
    }
    
};