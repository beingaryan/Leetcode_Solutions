class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // int check=image[sr][sc];
        if(image[sr][sc]==newColor)return image;
        updatedFill(image,sr,sc,image.size(),image[0].size(),newColor,image[sr][sc]);
        
        return image;
    }
    
    void updatedFill(vector<vector<int>>& image, int sr, int sc,int m,int n, int newColor,int check){
        if(sr<0||sr>=m||sc<0||sc>=n||image[sr][sc]!=check)
            return;
        
        // if(image[sr][sc]!=check)return;
        
        image[sr][sc]=newColor;
        
        updatedFill(image,sr-1,sc,m,n,newColor,check);
        updatedFill(image,sr,sc+1,m,n,newColor,check);
        updatedFill(image,sr+1,sc,m,n,newColor,check);
        updatedFill(image,sr,sc-1,m,n,newColor,check);
        
        return;
    }
};
