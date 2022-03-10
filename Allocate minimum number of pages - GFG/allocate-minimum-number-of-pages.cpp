// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        int start=0;
        long totalSum=0;
        
        for(int x=0;x<N;x++)
        totalSum+=A[x];
        
        long int end=totalSum;
        int answer=-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            
            if(isPossible(A,N,M,mid))
                {
                    answer=mid;
                    end=mid-1;
                }
                else
                start=mid+1;
        }
        return answer;
        
    }
    
    bool isPossible(int pages[],int N,int M,int boundVal)
    {
        
        int studentsCount=1;
        int currentSum=0;
        
        for(int currentPage=0;currentPage<N;currentPage++)
        {
            if(pages[currentPage]>boundVal)
            return false;
            
            if(currentSum+pages[currentPage]<=boundVal)
                currentSum=currentSum+pages[currentPage];
                
            else
            {
                studentsCount+=1;
                currentSum=pages[currentPage];
                
                if(studentsCount>M)
                {
                return false;
                
                    
                }
            }
                
        }
        return true;
        
        
        
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends