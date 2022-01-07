class Solution {
public:
    int maxSubArray(vector<int>& nums) {
      
        int maxval=INT_MIN;
        int max_so_far=-10001;
        for(int i=0;i<nums.size();i++){
            
          max_so_far=max(nums[i],nums[i]+max_so_far);
            maxval=max(maxval,max_so_far);
        }
        
        return maxval;
    }
};