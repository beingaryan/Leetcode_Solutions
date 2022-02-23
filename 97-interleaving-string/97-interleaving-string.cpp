class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) 
    {
        int s1len=s1.size();
        int s2len=s2.size();
        int s3len=s3.size();
        
        if(s1len+s2len!=s3len)
         return false;
            vector<vector<int>> dp(s1len + 1, vector<int> (s2len+ 1, -1));;
        return solve(s1,s2,s3,0,0,0,s1len,s2len,s3len,dp);
    }
    
    bool solve(string &s1,string &s2, string &s3, int i, int j, int k, int s1len,int s2len,int s3len, vector<vector<int>> &dp){
        if(i==s1len&&j==s2len)
            return true;
       
        if(i>s1len||j>s2len||(s1[i]!=s3[k])&&s2[j]!=s3[k])
            return false;
         if(dp[i][j]!=-1)return dp[i][j];
        return dp[i][j]=((s1[i]==s3[k])&&solve(s1,s2,s3,i+1,j,k+1,s1len,s2len,s3len,dp))||((s2[j]==s3[k])&&(solve(s1,s2,s3,i,j+1,k+1,s1len,s2len,s3len,dp)));
        
    }
};