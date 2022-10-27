class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool>state(nums.size(),false);
        vector<int>currAns;
        vector<vector<int>>totalAns;
        unordered_set<string>set;
        recur(state,nums,currAns,totalAns,set);
        return totalAns;
    }
    
    void recur(vector<bool>&state,vector<int>nums,vector<int>&currAns,vector<vector<int>>&totalAns, unordered_set<string>&set){
        if(currAns.size()==nums.size()){
            string str;
            for(auto ele:currAns){
                str+=ele+'0'+'#';
            }
         if(set.find(str)==set.end()){
             set.insert(str);
            totalAns.push_back(currAns);
         }
        }
        
        // if(currIdx>=nums.size())
        //     return;
        
        for(int i=0;i<nums.size();i++){
            
            
            if(state[i]==false){
                currAns.push_back(nums[i]);
                state[i]=true;
            recur(state,nums,currAns,totalAns,set);
            state[i]=false;
                  currAns.pop_back();
            }
              
        }
    }
};