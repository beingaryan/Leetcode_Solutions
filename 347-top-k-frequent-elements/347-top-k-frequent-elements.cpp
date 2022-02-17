class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map<int,int>mp;
        
        for(auto num:nums)
            mp[num]++;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minHeap;
        
        for(auto ele:mp){
            minHeap.push({ele.second,ele.first});//freq,element
            if(minHeap.size()>k)
                minHeap.pop();
            
            
        }
        vector<int>ans;
        while(!minHeap.empty())
        {
           ans.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return ans;
        
    }
};