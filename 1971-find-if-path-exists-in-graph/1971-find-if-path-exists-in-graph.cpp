class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>adj(n);
        
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
            
        }
        
        vector<bool>visited(n,false);
        if(source==destination)return true;
        
        return pathExists(source,  destination,adj,visited);
        // for(int i=0;i<adj.size();i++)
    }
    
    bool pathExists(int source, int destination,vector<vector<int>>&adj,vector<bool>&visited){
        
        if(source==destination)return true;
        
        
        
        
        visited[source]=true;
        
        
        
        for(int i=0;i<adj[source].size();i++){
            if(visited[adj[source][i]]==false){
            if(pathExists(adj[source][i],destination,adj,visited)==true)return true;}
        }
        
        return false;
        
        
    }
};