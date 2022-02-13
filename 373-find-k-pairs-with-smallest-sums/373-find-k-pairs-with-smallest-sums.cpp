class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        
        int i=0;
        int j=0;
        set<pair<int,int>>s;
        pq.push({nums1[i]+nums2[j],{i,j}});
        s.insert({i,j});
        vector<vector<int>>ans;
        vector<int>singlePair;
        int n1=nums1.size();
        int n2=nums2.size();
        int endIndex=k;
        
        // if(k<n1||k<n2)
        //     endIndex=k;
        // if(n1!=n2)
        //     endIndex
        // if(k>n1&&k<n2||k>n2&&k<n1||k>n1&&k>n2&&n1!=n2)
        //     endIndex=max(n1,n2);
        set<pair<int,int>>answerSet;
        for(int c=0;c<k;c++){
           pair<int,pair<int,int>>temp=pq.top();
            pq.pop();
        
            if(answerSet.find(make_pair(temp.second.first,temp.second.second))==answerSet.end()){
             singlePair.push_back(nums1[temp.second.first]);
            singlePair.push_back(nums2[temp.second.second]);
            answerSet.insert(make_pair(temp.second.first,temp.second.second));
            ans.push_back(singlePair);
            singlePair.clear();
            }
            
             i=temp.second.first;
            j=temp.second.second;
            
            if(i+1<n1&&j<n2){
            int sum=nums1[i+1]+nums2[j];
            pair<int,int>check;
            check.first=i+1;
            check.second=j;
            
                        
            if(s.find(check)==s.end()){
                s.insert(check);
                pq.push({sum,check});
                
            }
            
            }
            
             if(i<n1&&j+1<n2){
            int sumT=nums1[i]+nums2[j+1];
            pair<int,int>checkT;
            checkT.first=i;
            checkT.second=j+1;
            
            if(s.find(checkT)==s.end()){
                s.insert(checkT);
                pq.push({sumT,checkT});
                
            }
            
             }
            
        }
        
        return ans;
    }
};