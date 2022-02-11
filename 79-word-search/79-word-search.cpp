class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        string tempWord="";
        int rowSize=board.size();
        int colSize=board[0].size();
        
        for(int i=0;i<rowSize;i++){
            for(int j=0;j<colSize;j++){
                if(board[i][j]==word[0]){
                if(fun(board,word,tempWord,0,i,j,rowSize,colSize))
                    return true;}
            }
        }
        
        return false;
    }
    
    bool fun(vector<vector<char>>& board,string&word,string tempWord,int k,int currRow, int currCol,int rowSize, int colSize)
    {
    // cout<<tempWord<<"*"<<endl;
        if(word==tempWord){
            // cout<<tempWord<<"*"<<endl;
            return true;}
        
        if(currRow<0||currRow>=rowSize||currCol<0||currCol>=colSize||board[currRow][currCol]!=word[k])
            return false;
        
        
        
        // cout<<tempWord<<"*"<<endl;
        char c=board[currRow][currCol];
        board[currRow][currCol]='*';
        tempWord.push_back(c);
        bool right=fun(board,word,tempWord,k+1,currRow,currCol+1,rowSize,colSize);
        tempWord.pop_back();
        board[currRow][currCol]=c;
          
        
        char d=board[currRow][currCol];
        board[currRow][currCol]='*';
        tempWord.push_back(d);
        bool left=fun(board,word,tempWord,k+1,currRow,currCol-1,rowSize,colSize);
        tempWord.pop_back();
         board[currRow][currCol]=d;
        
        
      char e=board[currRow][currCol];
        board[currRow][currCol]='*';
        tempWord.push_back(e);
        bool down=fun(board,word,tempWord,k+1,currRow+1,currCol,rowSize,colSize);
        tempWord.pop_back();
       board[currRow][currCol]=e;
        
        
         char f=board[currRow][currCol];
        board[currRow][currCol]='*';
        tempWord.push_back(f);
        bool up=fun(board,word,tempWord,k+1,currRow-1,currCol,rowSize,colSize);
        tempWord.pop_back();
       board[currRow][currCol]=f;
        
        
        return right||left||down||up;
    }
};