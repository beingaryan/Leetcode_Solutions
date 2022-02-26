class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_map<int,int>mp;
        for(auto candy:candyType)
            mp[candy]++;
        
        return min(mp.size(),candyType.size()/2);
    }
};