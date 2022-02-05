class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
         unordered_map<int,int>mp;
        
        int n=nums.size();
        int check=n/3;
        
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        vector<int>v;
        for(int i=0;i<n;i++){
            if(mp[nums[i]]>check&&mp[nums[i]]!=-1){
                mp[nums[i]]=-1;
                v.push_back(nums[i]);}
        }
        return v;
    }
};