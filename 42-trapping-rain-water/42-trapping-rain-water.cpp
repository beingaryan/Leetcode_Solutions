class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        
        int left=0;
        int right=n-1;
        
        int maxLeft=0;
        int maxRight=0;
        int res=0;
        while(left<=right)
        {
            if(height[left]<=height[right])
            {
                maxLeft=max(maxLeft,height[left]);
                res+=maxLeft-height[left];
                left++;
                
            }
            else{
                maxRight=max(maxRight,height[right]);
                res+=maxRight-height[right];
                right--;
            }
        }
        return res;
    }
};