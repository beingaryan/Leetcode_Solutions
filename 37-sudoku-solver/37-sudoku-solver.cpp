class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        sudokuSolver(board,0,0);
        
        return;
    }
    
    bool sudokuSolver(vector<vector<char>>& board, int currentRow, int currentCol){
        if(currentRow==9){
            return true;
        }
        int newRow=0,newCol=0;
        //Making new key out of current key
        if(currentCol==8){
            newRow=currentRow+1;
             newCol=0;
        }
        
        else{
           newRow=currentRow;
           newCol=currentCol+1;
        }
        
        if(board[currentRow][currentCol]!='.'){
            return sudokuSolver(board,newRow, newCol);
        }
        
        for(int currentVal=1;currentVal<10;currentVal++){
            if(isValidMove(board,currentRow,currentCol,currentVal)){
                board[currentRow][currentCol]=((char)(currentVal+'0'));
                if(sudokuSolver(board,newRow,newCol)==true)return true;
                board[currentRow][currentCol]='.';
            }
        }
        
        return false;
        
    }
    
    bool isValidMove(vector<vector<char>>& board, int currentRow, int currentCol, int currentVal){
        return isRowValid(board,currentRow, currentVal) && isColumnValid(board,currentCol, currentVal) && isSubGridValid(board,currentRow,currentCol, currentVal);
    }
    
    bool isRowValid(vector<vector<char>>& board, int currentRow, int currentVal){
        for(int i=0;i<9;i++){
            if(board[currentRow][i]==((char)(currentVal+'0')))return false;
        }
        
        return true;
    }
    
    
    bool isColumnValid(vector<vector<char>>& board, int currentCol, int currentVal){
        for(int i=0;i<9;i++){
            if(board[i][currentCol]==((char)(currentVal+'0')))return false;
        }
        
        return true;
    }
    
    bool isSubGridValid(vector<vector<char>>& board, int currentRow, int currentCol, int currentVal){
        int newR=3*(currentRow/3);
        int newC=3*(currentCol/3);
        
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(board[newR+i][newC+j]==((char)(currentVal+'0'))){
                    return false;
                }
            }
        }
        
        return true;
    }
};