// { Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

Node* buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

bool isBST(Node* n, int lower, int upper)
{
    if (!n) return true;
    if ( n->data <= lower || n->data >= upper ) return false;
    return (  isBST( n->left, lower, n->data )  &&  isBST( n->right, n->data, upper )  );
}

bool compare( Node* a, Node* b, vector<pair<int, int>> &mismatch )
{
    if ( !a && !b ) return true;
    if ( !a || !b ) return false;

    if ( a->data != b->data )
        mismatch.push_back( pair<int, int> (a->data, b->data) );

    return ( compare( a->left, b->left, mismatch ) && compare( a->right, b->right, mismatch ) );
}


 // } Driver Code Ends
/*
struct Node
{
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
  int c=0;
  
  
    void correctBST( struct Node* root )
    {
        vector<int>vec;
        vector<int>wrong;
        struct Node* inorderVal=new Node(INT_MIN);
        // int wrong1,wrong2;
        struct Node* wrong1;
        struct Node* wrong2;
        inorder(root,inorderVal,wrong1,wrong2);
        
        int temp=wrong1->data;
        wrong1->data=wrong2->data;
        wrong2->data=temp;
       
        // correctTree(root,wrong1,wrong2);

    }
    
    // void correctTree( struct Node* &root, int val1, int val2){
    //     if(!root)return;
       
    //   stack<Node*> s;
        
    //     s.push(root);
        
    //     while(!s.empty()){
    //         Node* currentNode=s.top();
    //         s.pop(); 
            
    //         if(currentNode->data==val1)
    //         currentNode->data=val2;
            
    //         else if(currentNode->data==val2)
    //         currentNode->data=val1;
            
          
       
    //         if(currentNode->right){
    //         Node* rightNode=currentNode->right;
    //         s.push(rightNode);
                
    //         }
            
            
    //          if(currentNode->left){
    //         Node* leftNode=currentNode->left;
    //         s.push(leftNode);
    //          }
            
    //     } 
    // }
       
    
    
    void inorder(struct Node* root, struct Node* &inorderVal,struct Node* &wrong1, struct Node* &wrong2)
    {
    if(!root)return;
    
    inorder(root->left,inorderVal,wrong1,wrong2);
    
    if(inorderVal->data>root->data){
        c++;
        if(c==1)
        {
     
        wrong1=inorderVal;
        wrong2=root;
        }
        if(c==2)
        {
               wrong2=root;
        
        }
    }
    inorderVal=root;
    inorder(root->right,inorderVal,wrong1,wrong2);   
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    getchar();

    while (t--)
    {
        string s;
        getline(cin, s);

        Node* root = buildTree(s);
        Node* duplicate = buildTree(s);

        Solution ob;
        ob.correctBST(root);

        // check 1: is tree now a BST
        if ( ! isBST(root, INT_MIN, INT_MAX) )
        {
            cout << "0\n";
            continue;
        }

        // check 2: comparing with duplicate tree

        vector<pair<int, int>> mismatch;
        // a vector to store data of mismatching nodes

        if ( ! compare( root, duplicate, mismatch) )
        {
            // false output from this function indicates change in structure of tree
            cout << "0\n";
            continue;
        }

        // finally, analysing the mismatching nodes
        if ( mismatch.size() != 2 || mismatch[0].first != mismatch[1].second || mismatch[0].second != mismatch[1].first )
            cout << "0\n";
        else cout << "1\n";
    }
    return 0;
}
  // } Driver Code Ends