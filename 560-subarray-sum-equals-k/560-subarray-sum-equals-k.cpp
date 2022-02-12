class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans=0;
        int prefixSum=0;
        int n=nums.size();
        map<int,int>mp;
        mp[0]=1;
        
        
        for(int i=0;i<n;i++){
        prefixSum+=nums[i];
        
        if(mp.find(prefixSum-k)!=mp.end())
            ans=ans+mp[prefixSum-k];
    
            mp[prefixSum]++;;
                 
    }
        return ans;
    }
    

};