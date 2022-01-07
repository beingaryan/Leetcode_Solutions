class Solution {
public:
    
    vector<vector<string>> solveNQueens(int n) {
    vector<vector<char>> grid(n,vector<char> (n,'.'));
    vector<vector<string>> answer;
        
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         grid[i][j]='.';
        //     }
        // }
        
        NQueens(grid,0,n,answer);
        
        return answer;
    }
    
    void  populateAns(vector<vector<char>> grid ,int n,vector<string>  &currentanswer){
               
        for(int i=0;i<n;i++){
        
        string tempAns="";
            for(int j=0;j<n;j++){
                tempAns+=grid[i][j];
            }
           
            currentanswer.push_back(tempAns);
        }
       
        return ;
    }
    
    void NQueens(vector<vector<char>> grid ,int currentRow, int n,vector<vector<string>> &answer ){
        if(currentRow==n){
            vector<string> currentanswer;
            populateAns(grid,n,currentanswer);
            
            answer.push_back(currentanswer);
            
            return;
        }
        
        for(int currentCol=0;currentCol<n;currentCol++){
        if(isValid(currentRow,currentCol,grid, n)){
            grid[currentRow][currentCol]='Q';
            NQueens(grid,currentRow+1,n,answer);
            grid[currentRow][currentCol]='.';
        }
        }
        
        return;
    }
    
    bool isValid(int currentRow, int currentCol, vector<vector<char>> grid, int n ){
        return isRowValid(currentRow,grid,n)&&isColumnValid(currentCol,grid,n)&&AreDiagonalsValid(currentRow,currentCol,grid,n);
    }
    
    bool isRowValid(int currentRow, vector<vector<char>> grid  , int n){
        for(int i=0;i<n;i++){
            if(grid[currentRow][i]=='Q')return false;
        }
        
        return true;
    }
    
    
     bool isColumnValid(int currentCol, vector<vector<char>> grid , int n){
        for(int i=0;i<n;i++){
            if(grid[i][currentCol]=='Q')return false;
        }
        
        return true;
    }
    
    bool AreDiagonalsValid(int currentRow, int currentCol, vector<vector<char>> grid , int n){
        int i=currentRow;
        int j=currentCol;
        
        //Top Left
        while(i>=0 && j>=0){
            if(grid[i][j]=='Q')return false;
            i--;
            j--;
        }
        
        i=currentRow;
        j=currentCol;
        
        //Top Right
        while(i>=0 && j<n){
            if(grid[i][j]=='Q')return false;
            i--;
            j++;
        }
        
        
        i=currentRow;
        j=currentCol;
        
        //Bottom Right
        while(i<n && j<n){
            if(grid[i][j]=='Q')return false;
            i++;
            j++;
        }
        
        
        i=currentRow;
        j=currentCol;
        
        //Bottom Left
        while(i<n && j>=0){
            if(grid[i][j]=='Q')return false;
            i++;
            j--;
        }
        
        return true;
    }
};