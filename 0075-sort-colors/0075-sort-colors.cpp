class Solution {
public:
    void sortColors(vector<int>& nums) {
       // 2 0 1 0 2 1 2 2 0 0 0 1
       // L                     R
       // M
       //     0 1 2 2 1 0 2
       //     a[l]<=a[m]
        int low=0;
        int high=nums.size()-1;
        int mid=0;
        
        while(mid<=high){
            switch(nums[mid]){
                case 0:
                    swap(nums[low++],nums[mid++]);
                    break;
                    
                case 1:
                    mid++;
                    break;
                    
                case 2:
                    swap(nums[mid],nums[high--]);
                    break;
            }
        }
        return;
           
    }
};