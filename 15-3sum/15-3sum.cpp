class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>v;
        vector<int>tempV;
        if(nums.empty())
            return v;
        
        sort(nums.begin(),nums.end());
        
        int n=nums.size();
        for(int i=0;i<n-2;i++){
        
            if(i>0 &&nums[i]==nums[i-1])
                continue;
            
            int left=i+1;
            int right=n-1;
            
            while(left<right){
                if(nums[i]+nums[left]+nums[right]==0){
                    tempV.push_back(nums[i]);
                    tempV.push_back(nums[left]);
                    tempV.push_back(nums[right]);
                    v.push_back(tempV);
                    tempV.clear();
                    int lastLeft=nums[left]; int lastRight=nums[right];
                    while(left<right && nums[left]==lastLeft){
                        left++;
                    }
                    
                    while(left<right && nums[right]==lastRight){
                        right--;
                    }
                }
                else if(nums[i]+nums[left]+nums[right]>0)
                    right--;
                else
                    left++;
            }
        }
        return v;
    }
};