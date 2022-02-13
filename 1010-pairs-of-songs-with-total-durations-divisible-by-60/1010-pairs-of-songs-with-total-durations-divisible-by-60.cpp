class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int,int>mp;
        int maxElement=60;
        int n=time.size();
        int total=0;
        for(int i=0;i<n;i++){
            
            int curr=time[i];
            int toCheck=(60-(curr%60));
            
            while(toCheck<=maxElement){
                
                if(mp.find(toCheck)!=mp.end())
                {
                    total+=mp[toCheck];
                }
                toCheck+=60;
            }
            
            mp[time[i]]++;
            maxElement=max(maxElement,time[i]);
        }
        
        return total;
    }
};