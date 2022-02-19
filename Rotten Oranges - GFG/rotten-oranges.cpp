// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
       queue<pair<int,int>>parent;
       
        
        vector<int>directions={1,0,-1,0,1};
        
        int rowSize=grid.size();
        int colSize=grid[0].size();
        
        int noFresh=false;
        for(int i=0;i<rowSize;i++){
            for(int j=0;j<colSize;j++){
                if(grid[i][j]==2){
                    parent.push({i,j});
                }
                if(grid[i][j]==1){
                    noFresh=true;
                }
            }
        }
        
        if(noFresh==false){
            return -1;
        }
        
        int count=0;
        while(parent.empty()==false){
           
            int sz=parent.size();
            
            while(sz--){
                
            int r=parent.front().first;
            int c=parent.front().second;
            parent.pop();
                
            for(int i=0;i<4;i++){
                int newRow=r+directions[i];
                int newCol=c+directions[i+1];
                
                if(newRow>=0 && newRow<rowSize && newCol>=0 && newCol<colSize && grid[newRow][newCol]==1){// && grid[newRow][newCol]!=-1){
                     grid[newRow][newCol]=2;
                     parent.push({newRow,newCol});
                }
                
            }
        }
             count++;
        }
        
        for(int i=0;i<rowSize;i++){
            for(int j=0;j<colSize;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        
        return count-1;
        
        
        
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends