// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    int sr=KnightPos[0]-1;
	    int sc=KnightPos[1]-1;
	    int dr=TargetPos[0]-1;
	    int dc=TargetPos[1]-1;
	    vector<vector<int>>grid(N+4,vector<int>(N+4,0));
	 
	 queue<pair<int,int>>q;
// 	 int dx={-1
	 int steps=0;
	 q.push({sr,sc});
	 //2,-1
	 //2,1 D
	 //1,-2 D
	 //1,2
	 //-1,2 D
	 //-1,-2
	 //-2,-1 D
	 //-2,1 D
    
    vector<int> dx={2,2,1,1,-1,-1,-2,-2};
    vector<int> dy={-1,1,-2,2,2,-2,-1,1};

	 while(!q.empty()){
	     int size=q.size();
	     while(size--){
	         int currRow=q.front().first;
	         int currCol=q.front().second;
	         q.pop();
	         if(currRow==dr&&currCol==dc)
	         return steps;
	         
	         for(int i=0;i<8;i++){
	             int newRow=currRow+dx[i];
	             int newCol=currCol+dy[i];
	             
	             if(newRow<0||newRow>=N||newCol<0||newCol>=N||grid[newRow][newCol]==1){
	                 continue;
	             }
	             grid[newRow][newCol]=1;
	             q.push({newRow,newCol});
	         }
	         
	         
	     }
	     steps++;
	 }
	 return steps;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends