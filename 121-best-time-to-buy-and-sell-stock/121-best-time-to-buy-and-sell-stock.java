class Solution {
    public int maxProfit(int[] prices) {
        
        return fun(prices,0, true,1, new HashMap<String, Integer>());
    }
    
    public int fun(int [] prices, int cd, boolean canBuy, int transaction, HashMap<String, Integer> memo){
        
        
        if(cd>=prices.length || transaction==0)return 0;
        
        
        
        String currkey=Integer.toString(cd)+'_'+Boolean.toString(canBuy)+'_'+Integer.toString(transaction);
        if(memo.containsKey(currkey))return memo.get(currkey);
        
        int idle=fun(prices,cd+1,canBuy,transaction,memo);
        // int buy=0;
        // int sell=0;
       
        if(canBuy==true)
        {
           int buy=-prices[cd]+fun(prices,cd+1,false,transaction,memo);
             memo.put(currkey, Math.max(idle,buy));

        }   
        
      
        if(canBuy==false){
           int sell=prices[cd]+fun(prices,cd+1,true,transaction-1,memo);
             memo.put(currkey, Math.max(idle,sell));
        }
        
        // memo.put(currkey, Math.max(idle,Math.max(buy,sell)));
        return memo.get(currkey);
       
    }
}