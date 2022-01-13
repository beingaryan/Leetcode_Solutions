class Solution {
public:
    int mySqrt(int num) {
        int start=0;
        int end=num;
        
        long long ans,mid;
        
        while(start<=end){
         mid=start+(end-start)/2;
            
            if(mid*mid==num)return mid;
            
            if(mid*mid<num){
                start=mid+1;
                ans=mid;
            }
            else{
                end=mid-1;
            }
        }
        
        return ans;
    }
};