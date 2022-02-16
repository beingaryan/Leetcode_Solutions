// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool>visited(V+1,false);
        
        for(int i=0;i<V;i++){
            if(visited[i]==false){
                if(dfs(i,adj,visited,-1))
                return true;
            }
        }
        return false;
    }
    
    bool dfs(int vertex,vector<int> adj[],vector<bool>&visited,int parent ){
        visited[vertex]=true;
        
        for(auto neighbours: adj[vertex]){
            if(visited[neighbours]==false){
                if(dfs(neighbours,adj,visited,vertex))
                return true;
            }else if(parent!=neighbours)
            return true;
        }
        return false;
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
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends