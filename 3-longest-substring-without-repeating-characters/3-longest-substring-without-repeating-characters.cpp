#include<bits/stdc++.h>
class Solution {
public:
    int lengthOfLongestSubstring(string A) {
          unordered_map<char ,int > HashMap;
    int n=A.size();
        int release=0;int ans=0;
        for(int i=0;i<n;i++){
            
            if(HashMap.find(A[i])!=HashMap.end())
            {
            HashMap[A[i]]++;
                
            }
            
            else
            {
                HashMap[A[i]]=1;
                // distinctCount++;
            }
             
            if(i-release+1==HashMap.size()){
            if(HashMap.size()>ans)ans=HashMap.size();
             }
            
            if(i-release+1==HashMap.size())continue;
          
            
            
          while(i-release+1>HashMap.size()) { 
          HashMap[A[release]]--;
            if(HashMap[A[release]]==0){
                HashMap.erase(A[release]);
                    
            }
              
          release++;
          }
        }
        
        return ans;
        
    }
    
 
};