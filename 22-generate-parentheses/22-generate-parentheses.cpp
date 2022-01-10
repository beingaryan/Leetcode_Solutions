class Solution {
public:
    
    void allParanthesis(vector<string>&result, int open,int close, string tempAns){
        if(open==0 && close==0){
            result.push_back(tempAns);
            return;
        }
        
        if(open!=0){
            // tempAns.push_back('(');
            allParanthesis(result,open-1,close,tempAns+'(');
            // tempAns.pop_back();
        }
        
        if(open!=close&&close!=0){
            // tempAns.push_back(')');
            allParanthesis(result,open,close-1,tempAns+')');
            // tempAns.pop_back();
        }
        
        return;
        
        
    }
    vector<string> generateParenthesis(int n) {
        
        vector<string> result;
        string tempAns="";

        allParanthesis(result,n,n,tempAns);
        return result;

    }
};