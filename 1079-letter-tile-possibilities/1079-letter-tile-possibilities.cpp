class Solution {
public:
    int numTilePossibilities(string tiles) {
      
        
// //         string check=tiles;
// //         string appendS=tiles+check;
        
// //         reverse(check.begin(),check.end());
//         // check=check+tiles;
//         // cout<<check;
//         int n=tiles.size();
//          // for(int i=0;i<n;i++){
//          //    // string temp="";
//          //     calculate(i,i+n,s,temp,appendS);
//          // }
        
//     string temp="";
        // calculate(0,n,s,temp,tiles);
        // calculate(0,n,s,temp,check);
        // calculate(0,n,s,temp,check);
        
            // for (auto it = s.begin(); it !=
            //                  s.end(); ++it)
            // {
                // string combination=*it;
                // if(perm.size()==1)continue;
        int n=tiles.size();
          string perm="";
          set<string>s;
          vector<bool>visited(n,false);
          permutation(tiles,s,visited,perm,n);
        for (auto it = s.begin(); it !=
                             s.end(); ++it)
            {
        cout <<*it<<"*";
            }
                return s.size()-1;
    }
    
    
    void permutation(string&tiles,set<string>&s,vector<bool>&visited,string &perm,int size){
        
        if(perm.size()==size)//&&perm.size()>0){
        {s.insert(perm);
            return;
        }
        
         s.insert(perm);
        for(int i=0;i<size;i++){
            if(visited[i]==false){
                visited[i]=true;
                perm.push_back(tiles[i]);
                permutation(tiles,s,visited,perm,size);
                visited[i]=false;
                perm.pop_back();
                
            }
        }
        return;
    }
    
//     void calculate(int start, int end, set<string>&s,string temp,string tiles){
        
//         if(start>=end){
//             // if(s.find(temp)==s.end()){
//                 s.insert(temp);
//             // }
//             return;
//         }
        
//         temp.push_back(tiles[start]);
//         calculate(start+1,end,s,temp,tiles);
//         temp.pop_back();
//         calculate(start+1,end,s,temp,tiles);
        
//         return;
        
//     }

    
    
    
};