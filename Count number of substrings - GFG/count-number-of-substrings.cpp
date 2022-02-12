// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    long long int substrCount (string s, int k) {
        	return atMostKUniqueCharacters(s,k)-atMostKUniqueCharacters(s,k-1);
    }
    
      long long int atMostKUniqueCharacters(string s, int k){
        // unordered_map<char,long long int>mp;
        long long int release=0;
        long long int answer=0;
        long long int distinct=0;
        long long int freq[26]={0};
        
      for(int i=0;i<s.size();i++){
        char c=s[i];  
          if(freq[c-'a']!=0)
          {
          freq[c-'a']++;       
          }
         
     else {//(mp.find(s[i])==mp.end()){
         freq[c-'a']=1;
         distinct++;
     }
          // mp[s[i]]++;
//       release<=i&&distinct
          while(distinct>k){
              char discard=s[release];
              freq[discard-'a']--;
            //   mp[discard]--;
            
              if(freq[discard-'a']==0){
            //   mp.erase(discard);
              distinct--;
              }
            
            release++;
              
          }
          
          answer=answer+i-release+1;
          
      }
      
      return answer;
    }
};

// { Driver Code Starts.


int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		int k; cin >> k;
		Solution ob;
		cout <<ob.substrCount (s, k) << endl;
	}
}  // } Driver Code Ends