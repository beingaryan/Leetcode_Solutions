class Solution {
public:
    
    void combinationOfLetters(string digits,int currentIndex, vector<string> &result, string tempAns,unordered_map<char,string>map ){
        
        if(currentIndex==digits.size()){
            result.push_back(tempAns);
            return;
        }
        
        string lookup=map[digits[currentIndex]];
        
        for(int i=0;i<lookup.size();i++){
            tempAns.push_back(lookup[i]);
            combinationOfLetters(digits,currentIndex+1,result,tempAns,map);
            tempAns.pop_back();
        }
        
        return;
        
        
        
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        
        string tempAns="";
        
        if(digits.size()==0)return result;
        
        unordered_map<char,string>map;
        map.insert({'2',"abc"});
        map.insert({'3',"def"});
        map.insert({'4',"ghi"});
        map.insert({'5',"jkl"});
        map.insert({'6',"mno"});
        map.insert({'7',"pqrs"});
        map.insert({'8',"tuv"});
        map.insert({'9',"wxyz"});

     
        
        // if(zz)
        
        combinationOfLetters(digits,0,result,tempAns,map);
        return result;
    }
};