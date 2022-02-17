// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
public:
    //Function to reverse every sub-array group of size k.
    void reverseInGroups(vector<long long>& arr, int n, int k){
        // code here
        // if(k>n)return;
      return reverseArr(arr,n,k,0,min(k-1,n-1));
    }
    
    void reverseArr(vector<long long>& arr, int n, int k,int low,int high){
          if(low>high)
        return;
        int newLow=low;
        int newHigh=high;
        
        while(newLow<=newHigh){
            swap(arr[newLow],arr[newHigh]);
            newLow++;
            newHigh--;
        }
        // int newHigh=min(n-1,low+2k0)
        
        reverseArr(arr,n,k,low+k,min(n-1,low+2*k-1));
        return ;
        
    }
};

// { Driver Code Starts.
int main() {
    int t; 
    cin >> t; 
    while(t--){ 
        int n;
        cin >> n; 
        vector<long long> arr; 
        int k;
        cin >> k; 

        for(long long i = 0; i<n; i++)
        {
            long long x;
            cin >> x; 
            arr.push_back(x); 
        }
        Solution ob;
        ob.reverseInGroups(arr, n, k);
        
        for(long long i = 0; i<n; i++){
            cout << arr[i] << " "; 
        }
        cout << endl;
    }
}

  // } Driver Code Ends