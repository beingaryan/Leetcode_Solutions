// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int findMin(int arr[], int n){
        int low=0;
        int high=n-1;
        int mid=-1;
       int ans=-1;
        while(low<=high){
           
            mid=(high+low)/2;
            int prev=(n+mid-1)%n;
            int next=(mid+1)%n;
            
            if(arr[mid]<=arr[prev]&&arr[mid]<=arr[next])
                return arr[mid];
                
            else if(arr[mid]>=arr[high])
            low=mid+1;
            else
            high=mid-1;
        }
        
        return arr[mid];
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
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution ob;
		cout<<ob.findMin(a, n)<<endl;
	}
	return 0;
}  // } Driver Code Ends