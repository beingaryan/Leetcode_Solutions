class Solution {
public:
    bool isRobotBounded(string instructions) {
        //up,left,down,right;
        vector<vector<int>>directions={{0,1},{-1,0},{0,-1},{1,0}};
        
        int currentIndex=0;
        
        int x=0;
        int y=0;
        
        for(int i=0;i<instructions.size();i++){
            if(instructions[i]=='L'){
               currentIndex=(currentIndex+1)%4; 
            }else if(instructions[i]=='R'){
                currentIndex=(currentIndex+3)%4; 
            }
            else{
                x=x+directions[currentIndex][0];
                y=y+directions[currentIndex][1];
            }
        }
        
        return x==0&&y==0||currentIndex!=0;
        
    }
};