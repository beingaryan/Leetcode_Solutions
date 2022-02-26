class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        int n=nums.size();
        vector<int>visited(n,0);
        
        vector<vector<int>>vec;
        vector<int>temp;
        
        fun(vec,temp,visited,n,nums);
        return vec;
    }
    
    void fun(vector<vector<int>>&vec,vector<int>&temp,vector<int>&visited,int n,vector<int>& nums)
    {
        if(temp.size()==n){
            vec.push_back(temp);
            return;
        }
        for(int i=0;i<n;i++){
            if(visited[i]==0){
                visited[i]=1;
                temp.push_back(nums[i]);
                fun(vec,temp,visited,n,nums);
                visited[i]=0;
                temp.pop_back();
            }
        }
        
        return;
        
     
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
//     int n=nums.size();      
//         vector<int>visited(n+1,0);
        
//         vector<vector<int>>ans;
//         vector<int>vec;
        
// //            for(int i=0;i<visited.size();i++)
// //             {
// //                 cout<<visited[i]<<" ";
// //             }
// //             cout<<endl;
        
//         permuteWays(nums,visited,vec,ans);
//         return ans;
//     }
    
//     void permuteWays(vector<int> &nums,vector<int> &visited,vector<int> &vec,vector<vector<int>> &ans){
//         //BC
//         if(vec.size()==nums.size())
//         {
//             // for(int i=0;i<vec.size();i++)
//             // {
//             //     cout<<vec[i]<<" ";
//             // }
//             // cout<<endl;
//             ans.push_back(vec);
//             return;
//         }
        
        
//         for(int i=0;i<nums.size();i++)
//         {
//             if(visited[i]==0)
//             {
                
//                 vec.push_back(nums[i]);
//                 visited[i]=1;
//                 permuteWays(nums,visited,vec,ans);
//                 visited[i]=0;
//                 vec.pop_back();
//             }
            
//             // 
//         }
//         return;
};