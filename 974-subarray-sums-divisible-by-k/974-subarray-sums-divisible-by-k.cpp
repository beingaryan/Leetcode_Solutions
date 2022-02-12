class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans=0;
        map<int,int>mp;
        int prefixSum=0;
        mp[0]=1;
        
        
        for(int i=0;i<nums.size();i++){
          prefixSum+=nums[i];
            int rem=((prefixSum%k)+k)%k;
            if(mp.find(rem)==mp.end()){
                mp[rem]=1;
            }
            else{
                ans=ans+mp[rem];
                mp[rem]++;
            }
        }
        
        return ans;
        
    }
};