class Solution {
    public int maxProfit(int[] prices, int fee) {
        return fun(prices,0, true, fee, new HashMap<String, Integer>());
    }



    public int fun(int [] prices, int cd, boolean canBuy, int fee, HashMap<String, Integer> memo){
        
        
        if(cd>=prices.length )return 0;
        
        
        
        String currkey=Integer.toString(cd)+'_'+Boolean.toString(canBuy)+'_';
         if(memo.containsKey(currkey))return memo.get(currkey);
        
        int idle=fun(prices,cd+1,canBuy,fee,memo);
        
       
        if(canBuy==true)
        {
            int buy=-fee-prices[cd]+fun(prices,cd+1,false,fee,memo);
             memo.put(currkey, Math.max(idle,buy));

        }   
        
      
        if(canBuy==false){
           int sell=prices[cd]+fun(prices,cd+1,true,fee,memo);
             memo.put(currkey, Math.max(idle,sell));
        }
        
        return memo.get(currkey);
       
    }
}