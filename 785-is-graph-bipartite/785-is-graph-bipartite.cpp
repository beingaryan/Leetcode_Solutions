class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
    int n=graph.size();
        
        vector<int>visited(n+1,-1);
        
        for(int i=0;i<n;i++){
            if(visited[i]==-1){
                if((checkEvenNodes(i,visited,0,graph)==false))
                    return false;
            }
        }
    return true;
    }
    
    
    bool checkEvenNodes(int vertex,vector<int>&visited,int colourIndex,vector<vector<int>>&graph){
        if(visited[vertex]!=-1)
            return visited[vertex]==colourIndex;
        
        visited[vertex]=colourIndex;
        
        for(auto neigh:graph[vertex]){
            if(checkEvenNodes(neigh,visited,1-colourIndex,graph)==false)
                return false;
        }
        return true;
    }
//     int n=graph.size();
        
//         vector<int>set(n,-1);
//         // vector<int>visited(n,0);
        
//         for(int i=0;i<n;i++)
//         {
//             if(set[i]==-1)//not yet visited
//             {
//                 if((checkEvenLength(set,i,graph,0))==false){
//                     return false;
//                 }
//             }
//         }
        
//         return true;
//     }
    
//     bool checkEvenLength(vector<int>&set,int vertex,vector<vector<int>>& graph,int setIndex)
//     {
//         if(set[vertex]!=-1)
//             return setIndex==set[vertex];
        
//         set[vertex]=setIndex;
        
//         for(auto neighbours:graph[vertex])
//         {
//             if(checkEvenLength(set,neighbours,graph,1-setIndex)==false)
//                 return false;
//         }
        
//         return true;
//     }
};