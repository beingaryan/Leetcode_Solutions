class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        	return atMostKUniqueCharacters(nums,k)-atMostKUniqueCharacters(nums,k-1);
    }
    
      int atMostKUniqueCharacters(vector<int>&s, int k){
        unordered_map<int,int>mp;
        int release=0;
        int answer=0;
        int distinct=0;
      for(int i=0;i<s.size();i++){
          
          if(mp.find(s[i])!=mp.end())
          {
          mp[s[i]]++;       
          }
         
     else {
         mp[s[i]]=1;
         distinct++;
     }
 
          while(distinct>k){
              mp[s[release]]--;
            
              if(mp[s[release]]==0){
              mp.erase(s[release]);
              distinct--;
              }
            
            release++;
              
          }
          
          answer=answer+i-release+1;
          
      }
      
      return answer;
    }
};