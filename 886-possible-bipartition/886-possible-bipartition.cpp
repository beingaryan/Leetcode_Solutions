class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>>graph(n+1);
        
        for(int i=0;i<dislikes.size();i++){
            graph[dislikes[i][0]].push_back(dislikes[i][1]);
            graph[dislikes[i][1]].push_back(dislikes[i][0]);
            
        }
        
        vector<int>set(n+1,-1);
        
        for(int i=1;i<=n;i++){
            if(set[i]==-1){
                if(checkEvenLength(i,graph,set,0)==false)
                    return false;
            }
        }
        return true;
    }
    
    bool checkEvenLength(int vertex,vector<vector<int>>&graph,vector<int>&set,int setIndex){
        if(set[vertex]!=-1)
            return setIndex==set[vertex];
        
        set[vertex]=setIndex;
        
        for(auto neighbours:graph[vertex]){
            if(checkEvenLength(neighbours,graph,set,1-setIndex)==false)
                return false;
        }
        return true;
    }
};