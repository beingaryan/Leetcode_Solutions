class Solution {
public:
    int maxProfit(vector<int>& prices) {
      vector<vector<int>>dp(prices.size()+1,vector<int>(2,-1));
        
        //prices.size() canBuy kTransaction
        int currDay=0;
        int canBuy=1;
        // int kTrans=3*;
        return maxEarn(dp,prices,currDay, canBuy, prices.size());
        
    }
    
    int maxEarn(vector<vector<int>>&dp,vector<int>& prices, int currDay, int canBuy, int n ){
        
       if(currDay>=n)return 0;
        
        // if(kTrans<=0)return 0;
        
        if(dp[currDay][canBuy]!=-1)
            return dp[currDay][canBuy];
        
        if(canBuy==1){
            int buy=-prices[currDay]+maxEarn(dp,prices,currDay+1,0,n);
            int idle=maxEarn(dp,prices,currDay+1,canBuy,n);
            
            dp[currDay][canBuy]=max(buy,idle);
        }else if(canBuy==0){
            
             int sell=prices[currDay]+maxEarn(dp,prices,currDay+1,1,n);
            int idle=maxEarn(dp,prices,currDay+1,canBuy,n);
              dp[currDay][canBuy]=max(sell,idle);
        }
       return  dp[currDay][canBuy];
    }
};