// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> res;
        string ans="";
        fun(m,n,0,0,ans,res);
        return res;
    }
    
    void fun(vector<vector<int>> &m,int n,int row,int col,string ans,vector<string>&res)
    {
        if(row<0||row>=n||col<0||col>=n||m[row][col]==0)
        return;
        
        if(row==n-1&&col==n-1){
            m[row][col]=0;
            res.push_back(ans);
            m[row][col]=1;
            return;
        }
        m[row][col]=0;
        fun(m,n,row+1,col,ans+"D",res);
        fun(m,n,row,col-1,ans+"L",res);
        fun(m,n,row,col+1,ans+"R",res);
        fun(m,n,row-1,col,ans+"U",res);
        m[row][col]=1;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends