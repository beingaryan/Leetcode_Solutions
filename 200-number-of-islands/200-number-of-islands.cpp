class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        int m=grid.size();
        int n=grid[0].size();
        
        for(int currentRow=0;currentRow<m;currentRow++){
            for(int currentCol=0;currentCol<n;currentCol++){
              if(grid[currentRow][currentCol]=='1') {
                  // grid[currentRow][currentCol]='0';
                  ans++;
                  totalIslands(grid,currentRow,currentCol,m,n);
              } 
            }
        }
        return ans;
         
//         vector<bool>visited(n,false);
//         totalIslands(grid,)
//          updatedFill(image,0,0,grid.size(),grid[0].size(),visited,image[sr][sc]);
    }
    
    
    void totalIslands(vector<vector<char>>& grid,int sr,int sc,int m, int n)
    {
        if(sr<0||sr>=m||sc<0||sc>=n||grid[sr][sc]=='0')
            return;
        
        grid[sr][sc]='0';
        totalIslands(grid,sr-1,sc,m,n);
        totalIslands(grid,sr,sc+1,m,n);
        totalIslands(grid,sr+1,sc,m,n);
        totalIslands(grid,sr,sc-1,m,n);
        
        return;
    }
    };