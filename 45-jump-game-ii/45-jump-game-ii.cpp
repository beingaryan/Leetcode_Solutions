class Solution {
public:
    int jump(vector<int>& nums) {
//         if(nums.size()==1)return 0;
//          int n=nums.size();
//     int totalJumps=1;
//     int maxReach=nums[0];
//         int i=1;
//         if(maxReach>=n-1)return 1;
//         while(maxReach<n){
//             if(maxReach<i+nums[i]){
//             maxReach=i+nums[i];
//             totalJumps++;    
//             }
            
//             i++;
//         }
        int curr_max=0;
        int max_so_far=0;
        int c=0;
        
        for(int i=0;i<nums.size()-1;i++){
            if(curr_max<i+nums[i])
            {
             curr_max=i+nums[i];
            
            }
            if(i==max_so_far){
                c++;
                max_so_far=curr_max;
            }
            
            // if(i==)
            
        }
        
        return c;
    }
};