// { Driver Code Starts


#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	    
	    int lo=lastOccurence(arr,0,n-1,x,n);
	    int fo=firstOccurrence(arr,0,n-1,x,n);
	   // cout<<lo<<" "<<fo<<endl;
	   
	   
	   
	   if(lo==-1&&fo==-1)
	   return 0;
	   
	    return lo-fo+1;
	}
	
	int firstOccurrence(int arr[],int low, int high, int x,int n)
	{
	
	while(low<=high){
	    int mid=low+(high-low)/2;
	    
	    if(arr[mid]<x)
	    low=mid+1;
	    
	    else if((arr[mid]==x&&arr[mid-1]<x)||(arr[mid]==x&&mid==0))
	    return mid;
	    
	    else 
	    high=mid-1;
	    
	}
	return -1;
	    
	}
	
		int lastOccurence(int arr[],int low, int high, int x,int n)
	{
	
	while(low<=high){
	    int mid=low+(high-low)/2;
	    
	    if(arr[mid]>x)
	    high=mid-1;
	    
	    else if((arr[mid]==x&&arr[mid+1]>x)||(arr[mid]==x&&mid==n-1))
	    return mid;
	    
	    else 
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
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends