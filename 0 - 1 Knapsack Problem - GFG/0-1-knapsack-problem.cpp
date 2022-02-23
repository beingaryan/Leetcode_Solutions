// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
              unordered_map<string,int>mp;

       return maxProfit(wt,val,W,n,0,mp);

    }
    
     int maxProfit(int wt[],int val[],int cap,int n,int curr,unordered_map<string,int>&mp)
    {
    
        if(curr>=n)return 0;
        
        if(cap<=0)return 0;
         string curr_key = to_string(curr)  + "_"  + to_string(cap);
    
    if(mp.find(curr_key)!=mp.end())
    return mp[curr_key];
    
    
        int consider=0;
        if(wt[curr]<=cap)
        consider=val[curr]+maxProfit(wt,val,cap-wt[curr],n,curr+1,mp);
        
        int notConsider=maxProfit(wt,val,cap,n,curr+1,mp);
        
        return  mp[curr_key]=max(consider,notConsider);
        
    }
    
};

// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends