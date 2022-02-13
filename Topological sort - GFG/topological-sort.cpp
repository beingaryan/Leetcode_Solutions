// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    unordered_set<int>visited;
	    
	    unordered_set<int>recStack;
	    vector<int>vec;
	    for(int i=0;i<V;i++)
	    {
	        
	        if(visited.find(i)==visited.end())
	        {
	        dfs(visited,recStack,vec,i,adj);  
	        }
	    }
	    
	    reverse(vec.begin(),vec.end());
	    
	    
	    return vec;
	    
	}
	
	void dfs(unordered_set<int>&visited,unordered_set<int>&recStack,vector<int>&vec,int vertex,vector<int> adj[]){
	    visited.insert(vertex);
	    recStack.insert(vertex);
	    
	    for(auto neighbour:adj[vertex]){
	        if(visited.find(neighbour)==visited.end()){//not present
	            dfs(visited,recStack,vec,neighbour,adj);
	        }
	    }
	    
	    vec.push_back(vertex);
	    recStack.erase(vertex);
	 return;   
	}
};

// { Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}  // } Driver Code Ends