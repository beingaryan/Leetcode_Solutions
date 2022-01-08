class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int m=obstacleGrid.length;
        int n=obstacleGrid[0].length;
        if(obstacleGrid[0][0]==1 || obstacleGrid[m-1][n-1]==1)return 0;
         return fun(m,n,0,0, obstacleGrid, new HashMap<String,Integer>());
    }
    
    public int fun(int m,int n, int r, int c,int[][] obstacleGrid, HashMap<String,Integer> memo){
    
    if(r>=m)return 0;
    if(c>=n)return 0;
        
    if(obstacleGrid[r][c]==1)return 0;
        
    if(r==m-1&&c==n-1)return 1;
        
        String currkey=Integer.toString(r)+'_'+Integer.toString(c);
        if(memo.containsKey(currkey)){
            return memo.get(currkey);
        }
    int right=fun( m, n, r,  c+1,obstacleGrid,memo);
    int down=fun( m, n, r+1,  c,obstacleGrid,memo);
    memo.put(currkey,right+down);
    return right + down;
    }
    
}