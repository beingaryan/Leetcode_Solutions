class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
       int m=text1.size();
        int n=text2.size();
        
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        
        return LCS(dp,m,n,text1,text2);
    }
    
    int LCS(vector<vector<int>>&dp,int m,int n,string &text1,string &text2){
        if(m<=0||n<=0)
            return 0;
        
        if(dp[m][n]!=-1)
            return dp[m][n];
        
        if(text1[m-1]==text2[n-1])
            dp[m][n]=1+LCS(dp,m-1,n-1,text1,text2);
    else{
        dp[m][n]=max(LCS(dp,m,n-1,text1,text2),LCS(dp,m-1,n,text1,text2));
    }
    return dp[m][n];
}
    
};