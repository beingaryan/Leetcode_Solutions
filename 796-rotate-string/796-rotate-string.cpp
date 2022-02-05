class Solution {
public:
    bool rotateString(string s, string goal) {
      string tempSource=s;
        
        while(1){
            char c=s[0];
            s.erase(0,1);
            s.push_back(c);
            c++;
            if(s==goal)return true;
            if(s==tempSource)break;
        }
        return false;
    }
};