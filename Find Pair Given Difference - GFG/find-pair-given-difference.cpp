// { Driver Code Starts
#include<bits/stdc++.h>
 
using namespace std; 


bool findPair(int arr[], int size, int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l,n;
        cin>>l>>n;
        int arr[l];
        for(int i=0;i<l;i++)
            cin>>arr[i];
        if(findPair(arr, l, n))
            cout<<1<<endl;
        else cout<<"-1"<<endl;
    }
    
  
    return 0;
}// } Driver Code Ends


bool findPair(int nums[], int size, int k){
      vector<int>v;
        unordered_map<int,int>mp;
        
        for(int i=0;i<size;i++){
            if(mp.find((k+nums[i]))!=mp.end())
            {
                return true;
                //  v.push_back(mp[k-nums[i]]);
                // v.push_back(i);
                // return v;
            }
            else if(mp.find((nums[i]-k))!=mp.end())
            return true;
            else{
                mp[nums[i]]=i;
            }
        }
        return false;
    
}