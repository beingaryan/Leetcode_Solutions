class Solution {
public:
    int rob(vector<int>& nums) {
   vector<vector<int>>dp(nums.size()+1,vector<int>(2,-1));
        int n=nums.size();
        int robFirst=1;
        return maxMoneyRobbed(nums,dp,0,robFirst);
    }
    
    int maxMoneyRobbed(vector<int>& nums,vector<vector<int>>&dp,int currIndex,int robFirst){
        if(currIndex>=nums.size()||((currIndex==nums.size()-1)&&(robFirst==0)))
            return 0;
        if(nums[currIndex]==-1)
            return 0;
        if(dp[currIndex][robFirst]!=-1)
            return dp[currIndex][robFirst];
        
        int robbed=0,notRobbed=0;
       
        if(currIndex==0)
        robbed=nums[currIndex]+maxMoneyRobbed(nums,dp,(currIndex+2),0);
        else
        robbed=nums[currIndex]+maxMoneyRobbed(nums,dp,(currIndex+2),robFirst);
        notRobbed=maxMoneyRobbed(nums,dp,(currIndex+1),robFirst);
        
        return dp[currIndex][robFirst]=max(robbed,notRobbed);
    }
};