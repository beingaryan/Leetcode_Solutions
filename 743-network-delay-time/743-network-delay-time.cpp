class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        
        for(int i=0;i<times.size();i++){
            adj[times[i][0]].push_back({times[i][1],times[i][2]});//source,target,weight
        }
        
        //  bool visit[n+1];
        // memset(visit, false, sizeof(visit));
        vector<int>distance(n+1,INT_MAX);
        
        distance[k]=0;
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        pq.push({0,k});//dist,src
          
        while(!pq.empty()){
            
            int oldV=pq.top().second;
            pq.pop();
        for(auto neighbours:adj[oldV]){
            int newV=neighbours.first;
            int oldToNewDist=neighbours.second;
            
            if(distance[newV]>distance[oldV]+oldToNewDist){
                distance[newV]=distance[oldV]+oldToNewDist;
                pq.push({distance[newV],newV});
            }
        }
           
    
    } 
        int ans=-1;
            for(int i=1;i<n+1;i++){
                ans=max(ans,distance[i]);
            }
        if(ans==INT_MAX)return -1;
        return ans;   
    }
};