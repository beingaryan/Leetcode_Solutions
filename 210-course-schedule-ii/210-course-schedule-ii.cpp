class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& edges) {
    
        vector<int>ans;
        
    vector<vector<int>>adj(n);
        
        for(int i=0;i<edges.size();i++){
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        unordered_set<int>visited;
        unordered_set<int>recStack;
        
        for(int i=0;i<n;i++){
            if(visited.find(i)==visited.end())
            {
                if(dfs(i,adj,visited,recStack,ans)){
                    vector<int>v;
                    return v;
                }
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
    bool dfs(int vertex, vector<vector<int>>&adj,unordered_set<int>&visited,unordered_set<int>&recStack,vector<int>&ans){
        visited.insert(vertex);
        recStack.insert(vertex);
        
        for(auto neighbours:adj[vertex]){
            if(visited.find(neighbours)==visited.end())//not present
            {
                if(dfs(neighbours,adj,visited,recStack,ans))
                    return true;
            }
            else if(recStack.find(neighbours)!=recStack.end())
            {
            
                return true;
            }
        }
        
        ans.push_back(vertex);
        recStack.erase(vertex);
        return false;
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    // }
//         vector<int>ans;
//         vector<vector<int>>adj(n);
        
//         for(int i=0;i<edges.size();i++){
//             adj[edges[i][1]].push_back(edges[i][0]);
//         }
        
//         unordered_set<int>visited;
//         unordered_set<int>recStack;
        
//         for(int i=0;i<n;i++){
//             if(visited.find(i)==visited.end()){
//                 if(dfs(adj,i,visited,recStack,ans)){
//                     vector<int>v;
//                     return v;
//                 }

//             }
//         }
        
//         reverse(ans.begin(),ans.end());
        
//         return ans;
//     }
    
//     bool dfs(vector<vector<int>>&adj,int currentVertex, unordered_set<int>&visited, unordered_set<int>&recStack,vector<int>&ans){
//         visited.insert(currentVertex);
//         recStack.insert(currentVertex);
        
//         for(auto neighbours:adj[currentVertex]){
//             if(visited.find(neighbours)==visited.end()){
//                 if(dfs(adj,neighbours,visited,recStack,ans))
//                     return true;
//             }else if(recStack.find(neighbours)!=recStack.end()){
//                 return true;
//             }
//         }
//         ans.push_back(currentVertex);
//         recStack.erase(currentVertex);
        
        
//         return false;
        
        
//     }
};