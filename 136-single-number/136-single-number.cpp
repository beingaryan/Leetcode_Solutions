class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int result=0;
        for(int num:nums){
            result=result^num;
        }
        
        return result;
        // XOR of two elements is 0 if both elements are the same and the XOR of a number x with 0 is x
    }
};