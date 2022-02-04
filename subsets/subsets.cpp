class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
      vector<vector<int>> ans;
        int idx=0;
        vector<int>temp;
         fun(nums,idx,ans,temp);
    return ans;
    }
    
    void fun(vector<int> &nums, int idx, vector<vector<int>> &ans,vector<int>temp){
        // ;
        if(idx>=nums.size()){
            ans.push_back(temp);
            return ;
        }
        
        
        temp.push_back(nums[idx]);
        fun(nums,idx+1,ans,temp);
        temp.pop_back();
        fun(nums,idx+1,ans,temp);
        
        return;
    
    }
};