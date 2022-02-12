class Solution {
public:
    bool isAnagram(string s, string t) {
        int slen=s.size();
        int tlen=t.size();
        map<char,int>mp;
        for(int i=0;i<slen;i++){
            mp[s[i]]++;
        }
        
        for(int i=0;i<tlen;i++){
            mp[t[i]]--;
            
            if(mp[t[i]]<0)
                return false;
            
            if(mp[t[i]]==0)
                mp.erase(t[i]);
        }
        cout<<mp.size();
        return mp.size()==0;
    }
};