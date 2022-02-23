class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
      vector<vector<vector<int>>>dp(prices.size()+1,vector<vector<int>>(2,vector<int>(k+1,-1)));
        
        //prices.size() canBuy kTransaction
        int currDay=0;
        int canBuy=1;
        // int kTrans=1;
        return maxEarn(dp,prices,currDay, canBuy, k,prices.size());
        
    }
    
    int maxEarn(vector<vector<vector<int>>>&dp,vector<int>& prices, int currDay, int canBuy, int kTrans,int n ){
        
       if(currDay>=n)return 0;
        
        if(kTrans<=0)return 0;
        
        if(dp[currDay][canBuy][kTrans]!=-1)
            return dp[currDay][canBuy][kTrans];
        
        if(canBuy==1){
            int buy=-prices[currDay]+maxEarn(dp,prices,currDay+1,0,kTrans,n);
            int idle=maxEarn(dp,prices,currDay+1,canBuy,kTrans,n);
            
            dp[currDay][canBuy][kTrans]=max(buy,idle);
        }else if(canBuy==0){
            
             int sell=prices[currDay]+maxEarn(dp,prices,currDay+1,1,kTrans-1,n);
            int idle=maxEarn(dp,prices,currDay+1,canBuy,kTrans,n);
              dp[currDay][canBuy][kTrans]=max(sell,idle);
        }
       return  dp[currDay][canBuy][kTrans];
    }
    
};