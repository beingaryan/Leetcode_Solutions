class Solution {
public:
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> temp;
        vector<int>ans;
        
        fun(candidates,target,temp,ans,0,candidates.size());
        return temp;
    }
    // 2+2+2
    void fun(vector<int>& candidates,int target,vector<vector<int>>&temp,vector<int>&ans,int index,int n){
        if(target==0){
            temp.push_back(ans);
            return;
        }
        if(index>=n||target<0)
            return;
        
        if(candidates[index]<=target){
            ans.push_back(candidates[index]);
            fun(candidates,target-candidates[index],temp,ans,index,n);
            ans.pop_back();
        }
            fun(candidates,target,temp,ans,index+1,n);
        return;
    }
};    
   