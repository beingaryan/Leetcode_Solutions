class Solution {
public:
       unordered_map<int,int>mp;
    int minCostClimbingStairs(vector<int>& cost) {
          int a = mincost(cost,0);
        // int b = mincost(cost,1);
        return min(a,mp[1]);
    }
    
     int mincost(vector<int>&cost , int curr)
    {
      if(curr==cost.size())return 0;
               if(curr>cost.size())return 1000;
         
        if(mp.find(curr)!=mp.end())
            return mp[curr];
         
         int oneStep=cost[curr]+mincost(cost,curr+1);
         int twoStep=cost[curr]+mincost(cost,curr+2);
         
         return mp[curr]=min(oneStep,twoStep);
     }
};