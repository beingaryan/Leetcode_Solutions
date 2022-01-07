class Solution {
public:
    string originalDigits(string s) {
        int freq[26]={0};int n=s.length();
        for(int i=0;i<n;i++){
            freq[s[i]-'a']++;
        }
        int res[10];
        res[0]=freq['z'-'a'];
        res[2]=freq['w'-'a'];
        res[4]=freq['u'-'a'];
        res[6]=freq['x'-'a'];
        res[8]=freq['g'-'a'];
        
        res[1]=freq['o'-'a']-res[0]-res[2]-res[4];
        res[3]=freq['h'-'a']-res[8];
        res[5]=freq['f'-'a']-res[4];
        res[7]=freq['s'-'a']-res[6];
        res[9]=freq['i'-'a']-res[5]-res[6]-res[8];
        
        
        string op;
        for(int i=0;i<10;i++){
            while(res[i]-->0){
                op.push_back((char)(i+'0'));
            }
        }
        
        return op;
        
    }
    
};