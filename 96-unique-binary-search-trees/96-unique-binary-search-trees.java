class Solution {
    public int numTrees(int n) {
        return nthCatalon(n, new HashMap<Integer, Integer>());
    }
    
    public int nthCatalon( int n, HashMap<Integer, Integer> memo){
         
        if(n <= 1)
        return 1;
        
        int currentKey = n;
        
        if(memo.containsKey(currentKey)){
            return memo.get(currentKey);
        }
        
        int ways = 0;
        for(int i =0; i< n;i++) {
            ways += nthCatalon(i, memo)*nthCatalon(n-i-1, memo);
        }
        
        memo.put(currentKey, ways);
        return memo.get(currentKey);
    }
}