class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        
        int i=0;
        int j=0;
        
        set<pair<int,int>>answerSet;
        set<pair<int,int>>s;
                
        vector<vector<int>>ans;
        vector<int>singlePair;
        
        int n1=nums1.size();
        int n2=nums2.size();
        
        
        pq.push({nums1[i]+nums2[j],{i,j}});
        s.insert({i,j});
        
        for(int c=0;c<k;c++)
        
        {
           
            auto temp=pq.top();
            pq.pop();
            
            i=temp.second.first;
            j=temp.second.second;
            
        if(answerSet.find({i,j})==answerSet.end()){
            
            singlePair.push_back(nums1[i]);
            singlePair.push_back(nums2[j]);            
            ans.push_back(singlePair);
            
            answerSet.insert({i,j});
            singlePair.clear();
            }
            
            
            
            if(i+1<n1 && j<n2)
        {
            int sum=nums1[i+1]+nums2[j];
            pair<int,int>check={i+1,j};
                        
            if(s.find(check)==s.end()){
                s.insert(check);
                pq.push({sum,check});    
            }
            
        }
            
             if(i<n1 && j+1<n2)
        {
            int sum=nums1[i]+nums2[j+1];
            pair<int,int>check={i,j+1};
            
            
            if(s.find(check)==s.end())
            {
                s.insert(check);
                pq.push({sum,check});    
            }
            
        }
            
    }
        
        return ans;
    }
   
};