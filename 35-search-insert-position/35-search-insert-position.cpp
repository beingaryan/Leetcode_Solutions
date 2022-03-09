class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return (findCeil(nums,target)==-1)?nums.size():findCeil(nums,target);
    }
    
    int findCeil(vector<int>&nums, int target){
        int start=0;
        int end=nums.size()-1;
        int answer=-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            
            if(nums[mid]==target)
                return mid;
            
            else if(nums[mid]<target)
                start=mid+1;
            
            else
            {
                answer=mid;
                end=mid-1;
            }
            
            
        }
        
        return answer;
    }
};
