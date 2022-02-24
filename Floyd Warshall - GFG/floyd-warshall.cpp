// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	   int V=matrix.size();
	   
	   for(int i=0;i<V;i++){
	       for(int j=0;j<V;j++){
	           if(matrix[i][j]==-1)
	           matrix[i][j]=INT_MAX;
	           }
	   }
	   
	   for(int k=0;k<V;k++){//intermediate
	       for(int i=0;i<V;i++){
	           for(int j=0;j<V;j++){
	               if(matrix[i][k]!=INT_MAX&&matrix[k][j]!=INT_MAX)
	           {
	               matrix[i][j]=min(matrix[i][j],matrix[i][k]+matrix[k][j]);
	           }
	               
	           }
	       }
	   }
	   
	    
	   for(int i=0;i<V;i++){
	       for(int j=0;j<V;j++){
	           if(matrix[i][j]==INT_MAX)
	           matrix[i][j]=-1;
	           }
	   }
	   
	   
	}
	
// 	 int V=matrix.size();
// 	    for(int i=0;i<V;i++){
// 	        for(int j=0;j<V;j++){
// 	            if(matrix[i][j]==-1)
// 	            matrix[i][j]=INT_MAX;//Change it to INT_MAX as we are taking i=
// 	            //minimum of mat[i][j] and if it's -1 so everytime t may give negative value
	            
// 	        }
// 	    }
	    
// 	    for(int k=0;k<V;k++)//Intermediate
// 	    {
// 	        for(int i=0;i<V;i++)//Source
// 	        {
// 	            for(int j=0;j<V;j++)//Destination
// 	            {       
	            
// 	            if(matrix[i][k]!=INT_MAX&&matrix[k][j]!=INT_MAX)
// 	            {
// 	            matrix[i][j]=min(matrix[i][j],matrix[i][k]+matrix[k][j]);    
// 	            }
	            
	                
// 	            }
//     	    }
//         }
	    
// 	    for(int i=0;i<V;i++)
// 	    {
// 	        for(int j=0;j<V;j++)
// 	        {
// 	            if(matrix[i][j]==INT_MAX)
// 	            matrix[i][j]=-1;
// 	        }
// 	    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		obj.shortest_distance(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends