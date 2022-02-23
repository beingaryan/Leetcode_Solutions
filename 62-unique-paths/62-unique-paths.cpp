class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return totalWays(dp,m,n,0,0);
    }
    
    int totalWays(vector<vector<int>>&dp,int m,int n,int row,int col){
        if(row<0||row>=m||col<0||col>=n)
            return 0;
        if(row==m-1&&col==n-1)
            return 1;
        
        if(dp[row][col]!=-1)
            return dp[row][col];
        
        int down=totalWays(dp,m,n,row+1,col);
        int right=totalWays(dp,m,n,row,col+1);
        return dp[row][col]=down+right;
    }
};