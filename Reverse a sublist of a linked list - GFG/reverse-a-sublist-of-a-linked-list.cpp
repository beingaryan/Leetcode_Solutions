// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};


 // } Driver Code Ends
//User function Template for C++

/*Link list node 
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};*/

class Solution
{
    public:
    
    Node* reverse(Node* head){
        Node* curr=head;
        Node* prev=NULL;
        Node* priorToPrev=NULL;
        
        while(curr){
            priorToPrev=prev;
            prev=curr;
            curr=curr->next;
            prev->next=priorToPrev;
        }
        
        return prev;
    }
    Node* reverseBetween(Node* head, int m, int n)
    {
        if(m==n)
        return head;
        Node* revS=NULL;
        Node* revEnd=NULL;
        Node* revEndNext=NULL;
        Node* revSPrev=NULL;
        Node* curr=head;
        int i=1;
        while(curr && i<=n){
           if(i<m){
               revSPrev=curr;
           } 
           if(i==m){
               revS=curr;
           }
           if(i==n){
               revEnd=curr;
               revEndNext=curr->next;
           }
           
           curr=curr->next;
           i++;
        }
        revEnd->next=NULL;
        
        revEnd=reverse(revS);
        if(revSPrev){
            revSPrev->next=revEnd;
        }
        else
        head=revEnd;
        
        revS->next=revEndNext;
        return head;
    }
};

// { Driver Code Starts.

/* Function to print linked list */
void printList(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}



// Driver program to test above functions
int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int N, m, n;
		cin >> N>>m>>n;

		Node *head = NULL;
		Node *temp = head;

		for (int i = 0; i < N; i++) {
			int data;
			cin >> data;
			if (head == NULL)
				head = temp = new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}

		

        Solution ob;

		Node* newhead = ob.reverseBetween(head, m, n);
		printList(newhead);

		cout << "\n";



	}
	return 0;
}
  // } Driver Code Ends