// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	   
	 vector<int>dp(n+1,-1);
        return maxMoneyRobbed(arr,n,dp,0);
    }
    
    int maxMoneyRobbed(int *arr,int n,vector<int>&dp,int currIndex){
        if(currIndex>=n)
            return 0;
        
        if(dp[currIndex]!=-1)
            return dp[currIndex];
        int robbed=arr[currIndex]+maxMoneyRobbed(arr,n,dp,currIndex+2);
        int notRobbed=maxMoneyRobbed(arr,n,dp,currIndex+1);
        
        return dp[currIndex]=max(robbed,notRobbed);
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends