class Solution {
public:
    int totalNQueens(int n) {
        vector<vector<char>> grid(n,vector<char>(n,'.'));
        vector<vector<string>> answer;
        int result=0;
        NQueens(grid,answer,n,0,result);
        return result;
    }
    
    vector<string> populateAns( vector<vector<char>> grid, int n){
       vector<string> currentAnswer;
        
        for(int i=0;i<n;i++){
            string tempAns="";
            for(int j=0;j<n;j++){
                tempAns+=grid[i][j];
                
            }
            // cout<<tempAns<<endl;
            currentAnswer.push_back(tempAns);
        }
        // cout<<endl;
        
        return currentAnswer;
    }
    
    // [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
    void NQueens(vector<vector<char>>grid,vector<vector<string>> &answer, int n, int currentRow, int &result){
        
        if(currentRow==n)
        {
            // vector<string>currentAnswer=populateAns(grid,n);
            // answer.push_back(currentAnswer);
             result++;
            return;
            
        }
        
        for(int currentCol=0;currentCol<n;currentCol++)
        {
        if(isSafe(currentRow,currentCol,grid,n)){
            grid[currentRow][currentCol]='Q';
            NQueens(grid,answer,n,currentRow+1,result);
            grid[currentRow][currentCol]='.';
        }
        }
            return;
    }
        
        bool isSafe(int currentRow, int currentCol, vector<vector<char>>grid, int n ){
            return isRowSafe(currentRow,grid,n)&& isColumnSafe(currentCol,grid,n)&& AreDiagonalsSafe(currentRow,currentCol,grid,n);
        }
        
        bool isRowSafe(int currentRow, vector<vector<char>>grid, int n){
            for(int i=0;i<n;i++){
                if(grid[currentRow][i]=='Q')return false;
            }
            return true;
        }
    
        bool isColumnSafe(int currentCol, vector<vector<char>>grid, int n){
            for(int i=0;i<n;i++){
                if(grid[i][currentCol]=='Q')return false;
            }
            return true;
        }
        
        bool AreDiagonalsSafe(int currentRow, int currentCol, vector<vector<char>>grid, int n){
            int i=currentRow;
            int j=currentCol;
            //TL
            while(i>=0 && j>=0){
                if(grid[i][j]=='Q')return false;
                i--;
                j--;
            }
            
            
            i=currentRow;
            j=currentCol;
            //TR
            while(i>=0 && j<n){
                if(grid[i][j]=='Q')return false;
                i--;
                j++;
            }
            
            i=currentRow;
            j= currentCol;
            //BR
            while(i<n && j<n){
                if(grid[i][j]=='Q')return false;
                i++;
                j++;
            }
            
               
            i=currentRow;
            j=currentCol;
            //BL
            while(i<n && j>=0){
                if(grid[i][j]=='Q')return false;
                i++;
                j--;
            }
            
            return true;
            
            
        }
        
        
        
};
    