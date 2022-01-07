class Solution {
    public int maxProfit(int[] prices) {
        
        return fun(prices,0, true, new HashMap<String, Integer>());
    }
    
    public int fun(int [] prices, int cd, boolean canBuy,  HashMap<String, Integer> memo){
        
        
        if(cd>=prices.length )return 0;
        
        
        
        String currkey=Integer.toString(cd)+'_'+Boolean.toString(canBuy)+'_';
         if(memo.containsKey(currkey))return memo.get(currkey);
        
        int idle=fun(prices,cd+1,canBuy,memo);
        
       
        if(canBuy==true)
        {
            int buy=-prices[cd]+fun(prices,cd+1,false,memo);
             memo.put(currkey, Math.max(idle,buy));

        }   
        
      
        if(canBuy==false){
           int sell=prices[cd]+fun(prices,cd+1,true,memo);
             memo.put(currkey, Math.max(idle,sell));
        }
        
        return memo.get(currkey);
       
    }
}