class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
     vector<vector<int>>adj(n);
        
        for(int i=0;i<paths.size();i++){
            adj[paths[i][0]-1].push_back(paths[i][1]-1);
            adj[paths[i][1]-1].push_back(paths[i][0]-1);    
        }
        
        vector<int>result(n,0);
        
        for(int i=0;i<n;i++){
            if(result[i]==0)
                dfs(i,result,adj);
        }
        
        return result;
        
    }
    
    
    void dfs(int v,vector<int>&result,vector<vector<int>>&adj){
        
        vector<bool>used(5,0);
        
        for(int i=0;i<adj[v].size();i++){
            used[result[adj[v][i]]]=1;
        }
        
        
        for(int k=1;k<5;k++){
            
            if(used[k]==0){
                result[v]=k;
                break;
            }
        }
        
        
        
        
        
        for(int i=0;i<adj[v].size();i++){
            if(result[adj[v][i]]==0)
                dfs(adj[v][i],result,adj);
            
        }
        return;
    }
};