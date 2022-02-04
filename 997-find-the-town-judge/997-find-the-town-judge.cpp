class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
          vector<int>outDeg(n+1,0);
          vector<int>inDeg(n+1,0);
        // vector<int>
        for(int i=0;i<trust.size();i++){
            outDeg[trust[i][0]]++;
            inDeg[trust[i][1]]++;
            
            // adj[edges[i][0]].push_back(edges[i][1]);
            // adj[edges[i][1]].push_back(edges[i][0]);
            
        }
        
        int townJudge=-1;
         for(int i=1;i<n+1;i++){
            // adj[edges[i][0]].push_back(edges[i][1]);
            // adj[edges[i][1]].push_back(edges[i][0]);
             
            if(inDeg[i]==n-1&&outDeg[i]==0)townJudge=i;
        }
        
        return townJudge;
        
    }
};