// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges)
	{
	    
	    vector<int>distance(n+1,INT_MAX);
	    distance[0]=0;
	for(int i=0;i<n-1;i++){
	    for(auto edge:edges){
	        int src=edge[0];
	        int dest=edge[1];
	        int dist=edge[2];
	        
	        if(distance[src]!=INT_MAX)
	        distance[dest]=min(distance[dest],dist+distance[src]);
	    }
	}
	
	for(auto edge:edges){
	        int src=edge[0];
	        int dest=edge[1];
	        int dist=edge[2];
	        
	        if(distance[src]!=INT_MAX&&distance[dest]>distance[src]+dist)
	       // distance[dest]=min(distance[dest],dist+distance[src]);
	       return 1;
	    }
	
	return 0;
	
	}
	
// 	 vector<int>distance(n+1,INT_MAX);
// 	 distance[0]=0;
// 	 for(int i=0;i<n-1;i++){
// 	 for(auto edge:edges){
// 	     int source=edge[0];
// 	     int destination=edge[1];
// 	     int weight=edge[2];
	     
// 	   //  if(distance[])
// 	   if(distance[source]!=INT_MAX)
// 	   distance[destination]=min(distance[destination],distance[source]+weight);
// 	 }
// 	 }
	 
	 
// 	 for(auto edge:edges){
// 	     int source=edge[0];
// 	     int destination=edge[1];
// 	     int weight=edge[2];
	     
// 	     if(distance[source]!=INT_MAX&&distance[destination]>distance[source]+weight)
// 	     return 1;//Negative Weight Cycle is Present
// 	 }
// 	 return 0;
	    
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends