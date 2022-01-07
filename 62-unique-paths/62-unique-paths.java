class Solution {
    public int uniquePaths(int m, int n) {
         return fun(m,n,0,0, new HashMap<String,Integer>());
    }
    
    public int fun(int m,int n, int r, int c, HashMap<String,Integer> memo){
    
    if(r>=m)return 0;
    if(c>=n)return 0;
    
    if(r==m-1&&c==n-1)return 1;
        String currkey=Integer.toString(r)+'_'+Integer.toString(c);
        if(memo.containsKey(currkey)){
            return memo.get(currkey);
        }
    int right=fun( m, n, r,  c+1,memo);
    int down=fun( m, n, r+1,  c,memo);
    memo.put(currkey,right+down);
    return right + down;
    }
    
}