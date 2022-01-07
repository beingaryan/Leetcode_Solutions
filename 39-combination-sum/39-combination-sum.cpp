class Solution {
public:
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
      vector<vector<int>> answer;
        vector<int>temp;
        fun(candidates,0,target,temp,answer);
        return answer; 
    }
    
    void fun(vector<int>& candidates,int index,int target,vector<int>temp,vector<vector<int>>&answer){
        
        if(index>=candidates.size()&&target==0)
        {
            answer.push_back(temp);
            return ;
        }
      
        if(index>=candidates.size()&&target!=0)return;
        
      
    if(target>= candidates[index])
      {
        
          temp.push_back(candidates[index]);
          fun(candidates,index,target-candidates[index],temp,answer);
          temp.pop_back();
        
      }
        
        fun(candidates,index+1,target,temp,answer);
        return;
        
    }  
};    
   