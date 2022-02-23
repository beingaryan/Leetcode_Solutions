// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution{
  public:
  int maxprofit(int prices[],int n ,int curr,vector<vector<int>>&vec)
  {
      if(n==0) return 0;
      if(curr>=n) return 0;
      if(vec[curr][n]!=-1) return vec[curr][n];
      int consider = 0;
      int len = curr+1;
      if(len<=n)
      {
          consider = prices[curr]+maxprofit(prices,n-len,curr,vec);
      }
      int notconsider = maxprofit(prices,n,curr+1,vec);
      return vec[curr][n]=max(consider,notconsider);
  }
    int cutRod(int price[], int n) {
        // vector<vector<long>>vecCheck(sqrt(n)+10,vector<long>(n+1,-1));
        // for(int i=0;i<vecCheck.size();i++){
        //     for(int j=0;j<vecCheck[0].size();j++){
        //         cout<<vecCheck[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        vector<vector<int>>vec(1002,vector<int>(1002,-1));
        return maxprofit(price,n,0,vec);
        
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}  // } Driver Code Ends