class Solution {
    public int minPathSum(int[][] grid) {
        int m=grid.length;
        int n=grid[0].length;
        return fun(m,n,0,0,grid,new HashMap<String,Integer>());
    }
       public int fun(int m,int n, int r, int c, int[][] grid, HashMap<String,Integer> memo){
           if(r>=m || c>=n)return 10001;
           
           if(r==m-1 && c==n-1){
               return grid[r][c];
           }
           
           String currkey=Integer.toString(r)+'_'+Integer.toString(c);
           if(memo.containsKey(currkey))
           {
               return memo.get(currkey);
           }
           
           int down=grid[r][c]+fun(m, n,  r+1,  c, grid, memo);
           int right=grid[r][c]+fun(m, n,  r,  c+1, grid, memo);
        
           memo.put(currkey,Math.min(down,right));
            return Math.min(down,right);
       }
    
}