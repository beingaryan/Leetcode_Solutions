// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
		vector<string> AllPossibleStrings(string s){
		    vector<string> result;
		    string answer="";
		    
		    helper(s,answer,result,0);
		    sort(result.begin(),result.end());
		    return result;
		    
		}
//string passed by value
//array passed by reference
    void helper(string s, string &answer, vector<string>&result,int idx){
        
        if(idx>=s.size()){
            if(answer=="")return;
            result.push_back(answer);
            return;
            
        }
        
        // if(answer=="")return;
        
        answer.push_back(s[idx]);
        helper(s,answer,result,idx+1);
        answer.pop_back();
        helper(s,answer,result,idx+1);
        
        return;
   
        
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}  // } Driver Code Ends