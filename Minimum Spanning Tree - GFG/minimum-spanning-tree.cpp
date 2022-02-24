// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
     
     
     priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
     vector<int>distance(V+1,INT_MAX);
     vector<bool>visited(V+1,false);
     
     distance[0]=0;
     
     pq.push({0,0});
     int ans=0;
     while(!pq.empty()){
         int u=pq.top().second;
         pq.pop();
         visited[u]=true;
         
         for(auto neighbours:adj[u]){
             int v=neighbours[0];
             int wt=neighbours[1];
             
             if(visited[v]==false&&distance[v]>wt){
                 distance[v]=wt;
                 
                 pq.push({wt,v});
             }
         }
        //  ans+=
     }
      int sum=0;
        for(int i=0;i<V;i++)
        {
            sum+=distance[i];
        }
        return sum;
    //   return ans; 
    }
    
    // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
    //     vector<int>distance(V+1,INT_MAX);
        
    //     pq.push({0,0});///distance,src
        
    //     distance[0]=0;
    //     int ans=0;
    //      bool mst[V];
    //      for(int i=0;i<V;i++)
    //     {
    //         mst[i]=false;
    //     }
    //     while(!pq.empty()){
    //         ans+=pq.top().first;
    //         int u=pq.top().second;
    //         pq.pop();
    //         mst[u]=true;
    //         for(auto neigh:adj[u]){
    //             int v=neigh[0];
    //             int wt=neigh[1];
                
    //             if(mst[v]==false&&distance[v]>wt){
    //                 distance[v]=wt;
    //                 pq.push({distance[v],v});
    //             }
    //         }
            
    //     }
        
    //      int sum=0;
    //     for(int i=0;i<V;i++)
    //     {
    //         sum+=distance[i];
    //     }
    //     return sum;
    //   a
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends