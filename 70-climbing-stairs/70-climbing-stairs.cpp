class Solution {
public:
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
       return fun(n,dp);
    }
    
    int fun(int n,vector<int>&dp){
        if(n<0)return 0;
        if(n==0)return 1;
        if(dp[n]!=-1)return dp[n];
        int one=fun(n-1,dp);
        int two=fun(n-2,dp);
        
        return dp[n]=one+two;
    }
};