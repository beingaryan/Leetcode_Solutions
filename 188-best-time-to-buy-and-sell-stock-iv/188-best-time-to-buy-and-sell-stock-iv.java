class Solution {
    public int maxProfit(int k, int[] prices) {
          return fun(prices,0, 1,k, new HashMap<String, Integer>());
    }
    
     public int fun(int [] prices, int cd, int canBuy, int transaction, HashMap<String, Integer> memo){
        
        
        if(cd>=prices.length || transaction==0)return 0;
        
        
        
      //  String currkey=Integer.toString(cd)+'_'+Integer.toString(canBuy)+'_'+Integer.toString(transaction);
         String currkey= ""+cd+"_"+canBuy+"_"+transaction;
             
             
         if(memo.containsKey(currkey))return memo.get(currkey);
        
        int idle=fun(prices,cd+1,canBuy,transaction,memo);
        
       
        if(canBuy==1)
        {
            int buy=-prices[cd]+fun(prices,cd+1,0,transaction,memo);
             memo.put(currkey, Math.max(idle,buy));
            return Math.max(idle,buy);

        }   
        
      
        else{
           int sell=prices[cd]+fun(prices,cd+1,1,transaction-1,memo);
             memo.put(currkey, Math.max(idle,sell));
            return Math.max(idle,sell);
        }
        
        // return memo.get(currkey);
       
    }
}
