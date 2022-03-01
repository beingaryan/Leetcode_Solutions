class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
     int maxAreaSol=0;
     int m=grid.size();
        int n=grid[0].size();
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    
                    maxAreaSol=max(maxAreaSol,maxArea(grid,i,j,m,n));
                    // cout<<maxAreaSol<<" i "<<i<<" j "<<j<<endl;
                }
            }
        }
        return maxAreaSol;
    }
    
    int maxArea(vector<vector<int>>& grid, int currentRow, int currentCol, int rowSize, int colSize){
        if(currentRow<0||currentRow>=rowSize||currentCol<0||currentCol>=colSize||grid[currentRow][currentCol]!=1)
            return 0;
        
        grid[currentRow][currentCol]=0;
        
        int up=maxArea(grid,currentRow-1,currentCol,rowSize,colSize);
        int down=maxArea(grid,currentRow+1,currentCol,rowSize,colSize);
        int left=maxArea(grid,currentRow,currentCol-1,rowSize,colSize);
        int right=maxArea(grid,currentRow,currentCol+1,rowSize,colSize);
        
        return 1+left+down+right+up;
    }
};