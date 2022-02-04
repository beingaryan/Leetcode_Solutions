class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();      
        vector<int>visited(n+1,0);
        
        vector<vector<int>>ans;
        vector<int>vec;
        
//            for(int i=0;i<visited.size();i++)
//             {
//                 cout<<visited[i]<<" ";
//             }
//             cout<<endl;
        
        permuteWays(nums,visited,vec,ans);
        return ans;
    }
    
    void permuteWays(vector<int> &nums,vector<int> &visited,vector<int> &vec,vector<vector<int>> &ans){
        //BC
        if(vec.size()==nums.size())
        {
            // for(int i=0;i<vec.size();i++)
            // {
            //     cout<<vec[i]<<" ";
            // }
            // cout<<endl;
            ans.push_back(vec);
            return;
        }
        
        
        for(int i=0;i<nums.size();i++)
        {
            if(visited[i]==0)
            {
                
                vec.push_back(nums[i]);
                visited[i]=1;
                permuteWays(nums,visited,vec,ans);
                visited[i]=0;
                vec.pop_back();
            }
            
            // 
        }
        return;
    }
    
};