// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        vector<int>distance(V+1,INT_MAX);
        pq.push({0,S});
        distance[S]=0;
        bool vis[V];
         for(int i=0;i<V;i++)
        {
            vis[i]=false;
        }
        while(!pq.empty()){
            int u=pq.top().second;
            pq.pop();
            vis[u]=true;
            for(auto neighbours:adj[u]){
                // cout<<neighbours;
                int v=neighbours[0];
                int wt=neighbours[1];
                
                if(vis[v]==false&&distance[v]>distance[u]+wt)
                {
                    distance[v]=distance[u]+wt;
                    pq.push({distance[v],v});
                }
            }
        }
        return distance;
    }
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends