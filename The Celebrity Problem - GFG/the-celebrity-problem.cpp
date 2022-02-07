// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& trust, int n) 
    {
       vector<int>outDeg(n,0);
          vector<int>inDeg(n,0);
        
        for(int i=0;i<trust.size();i++){
            for(int j=0;j<trust[0].size();j++){
            if(trust[i][j]==1){
            outDeg[i]++;
            inDeg[j]++;
            }
           
            }
        }
        
        int celebrity=-1;
         for(int i=0;i<n;i++){
           
            if(inDeg[i]==n-1&&outDeg[i]==0)celebrity=i;
        }
        
        return celebrity;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}
  // } Driver Code Ends