class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        
        vector<bool>visited(n,false);
        
        vector<vector<int>>ans;
        vector<int>path;
        sourceToDestination(graph,visited,0,n-1,path,ans);
        return ans;
    }
    
    void sourceToDestination(vector<vector<int>>& graph,vector<bool>&visited,int source,int destination,vector<int>&path,vector<vector<int>>&ans)
    {
        if(source==destination){
        path.push_back(source);
        visited[source]=true;
        // vector<int> vect2;
        //     vect2=path;
        ans.push_back(path);
         path.pop_back();
        visited[source]=false;
        return;
        }
        
        
        path.push_back(source);
        visited[source]=true;
        
        for(int i=0;i<graph[source].size();i++){
            if(visited[graph[source][i]]==false)
                sourceToDestination(graph,visited,graph[source][i],destination,path,ans);
        }
        
        path.pop_back();
        visited[source]=false;
        return;
    }
    
    
    
    
    };