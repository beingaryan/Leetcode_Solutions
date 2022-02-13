class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>>adj(n);
        
        // int n=edges.size();
        
        
        for(int i=0;i<edges.size();i++){
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        unordered_set<int>visited;
        unordered_set<int>recStack;
        
        for(int i=0;i<n;i++)
        {
            if(visited.find(i)==visited.end())
            {
            if(dfs(adj,i,visited,recStack))
                return false;//cycle is present
            }
        }
        return true;
    }
    
    bool dfs(vector<vector<int>>&adj,int vertex,unordered_set<int>&visited,unordered_set<int>&recStack)
    {
        visited.insert(vertex);
        recStack.insert(vertex);
        
        for(auto neighbours:adj[vertex]){
            if(visited.find(neighbours)==visited.end())
            {//not visited{
                if(dfs(adj,neighbours,visited,recStack))
                    return true;
            }
            else if(recStack.find(neighbours)!=recStack.end()){
                return true;//already visited and current Path is present
            }
            }
        recStack.erase(vertex);
        return false;
        }
    

    
    
//     vector<int>ans;
//         vector<vector<int>>adj(n);
        
//         for(int i=0;i<edges.size();i++){
//             adj[edges[i][1]].push_back(edges[i][0]);
//         }
        
//         unordered_set<int>visited;
//         unordered_set<int>recStack;
        
//         for(int i=0;i<n;i++){
//             if(visited.find(i)==visited.end()){
//                 if(dfs(adj,i,visited,recStack,ans)){
//                     return false;
//                 }

//             }
//         }
        
//         // reverse(ans.begin(),ans.end());
        
//         return true;
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