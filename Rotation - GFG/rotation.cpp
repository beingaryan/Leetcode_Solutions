// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int findKRotation(int arr[], int n) {
	    int low=0;
	    int high=n-1;
	    while(low<=high){
	        int mid=low+(high-low)/2;
	        int prev = (mid-1 + n)  %n , next = (mid+1)%n;
	        if(arr[prev]>=arr[mid]&&arr[mid]<=arr[next])
	       // high=mid-1;ret
	       return mid;
	       
	       else  if(arr[high]>=arr[mid])
	        high=mid-1;
	        
	        
	        
	       
	       else if(arr[mid]>=arr[low])
	       low=mid+1;
	        
	        
	    }
	    return -1;
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends