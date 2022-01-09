class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> answer;
        vector<int>currentAnswer;
        set<string> val;
        sort(nums.begin(),nums.end());
        noDuplicateSubset(nums, 0,answer,currentAnswer,val);
        return answer;
    }
    
    void noDuplicateSubset(vector<int>& nums,int idx,vector<vector<int>>&answer,vector<int>&currentAnswer,set<string>&val){
        if(idx>=nums.size()){
             string ans="";
            for(int i=0;i<currentAnswer.size();i++){
                int temp=currentAnswer[i];
               ans+=((char)(temp+'0'));
                ans+='_';
            }
            if(!val.count(ans)){
                val.insert(ans);
                answer.push_back(currentAnswer);
            }
            
            return;
            
        }
       
        currentAnswer.push_back(nums[idx]);
        noDuplicateSubset(nums,idx+1,answer,currentAnswer,val);
        currentAnswer.pop_back();
        noDuplicateSubset(nums,idx+1,answer,currentAnswer,val);
        return;
    }
};

