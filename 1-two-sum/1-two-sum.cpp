class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int k) {
        vector<int>v;
        unordered_map<int,int>mp;
        
        for(int i=0;i<nums.size();i++){
            if(mp.find(k-nums[i])!=mp.end())
            {
                 v.push_back(mp[k-nums[i]]);
                v.push_back(i);
                return v;
            }else{
                mp[nums[i]]=i;
            }
        }
        return v;
    }
//     sort(nums.begin(),nums.end());
//         int left=0;
//         int n= nums.size();
//         int right=n-1;
//         while(left<right){
            
//             if(nums[left]+nums[right]>k)right--;
//             else if(nums[left]+nums[right]<k)left++;
//             else if(nums[left]+nums[right]==k) {
//                
//              return v;   
//             }
//         }
};