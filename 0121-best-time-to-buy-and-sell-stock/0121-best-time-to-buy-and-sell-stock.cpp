class Solution {
public:
    int maxProfit(vector<int>& prices) {
       // vector<int>dp(prices.size(),vector<int>(2,vector<int>(2,-1)));
         // vector<vector<vector<int>>>dp(prices.size()+1,vector<vector<int>>(2,vector<int>(2,-1)));
        vector<vector<vector<int>>>dp(prices.size()+1,vector<vector<int>>(2,vector<int>(2,-1)));
        int kTrans=1;
        int canBuy=1;
        int currDay=0;
        
        return maxEarn(prices,prices.size(),kTrans,canBuy,currDay,dp);
    }
    
int maxEarn(vector<int>& prices,int n,int kTrans,int canBuy, int currDay,vector<vector<vector<int>>>&dp){
        if(currDay>=n)
            return 0;
        
        if(kTrans<=0)
            return 0;
    
    if(dp[currDay][kTrans][canBuy]!=-1)
        return dp[currDay][kTrans][canBuy];
        
        if(canBuy==1){
            int buy=-prices[currDay]+maxEarn(prices,n,kTrans,0,currDay+1,dp);
            int idle=maxEarn(prices,n,kTrans,canBuy,currDay+1,dp);
            
            dp[currDay][kTrans][canBuy]=max(buy,idle);
        }
    else{
            int sell=prices[currDay]+maxEarn(prices,n,kTrans-1,1,currDay+1,dp);
            int idle=maxEarn(prices,n,kTrans,canBuy,currDay+1,dp);
            
            dp[currDay][kTrans][canBuy]=max(sell ,idle);   
    }
    return dp[currDay][kTrans][canBuy];
    }
};