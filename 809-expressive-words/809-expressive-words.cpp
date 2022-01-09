class Solution {
public:
    
    
    bool isExpressive(string query, string stretched){
        
       int m=query.size();
        int n=stretched.size();
    int i=0,j=0;
        
        while(i<m&&j<n){
            if(query[i]!=stretched[j])return false;
            
            int count1=0,count2=0;
            char c=query[i];
            
            while(i<m && query[i]==c){
                i++;
                count1++;
            }
            
            while(j<n && stretched[j]==c){
                j++;
                count2++;
            }
            
            if(count1==count2)continue;
            
            if(count1>count2)return false;
            
            else if(count2>=3)continue;
            
            return false;
            
        }
        if(i!=m || j!=n)return false;
        return true;
    }
    
    int expressiveWords(string s, vector<string>& words) {
     int answer=0;
        for(int i=0;i<words.size();i++){
           if(isExpressive(words[i],s))answer++;
        }
     return answer;   
    }
};
//    string uniqueChar_par="";
//         map<char,int>val;
//         int answer=0;
//         for(int i=0;i<s.size();i++){
           
            
//             if(val.find(s[i]) == val.end()){
//             // if(!(val.count(s[i])>0)){
              
//                uniqueChar_par+=s[i];
//            }
//              val[s[i]]++;
//         }//helo
        
//         // cout<<"uniqueChar_par"<<uniqueChar_par;
        
//         vector<int> char_count_par;
//         for(int i=0;i<uniqueChar_par.size();i++){
            
//             char_count_par.push_back(val[uniqueChar_par[i]]);
//            // cout<<char_count_par[i]<<" ";
//         }//1323
        
//         //hello
//         for(int j=0;j<words.size();j++){
//             string temp=words[j];
//             // for(int i=0;i<temp.size();i++){
//            int i=0;
//             int cp=0;
//             while(1){
            
//             int count=1;
//                while(temp[i]==temp[i+1]&&i<temp.size()){
//                    count++;
//                    i++;
//                }
//                if(temp[i]==uniqueChar_par[cp]){
                   
//                    if((char_count_par[cp]>=3&&count<=char_count_par[cp])||(count==char_count_par[cp])){
//                        cout<<"Yes";
//                   if(i<temp.size()) {
//                       cp++;
//                       i++;
//                       continue;}
                       
//                        else if(i==temp.size()-1){
//                       answer++;
//                       break;
                      
                      
//                   }
//                        // cout<<"Yes";
//                }
//                }
//                 else{
//                     break;
//                 }
//                if(i==temp.size())break;
               
//            }
//             // }
// //1323
// //1121

// // helo
// // helo

//         }



// //h1e3l2o3


// //cp
// //cc


// cp==cc

// cp>=3&&cc<=cp


// //h 1
// //e 3
// //l 2
// //o 3

// //h

// //consecutive elements count less than 3

//consecutive elements count equal


//