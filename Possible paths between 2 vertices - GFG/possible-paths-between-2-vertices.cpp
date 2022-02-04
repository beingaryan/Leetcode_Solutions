// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to count paths between two vertices in a directed graph.
    int countPaths(int n, vector<int> adj[], int source, int destination) {
        // cout<<adj[0][];
        //  for (int i=0; i<n; i++)
        //  {
        //       for (int j=0; j<adj[i].size(); j++)
        //  {
        //      cout<<adj[i][j]<<" ";
        //  }
        //      cout<<endl;
        //  }
        
        vector<bool>visited(n,false);
        vector<vector<int>>ans;
        vector<int>path;
        sourceToDestination(adj,visited,source,destination,path,ans);
        return ans.size();
        // return 0;
    }
    
    void sourceToDestination(vector<int> adj[],vector<bool>&visited,int source, int destination,vector<int>&path,vector<vector<int>>&ans)
{
    if(source==destination)
    {
        path.push_back(source);
        visited[source]=true;
        
        ans.push_back(path);
        
        path.pop_back();
        visited[source]=false;
    }
    
    path.push_back(source);
    visited[source]=true;
    
    for(auto connection:adj[source]){
    if(visited[connection]==false){
    sourceToDestination(adj,visited,connection,destination,path,ans);
    }
    }
     visited[source]=false;
    path.pop_back();
   
    return;
}
    
    
    
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // adj[v].push_back(u);
        }
        int source, destination;
        cin >> source >> destination;
        Solution obj;
        cout << obj.countPaths(V, adj, source, destination) << endl;
    }
    return 0;
}  // } Driver Code Ends