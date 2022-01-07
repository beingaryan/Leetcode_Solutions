class Solution {
    public int climbStairs(int n) {
     return totalways(0,n,new HashMap <Integer, Integer> ());   
    }
    //int dp[n+1]={-1};
    
    public int totalways(int currentStair, int targetStair, HashMap<Integer, Integer> memo){
        if(currentStair==targetStair) return 1;
        if(currentStair>targetStair) return 0;
        
        
        int currentkey=currentStair;
        
        if(memo.containsKey(currentkey)){
            return memo.get(currentkey);
        }
        
        // if(dp[currentStair]!=-1)return dp[currentStair];
        int onestep=totalways(currentStair+1,targetStair, memo);
        int twostep=totalways(currentStair+2,targetStair, memo);
        
        memo.put(currentStair, onestep+twostep);
        return onestep+twostep;
        
    }
}