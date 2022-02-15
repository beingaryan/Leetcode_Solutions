class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {

    queue<int>q;
    int n=board.size();
    vector<vector<int>>visited(n,vector<int>(n,0));
    
    q.push(1);
        visited[n-1][0]=1;
        int steps=0;
        while(!q.empty()){
            
            int size=q.size();
            
            while(size--){
            
            int top=q.front();
            q.pop();
                
            if(top==n*n)return steps;
                
                for(int k=1;k<=6;k++){
                    if(top+k>n*n)break;
                    int nextPos=top+k;
                    
                    int r=n-(nextPos-1)/n-1;
                    int c=(nextPos-1)%n;
                    
                    if(n%2==r%2)
                        c=n-c-1;
                    
                    if(visited[r][c]==0){
                        
                        visited[r][c]=1;
                        
                    if(board[r][c]!=-1){
                        
                        q.push(board[r][c]);
                    }
                    else
                    {
                        q.push(nextPos);
                        
                    }
                }
                }
            
            }
             steps++;
            }
           return -1;
        }
    
        
    // }
};