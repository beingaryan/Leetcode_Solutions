class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>ans;
        vector<int>currentPath;
        int n=graph.size();
        vector<bool>visited(n,false);
        // currentPath.push_back(0);
            // visited[n];
        fun(graph,ans,0,visited,n,currentPath);
        return ans;
    }
    
    
    void fun(vector<vector<int>>& graph,vector<vector<int>> &ans, int vertex,vector<bool>&visited,int n, vector<int>&currentPath){
        if(vertex==n-1){
            currentPath.push_back(vertex);
            ans.push_back(currentPath);
             currentPath.pop_back();
            return;
        }
        
        if(visited[vertex]==true)return;
        
        visited[vertex]=true;
        currentPath.push_back(vertex);
        
        for(auto neighbours:graph[vertex])
            fun(graph,ans,neighbours,visited,n,currentPath);
        visited[vertex]=false;
        currentPath.pop_back();
        
        return;
    }
};
































// void sourceToTarget(vector<vector<int>>&graph,int currNode,vector<bool>&visited,int n,
//                        vector<int>&currentPath,vector<vector<int>>&ans){
//         if(currNode==n-1){
//             currentPath.push_back(currNode);
//             ans.push_back(currentPath);
//             currentPath.pop_back();
//             return;
//         }
//         if(visited[currNode]==true)
//             return;
        
//         visited[currNode]=true;
//         currentPath.push_back(currNode);
        
//         for(auto neighbours:graph[currNode]){
//             sourceToTarget(graph,neighbours,visited,n,currentPath,ans);
//         }
//         visited[currNode]=false;
//         currentPath.pop_back();
        
//     }
    
//     vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
//         vector<vector<int>>ans;
//         int n=graph.size();
//         vector<bool>visited(n);
//         vector<int>currentPath;
        
//         sourceToTarget(graph,0,visited,n,currentPath,ans);
//         return ans;
//     }
