// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minThrow(int n, int arr[]){
        
        unordered_map<int,int>mp;
        
        for(int i=0;i<2*n;i+=2){
            mp[arr[i]]=arr[i+1];
        }
        
        queue<int>q;
        vector<int>visited(31,0);
        q.push(1);
        visited[1]=1;
        int steps=0;
        
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                int top=q.front();
                q.pop();
                
                if(top==30)
                return steps;
                
                for(int k=1;k<=6;k++){
                    if(top+k>30)
                    break;
                    
                    if(!visited[top+k]){
                        visited[top+k]=1;
                        
                        if(mp.find(top+k)==mp.end()){
                            q.push(top+k);
                        }else{
                            q.push(mp[top+k]);
                        }
                    }
                }
            }
            steps++;
        }
        return -1;
        
    }
    

// int minThrow(int n, int arr[]){
//       unordered_map<int,int>m;
//       for(int i=0;i<2*n;i+=2)
//       {
//           m[arr[i]]=arr[i+1];
//       }
//       vector<int>vis(31,0);
//       queue<int>q;
//       q.push(1);
//       vis[1]=1;
//       int steps=0;
//       while(!q.empty())
//       {
//           int size=q.size();
//           for(int i=0;i<size;i++)
//           {
//               int x=q.front();
//               q.pop();
//               if(x==30)return steps;
//               for(int k=1;k<=6;k++)
//               {
//                   if(x+k>30)break;
//                   if(!vis[k+x])
//                   {
//                       vis[k+x]=1;
//                       if(m.find(k+x)==m.end())
//                           q.push(k+x);
//                       else
//                           q.push(m[k+x]);
//                   }    
//               }
//           }
//           steps++;
//       }
//       return -1;
//   }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[2*N];
        for(int i = 0;i < 2*N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.minThrow(N, arr)<<"\n";
    }
    return 0;
}  // } Driver Code Ends