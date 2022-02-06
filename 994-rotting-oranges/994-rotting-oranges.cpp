class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
       queue<pair<int,int>>parent;//r,c
       queue<pair<int,int>>child;
        
        vector<int>directions={1,0,-1,0,1};
        int rowSize=grid.size();
        int colSize=grid[0].size();
        
        int noFresh=false;
        for(int i=0;i<rowSize;i++){
            for(int j=0;j<colSize;j++){
                if(grid[i][j]==2){
                    parent.push({i,j});
                }
                if(grid[i][j]==1){
                    noFresh=true;
                }
            }
        }
        
        if(noFresh==false){
            return 0;
        }
        
        int count=0;
        while(parent.empty()==false){
            int r=parent.front().first;
            int c=parent.front().second;
            parent.pop();
            
            for(int i=0;i<4;i++){
                int newRow=r+directions[i];
                int newCol=c+directions[i+1];
                
                if(newRow>=0 && newRow<rowSize && newCol>=0 && newCol<colSize && grid[newRow][newCol]==1 && grid[newRow][newCol]!=-1){
                     grid[newRow][newCol]=-1;
                     child.push({newRow,newCol});
                }
                
            } 
            if(parent.empty()){
                swap(child,parent);
                count++;
            }
            
        }
        
        for(int i=0;i<rowSize;i++){
            for(int j=0;j<colSize;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        
        return count-1;
        
        
        
    }



      // cout<<" r "<<r<<" c "<<c<<endl;
            
//             if(r+1<rowSize&&grid[r+1][c]==1&&grid[r+1][c]!=-1){
//                 grid[r+1][c]=-1;
//                 child.push({r+1,c});
//             }
            
//             if(r-1>=0&&grid[r-1][c]==1&&grid[r-1][c]!=-1){
//                 grid[r-1][c]=-1;
//                 child.push({r-1,c});
//             }
            
//              if(c+1<colSize&&grid[r][c+1]==1&&grid[r][c+1]!=-1){
//                 grid[r][c+1]=-1;
//                 child.push({r,c+1});
//             }
            
//              if(c-1>=0&&grid[r][c-1]==1&&grid[r][c-1]!=-1){
//                 grid[r][c-1]=-1;
//                 child.push({r,c-1});
//             }
           
                // if(parent.empty()==false)
                //     count++;
};