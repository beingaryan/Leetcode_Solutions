class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int numRows=rowIndex+1;
          vector<vector<int>> v(numRows);
    
    for(int i=0;i<numRows;i++)
    {
        v[i]=vector<int>(i+1);
    
    }
    
    for(int i=0;i<numRows;i++)
    {
        for(int j=0;j<v[i].size();j++)
        {
            v[i][0]=1;
            v[i][v[i].size()-1]=1;
        }
    }
    
    if(numRows==1 || numRows==2)
        return v[rowIndex];
    
    for(int i=2;i<numRows;i++)
    {
        for(int j=1;j<v[i].size()-1;j++)
        {
            v[i][j] = v[i-1][j]+ v[i-1][j-1];
        }
    }
    
    return v[rowIndex];     
    }
};