class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size()+1,-1);
        return maxMoneyRobbed(nums,dp,0);
    }
    
    int maxMoneyRobbed(vector<int>& nums,vector<int>&dp,int currIndex){
        if(currIndex>=nums.size())
            return 0;
        
        if(dp[currIndex]!=-1)
            return dp[currIndex];
        int robbed=nums[currIndex]+maxMoneyRobbed(nums,dp,currIndex+2);
        int notRobbed=maxMoneyRobbed(nums,dp,currIndex+1);
        
        return dp[currIndex]=max(robbed,notRobbed);
    }
};