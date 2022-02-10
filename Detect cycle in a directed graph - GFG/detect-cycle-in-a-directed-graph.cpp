// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        unordered_set<int>visited;
        unordered_set<int>recStack;
        
        for(int i=0;i<V;i++){
            if(visited.find(i)==visited.end()){
                if(dfs(visited,recStack,i,adj))
                return true;
            }
        }
        
        return false;
    }
    
    bool dfs(unordered_set<int>&visited,unordered_set<int>&recStack,int currVertex,vector<int>adj[]){
        visited.insert(currVertex);
        recStack.insert(currVertex);
        
        for(auto neighbours:adj[currVertex]){
            if(visited.find(neighbours)==visited.end()){
                if(dfs(visited,recStack,neighbours,adj))
                return true;
            }
            else if(recStack.find(neighbours)!=recStack.end()){
                return true;
            }
            }
            // s.find(key)
            // visited.erase(currVertex);
            recStack.erase(currVertex);
            return false;
        }
    
    
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends