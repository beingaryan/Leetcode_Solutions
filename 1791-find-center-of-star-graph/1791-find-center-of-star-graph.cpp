class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n=edges.size()+1;
       vector<int>outDeg(n+1,0);
          vector<int>inDeg(n+1,0);

        for(int i=0;i<edges.size();i++){
            outDeg[edges[i][0]]++;
            outDeg[edges[i][1]]++;
            
            inDeg[edges[i][0]]++;
            inDeg[edges[i][1]]++;
            
       
        }  
        
         int centerStar=-1;
         for(int i=1;i<n+1;i++){
           
            if(inDeg[i]==n-1&&outDeg[i]==n-1)centerStar=i;
        }
        
        return centerStar;
    }
};