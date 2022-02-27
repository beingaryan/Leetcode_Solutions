/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)
            return "NULL,";
        
        return to_string(root->val)+","+serialize(root->left)+serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string>q;
        string temp="";
        for(int i=0;i<data.size();i++){
            if(data[i]==','){
                q.push(temp);
                temp="";
                continue;
            }
            temp+=data[i];
        }
         if(!temp.empty())q.push(temp);
            
            return desFunc(q);//,data);
    }
    
    
    TreeNode* desFunc(queue<string>&q){//,string data){
        if(q.empty())return NULL;
        string current=q.front();
        q.pop();
        if(current=="NULL")
            return NULL;
        TreeNode* newNode=new TreeNode(stoi(current));
        newNode->left=desFunc(q);
        newNode->right=desFunc(q);
        return newNode;
    
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));